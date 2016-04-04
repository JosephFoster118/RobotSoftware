#include "gri/Controller.h"


namespace gri
{

Controller::Controller()
{
	controller = new ControllerHolder[MAX_CONTROLLER_COUNT];
	for(uint16_t i = 0; i < MAX_CONTROLLER_COUNT; i++)
	{
		memset(&controller[i],0,sizeof(ControllerHolder));
	}
	printf("Controller::%s::%d: Controller initialized\n",__INFO__);
	mutex = new gsi::Mutex();
}

void Controller::parseControllerData(char* data)
{
	mutex->lock();
	uint8_t controller_count = 0;
	uint32_t offset = 0;
	memcpy(&controller_count,POINTER_OFFSET(data,offset),1);
	//printf("Controller::%s::%d: Controller Count [%d]\n",__INFO__,controller_count);
	offset += 1;
	//set controller data
	if(controller_count <= MAX_CONTROLLER_COUNT)
	{
		for(uint8_t i = 0; i < controller_count; i++)
		{
			uint8_t axis_count = 0;
			uint8_t button_count = 0;
			memcpy(&axis_count,POINTER_OFFSET(data,offset),1);
			offset += 1;
			memcpy(&button_count,POINTER_OFFSET(data,offset),1);
			offset += 1;
			//printf("Controller::%s::%d: Controller [%d], Axis count [%d], Button count [%d]\n",
			//__INFO__,i,axis_count,button_count);
			memcpy(controller[i].axis,POINTER_OFFSET(data,offset),sizeof(double)*axis_count);
			
			offset += sizeof(double)*axis_count;
			memcpy(controller->button,POINTER_OFFSET(data,offset),button_count);
			offset += button_count;
		}
	}
	mutex->unlock();
}

double Controller::getAxis(uint8_t cont, uint8_t number)
{
	mutex->lock();
	double result = controller[cont].axis[number];
	mutex->unlock();
	return result;
}

}
