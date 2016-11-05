/* ============================================================================
 * I B E X - CtcSegment Tests
 * ============================================================================
 * Copyright   : Ecole des Mines de Nantes (FRANCE)
 * License     : This program can be distributed under the terms of the GNU LGPL.
 *               See the file COPYING.LESSER.
 *
 * Author(s)   : Benoit Desrochers, Gilles Chabert
 * Created     : Jan 06, 2014
 * ---------------------------------------------------------------------------- */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "catch_interval.hpp"

#include "ibex_CtcSegment.h"

// using namespace std;
using namespace ibex;
using namespace Catch;
using namespace Detail;


TEST_CASE("test_contract_segment", "")
{
    CtcSegment c(0,0,10,20);
    double _box[][2] = {{-5,50},  {-5,50}};
    IntervalVector box(2,_box);

    double _resbox[][2] = {{0,10},  {0,20}};
    IntervalVector resbox(2,_resbox);

    c.contract(box);
    CHECK(box == resbox);

}

TEST_CASE("test_contract_border", "")
{
    CtcSegment c(0,0,10,20);
    double _box[][2] = {{10,50},  {20,50}};
    IntervalVector box(2,_box);

    double _resbox[][2] = {{10,10},  {20,20}};
    IntervalVector resbox(2,_resbox);

    c.contract(box);

    CHECK(box == resbox);
}

TEST_CASE("test_contract_degenerate", "")
{
    CtcSegment c(5,5,5,5);
    double _box[][2] = {{-5,50},  {-5,50}};
    IntervalVector box(2,_box);

    double _resbox[][2] = {{5,5},  {5,5}};
    IntervalVector resbox(2,_resbox);

    c.contract(box);

    CHECK(box == resbox);
}

TEST_CASE("test_contract_empty", "")
{
    CtcSegment c(0,0,10,20);
    //double _box[][2] = {{-5,-2},  {-5,50}};
    IntervalVector box = IntervalVector::empty(2);

    c.contract(box);

	  CHECK(box.is_empty());
}


TEST_CASE("test_call_with_empty_box", "")
{
    CtcSegment c(0,0,10,20);
    //double _box[][2] = {{-5,50},  {-5,50}};
    IntervalVector box = IntervalVector::empty(2);

	c.contract(box);

	CHECK(box.is_empty());
}

TEST_CASE("test_call_with_all_real", "")
{
    CtcSegment c(0,0,10,20);
    //double _box[][2] = {{-5,50},  {-5,50}};
    IntervalVector box(2,Interval::ALL_REALS);

    double _resbox[][2] = {{0,10},  {0,20}};
    IntervalVector resbox(2,_resbox);

    c.contract(box);
    CHECK(box == resbox);
}

TEST_CASE("test_successive_calls", "")
{
    CtcSegment c(0,0,10,10);


    IntervalVector box1(2,Interval::ALL_REALS), resbox1(2,Interval(0,10));
    c.contract(box1);
    CHECK(box1 == resbox1);



    IntervalVector box2(2,Interval(-20,-10)), resbox2(2,Interval::EMPTY_SET);
    c.contract(box2);
    CHECK(box2 == resbox2);



    IntervalVector box3(2,Interval::ALL_REALS), resbox3(2,Interval(0,10));
    c.contract(box3);
    CHECK(box3 == resbox3);
}
