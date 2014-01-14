curdir=`dirname $0`
#curdir=`pwd`
export LD_LIBRARY_PATH=/home/migashko/prj/phantom/lib
export PATH=$PATH:/home/migashko/prj/yandex-tank:/home/migashko/prj/phantom/bin:$curdir

tank.py -l `pwd`/load.log -o "tank.artifacts_base_dir=`pwd`/result" -o "tank.artifacts_dir=`pwd`/result" $@