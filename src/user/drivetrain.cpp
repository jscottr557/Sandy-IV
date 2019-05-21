#include "user/drivetrain.hpp"

Motor FR(19, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor FL(15, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
Motor BR(17, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor BL(14, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);

void drivetrainInit(std::string breakMode)
{
  if(breakMode == "free")
  {
    FR.set_brake_mode(E_MOTOR_BRAKE_COAST);
    FL.set_brake_mode(E_MOTOR_BRAKE_COAST);
    BR.set_brake_mode(E_MOTOR_BRAKE_COAST);
    BL.set_brake_mode(E_MOTOR_BRAKE_COAST);
  }
  if(breakMode == "brake")
  {
    FR.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    FL.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    BR.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    BL.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  }
  FR.tare_position();
  FL.tare_position();
  BR.tare_position();
  BL.tare_position();
}

int getAvgSideTicks(char side)
{
  int avg = 0;
  if(side == 'l')
  {
    avg = (FL.get_position() + BL.get_position())/2;
  }
  else if(side == 'r')
  {
    avg = (FR.get_position() + BR.get_position())/2;
  }
  return avg;
}

void setPower(int power, char side)
{
  if(side == 'r')
  {
    FR.move(power);
    BR.move(power);
  }
  else if(side == 'l')
  {
    FL.move(power);
    BL.move(power);
  }
}

void setVel(int vel, char side)
{
  if(side == 'r')
  {
    FR.move_velocity(vel);
    BR.move_velocity(vel);
  }
  else if(side == 'l')
  {
    FL.move_velocity(vel);
    BL.move_velocity(vel);
  }
}

void stopAll()
{
  FR.move_velocity(0);
  FL.move_velocity(0);
  BR.move_velocity(0);
  BL.move_velocity(0);
}

void driveDrivetrain(Controller controller)
{
  int lPower = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) + controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
  int rPower = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) - controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
  if(abs(controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) < 0 && abs(controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X)) < 0)
  {
    stopAll();
  }
  else
  {
    setPower(lPower, 'l');
    setPower(rPower, 'r');
  }
}

void driveDistance(int inches, std::string direction)
{
  drivetrainInit("brake");
  int ticks = (inches/ 1/*wheelDiam*/) * 360;
  int lAvgTicks = 0;
  int rAvgTicks = 0;
  int avgTicks = 0;
  int currentPower = 0;
  int lPower = 0;
  int rPower = 0;
  int distErr = 0;
  int alignErr = 0;
  float distKp = 0;
  float alignKp = 0;
  const int SLEW = 0;
  while(avgTicks < ticks)
  {
    lAvgTicks = getAvgSideTicks('l');
    rAvgTicks = getAvgSideTicks('r');
    avgTicks = (getAvgSideTicks('l') + getAvgSideTicks('r'))/2;

    //Make sure we dont accelerate/decelerate too fast with slew
    if(((ticks - avgTicks) * distKp) > SLEW)
    {
      distErr = SLEW;
    }
    else
    {
      distErr = (ticks - avgTicks) * distKp;
    }

    //Decide wether to accelerate or decelerate
    if(currentPower > (ticks - avgTicks))
    {
      distErr = distErr * -1;
    }

    //Decide which side is too far ahead, apply acceleration curve
    alignErr = abs((lAvgTicks - rAvgTicks)) * alignKp;
    if(lAvgTicks > rAvgTicks)
    {
      lPower = (currentPower + distErr) - alignErr;
      rPower = currentPower + distErr;
    }
    else if(rAvgTicks > lAvgTicks)
    {
      rPower = (currentPower + distErr) - alignErr;
      lPower = currentPower + distErr;
    }

    //Send velocity targets to both sides of the drivetrain
    setVel(lPower, 'l');
    setVel(rPower, 'r');

    //Set current power for next cycle, make sure it doesn't get too high/low
    currentPower = currentPower + distErr;
    if(currentPower > 200)
    {
      currentPower = 200;
    }
    else if(currentPower < 0)
    {
      currentPower = 0;
    }
  }
  stopAll();
}
