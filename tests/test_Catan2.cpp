
// ============================================================================
//                                P Y I B E X
// File        : test_Catan2.cpp
// Author      : Benoit Desrochers
// Copyright   : Benoit Desrochers
// License     : See the LICENSE file
// Created     : Feb 05, 2016
// ============================================================================

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "catch_interval.hpp"

#include "ibex_CtcAngle.h"

using namespace ibex;
using namespace Catch;
using namespace Detail;

TEST_CASE( "test_POS_REALS", "") {

    Interval xx, yy, thh;
    std::tie(xx, yy, thh) = Catan2(Interval::POS_REALS, Interval::POS_REALS, Interval::HALF_PI | Interval(0));
    CHECK( xx  == Interval::POS_REALS);
    CHECK( yy  == Interval::POS_REALS);
    CHECK( thh  == (Interval::HALF_PI | Interval(0))  );
}

TEST_CASE( "test_ZEROS", "") {
    Interval xx, yy, thh;
    std::tie(xx, yy, thh) = Catan2(Interval(0), Interval(0), Interval::HALF_PI | Interval(0));

    CHECK( xx == Interval::EMPTY_SET);
    CHECK( yy == Interval::EMPTY_SET);
    CHECK( thh == Interval::EMPTY_SET);
}

TEST_CASE( "test_HALF_PI", "") {
    Interval xx, yy, thh;
    std::tie(xx, yy, thh) = Catan2(Interval(0), Interval(1,4), Interval::HALF_PI);

    CHECK( xx == Interval(0));
    CHECK( yy == Interval(1,4));
    CHECK( thh == Interval::HALF_PI);
}

TEST_CASE("test_Catan2_000", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.999999999998cp-1, 0x1.6666666666672p+1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(NAN, NAN));
    CHECK ( y == Interval(NAN, NAN));
    CHECK ( th == Interval(NAN, NAN));

}


TEST_CASE("test_Catan2_001", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.3333333333313p-2, 0x1.2666666666679p+1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.85e1b9e6d304cp+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(0x1.3333333333313p-2, 0x1.b1ad66a153796p-2));
    CHECK ( th == Interval(0x1.1d4e1d42e573ep-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_002", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.9999999999959p-3, 0x1.19999999999adp+1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.03ebd1448cacfp+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(0x1.9999999999959p-3, 0x1.b1ad66a153796p-2));
    CHECK ( th == Interval(0x1.7cbfb4c43746ep-5, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_003", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.9999999999918p-4, 0x1.0cccccccccce1p+1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(0x1.9999999999918p-4, 0x1.b1ad66a153796p-2));
    CHECK ( th == Interval(0x1.7cf45fe330f7ep-6, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_004", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.9999999999a1cp-4, 0x1.e666666666691p+0),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.9999999999a1cp-4, 0x1.b1ad66a153796p-2));
    CHECK ( th == Interval(-0x1.c6a4cd203b564p-5, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_005", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.99999999999bbp-2, 0x1.99999999999c6p+0),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.99999999999bbp-2, 0x1.b1ad66a153796p-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_006", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.99999999999a7p+0, 0x1.9999999999a5cp-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.b1ad66a153796p-2, 0x1.9999999999a5cp-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_007", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.e666666666675p+0, 0x1.9999999999ca4p-4),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.b1ad66a153796p-2, 0x1.9999999999ca4p-4));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.c6a4cd203b831p-5));

}


TEST_CASE("test_Catan2_008", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.0ccccccccccd5p+1, -0x1.9999999999690p-4),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.b1ad66a153796p-2, -0x1.9999999999690p-4));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.7cf45fe330d23p-6));

}


TEST_CASE("test_Catan2_009", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.19999999999a2p+1, -0x1.9999999999815p-3),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.03ebd1448ca02p+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.b1ad66a153796p-2, -0x1.9999999999815p-3));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.7cbfb4c437340p-5));

}


TEST_CASE("test_Catan2_010", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.266666666666fp+1, -0x1.3333333333271p-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.85e1b9e6d2f7ep+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.b1ad66a153796p-2, -0x1.3333333333271p-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.1d4e1d42e56a8p-4));

}


TEST_CASE("test_Catan2_011", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.333333333333cp+1, -0x1.99999999998d7p-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.03ebd1448ca7dp+2, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.b1ad66a153796p-2, -0x1.99999999998d7p-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.7bee0d1b49326p-4));

}


TEST_CASE("test_Catan2_012", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.4000000000009p+1, -0x1.fffffffffff3dp-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(NAN, NAN));
    CHECK ( y == Interval(NAN, NAN));
    CHECK ( th == Interval(NAN, NAN));

}


TEST_CASE("test_Catan2_013", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.9999999999a1cp-2, -0x1.99999999998b2p-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.03ebd1448ca65p+2, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.9999999999a1cp-2, -0x1.99999999998b2p-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.7bee0d1b49303p-4));

}


TEST_CASE("test_Catan2_014", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.33333333333b6p-2, -0x1.333333333324bp-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.85e1b9e6d2f4ep+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.33333333333b6p-2, -0x1.333333333324bp-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.1d4e1d42e5685p-4));

}


TEST_CASE("test_Catan2_015", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.9999999999a9fp-3, -0x1.99999999997c9p-3),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.03ebd1448c9d1p+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.9999999999a9fp-3, -0x1.99999999997c9p-3));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.7cbfb4c4372fap-5));

}


TEST_CASE("test_Catan2_016", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.9999999999ba4p-4, -0x1.99999999995f8p-4),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.9999999999ba4p-4, -0x1.99999999995f8p-4));
    CHECK ( th == Interval(-0x1.c6a4cd203b715p-5, -0x1.7cf45fe330c96p-6));

}


TEST_CASE("test_Catan2_017", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(-0x1.0500000000000p-47, 0x1.d100000000000p-47),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(-0x1.0500000000000p-47, 0x1.d100000000000p-47));
    CHECK ( th == Interval(-0x1.2200000000004p-48, 0x1.0255555555559p-47));

}


TEST_CASE("test_Catan2_018", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.9999999999790p-4, 0x1.9999999999d3cp-4),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2));
    CHECK ( y == Interval(0x1.9999999999790p-4, 0x1.9999999999d3cp-4));
    CHECK ( th == Interval(0x1.7cf45fe330e12p-6, 0x1.c6a4cd203b8d9p-5));

}


TEST_CASE("test_Catan2_019", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.9999999999895p-3, 0x1.9999999999b6bp-3),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.03ebd1448ca53p+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(0x1.9999999999895p-3, 0x1.9999999999b6bp-3));
    CHECK ( th == Interval(0x1.7cbfb4c4373b7p-5, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_020", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.33333333332b1p-2, 0x1.333333333341cp-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.85e1b9e6d2fcfp+1, 0x1.1333333333336p+2));
    CHECK ( y == Interval(0x1.33333333332b1p-2, 0x1.333333333341cp-2));
    CHECK ( th == Interval(0x1.1d4e1d42e56e3p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_021", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.9999999999917p-2, 0x1.9999999999a83p-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.03ebd1448caa5p+2, 0x1.1333333333336p+2));
    CHECK ( y == Interval(0x1.9999999999917p-2, 0x1.9999999999a83p-2));
    CHECK ( th == Interval(0x1.7bee0d1b49360p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_022", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.cccccccccccc8p+0, 0x1.1333333333336p+2),
                                Interval(0x1.fffffffffff7dp-2, 0x1.0000000000075p-1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(NAN, NAN));
    CHECK ( y == Interval(NAN, NAN));
    CHECK ( th == Interval(NAN, NAN));

}


TEST_CASE("test_Catan2_023", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(0x1.fffffffffff7bp-2, 0x1.800000000003dp+0),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(NAN, NAN));
    CHECK ( y == Interval(NAN, NAN));
    CHECK ( th == Interval(NAN, NAN));

}


TEST_CASE("test_Catan2_024", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(0x1.999999999988dp-3, 0x1.3333333333372p+0),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(0x1.999999999988dp-3, 0x1.60fe41acfc807p-2));
    CHECK ( th == Interval(0x1.d39b13b547971p-5, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_025", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.0d00000000000p-47, 0x1.0000000000040p+0),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(-0x1.0d00000000000p-47, 0x1.60fe41acfc807p-2));
    CHECK ( th == Interval(-0x1.336db6db6db79p-49, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_026", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.9999999999aa7p-3, 0x1.9999999999a1ap-1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(-0x1.9999999999aa7p-3, 0x1.60fe41acfc807p-2));
    CHECK ( th == Interval(-0x1.d39b13b547c0ap-5, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_027", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.9999999999a21p-2, 0x1.33333333333b4p-1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(-0x1.60fe41acfc807p-2, 0x1.60fe41acfc807p-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_028", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.3333333333378p-1, 0x1.9999999999a9cp-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(-0x1.60fe41acfc807p-2, 0x1.60fe41acfc807p-2));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_029", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.99999999999e0p-1, 0x1.9999999999b9fp-3),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(-0x1.60fe41acfc807p-2, 0x1.9999999999b9fp-3));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.d39b13b547d25p-5));

}


TEST_CASE("test_Catan2_030", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.0000000000024p+0, 0x1.0280000000000p-46),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(-0x1.60fe41acfc807p-2, 0x1.0280000000000p-46));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.276db6db6db79p-48));

}


TEST_CASE("test_Catan2_031", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.3333333333358p+0, -0x1.9999999999795p-3),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1));
    CHECK ( y == Interval(-0x1.60fe41acfc807p-2, -0x1.9999999999795p-3));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, -0x1.d39b13b547856p-5));

}


TEST_CASE("test_Catan2_032", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.bfffffffffff0p+1, 0x1.c000000000002p+1),
                                Interval(-0x1.666666666668cp+0, -0x1.9999999999897p-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(NAN, NAN));
    CHECK ( y == Interval(NAN, NAN));
    CHECK ( th == Interval(NAN, NAN));

}


TEST_CASE("test_Catan2_033", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.6100000000000p-47, 0x1.1500000000000p-47),
                                Interval(-0x1.0000000000028p+0, 0x1.0380000000000p-46),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x0.0p+0, 0x1.1500000000000p-47));
    CHECK ( y == Interval(-0x1.b4838eedea87ep-51, 0x1.b4838eedea87ep-51));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_034", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.6100000000000p-47, 0x1.1500000000000p-47),
                                Interval(-0x1.66666666666b7p-1, 0x1.3333333333437p-2),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x0.0p+0, 0x1.1500000000000p-47));
    CHECK ( y == Interval(-0x1.b4838eedea87ep-51, 0x1.b4838eedea87ep-51));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_035", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.6100000000000p-47, 0x1.1500000000000p-47),
                                Interval(-0x1.9999999999a3cp-2, 0x1.33333333333b7p-1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x0.0p+0, 0x1.1500000000000p-47));
    CHECK ( y == Interval(-0x1.b4838eedea87ep-51, 0x1.b4838eedea87ep-51));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_036", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.6100000000000p-47, 0x1.1500000000000p-47),
                                Interval(-0x1.9999999999adfp-3, 0x1.9999999999a1fp-1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x0.0p+0, 0x1.1500000000000p-47));
    CHECK ( y == Interval(-0x1.b4838eedea87ep-51, 0x1.b4838eedea87ep-51));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_037", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.9999999999839p-3, 0x1.9999999999aafp-3),
                                Interval(-0x1.9999999999a3dp-2, 0x1.33333333333bcp-1),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.9999999999839p-3, 0x1.9999999999aafp-3));
    CHECK ( y == Interval(-0x1.42bc93d15bf0cp-6, 0x1.42bc93d15bf0cp-6));
    CHECK ( th == Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));

}


TEST_CASE("test_Catan2_038", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.3333333333317p+1, 0x1.3333333333349p+1),
                                Interval(-0x1.4700000000000p-47, 0x1.1580000000000p-46),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.3333333333317p+1, 0x1.3333333333349p+1));
    CHECK ( y == Interval(-0x1.4700000000000p-47, 0x1.1580000000000p-46));
    CHECK ( th == Interval(-0x1.108000000001ap-48, 0x1.ce8000000002bp-48));

}


TEST_CASE("test_Catan2_039", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.3333333333317p+1, 0x1.3333333333349p+1),
                                Interval(-0x1.9999999999c28p-4, -0x1.9999999999544p-4),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.3333333333317p+1, 0x1.3333333333349p+1));
    CHECK ( y == Interval(-0x1.9999999999c28p-4, -0x1.9999999999544p-4));
    CHECK ( th == Interval(-0x1.5522d16b2f7f5p-5, -0x1.5522d16b2f1e9p-5));

}


TEST_CASE("test_Catan2_040", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.3333333333317p+1, 0x1.3333333333349p+1),
                                Interval(0x1.999999999970cp-4, 0x1.9999999999df0p-4),
                                Interval(-0x1.921fb54442d18p-4, 0x1.921fb54442d18p-4));
    CHECK ( x == Interval(0x1.3333333333317p+1, 0x1.3333333333349p+1));
    CHECK ( y == Interval(0x1.999999999970cp-4, 0x1.9999999999df0p-4));
    CHECK ( th == Interval(0x1.5522d16b2f364p-5, 0x1.5522d16b2f970p-5));

}


TEST_CASE("test_Catan2_041", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.3333333333317p+1, 0x1.3333333333317p+1),
                                Interval(0x1.999999999970cp-4, 0x1.0ccccccccccf1p+1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(0x1.3333333333317p+1, 0x1.3333333333317p+1));
    CHECK ( y == Interval(0x1.999999999970cp-4, 0x1.0ccccccccccf1p+1));
    CHECK ( th == Interval(0x1.5522d16b2f39bp-5, 0x1.700a7c578467bp-1));

}


TEST_CASE("test_Catan2_042", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.3333333333317p+1, 0x1.b333333333317p+1),
                                Interval(0x1.999999999970cp-4, 0x1.19999999999e3p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(0x1.3333333333317p+1, 0x1.b333333333317p+1));
    CHECK ( y == Interval(0x1.999999999970cp-4, 0x1.19999999999e3p+0));
    CHECK ( th == Interval(0x1.e1be544ec993fp-6, 0x1.b8139a5719550p-2));

}


TEST_CASE("test_Catan2_043", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.199999999995cp+0, 0x1.0ccccccccccbbp+1),
                                Interval(0x1.999999999996dp+0, 0x1.4ccccccccccf5p+1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(0x1.199999999995cp+0, 0x1.0ccccccccccbbp+1));
    CHECK ( y == Interval(0x1.999999999996dp+0, 0x1.4ccccccccccf5p+1));
    CHECK ( th == Interval(0x1.4d59ed9394f52p-1, 0x1.2ba9894fc544cp+0));

}


TEST_CASE("test_Catan2_044", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.fffffffffff01p-2, 0x1.7ffffffffffe0p+0),
                                Interval(0x1.999999999996dp+0, 0x1.4ccccccccccf5p+1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(0x1.fffffffffff01p-2, 0x1.7ffffffffffe0p+0));
    CHECK ( y == Interval(0x1.999999999996dp+0, 0x1.4ccccccccccf5p+1));
    CHECK ( th == Interval(0x1.a2a25f172cfd0p-1, 0x1.617ca2b906f25p+0));

}


TEST_CASE("test_Catan2_045", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.0080000000000p-46, 0x1.fffffffffffc5p-1),
                                Interval(0x1.999999999996dp+0, 0x1.4ccccccccccf5p+1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.0080000000000p-46, 0x1.fffffffffffc5p-1));
    CHECK ( y == Interval(0x1.999999999996dp+0, 0x1.4ccccccccccf5p+1));
    CHECK ( th == Interval(0x1.031f57e54adb7p+0, 0x1.921fb54442d4fp+0));

}


TEST_CASE("test_Catan2_046", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.0080000000000p-46, 0x1.fffffffffffc5p-1),
                                Interval(0x1.e666666666638p+0, 0x1.733333333335cp+1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.0080000000000p-46, 0x1.fffffffffffc5p-1));
    CHECK ( y == Interval(0x1.e666666666638p+0, 0x1.733333333335cp+1));
    CHECK ( th == Interval(0x1.1618f66769c62p+0, 0x1.921fb54442d49p+0));

}


TEST_CASE("test_Catan2_047", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.0080000000000p-46, -0x1.d200000000000p-48),
                                Interval(0x1.e666666666638p+0, 0x1.733333333335cp+1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.0080000000000p-46, -0x1.d200000000000p-48));
    CHECK ( y == Interval(0x1.e666666666638p+0, 0x1.733333333335cp+1));
    CHECK ( th == Interval(0x1.921fb54442d17p+0, 0x1.921fb54442d49p+0));

}


TEST_CASE("test_Catan2_048", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.4000000000025p+1, -0x1.800000000003bp+0),
                                Interval(-0x1.0000000000072p-1, 0x1.7fffffffffffep+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.4000000000025p+1, -0x1.800000000003bp+0));
    CHECK ( y == Interval(-0x1.0000000000072p-1, 0x1.7fffffffffffep+0));
    CHECK ( th == Interval(0x1.2d97c7f3321d8p+1, 0x1.bb4ed48a90101p+1));

}


TEST_CASE("test_Catan2_049", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.e66666666668ep+1, -0x1.666666666667cp+1),
                                Interval(-0x1.0000000000072p-1, 0x1.7fffffffffffep+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.e66666666668ep+1, -0x1.666666666667cp+1));
    CHECK ( y == Interval(-0x1.0000000000072p-1, 0x1.7fffffffffffep+0));
    CHECK ( th == Interval(0x1.532c1ae0e390ap+1, 0x1.a8be1a9720d24p+1));

}


TEST_CASE("test_Catan2_050", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.e66666666668ep+1, -0x1.666666666667cp+1),
                                Interval(-0x1.0000000000072p-1, -0x1.0000000000002p-1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.e66666666668ep+1, -0x1.666666666667cp+1));
    CHECK ( y == Interval(-0x1.0000000000072p-1, -0x1.0000000000002p-1));
    CHECK ( th == Interval(0x1.a2dea9020a5bcp+1, 0x1.a8be1a9720d24p+1));

}


TEST_CASE("test_Catan2_051", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.e66666666668ep+1, -0x1.666666666667cp+1),
                                Interval(-0x1.c900000000000p-47, -0x1.4000000000000p-53),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.e66666666668ep+1, -0x1.666666666667cp+1));
    CHECK ( y == Interval(-0x1.c900000000000p-47, -0x1.4000000000000p-53));
    CHECK ( th == Interval(0x1.921fb54442d17p+1, 0x1.921fb54442d23p+1));

}


TEST_CASE("test_Catan2_052", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.0000000000014p+2, -0x1.8000000000014p+1),
                                Interval(-0x1.c900000000000p-47, -0x1.4000000000000p-53),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.0000000000014p+2, -0x1.8000000000014p+1));
    CHECK ( y == Interval(-0x1.c900000000000p-47, -0x1.4000000000000p-53));
    CHECK ( th == Interval(0x1.921fb54442d17p+1, 0x1.921fb54442d22p+1));

}


TEST_CASE("test_Catan2_053", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.0000000000014p+2, -0x1.000000000000ap+2),
                                Interval(-0x1.c900000000000p-47, 0x1.ffffffffffffep-1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.0000000000014p+2, -0x1.000000000000ap+2));
    CHECK ( y == Interval(-0x1.c900000000000p-47, 0x1.ffffffffffffep-1));
    CHECK ( th == Interval(0x1.72c43f4b1650ap+1, 0x1.921fb54442d20p+1));

}


TEST_CASE("test_Catan2_054", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.0000000000014p+2, -0x1.000000000000ap+2),
                                Interval(-0x1.0000000000073p-1, 0x1.ffffffffffffep-2),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.0000000000014p+2, -0x1.000000000000ap+2));
    CHECK ( y == Interval(-0x1.0000000000073p-1, 0x1.ffffffffffffep-2));
    CHECK ( th == Interval(0x1.8234d7f6ecb9cp+1, 0x1.a20a929198e9bp+1));

}


TEST_CASE("test_Catan2_055", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333420p-1, -0x1.3333333333368p-1),
                                Interval(-0x1.0000000000073p-1, 0x1.ffffffffffffep-2),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.3333333333420p-1, -0x1.3333333333368p-1));
    CHECK ( y == Interval(-0x1.0000000000073p-1, 0x1.ffffffffffffep-2));
    CHECK ( th == Interval(0x1.393286347d27dp+1, 0x1.eb0ce454087d0p+1));

}


TEST_CASE("test_Catan2_056", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.b3333333333aep+0, -0x1.b333333333349p+0),
                                Interval(-0x1.0000000000020p+1, -0x1.fffffffffffffp-1),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.b3333333333aep+0, -0x1.b333333333349p+0));
    CHECK ( y == Interval(-0x1.0000000000020p+1, -0x1.fffffffffffffp-1));
    CHECK ( th == Interval(0x1.d62f3e07f2841p+1, 0x1.008159ada8be1p+2));

}


TEST_CASE("test_Catan2_057", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.9999999999a15p+0, -0x1.3333333333428p-1),
                                Interval(-0x1.19999999999bap+1, -0x1.3333333333332p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.9999999999a15p+0, -0x1.7041d7138976cp-1));
    CHECK ( y == Interval(-0x1.19999999999bap+1, -0x1.3333333333332p+0));
    CHECK ( th == Interval(0x1.e47df3d0dd4bap+1, 0x1.0b090e5f5461ap+2));

}


TEST_CASE("test_Catan2_058", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.800000000007cp+0, -0x1.00000000000f4p-1),
                                Interval(-0x1.3333333333354p+1, -0x1.6666666666664p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.800000000007cp+0, -0x1.ada22596cb0a7p-1));
    CHECK ( y == Interval(-0x1.3333333333354p+1, -0x1.6666666666664p+0));
    CHECK ( th == Interval(0x1.f23e26ce918b6p+1, 0x1.0b090e5f5461ap+2));

}


TEST_CASE("test_Catan2_059", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.4cccccccccd4ap+0, -0x1.333333333351ap-2),
                                Interval(-0x1.4cccccccccceep+1, -0x1.9999999999996p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.4cccccccccd4ap+0, -0x1.eb02741a0c9e3p-1));
    CHECK ( y == Interval(-0x1.159f2300067a1p+1, -0x1.9999999999996p+0));
    CHECK ( th == Interval(0x1.01ecb4e504e60p+2, 0x1.0b090e5f5461ap+2));

}


TEST_CASE("test_Catan2_060", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.33333333333b1p+0, -0x1.9999999999d67p-3),
                                Interval(-0x1.6666666666688p+1, -0x1.cccccccccccc8p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.33333333333b1p+0, -0x1.1431614ea718fp+0));
    CHECK ( y == Interval(-0x1.0044204ecae76p+1, -0x1.cccccccccccc8p+0));
    CHECK ( th == Interval(0x1.07f5f24725550p+2, 0x1.0b090e5f5461ap+2));

}


TEST_CASE("test_Catan2_061", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.33333333333b1p+0, -0x1.9999999999d67p-3),
                                Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(-0x1.33333333333b1p+0, -0x1.238974ef777dep+0));
    CHECK ( y == Interval(-0x1.0044204ecae76p+1, -0x1.e666666666661p+0));
    CHECK ( th == Interval(0x1.098a684d17addp+2, 0x1.0b090e5f5461ap+2));

}


TEST_CASE("test_Catan2_062", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.1999999999a18p+0, -0x1.999999999a134p-4),
                                Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.0b090e5f5461ap+2));
    CHECK ( x == Interval(NAN, NAN));
    CHECK ( y == Interval(NAN, NAN));
    CHECK ( th == Interval(NAN, NAN));

}


TEST_CASE("test_Catan2_063", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.1999999999a18p+0, -0x1.999999999a134p-4),
                                Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.2d97c7f332205p+2));
    CHECK ( x == Interval(-0x1.1999999999a18p+0, -0x1.999999999a134p-4));
    CHECK ( y == Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0));
    CHECK ( th == Interval(0x1.0c0186f21dde0p+2, 0x1.2b630a0fd1205p+2));

}


TEST_CASE("test_Catan2_064", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.000000000007fp+0, -0x1.e680000000000p-46),
                                Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.2d97c7f332205p+2));
    CHECK ( x == Interval(-0x1.000000000007fp+0, -0x1.e680000000000p-46));
    CHECK ( y == Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0));
    CHECK ( th == Interval(0x1.0e96183bfbd96p+2, 0x1.2d97c7f3321ccp+2));

}


TEST_CASE("test_Catan2_065", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1),
                                Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0),
                                Interval(-0x1.921fb54442d1bp-1, 0x1.2d97c7f332205p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1));
    CHECK ( y == Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0));
    CHECK ( th == Interval(0x1.2392041229ca7p+2, 0x1.2d97c7f332205p+2));

}


TEST_CASE("test_Catan2_066", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1),
                                Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0),
                                Interval(0x1.c463abeccb2b2p-1, 0x1.9868341953e2ap+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1));
    CHECK ( y == Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0));
    CHECK ( th == Interval(0x1.2392041229ca7p+2, 0x1.442f2cf21352bp+2));

}


TEST_CASE("test_Catan2_067", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1),
                                Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0),
                                Interval(0x1.c463abeccb2b2p-1, 0x1.2d97c7f33225ap+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.8a99950860f20p-42));
    CHECK ( y == Interval(-0x1.7333333333355p+1, -0x1.e666666666661p+0));
    CHECK ( th == Interval(0x1.2392041229ca7p+2, 0x1.2d97c7f33225ap+2));

}


TEST_CASE("test_Catan2_068", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1),
                                Interval(-0x1.7333333333355p+1, -0x1.cccccccccccc0p-1),
                                Interval(0x1.c463abeccb2b2p-1, 0x1.2d97c7f33225ap+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.8a99950860f20p-42));
    CHECK ( y == Interval(-0x1.7333333333355p+1, -0x1.cccccccccccc0p-1));
    CHECK ( th == Interval(0x1.190038500b7c0p+2, 0x1.2d97c7f33225ap+2));

}


TEST_CASE("test_Catan2_069", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1),
                                Interval(-0x1.7333333333355p+1, 0x1.199999999999ep+0),
                                Interval(0x1.c463abeccb2b2p-1, 0x1.2d97c7f33225ap+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.6666666666575p-1));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.199999999999ep+0));
    CHECK ( th == Interval(0x1.c463abeccb2b2p-1, 0x1.2d97c7f33225ap+2));

}


TEST_CASE("test_Catan2_070", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.c463abeccb2b2p-1, 0x1.2d97c7f33225ap+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1));
    CHECK ( th == Interval(0x1.c463abeccb2b2p-1, 0x1.2d97c7f33225ap+2));

}


TEST_CASE("test_Catan2_071", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.2106ca491005dp+1, 0x1.858eb79a20c4ep+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.76530436f436dp-2));
    CHECK ( th == Interval(0x1.2106ca491005dp+1, 0x1.858eb79a20c4ep+2));

}


TEST_CASE("test_Catan2_072", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.a4f931c375f21p+1, 0x1.c787eb5753bc5p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.e02b510c34544p+0));
    CHECK ( th == Interval(0x1.a4f931c375f21p+1, 0x1.c787eb5753bc5p+2));

}


TEST_CASE("test_Catan2_073", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.c13f6c8242b1fp+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.8a7139c897db1p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.c13f6c8242b1fp+2));

}


TEST_CASE("test_Catan2_074", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.baf6edad31a6bp+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.42c42d6635c45p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.baf6edad31a6bp+2));

}


TEST_CASE("test_Catan2_075", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.ae65f0030f903p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.9bab257fb0135p-1));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.ae65f0030f903p+2));

}


TEST_CASE("test_Catan2_076", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.a1d4f258ed79bp+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x1.b40c3616423e4p-2));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.a1d4f258ed79bp+2));

}


TEST_CASE("test_Catan2_077", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.6c6cbc45dc9a1p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.6c6cbc45dc9a1p+2));

}


TEST_CASE("test_Catan2_078", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.502681870fe77p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.502681870fe77p+2));

}


TEST_CASE("test_Catan2_079", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.49de02b1fedc3p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.5f21096561873p+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.49de02b1fedc3p+2));

}


TEST_CASE("test_Catan2_080", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.40714472654b5p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.c268be6f93e40p-1));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.40714472654b5p+2));

}


TEST_CASE("test_Catan2_081", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.37048632cbba7p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b87fa0e1747b0p-2));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.37048632cbba7p+2));

}


TEST_CASE("test_Catan2_082", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fcf0216a648f9p+1, 0x1.30bc075dbaaf3p+2));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.23c631104b50bp-3));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.fcf0216a648f9p+1, 0x1.30bc075dbaaf3p+2));

}


TEST_CASE("test_Catan2_083", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.3bbae55298756p+3, 0x1.54dce0a6dcae9p+3));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x0.0p+0));
    CHECK ( y == Interval(-0x1.ad488289c817ep-1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.3bbae55298756p+3, 0x1.54dce0a6dcae9p+3));

}


TEST_CASE("test_Catan2_084", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.46b9c34776491p+3, 0x1.5fdbbe9bba82bp+3));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.07f3320ee50aep-40));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.46b9c34776491p+3, 0x1.5fdbbe9bba82bp+3));

}


TEST_CASE("test_Catan2_085", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.566f005c20e53p+3, 0x1.6f90fbb0651f7p+3));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.8cd23177f3008p+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.566f005c20e53p+3, 0x1.6f90fbb0651f7p+3));

}


TEST_CASE("test_Catan2_086", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.67b65d260fc42p+3, 0x1.80d8587a53ff1p+3));
    CHECK ( x == Interval(0x0.0p+0, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.67b65d260fc42p+3, 0x1.80d8587a53ff1p+3));

}


TEST_CASE("test_Catan2_087", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.78fdb9effea31p+3, 0x1.921fb54442debp+3));
    CHECK ( x == Interval(0x0.0p+0, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.b333333333520p+0, 0x1.66b33333332d2p-41));
    CHECK ( th == Interval(0x1.78fdb9effea31p+3, 0x1.921fb54442debp+3));

}


TEST_CASE("test_Catan2_088", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.8a4516b9ed820p+3, 0x1.a367120e31be5p+3));
    CHECK ( x == Interval(0x0.0p+0, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(-0x1.b40c36164134ap-2, 0x1.04d94dadd7c89p+0));
    CHECK ( th == Interval(0x1.8a4516b9ed820p+3, 0x1.a367120e31be5p+3));

}


TEST_CASE("test_Catan2_089", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.a042d2a3a9296p+3, 0x1.b964cdf7ed669p+3));
    CHECK ( x == Interval(0x0.0p+0, 0x1.b3333333332bcp+0));
    CHECK ( y == Interval(0x0.0p+0, 0x1.0cccccccccccfp+1));
    CHECK ( th == Interval(0x1.a042d2a3a9296p+3, 0x1.b964cdf7ed669p+3));

}


TEST_CASE("test_Catan2_090", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.b4ae6ed8208dfp+3, 0x1.cdd06a2c64cbfp+3));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.1f5a6a7156cf6p+0));
    CHECK ( y == Interval(0x0.0p+0, 0x1.0cccccccccccfp+1));
    CHECK ( th == Interval(0x1.b4ae6ed8208dfp+3, 0x1.cdd06a2c64cbfp+3));

}


TEST_CASE("test_Catan2_091", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.c463abeccb2a1p+3, 0x1.dd85a7410f68bp+3));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x1.b5610d40e0466p-44));
    CHECK ( y == Interval(0x0.0p+0, 0x1.0cccccccccccfp+1));
    CHECK ( th == Interval(0x1.c463abeccb2a1p+3, 0x1.dd85a7410f68bp+3));

}


TEST_CASE("test_Catan2_092", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.d73d286bfe4bdp+3, 0x1.f05f23c0428b3p+3));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x0.0p+0));
    CHECK ( y == Interval(0x0.0p+0, 0x1.cbc1ddc6c9214p-2));
    CHECK ( th == Interval(0x1.d73d286bfe4bdp+3, 0x1.f05f23c0428b3p+3));

}


TEST_CASE("test_Catan2_093", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.fb5e01b5204c8p+3, 0x1.0a3ffe84b246bp+4));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x0.0p+0));
    CHECK ( y == Interval(-0x1.9e36147ea1a60p-2, 0x0.0p+0));
    CHECK ( th == Interval(0x1.fb5e01b5204c8p+3, 0x1.0a3ffe84b246bp+4));

}


TEST_CASE("test_Catan2_094", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(-0x1.3333333333532p-2, 0x1.b3333333332bcp+0),
                                Interval(-0x1.7333333333355p+1, 0x1.0cccccccccccfp+1),
                                Interval(0x1.0652af3f87957p+4, 0x1.12e3ace9a9b68p+4));
    CHECK ( x == Interval(-0x1.3333333333532p-2, 0x0.0p+0));
    CHECK ( y == Interval(-0x1.7333333333355p+1, 0x0.0p+0));
    CHECK ( th == Interval(0x1.0652af3f87957p+4, 0x1.12e3ace9a9b68p+4));

}


TEST_CASE("test_Catan2_095", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.0652af3f87957p+4, 0x1.12e3ace9a9b68p+4));
    CHECK ( x == Interval(NAN, NAN));
    CHECK ( y == Interval(NAN, NAN));
    CHECK ( th == Interval(NAN, NAN));

}


TEST_CASE("test_Catan2_096", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.0652af3f87957p+4, 0x1.18631be418a09p+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.4d72bff2e9a20p-1));
    CHECK ( y == Interval(-0x1.4ccccccccccf1p+1, -0x1.98cdc04bd35f2p-1));
    CHECK ( th == Interval(0x1.15b041c892076p+4, 0x1.18631be418a09p+4));

}


TEST_CASE("test_Catan2_097", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.0652af3f87957p+4, 0x1.28e168d3655ecp+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.12460d7774138p+3));
    CHECK ( y == Interval(-0x1.4ccccccccccf1p+1, -0x1.f100d222d212cp-5));
    CHECK ( th == Interval(0x1.15b041c892076p+4, 0x1.28e168d3655ecp+4));

}


TEST_CASE("test_Catan2_098", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.16d0fc2ed4525p+4, 0x1.445e93b78ff11p+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4));
    CHECK ( y == Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3));
    CHECK ( th == Interval(0x1.16d0fc2ed4525p+4, 0x1.445e93b78ff11p+4));

}


TEST_CASE("test_Catan2_099", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.16d0fc2ed4525p+4, 0x1.2ff2f783188d5p+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4));
    CHECK ( y == Interval(-0x1.4ccccccccccf1p+1, 0x1.f175a63c6e423p+1));
    CHECK ( th == Interval(0x1.16d0fc2ed4525p+4, 0x1.2ff2f783188d5p+4));

}


TEST_CASE("test_Catan2_100", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.2d97c7f3321a3p+4, 0x1.46b9c34776570p+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4));
    CHECK ( y == Interval(-0x1.33d99999999a3p-38, 0x1.cccccccccccdbp+3));
    CHECK ( th == Interval(0x1.2d97c7f3321a3p+4, 0x1.4680e0a8f100bp+4));

}


TEST_CASE("test_Catan2_101", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.30bc075dba9fbp+4, 0x1.49de02b1fedccp+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4));
    CHECK ( y == Interval(0x1.45e5e4d10dc92p-5, 0x1.cccccccccccdbp+3));
    CHECK ( th == Interval(0x1.30bc075dba9fbp+4, 0x1.4680e0a8f100bp+4));

}


TEST_CASE("test_Catan2_102", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.331736eda103dp+4, 0x1.4c393241e5411p+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4));
    CHECK ( y == Interval(0x1.251d4c645f6a4p-4, 0x1.cccccccccccdbp+3));
    CHECK ( th == Interval(0x1.331736eda103dp+4, 0x1.4680e0a8f100bp+4));

}


TEST_CASE("test_Catan2_103", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.999999999959dp-3, 0x1.a33333333333ep+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.363b765829895p+4, 0x1.4f5d71ac6dc6dp+4));
    CHECK ( x == Interval(0x1.999999999959dp-3, 0x1.8066307630e3fp+4));
    CHECK ( y == Interval(0x1.eb02741a0b978p-4, 0x1.cccccccccccdbp+3));
    CHECK ( th == Interval(0x1.363b765829895p+4, 0x1.4680e0a8f100bp+4));

}


TEST_CASE("test_Catan2_104", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.8cccccccccc81p+1, 0x1.e1999999999b1p+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.cccccccccccdbp+3),
                                Interval(0x1.3896a5e80fed7p+4, 0x1.51b8a13c542b2p+4));
    CHECK ( x == Interval(0x1.8cccccccccc81p+1, 0x1.18be43293782fp+4));
    CHECK ( y == Interval(0x1.45a535470c943p+1, 0x1.cccccccccccdbp+3));
    CHECK ( th == Interval(0x1.3896a5e80fed7p+4, 0x1.43553d7e8a4cbp+4));

}


TEST_CASE("test_Catan2_105", "") {
    Interval x, y,th;
    std::tie(x, y, th) = Catan2(Interval(0x1.8cccccccccc81p+1, 0x1.e1999999999b1p+4),
                                Interval(-0x1.4ccccccccccf1p+1, 0x1.1d999999999b9p+6),
                                Interval(0x1.3896a5e80fed7p+4, 0x1.51b8a13c542b2p+4));
    CHECK ( x == Interval(0x1.8cccccccccc81p+1, 0x1.e1999999999b1p+4));
    CHECK ( y == Interval(0x1.45a535470c943p+1, 0x1.1d999999999b9p+6));
    CHECK ( th == Interval(0x1.3896a5e80fed7p+4, 0x1.46080971d558ep+4));

}
