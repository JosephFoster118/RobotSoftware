#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "gri/RobotInclude.h"
#include "gsi/Mutex.h"
#include "gri/Module.h"
#include "gri/DigitalIO.h"

#define GPIO_FILE_NAME_LENGTH 128

namespace gri
{

class GPIO: public DigitalIO
{
	public:
		GPIO(uint8_t id);
		~GPIO();
		void setValue(bool v);
		bool getValue();
	private:
		FILE* handle;
		char value_file_name[GPIO_FILE_NAME_LENGTH];
		bool is_out;
};

}


