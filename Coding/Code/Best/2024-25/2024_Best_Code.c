#pragma config(Motor,  port2,           rDrive,        tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port3,           armGrip,       tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           arm,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           hab1,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           hab2,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           elevator,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           coreGrip,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           lDrive,        tmotorServoContinuousRotation, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void customArcade(){
	setMotor(lDrive, vexRT[Ch3] + vexRT[Ch4]);
	setMotor(rDrive, vexRT[Ch3] - vexRT[Ch4]);
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
		setMotor(motor, 127);
	}
	if (down){
		setMotor(motor, -127);
	}
}

void moduleDrop(){
		if (vexRT[Btn7D]){
			setMotor(hab1, 127);
			wait(1);
			setMotor(hab2, 127);
		}
}

task main(){
	while (true){
		customArcade();		//move wheels using joysticks

		motorPosControl(arm, vexRT[Btn5U], vexRT[Btn5D]);		//move arm using buttons

		servoControl(armGrip, vexRT[Btn8U], vexRT[Btn8D]);	//move arm grabber using buttons

		motorPosControl(elevator, vexRT[Btn6D], vexRT[Btn6U]); 	//move elevator using buttons

		servoControl(coreGrip, vexRT[Btn8L], vexRT[Btn8R]); 	//move core grip using buttons

		moduleDrop(); 	//activate habitat deployment mechanism using a button
	}
}