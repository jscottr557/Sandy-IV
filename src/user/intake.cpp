#include "user/intake.hpp"

Motor intakeL(8, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
Motor intakeR(9, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);

void initIntake()
{
  intakeL.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  intakeR.set_brake_mode(E_MOTOR_BRAKE_BRAKE);

  intakeL.tare_position();
  intakeR.tare_position();
}

void setIntake(std::string state)
{
  if(state == "in")
  {
    intakeL.move(127);
    intakeR.move(127);
  }
  else if(state == "out")
  {
    intakeL.move(-127);
    intakeR.move(-127);
  }
  else if(state == "off")
  {
    intakeL.move(0);
    intakeR.move(0);
  }
}

void controlIntake(Controller controller)
{
  if(controller.get_digital(E_CONTROLLER_DIGITAL_L1))
  {
    setIntake("in");
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_L2))
  {
    setIntake("out");
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_L1) == 0)
  {
    setIntake("off");
  }
  else if(controller.get_digital(E_CONTROLLER_DIGITAL_L2) == 0)
  {
    setIntake("off");
  }
}
