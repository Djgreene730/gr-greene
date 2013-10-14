/* -*- c++ -*- */

#define GREENE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "greene_swig_doc.i"

%{
#include "greene/findMax_vff.h"
%}


%include "greene/findMax_vff.h"
GR_SWIG_BLOCK_MAGIC2(greene, findMax_vff);
