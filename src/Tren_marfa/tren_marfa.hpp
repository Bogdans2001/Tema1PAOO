#include "tren.hpp"
class Tren_Marfa : public Tren {
    public: 
        Tren_Marfa(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane);
        Tren_Marfa(const char& vechi);
        Tren_Marfa(const char&& vechi);
        ~Tren_Marfa();
        void adauga_vagon(int numar_vagon);
        void schimba_ruta(char *ruta_noua, int dimensiune_ruta);
        void sterge_vagon(int numar_vagon);
        void afisare();
};