#ifndef ROBOT_PACKET_H
#define ROBOT_PACKET_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "RobotInclude.h"
#include "gsu/Callback.h"

#define POINTER_OFFSET(start, offset) ((char *) start + (offset))

namespace gri
{
	

	
class RobotPacket
{
	public:
		RobotPacket(gsu::Callback* cb);
		~RobotPacket();
		
		enum PacketType
		{
			HEART_BEAT = 0x00,
			MODE_CHANGE = 0x01,
			INFO = 0x02,
			CONTROLLER_DATA = 0x03,
			GUI_DATA = 0x04
		};
		PacketType getPacketType();
		uint32_t getPacketSize();
		bool parseData(void* data);
		char* getData();
	private:
		uint32_t packet_size;
		PacketType packet_type;
		gsu::Callback* callback;
		char packet_data[1024];
		
};

}




#endif
