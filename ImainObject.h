#ifndef _I_MAIN_OBJECT_
#define _I_MAIN_OBJECT_
#include <iostream>
#include <string>
using namespace std;
class ImainObject
{
	public : 
	ImainObject();
	 ~ImainObject();
	void handleEventOnIdle();
	void handleStateOnIdle()  ;
	void handleEventOnRunning() ;
	void handleStateOnRunning() ;
};
#endif
