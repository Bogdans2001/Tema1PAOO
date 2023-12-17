#include<iostream>
#include "tren_marfa.hpp"

using namespace Vehicul;

//Constructor no-arg
Tren_Marfa::Tren_Marfa()
    : Tren::Tren(){
        this->produs=std::make_shared<std::string>();
        this->cantitate=0;
}

//Constructor
Tren_Marfa::Tren_Marfa(std::string ruta, int nr_vagoane, int *numere_vagoane, int cantitate, std::shared_ptr<std::string> produs) 
    : Tren::Tren(ruta, nr_vagoane, numere_vagoane) {
        this->cantitate=cantitate;
        this->produs=std::make_shared<std::string>();
        this->produs = produs;
    }


//Destructor
Tren_Marfa::~Tren_Marfa(){
}


//Copy constructor
Tren_Marfa::Tren_Marfa(const Tren_Marfa& vechi)
    : Tren::Tren(vechi){
        this->cantitate=vechi.cantitate;
        this->produs=std::make_shared<std::string>();
        this->produs = vechi.produs;
}

//Move constructor
Tren_Marfa::Tren_Marfa(Tren_Marfa&& vechi)
    : Tren::Tren(std::move(vechi)){
        this->cantitate=vechi.cantitate;
        this->produs=std::make_shared<std::string>();
        this->produs=vechi.produs;
        vechi.cantitate=0;
}


//Copy assignment
Tren_Marfa& Tren_Marfa::operator=(const Tren_Marfa& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(vechi);
    this->cantitate=vechi.cantitate;
    this->produs=vechi.produs;
    return *this;
}


//Move assignment
Tren_Marfa& Tren_Marfa::operator=(Tren_Marfa&& vechi){
    if(this==&vechi) {
        return *this;
    }
    Tren::operator=(std::move(vechi));
    this->cantitate=vechi.cantitate;
    this->produs = vechi.produs;
    vechi.cantitate=0;
    vechi.produs=nullptr;
    return *this;
}


bool Tren_Marfa::operator==(const Tren_Marfa& vechi){
    if(Tren::operator==(vechi) == 0){
        return 0;
    }
    if( (this->cantitate != vechi.cantitate) || ( *(this->produs) == *(vechi.produs) ) ){
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

void Tren_Marfa::schimba_produs(std::shared_ptr<std::string> produs){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Functia schimba produs a fost apelata\n";
    this->produs = produs;
    std::cout<<"Produsul a fost schimbat\n";
}

void Tren_Marfa::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul circula pe ruta: "<<*(this->ruta)<<" si transporta "<<*(this->produs)<<" in cantitate de "<<this->cantitate<<"\n";
    std::cout<<"Structura: Locomotiva ";
    for(int i=0;i<this->nr_vagoane;i++){
        std::cout<<" <- "<<this->numere_vagoane[i];
    }
    std::cout<<"\n";
}