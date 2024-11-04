#pragma config(Motor,  port2,           LeftDrive,     tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port3,           Claw,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           Arm,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           Elevator,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           RightDrive,    tmotorServoContinuousRotation, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true)  {
		enableCompetitionMode();

		//An arcade control that allows motors to run at a faster speed, instead of the speed provided by the function
		motor[LeftDrive] = (vexRT[Ch3] + vexRT[Ch4]);
		motor[RightDrive] = (vexRT[Ch3] - vexRT[Ch4]);

		//claw
		if (vexRT[Btn7U]) {
			setMotor(Claw, 180);
			}	else if (vexRT[Btn7D]) {
			setMotor(Claw, -180);
		}



		//Elevator
		if (vexRT[Btn6U]) {
			setMotor(Elevator, -127);
			} else if (vexRT[Btn6D]) {
			setMotor(Elevator, 127);
			} else {
			setMotor(Elevator, 0);
		}



		//arm
		if (vexRT[Btn5U]) {
			setMotor(Arm, 127);
			} else if (vexRT[Btn5D])  {
			setMotor(Arm, -127);
			} else {
			setMotor(Arm, 0);
		}


	}
}