#include "tren.hpp"
namespace Vehicul{
    class Tren_Calatori: public Tren {
        private:
            int nr_calatori;
            int dimensiune_confort;
            char *confort;
        public: 
            Tren_Calatori();
            Tren_Calatori(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane, int nr_calatori, char *confort, int dimensiune_confort);
            Tren_Calatori(const Tren_Calatori& vechi);
            Tren_Calatori(Tren_Calatori&& vechi);
            ~Tren_Calatori();
            Tren_Calatori& operator=(const Tren_Calatori& vechi);
            Tren_Calatori& operator=(Tren_Calatori&& vechi);
            bool operator==(const Tren_Calatori& vechi);
            void schimba_confort(char *confort, int dimensiune_confort);
            void adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void afisare();
    };
}