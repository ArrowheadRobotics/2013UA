#include "gate.h"
#include "../Robotmap.h"
#include "../Robot.h"
gate::gate() : Subsystem("gate") {
	sol1 = RobotMap::gatesol1;
	sol2 = RobotMap::gatesol2;
}
    
void gate::InitDefaultCommand() {

}

void gate::toggle(){
	if(Robot::gate->sol1->Get()==true){
		Robot::gate->sol1->Set(false);
		Robot::gate->sol2->Set(true);
	}else{
		Robot::gate->sol1->Set(true);
		Robot::gate->sol2->Set(false);
	}
}
