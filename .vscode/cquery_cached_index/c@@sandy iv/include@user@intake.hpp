#include "api.h"

using namespace pros;

/*Clears the IMES(Integrated motor encoders) on the intake motors, and sets them
  to brake automatically.*/
void initIntake();


/*Sets the state of the intake. This will always run the intake motors at full
  power, unless they are turned off.

  \param state
    What the intake should do. If in, intake turns in, if out, intake turns out,
    if off, intake stops.
    Valid arguments:
      in
      out
      off
*/
void setIntake(std::string state);


/*Allows the user to control the intake during opcontrol.

  \note This method uses the left bumper switches to control the motion of the
  intake. Additionally, if both the top and bottom left bumpers are pressed,
  the intake will override to turning out.

  \param controller
    An object used by the method to get driver inputs from.
    Valid arguments:
      A constructed Controller(from PROS API) object.
*/
void controlIntake(Controller controller);


/*Allows the user to control the intake during opcontrol. If only btnIn is true,
  the intake turns in, if only btnOut is true, the intake turns out, if both are
  true, the intake turns out, if both are false, the intake stops.

  \note The values passed to btnIn and btnOut should probably retrived from
  buttons close to each other on the controller.

  \param btnIn
    Value used to control which way the intake turns.
    Valid arguments:
      Either a 1 or a 0, usually obtained from the getDigital of a Controller
      object.

  \param btnIn
    Value used to control which way the intake turns.
    Valid arguments:
      Either a 1 or a 0, usually obtained from the getDigital of a Controller
      object.
*/
void controlIntake(bool btnIn, bool btnOut);
