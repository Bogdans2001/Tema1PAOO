#include<iostream>
#include<string.h>
#include "tren_calatori.hpp"

using namespace Vehicul;

//Constructor no-arg
Tren_Calatori::Tren_Calatori()
    : Tren::Tren(){
        this->nr_calatori=0;
        this->confort=nullptr;
        this->dimensiune_confort=-1;
}

//Constructor
Tren_Calatori::Tren_Calatori(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane, int nr_calatori, char *confort, int dimensiune_confort) 
    : Tren::Tren(ruta, dimensiune_ruta, nr_vagoane, numere_vagoane) {
        this->nr_calatori=nr_calatori;
        this->dimensiune_confort=dimensiune_confort;
        this->confort=new char[this->dimensiune_confort+1];
        strcpy(this->confort,confort);
    }

//Destructor
Tren_Calatori::~Tren_Calatori(){
    delete[] this->confort;
}


//Copy constructor
Tren_Calatori::Tren_Calatori(const Tren_Calatori& vechi)
    : Tren::Tren(vechi){
        this->nr_calatori=vechi.nr_calatori;
        this->dimensiune_confort=vechi.dimensiune_confort;
        this->confort=new char[this->dimensiune_confort+1];
        strcpy(this->confort,vechi.confort);
}


//Move constructor
Tren_Calatori::Tren_Calatori(Tren_Calatori&& vechi)
    : Tren::Tren(std::move(vechi)){
        this->nr_calatori=vechi.nr_calatori;
        this->dimensiune_confort=vechi.dimensiune_confort;
        this->confort=vechi.confort;
        vechi.confort=nullptr;
        vechi.dimensiune_confort=-1;
        vechi.nr_calatori=0;
}

//Copy assignment
Tren_Calatori& Tren_Calatori::operator=(const Tren_Calatori& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(vechi);
    if(this->dimensiune_confort != vechi.dimensiune_confort){
        this->dimensiune_confort=vechi.dimensiune_confort;
        delete[] this->confort;
        this->confort=new char[this->dimensiune_confort+1];
    }
    this->nr_calatori=vechi.nr_calatori;
    strcpy(this->confort,vechi.confort);
    return *this;
}


//Move assignment
Tren_Calatori& Tren_Calatori::operator=(Tren_Calatori&& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(std::move(vechi));
    delete[] this->confort;
    this->dimensiune_confort=vechi.dimensiune_confort;
    this->confort=vechi.confort;
    this->nr_calatori=vechi.nr_calatori;
    vechi.nr_calatori=0;
    vechi.dimensiune_confort=-1;
    vechi.confort=nullptr;
    return *this;
}


bool Tren_Calatori::operator==(const Tren_Calatori& vechi){
    if(Tren::operator==(vechi) == 0){
        return 0;
    }
    if( (this->nr_calatori != vechi.nr_calatori) || (this->dimensiune_confort != vechi.dimensiune_confort) || (strcmp(this->confort, vechi.confort) != 0) ){
        return 0;
    }
    return 1;
}

void Tren_Calatori::adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon){
    bool ok=adauga_vagon(numar_vagon);
    std::cout<<"Functia adauga vagon personalizat a fost apelata pentru un tren cu calatori.\n";
    if(!ok) {
        return;
    }
    this->nr_calatori+=cantitate_vagon;
}

void Tren_Calatori::sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon){
    std::cout<<"Functia sterge vagon personalizat a fost apelata pentru un tren cu calatori.\n";
    int diferenta_cantitate=this->nr_calatori-cantitate_vagon;
    if(diferenta_cantitate<0) {
        std::cout<<"Numarul de calatori ce urmeaza a fi sters este prea mare.\n";
        return;
    }
    bool ok=sterge_vagon(numar_vagon);
    if(!ok){
        return;
    }
    this->nr_calatori=diferenta_cantitate;
}

void Tren_Calatori::schimba_confort(char *confort, int dimensiune_confort){
    if(this->dimensiune_confort != dimensiune_confort){
        this->dimensiune_confort=dimensiune_confort;
        delete[] this->confort;
        this->confort=new char[this->dimensiune_confort+1];
    }
    strcpy(this->confort, confort);
    std::cout<<"Confortul a fost schimbat\n";
}

void Tren_Calatori::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul de tip "<<this->confort<<" circula pe ruta: "<<this->ruta<<" avand un numar de "<<this->nr_calatori<<" calatori\n";
    std::cout<<"Structura: Locomotiva ";
    for(int i=0;i<this->nr_vagoane;i++){
        std::cout<<" <- "<<this->numere_vagoane[i];
    }
    std::cout<<"\n";
}