#include <gsi/TCPSocket.h>

// @TODO: create a network class to hold byte swap info

bool do_byte_swap = (1 != ntohs(1));

float hostToNetFloat(float val)
{
	return netToHostFloat(val);
}

float netToHostFloat(float val)
{
	if (do_byte_swap)
	{
		uint32_t in_val;
		float *fp = (float *)(&in_val);
		*fp = val;
		in_val = htonl(in_val);
		return (*fp);
	}
	else
	{
		return val;
	}
}

namespace gsi
{
	
	TCPSocket::TCPSocket()
	{
#if defined (PTHREADS)
		printf("Creating Socket\n");
		
#endif
		
	}
	
	TCPSocket::TCPSocket(uint16_t port, SocketType st)
	{
#if defined (PTHREADS)
		printf("Creating Socket\n");
		
#endif
	}
	
	
}


