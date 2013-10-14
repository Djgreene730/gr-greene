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


#ifndef INCLUDED_GREENE_FINDMAX_VFF_H
#define INCLUDED_GREENE_FINDMAX_VFF_H

#include <greene/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace greene {

    /*!
     * \brief <+description of block+>
     * \ingroup greene
     *
     */
    class GREENE_API findMax_vff : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<findMax_vff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of greene::findMax_vff.
       *
       * To avoid accidental use of raw pointers, greene::findMax_vff's
       * constructor is in a private implementation
       * class. greene::findMax_vff::make is the public interface for
       * creating new instances.
       */
      static sptr make(int len);
    };

  } // namespace greene
} // namespace gr

#endif /* INCLUDED_GREENE_FINDMAX_VFF_H */

