class Tienda
{
    public:
        Tienda();
        Tienda(string nombre);
        void SetNombre(string nombre);
        string GetNombre();

    private:
        string Nombre;
};
class Usuario
{
    public:
        Usuario();
        Usuario(string name, string contrasenia, string id);
        void SetNombre(string nombre);
        string GetNombre();
        void SetContrasenia(string contrasenia);
        string GetContrasenia();
        void SetID(string id);
        string GetID();
    protected:
        string Nombre;
        string Contrasenia;
        string ID;
};
class Objeto
{
    private:
        float Precio;
        int ID;
        string Nombre;
    public:
        Objeto();
        Objeto(string nombre, float precio, int id);
        void SetID(int id);
        int GetID();
        void SetPrecio(float precio);
        int GetPrecio();
        void SetNombre(string nombre);
        string GetNombre();
};
class Carrito
{
    private:
        Objeto ObjetosC[20];
    public:
        Carrito();
        void ImprimirCarrito();
        void SetCarrito(Objeto obc);
        Objeto GetObjeto(int x);
        void BorrarCarrito(Objeto vacio);
};
class Comprador : public Usuario
{
    public:
        Comprador();
        Comprador(string name, string contrasenia, string id, double balance);
        void SetBalance(double balance);
        double GetBalance();
        void AgregarCarrito(Objeto ob);
        void VerCarrito();
        void ComprarCarrito();
        void EliminarCarrito();
    private:
        double Balance;
        Carrito carrito;
};