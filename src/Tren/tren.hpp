class Tren
{
    private:
        int dimensiune_ruta;
        char *ruta;
        int nr_vagoane;
        int *numere_vagoane;
    
    public:
        Tren(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane);
        Tren(const Tren& vechi);
        Tren(Tren&& tren);
        ~Tren();
        void adauga_vagon(int numar_vagon);
        void schimba_ruta(char *ruta_noua, int dimensiune_ruta);
        void sterge_vagon(int numar_vagon);
        void afisare();
};