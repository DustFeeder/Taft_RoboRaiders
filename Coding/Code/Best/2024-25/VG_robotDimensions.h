//we're using inches, final diameter is 6.625 inches
int segmentCount = 34;		//test value
float wheelDiameter = 12;	//test value
float wheelBaseWidth = 0;	//find actual value

float segmentArcLength = wheelDiameter * 3.14 / segmentCount;	//replace "3.14" with "PI" in robotC
float segmentArcDegrees = (360 * wheelDiameter) / (segmentCount * wheelBaseWidth);
bool segment = false;