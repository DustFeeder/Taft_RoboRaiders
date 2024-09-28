#pragma config(Sensor, in1,    wheelEncoder,  sensorLineFollower)
#pragma config(Motor,  port2,  Ldrive,        tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port9,  Rdrive,        tmotorServoContinuousRotation, openLoop, driveRight)

int holeCount = 16;
float wheelDiameter = 8 + 5/16;
float IRSensor = 0;

#include "VG_Distance.h"

task main() {
	while(true) {
		arcadeControl(vexRT[Ch3], vexRT[Ch4], 10);
		float distanceTraveled = distCalc(distanceTraveled);
		IRSensor = wheelEncoder;
		if (vexRT[Btn5D]) {
			distDrive(120, 50);
		}
	}
}
