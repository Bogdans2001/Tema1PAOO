namespace Vehicul{
    class VehiculSine{
        public:
            virtual bool adauga_vagon(int numar_vagon)=0;
            virtual bool sterge_vagon(int numar_vagon)=0;
            virtual void afisare()=0;
    };
}