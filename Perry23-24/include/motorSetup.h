#include "main.h"

pros::Controller master (pros::E_CONTROLLER_MASTER);

#define FR_MOTOR 9 //
#define MR_MOTOR 4 
#define BR_MOTOR 6
#define FL_MOTOR 17
#define ML_MOTOR 18
#define BL_MOTOR 19
#define INERTIAL 21

#define LEFT_INTAKE 20
#define RIGHT_INTAKE 10

#define FLYWHEEL 15

#define BACKROTATE 11
#define LEFTROTATE 12

pros::Motor FRight(FR_MOTOR, MOTOR_GEAR_BLUE, false);
pros::Motor MRight(MR_MOTOR, MOTOR_GEAR_BLUE, true);
pros::Motor BRight(BR_MOTOR, MOTOR_GEAR_BLUE, false); //stacked

pros::Motor FLeft(FL_MOTOR, MOTOR_GEAR_BLUE, true);
pros::Motor MLeft(ML_MOTOR, MOTOR_GEAR_BLUE,  false);
pros::Motor BLeft(BL_MOTOR, MOTOR_GEAR_BLUE, true); //stacked

pros::Motor Left_Intake(LEFT_INTAKE, MOTOR_GEAR_BLUE);
pros::Motor Right_Intake(RIGHT_INTAKE, MOTOR_GEAR_BLUE, true);
pros::Motor Flywheel(FLYWHEEL, MOTOR_GEAR_BLUE);

pros::Rotation backRotate(BACKROTATE); //pos is right
pros::Rotation leftRotate(LEFTROTATE); //neg is forward

pros::ADIDigitalOut endgame ('B'); //1 is out, 0 is inside
pros::ADIDigitalOut wings('A');
pros::ADIDigitalOut blockerblocker('C');

pros::IMU Inertial (INERTIAL);
 
double leftTrackDia = 2.75;
double rightTrackDia = 2.75;
double sideTrackDia = 2.75;