#include "user/tray.hpp"

/*README IF YOU WANT TO CHANGE THIS MOTOR
  TO REVERSE:
    Set the third value in the constructor call to its current opposite;
    if it is 1 now, change it to 0, if it is 0 now, change it to 1.

  TO CHANGE PORT:
    Change the first value in the constructor call to the motor's new port.

  You can also mouse over the constructor to gain additional information about
  each parameter if you desire.
*/
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
  lcd::print(2, "trayPos: %d", getTrayPos());
  int err = 0;
  while(getTrayPos() != pos)
  {
    err = (pos - getTrayPos());
    tray.move_velocity(err);
  }
  return;
}

void controlTray(Controller controller)
{
  if(controller.get_digital(E_CONTROLLER_DIGITAL_X) || controller.get_digital(E_CONTROLLER_DIGITAL_UP))
  {
    setTrayPower(-100);
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_B) || controller.get_digital(E_CONTROLLER_DIGITAL_DOWN))
  {
    setTrayPower(100);
  }
  else
  {
    setTrayPower(0);
  }
  return;
}

void controlTray(bool btnUp, bool btnDown)
{
  if(btnUp)
  {
    setTrayPower(-100);
  }
  else if(btnDown)
  {
    setTrayPower(100);
  }
  else
  {
    setTrayPower(0);
  }
  return;
}
