#include "barriere.h"

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
    if (nbArrives != nbThreads)
        while (nbArrives != nbThreads)
            cv.wait(l);
    else 
    {
        nbArrives = 0;
        cv.notify_all();
    }
}
