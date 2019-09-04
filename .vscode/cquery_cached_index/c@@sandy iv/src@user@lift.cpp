#include "user/lift.hpp"

//TODO: make sure the ports are set correctly once
Motor liftR(0, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor liftL(1, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);

void liftInit()
{
  liftR.tare_position();
  liftL.tare_position();

  liftR.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  liftL.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}

int getAvgLiftPos()
{
  return (fabs(liftL.get_position()) + fabs(liftR.get_position()))/2;
}

void moveLiftPower(int power)
{
  liftR.move(power);
  liftL.move(power);
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
  int alignErr = 0;
  int lPower = 0;
  int rPower = 0;

  while(avgPos != pos)
  {
    avgPos = getAvgLiftPos();
    distErr = pos - avgPos;
    alignErr = fabs(liftL.get_position() - liftR.get_position());

    if(fabs(liftL.get_position()) > fabs(liftR.get_position()))
    {
      lPower = distErr - alignErr;
      rPower = distErr;
    }
    else if(fabs(liftR.get_position()) > fabs(liftL.get_position()))
    {
      rPower = distErr - alignErr;
      lPower = distErr;
    }

    liftL.move_velocity(lPower);
    liftR.move_velocity(rPower);
  }
}
