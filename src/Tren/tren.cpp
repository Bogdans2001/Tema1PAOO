#include<iostream>
#include<string.h>
#include "tren.hpp"

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

//Copy assignment
Tren& Tren::operator=(const Tren& vechi){
    std::cout<<"Copy assignment a fost apelat\n";
    if(this==&vechi) {
        return *this;
    }
    if(this->dimensiune_ruta != vechi.dimensiune_ruta){
        this->dimensiune_ruta=vechi.dimensiune_ruta;
        delete[] this->ruta;
        this->ruta=new char[this->dimensiune_ruta+1];
    }
    if(this->nr_vagoane != vechi.nr_vagoane){
        this->nr_vagoane=this->nr_vagoane;
        delete[] this->numere_vagoane;
        this->numere_vagoane=new int[this->nr_vagoane];
    }
    if(strcmp(this->ruta,vechi.ruta) !=0 ){
        strcpy(this->ruta,vechi.ruta);
    }
    for(int i=0;i<this->nr_vagoane;i++){
        this->numere_vagoane[i]=vechi.numere_vagoane[i];
    }
    return *this;
}

//Move assignment
Tren& Tren::operator=(Tren&& vechi){
    std::cout<<"Move assignment a fost apelat\n";
    if(this==&vechi) {
        return *this;
    }
    if(this->dimensiune_ruta != vechi.dimensiune_ruta){
        this->dimensiune_ruta=vechi.dimensiune_ruta;
        delete[] this->ruta;
        this->ruta=new char[this->dimensiune_ruta+1];
    }
    if(this->nr_vagoane != vechi.nr_vagoane){
        this->nr_vagoane=this->nr_vagoane;
        delete[] this->numere_vagoane;
        this->numere_vagoane=new int[this->nr_vagoane];
    }
    if(strcmp(this->ruta,vechi.ruta) !=0 ){
        strcpy(this->ruta,vechi.ruta);
    }
    for(int i=0;i<this->nr_vagoane;i++){
        this->numere_vagoane[i]=vechi.numere_vagoane[i];
    }
    vechi.dimensiune_ruta = -1;
    vechi.nr_vagoane = 0;
    vechi.ruta=nullptr;
    vechi.numere_vagoane=nullptr;
    return *this;
}

bool Tren::operator==(const Tren& vechi){
    if( (this->dimensiune_ruta!=vechi.dimensiune_ruta) || (this->nr_vagoane!=this->nr_vagoane) || (strcmp(this->ruta,vechi.ruta) !=0 ) ) {
        return 0;
    }

    for(int i=0;i<this->nr_vagoane;i++) {
        if(this->numere_vagoane[i] != vechi.numere_vagoane[i]) {
            return 0;
        }
    }
    return 1;
}

bool Tren::find(int numar_vagon) {
    bool check=0;
    for(int i=0;i<this->nr_vagoane;i++){
        if(numar_vagon==this->numere_vagoane[i]){
            check=1;
            break;
        }
    }
    return check;
}

//cautam o valoare in vector, daca o gasim, o mutam la final, functia va ajuta in cadrul metodei sterge_vagon
//Va fi mai usor de sters vagonul daca se afla pe ultima pozitie
bool Tren::find_sterge(int numar_vagon){
    int aux,poz;
    bool check=0;
    for(int i=0;i<this->nr_vagoane;i++){
        if(numar_vagon==this->numere_vagoane[i]) {
            check=1;
            poz=i;
            break;
        }
    }
    if(check==0) return check;
    for(int i=poz;i<this->nr_vagoane-1;i++){
        this->numere_vagoane[i]=this->numere_vagoane[i+1];
    }
    this->numere_vagoane[this->nr_vagoane-1]=numar_vagon;
    return check;
}

bool Tren::adauga_vagon(int numar_vagon){
    if(this->ruta==NULL){
        std::cout<<"Nu se poate adauga vagonul, move constructorul a fost apelat pentru acest tren\n";
        return 0;
    }
    bool check;
    check=find(numar_vagon);
    if(check) {
        std::cout<<"Vagonul cu numarul "<<numar_vagon<<" exista deja\n";
        return 0;
    }
    int *aux=new int[this->nr_vagoane+1];
    for(int i=0;i<this->nr_vagoane;i++){
        aux[i]=this->numere_vagoane[i];
    }
    delete[] this->numere_vagoane;
    this->numere_vagoane=new int[this->nr_vagoane+1];
    aux[this->nr_vagoane]=numar_vagon;
    this->numere_vagoane=aux;
    this->nr_vagoane++;
    std::cout<<"Vagonul "<<numar_vagon<<" a fost adaugat\n";
    return 1;
}

void Tren::schimba_ruta(char *ruta_noua, int dimensiune_ruta){
    if(this->ruta==NULL){
        std::cout<<"Nu se poate schimba ruta, move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    delete[] this->ruta;
    this->dimensiune_ruta=dimensiune_ruta;
    this->ruta=new char[this->dimensiune_ruta+1];
    strcpy(this->ruta, ruta_noua);
    std::cout<<"Ruta a fost schimbata\n";
}

bool Tren::sterge_vagon(int numar_vagon){
    if(this->ruta==NULL){
        std::cout<<"Nu se poate sterge vagonul, move constructorul a fost apelat pentru acest tren\n";
        return 0;
    }
    bool checked=find_sterge(numar_vagon);
    if(checked==0) {
        std::cout<<"Vagonul "<<numar_vagon<<" nu exista\n";
        return 0;
    }
    this->nr_vagoane--;
    int *aux;
    aux=new int[this->nr_vagoane];
    for(int i=0;i<this->nr_vagoane;i++){
        aux[i]=this->numere_vagoane[i];
    }
    delete[] this->numere_vagoane;
    this->numere_vagoane=new int[this->nr_vagoane];
    this->numere_vagoane=aux;
    std::cout<<"Vagonul "<<numar_vagon<<" a fost sters\n";
    return 1;
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