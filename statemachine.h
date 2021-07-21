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
		mstateIdle = new stateIdle(sp);
		mstateRunning = new stateRunning(sp);
		mCurrentState = mstateIdle;
	}
	~statemachine();
	void processEvent(int t)
	{
		mCurrentState->processEvent(t);
	}
	void transferNextState(statebase next); 
	class stateIdle : public statebase
	{
		public: 
		stateIdle(ImainObject &sp): statebase(sp){} ;
		virtual ~stateIdle();
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
		virtual ~stateRunning();
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
	stateIdle *mstateIdle;
	stateRunning *mstateRunning;
	statebase *mCurrentState;
 };
 #endif
