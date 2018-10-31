


void gyro_turn(float degree, int speed, bool direction)
		{
			degree = (!direction)? (degree) : (degree * -1);
			degree *= 10;

			if (SensorValue[gyro] > degree && direction)
			{
				motor[LBdrive] = speed;
				motor[LFdrive] = speed;
				motor[RBdrive] = -speed;
				motor[RFdrive] = -speed;
			}

			else if (SensorValue[gyro] < degree && !direction)
			{
				motor[LBdrive] = -speed;
				motor[LFdrive] = -speed;
				motor[RBdrive] = speed;
				motor[RFdrive] = speed;
			}

			else
			{
				motor[LBdrive] = 0;
				motor[LFdrive] = 0;
				motor[RBdrive] = 0;
				motor[RFdrive] = 0;
			}
}

void forward(int time, int speed)
{
		//recording gyro reading for veer
		int initial = SensorValue[gyro];

		float k = 1;

		clearTimer(T1);

		while (time1[T1] < time)
		{
			int error = SensorValue[gyro] - initial;
			motor[RBdrive] = speed - (error*k);
			motor[RFdrive] = speed - (error*k);
			motor[LBdrive] = speed - (-error*k);
			motor[LFdrive] = speed - (-error*k);

		}


}


void backward(int time, int speed)
{
		//recording gyro reading for veer
		int initial = SensorValue[gyro];

		float k = 1;

		clearTimer(T1);

		while (time1[T1] < time)
		{
			int error = SensorValue[gyro] - initial;
			motor[RBdrive] = -speed - (error*k);
			motor[RFdrive] = -speed - (error*k);
			motor[LBdrive] = -speed - (-error*k);
			motor[LFdrive] = -speed - (-error*k);

		}



}
