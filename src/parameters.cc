#include "parameters.hh"

Parameter par;

Parameter::~Parameter(){
}

// Default parameter values specified in the constructor
Parameter::Parameter() {
    steps = 10;
}
