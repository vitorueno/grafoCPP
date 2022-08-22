#!/bin/sh

rm -rf build 
rm -rf a.out
mkdir -p build
cd build
cmake ..
make 

ln -sr a.out ..