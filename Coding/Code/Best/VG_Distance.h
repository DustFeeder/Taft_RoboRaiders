//Header File for VG_IRTest.c

float holeArc = 360 / holeCount;
float holeArcLength = holeArc * wheelDiameter * PI / 360;
bool hole = false;

float distCalc(float distance) {
	if (SensorValue[wheelEncoder] < 200 && false == hole) {
		distance += holeArcLength;
		hole = true;
	} else if (SensorValue[wheelEncoder] > 200) {
		hole = false;
	}
	return distance;
}

void distDrive(float distance, int speed) {
	int holes = distance / holeArcLength;
	for (int i = 0; i < holes; i++) {
		setMultipleMotors(speed, Ldrive, Rdrive);
		waitUntil(SensorValue[wheelEncoder] > 200);
	}
	stopAllMotors();
}
