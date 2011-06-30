/*
 *  nf.h
 *  PolyBoRi
 *
 *  Created by Michael Brickenstein on 25.04.06.
 *  Copyright 2006 The PolyBoRi Team. See LICENSE file.
 *
 */
#include <algorithm>
#include <vector>
#include <queue>

#include "SlimgbReduction.h"
#include "LMLessCompare.h"
#include "groebner_alg.h"


#if HAVE_M4RI
extern "C"{
#include <m4ri/m4ri.h>

#ifndef __M4RI_TWOPOW
#define __M4RI_TWOPOW TWOPOW
#endif
}
#endif
#ifndef PBORI_GB_NF_H
#define PBORI_GB_NF_H
BEGIN_NAMESPACE_PBORIGB


void drawmatrix(mzd_t* mat, const char* filename);

Polynomial add_up_exponents(const std::vector<Exponent>& vec,
			    const Polynomial& init);
Polynomial add_up_monomials(const std::vector<Monomial>& res_vec,
			    const Polynomial& init);


int select_no_deg_growth(const ReductionStrategy& strat, const Monomial& m);




typedef SlimgbReduction<SLIMGB_SIMPLEST> slimgb_reduction_type;
std::vector<Polynomial> parallel_reduce(std::vector<Polynomial> inp, GroebnerStrategy& strat, int average_steps, double delay_f);
Polynomial red_tail(const ReductionStrategy& strat, Polynomial p);
Polynomial red_tail_short(const ReductionStrategy& strat, Polynomial p);
Polynomial nf3(const ReductionStrategy& strat, Polynomial p, Monomial rest_lead);
Polynomial nf3_short(const ReductionStrategy& strat, Polynomial p);
Polynomial ll_red_nf(const Polynomial& p,const BooleSet& reductors);

Polynomial ll_red_nf_noredsb(const Polynomial& p,const BooleSet& reductors);
Polynomial add_up_polynomials(const std::vector<Polynomial>& vec,
			      const Polynomial& init);
Polynomial plug_1(const Polynomial& p, const MonomialSet& m_plus_ones);
MonomialSet mod_mon_set(const MonomialSet& as, const MonomialSet &vs);
std::vector<Polynomial> gauss_on_polys(const std::vector<Polynomial>& orig_system);
Polynomial ll_red_nf_noredsb_single_recursive_call(const Polynomial& p,const BooleSet& reductors);
Polynomial cheap_reductions(const ReductionStrategy& strat, Polynomial p);

Polynomial nf3_lexbuckets(const GroebnerStrategy& strat, Polynomial p, Monomial rest_lead);
Polynomial nf3_no_deg_growth(const ReductionStrategy& strat, Polynomial p, Monomial rest_lead);
Polynomial nf3_degree_order(const ReductionStrategy& strat, Polynomial p, Monomial lead);
Polynomial nf3_short(const ReductionStrategy& strat, Polynomial p);

template <class T>
inline Polynomial
add_up_generic(const std::vector<T>& res_vec, int
start, int end, Polynomial init){
    //we assume the polynomials to be pairwise different
    int s=end-start;
    if (s==0) return init;
    if (s==1) return Polynomial(res_vec[start]);
    int h=s/2;
    return add_up_generic(res_vec,start,start+h,init) +
      add_up_generic(res_vec,start+h,end, init);
}

template <class T>
inline Polynomial
add_up_generic(const std::vector<T>& res_vec,
                                             Polynomial init){
    //we assume the polynomials to be pairwise different
    int s=res_vec.size();
    if (s==0) return init;
    if (s==1) return (Polynomial) res_vec[0];
    int h=s/2;
    
    return add_up_generic(res_vec,0,h, init) + 
      add_up_generic(res_vec,h,s, init);
}



END_NAMESPACE_PBORIGB
#endif
