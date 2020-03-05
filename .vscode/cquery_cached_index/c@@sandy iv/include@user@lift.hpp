#include "api.h"

using namespace pros;

/*Clears the IMES(Integrated motor encoders) on the lift motor, and sets it
  to hold its position.*/
void initLift();


/*Returns the number of ticks(degrees) the lift motor has
  traveled(rotated).*/
int getLiftPos();


/*Sets the arbitrary "power" of the lift motor.

  \param power
    The amount of "power" you want behind the motor's rotation.
    This number is an indicator of scale more than anything else, with numbers
    farther from 0 indicating more "power", and sign indicating direction.
    Valid arguments:
      From -127 to 127(inclusive).
*/
void moveLiftPower(int power);


/*Moves the lift to a specific tick position.

  \note The position that the lift "moves"(rotates) to depends on its starting
  position; the position should be treated as absolute, and not relative.

  \param pos
    The tick position the life should move/rotate to.
    Valid arguments:
      Any position the lift can move to.
*/
void moveLiftTo(int pos);


/*Allows the user to control the lift during opcontrol.

  \note This method uses the right bumper switches to control the motion of the
  intake. Additionally, if both the top and bottom right bumpers are pressed,
  the lift will override to moving up.

  \param controller
    An object used by the method to get driver inputs from.
    Valid arguments:
      A constructed Controller(from PROS API) object.
*/
void controlLift(Controller controller);


/*Allows the user to control the lift during opcontrol. If only btnDown is true,
  the lift moves down, if only btnUp is true, the lift moves up, if both are
  true, the lift moves up, if both are false, the lift stops.

  \note The values passed to btnUp and btnDown should probably retrived from
  buttons close to each other on the controller.

  \param btnUp
    Value used to control which way the lift moves.
    Valid arguments:
      Either a 1 or a 0, usually obtained from the getDigital of a Controller
      object.

  \param btnIn
    Value used to control which way the lift moves.
    Valid arguments:
      Either a 1 or a 0, usually obtained from the getDigital of a Controller
      object.
*/
void controlLift(bool btnUp, bool btnDown);
