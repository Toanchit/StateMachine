#ifndef _STATE_BASE_H_
#define _STATE_BASE_H_
#include<iostream>
#include "ImainObject.h"
using namespace std;
class statebase 
{
	protected:
	ImainObject &mSp;
	public:
	statebase(ImainObject &sp) : mSp(sp) {};
	virtual void processEvent(int t) = 0;
	virtual void enter() = 0;
	virtual void exit() = 0;
		
};

#endif
