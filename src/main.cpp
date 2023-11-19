#include<iostream>
#include<string.h>
#include "tren.hpp"
#include "tren_calatori.hpp"
#include "tren_marfa.hpp"

int main(){
    char ruta1[]="Bucuresti-Timisoara", ruta2[]="Bucuresti-Constanta", ruta3[]="Timisoara-Cluj";
    char produs1[]="mere", produs2[]="pere", produs3[]="prune";
    char confort1[]="Rapid", confort2[]="Personal", confort3[]="Accelerat";
    int dimensiune1=19, dimensiune2=19, dimensiune3=14;
    int numere_vagoane1[]={434,433,4,3,2,1}, numere_vagoane2[]={1,2,3,4};
    int nr_vagoane1=6, nr_vagoane2=4;

    std::cout<<"\n\nConstructorii subclasei tren_marfa:\n\n";


    Vehicul::Tren_Marfa tren_marfa4;
    Vehicul::Tren_Marfa tren_marfa1=Vehicul::Tren_Marfa(ruta1, dimensiune1, nr_vagoane1, numere_vagoane1, 100, produs1, 4);
    tren_marfa1.afisare();
    Vehicul::Tren_Marfa tren_marfa2=Vehicul::Tren_Marfa(tren_marfa1);
    tren_marfa2.afisare();
    Vehicul::Tren_Marfa tren_marfa3=Vehicul::Tren_Marfa(ruta2, dimensiune2, nr_vagoane1, numere_vagoane1, 200, produs2, 4);
    tren_marfa3.afisare();
    tren_marfa1=tren_marfa3;
    tren_marfa3.afisare();
    tren_marfa4=Vehicul::Tren_Marfa(ruta3, dimensiune3, nr_vagoane1, numere_vagoane1, 250, produs3, 5);
    tren_marfa4.afisare();


    std::cout<<"\n\nFunctiile subclasei tren_marfa:\n\n";


    tren_marfa4.adauga_vagon_personalizat(6,10);
    tren_marfa4.afisare();
    tren_marfa4.schimba_ruta(ruta1, dimensiune1);
    tren_marfa4.afisare();
    tren_marfa4.schimba_produs(produs1, 4);
    tren_marfa4.afisare();
    tren_marfa4.sterge_vagon_personalizat(6,10);
    tren_marfa4.afisare();

    std::cout<<"\n\nConstructorii subclasei tren_calatori:\n\n";


    Vehicul::Tren_Calatori tren_calatori4;
    Vehicul::Tren_Calatori tren_calatori1=Vehicul::Tren_Calatori(ruta1, dimensiune1, nr_vagoane1, numere_vagoane1, 100, confort1, 5);
    tren_calatori1.afisare();
    Vehicul::Tren_Calatori tren_calatori2=Vehicul::Tren_Calatori(tren_calatori1);
    tren_calatori2.afisare();
    Vehicul::Tren_Calatori tren_calatori3=Vehicul::Tren_Calatori(ruta2, dimensiune2, nr_vagoane1, numere_vagoane1, 200, confort2, 8);
    tren_calatori3.afisare();
    tren_calatori1=tren_calatori3;
    tren_calatori3.afisare();
    tren_calatori4=Vehicul::Tren_Calatori(ruta3, dimensiune3, nr_vagoane1, numere_vagoane1, 250, confort3, 9);
    tren_calatori4.afisare();


    std::cout<<"\n\nFunctiile subclasei tren_calatori:\n\n";


    tren_calatori4.adauga_vagon_personalizat(6,10);
    tren_calatori4.afisare();
    tren_calatori4.schimba_ruta(ruta1, dimensiune1);
    tren_calatori4.afisare();
    tren_calatori4.schimba_confort(confort1, 5);
    tren_calatori4.afisare();
    tren_calatori4.sterge_vagon_personalizat(6,10);
    tren_calatori4.afisare();
    return 0;
}