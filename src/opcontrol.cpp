#include "main.h"

using namespace pros;

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
	//Initilize the subsystems
	initDrivetrain("coast");
	initLift();
	initTray();
	initIntake();

	//Initilize the LCD emulator
	lcd::initialize();

	//Initilize the controller
	Controller controller(E_CONTROLLER_MASTER);

	while(1)
	{
		//lcd::print(1, "Lift pos: %d", getLiftPos());
		lcd::print(1, "AutonSel: %d", getSelVal());
		controlDrivetrain(controller);
		controlLift(controller);
		controlIntake(controller);
		controlTray(controller);
		delay(20);
		if(controller.get_digital(DIGITAL_Y) && controller.get_digital(DIGITAL_A) && controller.get_digital(DIGITAL_LEFT) && controller.get_digital(DIGITAL_RIGHT))
		{
			decideAuton(getSelVal());//driveInches(24, "forward");
		}
	}
}
