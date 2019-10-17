#include "api.h"

using namespace pros;

//CLear the encoder on the tray motor, set it to hold position
void initTray();

//Get the position of the tray motor encoder
int getTrayPos();

//Set the arbitrary "power" of the tray motor
//Args for power are -127 to 127
void setTrayPower(int power);

//Move the tray to a specific tick position
void moveTrayTo(int pos);

//Let the user control the tray in driver control
void controlTray(Controller controller);
