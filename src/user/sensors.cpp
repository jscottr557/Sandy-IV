#include "user/sensors.hpp"

ADIAnalogIn autonSel(1);

int getSelVal()
{
  return autonSel.get_value();
}
