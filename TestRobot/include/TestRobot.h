#pragma once

#include <stdio.h>
#include "gri/Robot.h"
#include "gri/Controller.h"
#include "gri/RobotMain.h"
#include "gri/GPIO.h"
#include "gsu/Vector2D.h"
#include <math.h>

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
	private:
	gri::Controller* controller;
	gri::GPIO* test_out1;
	gri::GPIO* test_out2;
	uint32_t cnt;
};


