//============================================================================
//                               P Y I B E X
// File        : pyIbex_Separator.cpp
// Author      : Benoit Desrochers
// Copyright   : Benoit Desrochers
// License     : See the LICENSE file
// Created     : Mar 02, 2015
//============================================================================

#include "ibex_Interval.h"
#include "ibex_CtcAngle.h"
#include "ibex_CtcPolar.h"
#include "ibex_Sep.h"
#include "ibex_SepPolarXY.h"
#include "ibex_SepPolygon.h"
#include "ibex_CtcSegment.h"


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

using ibex::Interval;
using ibex::IntervalVector;

void SepPolygonFromList(ibex::SepPolygon &instance,  std::vector< std::vector<double> >& lst){
  if (lst.size() != 2){
    throw std::invalid_argument("Invalide input argmment: expected [[ x1, x2, ..., xn], [ y1, y2, ..., yn]]");
  }
  std::vector<double> &lx = lst[0];
  std::vector<double> &ly = lst[1];
  int n = lx.size();
  std::vector<double> ax(n), ay(n),bx(n),by(n);
  for(size_t i = 0; i < n; i++){
      ax[i] = lx[i];
      ay[i] = ly[i];
      bx[i] = lx[ (i+1)%n ];
      by[i] = ly[ (i+1)%n ];
  }
  new(&instance) ibex::SepPolygon(ax, ay, bx, by);
}

PYBIND11_PLUGIN(geometry)
{
  py::module m("geometry", "Python binding of ibex-geometry functions");

  py::object ctc = (py::object) py::module::import("pyibex").attr("Ctc");
  py::object sep = (py::object) py::module::import("pyibex").attr("Sep");

    // Export CtcAngle
    py::class_<ibex::CtcAngle>(m, "CtcAngle", ctc)
        .def(py::init<>())
        .def("contract", ( void (ibex::CtcAngle::*) (IntervalVector&) ) &ibex::CtcAngle::contract)
        .def("contract", ( void (ibex::CtcAngle::*) (Interval&, Interval&, Interval&)) &ibex::CtcAngle::contract)
    ;

    // Export CtcPolar
    py::class_<ibex::CtcPolar>(m, "CtcPolar", ctc)
        .def(py::init<>())
        .def("contract", ( void (ibex::CtcPolar::*) (IntervalVector&) ) &ibex::CtcPolar::contract)
        .def("contract", ( void (ibex::CtcPolar::*) (Interval&, Interval&, Interval&, Interval&) ) &ibex::CtcPolar::contract)
    ;

    // Export SepPolarXY
    py::class_<ibex::SepPolarXY>(m, "SepPolarXY", sep)
        .def(py::init<Interval, Interval>())
        .def("separate", &ibex::SepPolarXY::separate)
    ;


    // Export CtcSegment
    py::class_<ibex::CtcSegment>(m, "CtcSegment", ctc)
        .def(py::init<double, double,double,double>())
        .def("contract", &ibex::CtcSegment::contract)
    ;

    // Export SepPolygon
    py::class_<ibex::SepPolygon>(m, "SepPolygon", sep)
      .def("__init__", &SepPolygonFromList)
      .def("separate", (void (ibex::Sep::*) (IntervalVector&, IntervalVector&)) &ibex::SepPolygon::separate);


    m.def("bwd_angle", &ibex::bwd_angle);
    return m.ptr();

}
