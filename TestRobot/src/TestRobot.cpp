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
		gsi::Thread::sleep(5);
		char* data = new char[512];
		uint32_t size = 512;
		uint8_t type = 0x01;
		uint8_t mode = 0x01;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		gsi::Thread::sleep(5);
		mode = 0x00;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		gsi::Thread::sleep(5);
		mode = 0x02;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		gsi::Thread::sleep(5);
		mode = 0x00;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		
		for(uint32_t i = 0; i < 5000; i++)
		{
		mode = 0x01;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		gsi::Thread::sleep(5);
		mode = 0x00;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		gsi::Thread::sleep(5);
		mode = 0x02;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		gsi::Thread::sleep(5);
		mode = 0x00;
		memset(data,0,512);
		memcpy(data,&size,4);
		memcpy(data + 4,&type,1);
		memcpy(data + 5,&mode,1);
		packet->parseData(data);
		}
	}
	private:
	RobotPacket* packet;
};


TestRobot::TestRobot()
{
	printf("Initializing Test Robot\n");
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
	printf("TestRobot::%s::%d: Disabled periodic\n",__INFO__);
}
void TestRobot::teleopInit()
{
	printf("TestRobot::%s::%d: Teleop init\n",__INFO__);
}
void TestRobot::teleopPeriodic()
{
	printf("TestRobot::%s::%d: Teleop periodic\n",__INFO__);
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
