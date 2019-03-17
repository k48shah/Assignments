void tagging() {
	if (SensorValue[S2] == 255 && SensorValue[S1] == 1)
	{
		motor[motorA] = 0;
		motor[motorC] = 0;
		motor[motorD] = 25;
		wait1Msec(3000);
		motor[motorD] = 0;
		motor[motorA] = 75;
		motor[motorC] = -75;
		wait1Msec(800);
		motor[motorA] = 0;
		motor[motorC] = 0;
		motor[motorD] = -15;
		wait1Msec(1000);
		motor[motorA] = 75;
		motor[motorC] = -75;
		wait1Msec(800);
		motor[motorA] = 75;
		motor[motorC] = 75;
	}
}

void obstacles() {
	if(SensorValue[S2] != 255 && SensorValue[S1] == 1)
	{
		motor[motorA] = 0;
		motor[motorC] = 0;
		wait1Msec(3000);
		motor[motorA] = 75;
		motor[motorC] = 75;
	}

}

void nextInterval() {

	const float rotationToDegrees = 100*360 / (5.5 * PI);
	motor[motorA] = 75;
	motor[motorC] = -75;
	wait1Msec(400);
	motor[motorA] = 75;
	motor[motorC] = 75;

	while (nMotorEncoder[motorA] <= rotationToDegrees)
	{}
	motor[motorA] = 75;
	motor[motorC] = -75;
	wait1Msec(400);
	motor[motorA] = 75;
	motor[motorC] = 75;
}





task main() {

	const float wheelRotation = PI * 5.5;
	const float FIELDWIDTH = 101;
	const float FIELDLENGTH = 59;
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;

	for (interval = 0; interval < FIELDWIDTH; interval++)
	{
		float driveStraight = 0;
		motor[motorA] = 75;
		motor[motorC] = 75;
		nMotorEncoder[motorA] = 0;
		while (SensorValue[S1] == 0 && driveStraight < 59)
		{
			obstacles();
			tagging();
			if (nEncoder[motorA] == wheelRotation)
				driveStraight++;
		}
		nextInterval();
	}

}


/*
Assumptions
1. Wheel diameter is exactly ______

Failures:
1. No bumps on the ground. Ground is flat.
2. Duck moves or flies away during tagging timeframe
3. Obstacles are always moving, no obstacle stays in the same place after 3
   seconds
*/
