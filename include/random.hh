// random.h
#ifndef _RND_HH_
#define _RND_HH_

#include <random> //--- FOR THIS YOU NEED c++11, enable with -std=c++11 flag

// Declare engine - single instance for the whole code
//extern std::mt19937 my_rng;
extern std::mt19937_64 my_rng;

//Declare distributions:
extern std::uniform_real_distribution<double> my_unif_real_dist;
//extern std::uniform_int_distribution<double> my_unif_int_dist;
extern std::normal_distribution<double> normal_1_005;
int Seed(int seed);
double uniform();
double tr_noise();
double returnNormal(double mu, double stdev);
#endif 