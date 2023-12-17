#include<iostream>
#include<string>
#include "tren.hpp"

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

Tren::Tren(const Tren& vechi){
    this->nr_vagoane = vechi.nr_vagoane;
    this->ruta=std::make_unique<std::string>(*(vechi.ruta));
    parcurgere_copy(vechi.numere_vagoane);
}


//Destructorul
Tren::~Tren(){
    std::cout<<"Destructorul a fost apelat\n";
}

void Tren::parcurgere_copy(std::shared_ptr<Numar_vagon> old){
    std::shared_ptr<Numar_vagon> p1;
    this->numere_vagoane=std::make_shared<Numar_vagon>();
    p1=this->numere_vagoane;
    while(old != nullptr){
        p1->numar_vagon = old->numar_vagon;
        p1->numar_transport = old->numar_transport;
        if(old->next != nullptr) {
            p1->next=std::make_shared<Numar_vagon>();
        }
        else {
            p1->next = nullptr;
        }
        old = old->next;
        p1=p1->next;
    }
}


bool Tren::parcurgere(){
    std::shared_ptr<Numar_vagon> p;
    p = this->numere_vagoane;
    while(p != nullptr){
        std::cout<<" <- ("<<p->numar_vagon<<" <- " << p->numar_transport<<") ";
        p=p->next;
    }
    return 0;
}


int Tren::calculeaza_transport(){
    std::shared_ptr<Numar_vagon> p = this->numere_vagoane;
    int s=0;
    while(p != nullptr){
        s=s+p->numar_transport;
        p=p->next;
    }
    return s;
}

bool Tren::find(int vagon) {
    std::shared_ptr<Numar_vagon> p;
    p=this->numere_vagoane;
    while(p != nullptr){
        if(p->numar_vagon==vagon){
            return 1;
        }
        p=p->next;
    }
    return 0;
}


void Tren::adauga_vagon(Numar_transport node_values){
    std::shared_ptr<Numar_vagon> p = this->numere_vagoane;
    std::shared_ptr<Numar_vagon> node = std::make_shared<Numar_vagon>();
    if(find(node_values.numar_vagon)){
        std::cout<< "Vagonul exista\n";
        return;
    }
    node->numar_vagon = node_values.numar_vagon;
    node->numar_transport = node_values.numar_transport;
    node->next=nullptr;
    if(p->numar_vagon==0) {
        this->numere_vagoane = node;
        return;
    }
    while(p->next != nullptr){
        p=p->next;
    }
    p->next=node;
}

void Tren::sterge_vagon(int node_value){
    std::shared_ptr<Numar_vagon> p;
    std::shared_ptr<Numar_vagon> q;
    p = this->numere_vagoane;
    q = p->next;

    if(!find(node_value)){
        std::cout<< "Vagonul nu exista\n";
        return;
    }

    if(!p) {
        return;
    }

    if(!q) {
        this->numere_vagoane = nullptr;

        return;
    }

    if(p->numar_vagon == node_value){
        this->numere_vagoane=q;

        return;
    }

    while(q != nullptr){
        if(q->numar_vagon == node_value) {
            p->next = q->next;
            break;
        }
        p=q;
        q=q->next;
    }
}

void Tren::afisare(){
    std::cout<<"Trenul circula pe ruta: "<<*(this->ruta)<<"\n";
    std::cout<<"Structura: Locomotiva ";
    parcurgere();
    std::cout<<"\n";
}