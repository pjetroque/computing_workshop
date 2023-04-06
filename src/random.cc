//random.cpp
#include <stdio.h>
#include <iostream>
#include <chrono>
#include "random.hh"
#include "parameters.hh"

extern Parameter par;

//std::mt19937 my_rng {}; 
std::mt19937_64 my_rng {}; // Defines an engine
std::uniform_real_distribution<double> my_unif_real_dist(0., 1.); //Define distribution
std::normal_distribution<double> normal_1_005(1.0, 0.05);
// Function to seed the random number generator from main file
// useful if you want the seed from a parameter file
// a negative value for seed gets you a random seed
// outputs the seed itself
int Seed(int seed)
{
  if (seed < 0) {
    long rseed=static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::cerr << "Randomizing random generator, seed is "<<rseed<<std::endl;
    my_rng.seed(rseed);
    return rseed;
  } else {
    std::cerr << "User-provided seed is "<<seed<<std::endl;
    my_rng.seed(seed);
    return seed;
  }
}
// This is the function to call if you want a random number in the interval [0,1)
double uniform(void)
{
  return my_unif_real_dist(my_rng);
}

double tr_noise(void){
  return normal_1_005(my_rng);
}

double returnNormal(double mean, double stdev)
{
  static int spareavailable=0;
  static double spare=0.;
  double val1, val2;
  double s, fac;
  if(spareavailable){
    spareavailable=0;
    return mean +spare*stdev;
  }
  else{
    do{
      
      val1=uniform()*2. -1.;
      val2=uniform()*2. -1.;
      s=val1*val1+val2*val2;
      
    }while (s>=1.||s==0);
    
    fac=sqrt((-2.*log(s))/s);
    
    spare=val1*fac;
    spareavailable=1;
    return mean+val2*fac*stdev;

  }
}