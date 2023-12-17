#include "tren.hpp"
#include <cstring>
namespace Vehicul{
    class Tren_Calatori: public Tren {
        private:
            int nr_calatori;
            std::shared_ptr<std::string> confort;
        public: 
            Tren_Calatori();
            Tren_Calatori(std::string ruta, int nr_vagoane, int *numere_vagoane, int nr_calatori, std::shared_ptr<std::string> confort);
            Tren_Calatori(const Tren_Calatori& vechi);
            Tren_Calatori(Tren_Calatori&& vechi);
            ~Tren_Calatori();
            Tren_Calatori& operator=(const Tren_Calatori& vechi);
            Tren_Calatori& operator=(Tren_Calatori&& vechi);
            bool operator==(const Tren_Calatori& vechi);
            void schimba_confort(std::shared_ptr<std::string> confort);
            void adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void afisare();
    };
}