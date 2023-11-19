#include<iostream>
#include<string.h>
#include "tren_marfa.hpp"

Tren_Marfa::Tren_Marfa(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane, int cantitate, char* produs, int dimensiune_produs) 
    : Tren(ruta, dimensiune_ruta, nr_vagoane, numere_vagoane) {
        this->cantitate=cantitate;
        this->dimensiune_produs=dimensiune_produs;
        this->produs=new char[this->dimensiune_produs+1];
        strcpy(this->produs,produs);
    }

Tren_Marfa::~Tren_Marfa(){
        delete[] this->produs;
}

Tren_Marfa::Tren_Marfa(const Tren_Marfa& vechi)
    : Tren(vechi){
        this->cantitate=vechi.cantitate;
        this->dimensiune_produs=vechi.dimensiune_produs;
        this->produs=new char[this->dimensiune_produs+1];
        strcpy(this->produs,vechi.produs);
}

Tren_Marfa::Tren_Marfa(Tren_Marfa&& vechi)
    : Tren(std::move(vechi)){
        this->cantitate=vechi.cantitate;
        this->dimensiune_produs=vechi.dimensiune_produs;
        this->produs=new char[this->dimensiune_produs+1];
        strcpy(this->produs, vechi.produs);
        vechi.produs=nullptr;
        vechi.dimensiune_produs=-1;
        vechi.cantitate=0;
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
}

void Tren_Marfa::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul circula pe ruta: "<<this->ruta<<"si transporta "<<this->produs<<"in cantitate de"<<this->cantitate<<"\n";
    std::cout<<"Structura: Locomotiva ";
    for(int i=0;i<this->nr_vagoane;i++){
        std::cout<<" <- "<<this->numere_vagoane[i];
    }
    std::cout<<"\n";
}