#ifndef _MAIN_OBJECT_H_
#define _MAIN_OBJECT_H_
#include "ImainObject.h"
#include "statemachine.h"
#include <stdio.h>


class mainObject : public ImainObject
{
	public : 
		statemachine *sp1;
		mainObject()
		{
			sp1 = new statemachine(*this);
		}
		void processEvent(int n)
		{
			std::cout<<"Event = "<<n<<std::endl;
			sp1->processEvent(n);
		}
		void handleEventOnIdle()
		{
			std::cout<<"Handle event on IDle"<<endl;
		}
		void handleStateOnIdle() 
		{
			std::cout<<"Handle state in Idle" << endl;
		}
		void handleEventOnRunning()
		{
			std::cout<<"Handle event on Running" << endl;
		}
		void handleStateOnRunning()
		{
			std::cout<<"Handle state on running" << endl;
		}
} ;
#endif

