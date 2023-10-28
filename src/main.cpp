#include<iostream>
#include<string.h>
#include "tren.hpp"

using namespace std;

int main(){
    char ruta1[]="Bucuresti-Timisoara", ruta2[]="Bucuresti-Constanta";
    int dimensiune1=19, dimensiune2=19;
    int numere_vagoane1[]={434,433,4,3,2,1}, numere_vagoane2[]={1,2,3,4};
    int nr_vagoane1=6, nr_vagoane2=4;
    Tren tren1=Tren(ruta1, dimensiune1, nr_vagoane1, numere_vagoane1);
    tren1.afisare();
    Tren tren2=Tren(tren1);
    Tren tren3=std::move(tren2);
    Tren tren4=Tren(ruta2, dimensiune2, nr_vagoane2, numere_vagoane2);
    tren2.afisare();
    tren3.afisare();
    tren4.afisare();
    tren1.adauga_vagon(5);
    tren1.afisare();
    tren3.sterge_vagon(5);
    tren3.afisare();
    tren3.sterge_vagon(2);
    tren3.afisare();
    return 0;
}