#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "gri/RobotInclude.h"
#include "gsi/Mutex.h"

#define MAX_CONTROLLER_COUNT 6
#define MAX_AXIS_COUNT 12
#define MAX_BUTTON_COUNT 22

namespace gri
{
class Controller
{
	public:
		Controller();
		~Controller();
		typedef struct
		{
			double axis[MAX_AXIS_COUNT];
			uint8_t button[MAX_BUTTON_COUNT];
		}ControllerHolder;
		
		void parseControllerData(char* data);
		double getAxis(uint8_t cont, uint8_t number);
	private:
		ControllerHolder* controller;
		gsi::Mutex* mutex;
		
};
}






