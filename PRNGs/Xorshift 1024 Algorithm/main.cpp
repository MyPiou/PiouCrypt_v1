#include <iostream>
#include "PRNG.h"
using namespace std;
int main()
{
	PRNG rng;
	for(int i=0; i<50; i++)
		cout << rng.getRandomInt(0, 100) << endl;
}