---The format of Robot Packets---


+HEADER *Describes the contents of the message* (5 bytes)
	-uint32: package size
	-uint8: Type of package
+HEADER END

---Types of packages---
0x00:	Heart Beat
	A small message to let the reciever know
	a connection is still alive
0x01:	Mode Change
0x02:	Info
0x03:	Controller Data
0x04:	Gui Data

---Controller Data Structure---

uint8_t: controller count
[Dynamic Size (3 + 8*[axis count] + (button count)] --Controller--
	uint8_t: axis count
	uint8_t: button count
	[Dynamic Size (8*[axis count])] --Axes--
		double: axis value
	[Dynamic Size (button count)] --buttons--
		uint8_t: button value
		

