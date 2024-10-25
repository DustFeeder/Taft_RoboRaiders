float motionCalculation(float distance, float encoder, bool turning) {
	int segmentDistance = segmentArcLength;
	if (turning) {
		segmentDistance = segmentArcDegrees;
	}
	if (SensorValue[encoder] < 200 && false == segment) {
		distance += segmentDistance;
		segment = true;
		} else if (SensorValue[encoder] > 200) {
		segment = false;
	}
	return distance;
}

void autoDrive(bool turning, bool button, float encoder, float motor, int speed, float totalDistance) {
	if (true == button) {
		int distanceGone = 0;
		while (distanceGone < totalDistance) {
			setMotor(motor, speed);
			distanceGone = motionCalculation(distanceGone, encoder, turning);
		}
		setMotor(motor, 0);
	}
}
