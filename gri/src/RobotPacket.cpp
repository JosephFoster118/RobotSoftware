#include "gri/RobotPacket.h"

namespace gri
{
	RobotPacket::RobotPacket(gsu::Callback* cb)
	{
		callback = cb;
	}
	
	RobotPacket::~RobotPacket()
	{
		
	}
	
	bool RobotPacket::parseData(void* data)
	{
		printf("data recieved (%p)\n",data);
		//Parse Header
		uint8_t type;
		memcpy(&packet_size,data,4);
		memcpy(&type,POINTER_OFFSET(data,4),1);
		packet_type = static_cast<PacketType>(type);
		memcpy(packet_data,POINTER_OFFSET(data,5),packet_size);
		switch(packet_type)
		{
			case HEART_BEAT:
			{
				printf("RobotPacket::%s::%d: Hear beat recieved\n",__INFO__);
			}break;
			case MODE_CHANGE:
			{
				printf("RobotPacket::%s::%d: Mode change recieved\n",__INFO__);

			}break;
			case INFO:
			{
				printf("RobotPacket::%s::%d: Info recieved\n",__INFO__);
			}break;
			case CONTROLLER_DATA:
			{
				printf("RobotPacket::%s::%d: Controller data recieved\n",__INFO__);
			}break;
			case GUI_DATA:
			{
				printf("RobotPacket::%s::%d: Gui data recieved\n",__INFO__);
			}break;
			default:
			{
				printf("RobotPacket::%s::%d: Unknown packet type recieved\n",__INFO__);
			}break;
		}
		callback->callbackNetwork(NULL);
		
		
		return true;
	}
	
	uint32_t RobotPacket::getPacketSize()
	{
		return packet_size;
	}
	
	RobotPacket::PacketType RobotPacket::getPacketType()
	{
		return packet_type;
	}
	
	char* RobotPacket::getData()
	{
		return packet_data;
	}
	
}


