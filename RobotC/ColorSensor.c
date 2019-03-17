float max(float redTileWidth, float maxRedTileWidthFunc)
{
	if (redTileWidth > maxRedTileWidthFunc)
		maxRedTileWidthFunc = redTileWidth;
	return maxRedTileWidthFunc;
}

int redTile()
{
	nMotorEncoder[motorA] = 0;
	float distance = 0;
	float degreesTurned = 0;
	motor[motorA] = motor[motorC] = 25;
	while (SensorValue[S3] == (int) colorRed)
	{}
	degreesTurned = nMotorEncoder[motorA];
	distance = degreesTurned * 2 * PI * 2.75 * 10 / 360;
	while (SensorValue[S3] != (int) colorBlue)
	{}
	motor[motorA] = motor[motorC] = 0;
	wait1Msec(500);
	return distance;
	motor[motorA] = motor[motorC] = 25;
}

void blueTile()
{
	motor[motorA] = motor[motorC] = 25;
	while (SensorValue[S3] != (int) colorRed)
	{}
	motor[motorA] = motor[motorC] = 0;
	wait1Msec(500);
	motor[motorA] = motor[motorC] = 25;
}


task main()
{

	SensorType[S3] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Color_Color;
	wait1Msec(50);
	float maxRedTileWidth = 0; //The integer value will never be negative for distance
	int numberOfRedTiles = 0;
	motor[motorA] = motor[motorC] = 25;
	while (numberOfRedTiles < 3)
	{
		float distance = 0;
		while (SensorValue[S3] != (int) colorRed || SensorValue[S3] != (int) colorBlue)
		{}
		if (SensorValue[S3] == (int) colorRed)
		{
			redTile();
			distance = redTile();
			numberOfRedTiles++;
			max(distance, maxRedTileWidth);
			maxRedTileWidth = max(distance, maxRedTileWidth);
		}
		if (SensorValue[S3] == (int) colorBlue)
			blueTile();

		motor[motorA] = 0;
		motor[motorC] = 0;
	}
	displayString(0, "%d ", maxRedTileWidth);
}
