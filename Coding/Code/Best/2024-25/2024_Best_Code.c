#pragma config(Motor,  port2,           rDrive,        tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port4,           bottomHabitat, tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           arm,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           topHabitat,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           lDrive,        tmotorServoContinuousRotation, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

bool changeDrive = true;
bool driveArcade = true;

void customArcade(bool toggle){
	if (toggle && changeDrive) {
		driveArcade = !driveArcade;
		changeDrive = !changeDrive;
	}
	if (!toggle && !changeDrive) {
		changeDrive = !changeDrive;
	}
	if (driveArcade) {
		setMotor(lDrive, vexRT[Ch3] + vexRT[Ch4]);
		setMotor(rDrive, vexRT[Ch3] - vexRT[Ch4]);
	} else {
		setMotor(lDrive, vexRT[Ch3]);
		setMotor(rDrive, vexRT[Ch2]);
	}
}

void motorPosControl(float motor, bool up, bool down) {
	if(up) {
		setMotor(motor, 127);
		}	else if(down){
		setMotor(motor, -127);
		}	else {
		setMotor(motor, 0);
	}
}

void servoControl(float motor, bool up, bool down){
	if (up){
		setMotor(motor, 90);
	}
	if (down){
		setMotor(motor, -90);
	}
}

task main(){
	while (true){
		customArcade(vexRT[Btn8D]);		//move wheels using joysticks

		//servoControl(armGrip, vexRT[Btn8U], vexRT[Btn8D]);	//move arm grabber using buttons

		//motorPosControl(elevator, vexRT[Btn6D], vexRT[Btn6U]); 	//move elevator using buttons

		//servoControl(coreGrip, vexRT[Btn8L], vexRT[Btn8R]); 	//move core grip using buttons

		servoControl(topHabitat, vexRT[Btn7U], vexRT[Btn7D]);

		servoControl(bottomHabitat, vexRT[Btn7U], vexRT[Btn7D]);

		motorPosControl(arm, vexRT[Btn5U], vexRT[Btn5D]);		//move arm using buttons
	}
}
