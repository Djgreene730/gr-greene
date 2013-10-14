#!/bin/sh
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/iaa/gnuradio/gr-greene/lib
export PATH=/home/iaa/gnuradio/gr-greene/build/lib:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DYLD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DYLD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-greene 
