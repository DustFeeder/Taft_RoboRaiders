#pragma config(Sensor, in1,    centerIR,       sensorLineFollower)
#pragma config(Sensor, in2,    rightIR,        sensorLineFollower)
#pragma config(Sensor, in3,    leftIR,         sensorLineFollower)
#pragma config(Sensor, dgtl1,  LimitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  LimitSwitch2,   sensorTouch)
#pragma config(Sensor, dgtl3,  LimitSwitch3,   sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port4,           Servo,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           Servo3,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           ElvtorMotor,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           Servo4,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           RotateMotor,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           Servo2,        tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

#pragma autonomousDuration(15)
#pragma userControlDuration(120)
// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton() {
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


// //Faster line follower to make sure brains come out

task autonomous() {
	if (SensorValue(rightIR) > 200 ) {
		setMotor(rightMotor, -69);
	}

	if (SensorValue(rightIR) < 200) {
		setMotor(rightMotor, -26);
	}

	if (SensorValue (leftIR) > 200) {
		setMotor(leftMotor, -65);
	}

	if (SensorValue (leftIR) < 200) {
		setMotor(leftMotor, -24);
	}

	if (SensorValue (leftIR) < 200 && SensorValue (rightIR) < 200) {
		setMotor(leftMotor, -35);
		setMotor(rightMotor, -35);
	}
}



task Start() {
	if (SensorValue(rightIR) > 200 ) {
		setMotor(rightMotor, -69);
	}

	if (SensorValue(rightIR) < 200) {
		setMotor(rightMotor, -20);
	}

	if (SensorValue (leftIR) > 200) {
		setMotor(leftMotor, -67);
	}

	if (SensorValue (leftIR) < 200) {
		setMotor(leftMotor, -20);
	}

	if (SensorValue (leftIR) < 200 && SensorValue (rightIR) < 200) {
		setMotor(leftMotor, -35);
		setMotor(rightMotor, -35);
	}
}






task normal_speed() {
	if (SensorValue(rightIR) > 200 ) {
		setMotor(rightMotor, -73);
	}

	if (SensorValue(rightIR) < 200) {
		setMotor(rightMotor, -29);
	}

	if (SensorValue (leftIR) > 200) {
		setMotor(leftMotor, -71);
	}

	if (SensorValue (leftIR) < 200) {
		setMotor(leftMotor, -27);
	}

}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol() {
	while (true)  {
		enableCompetitionMode();

		//An arcade control that allows motors to run at a faster speed, instead of the speed provided by the function
		motor[leftMotor] = (vexRT[Ch3] + vexRT[Ch4]);
		motor[rightMotor] = (vexRT[Ch3] - vexRT[Ch4]);


		if (vexRT[Btn7U]) {
			setMotor(Servo3, 180);   //Controls to open both claws and close both claws at the same time
			setMotor(Servo4, -180);
			}	else if (vexRT[Btn7D]) {
			setMotor(Servo3, -180);
			setMotor(Servo4, 180);
		}




		if (vexRT[Btn7L] == 1 ) {
			setMotor(Servo4, -180);  //Allows for us to open either claw seperatly
		}

		if (vexRT[Btn7R] == 1 ) { //Allows for us to open either claw seperatly
			setMotor(Servo3, 180);
		}




		//Set up for elevator and limit switch to make sure the motor isnt overran
		if (vexRT[Btn6U] == 1) {
			setMotor(ElvtorMotor, -127);
			}	else if  (vexRT[Btn6D] == 1 && SensorValue[LimitSwitch] == 1){
			setMotor(ElvtorMotor,127);
			}	else if (vexRT[Btn6D] == 1 && SensorValue[LimitSwitch] == 0) {
			setMotor(ElvtorMotor,127);
			}	else {
			setMotor(ElvtorMotor, 0);
		};

		if  (SensorValue[LimitSwitch] == 0) {
			setMotor(ElvtorMotor,0);
		}

		if  (SensorValue[LimitSwitch3] == 0) {
			setMotor(ElvtorMotor,0);
		}






		//Set up for motor that rotates the claws, as well as the limit switch for those
		if (vexRT[Btn8L]) {
			setMotor(RotateMotor, 127);
			} else if (vexRT[Btn8R])  {
			setMotor(RotateMotor, -127);
			} else {
			setMotor(RotateMotor, 0);
		}

		if  (SensorValue[LimitSwitch2] == 0) {  //if the limit switch is hit, stop the motor
			setMotor(RotateMotor,0);
		}





		int y = 1; // declaring a variable to use for the autonomous timer






		//Blue and yellow side

		if (vexRT [Btn5U]) {

			while ( y < 5000) {
				startTask(Start);
				y = y+1; // this counts y and make it increase
				if (vexRT [Btn5D]) {
					y = y+10000000; // if this button is pressed, y will equal a value out of the perameters stopping the auto (Kill switch)
				}
			}

			while ( y < 70000) {
				startTask(normal_speed);
				y = y+1;
				if (vexRT [Btn5D]) {
					y = y+10000000;
				}
			}/*
			while ( y < 70000){
			startTask(Right_turn);
			y = y+1;
			if (vexRT [Btn5D]) {
			y = y+10000000;
			}
			}*/
			while ( y <120000) {
				startTask(autonomous);
				y = y+1;
				if (vexRT [Btn5D]) {
					y = y+10000000;
				}
			}
			while ( y <1000000) { // set this to a super high number so that it doesnt end unless we click the kill switch
				startTask(normal_speed);
				y = y+1;

				//this makes a kill switch to the autonomous, once it finishes or if it makes a mistake mid game
				if (vexRT [Btn5D]) {
					y = y+10000000;
				}
			}

		}
	}
}
