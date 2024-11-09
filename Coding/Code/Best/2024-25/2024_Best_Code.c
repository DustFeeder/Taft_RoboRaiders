#pragma config(Motor,  port2,           rightDrive,    tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port3,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           frontHabitat,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           bottomHabitat, tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           leftDrive,     tmotorServoContinuousRotation, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

bool toggle1 = true;
bool toggle2 = true;

void customArcade(){
	if (abs(vexRT[Ch3]) < 20 && abs(vexRT[Ch4]) < 20) {
		setMotor(leftDrive, (vexRT[Ch2] + vexRT[Ch1]) / 2);
		setMotor(rightDrive, (vexRT[Ch2] - vexRT[Ch1]) / 2);
		} else {
		setMotor(leftDrive, vexRT[Ch3] + vexRT[Ch4]);
		setMotor(rightDrive, vexRT[Ch3] - vexRT[Ch4]);
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
void servoControl1(float motor, bool up, bool down){
	if (up){
		setMotor(motor, -90);
	}
	if (down){
		setMotor(motor, 90);
	}
}

//not done - feel free to fix
void moduleDrop(float servo1, bool button1, bool button2, bool frontHab){
	if (button1 && button2){
		if(toggle1 && frontHab){
			setMotor(servo1, 90);
			toggle1 = false;
		}
		if(toggle2 && !frontHab){
			setMotor(servo1, 90);
			toggle2 = false;
		}
		if (!toggle1 && frontHab){
			setMotor(servo1, -90);
			toggle1 = true;
		}
		if (!toggle2 && !frontHab){
			setMotor(servo1, -90);
			toggle2 = true;
		}
	}
}

void resetArm(float motor1, bool top, bool bottom){
	if(top){
		setMotor(motor1, 127);
		wait(1.7);
		setMotor(motor1, 0);
	} else if(bottom){
		setMotor(motor1, -127);
		wait(1.7);
		setMotor(motor1, 0);
	}
}

task main(){
	while (true){
		customArcade();	//move wheels using joysticks

		//resetArm(armMotor, vexRT[Btn6U], vexRT[Btn6D]); // resets the arm to default

		motorPosControl(armMotor, vexRT[Btn5U], vexRT[Btn5D]);		//move arm using buttons

		servoControl(frontHabitat, vexRT[Btn8U], vexRT[Btn8D]);	//move arm grabber using buttons !!t using anymore
   	servoControl1(bottomHabitat, vexRT[Btn8U], vexRT[Btn8D]);
		//motorPosControl(elevator, vexRT[Btn6D], vexRT[Btn6U]); 	//move elevator using buttons !!t using anymore

		//servoControl(coreGrip, vexRT[Btn8L], vexRT[Btn8R]); 	//move core grip using buttons !!t using anymore

	//	moduleDrop(bottomHabitat, vexRT[Btn8U], vexRT[Btn8D], false); 	//activates front habitat deployment mechanisms using buttons
	//	moduleDrop(frontHabitat, vexRT[Btn8U], vexRT[Btn8D], true); 	//activates bottom habitat deployment mechanisms using buttons
	}
}
