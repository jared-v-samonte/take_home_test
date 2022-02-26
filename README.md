# The Tasks
The input data is a JSON file that contains an array of 2-D line segments. Some line segments may be merged: they are parallel and share an endpoint. 

There are two tasks: 
* Find all merge-able lines from the original [1-split.json](test/assets/1-split.json) file and merge them. We have provided some boilerplate code/project files to get you started.
* Write a separate python script that take in the original [1-split.json](test/assets/1-split.json) along with the solution output from your code and visualize the lines on two graphs. You may use any open source Python or C++ library. 

## How to build and Run
* Build with Linux cmake:
  ```
  mkdir build && cd build
  cmake ..
  make
  ```
* Run main program in Windows Subsystem for Linux:
  ```
  ./take_home_test
  ```
* Run main program in Windows Subsystem for Linux:
  ```
  ./unit_ test to run tests
  ```
* Go to build folder
* ./take_home_test for running main file
* ./unit_ test to run tests

# Prerquesites
### Build:
* WSL 2 (Windows Subsystem Linux) 
* Xming
* Xlaunch 
* VcXsrv
### Install Prerquesites
* sudo apt install x11-apps
* sudo apt install x11-xserver-utils
* sudo apt-get update && sudo apt-get install build-essential
* sudo apt install cmake
* sudo apt install g++
### Dipaly Set-Up (must do this for every newly opened teminal):
* export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
* export LIBGL_ALWAYS_INDIRECT=0
* export CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:/usr/include/python3.8/"

