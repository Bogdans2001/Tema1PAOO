#include "tren.hpp"
#include<string>
#include<cstring>

namespace Vehicul{
    class Tren_Marfa : public Tren {
        private:
            int cantitate;
            std::shared_ptr<std::string> produs;
        public: 
            Tren_Marfa();
            Tren_Marfa(std::string ruta, int nr_vagoane, int *numere_vagoane, int cantitate, std::shared_ptr<std::string> produs);
            Tren_Marfa(const Tren_Marfa& vechi);
            Tren_Marfa(Tren_Marfa&& vechi);
            ~Tren_Marfa();
            Tren_Marfa& operator=(const Tren_Marfa& vechi);
            Tren_Marfa& operator=(Tren_Marfa&& vechi);
            bool operator==(const Tren_Marfa& vechi);
            void adauga_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void sterge_vagon_personalizat(int numar_vagon, int cantitate_vagon);
            void schimba_produs(std::shared_ptr<std::string> produs);
            void afisare();
    };
}