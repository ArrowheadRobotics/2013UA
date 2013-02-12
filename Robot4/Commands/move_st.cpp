//Todo Remove RoboBuilder AUTOGEN from this file
// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "move_st.h"
move_st::move_st() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevation);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetTimeout(.5);
}
// Called just before this Command runs the first time
void move_st::Initialize() {
	printf("move_dn - int\n");
	/*
	Robot::elevation->Stop();
	try
		{
			printf("is table connected %d    ",Robot::oi->server->IsConnected());
			printf("%f\n",Robot::oi->server->GetNumber("test",0.0));
			printf("%f\n",Robot::oi->server->GetNumber("IM",0.0));
			printf("is table 2 connected %d  ",Robot::oi->server2->IsConnected());
			printf("%f\n",Robot::oi->server->GetNumber("BFR"));
		}
	catch (...)
		{
			printf("FAILBLOG.ORG\n");
			}
			*/
}
// Called repeatedly when this Command is scheduled to run
void move_st::Execute() {
	Robot::elevation->Stop();
}
// Make this return true when this Command no longer needs to run execute()
bool move_st::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void move_st::End() {
	printf("move_dn - end\n");
	Robot::elevation->qenc->Reset();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void move_st::Interrupted() {
	printf("move_db - interrup\n");
	Robot::elevation->Stop();
}
