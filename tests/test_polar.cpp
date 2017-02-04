#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "catch_interval.hpp"

#include "ibex_CtcAngle.h"

using namespace ibex;
using namespace Catch;
using namespace Detail;

bool checkbwd_atan2(const Interval& a, const Interval& y_bef, const Interval& x_bef,
								const Interval& y_aft, const Interval& x_aft) {
	bool res=true;
	Interval y;
	Interval x;

	y=y_bef;
	x=x_bef;
	bwd_angle(a,y,x);
	std::cout << "x1=" << x << " x2=" << y << std::endl;

	CHECK ( ApproxIntv(x) == x_aft);
	CHECK ( ApproxIntv(y) == y_aft);

	return res;
}

TEST_CASE("bwd_atan2_01", "") {
	checkbwd_atan2( Interval(M_PI/6.,M_PI/3.),
												Interval(.5,10),
												Interval(.5,2),
												Interval(0.5,2*sqrt(3.)),
												Interval(0.5,2.)
	);
}
TEST_CASE( "bwd_atan2_02" , "") {
	checkbwd_atan2(Interval(M_PI/4.,3*M_PI/4.),Interval(1.,2.), Interval(-100.,100.), Interval(1.,2.), Interval(-2,2));
}
