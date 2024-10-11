//header file for modified version of VG_Distance with no Ir, just a timer using a for loop.
//15"/sec max robot speed

float wheelCircumfrence = wheelDiameter * PI;
float maxMotorSpeed = 0;
float wheelspeed = wheelCircumfrence * maxMotorSpeed * 60;

void Time_Drive(float Distance, float Time) {
	float speed = ((Distance / Time) / wheelspeed) * 127;
	while (getTimer(T1, seconds) < Time){
		setMultipleMotors(speed, LDrive, RDrive);
	}
	resetTimer(T1);
	stopAllMotors();
}
