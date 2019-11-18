#include "api.h"

//The set of commands for atuon on the red side
void autonRed();

//The set of commands for atuon on the red side
void autonBlue();

//Decide which autotmous to run based on input
//Args for autonSel are from 0 to 4095(the range of values of a potentiometer)
void decideAuton(int autonSel);
