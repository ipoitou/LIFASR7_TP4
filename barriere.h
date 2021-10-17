

#ifndef _BARRIERE
#define _BARRIERE
#include <mutex>
#include <condition_variable>

using namespace std;

class Barriere
{
	private:
		mutex m;
		condition_variable cv;
		int nbThreads;
		int nbArrives;

    public :
    //Constructeur-------------------------------------------------------------
    Barriere(const int nb);
    //Postcondition :  barriere créée avec nbThreads initialisé
    
    //Destructeur---------------------------------------------------------------
    ~Barriere();
     //Postcondition : l'espace occupé par *this  peut-être restitué
    
    //Fonction---------------------------------------------------------------
    void attenteBarriere();
};


#endif
