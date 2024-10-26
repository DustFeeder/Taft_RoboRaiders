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

//distance is in inches
float autoDrive(bool turning, float encoder, float motor, int speed, float distanceGone) {
	setMotor(motor, speed);
	distanceGone = motionCalculation(distanceGone, encoder, turning);
	return distanceGone;
}

float driveControl(bool turning, float encoder, float motor, int speed, float target, float distanceGone) {
	if (distanceGone < target) {
		setMotor(motor, speed);
	} else {
		stopMotor(motor);
	}
	distanceGone = motionCalculation(distanceGone, encoder, turning);
	return distanceGone;
}

void autoDrive2(bool turning, int speed, float target) {
	float distanceL = 0;
	float distanceR = 0;
	float targetL = target;
	float targetR = target;
	if (turning) {
		targetR = -target;
	}
	while (distanceL < targetL || distanceR < targetR) {
		distanceL = driveControl(turning, IRL, LDrive, speed, targetL, distanceL);
		distanceR = driveControl(turning, IRR, RDrive, speed, targetR, distanceR);
	}
}
