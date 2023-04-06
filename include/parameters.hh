#ifndef ParametersHeader
#define ParametersHeader

#include "Cell.hh"
#include "stdlib.h"


using namespace std;

class Parameter{
public:
    static const int width = 20;
    static const int height = 10;
    int steps;
    float nutrient_influx;
    float energy_synthesis;
    double mutate_mu;
    double mutate_mustd;
    float D_nutrients; //diffusion speed nutrients
    float D_energy;    //diffusion speed energy

    Parameter();
    ~Parameter();

    void SetParameters();
};

#endif