#include "barriere.h"
#include <iostream>

using namespace std;


Barriere::Barriere(int n)
{
    nbThreads = n;
    nbArrives = 0;
}

Barriere::~Barriere() {}

void Barriere::attenteBarriere()
{
    unique_lock<mutex> l(m);
    ++nbArrives;
    while (nbArrives != nbThreads) 
    {
        cv.wait(l);
    }
    
    if(nbArrives == nbThreads)
    {
        cv.notify_all();
    }

    nbArrives=0;
    
    
}
