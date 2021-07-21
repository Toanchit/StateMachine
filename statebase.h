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
	virtual ~statebase();
	virtual void processEvent(int t);
	virtual void enter();
	virtual void exit();
		
};

#endif
