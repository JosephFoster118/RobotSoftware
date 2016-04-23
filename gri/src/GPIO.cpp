#include "gri/GPIO.h"

namespace gri
{

GPIO::GPIO(uint8_t id)
{
	handle = NULL;
	char buffer[GPIO_FILE_NAME_LENGTH];
	memset(buffer,0,GPIO_FILE_NAME_LENGTH);
	memset(value_file_name,0,GPIO_FILE_NAME_LENGTH);
	//sprintf(buffer,"")
	handle = fopen("/sys/class/gpio/export","w");
	if(handle != NULL)
	{
		fprintf(handle,"%d",id);
		fclose(handle);
		handle = NULL;
		sprintf(buffer,"/sys/class/gpio/gpio%d/direction",id);
		handle = fopen(buffer,"w+");
		if(handle != NULL)
		{
			fprintf(handle,"high");
			fclose(handle);
			handle = NULL;
			sprintf(value_file_name,"/sys/class/gpio/gpio%d/value",id);
		}
		else
		{
			printf("GPIO::%s::%d:ERROR: GPIO with id %d does not exist\n",__INFO__,id);
		}
	}
	else
	{
		printf("GPIO::%s::%d:ERROR: Fatal GPIO Error\n",__INFO__);
	}
	
}

GPIO::~GPIO()
{
	//TODO: Create ~GPIO()
}

void GPIO::setValue(bool v)
{
	value = v;
	handle = fopen(value_file_name,"w");
	if(handle != NULL)
	{
		fprintf(handle,"%d",v);
		fclose(handle);
		handle = NULL;
	}
	
}

bool GPIO::getValue()
{
	handle = fopen(value_file_name,"r");
	if(handle != NULL)
	{
		fscanf(handle,"%i",&value);
		fclose(handle);
		handle = NULL;
	}
	return value;

}

}


