#include "main.h"
#include "functions.h"

/*
1800 ticks/rev with 36:1 gears
900 ticks/rev with 18:1 gears
300 ticks/rev with 6:1 gears
*/

//Geared down to 342 RPM (from 600)

class driveTrain{
    public:
    driveTrain() = default;

    driveTrain(double wheelD, double wheelDist){
        wheelDia = wheelD;
        wheelCirc = wheelDia * M_PI;
        robotCirc = wheelDist * M_PI;
        robotDia = wheelDist;
    }

    double wheelDia;
    double wheelCirc;
    double robotCirc;
    double robotDia;
    double gearR = 57/100; //driven/drive
    double ticksInRev = 300;

    double driveKP = 0;
    double driveKD = 0;
    double turningKP = 0;
    double turningKD = 0;

    //Converts distance (inches) into the AMOUNT OF ENCODER TICKS THE MOTOR NEEDS TO TURN
    double distToTicks(double dist){
        double ticks = dist;
        ticks /= wheelCirc;
        ticks /= gearR;
        ticks *= ticksInRev;
        return ticks;
    }

    //Function for turning in place (CLOCKWISE)
    double degToTicks(double degrees){
        //Arc length = radius * angle(radians)
        //1. Convert from degrees to radians
        double rad = degToRad(deg);
        //2. Use Arc Length formula to find the distance the wheels have to move;
        double dist = wheelDia/2 * rad;
        //3. Convert to ticks
        double ticks = distToTicks(dist);
        return ticks;
    }
};