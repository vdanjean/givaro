/* -*- mode: C++; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
// vim:sts=8:sw=8:ts=8:noet:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s
/* field/modular-balanced-double.h
 * Copyright (C) 2003 Pascal Giorgi
 *               2005 Clement Pernet
 * Written by Pascal Giorgi <pascal.giorgi@ens-lyon.fr>
 * and Clement Pernet <Clement.Pernet@imag.fr>
 * and Brice Boyer <bboyer@imag.fr>
 *
 * ------------------------------------
 *
 *
 * ========LICENCE========
 * This file is part of the library FFLAS-FFPACK.
 *
 * FFLAS-FFPACK is free software: you can redistribute it and/or modify
 * it under the terms of the  GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * ========LICENCE========
 *.
 */

/*! @file field/modular-balanced.h
 * @ingroup field
 * @brief Balanced representation of <code>Z/mZ</code> over several types .
 */

#ifndef __GIVARO_modular_balanced_H
#define __GIVARO_modular_balanced_H

#include <givaro/givconfig.h>

#include "givaro/modular-balanced-double.h"
#include "givaro/modular-balanced-float.h"
#include "givaro/modular-balanced-int32.h"
#include "givaro/modular-balanced-integer.h"

#ifndef __DONOTUSE_Givaro_SIXTYFOUR__
#include "givaro/modular-balanced-int64.h"
#endif

#endif // __GIVARO_modular_balanced_double_H
