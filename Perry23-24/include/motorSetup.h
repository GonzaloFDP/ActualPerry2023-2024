#include "main.h"

pros::Controller master (pros::E_CONTROLLER_MASTER);

#define FR_MOTOR 1
#define MR_MOTOR 2
#define BR_MOTOR 3
#define FL_MOTOR 4
#define ML_MOTOR 5
#define BL_MOTOR 6

#define INTAKE 7
#define SLAPPER 8
#define CLIMBER 9

pros::Motor FRight(FR_MOTOR,E_MOTOR_GEAR_BLUE, true);
pros::Motor MRight(MR_MOTOR,E_MOTOR_GEAR_BLUE, true);
pros::Motor BRight(BR_MOTOR,E_MOTOR_GEAR_BLUE, true);

pros::Motor FLeft(FL_MOTOR,E_MOTOR_GEAR_BLUE, false);
pros::Motor MLeft(ML_MOTOR,E_MOTOR_GEAR_BLUE, false);
pros::Motor BLeft(BL_MOTOR,E_MOTOR_GEAR_BLUE, false);

pros::Motor Intake(INTAKE);
 
double leftTrackDia = 2.75;
double rightTrackDia = 2.75;
double sideTrackDia = 2.75;