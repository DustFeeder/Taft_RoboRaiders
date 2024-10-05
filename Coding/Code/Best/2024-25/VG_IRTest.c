#pragma config(Sensor, in1,    wheelEncoder,  sensorLineFollower)
#pragma config(Motor,  port2,  Ldrive,        tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port9,  Rdrive,        tmotorServoContinuousRotation, openLoop, driveRight)

int holeCount = 16;
float wheelDiameter = 6 + 7/8;

float distanceTraveled = 0;
float IRSensor = 0;

#include "VG_Distance.h"

task main() {
	while(true) {
		arcadeControl(vexRT[Ch3], vexRT[Ch4], 10);
		distanceTraveled = distCalc(distanceTraveled);
		IRSensor = wheelEncoder;
		distDrive(vexRT[Bnt5D], 120, 50);
		
	}
}
