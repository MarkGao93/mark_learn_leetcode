#!/bin/bash

# rm -rf build

if [ ! -d "build" ]; then
	mkdir build
fi

# QTDIR="$( cd "$( dirname "$0"  )" && pwd  )""/thirdparty/qt"

cd build
# cmake .. -DCMAKE_PREFIX_PATH=${QTDIR} -DCMAKE_BUILD_TYPE=Release
cmake .. -DCMAKE_BUILD_TYPE=Debug
# make -j8
make -j8

cp ./bin/marklearnleetcode ../common/bin
cp -r ./lib/ ../common/
cd ..


./common/bin/marklearnleetcode