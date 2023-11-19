#include<iostream>
#include<string.h>
#include "tren.hpp"
#include "tren_calatori.hpp"
#include "tren_marfa.hpp"

int main(){
    char ruta1[]="Bucuresti-Timisoara", ruta2[]="Bucuresti-Constanta";
    char produs1[]="mere";
    int dimensiune1=19, dimensiune2=19;
    int numere_vagoane1[]={434,433,4,3,2,1}, numere_vagoane2[]={1,2,3,4};
    int nr_vagoane1=6, nr_vagoane2=4;
    Vehicul::Tren_Marfa tren_marfa1=Vehicul::Tren_Marfa(ruta1, dimensiune1, nr_vagoane1, numere_vagoane1, 100, produs1, 4);
    return 0;
}