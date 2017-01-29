from vibes import vibes
from pyibex import *
# Libraries we need
# import pyxhook
import time
import math
import curses
import curses.ascii

from curses import wrapper
from Catan2 import Catan2


def print2(itv):
  return "[%s; %s]"%(itv.lb().hex(),  itv.ub().hex())

def main(stdscr):
    # Clear screen
    stdscr.clear()
    stdscr.keypad(1)
    begin_x = 20; begin_y = 7
    height = 5; width = 40
    win = curses.newwin(height, width, begin_y, begin_x)
    stdscr.addstr(0,10,"Hit 'space' to quit")
    stdscr.refresh()
    cpt = 0
    key = ''
    x = Interval(1,1.5)
    y = Interval(2,3)
    dth = Interval.HALF_PI.mid()/32.
    th = Interval(0).inflate(2*dth)


    Interval.__str__ = print2
    fout = open("test.txt", "a")
    fout.write("#================ RUN ===============\n")

    while key != ord(' '):

        key = stdscr.getch()
        lower_key = chr(key).lower()

        if lower_key == 'z' :
          y += 0.5 if curses.ascii.isupper(key) else 0.1
        elif lower_key == 's' :
          y -= 0.5 if curses.ascii.isupper(key) else 0.1
        elif lower_key == 'd' :
          x += 0.5 if curses.ascii.isupper(key) else 0.1
        elif lower_key == 'q' :
          x -= 0.5 if curses.ascii.isupper(key) else 0.1
        elif lower_key == 'a':
          th += dth/8. if curses.ascii.isupper(key) else dth
        elif lower_key == 'e':
          th -= dth/8. if curses.ascii.isupper(key) else dth

        elif key == curses.KEY_NPAGE:
          th = th.lb() + (Interval(0,th.diam()-dth) | Interval(0))
        elif key == curses.KEY_PPAGE:
          th = th.lb() + (Interval(0,th.diam()+dth) | Interval(0))
        elif key == curses.KEY_RIGHT:
          x = x.lb() + (Interval(0,x.diam()+1) | Interval(0))
        elif key == curses.KEY_LEFT:
          x = x.lb() + (Interval(0,x.diam()-1) | Interval(0))
        elif key == curses.KEY_UP:
          y = y.lb() + (Interval(0,y.diam()+1) | Interval(0))
        elif key == curses.KEY_DOWN:
          y = y.lb() + (Interval(0,y.diam()-1) | Interval(0))

        #
        # # if curses.ascii.ascii(key) == "a":
        #
        # if key == curses.KEY_UP or key == 566:
        #   y += 0.5 if key==566 else 0.1
        # elif key == curses.KEY_DOWN or key == 525:
        #   y -= 0.5 if key==525 else 0.1
        # elif key == curses.KEY_RIGHT or key == 560:
        #   x += 0.5 if key==560 else 0.1
        # elif key == curses.KEY_LEFT or key == 545:
        #   x -= 0.5 if key==545 else 0.1
        # elif key == ord('a') or key == 1:
        #   th += 0.1 if key==1 else 0.05
        # elif key == ord('e') or key == 5:
        #   th -= 0.1 if key==5 else 0.05
        #
        # elif key == ord('A'):
        #   th = th.lb() + (Interval(0,th.diam()-0.1) | Interval(0))
        # elif key == ord('E'):
        #   th = th.lb() + (Interval(0,th.diam()+0.1) | Interval(0))
        # elif key == ord('z'):
        #   x = x.lb() + (Interval(0,x.diam()+1) | Interval(0))
        # elif key == ord('s'):
        #   x = x.lb() + (Interval(0,x.diam()-1) | Interval(0))
        # elif key == ord('d'):
        #   y = y.lb() + (Interval(0,y.diam()+1) | Interval(0))
        # elif key == ord('q'):
        #   y = y.lb() + (Interval(0,y.diam()-1) | Interval(0))

        elif key == ord('R'):
          x = Interval(1,1.5)
          y = Interval(2,3)
          th = Interval(0).inflate(1)


        xx,yy,thh = Catan2(x,y,Interval(th))

        # print(event.Key, event.Ascii, th, thh)
        # print(x, y, th  )
        vibes.clearFigure()
        vibes.drawBox(x[0], x[1], y[0], y[1], 'r')
        vibes.drawPie((0,0), (1e-5,5), th*180./math.pi, "r")
        vibes.drawPie((0,0), (1e-5,5), thh*180./math.pi, "b")
        vibes.drawBox(xx[0], xx[1], yy[0], yy[1], 'b')

        # if key in actions:
        #   x, y, th = actions[key]( x,y,th )
        # fct = actions.get(key, lambda x,y,th:x,y,th)

        stdscr.clear()
        stdscr.addstr(1, 10, "Pressed %s %d"%(lower_key, key))
        stdscr.addstr(1,25,str(curses.ascii.ctrl(key)))
        stdscr.addstr(1,40,str(curses.ascii.ascii(key)))
        stdscr.addstr(1,40,str(curses.ascii.alt(key)))
        stdscr.addstr(3, 20, "x    : %s\t\t%s"%(x,xx))
        stdscr.addstr(4, 20, "y    : %s\t\t%s"%(y,yy))
        stdscr.addstr(5, 20, "theta : %s\t\t%s"%(th, thh))
        if key == ord("t"):
          fout.write("%s %s %s -> %s %s %s\n"%(x,y,th, xx, yy, thh))
        stdscr.refresh()

    curses.endwin()
    fout.write("#===================== END ===============\n");

if __name__ == '__main__':
  vibes.beginDrawing()
  vibes.newFigure("Debut Catan2")
  vibes.setFigureSize(500,500)
  vibes.drawBox(-5,5,-5,5)
  vibes.axisAuto()

  wrapper(main)
