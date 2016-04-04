#include "TestRobot.h"

using namespace gri;
using namespace gsu;


class tester: public gsi::Thread
{
	public:
	tester(RobotPacket* p)
	{
		packet = p;
	}
	
	void run()
	{
		gsi::Thread::sleep(2.0);
		//Enable robot
		char* data = new char[512];
		uint32_t size = 512;
		uint8_t type = 0x01;
		uint8_t mode = 0x01;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		//Send controller packets
		for(uint32_t i = 0; i < 300000; i++)
		{
		memset(data,0,512);
		size = 52;
		type = 0x03;
		uint8_t controller_cnt = 1;
		uint8_t axis_count = 2;
		uint8_t button_count = 0;
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&controller_cnt,1);
		memcpy(data + 6,&axis_count,1);
		memcpy(data + 7,&button_count,1);
		
		uint32_t offset = 8;
		double axis_value_1 = sin(((double(i)*R_PI*2.0)*0.01)/4.0);
		double axis_value_2 = cos(((double(i)*R_PI*2.0)*0.01)/4.0);
		memcpy(data + offset,&axis_value_1,sizeof(double));
		offset += 8;
		memcpy(data + offset,&axis_value_2,sizeof(double));
		offset += 8;
		packet->parseData(data);
		gsi::Thread::sleep(0.01);
		}
		
		
		gsi::Thread::sleep(50000);
		//Disable robot
		type = 0x01;
		mode = 0x00;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		gsi::Thread::sleep(5);
		
	}
	private:
	RobotPacket* packet;
};


TestRobot::TestRobot()
{
	printf("Initializing Test Robot\n");
	controller = getController();
	//Test Vector2D
	//copy
	Vector2D* vect = new Vector2D(25.2,3.58);
	Vector2D* clone = new Vector2D(3.0,3.0);
	*vect = *clone;
	printf("Values: (%.3f,%.3f), (%.3f,%.3f)\n",vect->getX(),vect->getY(),clone->getX(),clone->getY());
	delete vect;
	delete clone;
	
	vect = new Vector2D();
	Vector2D* vect_a = new Vector2D(1.0,2.0);
	Vector2D* vect_b = new Vector2D(5.0,3.0);
	Vector2D* vect_c = new Vector2D(2.0,9.0);
	*vect = *vect_a + *vect_b + *vect_c;
	printf("Values: (%.3f,%.3f)\n",vect->getX(),vect->getY());
	*vect = *vect_a - *vect_b - *vect_c;
	printf("Values: (%.3f,%.3f)\n",vect->getX(),vect->getY());
	tester* test = new tester(getRobotPacket());
	test->start();
}


void TestRobot::disableInit()
{
	printf("TestRobot::%s::%d: Disabled init\n",__INFO__);
}
void TestRobot::disablePeriodic()
{
	//printf("TestRobot::%s::%d: Disabled periodic\n",__INFO__);
}
void TestRobot::teleopInit()
{
	printf("TestRobot::%s::%d: Teleop init\n",__INFO__);
}
void TestRobot::teleopPeriodic()
{
	printf("TestRobot::%s::%d: Controller Data: axis0[%+.4f] axis1[%+.4f]\n",__INFO__,
		controller->getAxis(0,0),
		controller->getAxis(0,1));
}
void TestRobot::autonomousInit()
{
	printf("TestRobot::%s::%d: Auton init\n",__INFO__);
}
void TestRobot::autonomousPeriodic()
{
	printf("TestRobot::%s::%d: Auton periodic\n",__INFO__);
}

REGISTER_ROBOT(TestRobot);
