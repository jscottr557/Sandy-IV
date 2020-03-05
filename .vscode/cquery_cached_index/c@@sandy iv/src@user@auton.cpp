#include "user/auton.hpp"
#include "main.h"

void autonRed5()
{
  setIntake("in");
  driveInchesVel(43 , 50, "forward");
  setIntake("off");
  delay(500);
  driveInchesVel(23, 70, "backward");
  turnDegrees(133, "right");
  setIntake("out");
  delay(250);
  setIntake("off");
  delay(500);
  driveInches(14, "forward");
  moveTrayTo(2900);
  setIntake("out");
  delay(1000);
  moveTrayTo(0);
  driveInchesVel(12, 20, "backward");
  setIntake("stop");
}

void autonRed5Prot()
{
  setIntake("in");
  driveInchesVel(21, 60, "forward");
  delay(750);
  turnDegrees(90, "right");
  driveInchesVel(9, 80, "forward");
  delay(200);
  driveInchesVel(7, 80, "backward");
  delay(200);
  turnDegrees(176, "left");
  delay(100);
  driveInches(16, "forward");
  turnDegrees(45, "left");
}

void autonRed3()
{
  setIntake("in");
  driveInchesVel(22, 60, "forward");
  delay(100);
  turnDegrees(92, "left");
  driveInchesVel(24, 60, "forward");
  setIntake("off");
  delay(100);
  turnDegrees(50, "left");
  setIntake("out");
  delay(225);
  setIntake("off");
  driveInchesVel(6, 60, "forward");
  moveTrayTo(2900);
  setIntake("out");
  moveTrayTo(1900);
  driveInchesVel(12, 20, "backward");
  setIntake("off");
}

void autonBlue5()
{
  setIntake("in");
  driveInchesVel(43 , 50, "forward");
  setIntake("off");
  delay(500);
  driveInchesVel(23, 70, "backward");
  turnDegrees(133, "right");
  setIntake("out");
  delay(250);
  setIntake("off");
  delay(500);
  driveInches(14, "forward");
  moveTrayTo(2900);
  setIntake("out");
  delay(1000);
  moveTrayTo(0);
  driveInchesVel(12, 20, "backward");
  setIntake("stop");
}

void autonBlue3()
{
  setIntake("in");
  driveInchesVel(22, 60, "forward");
  delay(100);
  turnDegrees(92, "right");
  driveInchesVel(24, 60, "forward");
  setIntake("off");
  delay(100);
  turnDegrees(50, "right");
  setIntake("out");
  delay(225);
  setIntake("off");
  driveInchesVel(6, 60, "forward");
  moveTrayTo(2900);
  setIntake("out");
  moveTrayTo(1900);
  driveInchesVel(12, 20, "backward");
  setIntake("off");
}

void autonBump()
{
  driveInches(15, "forward");
  delay(200);
  setIntake("out");
  delay(700);
  driveInches(30, "backward");
}

void decideAuton(int autonSel)
{
  if(autonSel >= 0 && autonSel < 1000)
  {
    autonRed5();
  }
  else if(autonSel >= 1000 && autonSel < 2000)
  {
    autonRed3();
  }
  else if(autonSel >= 2000 && autonSel < 3000)
  {
    autonBlue5();
  }
  else if(autonSel >= 3000 && autonSel < 4095)
  {
    autonBlue3();
  }
  else if(autonSel == 4095)
  {
    autonBump();
  }
  return;
}
