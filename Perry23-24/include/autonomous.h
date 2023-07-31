#include "main.h"
#include "driveTrain.h"

void auton1(){

}

void auton2(){

}

void progSkills(){

}


/*ADVANCED PROG*/
pros::Motor lift(1);
pros::Rotation liftRotation(2);
void moveLift(double targetDegrees){
    lift.set_brake_mode(MOTOR_BRAKE_HOLD);
    double degrees = liftRotation.get_position()/36000 * 360;
    
    if(targetDegrees >= degrees){
        while(targetDegrees >= degrees){
            lift.move_velocity(80);
        }
    }
    if(targetDegrees<degrees){
        while(targetDegrees < degrees){
            lift.move_velocity(-25);
        }
    }
    pros::delay(10);
    
    lift.brake();
}