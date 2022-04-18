/* main program that runs the simulation. Takes name of input file from user input in the terminal and uses that to run
   simulation. Simulation is done when metrics are displayed.
*/
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv){
  string theFile = argv[1];
  Simulation* aSimulation = new Simulation(theFile);
  aSimulation->simulate();
  return 0;
}
