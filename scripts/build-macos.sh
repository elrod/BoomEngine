#! /bin/bash

SOLUTION_ROOT=$(dirname $(dirname $(readlink -f "$0")))
pushd $SOLUTION_ROOT
rm -rf dist/macos/
rm -rf build/
cmake -S . -B build -DTARGET_PLATFORM=macos
cmake --build build
popd