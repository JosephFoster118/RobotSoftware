#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "gri/RobotInclude.h"
#include "gsi/Mutex.h"
#include "gri/Module.h"

namespace gri
{

class DigitalIO: public Module
{
	public:
		DigitalIO();
		~DigitalIO();
		virtual void setValue(bool v) = 0;
		virtual bool getValue() = 0;
	protected:
		bool value;
	private:
		
};

}




