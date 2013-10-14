/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "findMax_vff_impl.h"

namespace gr {
  namespace greene {

    findMax_vff::sptr
    findMax_vff::make(int len)
    {
      return gnuradio::get_initial_sptr
        (new findMax_vff_impl(len));
    }

    /*
     * The private constructor
     */
    findMax_vff_impl::findMax_vff_impl(int len)
      : gr::block("findMax_vff",
		gr::io_signature::make(1, 1, len * sizeof (float)),
		gr::io_signature::make(2, 2, sizeof (float)))
    {d_len = len;}

    /*
     * Our virtual destructor.
     */
    findMax_vff_impl::~findMax_vff_impl()
    {
    }

    void
    findMax_vff_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
        ninput_items_required[0] = noutput_items;
    }

    int
    findMax_vff_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        // Setup Outputs
		float *max_value = (float *) output_items[0];
        float *max_index = (float *) output_items[1];
		
        // Do <+signal processing+>
        for(int i = 0; i < noutput_items; i++) {
        
			// Set first value as max
			float value = ((const float *) input_items[0])[0];
			int search_index = 0;
			
			// Search for next max
			for (int index = 1; index < d_len; index++)
				if (((const float *) input_items[0])[index] > value) {
					value = ((const float *) input_items[0])[index];
					search_index = index;
				}
				
			// Set output values	
			*max_value++ = value;
			*max_index++ = search_index;

		}
		
        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace greene */
} /* namespace gr */

