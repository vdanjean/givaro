// ==========================================================================
// $Source: /var/lib/cvs/Givaro/src/kernel/gmp++/gmp++_int_add.C,v $
// Copyright(c)'1994-2009 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: M. Samama, T. Gautier
// $Id: gmp++_int_add.C,v 1.5 2010-12-20 12:09:37 briceboyer Exp $
// ==========================================================================


#ifndef __GIVARO_gmpxx_gmpxx_rat_add_C
#define __GIVARO_gmpxx_gmpxx_rat_add_C

#ifndef __GIVARO_INLINE_ALL
#include "gmp++/gmp++.h"
#endif

namespace Givaro {
	//-------------------------------------------------- operator +
	Rationel& Rationel::addin(Rationel& res, const Rationel& n)
	{
		if (isZero(n)) return res;
		if (isZero(res)) return res = n;
		mpq_add( (mpq_ptr)&res.gmp_rep, (mpq_srcptr)&res.gmp_rep, (mpq_srcptr)&n.gmp_rep );
		return res;
	}

	Rationel& Rationel::addin(Rationel& res, const Integer& n)
	{
		if (Givaro::isZero(n)) return res;
		Rationel nn ;
		setInteger(nn,n);
		if (isZero(res)) return res = nn;
		mpq_add( (mpq_ptr)&res.gmp_rep, (mpq_srcptr)&res.gmp_rep, (mpq_srcptr)&nn.gmp_rep );
		return res;
	}

#if 0
	Rationel& Rationel::addin(Rationel& res, const int64_t n)
	{
		if (isZero(n)) return res;
		if (isZero(res)) return res = n;
		int32_t sgn = sign(n);
		if (sgn >0) mpz_add_ui( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, n);
		else mpz_sub_ui((mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, -n);
		return res;
	}
	Rationel& Rationel::addin(Rationel& res, const uint64_t n)
	{
		if (isZero(n)) return res;
		if (isZero(res)) return res = n;
		mpz_add_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&res.gmp_rep, n);
		return res;
	}

	Rationel& Rationel::add(Rationel& res, const Integer& n1, const Integer& n2)
	{
		if (isZero(n1)) return res = n2;
		if (isZero(n2)) return res = n1;
		mpz_add( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n1.gmp_rep, (mpz_srcptr)&n2.gmp_rep);
		return res;
	}
	Rationel& Rationel::add(Rationel& res, const Integer& n1, const int64_t n2)
	{
		if (isZero(n1)) return res = n2;
		if (isZero(n2)) return res = n1;
		int32_t sgn = sign(n2);
		if (sgn >0) mpz_add_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n1.gmp_rep, n2);
		else mpz_sub_ui((mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n1.gmp_rep, -n2);
		return res;
	}
	Rationel& Rationel::add(Rationel& res, const Integer& n1, const uint64_t n2)
	{
		if (isZero(n1)) return res = n2;
		if (isZero(n2)) return res = n1;
		mpz_add_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n1.gmp_rep, n2);
		return res;
	}

	// -- operator +

	Integer& Integer::operator += (const Integer& n)
	{
		if (isZero(n)) return *this;
		if (isZero(*this)) return logcpy(n);
		mpz_add( (mpz_ptr)&(gmp_rep), (mpz_ptr)&gmp_rep, (mpz_srcptr)&n.gmp_rep) ;
		return *this;
	}

	Integer& Integer::operator += (const uint64_t l)
	{
		if (l==0) return *this;
		if (isZero(*this)) return logcpy(Integer(l));
		mpz_add_ui( (mpz_ptr)&(gmp_rep), (mpz_ptr)&gmp_rep, l);
		return *this;
	}

	Integer& Integer::operator += (const int64_t l)
	{
		if (l==0) return *this;
		if (isZero(*this)) return logcpy(Integer(l));
		int32_t sgn = sign(l);
		if (sgn >0) mpz_add_ui( (mpz_ptr)&(gmp_rep), (mpz_ptr)&gmp_rep, l);
		else mpz_sub_ui( (mpz_ptr)&(gmp_rep), (mpz_ptr)&gmp_rep, -l);
		return *this;
	}


	Integer Integer::operator + (const Integer& n) const
	{
		if (isZero(n)) return *this;
		if (isZero(*this)) return n;
		Integer res;
		mpz_add( (mpz_ptr)&(res.gmp_rep), (mpz_srcptr)&gmp_rep, (mpz_srcptr)&n.gmp_rep) ;
		return res;
	}

	Integer Integer::operator + (const uint64_t l) const
	{
		if (l==0) return *this;
		if (isZero(*this)) return Integer(l);
		Integer res;
		mpz_add_ui( (mpz_ptr)&(res.gmp_rep), (mpz_srcptr)&gmp_rep, l);
		return res;
	}

	Integer Integer::operator + (const int64_t l) const
	{
		if (l==0) return *this;
		if (isZero(*this)) return Integer(l);
		Integer res;
		int32_t sgn = sign(l);
		if (sgn >0) mpz_add_ui( (mpz_ptr)&(res.gmp_rep), (mpz_srcptr)&gmp_rep, l);
		else mpz_sub_ui( (mpz_ptr)&(res.gmp_rep), (mpz_srcptr)&gmp_rep, -l);
		return res;
	}

	Integer Integer::operator - () const
	{
		// JGD 18.06.1999
		Integer Res ;
		mpz_neg((mpz_ptr)&Res.gmp_rep, (mpz_srcptr)&gmp_rep );
		return Res ;
	}

	Integer operator + (const int32_t l, const Integer& n)
	{
		return n + (int64_t)l;
	}
	Integer operator + (const uint32_t l, const Integer& n)
	{
		return n + (uint64_t)l;
	}
	Integer operator + (const int64_t l, const Integer& n)
	{
		return n + l;
	}
	Integer operator + (const uint64_t l, const Integer& n)
	{
		return n + l;
	}
	Integer operator + (const Integer& n, const int32_t l)
	{
		return n + (int64_t)l;
	}
	Integer operator + (const Integer& n, const uint32_t l)
	{
		return n + (uint64_t)l;
	}

	Integer& operator += (Integer& n, const int32_t l)
	{
		return n += (int64_t)l;
	}
	Integer& operator += (Integer& n, const uint32_t l)
	{
		return n += (uint64_t)l;
	}


#endif


}

#endif // __GIVARO_gmpxx_gmpxx_int_add_C

// vim:sts=8:sw=8:ts=8:noet:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s:syntax=cpp.doxygen
