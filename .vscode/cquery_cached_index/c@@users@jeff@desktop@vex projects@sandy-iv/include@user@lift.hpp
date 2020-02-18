#include "api.h"

using namespace pros;

/*Clears the IMES(Integrated motor encoders) on the lift motor, and sets it
  to hold its position*/
void initLift();

/*Returns the number of ticks(degrees) the lift motor has
  traveled(rotated).*/
int getLiftPos();

/*Sets the arbitrary "power" of the lift motor

  \param power
    The amount of "power" you want behind the motor's rotation.
    This number is more an indicator of scale than anything else, with numbers
    farther from 0 indicating more "power", and sign indicating direction.
    Valid arguments:
      From -127 to 127(inclusive)
*/
void moveLiftPower(int power);

/*Moves the lift to a specific tick position

  \note The position that the lift "moves"(rotates) to depends on its starting
  position; the position should be treated as absolute, and not relative

  \param pos
    The tick position the life should move/rotate to.
    Valid arguments:
      
*/
void moveLiftTo(int pos);

//Let the user control the lift in driver control
void controlLift(Controller controller);
