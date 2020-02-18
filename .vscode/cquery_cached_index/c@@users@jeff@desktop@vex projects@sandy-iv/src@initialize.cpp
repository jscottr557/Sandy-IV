#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
  lcd::print(0, "AutonSel: %d", getSelVal());
  lcd::print(1, "TrayPos: %d", getLiftPos());
  lcd::print(2, "LiftPos: %d", getTrayPos());
  lcd::print(3, "RightDrivePos: %d", getAvgDriveSideTicks('r'));
  lcd::print(4, "LeftDrivePos: %d", getAvgDriveSideTicks('l'));
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize()
{
  lcd::print(0, "AutonSel: %d", getSelVal());
  lcd::print(1, "TrayPos: %d", getLiftPos());
  lcd::print(2, "LiftPos: %d", getTrayPos());
  lcd::print(3, "RightDrivePos: %d", getAvgDriveSideTicks('r'));
  lcd::print(4, "LeftDrivePos: %d", getAvgDriveSideTicks('l'));
}
