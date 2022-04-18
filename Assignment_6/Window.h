/* This file is used to declare the Window class. It declares the default constructor, destructor, and public variable idleTime.
   idleTime stores the amount of time a window is idle during the simulation.

*/
#include <iostream>
using namespace std;

class Window{
public:
  Window();
  ~Window();
  int idleTime;
};
