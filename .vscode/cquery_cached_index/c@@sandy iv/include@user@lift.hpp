#include "api.h"

using namespace pros;

//Clear the encoder on the lift motor, set it to hold its position
void initLift();

//Get the average position of the lift motor encoder
int getAvgLiftPos();

//Set the arbitrary "power" of both of the lift motors
//Args for power are -127 to 127
void moveLiftPower(int power);

//Move the lift to a specific tick position
void moveLiftTo(int pos);

//Let the user control the lift in driver control
void controlLift(Controller controller);
