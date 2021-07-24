#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H
#include<iostream>
#include "statebase.h"
using namespace std;

class statemachine
{
public:
	statemachine(ImainObject &sp) 
	{
		mstateIdle = std::make_shared<stateIdle>(sp);
		mstateRunning = std::make_shared<stateRunning>(sp);
		mCurrentState = mstateIdle;
	}
	void processEvent(int t)
	{
		mCurrentState->processEvent(t);
	}
	class stateIdle : public statebase
	{
		public: 
		stateIdle(ImainObject &sp): statebase(sp){} ;
		void processEvent(int n)
		{
			if(n == 1)
			{
				mSp.handleEventOnIdle();
			}
			if(n == 2)
			{
				mSp.handleStateOnIdle();
			}
		 } 
		void enter()
		{
			cout<<"Enter to Idle state";
			}	
		void exit()
		{
			cout<<"exit from Idle state";
		}
	};
	class stateRunning : public statebase
	{
		public:
		stateRunning(ImainObject &sp): statebase(sp){
		} ;
		void processEvent(int n)
		{
			
		 } 
		void enter()
		{
			cout<<"Enter to Running state";
			}	
		void exit()
		{
			cout<<"exit from Running state";
		}
	};
private :  
	std::shared_ptr<stateIdle> mstateIdle;
	std::shared_ptr<stateRunning> mstateRunning;
	std::shared_ptr<statebase> mCurrentState;
 };
 #endif
