../../build/demod/demod -C ./hub1.conf &
hub_pid=$!
../../build/demod/demod -C ./proxy.conf &
proxy_pid=$!
sleep 1
(echo '{"method":"subscribe", "params":"test", "id":1}'; sleep 10) | telnet  0.0.0.0 12346 > test.txt & 
cmd_pid=$!
sleep 1
kill $hub_pid
sleep 1
../../build/demod/demod -C ./hub1.conf &
hub_pid=$!
sleep 1
(echo '{"method":"publish", "params":{"channel":"test"}, "id":1}'; sleep 1) | telnet  0.0.0.0 12346 
sleep 1
kill $hub_pid
kill $proxy_pid
kill $cmd_pid
sleep 1
echo "-------------------------------------------------------------------------------------------------------------------------------"
result=`cat test.txt | grep publish | wc -l`
if [ $result == "1" ];
then
  echo 'DONE'
else
  echo 'ERROR'
fi
