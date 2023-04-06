
## Goal of workshop ##

To understand the structure of evolutionary simulations (will be discussed during talk)
What are the uses of these simulations and what are the types of outcome?

What is the output of a simulation? What are observables?
- fitness over time
- phenotype changes over time
- mechanism changes over time

## code structure ##

 World (with the population)

 Tree (agent)
  - cells
  - Boolean grid
  - light gradient
  
  #functions
  

Cell 
    - nutrient
    - energy
    - cell state
    - neighbours
    - position


## TODO

- storing the neighbours inside cells (make a function: updateneighbours)
- save ids in the agent grid to allow quick lookup of neighbours
- decide how to determine direction of cell division


## DONE
