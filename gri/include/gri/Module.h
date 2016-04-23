#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "gri/RobotInclude.h"
#include "gsi/Mutex.h"

#define MODULE_NAME_SIZE 128

namespace gri
{

class Module
{
	public:
	Module();
	~Module();
	
	protected:
	char module_name[MODULE_NAME_SIZE];
	private:
	
	static Module* getModule(std::String n);
	
};



}






