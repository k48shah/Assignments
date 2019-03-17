
task main()
{

	SensorType[S1] = sensorEV3_Touch;

	displayString(0, "Mon 35");

	for(int i = 0; i < 3; i++)
	{

		while(!getButtonPress(buttonLeft) && !getButtonPress(buttonRight) && !getButtonPress(buttonEnter))
		{}

		if (getButtonPress(buttonRight))
		{
			while (getButtonPress(buttonRight))
			{}

			motor[motorA] = 75;
			motor[motorC] = -75;
			wait1Msec(300);

		}

		if (getButtonPress(buttonLeft))
		{
			while (getButtonPress(buttonLeft))
			{}

			motor[motorA] = -75;
			motor[motorC] = 75;
			wait1Msec(300);

		}

		if (getButtonPress (buttonEnter))
		{
			while (getButtonPress(buttonEnter))
			{}

			displayString(1, "Vamanos");
			motor[motorA] = 100;
			motor[motorC] = 100;
			wait1Msec(2000);

		}

		motor[motorA] = 0;
		motor[motorC] = 0;

	}

	while (SensorValue[S1] == 0)
	{

		motor[motorA] = 75;
		motor[motorC] = 25;

	}

	motor[motorA] = 0;
	motor[motorC] = 0;

}
