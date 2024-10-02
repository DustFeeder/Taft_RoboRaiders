
void distDrive(float distance, float arcLength, int speed) {
	int holes = distance / arcLength;
	for (int i = 0; i < holes; i++) {
		setMultipleMotors(speed, Ldrive, Rdrive);
		waitUntil(SensorValue[wheelEncoder] < 200);
	}
	stopAllMotors();
}
