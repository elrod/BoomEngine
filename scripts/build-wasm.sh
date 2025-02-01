#! /bin/bash

SOLUTION_ROOT=$(dirname $(dirname $(readlink -f "$0")))
pushd $SOLUTION_ROOT
rm -rf dist/webassembly/
rm -rf build/
emcmake cmake -S . -B build -DTARGET_PLATFORM=webassembly
cmake --build build
popd