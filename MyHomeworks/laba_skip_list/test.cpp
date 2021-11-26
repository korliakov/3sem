#include <iostream>
#include <random>


	int RandLevel(int lvl_max, float p = 0.99) {

		std::random_device rd; // obtain a random number from hardware
    	std::mt19937 gen(rd()); // seed the generator
    	std::uniform_int_distribution<> distr(0, 10000);
    	float k = (float)distr(gen) / (10000);

		int lvl = 0;
		while (k <= p && lvl < lvl_max) {

			lvl++;
			k = (float)distr(gen) / (10000);
		}

		return lvl;

	}



int main()
{
    

	std::cout << RandLevel(1000);

}