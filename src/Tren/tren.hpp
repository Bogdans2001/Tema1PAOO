#pragma once
#include "VehiculeSine.hpp"

namespace Vehicul{
    class Tren : VehiculSine
    {
        protected:
            int dimensiune_ruta;
            char *ruta;
            int nr_vagoane;
            int *numere_vagoane;
            bool find(int numar_vagon);
            bool find_sterge(int numar_vagon);
        public:
            Tren();
            Tren(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane);
            Tren(const Tren& vechi);
            Tren(Tren&& tren);
            Tren& operator=(const Tren& vechi);
            Tren& operator=(Tren&& vechi);
            bool operator==(const Tren& vechi);
            virtual ~Tren();
            bool adauga_vagon(int numar_vagon);
            bool sterge_vagon(int numar_vagon);
            virtual void adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon)=0;
            void schimba_ruta(char *ruta_noua, int dimensiune_ruta);
            virtual void sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon)=0;
            virtual void afisare();
    };
}