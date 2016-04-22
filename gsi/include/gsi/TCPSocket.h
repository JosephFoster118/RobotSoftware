////
#pragma once



#pragma once

#include <exception>
#include <string>

#if defined (PTHREADS)
 
/* Bare nslookup utility (w/ minimal error checking) */
#include <stdio.h>          /* stderr, stdout */
#include <netdb.h>          /* hostent struct, gethostbyname() */
#include <arpa/inet.h>      /* inet_ntoa() to format IP address */
#include <netinet/in.h>     /* in_addr structure */
#include <string>
typedef void raw_type; // Type used for raw data on this platform

#elif defined(VXWORKS) || defined(_WRS_KERNEL)
#include <sys/types.h>       // For data types
#include <inetLib.h>
#include <selectLib.h>
#include <sockLib.h>
#include <usrLib.h>
#include <unistd.h>          // For close()//#include <netinet/in.h>      // For sockaddr_in
#include <string.h>
typedef char raw_type; // Type used for raw data on this platform

#elif defined(_WINDOWS)
#include <stdint.h>
#include <winsock.h>         // For socket(), connect(), send(), and recv()
typedef int socklen_t;
typedef char raw_type; // Type used for raw data on this platform

#pragma warning(disable : 4290)

#else

#endif


extern float netToHostFloat(float val);
extern float hostToNetFloat(float val);
namespace gsi
{
class TCPSocket
{
	public:
		enum SocketType
		{
			CLIENT = 0,
			SERVER
		};
		TCPSocket();
		TCPSocket(uint16_t port, SocketType st = CLIENT);
		
	
};



}

