#include "drive2.h"
drive2::drive2() {
}
// Called just before this Command runs the first time
void drive2::Initialize() {
	/*Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
	printf("driveInit  ");
	drive2::accelerate(.2,-1);
	while(Robot::driver->en1->GetDistance()>-1 || Robot::driver->en2->GetDistance()>-1){
		if(Robot::driver->en1->GetDistance()>-1){
			Robot::driver->spd1->Set(-.2);
		}
		else{
			Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()>-1){
			Robot::driver->spd2->Set(.2);
		}
		else{
			Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	Robot::driver->spd1->Set(0);
	Robot::driver->spd2->Set(0);
	printf("%f  %d  %f  %d\n", Robot::driver->en1->GetDistance(), Robot::driver->en1->Get(), Robot::driver->en2->GetDistance(), Robot::driver->en2->Get());
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();*/
}
// Called repeatedly when this Command is scheduled to run
void drive2::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool drive2::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void drive2::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void drive2::Interrupted() {
}
void drive2::accelerate(float spd, float dist){
	Robot::driver->spd1->Set(spd/5*2);
	Robot::driver->spd2->Set(spd/5*2);
	Wait(.1);
	Robot::driver->spd1->Set(spd/5*3);
	Robot::driver->spd2->Set(spd/5*3);
	while(Robot::driver->en1->GetDistance()>dist/5/-3 || Robot::driver->en2->GetDistance()>dist/5/-3){
				
	}
	Robot::driver->spd1->Set(spd/5*4);
	Robot::driver->spd2->Set(spd/5*4);
	while(Robot::driver->en1->GetDistance()>dist/5/-2 || Robot::driver->en2->GetDistance()>dist/5/-2){
					
	}
}