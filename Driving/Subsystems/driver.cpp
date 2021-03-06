// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "driver.h"
#include "../Robotmap.h"
#include "../robot.h"
driver::driver() : Subsystem("driver") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	en1 = RobotMap::driveren1;
	en2 = RobotMap::driveren2;
	spd2 = RobotMap::driverspd2;
	spd1 = RobotMap::driverspd1;
	driveTrain = RobotMap::driverdriveTrain;
	gyro1 = RobotMap::drivergyro1;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void driver::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void driver::M_drive(Joystick* stick1, Joystick* stick2){
	driveTrain->TankDrive(stick1, stick2);
}
void driver::read(){
	printf("Encoder 1 Raw: %d ",Robot::driver->en1->GetRaw());
	printf("Encoder 1: %d ",Robot::driver->en1->Get());
	printf("Encoder 2 Raw: %d ",Robot::driver->en2->GetRaw());
	printf("Encoder 2: %d ",Robot::driver->en2->Get());
	printf("RPM: %f\n", .24/Robot::driver->en1->GetPeriod());
}
void driver::reset(){
	Robot::driver->en1->Reset();
	Robot::driver->en2->Reset();
}
