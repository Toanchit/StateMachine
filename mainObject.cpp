#include "mainObject.h"
#include "statemachine.h"
using namespace std;
int main()
{
	mainObject *sp1 = new mainObject();
	sp1->processEvent(2);
		
	
	return 0;
}
