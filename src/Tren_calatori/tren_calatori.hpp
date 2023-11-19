#include "tren.hpp"
class Tren_Calatori: public Tren {
    private:
        int nr_calatori;
    public: 
        Tren_Calatori(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane, int nr_calatori);
        Tren_Calatori(const Tren_Calatori& vechi);
        Tren_Calatori(Tren_Calatori&& vechi);
        ~Tren_Calatori();
        void adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon);
        void sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon);
        void afisare();
};