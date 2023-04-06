#ifndef AgentHeader
#define AgentHeader

#include "Cell.hh"
#include "Genome.hh"
#include "parameters.hh"
#include "stdlib.h"
#include <vector>
#include <memory>
// #include <unique_ptr>


using namespace std;
extern Parameter par;

class Agent{
    public:
    std::vector<unique_ptr<Cell>> cells;
    int width;  //width of simulation grid
    int height; //height of simulation grid
    int lightgrid[par.height][par.width] = {};
    int cellgrid[par.height][par.width] = {};
    float fitness;

    Genome genome;

    //Functions
    Agent();
    ~Agent();

    void InitAgent();
    void Develop(int steps); //develop agent for N steps
    void Divide_cells();
    void UpdateNeighbours(Cell *cell);

    void MakeAgentFromParent(Agent &A, int agentid);

    void update_nutrients(); //cells in layer 0 get influx of nutrients and nutrients diffuse
    void update_energy();    //cells get energy based on light, cells share energy
    void update_celldivision(); //cells can diffusie if nutrients + energy > threshold
    void update_lightgradient();//update the lightgradient after changes in morphology and new shade
    void update_intracellstate(); //update the internal node state of cells
};

#endif