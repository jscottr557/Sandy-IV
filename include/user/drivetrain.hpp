#include "api.h"

using namespace pros;

void drivetrainInit(std::string breakMode);

int getAvgSideTicks(char side);

void setPower(int power, char side);

void setVel(int vel, char side);

void stopAll();

void driveDrivetrain(Controller controller);

void driveDistance(int inches, std::string direction);

void turnDegrees(std::string direction, int degrees);
