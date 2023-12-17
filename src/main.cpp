#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<mutex>
#include<barrier>
#include<thread>
#include<array>
#include "tren.hpp"

int numar_cutii;
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


int lista_vagoane[] = {433, 1, 3, 4, 7};

const auto nr_threads = std::thread::hardware_concurrency();


std::vector<Tren> tren = {
        Tren(ruta1, 6, numere_vagoane1),
        Tren(ruta2, 4, numere_vagoane2),
        Tren(ruta3, 4, numere_vagoane3),
        Tren(ruta1, 4, numere_vagoane4),
        Tren(ruta2, 4, numere_vagoane5),
        Tren(ruta3, 4, numere_vagoane6),
        Tren(ruta1, 6, numere_vagoane7),
        Tren(ruta2, 6, numere_vagoane8),
        Tren(ruta3, 6, numere_vagoane9),
        Tren(ruta1, 6, numere_vagoane10),
        Tren(ruta2, 6, numere_vagoane11)
    };

std::mutex my_mutex;

void sterge_actualizeaza(int i, int length, int *lista_vagoane, int length_lista){
    int start, end,s;
    start=i*length/nr_threads;
    end = (i+1)*length/nr_threads;
    for(int k=start;k<end;k++){
        my_mutex.lock();
        std::cout<<length_lista<<"\n";
        for(int p=0;p<length_lista;p++){
            tren[k].sterge_vagon(lista_vagoane[p]);
        }

        s=tren[k].calculeaza_transport();
        std::cout<<"Thread "<<i<<" Trenul "<<k<<" transporta "<<s<<" cutii\n";

        my_mutex.unlock();
    }
}

int main(){
    std::vector<std::thread> threads(nr_threads);

    Tren tren1(ruta2, 4, numere_vagoane2);
    Tren tren2(tren1);
    tren1.afisare();
    tren2.afisare();
    tren2.sterge_vagon(1);
    tren2.afisare();
    std::cout<<tren2.calculeaza_transport();

    std::cout<<"\n\n\n\nMutex si bariera\n\n\n\n";

    int length=0,length_lista=0;
    for(Tren& iterator : tren){
        length++;
    }
    for(int x: lista_vagoane){
        length_lista++;
    }
    for(int i=0;i<nr_threads;i++){
        threads[i]=std::thread(sterge_actualizeaza, i, length, lista_vagoane, length_lista);
    }

    for(int i = 0; i<nr_threads; i++){
        threads[i].join();
    }
    return 0;
}