cd ..
echo "#### COMPILATION ####"
~/Qt5.2.0/5.2.0/gcc_64/bin/qmake FactDev.pro -r -spec linux-g++ CONFIG+=debug >> /dev/null
make -j9 >> /dev/null
LD_LIBRARY_PATH=`pwd`/src
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH
Xvfb :1 &
ln -s `pwd`/src/sql `pwd`/tests/sql
echo "### TESTS EXECUTION"
cd tests
DISPLAY=:1 ./tests 127.0.0.1 FactDev FactDev
pkill Xvfb
