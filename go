#!/bin/bash
sudo rm -rf build
mkdir build
cd build/
cmake ../
make
make test
sudo make install
sudo ldconfig
