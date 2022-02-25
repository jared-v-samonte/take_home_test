# The Tasks
The input data is a JSON file that contains an array of 2-D line segments. Some line segments may be merged: they are parallel and share an endpoint. 

There are two tasks: 
* Find all merge-able lines from the original [1-split.json](test/assets/1-split.json) file and merge them. We have provided some boilerplate code/project files to get you started.
* Write a separate python script that take in the original [1-split.json](test/assets/1-split.json) along with the solution output from your code and visualize the lines on two graphs. You may use any open source Python or C++ library. 

## How to build
* MacOS(or Linux)/CLion: open the project in CLion, build, run the stub test.
* Windows/Visual Studio 2019: ask Visual Studio to clone this repo locally. It will open the project once done. Build, run the stub test.
* Windows/Visual Studio 2107: create a build folder outside of your repository. In your command prompt, execute ``cmake <path to your repository>``. That will create a Visual Studio solution. Open that in Visual Studio, build, run the stub test. Use Visual Studio to develop/debug. When you need to modify a project or the solution, change the CMakeLists.txt and rerun cmake.
* Linux/cmake:
  ```
  $ mkdir build && cd build
  $ cmake ..
  $ make
  ```

# Prerquesites
*Build:
* * WSL 2 (Windows Subsystem Linux) 
* * Xming
* * Xlaunch 
* * VcXsrv
* Install Prerquesites
* * sudo apt install x11-apps
* * sudo apt install x11-xserver-utils
* * sudo apt-get update && sudo apt-get install build-essential
* * sudo apt install cmake
* * sudo apt install g++
* Diaply Set-Up (must do this for every newly opened teminal):
* * export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
* * export LIBGL_ALWAYS_INDIRECT=0
* * export CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:/usr/include/python3.8/"

Set-Up:

mkdir build && cd build
cmake ..
make

unset PYTHONPATH
unset PYTHONHOME