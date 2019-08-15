#include "api.h"

using namespace pros;

void drivetrainInit(std::string breakMode);

int getAvgDriveSideTicks(char side);

void setDriveSidePower(int power, char side);

void setDriveSideVel(int vel, char side);

void stopAll();

void controlDrivetrain(Controller controller);

void driveDistance(int inches, std::string direction);

void turnDegrees(std::string direction, int degrees);
