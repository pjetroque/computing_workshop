#include "stdio.h"
#include <stdlib.h> 
#include "Cell.hh"
#include "Genome.hh"

Cell::~Cell(){
}

Cell::Cell(int id, int x, int y, Genome &G)
{
    cellid=id;
    coordinates[0]=x;
    coordinates[1]=y;

    nutrients[0]=0.;
    nutrients[1]=0.;


    //set input states
    for(int i=0; i<G.innr; i++){
        sensory.push_back(0.);
    }

    for(int i=0; i<G.regnr; i++){
        regnodes.push_back(0);
    }

    for(int i=0; i<G.outnr; i++){
        outnodes.push_back(0);
    }

}

Cell::Cell(const Cell &Parent)
{
    //id and coordinates should be set elsewhere
    nutrients[0]=Parent.nutrients[0];
    nutrients[1]=Parent.nutrients[1];
    //set input states
    sensory=Parent.sensory;
    regnodes=Parent.regnodes;
    outnodes=Parent.outnodes;
}

void Cell::update_cellstate(const Genome &G)
{
    
    double newval;
    vector <bool> newreg; //to keep the new states for the regulatory layer while updating this layer (they can cross regulate, use old state for that)
    
    //filter input data with evolved weights
    for (int i=0; i<sensory.size(); i++){
        sensory[i]=G.inputscale[i]*nutrients[i];
    }

    //update regulatory nodes
    for (int i=0; i<regnodes.size(); i++){
        newval=0.;
        
        //inputs from sensory layer
        for (int j=0; j<sensory.size(); j++){
            newval+=sensory[j]*G.reglayer_input[i][j];
        }
        //inputs from regulatory layer
        for (int j=0; j<regnodes.size(); j++){
            newval+=regnodes[j]*G.reglayer_input[i][j+sensory.size()];
        }
        if(newval>G.thresholds[i]){
            newreg.push_back(1);
        }else{
            newreg.push_back(0);
        }
    }
    //now update the nodes
    regnodes=newreg;

    //update output nodes
    for (int i=0; i<outnodes.size(); i++){
        newval=0.;
        //inputs from regulatory layer
        for (int j=0; j<regnodes.size(); j++){
            newval+=regnodes[j]*G.outlayer_input[i][j];
        }
        if(newval>G.thresholds[i+regnodes.size()]){
            outnodes[i]=1;
        }else{
            outnodes[i]=0;
        }

    }
}
