#include "api.h"

using namespace pros;

/*Clears the IME(Integrated motor encoder) on the tray motor, and sets it to
  hold its position automatically.*/
void initTray();


/*Returns the number of ticks(degrees) the tray motor has
  traveled(rotated).*/
int getTrayPos();


/*Sets the arbitrary "power" of the tray motor.

  \param power
    The amount of "power" you want behind the motor's rotation.
    This number is more an indicator of scale than anything else, with numbers
    farther from 0 indicating more "power", and sign indicating direction.
    Valid arguments:
      From -127 to 127(inclusive).
*/
void setTrayPower(int power);


/*Moves the tray to a specific tick position.

  \note The position that the tray "moves"(rotates) to depends on its starting
  position; the position should be treated as absolute, and not relative.

  \param pos
    The tick position the tray should move/rotate to.
    Valid arguments:
      Any position the tray can move to(for our team this is ~2900).
*/
void moveTrayTo(int pos);


/*Allows the user to control the tray during opcontrol.

  \note This method uses the left and right direction pads to control the motion
  of the intake. Additionally, if both the top and bottom direction buttons are
  pressed, the tray will override to moving up. Finally, this function does not
  provide full power to the motor, as full power is too jerky for the delicate
  operation of stacking cubes.

  \param controller
    An object used by the method to get driver inputs from.
    Valid arguments:
      A constructed Controller(from PROS API) object.
*/
void controlTray(Controller controller);


/*Allows the user to control the tray during opcontrol. If only btnDown is true,
  the tray moves down, if only btnUp is true, the tray moves up, if both are
  true, the tray moves up, if both are false, the lift stops.

  \note The values passed to btnUp and btnDown should probably retrived from
  buttons close to each other on the controller.

  \param btnUp
    Value used to control which way the tray moves.
    Valid arguments:
      Either a 1 or a 0, usually obtained from the getDigital of a Controller
      object.

  \param btnIn
    Value used to control which way the tray moves.
    Valid arguments:
      Either a 1 or a 0, usually obtained from the getDigital of a Controller
      object.
*/
void controlTray(bool btnUp, bool btnDown);
