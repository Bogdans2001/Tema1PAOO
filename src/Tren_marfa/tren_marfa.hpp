#include "tren.hpp"
namespace Vehicul{
    class Tren_Marfa : public Tren {
        private:
            int cantitate;
            char *produs;
            int dimensiune_produs;
        public: 
            Tren_Marfa();
            Tren_Marfa(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane, int cantitate, char *produs, int dimensiune_produs);
            Tren_Marfa(const Tren_Marfa& vechi);
            Tren_Marfa(Tren_Marfa&& vechi);
            ~Tren_Marfa();
            Tren_Marfa& operator=(const Tren_Marfa& vechi);
            Tren_Marfa& operator=(Tren_Marfa&& vechi);
            bool operator==(const Tren_Marfa& vechi);
            void adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void schimba_produs(char *produs, int dimensiune_produs);
            void afisare();
    };
}