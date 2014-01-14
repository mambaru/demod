export LD_LIBRARY_PATH=/home/migashko/prj/phantom/lib
export PATH=$PATH:/home/migashko/prj/yandex-tank:/home/migashko/prj/phantom/bin:`pwd`
echo $PATH
tank.py -l load.log -o "tank.artifacts_base_dir=`pwd`/result" -o "tank.artifacts_dir=`pwd`/result" $@