import sys
import matplotlib
import collections
matplotlib.use('Qt5Agg')


from PyQt5 import QtCore, QtWidgets

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg
from matplotlib.figure import Figure

import numpy as np
import pylab as pl
from matplotlib import collections  as mc
import matplotlib.pyplot

class MplCanvas(FigureCanvasQTAgg):

    def __init__(self, parent=None, width=5, height=4, dpi=100):
        fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = fig.add_subplot(111)
        lines = [[(0, 1), (1, 1)], [(2, 3), (3, 3)], [(1, 2), (1, 3)]]
        c = np.array([(1, 0, 0, 1), (0, 1, 0, 1), (0, 0, 1, 1)])

        lc = mc.LineCollection(lines, colors=matplotlib.pyplot.cm.gist_ncar(np.random.random()), linewidths=2)
        fig, ax = pl.subplots()
        ax.add_collection(lc)
        ax.autoscale()
        ax.margins(0.1)
        super(MplCanvas, self).__init__(fig)


class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, segement_list):
        #super(MainWindow, self).__init__(segement_list)

        # Create the maptlotlib FigureCanvas object,
        # which defines a single set of axes as self.axes.
        print(segement_list)
        sc = MplCanvas(self, width=5, height=4, dpi=100)
        #sc.axes.plot([0,1,2,3,4], [10,1,20,3,40])
        self.setCentralWidget(sc)

        self.show()
        
    
        
class List():
    
    def __init__(self):
        self.segement_list= collections.deque()
        super(List, self).__init__()

    def add_linesegment(self, start_x, start_y, end_x, end_y):
        global segement_list
        self.segement_list.append([(start_x, start_y), (end_x, end_y)])

    def print_link_list(self):
        print(self.segement_list)

    def display(self):
        global segement_list
        app = QtWidgets.QApplication(sys.argv)
        w = MainWindow(self.segement_list)
        app.exec_()
