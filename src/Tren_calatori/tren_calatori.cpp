#include<iostream>
#include<string.h>
#include "tren_calatori.hpp"

Tren_Calatori::Tren_Calatori(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane, int nr_calatori) 
    : Tren(ruta, dimensiune_ruta, nr_vagoane, numere_vagoane) {
        this->nr_calatori=nr_calatori;
    }

Tren_Calatori::~Tren_Calatori(){}

Tren_Calatori::Tren_Calatori(const Tren_Calatori& vechi)
    : Tren(vechi){
        this->nr_calatori=vechi.nr_calatori;
}

Tren_Calatori::Tren_Calatori(Tren_Calatori&& vechi)
    : Tren(std::move(vechi)){
        this->nr_calatori=vechi.nr_calatori;
        vechi.nr_calatori=0;
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

void Tren_Calatori::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul circula pe ruta: "<<this->ruta<<"avand un numar de "<<this->nr_calatori<<" calatori\n";
    std::cout<<"Structura: Locomotiva ";
    for(int i=0;i<this->nr_vagoane;i++){
        std::cout<<" <- "<<this->numere_vagoane[i];
    }
    std::cout<<"\n";
}