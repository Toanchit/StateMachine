#include "mainObject.h"
#include "statemachine.h"
int main()
{
	mainObject *sp1 = new mainObject();
	while (1)
	{
		int t;
		std::cout << "action: " <<std::endl;
		cin >> t;
		sp1->processEvent(t);
	}
}
