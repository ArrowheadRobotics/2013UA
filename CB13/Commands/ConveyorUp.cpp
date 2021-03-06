#include "ConveyorUp.h"

ConveyorUp::ConveyorUp() {
	// Use requires() here to declare subsystem dependencies
	Requires(Robot::conveyor);
	t = new Timer();
	t2 = new Timer();
}
// Called just before this Command runs the first time
void ConveyorUp::Initialize() {
	t->Reset();
	t->Start();
	t2->Reset();
	t2->Stop();
}
// Called repeatedly when this Command is scheduled to run
void ConveyorUp::Execute() {
	/*
	 * Cory can explain this indepth, if needed
	 * 
	 * or just enable the printf statement and run the conveyor to see how it works...
	 */
//	printf("Gatesol: %d FL: %d Timer: %f\n", RobotMap::gatesol1->Get(),
//			RobotMap::forkLiftSW->Get(), t->Get());
	if (RobotMap::gatesol1->Get()) {//Gate is open
		t2->Stop();
		t2->Reset();
		if (t->Get() > 1.25f) {//timer has completed, run conveyor
			if (!RobotMap::forkLiftSW->Get()) {//the switch was triggered, stop conveyor and reset timer 
				Robot::conveyor->conv->Set(Relay::kOff);
				t->Reset();
			} else {//switch not triggered, timer completed, run conveyor
				Robot::conveyor->Move();
			}
		} else {//timer has not completed, turn off the conveyor
			Robot::conveyor->conv->Set(Relay::kOff);
		}
	} else {//Gate is closed, turn off the conveyor
		t2->Start();
		if(t2->Get()>3.0f)Robot::conveyor->conv->Set(Relay::kOff);//wait for the frisbee to reach the back
	}
}
// Make this return true when this Command no longer needs to run execute()
bool ConveyorUp::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void ConveyorUp::End() {

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ConveyorUp::Interrupted() {
}
