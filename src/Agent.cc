#include "stdio.h"
#include <stdlib.h> 
#include "Agent.hh"
#include "parameters.hh"
#include "Genome.hh"

extern Parameter par;

Agent::Agent(){
}

Agent::~Agent(){
}

void Agent::InitAgent(){
    //init a genome
    genome.InitGenome(2, 3, 2);

    //make our initial cell in the middle of the bottom layer
    cells.emplace_back(make_unique<Cell>(0, par.width/2, 0, genome));
    cellgrid[0][par.width/2] = 1;

    //make initial light grid
    float lightval;
    for(int i=0; i<par.height; i++){
        lightval = 90*i/par.height + 10;
        for(int j=0; j<par.width; j++){
            lightgrid[i][j] = lightval;
        }
    }
}

void Agent::MakeAgentFromParent(Agent &A, int agentid)
{
    InitAgent();
    genome=A.genome;
    genome.MutateGenome(par.mutate_mu, par.mutate_mustd);
}

void Agent::Develop(int steps){
    //1: update cell states for all cells
    //2: update nutrient state all cells (influx + diffusion)
    //3: update energy state all cells   (f(light)+diffusion)
    int step;
    int x;
    int y;
    int nr_nb;
    for(step=0;step<steps;step++){
        //update cell states
        update_intracellstate();

        //update nutrient states and energy states
        for(auto &cell: cells){
            x = cell->coordinates[0];
            y = cell->coordinates[1];
            if(y==0){
                cell->nutrients[0] += par.nutrient_influx; //nutrients
            }
            cell->nutrients[1] += lightgrid[y][x]*0.1;     //energy
        }

        //compute diffusion nutrient states and energy states
        for(auto &cell: cells){
            cell->diffstates[0] = 0;
            cell->diffstates[1] = 0;
            nr_nb=0;
            for(auto &nb: cell->neighbours){
                cell->diffstates[0] += nb->nutrients[0];
                cell->diffstates[1] += nb->nutrients[1];
                nr_nb++;
            }
            cell->diffstates[0]-= nr_nb*cell->nutrients[0];
            cell->diffstates[1]-= nr_nb*cell->nutrients[1];
        }

        //finish diffusion nutrient and energy states
        for(auto &cell: cells){
            cell->nutrients[0] += cell->diffstates[0]*par.D_nutrients;
            cell->nutrients[1] += cell->diffstates[1]*par.D_energy;
        }

        //check if cells can divide
        Divide_cells();
    }
}

void Agent::UpdateNeighbours(Cell *cell){
    int x = cell->coordinates[0];
    int y = cell->coordinates[1];

    if(cellgrid[y+1][x]!=0){

    }
    if(cellgrid[y-1][x]!=0){

    }
    if(cellgrid[y][x+1]!=0){

    }
    if(cellgrid[y][x-1]!=0){

    }
}


void Agent::Divide_cells(){
    for(auto &cell: cells){
        int x = cell->coordinates[0];
        int y = cell->coordinates[1];
        int xnew = x;
        int ynew = y+1;

        //check grid EXAMPLE
        if(cellgrid[y+1][x] == 0){
            //new cell
            cells.emplace_back(make_unique<Cell>(cells.size(), xnew, ynew, genome));
            //do something with parent states
        };
    }
}

void Agent::update_intracellstate()
{
    for (auto &c: cells){
        c->update_cellstate(genome);
    }
}