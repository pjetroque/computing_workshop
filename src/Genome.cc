#include "Genome.hh"
#include "random.hh"

//default constructor required for init in other class
Genome::Genome()
{
  innr=0;
  regnr=0;
  outnr=0;
}

Genome::Genome(int in, int reg, int out)
{
  InitGenome(in, reg, out);
}

void Genome::InitGenome(int in, int reg, int out)
{
  int i,j;

  innr=in;
  regnr=reg;
  outnr=out;

  //how to scale the input
  for(i=0; i<innr; i++){
    inputscale.push_back(0.1);
  }

  for (i=0; i<reg; i++){
    reglayer_input.push_back(vector<double>());
    thresholds.push_back(0.);
    for (j=0; j<in+reg; j++){
        reglayer_input[i].push_back(0.0); 
    }
  }

  for (i=0; i<out; i++){
    outlayer_input.push_back(vector<double>());
    thresholds.push_back(0.);
    for (j=0; j<reg; j++){
        outlayer_input[i].push_back(0.);
    }
  }

}

Genome::~Genome()
{
 //cout<<"destructed"<<endl;
}
//copy constructor
Genome::Genome(const Genome &Parent)
{
  innr=Parent.innr;
  regnr=Parent.regnr;
  outnr=Parent.outnr;

  inputscale=Parent.inputscale;
  //inputnodes=Parent.inputnodes;
  reglayer_input=Parent.reglayer_input;
  outlayer_input=Parent.outlayer_input;
  thresholds=Parent.thresholds;
}

void Genome::MutateGenome(double mu, double mustd)
{
    int i,j;

    for(auto &n: inputscale){
        if(uniform()<mu){
            n+=returnNormal(0., mustd);
        }
    }

    for (auto &n: reglayer_input){
        for(auto &p: n){
            if(uniform()<mu){ //if this parameter mutates
                p+=returnNormal(0., mustd); //then pull a normally distributed mutation
            }
        }
    }

    for (auto &n: outlayer_input){
        for(auto &p: n){
            if(uniform()<mu){
                p+=returnNormal(0., mustd);
            }
        }
    }

    for (auto &n: thresholds){
        if(uniform()<mu){
            n+=returnNormal(0., mustd);
        
        }

    }
}

void Genome::PrintGenome(std::string filename)
{

    std::ofstream ofs;
    ofs.open( filename , std::ofstream::out);
    
    ofs << "[";

    ofs << innr<<", "<<regnr<<", "<<outnr;   

    for (auto &n: inputscale){
        ofs<< ", "<< n;
    }

    for (auto&n: thresholds){
        ofs <<", "<< n;
    }

    for (auto &n: reglayer_input){
        for(auto &p: n){
            ofs <<", "<< p;
        }
    }

    for (auto &n: outlayer_input){
        for(auto &p: n){
            ofs <<", "<< p;
        }         
            i++;
    }

    ofs << "]"<<endl;

    ofs.flush();
    ofs.close();
}