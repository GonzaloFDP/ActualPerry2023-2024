#include "main.h"
#include "odom.hpp"

//Mathematics

double degToRad(int deg){
    double rad = deg * M_PI /180;
    return rad;
}

//Variables
int intakeSpeed = 0;
int intakeDirection = 1; //Pos = 

//Movement


void driveFunc(int power, int turn){
    double left;
    double right;

    //Plugging this into a cubed function (600x^3)/(127^3)
    double cubed = 600*power*power*power;
    cubed /= (127*127*127);

    left = cubed + turn;
    right = cubed - turn;
    FLeft.move_velocity(left);
    MLeft.move_velocity(left);
    BLeft.move_velocity(left);
    FRight.move_velocity(right);
    MRight.move_velocity(right);
    BRight.move_velocity(right);
}

void tareDriveMotors(){
    FLeft.tare_position();
    MLeft.tare_position();
    BLeft.tare_position();
    FRight.tare_position();
    MRight.tare_position();
    BRight.tare_position();
}

void pidLoop (double target, double Kp, double Ki, double Kd){
    double threshold;
    double integral = 0;
    double output;
    double prevError = 0;
    tareDriveMotors();
    while (true){
            double leftSideMotors = (FLeft.get_position() + MLeft.get_position() + BLeft.get_position())/3;
            double rightSideMotors = (FRight.get_position() + MRight.get_position() + BRight.get_position())/3;
            double avgMotors = (leftSideMotors+rightSideMotors)/2;

            double error = target - avgMotors;

            integral += error;

            if(fabs(error) > threshold){
                integral = 0;
            }

            output = error * Kp + integral * Ki + (error-prevError) * Kd;

            FLeft.move_velocity(output);
            MLeft.move_velocity(output);
            BLeft.move_velocity(output);
            FRight.move_velocity(output);
            MRight.move_velocity(output);
            BRight.move_velocity(output);

            prevError = error;

            pros::delay(10);
    }
}

/*ADVANCED PROGRAMMING*/

void drivePID(double targetInches, double Kp, double Ki, double Kd){
    pros::Motor leftDrive(1,MOTOR_GEAR_GREEN);
    pros::Motor rightDrive(2,MOTOR_GEAR_GREEN,true);
    pros::Rotation rotation(4);
    rotation.reset();
    double wheelDia = 2.75;
    double error = targetInches;
    double integral=0;
    double prevError = error;

    tareDriveMotors();
    
    while(true){
        double measuredInches = (2.75 * 3.14 * rotation.get_position())/36000;
        error = targetInches - measuredInches;

        if(fabs(error) > 5){
            integral = 0;
        }
        
        leftDrive.move_velocity(error*Kp + integral*Ki + (error-prevError)*Kd);
        rightDrive.move_velocity(error*Kp + integral*Ki + (error-prevError)*Kd);

        prevError = error;

        pros::delay(10);
    }
}

void turnPid (double targetDegrees, double Kp, double Ki, double Kd){
    pros::Motor leftDrive(1,MOTOR_GEAR_GREEN);
    pros::Motor rightDrive(2,MOTOR_GEAR_GREEN,true);
    pros::IMU inertial (3);
    inertial.set_rotation(0);
    double error = targetDegrees - inertial.get_rotation();
    double prevError = error;
    double integral=0;
    while(fabs(error>1)){
        error = targetDegrees - inertial.get_rotation();
        integral += error;
    
        if(fabs(error) > 300){
            integral = 0;
        }

        output = error * Kp + integral * Ki + (error-prevError) * Kd;

        leftDrive.move_velocity(output);
        rightDrive.move_velocity(-1*output);

        prevError = error;
        pros::delay(10);
    }
}

void turnPidHeading (double targetHeading, double Kp, double Ki, double Kd){
    pros::Motor leftDrive(1,MOTOR_GEAR_GREEN);
    pros::Motor rightDrive(2,MOTOR_GEAR_GREEN,true);
    pros::IMU inertial (3);
    inertial.set_rotation(0);
    double error = targetHeading - inertial.get_heading();
    double prevError = error;
    double integral=0;
    tareDriveMotors();
    while(fabs(error>1)){
        error = targetHeading - inertial.get_heading();
        integral += error;
    
        if(fabs(integral) > 300){
            integral = (integral/fabs(integral))*300;
        }

        output = error * Kp + integral * Ki + (error-prevError) * Kd;

        leftDrive.move_velocity(output);
        rightDrive.move_velocity(-1*output);

        prevError = error;
        pros::delay(10);
    }
}

//Multitasking
int targetVelocity = 0;
void accelerateMotor(){
    int motorVel = 0;
    pros::Motor motor(1);
    while(true){
        if(motorVel < targetVelocity){
            motorVel+=fmin(5, targetVelocity-motorVel);
        } else if (motorVel >= targetVelocity){
            motorVel-=fmin(5,motorvel-targetVelocity);
        }
        motor.move_veloctity(motorVel);
        pros::delay(10);
    }
}

pros::Task accelerateMotorTask(accelerateMotor);

pros::Motor flywheel(20);
int flywheelTarget;
void flywheelPID(){
    int Kp =15;
    int Ki=3;
    int Kd=5;
    double error = flywheelTarget - flywheel.get_actual_velocity();
    double integral = 0;
    double prevError = error;
    while(true){
        error = flywheelTarget - flywheel.get_actual_velocity();
        integral += error;
        if(fabs(error)>100){
            integral = 0;
        }
        double output = error * Kp + integral * Ki + (error-prevError)*Kd;
        flywheel.move_voltage(output);
        prevError = error;
        pros::delay(10);
    }
}
pros::Task flywheelPidTask(flywheelPID);