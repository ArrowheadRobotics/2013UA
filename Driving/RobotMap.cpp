// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
Encoder* RobotMap::driveren1 = NULL;
Encoder* RobotMap::driveren2 = NULL;
SpeedController* RobotMap::driverspd2 = NULL;
SpeedController* RobotMap::driverspd1 = NULL;
RobotDrive* RobotMap::driverdriveTrain = NULL;
Gyro* RobotMap::drivergyro1 = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	driveren1 = new Encoder(1, 1, 1, 2, true, Encoder::k4X);
	lw->AddSensor("driver", "en1", driveren1);
	driveren1->SetDistancePerPulse(1.0);
        driveren1->SetPIDSourceParameter(Encoder::kRate);
        driveren1->Start();
	driveren2 = new Encoder(1, 5, 1, 6, false, Encoder::k4X);
	lw->AddSensor("driver", "en2", driveren2);
	driveren2->SetDistancePerPulse(1.0);
        driveren2->SetPIDSourceParameter(Encoder::kRate);
        driveren2->Start();
	driverspd2 = new Victor(1, 2);
	lw->AddActuator("driver", "spd2", (Victor*) driverspd2);
	
	driverspd1 = new Victor(1, 1);
	lw->AddActuator("driver", "spd1", (Victor*) driverspd1);
	
	driverdriveTrain = new RobotDrive(driverspd1, driverspd2);
	
	driverdriveTrain->SetSafetyEnabled(false);	
        driverdriveTrain->SetExpiration(0.1);
        driverdriveTrain->SetSensitivity(0.5);
        driverdriveTrain->SetMaxOutput(1.0);
        
	drivergyro1 = new Gyro(1, 1);
	lw->AddSensor("driver", "gyro1", drivergyro1);
	drivergyro1->SetSensitivity(0.0064);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
        driveren1->SetDistancePerPulse(39*3.1415926535897932384626433832795028841971693993/14000);
        driveren2->SetDistancePerPulse(39*3.1415926535897932384626433832795028841971693993/14000);
        driveren1->Reset();
        driveren2->Reset();
}
