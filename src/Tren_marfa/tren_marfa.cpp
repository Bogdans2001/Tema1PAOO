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

