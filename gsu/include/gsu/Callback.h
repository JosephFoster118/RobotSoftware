#pragma once

namespace gsu
{

class Callback
{
	public:
	virtual void callback(void* param);
	virtual void callbackNetwork(void* param);
	virtual void callbackAction(void* param);
};

}

