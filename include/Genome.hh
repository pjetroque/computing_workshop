#ifndef GenomeHeader
#define GenomeHeader

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

class Genome
{
    public:

    int innr, regnr, outnr; //number of input, regulatory anbd output nodes (just handy to have)

    vector <double> inputscale; //the scaling of the input layer: a multiplier before the data are sent to the regulatory layer
    vector < vector <double > > reglayer_input; // the regulatory inputs to the nodes in the regulatory layer (from input and reg layer)
    vector < vector <double > > outlayer_input; // the regulatory inputs to the nodes in the output layer (from regulatory layer)
    vector <double> thresholds; //activation thresholds for regulatory and output layers

    //constructor and destructor
    Genome();
    Genome(int in, int reg, int out);
    void InitGenome(int in, int reg, int out); //constructor body for handy init in classes
    ~Genome();
    Genome(const Genome &Parent); //copy constructor

    void PrintGenome(string filename); //makes a dot plot

    void MutateGenome(double mu, double mustd);
};

#endif