#pragma config(Motor,  port3,           LeftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           RightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           ArmMotor,      tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!




///////////////////////////////////////////////////////
/// Our schtuff
/////////////////////////////////////////////////////


void driveMotors(int leftSpeed, int rightSpeed)
{
	motor[LeftMotor]   =  leftSpeed;      // up = CW
	motor[RightMotor]  =  -rightSpeed;    // up = CCW
}

void moveArm(int aSpeed) //ground to robot is postive, vice versa
{
	motor[ArmMotor] = aSpeed;
}


void teleop()
{
	driveMotors(vexRT[Ch3], vexRT[Ch2]);

	int armSpeed = 0;
	if(vexRT[Btn5U])
	{
		armSpeed = 127;
	}
	else if(vexRT[Btn5D])
	{
		armSpeed = -127;
	}
	moveArm(armSpeed);
}

void autonDriveStraight(int aMilli)
{
	driveMotors(100, 105);
	wait1Msec(aMilli);
	driveMotors(0, 0);
	wait1Msec(5);
}


//void twoBallAuton()
//{
//	wait1Msec(1500);


//	driveMotors(-100, -105); //drive backwards (3seconds)
//	wait1Msec(2300);
//	driveMotors(0, 0);
//	wait1Msec(5);

//	driveMotors(100,105); //drive forwards (1second)
//	wait1Msec(1500);
//	driveMotors(0,0);
//	wait1Msec(5);

//	driveMotors(50,-55);//Turn toward second ball (Red Side)
//	wait1Msec(2000);											//NOTE:driveMotors(100,-105); wait1Msec(2000); is about 90 degrees clockwise
//	driveMotors(0,0);
//	wait1Msec(5);

//	driveMotors(-100,-105);//Move towards ball
//	wait1Msec(2300);
//	driveMotors(0,0);
//	wait1Msec(5);
//}

void diagonalBallStraightAuto()
{
	//drive forward for 4 seconds
	driveMotors(100, 105);
	wait1Msec(2250);
	driveMotors(0, 0);
	wait1Msec(5);

	moveArm(-80);
	wait1Msec(500);
	moveArm(0);
	wait1Msec(5);

	//driveMotors(-100,-105); //drive backwards (1second)
	//wait1Msec(2100);
	//driveMotors(0,0);
	//wait1Msec(5);

	driveMotors(0, 0);
}

void singleBallStraightAuto()
{
	//drive forward for 4 seconds
	driveMotors(-100, -105);
	wait1Msec(2300);
	driveMotors(0, 0);
	wait1Msec(5);

	driveMotors(100,105); //drive forwards (1second)
	wait1Msec(2300);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(0, 0);
}

//void buckyBallLeftAuto() //GOOD
//{
//	//driveMotors(-100,-105); //DRIVES FORWARD
//	//wait1Msec(2300);
//	//driveMotors(0,0);
//	//wait1Msec(5);

//	//driveMotors(-50,55); //TURNS LEFT 90?
//	//wait1Msec(1250);
//	//driveMotors(0,0);
//	//wait1Msec(5);

//	//driveMotors(-100,-105); //DRIVES FORWARD
//	//wait1Msec(4500);
//	//driveMotors(0,0);
//	//wait1Msec(5);

//	moveArm(60);
//	wait1Msec(0);
//	moveArm(0);
//	wait1Msec(5);
//}

//void buckyBallRightAuto() //GOOD
//{
//	driveMotors(-100,-105); //DRIVES FORWARD
//	wait1Msec(2300);
//	driveMotors(0,0);
//	wait1Msec(5);

//	driveMotors(50,-55); //TURNS RIGHT 90?
//	wait1Msec(1250);
//	driveMotors(0,0);
//	wait1Msec(5);

//	driveMotors(-100,-105); //DRIVES FORWARD
//	wait1Msec(4500);
//	driveMotors(0,0);
//	wait1Msec(5);

//	moveArm(60);
//	wait1Msec(0);
//	moveArm(0);
//	wait1Msec(5);
//}

void checkAuto(int isRight) //GOOD
{


	driveMotors(-122,-127); //DRIVES BACKWARDS
	wait1Msec(2300);
	driveMotors(0,0);
	wait1Msec(5);

	if(isRight == 1)
	{
		driveMotors(50,-55); //TURNS RIGHT 90
		wait1Msec(1250);
		driveMotors(0,0);
		wait1Msec(5);
	}
	else
	{
		driveMotors(-50,55); //TURNS LEFT 90
		wait1Msec(1250);
		driveMotors(0,0);
		wait1Msec(5);
	}

	moveArm(60);
	wait1Msec(500);
	moveArm(0);
	wait1Msec(5);

	driveMotors(-100,-105); //DRIVES BACKWARDS
	wait1Msec(3550);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(-100,-105);
	wait1Msec(600);
	driveMotors(0,0);
	wait1Msec(5);

	moveArm(-60);
	wait1Msec(450);
	driveMotors(0,0);
	moveArm(0);
	wait1Msec(5);

	moveArm(60);
	driveMotors(-50,-55);
	wait1Msec(500);
	driveMotors(0,0);
	moveArm(0);
	wait1Msec(5);
}

void checkAutoWithForwards(int isRight)
{
	driveMotors(122,127);
	wait1Msec(2300);
	driveMotors(0,0);
	wait1Msec(5);

	moveArm(-100);
	wait1Msec(500);
	moveArm(0);
	wait1Msec(5);

	if(isRight == 1)
	{
		driveMotors(50,-55); //TURNS RIGHT 90
		wait1Msec(1250);
		driveMotors(0,0);
		wait1Msec(5);
	}
	else
	{
		driveMotors(-50,55); //TURNS LEFT 90
		wait1Msec(1250);
		driveMotors(0,0);
		wait1Msec(5);
	}

	moveArm(60);
	driveMotors(100,105);
	wait1Msec(500);
	moveArm(0);
	wait1Msec(5);
	driveMotors(100,105);
	wait1Msec(3500);
	driveMotors(0,0);
	wait1Msec(5);
}

void skillChallengeLeftMidZone()
{
  /**********************************
	 * Left Side (Middle Zone)
	 **********************************/
	singleBallStraightAuto();     //DRIVE FORWARDS

	moveArm(60);									//PREPARE ARM
	wait1Msec(1000);
	moveArm(0);
	wait1Msec(5);

	wait1Msec(5000);							//HUMAN INTERACTION
	diagonalBallStraightAuto();		//DIAGONAL FORWARDS

	driveMotors(-100,-105); //DRIVE BACKWARDS TO START
	wait1Msec(2100);
	driveMotors(0,0);
	wait1Msec(5);


	//Move arm all the way back (away from ground)
	moveArm(60);
	wait1Msec(1000);
	moveArm(0);
	wait1Msec(5);
}

void skillChallengePrepAndDriveAccross()
{
	/**********************************
	 * Cross Field (Middle Zone)
	 **********************************/
	wait1Msec(3000);						//HUMAN TURN TOWARDS OTHER START


	driveMotors(100,105);					//DRIVE ACROSS TO RIGHT SIDE
	wait1Msec(6700);
	driveMotors(0,0);
	wait1Msec(5);

	//Let the human align it to hit the ball
	wait1Msec(5000);							//WAIT FOR HUMAN ADJUSTMENTS

	//Move the arm to the desired position
	moveArm(-60);
	wait1Msec(250);
	moveArm(0);
	wait1Msec(5);
}

void skillChallangeRightMidZOne()
{
	/**********************************
	 * Right Side (Middle Zone)
	 **********************************/
	wait1Msec(750);							//Small wait to make sure everything is OK


	singleBallStraightAuto();     //DRIVE FORWARDS

	moveArm(60);									//PREPARE ARM
	wait1Msec(1000);
	moveArm(0);
	wait1Msec(5);

	wait1Msec(5000);							//HUMAN INTERACTION
	diagonalBallStraightAuto();		//DIAGONAL FORWARDS

	driveMotors(-100,-105); 			//DRIVE BACKWARDS TO START
	wait1Msec(2100);
	driveMotors(0,0);
	wait1Msec(5);

	wait1Msec(3000);							//HUMAN ADJUSTMENTS
}

void skillChallengeMoveToBackZone()
{
	/**********************************
	 * MOVE TO BACK ZONE
	 **********************************/
	moveArm(60);									//READY ARM
	wait1Msec(1000);
	moveArm(0);
	wait1Msec(5);

	driveMotors(-100,-105);				//DRIVE OVER BUMP
	wait1Msec(2200);
	driveMotors(0,0);
	wait1Msec(5);

	wait1Msec(3000);							//CHANGE ANGLE TOWARDS CENTER (HUMAN)
}


void skillChallengeBackLeftBuckeyAuto()
{

	/**********************************
	 * KNOCK OFF BUCKYBALLS (LEFT SIDE)
	 **********************************/
	driveMotors(50,-55); 					//TURNS RIGHT 90
	wait1Msec(1250);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(100,105);					//KNOCKS BALLS OFF
	wait1Msec(700);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(-100,-105);				//GETS OFF THE BUMP
	wait1Msec(400);
	driveMotors(0,0);
	wait1Msec(5);

	moveArm(-60);									//MOVES ARM DOWN
	wait1Msec(500);
	moveArm(0);
	wait1Msec(5);

	driveMotors(100,105);					//DRIVE OVER BUMP (TRY TO PUSH BALLS OVER TO END)
	wait1Msec(5000);
	driveMotors(0,0);
	wait1Msec(5);

}

void skillChallengeBackRightBuckeyAuto()
{

	/**********************************
	 * KNOCKING BUCKYBALLS (RIGHT SIDE)
	 **********************************/

	driveMotors(100,105);					//DRIVES FORWARD
	wait1Msec(2300);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(50,-55); 					//TURNS RIGHT 90
	wait1Msec(1250);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(100,105);					//KNOCKS BALLS OFF
	wait1Msec(700);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(-100,-105);				//GETS OFF THE BUMP
	wait1Msec(400);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(-50,55); 					//TURNS LEFT 90
	wait1Msec(1250);
	driveMotors(0,0);
	wait1Msec(5);

	driveMotors(100,105);					//DRIVE TO SECOND SET OF BALLS
	wait1Msec(2300);
	driveMotors(0,0);
	wait1Msec(5);

}

void skillChallengeAuto()
{
	skillChallengeLeftMidZone();
	skillChallengePrepAndDriveAccross();
	skillChallangeRightMidZOne();

	skillChallengeMoveToBackZone();

	skillChallengeBackRightBuckeyAuto();
	skillChallengeBackLeftBuckeyAuto();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	skillChallengeAuto();

	//checkAuto(1);//1 is right, 0 is left
//	checkAutoWithForwards(1); //1 is right, 0 is left

	//buckyBallLeftAuto();
//OR
	//buckyBallRightAuto();


//|-------------------------|
	//singleBallStraightAuto();

	//moveArm(60);
	//wait1Msec(1000);
	//moveArm(0);
	//wait1Msec(5);

	//wait1Msec(5000);
	//diagonalBallStraightAuto();
//|--------------------------|

  //twoBallAuton();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................

	  //UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
		teleop();
	}
}
