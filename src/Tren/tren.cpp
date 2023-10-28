#include<iostream>
#include<string.h>
#include "tren.hpp"


//cautam o valoare in vector, daca o gasim, o mutam la final, functia va ajuta in cadrul metodei sterge_vagon
//Va fi mai usor de sters vagonul daca se afla pe ultima pozitie
bool find(int* vector, int lungime_vector, int numar){
    int aux,poz;
    bool check=0;
    for(int i=0;i<lungime_vector;i++){
        if(numar==vector[i]) {
            check=1;
            poz=i;
            break;
        }
    }
    if(check==0) return check;
    for(int i=poz;i<lungime_vector-1;i++){
        vector[i]=vector[i+1];
    }
    vector[lungime_vector-1]=numar;
    return check;
}


//Consturctorul
Tren::Tren(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane){
    std::cout<<"Constructorul a fost apelat\n";
    this->nr_vagoane=nr_vagoane;
    this->dimensiune_ruta=dimensiune_ruta;
    this->numere_vagoane=new int[this->nr_vagoane];
    for(int i=0;i<this->nr_vagoane;i++){
        this->numere_vagoane[i]=numere_vagoane[i];
    }
    this->ruta=new char[this->dimensiune_ruta+1];
    strcpy(this->ruta, ruta);
}

//Destructorul
Tren::~Tren(){
    std::cout<<"Destructorul a fost apelat\n";
    delete[] this->ruta;
    delete[] this->numere_vagoane;
}

//Copy Constructorul
Tren::Tren(const Tren& vechi){
    std::cout<<"Copy Constructorul a fost apelat\n";
    this->dimensiune_ruta=vechi.dimensiune_ruta;
    this->nr_vagoane=vechi.nr_vagoane;
    this->numere_vagoane=new int[this->nr_vagoane];
    this->ruta=new char[this->dimensiune_ruta+1];
    for(int i=0;i<this->nr_vagoane;i++){
        this->numere_vagoane[i]=vechi.numere_vagoane[i];
    }
    this->ruta=new char[this->dimensiune_ruta+1];
    strcpy(this->ruta, vechi.ruta);
}

//Move Constructorul
Tren::Tren(Tren&& vechi){
    std::cout<<"Move Constructorul a fost apelat\n";
    this->dimensiune_ruta=vechi.dimensiune_ruta;
    this->nr_vagoane=vechi.nr_vagoane;
    this->numere_vagoane=vechi.numere_vagoane;
    this->ruta=vechi.ruta;
    vechi.numere_vagoane=nullptr;
    vechi.ruta=nullptr;
    vechi.nr_vagoane=0;
    vechi.dimensiune_ruta=-1;
}

void Tren::adauga_vagon(int numar_vagon){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    int *aux=new int[this->nr_vagoane+1];
    for(int i=0;i<this->nr_vagoane;i++){
        aux[i]=this->numere_vagoane[i];
    }
    delete[] this->numere_vagoane;
    this->numere_vagoane=new int[this->nr_vagoane+1];
    for(int i=0;i<this->nr_vagoane;i++){
        this->numere_vagoane[i]=aux[i];
    }
    this->numere_vagoane[this->nr_vagoane]=numar_vagon;
    delete[] aux;
    this->nr_vagoane++;
}

void Tren::schimba_ruta(char *ruta_noua, int dimensiune_ruta){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    delete[] this->ruta;
    this->dimensiune_ruta=dimensiune_ruta;
    this->ruta=new char[this->dimensiune_ruta+1];
    strcpy(this->ruta, ruta_noua);
}

void Tren::sterge_vagon(int numar_vagon){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    bool checked=find(this->numere_vagoane, this->nr_vagoane, numar_vagon);
    if(checked==0) return;
    this->nr_vagoane--;
    int *aux;
    aux=new int[this->nr_vagoane];
    for(int i=0;i<this->nr_vagoane;i++){
        aux[i]=this->numere_vagoane[i];
    }
    delete[] this->numere_vagoane;
    this->numere_vagoane=new int[this->nr_vagoane];
    for(int i=0;i<this->nr_vagoane;i++){
        this->numere_vagoane[i]=aux[i];
    }
    delete[] aux;
}

void Tren::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul circula pe ruta: "<<this->ruta<<"\n";
    std::cout<<"Structura: Locomotiva ";
    for(int i=0;i<this->nr_vagoane;i++){
        std::cout<<" <- "<<this->numere_vagoane[i];
    }
    std::cout<<"\n";
}