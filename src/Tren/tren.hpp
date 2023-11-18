class Tren
{
    protected:
        int dimensiune_ruta;
        char *ruta;
        int nr_vagoane;
        int *numere_vagoane;
        bool find(int numar_vagon);
        bool find_sterge(int numar_vagon);
    public:
        Tren(char *ruta, int dimensiune_ruta, int nr_vagoane, int *numere_vagoane);
        Tren(const Tren& vechi);
        Tren(Tren&& tren);
        virtual ~Tren();
        void adauga_vagon(int numar_vagon);
        void schimba_ruta(char *ruta_noua, int dimensiune_ruta);
        void sterge_vagon(int numar_vagon);
        void afisare();
};