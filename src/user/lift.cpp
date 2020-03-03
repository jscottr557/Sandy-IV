#include "user/lift.hpp"

/*README IF YOU WANT TO CHANGE THIS MOTOR
  TO REVERSE:
    Set the third value in the constructor call to its current opposite;
    if it is 1 now, change it to 0, if it is 0 now, change it to 1.

  TO CHANGE PORT:
    Change the first value in the constructor call to the motor's new port.

  You can also mouse over the constructor to gain additional information about
  each parameter if you desire.
*/
Motor lift(4, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);

void initLift()
{
  lift.tare_position();

  lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}

int getLiftPos()
{
  return lift.get_position();
}

void moveLiftPower(int power)
{
  lift.move(power);
}

void controlLift(Controller controller)
{
  if(controller.get_digital(E_CONTROLLER_DIGITAL_R1))
  {
    moveLiftPower(127);
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_R2))
  {
    moveLiftPower(-127);
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_R1) == 0)
  {
    moveLiftPower(0);
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_R2) == 0)
  {
    moveLiftPower(0);
  }
}

void controlLift(bool btnUp, bool btnDown)
{
  if(btnUp)
  {
    moveLiftPower(127);
  }
  else if(btnDown)
  {
    moveLiftPower(-127);
  }
  else
  {
    moveLiftPower(0);
  }
}

void moveLiftTo(int pos)
{
  int avgPos = 0;
  int distErr = 0;
  int power = 0;

  while(avgPos != pos)
  {
    avgPos = getLiftPos();//avglift
    distErr = pos - avgPos;

    power = distErr;

    lift.move_velocity(power);
  }
}
