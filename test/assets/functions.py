import sys
import matplotlib
import collections
matplotlib.use('Qt5Agg')

#from PyQt5 import QtCore, QtWidgets
from PySide2 import QtCore, QtGui, QtWidgets

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas

from matplotlib.figure import Figure
from matplotlib import colors as mcolors

import pylab as pl
from matplotlib import collections  as mc
import matplotlib.pyplot as plt


class LinesDisplay(QtWidgets.QWidget):

    def __init__(self, segement_list):
        super(LinesDisplay, self).__init__()
        # Create the maptlotlib FigureCanvas object,
        # which defines a single set of axes as self.axes.


        self.figure = plt.gcf()
        self.canvas = FigureCanvas(self.figure)
        self.axes = self.figure.add_subplot(111)
        self.axes.set_xlim(-600, 1000)
        self.axes.set_ylim(-1100, 600)

        colors = [mcolors.to_rgba(c)
          for c in matplotlib.pyplot.rcParams['axes.prop_cycle'].by_key()['color']]

        lc = mc.LineCollection(list(segement_list), colors=colors, linewidths=2)
        self.axes.add_collection(lc)

        layout_canvas = QtWidgets.QVBoxLayout(self)
        layout_canvas.addWidget(self.canvas)

        
    
        
class List():
    
    def __init__(self):
        self.segement_list= collections.deque()
        super(List, self).__init__()

    def add_linesegment(self, start_x, start_y, end_x, end_y):
        self.segement_list.append([(start_x, start_y), (end_x, end_y)])

    def print_link_list(self):
        print(list(self.segement_list))


    def display(self):
        app = QtWidgets.QApplication(sys.argv)
        w = LinesDisplay(self.segement_list)
        w.show()
        sys.exit(app.exec_())
