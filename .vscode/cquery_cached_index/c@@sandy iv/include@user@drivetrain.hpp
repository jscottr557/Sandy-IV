#include "api.h"

using namespace pros;

//CLear the encoders on the drive motors, set how they brake
//Args for brakeMode are "coast", "brake", and "hold"
void initDrivetrain(std::string breakMode);

//Get the average number of ticks on a side of the drivetrain
//Args for side are a lowercase 'l', and 'r'
int getAvgDriveSideTicks(char side);

//Set the arbitrary "power" of one side of the drivetrain
//Args for side are a lowercase 'l', and 'r', power is from -127 to 127
void setDriveSidePower(int power, char side);

//Set the arbitrary "power" of the strafe motor on the drivetrain
//Args for power is from -127 to 127
void setStrafePower(int power);

//Set the velocity target of one side of the drivetrain
//Args for side are a lowercase 'l', and 'r', vel is from -200 to 200
void setDriveSideVel(int vel, char side);

//Set the velocity target for the strafe motor on the drivetrain
//Args for vel is from -200 to 200
void setStrafeVel(int vel);

//Stop all the motors on the drivetrain
void stopAll();

//Let the user control the drivetrain in driver control
void controlDrivetrain(Controller controller);

//Move the drivetrain forward or back a number of inches
//Args for direction are "forward" and "backward"
void driveInches(int inches, std::string direction);

//Turn the drivetrain a number of turnDegrees
//Args for direction are "left" with a lowercase "l", and "right"
void turnDegrees(int degrees, std::string direction);

//Strafe the drivetrain left or right a number of inches
//Arags for direction are a lowercase 'l', and 'r'
void strafeInches(int inches, char direction);
