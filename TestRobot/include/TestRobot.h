#pragma once

#include <stdio.h>
#include "gri/Robot.h"
#include "gri/RobotMain.h"
#include "gsu/Vector2D.h"

class TestRobot: public gri::Robot
{
	public:
	TestRobot();
	void disableInit();
	void disablePeriodic();
	void teleopInit();
	void teleopPeriodic();
	void autonomousInit();
	void autonomousPeriodic();
};


