import sys
import matplotlib
import collections
matplotlib.use('Qt5Agg')

from PySide2 import QtWidgets

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas

from matplotlib.figure import Figure
from matplotlib import colors as mcolors

import pylab as pl
from matplotlib import collections  as mc
import matplotlib.pyplot as plt


class LinesDisplay(QtWidgets.QWidget):

    def __init__(self, original_list, new_list):
        super(LinesDisplay, self).__init__()
        # Create the maptlotlib FigureCanvas object,
        # which defines a single set of axes as self.axes.
        #self.figure = plt.gcf()
        self.figure, (self.axes1, self.axes2) = plt.subplots(2)
        self.canvas = FigureCanvas(self.figure)

        #self.axes1 = self.figure.add_subplot(111)
        #self.axes2 = self.figure.add_subplot(111)

        self.axes1.set_title('Before')
        self.axes1.set_xlim(-600, 1000)
        self.axes1.set_ylim(-1100, 600)
        
        self.axes2.set_title('After')
        self.axes2.set_xlim(-600, 1000)
        self.axes2.set_ylim(-1100, 600)

        colors = [mcolors.to_rgba(c)
          for c in matplotlib.pyplot.rcParams['axes.prop_cycle'].by_key()['color']]

        lc = mc.LineCollection(list(original_list), colors=colors, linewidths=2)
        lc2 = mc.LineCollection(list(new_list), colors=colors, linewidths=2)

        self.axes1.add_collection(lc)
        self.axes2.add_collection(lc2)

        layout_canvas = QtWidgets.QVBoxLayout(self)
        layout_canvas.addWidget(self.canvas)

        
    
        
class List():
    
    def __init__(self):
        self.original_list= collections.deque()
        self.new_list= collections.deque()
        super(List, self).__init__()

    def addLineToOriginal(self, start_x, start_y, end_x, end_y):
        self.original_list.append([(start_x, start_y), (end_x, end_y)])

    def addLineToNew(self, start_x, start_y, end_x, end_y):
        self.new_list.append([(start_x, start_y), (end_x, end_y)])
                        
    def display(self):
        app = QtWidgets.QApplication(sys.argv)
        w = LinesDisplay(self.original_list, self.new_list)
        w.show()
        sys.exit(app.exec_())
