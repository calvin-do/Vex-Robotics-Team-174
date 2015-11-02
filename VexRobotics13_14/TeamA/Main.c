#pragma config(Motor,  port2,           LeftDrive,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           RightDrive,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           ScissorUp,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           ScissorDown,   tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void driveMotors(int leftSpeed, int rightSpeed)
{
	motor[LeftDrive]   =  -leftSpeed;      // up = CW
	motor[RightDrive]  =  rightSpeed;    // up = CCW
}

void controlScissors()
{
	if(vexRT[Btn6U])
	{
		motor[ScissorUp] = 127;
	}
	else if(vexRT[Btn6D])
	{
		motor[ScissorUp] = -50;
	}
	else
	{
		motor[ScissorUp] = 0;
	}

	if(vexRT[Btn5D])
	{
		motor[ScissorDown] = 50;
	}
	else if(vexRT[Btn5U])
	{
		motor[ScissorDown] = -127;
	}
	else
	{
		motor[ScissorDown] = 0;
	}

}

void teleop()
{
	driveMotors(vexRT[Ch3], vexRT[Ch2]);
	controlScissors();
}

void backZoneAuto()
{
	//drive forward for 4 seconds
	driveMotors(100, 105);
	wait1Msec(4000);
	driveMotors(0, 0);
	wait1Msec(5);

	//Pretend to wait for picking up ball
	wait1Msec(2000);

	//drive forward for 1 second
	driveMotors(100, 120);
	wait1Msec(1000);
	driveMotors(0, 0);
	wait1Msec(5);

	//turn 90 degrees left
	driveMotors(-100, 100);
	wait1Msec(1000);
	driveMotors(0, 0);
	wait1Msec(5);

	//drive forward into bump
	driveMotors(100, 120);
	wait1Msec(1000);
	driveMotors(0, 0);
	wait1Msec(5);

	driveMotors(0, 0);
}

void middleZoneAuton()
{
	driveMotors(100, 127);
	wait1Msec(2000);
	driveMotors(100, -100);
	wait1Msec(1000);
	driveMotors(100, 127);
	wait1Msec(3000);

	driveMotors(0, 0);
}

void skillChallengeAuto()
{

}

void autonomous()
{
	//backZoneAuto();
	middleZoneAuton();
}

task main()
{

	//while(true)
	//{
	//	teleop();
	//}

  autonomous();

}
