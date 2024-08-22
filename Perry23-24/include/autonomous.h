#include "main.h"
#include "driveTrain.h"
#include "pros/rtos.hpp"
driveTrain perry(4,13.5);
//Over side
/*void OverPreload(){
    flywheelSpeed = 600;
    turnPID(perry.degToTicks(45),perry.turnKP,perry.turnKI,perry.turnKD);
    stopDriveMotors();
    intakeDirection=1;
    intakeSpeed = 500;
    pros::delay(1000);
    flywheelSpeed=0;
    intakeSpeed=0;
}
void testAuton(){
    autonTurning(180,2.8,0.0003,0.55);
}
void OverAWP(){
    turnPID(perry.degToTicks(-53),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(300);
    stopDriveMotors();
    drivePID(perry.distToTicks(25),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
    stopDriveMotors();
    turnPID(perry.degToTicks(46),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    stopDriveMotors();
    drivePID(perry.distToTicks(5),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(100);
    stopDriveMotors();
    intakeDirection=1;
    intakeSpeed=500;
    pros::delay(500);
    intakeSpeed = 0;
    drivePID(perry.distToTicks(-4),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(200);
    stopDriveMotors();
    turnPID(perry.degToTicks(-220),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(400);
    stopDriveMotors();
    driveMotors(perry.distToTicks(-13),200);
    pros::delay(500);
    stopDriveMotors();
    drivePID(perry.distToTicks(5),perry.driveKP,perry.driveKI,perry.driveKD);
    tareDriveMotors();
    pros::delay(300);
    stopDriveMotors();
    turnPID(perry.degToTicks(-70),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(300);
    stopDriveMotors();
    drivePID(perry.distToTicks(6),perry.driveKP,perry.driveKI,perry.driveKD);
    stopDriveMotors();
}

//Under side
void UnderPreload(){
    intakeDirection=-1;
    intakeSpeed = 500;
    pros::delay(2000);
    intakeSpeed=0;
}

void UnderAWP(){
    pros::delay(100);
    turnPID(perry.degToTicks(50),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(500);
    stopDriveMotors();
    drivePID(perry.distToTicks(27),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
    stopDriveMotors();
    turnPID(perry.degToTicks(-50),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(400);
    stopDriveMotors();
    drivePID(perry.distToTicks(3),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
    intakeDirection=1;
    intakeSpeed=500;
    pros::delay(500);
    stopDriveMotors();
    intakeSpeed = 0;
    drivePID(perry.distToTicks(3),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(100);
    stopDriveMotors();
    drivePID(perry.distToTicks(-10),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(200);
    turnPID(perry.degToTicks(220),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(400);
    stopDriveMotors();
    driveMotors(perry.distToTicks(-12),1100);
    pros::delay(200);
    stopDriveMotors();
    drivePID(perry.distToTicks(5),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(200);
    stopDriveMotors();
    turnPID(perry.degToTicks(50),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(200);
    stopDriveMotors();
    drivePID(perry.distToTicks(34),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
}

void UnderAWP5Points(){
    drivePID(perry.distToTicks(70), perry.driveKP, perry.driveKI,perry.driveKD);
    pros::delay(300);
    turnPID(perry.degToTicks(90),perry.turnKP, perry.turnKI,perry.turnKD);
    pros::delay(300);
    intakeDirection=-1;
    intakeSpeed = 500;
    pros::delay(400);
    intakeSpeed = 0;
    driveMotors(perry.distToTicks(5),800);
    pros::delay(400);
    drivePID(perry.distToTicks(-6), perry.driveKP, perry.driveKI, perry.driveKD);
    turnPID(perry.degToTicks(180),perry.turnKP, perry.turnKI,perry.turnKD);
    intakeDirection=1;
    intakeSpeed = 500;
    drivePID(perry.distToTicks(15),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(800);
    intakeSpeed=0;
    turnPID(perry.degToTicks(-180),perry.turnKP, perry.turnKI,perry.turnKD);
    drivePID(perry.distToTicks(10),perry.driveKP, perry.driveKI, perry.driveKD);
    intakeDirection=1;
    intakeSpeed = 500;
    pros::delay(400);
    intakeSpeed=0;
    driveMotors(perry.distToTicks(5),800);
    pros::delay(400);
    turnPID(perry.degToTicks(-45),perry.turnKP, perry.turnKI,perry.turnKD);
    pros::delay(400);
    drivePID(perry.distToTicks(-55),perry.driveKP, perry.driveKI, perry.driveKD);
}*/

void OverAWP(){
    //==========================================
    double totalDirection = 47;
    drivePID(perry.distToTicks(-7),perry.driveKP, perry.driveKI, perry.driveKD);
    wings.set_value(1);
    pros::delay(200);
    autonTurning(0-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    wings.set_value(0);
    pros::delay(600);
    autonTurning(30-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    drivePID(perry.distToTicks(15),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(0-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    intakeDirection=-1;
    intakeSpeed=500;
    totalDirection += Inertial.get_rotation();
    pros::delay(300);
    wings.set_value(0);
    drivePID(perry.distToTicks(28),perry.driveKP, perry.driveKI, perry.driveKD);
    stopDriveMotors();
    pros::delay(1500);
    intakeSpeed=0;
    intakeDirection=1;
    //==========================================
}

void OverAWP5Points(){
    /*drivePID(perry.distToTicks(17),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(45,3,perry.turnKI,perry.turnKD);
    pros::delay(100);
    drivePID(perry.distToTicks(5),perry.driveKP, perry.driveKI, perry.driveKD);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(100);
    driveMotors(perry.distToTicks(10),1300);
    drivePID(perry.distToTicks(-9),perry.driveKP, perry.driveKI, perry.driveKD);
    intakeSpeed=0;
    autonTurning(-30,3,perry.turnKI,perry.turnKD);
    endgame.set_value(1);
    drivePID(perry.distToTicks(-16),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(-30,3,perry.turnKI,perry.turnKD);
    endgame.set_value(0);*/
    driveMotors(-perry.distToTicks(31),1300);
    drivePID(perry.distToTicks(21),perry.driveKP, perry.driveKI, perry.driveKD);
    /*autonTurning(-177,3,perry.turnKI,perry.turnKD);
    endgame.set_value(1);
    pros::delay(100);
    drivePID(perry.distToTicks(-22),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-45,3,perry.turnKI,perry.turnKD);
    pros::delay(100);
    drivePID(perry.distToTicks(10),perry.driveKP, perry.driveKI, perry.driveKD);
    endgame.set_value(0);*/
}
void testAuton(){
    drivePID(perry.distToTicks(24),perry.driveKP, perry.driveKI, perry.driveKD);
}

void UnderAWP(){
    driveMotors(-perry.distToTicks(33),1300);
    drivePID(perry.distToTicks(14),perry.driveKP, perry.driveKI, perry.driveKD);
}

void UnderAWP5Points(){
    /*drivePID(perry.distToTicks(40),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(50);
    autonTurning(90,perry.turnKP,perry.turnKI,perry.turnKD);
    //pros::delay(100);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(300);
    driveMotors(perry.distToTicks(16),600);
    pros::delay(100);
    intakeSpeed=0;
    pros::delay(100);
    drivePID(perry.distToTicks(-20),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(140,perry.turnKP,perry.turnKI,perry.turnKD);
    intakeDirection=1;
    intakeSpeed=500;
    pros::delay(100);
    drivePID(perry.distToTicks(24),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    intakeSpeed=0;
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(185,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    drivePID(perry.distToTicks(10),perry.driveKP, perry.driveKI, perry.driveKD);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(300);
    driveMotors(perry.distToTicks(14),1000);
    pros::delay(200);
    intakeSpeed=0;
    pros::delay(100);  
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-135,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    intakeDirection=1;
    intakeSpeed=500;
    drivePID(perry.distToTicks(24),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    intakeSpeed=0;
    drivePID(perry.distToTicks(-5),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(180,perry.turnKP,perry.turnKI,perry.turnKD);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(300);
    driveMotors(perry.distToTicks(26),150
    intakeSpeed=0;
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);*/
    double totalDirection = -45;
    drivePID(perry.distToTicks(16),perry.driveKP, perry.driveKI, perry.driveKD);
    totalDirection += Inertial.get_rotation();
    autonTurning(-86-(totalDirection),perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    intakeDirection=-1;
    intakeSpeed=500;
    wings.set_value(0);
    pros::delay(150);
    driveMotors(perry.distToTicks(25),800);
    intakeSpeed=0;
    drivePID(perry.distToTicks(-30),perry.driveKP, perry.driveKI, perry.driveKD);
    totalDirection += Inertial.get_rotation();
    autonTurning(-136-(totalDirection),perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    intakeDirection=1;
    intakeSpeed=500;
    drivePID(perry.distToTicks(62),perry.driveKP, perry.driveKI, perry.driveKD);
    totalDirection += Inertial.get_rotation();
    intakeSpeed=0;
    pros::delay(100);
    autonTurning(10-(totalDirection),perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    intakeDirection=-1;
    intakeSpeed=500;
    wings.set_value(1);
    pros::delay(150);
    driveMotors(perry.distToTicks(48),1200);
    wings.set_value(0);
    intakeSpeed=0;
    drivePID(perry.distToTicks(-25),perry.driveKP, perry.driveKI, perry.driveKD);
    totalDirection += Inertial.get_rotation();
    autonTurning(135-(totalDirection),perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    intakeDirection=1;
    intakeSpeed=300;
    drivePID(perry.distToTicks(20),perry.driveKP, perry.driveKI, perry.driveKD);
    totalDirection += Inertial.get_rotation();
    intakeSpeed=0;
    driveMotors(perry.distToTicks(-15),1300);
    autonTurning(0-(totalDirection),perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    wings.set_value(1);
    intakeDirection=-1;
    intakeSpeed=500;
    driveMotors(perry.distToTicks(21),1500);
    totalDirection += Inertial.get_rotation();
    intakeSpeed=0;
    wings.set_value(0);
    drivePID(perry.distToTicks(-14),perry.driveKP, perry.driveKI, perry.driveKD);
    totalDirection += Inertial.get_rotation();
}



void progSkills(){
    double totalDirection = -50;
    drivePID(perry.distToTicks(4),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(11,perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    drivePID(perry.distToTicks(-3),perry.driveKP, perry.driveKI, perry.driveKD);
    holdMotors();
    flywheelSpeed = 600;
    pros::delay(1000);
    for(int i = 0; i < 24; i++){
        FLeft.move_velocity(0);
        MLeft.move_velocity(0);
        BLeft.move_velocity(0);
        FRight.move_velocity(0);
        MRight.move_velocity(0);
        BRight.move_velocity(0);
        pros::delay(1000);
    }
    flywheelSpeed = 0;
    coastMotors();
    drivePID(perry.distToTicks(4),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-135-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    drivePID(perry.distToTicks(-8.5),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-195-(totalDirection),perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    drivePID(perry.distToTicks(-76),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(135-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation(); 
    drivePID(perry.distToTicks(-22),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(90-totalDirection, perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    driveMotors(perry.distToTicks(-21),1000);
    driveMotors(perry.distToTicks(10),1000);
    driveMotors(perry.distToTicks(-14),1000);
    drivePID(perry.distToTicks(3),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(135-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    drivePID(perry.distToTicks(12),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-155-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    drivePID(perry.distToTicks(42),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-30-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    intakeDirection=-1;
    intakeSpeed = 500;
    wings.set_value(1);
    pros::delay(500);
    driveMotors(perry.distToTicks(25),1500);
    driveMotors(perry.distToTicks(-10),1000);
    driveMotors(perry.distToTicks(13),1000);
    wings.set_value(0);
    intakeSpeed = 0;
    drivePID(perry.distToTicks(-20),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-90-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    drivePID(perry.distToTicks(48),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(35-(totalDirection), perry.turnKP,perry.turnKI,perry.turnKD);
    totalDirection += Inertial.get_rotation();
    intakeDirection=-1;
    intakeSpeed = 500;
    wings.set_value(1);
    pros::delay(500);
    driveMotors(perry.distToTicks(25),1500);
    driveMotors(perry.distToTicks(-15),1000);
    driveMotors(perry.distToTicks(18),1000);
    wings.set_value(0);
    intakeSpeed = 0;
    driveMotors(perry.distToTicks(-20),1000);

    /*
    [======]-[=====]-[====]-[===]-[==]-[=] Over Pipe [=]-[==]-[===]-[====]-[=====]-[======]

    autonTurning(-9,perry.turnKP,perry.turnKI,perry.turnKD);
    drivePID(perry.distToTicks(52),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning((45-Inertial.get_rotation()),perry.turnKP,perry.turnKI,perry.turnKD);
    driveMotors(perry.distToTicks(-30),1500);
    intakeDirection=-1;
    intakeSpeed = 500;
    wings.set_value(1);
    pros::delay(500);
    driveMotors(perry.distToTicks(84),4500);
    autonTurning((45-Inertial.get_rotation()),perry.turnKP,perry.turnKI,perry.turnKD);
    driveMotors(perry.distToTicks(54),1500);
    driveMotors(perry.distToTicks(-10),700);
    autonTurning((45-Inertial.get_rotation()),perry.turnKP,perry.turnKI,perry.turnKD);
    driveMotors(perry.distToTicks(15),700);
    wings.set_value(0);
    intakeSpeed = 0;
    driveMotors(perry.distToTicks(-15),1000);*/
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