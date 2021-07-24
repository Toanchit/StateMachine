#ifndef _I_MAIN_OBJECT_
#define _I_MAIN_OBJECT_
#include <iostream>
#include <string>
using namespace std;
class ImainObject
{
	public : 
	virtual void handleEventOnIdle() = 0;
	virtual void handleStateOnIdle() = 0;
	virtual void handleEventOnRunning() = 0;
	virtual void handleStateOnRunning() = 0;
};
#endif
