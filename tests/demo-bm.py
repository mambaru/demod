#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket
import json
import re
import argparse
import shlex
import datetime

config = {
  'host':'0.0.0.0',
  'port':12345,
  'method': 'set',
  'params': {'name':'name1','value':[1,2,3,4,5]},
  'result': None,
  'count': 1000000,
  'show':1000
}

class client:

  def __init__(self, conf=None):
    self.cli = None
    self.conf = conf
    self.id = 1
    self.counter=[]
    if not self.conf:
      self.conf = config
  
  def connect(self):
    self.cli = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.cli.connect( (self.conf['host'],int(self.conf['port']) ) )
    

  def request(self):
    self.id += 1
    reqstr =json.dumps({
      'method':self.conf['method'],
      'id':self.id,
      'params':self.conf['params']
    })+"\r\n";
    
    #print(reqstr)
    self.cli.send(reqstr)
    data = []
    while True:
      data += self.cli.recv(4096*2)
      #print(data[-1:][0])
      if len(data) > 0 and data[-1:][0]=='\n':
        break
    respstr = ''
    for d in data:
      if d>=32 and d <='~':
        respstr+=d
    #print(respstr)
    return json.loads( respstr );
  
  def request_ts(self):
    start = datetime.datetime.now()
    self.request()
    finish = datetime.datetime.now()
    result =  finish - start
    return result.microseconds + result.seconds*1000000
    
  def bench1(self):
    self.connect()
    ts = self.request_ts()
    self.cli.close()
    self.cli=None
    return ts

  def bench2(self):
    ts = self.request_ts()
    return ts
    
  def show(self, rate):
    self.counter.sort()
    clen = len(self.counter)
    p50 = clen/2
    p80 = clen/100 * 80
    p95 = clen/100 * 95
    p99 = clen/100 * 99
    p100 = clen-1
    print("\n50%\t80%\t95%\t99%\t100%\trate")
    print('{0}\t{1}\t{2}\t{3}\t{4}\t{5}persec'.format(self.counter[p50], self.counter[p80], self.counter[p95], self.counter[p99], self.counter[p100], rate) )
    self.counter = []
    
  def benchmark1(self):
    count=0
    start = datetime.datetime.now()
    for x in xrange(self.conf['count']):
      ts = self.bench1()
      self.counter.append(ts)
      if ( x % self.conf['show'] == 0 ):
        finish = datetime.datetime.now()
        result =  finish - start
        span = result.microseconds + result.seconds*1000000
        rate = len(self.counter)* 1000000/span 
        self.show(rate)
        start = datetime.datetime.now()
    
  def benchmark2(self):
    count=0
    self.connect()
    start = datetime.datetime.now()
    for x in xrange(self.conf['count']):
      ts = self.bench2()
      self.counter.append(ts)
      if ( x!=0 and x % self.conf['show'] == 0 ):
        finish = datetime.datetime.now()
        result =  finish - start
        span = result.microseconds + result.seconds*1000000
        rate = len(self.counter)* 1000000/span 
        self.show(rate)
        start = datetime.datetime.now()
    print("CLOSE")
    self.cli.close()
  
    

if __name__ == '__main__':
  cli = client()
  cli.benchmark1()

  
  
