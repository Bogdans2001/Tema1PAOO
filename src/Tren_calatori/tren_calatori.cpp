#include<iostream>
#include<string>
#include "tren_calatori.hpp"

using namespace Vehicul;

//Constructor no-arg
Tren_Calatori::Tren_Calatori()
    : Tren::Tren(){
        this->nr_calatori=0;
        this->confort=std::make_shared<std::string>();
}

//Constructor
Tren_Calatori::Tren_Calatori(std::string ruta, int nr_vagoane, int *numere_vagoane, int nr_calatori, std::shared_ptr<std::string> confort) 
    : Tren::Tren(ruta, nr_vagoane, numere_vagoane) {
        this->nr_calatori=nr_calatori;
        this->confort=std::make_shared<std::string>();
        this->confort = confort;
    }

//Destructor
Tren_Calatori::~Tren_Calatori(){
}


//Copy constructor
Tren_Calatori::Tren_Calatori(const Tren_Calatori& vechi)
    : Tren::Tren(vechi){
        this->nr_calatori=vechi.nr_calatori;
        this->confort=std::make_shared<std::string>();
        this->confort = confort;
}


//Move constructor
Tren_Calatori::Tren_Calatori(Tren_Calatori&& vechi)
    : Tren::Tren(std::move(vechi)){
        this->nr_calatori=vechi.nr_calatori;
        this->confort=std::make_shared<std::string>();
        this->confort = confort;
        vechi.nr_calatori=0;
}

//Copy assignment
Tren_Calatori& Tren_Calatori::operator=(const Tren_Calatori& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(vechi);
    this->nr_calatori=vechi.nr_calatori;
    this->confort = vechi.confort;
    return *this;
}


//Move assignment
Tren_Calatori& Tren_Calatori::operator=(Tren_Calatori&& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(std::move(vechi));
    this->confort=vechi.confort;
    this->nr_calatori=vechi.nr_calatori;
    vechi.nr_calatori=0;
    return *this;
}


bool Tren_Calatori::operator==(const Tren_Calatori& vechi){
    if(Tren::operator==(vechi) == 0){
        return 0;
    }
    if( (this->nr_calatori != vechi.nr_calatori) || ( *(this->ruta) == *(vechi.ruta) ) ){
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

void Tren_Calatori::schimba_confort(std::shared_ptr<std::string> confort){
    this->confort = confort;
    std::cout<<"Confortul a fost schimbat\n";
}

void Tren_Calatori::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul de tip "<<*(this->confort)<<" circula pe ruta: "<<*(this->ruta)<<" avand un numar de "<<this->nr_calatori<<" calatori\n";
    std::cout<<"Structura: Locomotiva ";
    for(int i=0;i<this->nr_vagoane;i++){
        std::cout<<" <- "<<this->numere_vagoane[i];
    }
    std::cout<<"\n";
}