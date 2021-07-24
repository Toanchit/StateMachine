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
		if (mCurrentState->processEvent(t))
		{
			transferState();
		}
		else
		{
			std::cout << "Do transfer state" << std::endl;
		}
		
	}

	void transferState()
	{
		switch (mCurrentState->state)
		{
		case 1:
		{
			mCurrentState->exit();
			mCurrentState = mstateIdle;
			mCurrentState->enter();
			break;
		}
		case 2:
		{
			mCurrentState->exit();
			mCurrentState = mstateRunning;
			mCurrentState->enter();
			break;
		}
		default:
			break;
		}
	}

	class stateIdle : public statebase
	{
		public: 
		stateIdle(ImainObject &sp): statebase(sp){} ;
		bool processEvent(int n)
		{
			switch (n)
			{
			case 1 :
			{
				mSp.handleEventOnIdle();
				return false;
			}
			case 2 :
			{
				mSp.handleStateOnIdle();
				state = 2;
				return true;
			}
			default:
				return false;
			}
			
		}
		void enter()
		{
			cout<<"Enter to Idle state"<<endl;
			}	
		void exit()
		{
			cout << "exit from Idle state" << endl;
		}
	};
	class stateRunning : public statebase
	{
		public:
		stateRunning(ImainObject &sp): statebase(sp){
		} ;
		bool processEvent(int n)
		{
			switch (n)
			{
			case 3:
			{
				mSp.handleEventOnRunning();
				return false;
			}
			case 4:
			{
				mSp.handleStateOnRunning();
				state = 1;
				return true;
			}
			default:
				return false;
			}
			
		 } 
		void enter()
		{
			cout << "Enter to Running state" << endl;
			}	
		void exit()
		{
			cout << "exit from Running state" << endl;
		}
	};
private : 
	std::shared_ptr<stateIdle> mstateIdle;
	std::shared_ptr<stateRunning> mstateRunning;
	std::shared_ptr<statebase> mCurrentState;
 };
 #endif
