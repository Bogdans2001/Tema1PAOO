#include<iostream>
#include<string>
#include<memory>
#include "tren.hpp"

int main(){
    std::string ruta1 = "Bucuresti-Timisoara";
    std::string ruta2 = "Bucuresti-Constanta";
    std::string ruta3 = "Timisoara-Cluj";
    std::shared_ptr<std::string> produs1, produs2, produs3;
    std::shared_ptr<std::string> confort1, confort2, confort3;
    produs1=std::make_shared<std::string>();
    produs2=std::make_shared<std::string>();
    produs3=std::make_shared<std::string>();
    confort1=std::make_shared<std::string>();
    confort2=std::make_shared<std::string>();
    confort3=std::make_shared<std::string>();
    *produs1="mere";
    *produs2="pere"; 
    *produs3="prune";
    *confort1="Rapid";
    *confort2="Personal"; 
    *confort3="Accelerat";
    Numar_transport numere_vagoane1[]={ {434, 80} , {433, 79}, {4, 78},{3, 77},{2, 76},{1, 75}}, numere_vagoane2[]={ {1, 82}, {2, 83}, {3, 85}, {4, 87}};
    int nr_vagoane1=6, nr_vagoane2=4;

    Tren tren1 = Tren(ruta1, nr_vagoane1, numere_vagoane1);
    tren1.adauga_vagon({434, 81});
    tren1.sterge_vagon(1);
    tren1.afisare();

    Tren tren2=Tren(ruta2, nr_vagoane2, numere_vagoane2);
    tren2.afisare();

    return 0;
}