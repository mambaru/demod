export LD_LIBRARY_PATH=/home/migashko/prj/phantom/lib/pantom
export PATH=$PATH:/home/migashko/prj/yandex-tank:/home/migashko/prj/phantom/bin:`pwd`
echo $PATH
tank.py -l /tmp/tank/load.log -o "tank.artifacts_base_dir=/tmp/tank/result" -o "tank.artifacts_dir=/tmp/tank/result" -o "tank.lock_dir=/tmp/tank/lock" -o "tank.phantom_modules_path=/home/migashko/prj/phantom/bin" $@