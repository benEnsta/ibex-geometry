//============================================================================
//                                  I B E X
// Author      : Mohamed Saad Ibn Seddik
//       Inspired from the work of  Benoit Desrochers
// Copyright   : Mohamed Saad Ibn Seddik
// License     : LGPL v3
// Created     : May 24, 2015
// Last Update : May 24, 2015
//============================================================================

#include "ibex_CtcPolar.h"

namespace ibex {

CtcPolar::CtcPolar() : Ctc(4) {}

CtcPolar::~CtcPolar() {}


void _contract(Interval &x, Interval& y,
                        Interval& rho, Interval& theta){
  // const double d2PI   = (2*Interval::PI).ub();

  // Interval theta_tmp = atan2(y, x);
  // bwd_imod(theta_tmp, theta, d2PI);
  // bwd_angle(theta, y, x);

  std::tie(x,   y, theta) = Catan2(x, y, theta);


  Interval a1 = sqr(x);
  Interval a2 = sqr(y);
  Interval a3 = a1 + a2;
  Interval a4 = sqr(rho);

  a4 &= a3;
  a3 &= a4;

  bwd_sqr(a4, rho);
  bwd_add(a3, a2, a1);
  bwd_sqr(a1, x);
  bwd_sqr(a2, y);

  Interval x1 = rho*cos(theta);
  Interval y1 = rho*sin(theta);
  x &= x1;
  y &= y1;
  if(x.is_empty() || y.is_empty() || rho.is_empty() || theta.is_empty()){
    x.set_empty(); y.set_empty();
    rho.set_empty(); theta.set_empty();
  }
}

void CtcPolar::contract(Interval &x, Interval& y,
                        Interval& rho, Interval& theta){
  // std::cout << rho << " -- " ;
  _contract(x,y,rho, theta);
  _contract(x,y,rho, theta);
  // std::cout << rho << "\n";

}

IntervalVector CtcPolar::RTfromXY(Interval x, Interval y){

  Interval rho(0, 1e10);
  Interval theta(-0.99*M_PI, M_PI);
  contract(x, y, rho, theta);
  IntervalVector res(2);
  res[0] = rho; res[1] = theta;
  return res;
}


void CtcPolar::contract(IntervalVector &box) {
  _contract(box[0], box[1], box[2], box[3]);
  _contract(box[0], box[1], box[2], box[3]);
}

}  // namespace ibex
