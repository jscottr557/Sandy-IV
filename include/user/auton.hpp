#include "api.h"

//The set of commands for auton on the red side
void autonRed5();

void autonRed3();

//The set of commands for auton on the blue side
void autonBlue5();

void autonBlue3();

//The set of commands for the bump autonomous
void autonBump();

//The set of commands for auton during a skills run
void autonSkills();

//Decide which autotmous to run based on input
//Args for autonSel are from 0 to 4095(the range of values of a potentiometer)
void decideAuton(int autonSel);
