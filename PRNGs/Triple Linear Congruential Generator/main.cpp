#include <iostream>
#include <chrono>
#include <random>
using namespace std;
int main ()
{
	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
	unsigned seed3 = std::chrono::system_clock::now().time_since_epoch().count();
	std::minstd_rand0 g1 (seed1);
	std::minstd_rand0 g2 (seed2);
	std::minstd_rand0 g3 (seed3);
	int range = 20 - 10;
	for (int i=0; i<30; i++)
	std::cout << "A time seed produced: " << (g1()+g2()+g3())%range+10 << std::endl;
  return 0;
}
