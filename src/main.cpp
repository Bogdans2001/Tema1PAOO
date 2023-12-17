#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include "tren.hpp"

int main(){
    std::string ruta1 = "Bucuresti-Timisoara";
    std::string ruta2 = "Bucuresti-Constanta";
    std::string ruta3 = "Timisoara-Cluj";



    Numar_transport numere_vagoane1[]={ {434, 80} , {433, 79}, {4, 78},{3, 77},{2, 76},{1, 75}}, 
    numere_vagoane2[]={ {1, 82}, {2, 83}, {3, 85}, {4, 87}},
    numere_vagoane3[]={ {2, 82}, {3, 83}, {4, 85}, {5, 87}},
    numere_vagoane4[]={ {3, 82}, {4, 83}, {5, 85}, {6, 87}},
    numere_vagoane5[]={ {4, 82}, {5, 83}, {6, 85}, {7, 87}},
    numere_vagoane6[]={ {5, 82}, {6, 83}, {7, 85}, {8, 87}},
    numere_vagoane7[]={ {6, 82}, {7, 83}, {8, 85}, {9, 87}, {10,77}, {11, 78}},
    numere_vagoane8[]={ {434, 80} , {433, 79}, {4, 78},{3, 77},{2, 76},{1, 75}},
    numere_vagoane9[]={ {433, 80} , {432, 79}, {4, 78},{3, 77},{2, 76},{1, 75}},
    numere_vagoane10[]={ {431, 80} , {430, 79}, {4, 78},{3, 77},{2, 76},{1, 75}},
    numere_vagoane11[]={ {435, 80} , {434, 79}, {4, 78},{3, 77},{2, 76},{1, 75}};

    std::vector<Tren> tren;

    Tren tren1=Tren(ruta1, numere_vagoane1);
    tren1.adauga_vagon({434, 81});
    tren1.sterge_vagon(1);
    tren1.afisare();

    Tren tren2=Tren(ruta2, numere_vagoane2);
    tren2.afisare();

    Tren tren3 = Tren(ruta3, numere_vagoane3);
    Tren tren4 = Tren(ruta1, numere_vagoane4);
    Tren tren5 = Tren(ruta2, numere_vagoane5);
    Tren tren6 = Tren(ruta3, numere_vagoane6);
    Tren tren7 = Tren(ruta1, numere_vagoane7);
    Tren tren8 = Tren(ruta2, numere_vagoane8);
    Tren tren9 = Tren(ruta3, numere_vagoane9);
    Tren tren10 = Tren(ruta1, numere_vagoane10);
    Tren tren11 = Tren(ruta2, numere_vagoane11);

    tren.push_back(tren1);
    tren.push_back(tren2);
    tren.push_back(tren3);
    tren.push_back(tren4);
    tren.push_back(tren5);
    tren.push_back(tren6);
    tren.push_back(tren7);
    tren.push_back(tren8);
    tren.push_back(tren9);
    tren.push_back(tren10);
    tren.push_back(tren11);
    return 0;
}