//============================================================================
//                                  I B E X
// Author      : Mohamed Saad Ibn Seddik
//       Inspired from the work of  Benoit Desrochers
// Copyright   : Mohamed Saad Ibn Seddik
// License     : LGPL v3
// Created     : May 25, 2015
// Last Update : May 2%, 2015
//============================================================================

#ifndef __IBEX_CTC_ANGLE_H__
#define __IBEX_CTC_ANGLE_H__

#include "ibex_IntervalVector.h"
#include "ibex_Ctc.h"
#include <tuple>
using namespace std;

namespace ibex {

/**
 * \ingroup geometry
 * Minimal contractor for the polar constraint:
 *  theta    = angle(x,y)
 */
class CtcAngle : public Ctc {

public:
  CtcAngle();

  /**
   * @brief Contract the box
   * @details Contract the box according to the polar constraints
   *
   * @param box Box of Intervals to contract. box=([x],[y],[rho],[theta])
   */
  virtual void contract(IntervalVector& box);

  /**
   * @brief Contract a the given intervals.
   *
   * @param x Interval x
   * @param y Interval y
   * @param theta Interval theta
   */
  void contract(Interval &x, Interval& y, Interval& theta);

  /**
   * \brief Delete this.
   */
  ~CtcAngle();

protected:
};

inline Interval Cmod(const Interval& x, const Interval& y){
  Interval xx(x);
  Interval yy(y);
  bwd_imod(xx,yy,2*Interval::PI.ub());
  return yy;
}

inline Interval Cmod_bwd(const Interval& x, const Interval& y){
  Interval xx(x);
  Interval yy(y);
  bwd_imod(xx,yy,2*Interval::PI.ub());
  return xx;
}



inline std::tuple<Interval, Interval, Interval> Catan2(const Interval&x, const Interval&y, const Interval& th){
  static const Interval iZeroPi2 = Interval(0) | (Interval::HALF_PI);
  static const Interval iPi2Pi = (Interval::HALF_PI) | Interval::PI;
  const double ITV2PI = 2*Interval::PI.ub();
  // static const Interval 2PI_UB = 2*Interval::PI.ub();
  if (x.is_empty() || y.is_empty() || th.is_empty()) {
      return std::make_tuple(Interval::EMPTY_SET, Interval::EMPTY_SET, Interval::EMPTY_SET);
  }
  if ( x.is_subset(Interval::POS_REALS) && y.is_subset(Interval::POS_REALS) && th.is_subset(iZeroPi2) ) {

    if (x == Interval::ZERO && y == Interval::ZERO){
      return std::make_tuple(Interval::EMPTY_SET, Interval::EMPTY_SET, Interval::EMPTY_SET);
    }

    Interval th_tmp = Cmod(th, iZeroPi2);

    // trick to keep tan(th) > 0 because we only consider x >= 0 and y>= 0
    Interval tan_lb = tan(Interval(th_tmp.lb()));
    Interval tan_ub = (th_tmp.ub() == Interval::HALF_PI.ub()) ? Interval(std::numeric_limits<double>::max(), POS_INFINITY)  : tan(Interval(th_tmp.ub()));
    Interval tanTh = tan_lb | tan_ub;
    // Interval tanTh = tan(th_tmp) & Interval(0, POS_INFINITY);

    Interval xx = x & y/tanTh;
    Interval yy = ( x != Interval::ZERO) ? y & x*tanTh : y;
    Interval thr =  th_tmp & ( ( x != Interval::ZERO ) ? atan(y/x) : Interval::HALF_PI );
    // cout << "XX " << xx << " " << tanTh << y/tanTh << "\n";
    // cout << "YY " << yy << " " << tanTh << x*tanTh << "\n";
    // cout << "TH " << th << " " <<  thr << " " << th_tmp << atan(y/x) << "\n";
    if (xx.is_empty() || yy.is_empty() || thr.is_empty() ){
      return std::make_tuple(Interval::EMPTY_SET, Interval::EMPTY_SET, Interval::EMPTY_SET);
    }

    return std::make_tuple(xx, yy, thr);
  }

  // Divide into four quadrats  and call contractor
  //  x > 0 and y > 0 and th \in [0, PI/2.]
  Interval x1 = x & Interval::POS_REALS;
  Interval y1 = y & Interval::POS_REALS;
  Interval th1 = Cmod(th,iZeroPi2);
  std::tie(x1, y1, th1) = Catan2(x1, y1, th1);
  Interval th11 = Cmod_bwd(th, th1);
  // bwd_imod(th11, th1, ITV2PI);

  // x > 0, y < 0 , th \in [-PI/2., 0]
  Interval x2 = x & Interval::POS_REALS;
  Interval y2 = y & Interval::NEG_REALS;
  Interval th2 = -Cmod(th, -iZeroPi2);
  std::tie(x2, y2, th2) = Catan2(x2, -y2, th2);
  Interval th22 = Cmod_bwd(th, -th2);
  // bwd_imod(th22, -th2, ITV2PI);

  // x < 0, y < 0 , th \in [-PI, -PI/2.]
  Interval x3 = x & Interval::NEG_REALS;
  Interval y3 = y & Interval::NEG_REALS;
  Interval th3 = Interval::PI + Cmod(th, -iPi2Pi);
  std::tie(x3, y3, th3) = Catan2(-x3, -y3, (th3 &  iZeroPi2) );
  Interval th33 = Cmod_bwd(th, th3 - Interval::PI);
  // bwd_imod(th33, th3 - Interval::PI, ITV2PI);

  // x < 0, y > 0 , th \in [PI/2., PI]
  Interval x4 = x & Interval::NEG_REALS;
  Interval y4 = y & Interval::POS_REALS;
  Interval th4 = Interval::PI - Cmod( th,iPi2Pi);
  std::tie(x4, y4, th4) = Catan2(-x4, y4, ( th4 & iZeroPi2) );
  Interval th44 = Cmod_bwd(th, Interval::PI -  th4);
  // bwd_imod(th44, Interval::PI -  th4, ITV2PI);

  Interval xx =   ( x1 | x2 | (-x3) | (-x4) );
  Interval yy =   ( y1 | (-y2) | (-y3) | (y4) );
  Interval thh =  ( th11 | (th22) | ( th33 ) | ( th44 ) );
  return std::make_tuple(xx,yy,thh);

}

inline bool bwd_angle(const Interval& theta, Interval& y, Interval& x) {

  if (theta.is_empty()) {
    x.set_empty(); y.set_empty();
    return false;
  }

    // Quadrant Intervals that are disjoint
    static const Interval iZero_PIo4(Interval::ZERO      | Interval::PI/4);
    static const Interval iZero_PIo2(Interval::ZERO      | Interval::HALF_PI);
    static const Interval iPIo4_PIo2(Interval::PI/4      | Interval::HALF_PI);
    static const Interval iPIo2_PI(Interval::HALF_PI     | Interval::PI);
    static const Interval iPI_3PIo2(Interval::PI         | 3*Interval::HALF_PI);
    static const Interval i3PIo2_2PI(3*Interval::HALF_PI | 2*Interval::PI);
    static const Interval iZero_PI(Interval::ZERO        | Interval::PI);
    static const Interval iZero_3PIo2(Interval::ZERO     | 3*Interval::HALF_PI);
    static const Interval iZero_2PI(Interval::ZERO       | 2*Interval::PI);

    // Quadrant limits defined from the intervals
    static const double dPIo4  = (Interval::PI/4).ub();
    static const double dPIo2  = (Interval::HALF_PI).ub();
    static const double d3PIo2 = (3*Interval::HALF_PI).ub();
    static const double dPI    = (Interval::PI).ub();
    static const double d2PI   = (2*Interval::PI).ub();

   //Lower half of upper right quadrant
   if(theta.is_subset(iZero_PIo4))
   {
       x = (x&Interval::POS_REALS) & ( (y&Interval::POS_REALS) * (1/tan( theta & iZero_PIo4)));
       y = (y&Interval::POS_REALS) & ( (x&Interval::POS_REALS) * (tan( theta & iZero_PIo4)));
   }

   //Upper half of upper right quadrant
   else if(theta.is_subset(iPIo4_PIo2))
   {
       bwd_angle(dPIo2-theta,x,y);
   }

   //Upper right quadrant
   else if(theta.is_subset(iZero_PIo2))
   {
       Interval x1=x; Interval y1=y; Interval x2=x; Interval y2=y;
       Interval theta1(theta.lb(),dPIo4), theta2(dPIo4, theta.ub());
       bwd_angle(theta1,y1,x1);
       bwd_angle(theta2,y2,x2);
       x=x1|x2; y=y1|y2;
   }

   //Upper left quadrant
   else if(theta.is_subset(iPIo2_PI))
   {
       Interval x2=-x;
       Interval theta2=dPI-theta;
       bwd_angle(theta2,y,x2);
       x=-x2;
   }

   //Lower left quadrant
   else if(theta.is_subset(iPI_3PIo2))
   {
       Interval y2=-y;
       Interval x2=-x;
       Interval theta2=theta-dPI;
       bwd_angle(theta2,y2,x2);
       x=-x2; y=-y2;
   }

   //Lower right quadrant
   else if(theta.is_subset(i3PIo2_2PI))
   {
       Interval x2=x;
       Interval y2=-y;
       Interval theta2=d2PI-theta;
       bwd_angle(theta2,y2,x2);
       x=x2; y=-y2;
   }

   //Upper bissection
   else if(theta.is_subset(iZero_PI)) {
       Interval theta1(theta.lb(),dPIo2), theta2(dPIo2, theta.ub());
       Interval x1=x; Interval y1=y; Interval x2=x; Interval y2=y;
       if(theta.lb() != dPIo2) bwd_angle(theta1,y1,x1);
       if(theta.ub() != dPIo2) bwd_angle(theta2,y2,x2);
       x=x1|x2; y=y1|y2;
   }

   //Left bissection
   else if(theta.is_subset(iZero_3PIo2)) {
       Interval theta1(theta.lb(),dPI), theta2(dPI, theta.ub());
       Interval x1=x; Interval y1=y; Interval x2=x; Interval y2=y;
       if(theta.lb() != dPI) bwd_angle(theta1,y1,x1);
       if(theta.ub() != dPI) bwd_angle(theta2,y2,x2);
       x=x1|x2; y=y1|y2;
   }

   //Lower bissection
   else if(theta.is_subset(iZero_2PI)) {
       Interval theta1(theta.lb(),3*dPIo2), theta2(3*dPIo2, theta.ub());
       Interval x1=x; Interval y1=y; Interval x2=x; Interval y2=y;
       if(theta.lb() != 3*dPIo2) bwd_angle(theta1,y1,x1);
       if(theta.ub() != 3*dPIo2) bwd_angle(theta2,y2,x2);
       x=x1|x2; y=y1|y2;
   }

   //Theta diameter greater than 2PI then theta will be considered as [0,2PI]
   else if (theta.diam() > d2PI)
   {
       Interval theta1(0,d2PI);
       bwd_angle(theta1,x,y);
   }

   // Modulo
   else
   {
       // We separate the intervals into 4 cases as imod does not support union.
       Interval theta1(0,dPIo2), theta2(dPIo2, dPI), theta3(dPI, 3*dPIo2), theta4(3*dPIo2, d2PI);
       Interval thetaTmp(theta);
       bwd_imod(thetaTmp,theta1,d2PI);
       thetaTmp=theta;
       bwd_imod(thetaTmp,theta2,d2PI);
       thetaTmp=theta;
       bwd_imod(thetaTmp,theta3,d2PI);
       thetaTmp=theta;
       bwd_imod(thetaTmp,theta4,d2PI);
       Interval x1=x; Interval y1=y;
       bwd_angle(theta1,y1,x1); // first quadrant
       Interval x2=x; Interval y2=y;
       bwd_angle(theta2,y2,x2); // second quadrant
       Interval x3=x; Interval y3=y;
       bwd_angle(theta3,y3,x3); // third quadrant
       Interval x4=x; Interval y4=y;
       bwd_angle(theta4,y4,x4); // fourth quadrant
       x=(x1|x2)|(x3|x4); y=(y1|y2)|(y3|y4);
       // not_implemented("bwd_atan2 not implemented yet for theta outside [0,2*PI].");
   }


   return !x.is_empty() || !y.is_empty();
}


}  // namespace ibex

#endif // __IBEX_CTC_ANGLE_H__
