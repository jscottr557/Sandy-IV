#include "user/auton.hpp"

void autonRed()
{

  return;
}

void autonBlue()
{

  return;
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
    ;
  }
  else if(autonSel >= 3000 && autonSel <= 4095)
  {
    ;
  }
  return;
}
