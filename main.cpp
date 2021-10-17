#include "barriere.h"
#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <string>
#include <sys/time.h>
using namespace std;

int fibonacci (int n)
{
  int f0 = 1;
  int f1 = 1;
  int temp;
  for (int i = 2; i <= n; i++)
  {
    temp = f0 + f1;
    f0 = f1;
    f1 = temp;
  }
  return f1;
}

void tache (int numThread, int numTour)
{
    struct timeval tv1, tv2;
    int err;
    err = gettimeofday(&tv1,NULL);
    std::cout << "Heure début " << tv1.tv_usec << endl;
    int rangFibonacci = rand() % 10 + 10;
    int fibo = fibonacci(rangFibonacci);
    err = gettimeofday(&tv2,NULL);
    int duree = tv2.tv_usec - tv1.tv_usec;
    cout << "Thread " << numThread << ", tour " << numTour << ": " << duree << endl;
}

void fct (int numThread, int nbTours, Barriere &b)
{
    for (int i = 1; i<= nbTours; i++)
    {
        cout << "thread " << numThread << " début tour " << i << endl;
        tache (numThread, i);
        b.attenteBarriere();
        cout << "thread " << numThread << " fin tour " << i << endl;
    }
}

int main()
{
    int nbThreads, nbTours;
    cout << "Combien de threads? ";
    cin >> nbThreads;
    cout << "Combien de tours? ";
    cin >> nbTours;

    thread tab[nbThreads];
    Barriere b(nbThreads);
    for (int i=0; i<nbThreads; i++) 
    {
        // création des threads en appelant la fonction fct
        tab[i] = thread(fct, i, nbTours, ref(b));
    }

  // on attend les threads
  for (int i=0; i<nbThreads; i++) {
    tab[i].join();
  }
  return 0;
}
