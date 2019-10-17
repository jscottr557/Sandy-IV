#include "api.h"

using namespace pros;

//CLear the encoder on the intake motors, set it to brake
void initIntake();

//Set the intake to intake or outtake at full power, or turn off
//Args for state are "in", "out", and "off"
void setIntake(std::string state);

//Let the user control the intake in driver control
void controlIntake(Controller controller);
