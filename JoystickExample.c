/* 

THIS IS CODE IS FOR THE FOLLOWING MOTOR CONFIGURATIONS ONLY

This code was used in the 2017-18 season and except for the drive probably does not have any functions that you need.
This is instead to get an idea of how to configure joystick controls for usercontrol.

*/



#pragma config(Sensor, in1,    gyro,           sensorNone)
#pragma config(Motor,  port1,           Lmobgoal,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Ldr4b,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LBdrive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           L4bar,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LFdrive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RFdrive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RBdrive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Rdr4b,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          Rmobgoal,      tmotorVex393_HBridge, openLoop, reversed)


task usercontrol()
{
  bLCDBacklight = true;
	string mainBattery, backupBattery;

	  }
		//Drive Chain
		motor[LFdrive] = (vexRT[Ch3] + vexRT[Ch3Xmtr2])*0.75;
	  motor[LBdrive] = (vexRT[Ch3] + vexRT[Ch3Xmtr2])*0.75;
		motor[RFdrive] = (vexRT[Ch2] + vexRT[Ch2Xmtr2])*0.75;
		motor[RBdrive] = (vexRT[Ch2] + vexRT[Ch2Xmtr2])*0.75;


		//Dr4B
		if(vexRT[Btn7U] == 1)
		{
			motor[Ldr4b] = 127;
			motor[Rdr4b] = 127;
		}
		else if(vexRT[Btn7D] == 1)
		{
			motor[Ldr4b] = -127;
			motor[Rdr4b] = -127;
		}
		else
		{
			motor[Ldr4b] = 0;
			motor[Rdr4b] = 0;
		}


		//mobile goal

		if(vexRT[Btn8UXmtr2] == 1)
		{
			motor[Lmobgoal] = 127;
			motor[Rmobgoal] = 127;
		}
		else if (vexRT[Btn8DXmtr2] == 1)
		{
			clearTimer(T1);
			motor[Lmobgoal] = -127;
			motor[Rmobgoal] = -127;
		}
		else if (vexRT[Btn8U] == 1)
		{
			motor[Lmobgoal] = 127;
			motor[Rmobgoal] = 127;
		}
		else if (vexRT[Btn8D] == 1)
		{
			clearTimer(T1);
			motor[Lmobgoal] = -127;
			motor[Rmobgoal] = -127;
		}
		else if (time1[T1] < 4000)
		{
			motor[Lmobgoal] = 0;
			motor[Rmobgoal] = 0;
		}
		else
		{
			motor[Lmobgoal] = 15;
			motor[Rmobgoal] = 15;
		}

		// intake
		if (vexRT[Btn5U] == 1)
		{
			motor[intake] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[intake] = -127;
		}
		else
		{
			motor[intake] = 20;
		}

		// 4bar
		if (vexRT[Btn6U] == 1 && vexRT[Btn7U] == 0)
		{
			motor[L4bar] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[L4bar] = -127;
		}
		else
		{
			motor[L4bar] = 0;
		}
	}
}
