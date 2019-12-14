#include "tray.hpp"

Motor tray(3, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);

void initTray()
{
  tray.set_brake_mode(E_MOTOR_BRAKE_HOLD);

  tray.tare_position();
  return;
}

int getTrayPos()
{
  return tray.get_position();
}

void setTrayPower(int power)
{
  tray.move(power);
  return;
}

void moveTrayTo(int pos)
{
  int err = 0;
  while(getTrayPos() != pos)
  {
    err = pos - getTrayPos();
    tray.move_velocity(err);
  }
  return;
}

void controlTray(Controller controller)
{
  if(controller.get_digital(E_CONTROLLER_DIGITAL_X))
  {
    setTrayPower(-100);
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_B))
  {
    setTrayPower(100);
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_X) == 0)
  {
    setTrayPower(0);
  }
  else if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B) == 0)
  {
    setTrayPower(0);
  }
  return;
}
