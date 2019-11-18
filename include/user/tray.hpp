#include "api.h"

using namespace pros;

//Clear the encoder on the tray motor, set it to hold position
void initTray();

//Get the degree position of the tray motor encoder
int getTrayPos();

//Set the arbitrary "power" of the tray motor
//Args for power are -127 to 127
void setTrayPower(int power);

//Move the tray to a specific degree position
void moveTrayTo(int pos);

//Let the user control the tray in driver control
void controlTray(Controller controller);
