	#!/usr/bin/env python
#============================================================================
#                                P Y I B E X
# File        : test_Interval.py
# Author      : Benoit Desrochers
# Copyright   : Benoit Desrochers
# License     : See the LICENSE file
# Created     : Dec 28, 2014
#============================================================================
import unittest
import pyibex
from pyibex import Interval
from pyibex_geometry import bwd_angle
from Catan2 import Catan2

# def Catan2(x,y,th):
# 	bwd_angle(th, y, x)
# 	return x, y, th

def itvFromHex(lb, ub):
	return Interval(float.fromhex(lb), float.fromhex(ub))

def print2(itv):
  return "[%s; %s]"%(itv.lb().hex(),  itv.ub().hex())

Interval.__str__ = print2
Interval.__repr__ = print2



class TestCatan2(unittest.TestCase):

	def assertSubset(self, x, x_ref):
		return x.is_subset(x_ref)
	def test_000(self):
		x = itvFromHex('0x1.4ccccccccccccp+1', '0x1.cccccccccccd0p+1')
		y = itvFromHex('0x1.cccccccccccccp-1', '0x1.e666666666668p+0')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.4ccccccccccccp+1', '0x1.cccccccccccd0p+1')
		y_ref = itvFromHex('0x1.cccccccccccccp-1', '0x1.e666666666668p+0')
		th_ref = itvFromHex('0x1.f5b75f92c80c9p-3', '0x1.431cd664bcf7dp-1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_001(self):
		x = itvFromHex('0x1.8ccccccccccccp+1', '0x1.0666666666668p+2')
		y = itvFromHex('0x1.cccccccccccccp-1', '0x1.e666666666668p+0')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.8ccccccccccccp+1', '0x1.0666666666668p+2')
		y_ref = itvFromHex('0x1.cccccccccccccp-1', '0x1.e666666666668p+0')
		th_ref = itvFromHex('0x1.ba8ac2095fc49p-3', '0x1.19865b3a65187p-1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_002(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('0x1.cccccccccccccp-1', '0x1.e666666666668p+0')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y_ref = itvFromHex('0x1.cccccccccccccp-1', '0x1.e666666666668p+0')
		th_ref = itvFromHex('0x1.8bb27662b4230p-3', '0x1.f146eb03b5f57p-2')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_003(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('0x1.9999999999971p-3', '0x1.3333333333340p+0')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y_ref = itvFromHex('0x1.9999999999971p-3', '0x1.3333333333340p+0')
		th_ref = itvFromHex('0x1.63f321d608865p-5', '0x1.4978fa3269efdp-2')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_004(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('-0x1.99999999999ecp-4', '0x1.ccccccccccce9p-1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y_ref = itvFromHex('-0x1.de6666666666bp-49', '0x1.ccccccccccce9p-1')
		th_ref = itvFromHex('-0x1.a000000000000p-51', '0x1.f5b75f92c8112p-3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_005(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('-0x1.99999999999afp-2', '0x1.3333333333350p-1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y_ref = itvFromHex('-0x1.de6666666666bp-49', '0x1.3333333333350p-1')
		th_ref = itvFromHex('-0x1.a000000000000p-51', '0x1.52397843c9b0bp-3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_006(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('-0x1.6666666666673p-1', '0x1.333333333336ep-2')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y_ref = itvFromHex('-0x1.de6666666666bp-49', '0x1.333333333336ep-2')
		th_ref = itvFromHex('-0x1.a000000000000p-51', '0x1.548be67e8f68ep-4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_007(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('-0x1.99999999999a7p-1', '0x1.9999999999a0fp-3')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y_ref = itvFromHex('-0x1.de6666666666bp-49', '0x1.9999999999a0fp-3')
		th_ref = itvFromHex('-0x1.a000000000000p-51', '0x1.c6a4cd203b551p-5')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_008(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('-0x1.0000000000008p+0', '0x1.d400000000000p-49')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y_ref = itvFromHex('-0x1.de6666666666bp-49', '0x1.d400000000000p-49')
		th_ref = itvFromHex('-0x1.a000000000000p-51', '0x1.0400000000001p-50')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_009(self):
		x = itvFromHex('0x1.cccccccccccccp+1', '0x1.2666666666668p+2')
		y = itvFromHex('-0x1.19999999999a2p+0', '-0x1.99999999998b0p-4')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('nan', 'nan')
		y_ref = itvFromHex('nan', 'nan')
		th_ref = itvFromHex('nan', 'nan')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_010(self):
		x = itvFromHex('-0x1.333333333336cp-2', '0x1.66666666666d3p-1')
		y = itvFromHex('-0x1.333333333335ap-2', '0x1.6666666666686p-1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.33dcfe54a381ep-34', '0x1.66666666666d3p-1')
		y_ref = itvFromHex('-0x1.233333333338dp-51', '0x1.6666666666686p-1')
		th_ref = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_011(self):
		x = itvFromHex('-0x1.99999999999d3p-2', '0x1.33333333333a0p-1')
		y = itvFromHex('0x1.fffffffffffebp-1', '0x1.000000000000bp+1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.b7cdfd9d7bdcep-33', '0x1.33333333333a0p-1')
		y_ref = itvFromHex('0x1.fffffffffffebp-1', '0x1.000000000000bp+1')
		th_ref = itvFromHex('0x1.07c6c6947a673p+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_012(self):
		x = itvFromHex('-0x1.99999999999d3p-2', '0x1.33333333333a0p-1')
		y = itvFromHex('0x1.4ccccccccccc0p+1', '0x1.cccccccccccdbp+1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.8bd2fdda89135p-32', '0x1.33333333333a0p-1')
		y_ref = itvFromHex('0x1.4ccccccccccc0p+1', '0x1.cccccccccccdbp+1')
		th_ref = itvFromHex('0x1.58103801195c5p+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_013(self):
		x = itvFromHex('-0x1.99999999999d3p-2', '0x1.33333333333a0p-1')
		y = itvFromHex('0x1.1333333333326p+2', '0x1.5333333333343p+2')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.235ede6b8875ap-31', '0x1.33333333333a0p-1')
		y_ref = itvFromHex('0x1.1333333333326p+2', '0x1.5333333333343p+2')
		th_ref = itvFromHex('0x1.6ea1d07357ff5p+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_014(self):
		x = itvFromHex('-0x1.99999999999d3p-2', '0x1.33333333333a0p-1')
		y = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.49da7e361ce76p-30', '0x1.33333333333a0p-1')
		y_ref = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th_ref = itvFromHex('0x1.842c8e55cbaeep+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_015(self):
		x = itvFromHex('-0x1.000000000001dp-1', '0x1.000000000006dp-1')
		y = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.49da7e361ce76p-30', '0x1.000000000006dp-1')
		y_ref = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th_ref = itvFromHex('0x1.867ed918ab126p+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_016(self):
		x = itvFromHex('-0x1.3333333333351p-1', '0x1.9999999999a74p-2')
		y = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.49da7e361ce76p-30', '0x1.9999999999a74p-2')
		y_ref = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th_ref = itvFromHex('0x1.88d1a160b267dp+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_017(self):
		x = itvFromHex('-0x1.6666666666685p-1', '0x1.333333333340ep-2')
		y = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.49da7e361ce76p-30', '0x1.333333333340ep-2')
		y_ref = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th_ref = itvFromHex('0x1.8b24ce3973508p+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_018(self):
		x = itvFromHex('-0x1.99999999999b9p-1', '0x1.9999999999b4fp-3')
		y = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.49da7e361ce76p-30', '0x1.9999999999b4fp-3')
		y_ref = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th_ref = itvFromHex('0x1.8d7846951341dp+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_019(self):
		x = itvFromHex('-0x1.cccccccccccedp-1', '0x1.9999999999d04p-4')
		y = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.49da7e361ce76p-30', '0x1.9999999999d04p-4')
		y_ref = itvFromHex('0x1.5ffffffffffecp+3', '0x1.8000000000030p+3')
		th_ref = itvFromHex('0x1.8fcbf15298703p+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_020(self):
		x = itvFromHex('-0x1.0000000000011p+0', '0x1.b500000000000p-47')
		y = itvFromHex('0x1.ffffffffffe3ep+0', '0x1.8000000000108p+1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.921fb54442d3dp+0')
		x_ref = itvFromHex('-0x1.49da7e361cf2fp-32', '-0x1.2a34c4c66279ep-46')
		y_ref = itvFromHex('0x1.ffffffffffe3ep+0', '0x1.8000000000108p+1')
		th_ref = itvFromHex('0x1.921fb54442d17p+0', '0x1.921fb54442d3dp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_021(self):
		x = itvFromHex('-0x1.0000000000011p+0', '0x1.b500000000000p-47')
		y = itvFromHex('0x1.ffffffffffe3ep+0', '0x1.8000000000108p+1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.9eb0b2ee64ea7p+0')
		x_ref = itvFromHex('-0x1.2dd5da7ac518ap-3', '-0x1.b7cdfd9d7bc38p-33')
		y_ref = itvFromHex('0x1.ffffffffffe3ep+0', '0x1.8000000000108p+1')
		th_ref = itvFromHex('0x1.921fb54442d17p+0', '0x1.9eb0b2ee64ea7p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_022(self):
		x = itvFromHex('-0x1.0000000000011p+0', '0x1.b500000000000p-47')
		y = itvFromHex('0x1.ffffffffffe3ep+0', '0x1.8000000000108p+1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.858eb79a20bd7p+0')
		x_ref = itvFromHex('nan', 'nan')
		y_ref = itvFromHex('nan', 'nan')
		th_ref = itvFromHex('nan', 'nan')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_023(self):
		x = itvFromHex('-0x1.cccccccccccefp-1', '0x1.9999999999d04p-4')
		y = itvFromHex('0x1.ffffffffffe3ep+0', '0x1.8000000000108p+1')
		th = itvFromHex('-0x1.a000000000000p-51', '0x1.858eb79a20bd7p+0')
		x_ref = itvFromHex('0x1.927278a3b0af2p-4', '0x1.9999999999d04p-4')
		y_ref = itvFromHex('0x1.ffffffffffe3ep+0', '0x1.048ccbdb34e83p+1')
		th_ref = itvFromHex('0x1.8555a278797ecp+0', '0x1.858eb79a20bd7p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_024(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.333333333333bp+1', '-0x1.666666666664dp+0')
		th = itvFromHex('-0x1.3a28c59d54345p+1', '-0x1.c463abeccb298p-1')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.f8399cd11ca6cp+0')
		y_ref = itvFromHex('-0x1.333333333333bp+1', '-0x1.666666666664dp+0')
		th_ref = itvFromHex('-0x1.2d0ead60663a4p+0', '-0x1.c463abeccb298p-1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_025(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.333333333333bp+1', '-0x1.666666666664dp+0')
		th = itvFromHex('-0x1.40714472653fap+1', '-0x1.dd85a7410f569p-1')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.c7ab8b631e162p+0')
		y_ref = itvFromHex('-0x1.333333333333bp+1', '-0x1.666666666664dp+0')
		th_ref = itvFromHex('-0x1.2d0ead60663a4p+0', '-0x1.dd85a7410f569p-1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_026(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.333333333333bp+1', '-0x1.666666666664dp+0')
		th = itvFromHex('-0x1.46b9c347764afp+1', '-0x1.f6a7a2955383ap-1')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.9a87699a99242p+0')
		y_ref = itvFromHex('-0x1.333333333333bp+1', '-0x1.7f218e25a7410p+0')
		th_ref = itvFromHex('-0x1.2d0ead60663a4p+0', '-0x1.f6a7a2955383ap-1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_027(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.333333333333bp+1', '-0x1.666666666664dp+0')
		th = itvFromHex('-0x1.4d02421c87564p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.7041d713899f3p+0')
		y_ref = itvFromHex('-0x1.333333333333bp+1', '-0x1.ab1c35d8a7489p+0')
		th_ref = itvFromHex('-0x1.2d0ead60663a4p+0', '-0x1.07e4cef4cbd85p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_028(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.333333333333bp+1', '-0x1.666666666664dp+0')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.7041d713899f3p+0')
		y_ref = itvFromHex('-0x1.333333333333bp+1', '-0x1.ab1c35d8a7489p+0')
		th_ref = itvFromHex('-0x1.2d0ead60663a4p+0', '-0x1.07e4cef4cbd85p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_029(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.4ccccccccccd5p+1', '-0x1.999999999997fp+0')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.8ef1fe552a6c7p+0')
		y_ref = itvFromHex('-0x1.4ccccccccccd5p+1', '-0x1.ab1c35d8a7489p+0')
		th_ref = itvFromHex('-0x1.34209a8c1098ep+0', '-0x1.07e4cef4cbd85p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_030(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.99999999999a3p+1', '-0x1.199999999998ap+1')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.eb02741a0cd43p+0')
		y_ref = itvFromHex('-0x1.99999999999a3p+1', '-0x1.199999999998ap+1')
		th_ref = itvFromHex('-0x1.4495d86823234p+0', '-0x1.07e4cef4cbd85p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_031(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.066666666666dp+2', '-0x1.8ccccccccccb6p+1')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.3a8d9260b0380p+1')
		y_ref = itvFromHex('-0x1.066666666666dp+2', '-0x1.8ccccccccccb6p+1')
		th_ref = itvFromHex('-0x1.54e16d0a3f522p+0', '-0x1.07e4cef4cbd85p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_032(self):
		x = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('0x1.0000000000000p+0', '0x1.4000000000000p+1')
		y_ref = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th_ref = itvFromHex('-0x1.56491d6ec41dcp+0', '-0x1.07e4cef4cbd85p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_033(self):
		x = itvFromHex('0x1.9999999999989p-3', '0x1.b33333333333dp+0')
		y = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('0x1.9999999999989p-3', '0x1.b33333333333dp+0')
		y_ref = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th_ref = itvFromHex('-0x1.85f14d43d81cep+0', '-0x1.151c4116f2801p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_034(self):
		x = itvFromHex('-0x1.99999999999a1p+0', '-0x1.99999999998b0p-4')
		y = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('-0x1.99999999999a1p+0', '-0x1.99999999998b0p-4')
		y_ref = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th_ref = itvFromHex('-0x1.0468a8ace4dffp+1', '-0x1.9837cb5534cf7p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_035(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th = itvFromHex('-0x1.b18a2f6d980b4p+1', '-0x1.07e4cef4cbd85p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th_ref = itvFromHex('-0x1.251279b802823p+1', '-0x1.def7b9d62da87p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_036(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('-0x1.0ccccccccccd4p+2', '-0x1.9999999999982p+1')
		th_ref = itvFromHex('-0x1.251279b802823p+1', '-0x1.def7b9d62da87p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_037(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('-0x1.6666666666680p+1', '-0x1.ccccccccccc98p+0')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('-0x1.6666666666680p+1', '-0x1.ccccccccccc98p+0')
		th_ref = itvFromHex('-0x1.48fe1f1cd42acp+1', '-0x1.00b320ad6fa6cp+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_038(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('-0x1.4cccccccccd11p+0', '-0x1.333333333324bp-2')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('-0x1.4cccccccccd11p+0', '-0x1.333333333324bp-2')
		th_ref = itvFromHex('-0x1.8476318c96b67p+1', '-0x1.2d97c7f3321bdp+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_039(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('-0x1.9999999999bcfp-3', '0x1.9999999999a11p-1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('-0x1.9999999999bcfp-3', '0x1.9999999999a11p-1')
		th_ref = itvFromHex('-0x1.d8bc56aa942d1p+1', '-0x1.7e95b1e3a76a7p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_040(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('0x1.33333333332a5p-1', '0x1.99999999999d9p+0')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('0x1.33333333332a5p-1', '0x1.99999999999d9p+0')
		th_ref = itvFromHex('-0x1.01ecb4e504e79p+2', '-0x1.ad24d07d8f046p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_041(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('0x1.7ffffffffffb6p+0', '0x1.4000000000022p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('0x1.7ffffffffffb6p+0', '0x1.4000000000022p+1')
		th_ref = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d1134fa7a211ap+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_042(self):
		x = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y = itvFromHex('0x1.e66666666661ap+0', '0x1.7333333333356p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.666666666666dp+1', '-0x1.4ccccccccccbcp+0')
		y_ref = itvFromHex('0x1.e66666666661ap+0', '0x1.7333333333356p+1')
		th_ref = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.de6ff62726236p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_043(self):
		x = itvFromHex('-0x1.2666666666671p+1', '-0x1.9999999999974p-1')
		y = itvFromHex('0x1.e66666666661ap+0', '0x1.7333333333356p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.2666666666671p+1', '-0x1.238974ef77896p+0')
		y_ref = itvFromHex('0x1.e66666666661ap+0', '0x1.7333333333356p+1')
		th_ref = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.ea8041f09b00dp+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_044(self):
		x = itvFromHex('-0x1.000000000000dp+1', '-0x1.fffffffffffb1p-2')
		y = itvFromHex('0x1.e66666666661ap+0', '0x1.7333333333356p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.000000000000dp+1', '-0x1.238974ef77896p+0')
		y_ref = itvFromHex('0x1.e66666666661ap+0', '0x1.7333333333356p+1')
		th_ref = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.f35f9d30b7554p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_045(self):
		x = itvFromHex('-0x1.99999999999b6p+0', '-0x1.9999999999858p-4')
		y = itvFromHex('0x1.e66666666661ap+0', '0x1.7333333333356p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.99999999999b6p+0', '-0x1.238974ef77896p+0')
		y_ref = itvFromHex('0x1.e66666666661ap+0', '0x1.55b02b13b91cap+1')
		th_ref = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.00ccbc7ca8a80p+2')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_046(self):
		x = itvFromHex('-0x1.99999999999b6p+0', '-0x1.9999999999858p-4')
		y = itvFromHex('0x1.e66666666661ap+0', '0x1.e6666666666acp+0')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.99999999999b6p+0', '-0x1.238974ef77896p+0')
		y_ref = itvFromHex('0x1.e66666666661ap+0', '0x1.e6666666666acp+0')
		th_ref = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.00ccbc7ca8a80p+2')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_047(self):
		x = itvFromHex('-0x1.19999999999a9p+1', '-0x1.666666666663dp-1')
		y = itvFromHex('0x1.8cccccccccc9ep+1', '0x1.8ccccccccccf2p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.19999999999a9p+1', '-0x1.dbaa60793c4d2p+0')
		y_ref = itvFromHex('0x1.8cccccccccc9ep+1', '0x1.8ccccccccccf2p+1')
		th_ref = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.0617b7a0afa48p+2')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_048(self):
		x = itvFromHex('-0x1.19999999999aap+1', '-0x1.666666666663cp-1')
		y = itvFromHex('-0x1.c280000000000p-46', '0x1.a880000000000p-46')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.19999999999aap+1', '-0x1.666666666663cp-1')
		y_ref = itvFromHex('-0x1.c280000000000p-46', '0x1.a880000000000p-46')
		th_ref = itvFromHex('-0x1.921fb54442d66p+1', '-0x1.921fb54442cc7p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_049(self):
		x = itvFromHex('-0x1.cccccccccccf2p+0', '-0x1.33333333332dbp-2')
		y = itvFromHex('-0x1.000000000003cp+1', '-0x1.fffffffffff8fp+0')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.cccccccccccf2p+0', '-0x1.007fa758625d9p-1')
		y_ref = itvFromHex('-0x1.000000000003cp+1', '-0x1.fffffffffff8fp+0')
		th_ref = itvFromHex('-0x1.26dcbd4239793p+1', '-0x1.d0f4a996ed405p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_050(self):
		x = itvFromHex('-0x1.8000000000027p+0', '0x1.6200000000000p-48')
		y = itvFromHex('-0x1.a6666666666a5p+1', '-0x1.a666666666624p+1')
		th = itvFromHex('-0x1.0b090e5f54604p+2', '-0x1.d0f4a996ed405p+0')
		x_ref = itvFromHex('-0x1.8000000000027p+0', '-0x1.a7390751d5828p-1')
		y_ref = itvFromHex('-0x1.a6666666666a5p+1', '-0x1.a666666666624p+1')
		th_ref = itvFromHex('-0x1.ff572aded0c0cp+0', '-0x1.d0f4a996ed405p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_051(self):
		x = itvFromHex('-0x1.3333333333388p-1', '0x1.cccccccccccfdp-1')
		y = itvFromHex('-0x1.a6666666666a5p+1', '-0x1.a666666666624p+1')
		th = itvFromHex('-0x1.6c6cbc45dc90cp+1', '-0x1.f6a7a295537c9p-2')
		x_ref = itvFromHex('-0x1.3333333333388p-1', '0x1.cccccccccccfdp-1')
		y_ref = itvFromHex('-0x1.a6666666666a5p+1', '-0x1.a666666666624p+1')
		th_ref = itvFromHex('-0x1.c02a9647f0dd5p+0', '-0x1.4df69d20aa2ebp+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_052(self):
		x = itvFromHex('-0x1.3333333333388p-1', '0x1.cccccccccccfdp-1')
		y = itvFromHex('-0x1.a6666666666a5p+1', '-0x1.a666666666624p+1')
		th = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.921fb54442ce6p+0')
		x_ref = itvFromHex('-0x1.3333333333388p-1', '0x1.6ad6be0852ff0p-32')
		y_ref = itvFromHex('-0x1.a6666666666a5p+1', '-0x1.a666666666624p+1')
		th_ref = itvFromHex('-0x1.c02a9647f0dd5p+0', '-0x1.921fb54442ce6p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_053(self):
		x = itvFromHex('-0x1.3333333333388p-1', '0x1.cccccccccccfdp-1')
		y = itvFromHex('0x1.9999999999737p-2', '0x1.9999999999bdbp-2')
		th = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.921fb54442ce6p+0')
		x_ref = itvFromHex('-0x1.3333333333388p-1', '-0x1.999999999957bp-2')
		y_ref = itvFromHex('0x1.9999999999737p-2', '0x1.9999999999bdbp-2')
		th_ref = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.dd63609c5c593p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_054(self):
		x = itvFromHex('-0x1.3333333333388p-1', '-0x1.3333333333388p-1')
		y = itvFromHex('0x1.9999999999737p-2', '0x1.33333333332e7p+1')
		th = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.40714472653d0p+1')
		x_ref = itvFromHex('-0x1.3333333333388p-1', '-0x1.3333333333388p-1')
		y_ref = itvFromHex('0x1.9999999999737p-2', '0x1.33333333334d5p-1')
		th_ref = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.dd63609c5c593p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_055(self):
		x = itvFromHex('-0x1.0cccccccccce5p+1', '-0x1.0ccccccccccdep+1')
		y = itvFromHex('0x1.9999999999737p-2', '0x1.33333333332e7p+1')
		th = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.40714472653d0p+1')
		x_ref = itvFromHex('-0x1.0cccccccccce5p+1', '-0x1.0ccccccccccdep+1')
		y_ref = itvFromHex('0x1.9999999999737p-2', '0x1.0ccccccccce08p+1')
		th_ref = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.aa3759b11adbap+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_056(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('0x1.33333333330d0p-2', '0x1.266666666661bp+1')
		th = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.40714472653d0p+1')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('0x1.33333333330d0p-2', '0x1.266666666661bp+1')
		th_ref = itvFromHex('-0x1.e1e4b426bd2cap+1', '-0x1.9e16c15744488p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_057(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('-0x1.f6a7a2955389ep+1', '-0x1.40714472653d0p+1')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th_ref = itvFromHex('-0x1.ca3b1ed6e0647p+1', '-0x1.7e48c65b7c6d9p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_058(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('0x1.1abe4b73fef53p+1', '0x1.d0f4a996ed466p+1')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th_ref = itvFromHex('0x1.5a044bb1a53ebp+1', '0x1.a5f6a42d09359p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_059(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('0x1.f383632acafbdp+2', '0x1.274f491e21167p+3')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('0x1.45e5e4d10e4f8p-1', '0x1.7ffffffffff70p+0')
		th_ref = itvFromHex('0x1.1f90ed8e8ab87p+3', '0x1.274f491e21167p+3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_060(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('0x1.1607ec5432308p+3', '0x1.439583dcedca3p+3')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th_ref = itvFromHex('0x1.1f90ed8e8ab87p+3', '0x1.328d83ad63b63p+3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_061(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('0x1.2a738888a9951p+3', '0x1.58012011652f9p+3')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.42bc93d15ce0dp-2')
		th_ref = itvFromHex('0x1.2a738888a9951p+3', '0x1.328d83ad63b63p+3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_062(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('0x1.c2d18c3786e5ep+3', '0x1.f05f23c042867p+3')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('0x1.45e5e4d10ccd9p-1', '0x1.7ffffffffff70p+0')
		th_ref = itvFromHex('0x1.e8a0c830ac213p+3', '0x1.f05f23c042867p+3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_063(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('0x1.d418e90175c4dp+3', '0x1.00d3404518b31p+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th_ref = itvFromHex('0x1.e8a0c830ac213p+3', '0x1.fb9d5e4f851f0p+3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_064(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff70p+0')
		th = itvFromHex('0x1.f1f1437586ba4p+3', '0x1.0fbf6d7f212e6p+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.99999999999a2p+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.e6113ec3cebe3p-2')
		th_ref = itvFromHex('0x1.f1f1437586ba4p+3', '0x1.fb9d5e4f851f0p+3')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_065(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.f1f1437586ba4p+3', '0x1.0fbf6d7f212e6p+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '0x0.0p+0')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.e6113ec3cebe3p-2')
		th_ref = itvFromHex('0x1.f1f1437586ba4p+3', '0x1.0fbf6d7f212e6p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_066(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.032e6fd4ff0f4p+4', '0x1.19f53b995ce11p+4')
		x_ref = itvFromHex('-0x1.def13b73c1e63p-1', '0x1.6e649f7d7a86ep-3')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x0.0p+0')
		th_ref = itvFromHex('0x1.032e6fd4ff0f4p+4', '0x1.19f53b995ce11p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_067(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.11518d3465680p+4', '0x1.281858f8c33afp+4')
		x_ref = itvFromHex('-0x1.975f5e0554745p-4', '0x1.65bc6cc8274dcp+0')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x0.0p+0')
		th_ref = itvFromHex('0x1.11518d3465680p+4', '0x1.281858f8c33afp+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_068(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.1abe4b73fef88p+4', '0x1.318517385ccc3p+4')
		x_ref = itvFromHex('0x0.0p+0', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.e758f127f23ddp-1')
		th_ref = itvFromHex('0x1.1abe4b73fef88p+4', '0x1.318517385ccc3p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_069(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.21cfda23b224ep+4', '0x1.3896a5e80ff92p+4')
		x_ref = itvFromHex('0x0.0p+0', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.21cfda23b224ep+4', '0x1.3896a5e80ff92p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_070(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.2a738888a9940p+4', '0x1.413a544d0768fp+4')
		x_ref = itvFromHex('0x0.0p+0', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.2a738888a9940p+4', '0x1.413a544d0768fp+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_071(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.331736eda1032p+4', '0x1.49de02b1fed8cp+4')
		x_ref = itvFromHex('-0x1.3187868401c1ep-2', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('0x0.0p+0', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.331736eda1032p+4', '0x1.49de02b1fed8cp+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_072(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.3e1614e27ed66p+4', '0x1.54dce0a6dcacep+4')
		x_ref = itvFromHex('-0x1.d3e7c544b32ccp+0', '0x1.cc524cd86d121p-1')
		y_ref = itvFromHex('0x0.0p+0', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.3e1614e27ed66p+4', '0x1.54dce0a6dcacep+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_073(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.4527a3923202cp+4', '0x1.8b0e26948fb01p+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '0x1.0ea21d7171c0fp+0')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.4527a3923202cp+4', '0x1.8b0e26948fb01p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_074(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.49de02b1fecb0p+4', '0x1.8fc485b45c78bp+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '0x1.af73f4ca3b7bap+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.49de02b1fecb0p+4', '0x1.8fc485b45c78bp+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_075(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.4dcb51f72971ep+4', '0x1.93b1d4f9871fep+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.4dcb51f72971ep+4', '0x1.93b1d4f9871fep+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_076(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.58ca2fec07452p+4', '0x1.9eb0b2ee64f40p+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.58ca2fec07452p+4', '0x1.9eb0b2ee64f40p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_077(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.5d808f0bd40d6p+4', '0x1.a367120e31bcap+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.5d808f0bd40d6p+4', '0x1.a367120e31bcap+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_078(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.687f6d00b1e0ap+4', '0x1.ae65f0030f90cp+4')
		x_ref = itvFromHex('-0x1.ab1c35d8a8e6ep-1', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.687f6d00b1e0ap+4', '0x1.ae65f0030f90cp+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_079(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.6d35cc207ea8ep+4', '0x1.b31c4f22dc596p+4')
		x_ref = itvFromHex('-0x1.9a812a58c7fd3p-1', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.6d35cc207ea8ep+4', '0x1.b31c4f22dc596p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_080(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '0x1.e66666666664cp+1')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.75106aaad3f6ap+4', '0x1.baf6edad31a7cp+4')
		x_ref = itvFromHex('-0x1.1f592a9c3f675p+1', '0x1.e66666666664cp+1')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.75106aaad3f6ap+4', '0x1.baf6edad31a7cp+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_081(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.75106aaad3f6ap+4', '0x1.baf6edad31a7cp+4')
		x_ref = itvFromHex('-0x1.1f592a9c3f675p+1', '-0x1.9999999999b40p-3')
		y_ref = itvFromHex('0x1.11af9bbc64444p-3', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.ad609ef38afa4p+4', '0x1.baf6edad31a7cp+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_082(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.7db4190fcb65cp+4', '0x1.c39a9c1229179p+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y_ref = itvFromHex('0x1.41f52d4faba3bp-7', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.ad609ef38afa4p+4', '0x1.c39a9c1229179p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_083(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('0x1.87e9e72a0717ap+4', '0x1.cdd06a2c64ca4p+4')
		x_ref = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.ad609ef38afa4p+4', '0x1.cdd06a2c64ca4p+4')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_084(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('-0x1.d0f4a996ee69cp+0', '0x1.46b9c34777068p+1')
		x_ref = itvFromHex('-0x1.1f592a9c41020p+1', '-0x1.9999999999b40p-3')
		y_ref = itvFromHex('0x1.11af9bbc62bd2p-3', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.b40e9af4828bap+0', '0x1.46b9c34777068p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_085(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('-0x1.4d02421c87e9cp+1', '0x1.c463abeccca50p+0')
		x_ref = itvFromHex('-0x1.ab1c35d8abd22p-1', '-0x1.9999999999b40p-3')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('-0x1.4d02421c87e9cp+1', '0x1.c463abeccca50p+0')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_086(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('-0x1.dd85a74110820p+0', '0x1.4071447265fc1p+1')
		x_ref = itvFromHex('-0x1.02e1cccf26d66p+1', '-0x1.9999999999b40p-3')
		y_ref = itvFromHex('0x1.2fc7b2421072bp-3', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('0x1.b40e9af4828bap+0', '0x1.4071447265fc1p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)


	def test_087(self):
		x = itvFromHex('-0x1.99999999999b4p+1', '-0x1.9999999999b40p-3')
		y = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th = itvFromHex('-0x1.f6a7a29554af2p+0', '0x1.33e046c843e59p+1')
		x_ref = itvFromHex('-0x1.a7adbffbba092p+0', '-0x1.9999999999b40p-3')
		y_ref = itvFromHex('-0x1.0000000000133p-1', '0x1.7ffffffffff71p+0')
		th_ref = itvFromHex('-0x1.f6a7a29554af2p+0', '0x1.33e046c843e59p+1')
		xx,yy,thh = Catan2(x,y,th)
		self.assertEqual(xx,x_ref)
		self.assertEqual(yy,y_ref)
		self.assertEqual(thh,th_ref)

if __name__ == '__main__':

	unittest.main()
