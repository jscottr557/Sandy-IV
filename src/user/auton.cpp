#include "user/auton.hpp"
#include "main.h"

void autonRed()
{
  //strafeInches(3, 'r');
  driveInches(24, "forward");
  //setIntake("out");
  delay(200);
  setIntake("off");
  driveInches(40, "backward");
}

void autonBlue()
{
  //strafeInches(3, 'l');
  driveInches(24, "forward");
  //setIntake("out");
  delay(200);
  setIntake("off");
  driveInches(40, "backward");
}

void decideAuton(int autonSel)
{
  if(autonSel >= 0 && autonSel < 1000)
  {
    autonRed();
  }
  else if(autonSel >= 1000 && autonSel < 2000)
  {
    autonBlue();
  }
  else if(autonSel >= 2000 && autonSel < 3000)
  {
    autonRed();
  }
  else if(autonSel >= 3000 && autonSel <= 4095)
  {
    autonBlue();
  }
  return;
}
