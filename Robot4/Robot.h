//Todo Remove RoboBuilder AUTOGEN from this file

#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Subsystems/gate.h"
#include "Commands/AutonomousCommand.h"
#include "Subsystems/Elevation.h"
#include "Subsystems/driver.h"
#include "OI.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static ::gate* gate;
	static OI *oi;
	LiveWindow *lw;
	static Elevation* elevation;
	static ::driver* driver;
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
