#include "api.h"

/*The set of commands for the 5 cube auton on the red side.

  Rough desription of this auton:
    Picks up the four cubes layed out in a straight line near the unprotected
    zone + the preload, and stacks them in the unprotected zone.

  Starting position:
    Robot should start facing the four cubes layed out in a row, with the back
    of the robot touching the field wall.
*/
void autonRed5();


/*The set of commands for the 3 cube auton on the red side.

  Rough description of this auton:
    Picks up the two cubes nearest the protected zone + the preload, and stacks
    them in the protected zone.

  Starting position:
    Robot should start partially on the red field tile, facing the cube touching
    the upper right corner of the red tile, with the back of the robot touching
    the field wall.
*/
void autonRed3();


/*The set of commands for the 5 cube auton on the blue side.

  Rough desription of this auton:
    Picks up the four cubes layed out in a straight line near the unprotected
    zone + the preload, and stacks them in the unprotected zone.

  Starting position:
    Robot should start facing the four cubes layed out in a row, with the back
    of the robot touching the field wall.
*/
void autonBlue5();


/*The set of commands for the 3 cube auton on the red side.

  Rough description of this auton:
    Picks up the two cubes nearest the protected zone + the preload, and stacks
    them in the protected zone.

  Starting position:
    Robot should start partially on the blue field tile, facing the cube
    touching the upper right corner of the blue tile, with the back of the robot
    touching the field wall.
*/
void autonBlue3();


/*The set of commands for the "bump" auton.

  Rough description of this auton:
    Sideless auton(side doesn't matter), drives to a scoring zone, outtakes
    a cube into that scoring zone, and backs away.

  Starting position:
    Robot should start parallel to field wall with the front facing towards the
    zone you want to score in, with the center of the preload being about 15 in.
    away from the center of the scoring zone. The preload can start either in or
    out of robot.
*/
void autonBump();


/*The set of commands for a programming skills run.

  Rough description of this auton:
    TBD

  Starting position:
    TBD
*/
void autonSkills();


/*Decides which automous to run based on potentiometer input.

  \param autonSel
    (generally) The return value of the potentiometer.
    Valid arguments:
      From 0 - 4095(inclusive)
*/
void decideAuton(int autonSel);
