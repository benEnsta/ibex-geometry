//============================================================================
//                                  I B E X
// File        : TestSepPolygon.cpp
// Author      : Benoit Desrochers, Guilherme Schvarcz Franco
// Copyright   : ENSTA Bretagne (France)
// License     : See the LICENSE file
// Created     : 2016
//============================================================================


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "catch_interval.hpp"
#include "vibes/vibes.h"

#include "ibex_SepPolygon.h"

#define BUFFER_SIZE 512

using namespace ibex;
using namespace Catch;
using namespace Detail;

std::vector<double> murs_xa, murs_xb, murs_ya, murs_yb, murs_xa2, murs_xb2, murs_ya2, murs_yb2;

void setup(){

    murs_xa.clear(); murs_xa2.clear();
    murs_xb.clear(); murs_xb2.clear();
    murs_ya.clear(); murs_ya2.clear();
    murs_yb.clear(); murs_yb2.clear();

    // Polygone convex
    murs_xa.push_back(6);  murs_ya.push_back(-6);   murs_xb.push_back(7);  murs_yb.push_back(9);
    murs_xa.push_back(7);  murs_ya.push_back(9);   murs_xb.push_back(0);  murs_yb.push_back(5);
    murs_xa.push_back(0);  murs_ya.push_back(5);    murs_xb.push_back(-9); murs_yb.push_back(8);
    murs_xa.push_back(-9); murs_ya.push_back(8);    murs_xb.push_back(-8); murs_yb.push_back(-9);
    murs_xa.push_back(-8); murs_ya.push_back(-9);   murs_xb.push_back(6);  murs_yb.push_back(-6);

    // Objet au milieu
    murs_xa2.push_back(-2); murs_ya2.push_back(3);   murs_xb2.push_back(3.5);  murs_yb2.push_back(2);
    murs_xa2.push_back(3.5); murs_ya2.push_back(2);   murs_xb2.push_back(3);  murs_yb2.push_back(-4);
    murs_xa2.push_back(3); murs_ya2.push_back(-4);   murs_xb2.push_back(-3);  murs_yb2.push_back(-3);
    murs_xa2.push_back(-3); murs_ya2.push_back(-3);   murs_xb2.push_back(-2);  murs_yb2.push_back(3);
}

class ToVibes : public SetVisitor {

public:

  /**
   * Function that will be called automatically on every boxes (leaves) of the set.
   */
  void visit_leaf(const IntervalVector& box, BoolInterval status) {

    //  Associate a color to the box.
    //  - YES (means "inside") is in red
    //  - NO (means "outside") is in cyan
    //  - MAYBE (means "boundary") is in yellow.
    const char* color;

    switch (status) {
    case YES:  color="k[r]"; break;
    case NO:   color="k[c]"; break;
    case MAYBE : color="k[y]"; break;
    }

    // Plot the box with Vibes
    vibes::drawBox(box[0].lb(), box[0].ub(), box[1].lb(), box[1].ub(), color);
  }

};

bool isFilesEqual(const std::string& lFilePath, const std::string& rFilePath)
{
    std::ifstream lFile(lFilePath.c_str(), std::ifstream::in | std::ifstream::binary);
    std::ifstream rFile(rFilePath.c_str(), std::ifstream::in | std::ifstream::binary);

    if(!lFile.is_open() || !rFile.is_open())
    {
        return false;
    }

    char *lBuffer = new char[BUFFER_SIZE]();
    char *rBuffer = new char[BUFFER_SIZE]();

    do {
        lFile.read(lBuffer, BUFFER_SIZE);
        rFile.read(rBuffer, BUFFER_SIZE);

        if (std::memcmp(lBuffer, rBuffer, BUFFER_SIZE) != 0)
        {
            delete[] lBuffer;
            delete[] rBuffer;
            return false;
        }
    } while (lFile.good() || rFile.good());

    delete[] lBuffer;
    delete[] rBuffer;
    return true;
}

std::vector< std::vector< std::vector<double> > > array2Vector(double doubleArray[][4], int rows)
{
    std::vector< std::vector< std::vector<double> > > ret(rows);
    for(size_t i =0; i < rows; ++i)
    {
        ret[i].resize(2);
        ret[i][0].insert(ret[i][0].end(), doubleArray[i]  , doubleArray[i]+2);
        ret[i][1].insert(ret[i][1].end(), doubleArray[i]+2, doubleArray[i]+4);
    }

    return ret;
}

std::vector< std::vector< std::vector<double> > > rarray2Vector(double doubleArray[][4], int rows)
{
    std::vector< std::vector< std::vector<double> > > ret(rows);
    for(size_t i =0; i < rows; ++i)
    {
        ret[i].resize(2);
        ret[i][0].insert(ret[i][0].end(), doubleArray[i]+2  , doubleArray[i]+4);
        ret[i][1].insert(ret[i][1].end(), doubleArray[i], doubleArray[i]+2);
    }

    return ret;
}

TEST_CASE("test_SepPolygon_01", "")
{
    setup();

    SepPolygon S1(murs_xa, murs_ya, murs_xb, murs_yb);

    IntervalVector box(2);
    box[0]=Interval(-10,10);
    box[1]=Interval(-10,10);
}

TEST_CASE("test_SepPolygon_02", "")
{
    setup();
    murs_xa.insert(murs_xa.end(), murs_xa2.begin(), murs_xa2.end());
    murs_ya.insert(murs_ya.end(), murs_ya2.begin(), murs_ya2.end());
    murs_xb.insert(murs_xb.end(), murs_xb2.begin(), murs_xb2.end());
    murs_yb.insert(murs_yb.end(), murs_yb2.begin(), murs_yb2.end());

    SepPolygon S1(murs_xa, murs_ya, murs_xb, murs_yb);
}

TEST_CASE("test_SepPolygon_03", "")
{
    setup();
    SepPolygon S1(murs_xa, murs_ya, murs_xb, murs_yb);
    SepPolygon S2(murs_xa2, murs_ya2, murs_xb2, murs_yb2);
    SepNot S3(S2);
    SepInter S(S1, S3);
}

//Test the inner contractor
TEST_CASE("test_SepPolygon_04", "")
{
    double ls[8][4] = {
        { 2.5,  0. ,  2.5,  5.},
        { 2.5,  5. ,  3. ,  5.},
        { 3. ,  5. ,  3. ,  0.},
        { 3. ,  0. ,  7. ,  6.},
        { 7. ,  6. ,  1. , 12.},
        { 1. ,  12., -7. ,  8.},
        {-7. ,  8. , -3. , -3.},
        {-3. , -3. ,  2.5,  0.}
    };
    std::vector< std::vector< std::vector<double> > > lines = array2Vector(ls,8);


    SepPolygon sep(lines);

    IntervalVector box_in(2,Interval(-30,-15));
    IntervalVector box_out = box_in;

    sep.separate(box_in, box_out);

    IntervalVector resbox(2,Interval(-30,-15));

    CHECK(box_in == resbox);
    CHECK(box_out == IntervalVector(2,Interval::EMPTY_SET));

    vibes::beginDrawing();
    vibes::newFigure("test_SepPolygon_04");
    vibes::setFigureProperties(vibesParams("x",106,"y",60,"width",800,"height",450));

    vibes::drawBox(box_out,"k[r]");
    vibes::drawBox(box_in,"k[c]");

    for(int i =0; i< lines.size(); i++)
        vibes::drawLine(lines[i],"k");
}

//Test the outter contractor
TEST_CASE("test_SepPolygon_05", "")
{
    double ls[8][4] = {
        { 2.5,  0. ,  2.5,  5.},
        { 2.5,  5. ,  3. ,  5.},
        { 3. ,  5. ,  3. ,  0.},
        { 3. ,  0. ,  7. ,  6.},
        { 7. ,  6. ,  1. , 12.},
        { 1. ,  12., -7. ,  8.},
        {-7. ,  8. , -3. , -3.},
        {-3. , -3. ,  2.5,  0.}
    };
    std::vector< std::vector< std::vector<double> > > lines = array2Vector(ls,8);

    SepPolygon sep(lines);

    IntervalVector box_in(2,Interval(-30,-15)); box_in[0] = Interval(-5,2); box_in[1] = Interval(3,7);
    IntervalVector box_out = box_in;

    sep.separate(box_in, box_out);

    double _resbox[][2] = {{-5,2},  {3,7}};
    IntervalVector resbox(2,_resbox);

    CHECK(box_in == IntervalVector(2,Interval::EMPTY_SET));
    CHECK(box_out == resbox);

    vibes::beginDrawing();
    vibes::newFigure("test_SepPolygon_05");
    vibes::setFigureProperties(vibesParams("x",1013,"y",60,"width",800,"height",450));

    vibes::drawBox(box_out,"k[r]");
    vibes::drawBox(box_in,"k[c]");

    for(int i =0; i< lines.size(); i++)
        vibes::drawLine(lines[i],"k");
}

//Test the paving
TEST_CASE("test_SepPolygon_06", "")
{
    double ls[8][4] = {
        { 2.5,  0. ,  2.5,  5.},
        { 2.5,  5. ,  3. ,  5.},
        { 3. ,  5. ,  3. ,  0.},
        { 3. ,  0. ,  7. ,  6.},
        { 7. ,  6. ,  1. , 12.},
        { 1. ,  12., -7. ,  8.},
        {-7. ,  8. , -3. , -3.},
        {-3. , -3. ,  2.5,  0.}
    };
    std::vector< std::vector< std::vector<double> > > lines = array2Vector(ls,8);

    SepPolygon sep(lines);

    IntervalVector box(2,Interval(-15,15));

    Set set(box);

    sep.contract(set,0.2);

    vibes::beginDrawing();
    vibes::newFigure("test_SepPolygon_06");
    vibes::setFigureProperties(vibesParams("x",106,"y",570,"width",800,"height",450));
    ToVibes drawVibes;
    set.visit(drawVibes);
    for(int i =0; i< lines.size(); i++)
        vibes::drawLine(lines[i],"k");


    char *tmpname = tmpnam(NULL);
    set.save(tmpname);

    CHECK(isFilesEqual(tmpname,"./setResult_06"));
}

//Test the paving
TEST_CASE("test_SepPolygon_07", "")
{
    double ls[8][4] = {
        { 2.5,  0. ,  2.5,  5.},
        { 2.5,  5. ,  3. ,  5.},
        { 3. ,  5. ,  3. ,  0.},
        { 3. ,  0. ,  7. ,  6.},
        { 7. ,  6. ,  1. , 12.},
        { 1. ,  12., -7. ,  8.},
        {-7. ,  8. , -3. , -3.},
        {-3. , -3. ,  2.5,  0.}
    };
    std::vector< std::vector< std::vector<double> > > lines = array2Vector(ls,8);


    double _innerPolygon[4][4] = {
        {-1.5, 3.5,  1  , 5},
        { 1  , 5  , -1  , 6.8},
        {-1  , 6.8, -4.3, 4.8},
        {-4.3, 4.8, -1.5, 3.5},
    };
    std::vector< std::vector< std::vector<double> > > innerPolygon = rarray2Vector(_innerPolygon,4);

    lines.insert(lines.end(),innerPolygon.begin(), innerPolygon.end());


    SepPolygon sep(lines);

    IntervalVector box(2,Interval(-15,15));

    Set set(box);

    sep.contract(set,0.2);

    vibes::beginDrawing();
    vibes::newFigure("test_SepPolygon_07");
    vibes::setFigureProperties(vibesParams("x",1013,"y",570,"width",800,"height",450));
    ToVibes drawVibes;
    set.visit(drawVibes);

    for(int i =0; i< lines.size(); i++)
        vibes::drawLine(lines[i],"k");

    for(int i =0; i< innerPolygon.size(); i++)
        vibes::drawLine(innerPolygon[i],"k");


    char *tmpname = tmpnam(NULL);
    set.save(tmpname);

    CHECK(isFilesEqual(tmpname,"./setResult_07"));
}
