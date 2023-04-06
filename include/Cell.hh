#ifndef CellHeader
#define CellHeader

#include <vector>
#include "Genome.hh"


class Cell{
    public:
    int cellid;
    int coordinates[2]; //x,y
    float nutrients[2]; //soil nutrients and energy
    float diffstates[2]; //diffstates of soil nutrients and energy
    
    //CELLSTATE
    vector <double> sensory;
    vector <bool> regnodes; //booleans should neatly convert to ints
    vector <bool> outnodes;

    vector<Cell*> neighbours;

    //Functions
    Cell(int id, int x, int y, Genome &G);
    ~Cell();
    Cell(const Cell &Parent);
    void update_cellstate(const Genome &G); //update the state of the cell network
};

#endif