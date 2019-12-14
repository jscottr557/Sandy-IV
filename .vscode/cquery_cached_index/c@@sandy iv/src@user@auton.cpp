#include "user/auton.hpp"
#include "main.h"

void autonRed()
{
  driveInches(24, "forward");
  //setIntake("out");
  delay(200);
  setIntake("out");
  delay(500);
  driveInches(30, "backward");
}

void autonBlue()
{
  driveInches(24, "forward");
  //setIntake("out");
  delay(200);
  setIntake("out");
  delay(500);
  driveInches(30, "backward");

  /*Experimental
    setIntake("in");
    driveInches(36, "forward");
    delay(200);
    driveInches(25, "backward");
    delay(200);
    driveInches(4, "forward");
    turnDegrees(90, "right");
    delay(200);
    driveInches(24, "forward");
    moveTrayTo(-45);
    driveInches(1);
    delay(200);
    driveInches(20, "backward");
  */

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
