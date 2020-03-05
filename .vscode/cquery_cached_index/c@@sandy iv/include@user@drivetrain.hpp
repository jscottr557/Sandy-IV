#include "api.h"

using namespace pros;

/*Clears the IMES(Integrated motor encoders) on all of the drive motors, and
  sets how they brake, making all of the drivetrain ready for use.

  \param brakeMode
    How the motor should brake.
    Valid arguments:
      coast
      brake
      hold
*/
void initDrivetrain(std::string brakeMode);


/*Returns the average number of ticks(degrees) one side of the drivetrain has
  traveled(rotated).

  \param side
    Which side of the drivetrain to average the IME counts from.
    Valid arguments:
      l
      r
*/
int getAvgDriveSideTicks(char side);


/*Sets the arbitrary "power" of one side of the drivetrain.

  \param power
    The amount of "power" you want behind the motors rotation.
    This number is more an indicator of scale than anything else, with numbers
    farther from 0 indicating more "power", and sign indicating direction.
    Valid arguments:
      From -127 to 127(inclusive).

  \param side
    The side of the drivetrain to apply the "power" to
    Valid arguments:
      l
      r
*/
void setDriveSidePower(int power, char side);


/*Sets the velocity target one side of the drivetrain.

  \note Velocity is a target, and is not guananteed to be accurate.

  \param vel
    The target velocity in RPM.
    Valid arguments:
      From -200 to 200(inclusive) for standard motor gearsets(green).
      From -100 to 100(inclusive) for torque motor gearsets(red).
      From -600 to 600(inclusive) for high-speed motor gearsets(blue).

  \param side
    The side of the drivetrain to apply the velocity target to.
    Valid arguments:
      l
      r
*/
void setDriveSideVel(int vel, char side);


//Stops all of the motors on the drivetrain.
void stopAllDrive();


/*Lets the user control the drivetrain during opcontrol.

  \note This function has a "single stick arcade" layout; all of the
  movement of the drivetrain is controlled from one joystick, in this case,
  the rightmost one.

  \param controller
    An object used by the method to get driver inputs from.
    Valid arguments:
      A constructed Controller(from PROS API) object.
*/
void controlDrivetrain(Controller controller);


/*Lets the user control the drivetrain during opcontrol.

  \note This function has a "single stick arcade" layout; all of the
  movement of the drivetrain is controlled from one joystick.

  \param joyY
    The current y(vertical axis) value of the chosen control joystick.
    Valid arguments:
      Any value returned by a joystick axis from a V5 controller.

  \param joyX
    The current x(horizontal axis) value of the chosen control joystick.
    Valid arguments:
      Any value returned by a joystick axis from a V5 controller.
*/
void controlDrivetrain(int joyY, int joyX);


/*Moves the drivetrain stright forward or backward for a number of inches, using
  pre-written acceleration control to ensure smooth and accurate starting,
  movement and stopping.

  \note This function uses both custom and onboard PID to ensure proper
  movement, and will almost certainly require some tuning of constants in order
  to guanantee proper function.

  \param inches
    The number of inches to drive.
    Valid arguments:
      Any integer greater than 0.

  \param direction
    Which direction to drive.
    Valid arguments:
      forward
      backward
*/
void driveInches(int inches, std::string direction);


/*Moves the drivetrain stright forward or backward at a constant target velocity
  for a number of inches.

  \note This function uses both custom and onboard PID to ensure proper
  movement, and will almost certainly require some tuning of constants in order
  to guanantee proper function. Additionally, velocity is a
  target, and is not guananteed to be accurate.

  \param inches
    The number of inches to drive.
    Valid arguments:
      Any integer greater than 0.

  \param vel
    The target velocity for the drivetrain to maintain while it is moving.
    Valid arguments:
      From 0 to 200(inclusive) for standard motor gearsets(green).
      From 0 to 100(inclusive) for torque motor gearsets(red).
      From 0 to 600(inclusive) for high-speed motor gearsets(blue).

  \param direction
    Which direction to drive.
    Valid arguments:
      forward
      backward
*/
void driveInchesVel(int inches, int vel, std::string direction);


/*Point-Turns the drivetrain left or right a number of degrees, using
  pre-written acceleration control to ensure smooth and accurate starting,
  movement and stopping.

  \note This function uses both custom and onboard PID to ensure proper
  movement, and will almost certainly require some tuning of constants in order
  to guanantee proper function. Additionally, velocity is a
  target, and is not guananteed to be accurate.

  \param degrees
    The number of degrees to turn.
    Valid arguments:
      Any integer greater than 0

  \param direction
    Which direction to drive.
    Valid arguments:
      right
      left
*/
void turnDegrees(int degrees, std::string direction);
