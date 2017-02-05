[![Build Status](https://travis-ci.org/benEnsta/ibex-geometry.svg?branch=master)](https://travis-ci.org/benEnsta/ibex-geometry)
# ibex-geometry
An Ibex module with geometrical features

# Polar constraints

This packages gathers developpement around then polar constraint which links Cartesian and Polar coordinates.
It contains :
 + bwd_angle : the elementary backward operation for atan2 ( without modulo 2*pi )
 + CtcAngle : A Forward/Backward contractor for the relation th = atan2(y, x)
 + Catan2 : other implementation of CtcAngle with tests [NEW]
 + CtcPolar : A Minimal contractor for the constraint x = rho*cos(theta), y   = rho*sin(theta)
 + SepPolarXY : separator for the projection of the polar constraint on the XY plan


# Build

## Build without pyibex interface
```bash
mkdir -p build && cd build
cmake -DWITH_PYTHON=OFF  ..
make
```


# Geometry constraints:

## CtcSegement

## SepPolygon


# Examples :
## python
bwd_angle, CtcAngle


# Refernces
