#include "user/lift.hpp"

//TODO: make sure the ports are set correctly once
Motor lift(7, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
//Motor //lift(6, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);

void initLift()
{
  lift.tare_position();
  //lift.tare_position();

  lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  //lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}

int getAvgLiftPos()
{
  return /*(fabs(//lift.get_position()) +*/ fabs(lift.get_position());//)/2;
}

void moveLiftPower(int power)
{
  lift.move(power);
  //lift.move(power);
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

void moveLiftTo(int pos)
{
  int avgPos = 0;
  int distErr = 0;
  int power = 0;

  while(avgPos != pos)
  {
    avgPos = getAvgLiftPos();
    distErr = pos - avgPos;

    power = distErr;

    lift.move_velocity(power);
  }
}
