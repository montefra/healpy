/*
 *  This file is part of libcxxsupport.
 *
 *  libcxxsupport is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  libcxxsupport is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libcxxsupport; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 *  libcxxsupport is being developed at the Max-Planck-Institut fuer Astrophysik
 *  and financially supported by the Deutsches Zentrum fuer Luft- und Raumfahrt
 *  (DLR).
 */

/*! \file pointing.cc
 *  Class representing a direction in 3D space
 *
 *  Copyright (C) 2003-2011 Max-Planck-Society
 *  \author Martin Reinecke
 */

#include "pointing.h"
#include "lsconstants.h"
#include "math_utils.h"

using namespace std;

vec3 pointing::to_vec3() const
  {
  double st=sin(theta);
  return vec3 (st*cos(phi), st*sin(phi), cos(theta));
  }
void pointing::from_vec3 (const vec3 &inp)
  {
  theta = atan2(sqrt(inp.x*inp.x+inp.y*inp.y),inp.z);
  phi = safe_atan2 (inp.y,inp.x);
  if (phi<0.) phi += twopi;
  }
void pointing::normalize()
  {
  theta=fmodulo(theta,twopi);
  if (theta>pi)
    {
    phi+=pi;
    theta=twopi-theta;
    }
  phi=fmodulo(phi,twopi);
  }

ostream &operator<< (ostream &os, const pointing &p)
  {
  os << p.theta << ", " << p.phi << std::endl;
  return os;
  }
