#include<iostream>
#include<string.h>
#include "tren_marfa.hpp"

using namespace Vehicul;

//Constructor no-arg
Tren_Marfa::Tren_Marfa()
    : Tren::Tren(){
        this->produs=nullptr;
        this->dimensiune_produs=-1;
        this->cantitate=0;
}

//Constructor
Tren_Marfa::Tren_Marfa(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane, int cantitate, char* produs, int dimensiune_produs) 
    : Tren::Tren(ruta, dimensiune_ruta, nr_vagoane, numere_vagoane) {
        this->cantitate=cantitate;
        this->dimensiune_produs=dimensiune_produs;
        this->produs=new char[this->dimensiune_produs+1];
        strcpy(this->produs,produs);
    }


//Destructor
Tren_Marfa::~Tren_Marfa(){
        delete[] this->produs;
}


//Copy constructor
Tren_Marfa::Tren_Marfa(const Tren_Marfa& vechi)
    : Tren::Tren(vechi){
        this->cantitate=vechi.cantitate;
        this->dimensiune_produs=vechi.dimensiune_produs;
        this->produs=new char[this->dimensiune_produs+1];
        strcpy(this->produs,vechi.produs);
}

//Move constructor
Tren_Marfa::Tren_Marfa(Tren_Marfa&& vechi)
    : Tren::Tren(std::move(vechi)){
        this->cantitate=vechi.cantitate;
        this->dimensiune_produs=vechi.dimensiune_produs;
        this->produs=vechi.produs;
        vechi.produs=nullptr;
        vechi.dimensiune_produs=-1;
        vechi.cantitate=0;
}


//Copy assignment
Tren_Marfa& Tren_Marfa::operator=(const Tren_Marfa& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(vechi);
    this->cantitate=vechi.cantitate;
    if(this->dimensiune_produs != vechi.dimensiune_produs){
        this->dimensiune_produs = vechi.dimensiune_produs;
        delete[] this->produs;
        this->produs = new char[this->dimensiune_produs+1];
    }
    strcpy(this->produs, vechi.produs);
    return *this;
}


//Move assignment
Tren_Marfa& Tren_Marfa::operator=(Tren_Marfa&& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(std::move(vechi));
    delete[] this->produs;
    this->cantitate=vechi.cantitate;
    this->dimensiune_produs=vechi.dimensiune_produs;
    this->produs = vechi.produs;
    vechi.cantitate=0;
    vechi.dimensiune_produs=-1;
    vechi.produs=nullptr;
    return *this;
}


bool Tren_Marfa::operator==(const Tren_Marfa& vechi){
    if(Tren::operator==(vechi) == 0){
        return 0;
    }
    if( (this->cantitate != vechi.cantitate) || (this->dimensiune_produs != vechi.dimensiune_produs) || (strcmp(this->produs, vechi.produs) != 0) ){
        return 0;
    }
    return 1;
}

void Tren_Marfa::adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon){
    bool ok=adauga_vagon(numar_vagon);
    std::cout<<"Functia adauga vagon personalizat a fost apelata pentru un tren marfar.\n";
    if(!ok) {
        return;
    }
    this->cantitate+=cantitate_vagon;
}

void Tren_Marfa::sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon){
    std::cout<<"Functia sterge vagon personalizat a fost apelata pentru un tren marfar.\n";
    int diferenta_cantitate=this->cantitate-cantitate_vagon;
    if(diferenta_cantitate<0) {
        std::cout<<"Cantitatea care se doreste a fi pierduta este prea mare.\n";
        return;
    }
    bool ok=sterge_vagon(numar_vagon);
    if(!ok){
        return;
    }
    this->cantitate=diferenta_cantitate;
}

void Tren_Marfa::schimba_produs(char *produs, int dimensiune_produs){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Functia schimba produs a fost apelata\n";
    delete[] this->produs;
    this->dimensiune_produs=dimensiune_produs;
    this->produs=new char[this->dimensiune_produs+1];
    strcpy(this->produs, produs);
    std::cout<<"Produsul a fost schimbat\n";
}

void Tren_Marfa::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul circula pe ruta: "<<this->ruta<<" si transporta "<<this->produs<<" in cantitate de "<<this->cantitate<<"\n";
    std::cout<<"Structura: Locomotiva ";
    for(int i=0;i<this->nr_vagoane;i++){
        std::cout<<" <- "<<this->numere_vagoane[i];
    }
    std::cout<<"\n";
}