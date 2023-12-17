#include<iostream>
#include<string>
#include "tren.hpp"

using namespace Vehicul;

//Constructor no-arg
Tren::Tren(){
    std::cout<<"Constructorul no-arg a fost apelat\n";
    this->ruta=std::make_unique<std::string>();
    this->numere_vagoane=std::make_shared<Numar_vagon>();
    this->nr_vagoane=0;
}

//Constructorul
Tren::Tren(std::string ruta, int nr_vagoane, Numar_transport *numere_vagoane){
    std::cout<<"Constructorul a fost apelat\n";
    this->nr_vagoane=nr_vagoane;
    this->numere_vagoane=std::make_shared<Numar_vagon>();
    for(int i=0;i<this->nr_vagoane;i++){
        adauga_vagon(numere_vagoane[i]);
    }
    this->ruta=std::make_unique<std::string>(ruta);
}

//Destructorul
Tren::~Tren(){
    std::cout<<"Destructorul a fost apelat\n";
}




bool Tren::parcurgere(std::shared_ptr<Numar_vagon> node){
    std::shared_ptr<Numar_vagon> p = std::make_shared<Numar_vagon>();
    p = node;
    while(p->next != nullptr){
        std::cout<<" <- "<<p->numar_vagon<<" <- " << p->numar_transport;
        p=p->next;
    }
    return 0;
}


bool Tren::find(int vagon, std::shared_ptr<Numar_vagon> nr_vagon) {
    std::shared_ptr<Numar_vagon> p = std::make_shared<Numar_vagon>();
    p=nr_vagon;
    while(p != nullptr){
        if(p->numar_vagon==vagon){
            return 1;
        }
        p=p->next;
    }
    return 0;
}

//cautam o valoare in vector, daca o gasim, o mutam la final, functia va ajuta in cadrul metodei sterge_vagon
//Va fi mai usor de sters vagonul daca se afla pe ultima pozitie

void Tren::adauga_vagon(Numar_transport node_values){
    std::shared_ptr<Numar_vagon> p = this->numere_vagoane;
    std::shared_ptr<Numar_vagon> node = std::make_shared<Numar_vagon>();
    node->numar_vagon = node_values.numar_vagon;
    node->numar_transport = node_values.numar_transport;
    node->next=nullptr;
    if(!p) {
        this->numere_vagoane = node;
        return;
    }
    while(p->next != nullptr){
        p=p->next;
    }
    p->next=node;
}

void Tren::sterge_vagon(Numar_transport node_values){
    std::shared_ptr<Numar_vagon> p = std::make_shared<Numar_vagon>();
    std::shared_ptr<Numar_vagon> q = std::make_shared<Numar_vagon>();
    p = this->numere_vagoane;
    q = p->next;

    if(!p) {
        return;
    }

    if(!q) {
        this->numere_vagoane = nullptr;
        return;
    }

    if(p->numar_vagon == node_values.numar_vagon && p->numar_transport == node_values.numar_transport){
        this->numere_vagoane=q;
        return;
    }

    while(q->next != nullptr){
        if(q->numar_vagon == node_values.numar_vagon && q->numar_transport == node_values.numar_transport) {
            p->next = q->next;
            break;
        }
        p=q;
        q=q->next;
    }
}

void Tren::afisare(){
    if(this->ruta==NULL){
        std::cout<<"Move constructorul a fost apelat pentru acest tren\n";
        return;
    }
    std::cout<<"Trenul circula pe ruta: "<<*(this->ruta)<<"\n";
    std::cout<<"Structura: Locomotiva ";
    parcurgere(this->numere_vagoane);
    std::cout<<"\n";
}