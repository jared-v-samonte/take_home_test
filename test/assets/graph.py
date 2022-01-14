import sys
import matplotlib
matplotlib.use('Qt5Agg')

import collections

from PyQt5 import QtCore, QtWidgets

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg
from matplotlib.figure import Figure
from matplotlib import colors as mcolors

import pylab as pl
from matplotlib import collections  as mc
import matplotlib.pyplot


class MplCanvas(FigureCanvasQTAgg):

    def __init__(self, parent=None, width=5, height=4, dpi=100):
        fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = fig.add_subplot(111)
        segement_list= collections.deque()
        segement_list.append([(0, 1), (1, 1)])
        segement_list.append([(2, 6), (6, 2)])
        segement_list.append([(8, 8), (9, 7)])
        colors = [mcolors.to_rgba(c)
          for c in matplotlib.pyplot.rcParams['axes.prop_cycle'].by_key()['color']]

        lc = mc.LineCollection(list(segement_list), colors=colors, linewidths=2)
        fig, ax = pl.subplots()
        ax.add_collection(lc)
        ax.autoscale()
        ax.margins(0.1)
        super(MplCanvas, self).__init__(fig)


class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)

        # Create the maptlotlib FigureCanvas object,
        # which defines a single set of axes as self.axes.
        sc = MplCanvas(self, width=5, height=4, dpi=100)
        #sc.axes.plot([0,1,2,3,4], [10,1,20,3,40])
        self.setCentralWidget(sc)

        self.show()

# driver code
if __name__ == '__main__':	
	app = QtWidgets.QApplication(sys.argv)
	w = MainWindow()
	app.exec_()
