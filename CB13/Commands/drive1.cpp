#include "drive1.h"
drive1::drive1() {
}
// Called just before this Command runs the first time
void drive1::Initialize() {
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
	printf("driveInit  ");
	/*
	drive1::accelerate(.3,5);
	while(Robot::driver->en1->GetDistance()<5 || Robot::driver->en2->GetDistance()<5){
		if(Robot::driver->en1->GetDistance()<5){
			Robot::driver->spd1->Set(-.3);
		}
		else{
			Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()<5){
			Robot::driver->spd2->Set(.3);
		}
		else{
			Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	drive1::accelerate(.3,-3);
	while(Robot::driver->en1->GetDistance()>2 || Robot::driver->en2->GetDistance()>2){
		if(Robot::driver->en1->GetDistance()>2){
			Robot::driver->spd1->Set(.3);
		}
		else{
			Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()>2){
			Robot::driver->spd2->Set(-.3);
		}
		else{
			Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	drive1::accelerate(.3,2);
	while(Robot::driver->en1->GetDistance()<4 || Robot::driver->en2->GetDistance()<4){
		if(Robot::driver->en1->GetDistance()<4){
			Robot::driver->spd1->Set(-.3);
		}
		else{
			Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()<4){
			Robot::driver->spd2->Set(.3);
		}
		else{
			Robot::driver->spd2->Set(0);
		}
		printf("%f  %f\n", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
	}
	drive1::accelerate(.3,-4);
	while(Robot::driver->en1->GetDistance()>0 || Robot::driver->en2->GetDistance()>0){
		if(Robot::driver->en1->GetDistance()>0){
			Robot::driver->spd1->Set(.3);
		}
		else{
			Robot::driver->spd1->Set(0);
		}
		if(Robot::driver->en2->GetDistance()>0){
			Robot::driver->spd2->Set(-.3);
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
	Robot::driver->en2->Reset();
	*/
}
// Called repeatedly when this Command is scheduled to run
void drive1::Execute() {
	//printf("1");
	//Robot::driver->M_drive(Robot::oi->getjoy1(), Robot::oi->getjoy2());
	//Robot::driver->read();
	//printf("exec  ");
}
// Make this return true when this Command no longer needs to run execute()
bool drive1::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void drive1::End() {
	//Robot::driver->spd1->Set(0);
	//Robot::driver->spd2->Set(0);
	printf("end  ");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void drive1::Interrupted() {
}
void drive1::accelerate(float spd, float dist){
	Robot::driver->spd1->Set(spd/5*-2);
	Robot::driver->spd2->Set(spd/5*2);
	Wait(.1);
	Robot::driver->spd1->Set(spd/5*-3);
	Robot::driver->spd2->Set(spd/5*3);
	Wait(.1);
	Robot::driver->spd1->Set(spd/5*-4);
	Robot::driver->spd2->Set(spd/5*4);
	while(Robot::driver->en1->GetDistance()<dist/5/2 || Robot::driver->en2->GetDistance()<dist/5/2){
		printf("%f  %f ", Robot::driver->en1->GetDistance(), Robot::driver->en2->GetDistance());
		printf("%f\n",dist/5/2);
		//Robot::driver->read();
	}
}
