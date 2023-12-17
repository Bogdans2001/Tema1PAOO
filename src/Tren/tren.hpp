#pragma once
#include "VehiculeSine.hpp"
#include <memory>

namespace Vehicul{
    typedef struct Numar_vagon{
                int numar_vagon;
                int numar_transport;
                std::shared_ptr<struct Numar_vagon> next;
            }Numar_vagon;
    
    typedef struct Numar_transport{
        int numar_vagon;
        int numar_transport;
    }Numar_transport;

    class Tren : VehiculSine
    {
        protected:
            int nr_vagoane; 
            std::unique_ptr<std::string> ruta;
            std::shared_ptr<Numar_vagon> numere_vagoane;
            bool find(int numar_vagon, std::shared_ptr<Numar_vagon> nr_vagon);
            bool parcurgere(std::shared_ptr<Numar_vagon> node);
            bool comparare(std::shared_ptr<Numar_vagon> numere_vagoane1, std::shared_ptr<Numar_vagon> numere_vagoane2);
        public:
            Tren();
            Tren(std::string ruta, int nr_vagoane, Numar_transport *numere_vagoane);
            Tren(const Tren& vechi);
            Tren(Tren&& tren);
            Tren& operator=(const Tren& vechi);
            Tren& operator=(Tren&& vechi);
            bool operator==(const Tren& vechi);
            virtual ~Tren();
            void adauga_vagon(Numar_transport node_values);
            void sterge_vagon(Numar_transport node_values);
            virtual void afisare();
    };
}