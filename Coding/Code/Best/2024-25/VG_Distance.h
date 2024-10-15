//Header File for VG_IRTest.c

float segmentArc = 360 / wheelSegments;
float segmentArcLength = segmentArc * wheelDiameter * PI / 360;
bool segment = false;
bool segment2 = false;

float distCalc(float distance) {
	if (SensorValue[IR] < 200 && false == segment) {
		distance += segmentArcLength;
		segment = true;
		} else if (SensorValue[IR] > 200) {
		segment = false;
	}
	return distance;
}
	float distCalc2(float distance2) {
		if (SensorValue[IR2] < 200 && false == segment2) {
			distance2 += segmentArcLength;
			segment2 = true;
			} else if (SensorValue[IR2] > 200) {
			segment2 = false;
		}
		return distance2;
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
