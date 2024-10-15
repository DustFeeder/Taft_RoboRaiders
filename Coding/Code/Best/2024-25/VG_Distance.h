//Header File for VG_IRTest.c

float segmentArc = 360 / wheelSegments;
float segmentArcLength = segmentArc * wheelDiameter * PI / 360;
bool segment = false;

float distCalc(float distance) {
	if (SensorValue[IR] < 200 && false == segment) {
		distance += segmentArcLength;
		segment = true;
	} else if (SensorValue[IR] > 200) {
		segment = false;
	}
	return distance;
}

void distDrive(bool button, float totalDistance, int speed) {
	if (true == button) {
		int distanceGone = 0;
		while (distanceGone < totalDistance) {
			setMultipleMotors(speed, LDrive, RDrive);
			distanceGone = distCalc(distanceGone);
		}
		stopAllMotors();
	}
}
