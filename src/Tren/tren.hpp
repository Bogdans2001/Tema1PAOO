class Tren
{
    private:
        char *ruta;
        int nr_vagoane;
        int *numere_vagoane;
    
    public:
        Tren(char *ruta, int nr_vagoane, int *numere_vagoane);
        Tren(const Tren& vechi);
        Tren(Tren&& tren);
        void adauga_vagon(int numar_vagon);
        void schimba_ruta(char *ruta_noua);
        void sterge_vagon(int numar_vagon);
        void afisare();
};