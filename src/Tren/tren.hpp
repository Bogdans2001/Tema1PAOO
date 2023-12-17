#include <memory>


typedef struct Numar_vagon{
            int numar_vagon;
            int numar_transport;
            std::shared_ptr<struct Numar_vagon> next;
        }Numar_vagon;
    
typedef struct Numar_transport{
    int numar_vagon;
    int numar_transport;
}Numar_transport;

class Tren
{
    protected:
        int nr_vagoane; 
        std::unique_ptr<std::string> ruta;
        std::shared_ptr<Numar_vagon> numere_vagoane;
        bool find(int numar_vagon);
        bool parcurgere();
    public:
        Tren();
        Tren(std::string ruta, Numar_transport *numere_vagoane);
        virtual ~Tren();
        void adauga_vagon(Numar_transport node_values);
        void sterge_vagon(int node_value);
        virtual void afisare();
};
