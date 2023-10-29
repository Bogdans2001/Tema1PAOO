#include<iostream>
#include<string.h>
#include "tren.hpp"

using namespace std;

int main(){
    char ruta1[]="Bucuresti-Timisoara", ruta2[]="Bucuresti-Constanta";
    int dimensiune1=19, dimensiune2=19;
    int numere_vagoane1[]={434,433,4,3,2,1}, numere_vagoane2[]={1,2,3,4};
    int nr_vagoane1=6, nr_vagoane2=4;
    std::cout<<"Tren1:\n";
    Tren tren1=Tren(ruta1, dimensiune1, nr_vagoane1, numere_vagoane1);
    tren1.afisare();
    std::cout<<"Tren2:\n";
    Tren tren2=Tren(tren1);
    tren2.afisare();
    std::cout<<"Tren 3<-Tren2\n";
    Tren tren3(std::move(tren2));
    std::cout<<"Tren2:\n";
    tren2.afisare();
    std::cout<<"Tren3:\n";
    tren3.afisare();
    std::cout<<"Tren2:\n";
    tren2.adauga_vagon(4);
    tren2.afisare();
    std::cout<<"Tren4:\n";
    Tren tren4=Tren(ruta2, dimensiune2, nr_vagoane2, numere_vagoane2);
    tren4.afisare();
    std::cout<<"Tren4:\n";
    tren4.adauga_vagon(5);
    tren4.afisare();
    std::cout<<"Tren4:\n";
    tren4.adauga_vagon(5);
    tren4.afisare();
    std::cout<<"Tren4:\n";
    tren4.sterge_vagon(5);
    tren4.afisare();
    std::cout<<"Tren4:\n";
    tren4.sterge_vagon(5);
    tren4.afisare();
    std::cout<<"Tren4:\n";
    tren4.sterge_vagon(2);
    tren4.afisare();
    std::cout<<"Tren4:\n";
    tren4.schimba_ruta("Timisoara->Cluj",15);
    tren4.afisare();
    return 0;
}