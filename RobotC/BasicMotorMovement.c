
task main()
{
	for (int run_five_times = 0; run_five_times < 5; run_five_times++)
	{
		motor[motorA] = 75; motor[motorC] = 75; wait1Msec(2000);

		motor[motorA] = 0; motor[motorC] = 0; wait1Msec(1000);
	}
}
