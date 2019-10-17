#include "api.h"

using namespace pros;

//CLear the encoders on the lift motors, set them to hold their position
void initLift();

//Get the average position of the lift motor encoders
int getAvgLiftPos();

//Set the arbitrary "power" of both of the lift motors
//Args for power are -127 to 127
void moveLiftPower(int power);

//Let the user control the lift in driver control
void controlLift(Controller controller);

//Move the lift to a specific tick position
void moveLiftTo(int pos);
