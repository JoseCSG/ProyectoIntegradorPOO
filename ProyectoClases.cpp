Tienda::Tienda()
{
    Nombre=" ";
}
Tienda::Tienda(string nombre)
{
    this->Nombre=nombre;
}
void Tienda::SetNombre(string nombre)
{
    this->Nombre=nombre;   
}
string Tienda::GetNombre()
{
    return Nombre;
}
Usuario::Usuario()
{
    Nombre=" ";
    Contrasenia=" ";
    ID=" ";
}
Usuario::Usuario(string nombre,string contrasenia,string id)
{
    this->Nombre=nombre;
    this->Contrasenia=contrasenia;
    this->ID=id;
}
void Usuario::SetNombre(string nombre)
{
    this->Nombre=nombre;
}
string Usuario::GetNombre()
{
    return Nombre;
}
void Usuario::SetContrasenia(string contrasenia)
{
    this->Contrasenia=contrasenia;
}
string Usuario::GetContrasenia()
{
    return Contrasenia;
}
void Usuario::SetID(string id)
{
    this->ID=id;
}
string Usuario::GetID()
{
    return ID;
}
Objeto::Objeto()
{
    Precio=0.0;
    ID=00000000;
    Nombre=" ";
}
Objeto::Objeto(string nombre, float precio, int id)
{
    this->Nombre=nombre;
    this->Precio=precio;
    this->ID=id;
}
void Objeto::SetID(int id)
{
    this->ID=id;
}
void Objeto::SetPrecio(float precio)
{
    this->Precio=precio;
}
void Objeto::SetNombre(string nombre)
{
    this->Nombre=nombre;
}
int Objeto::GetID()
{
    return ID;
}
int Objeto::GetPrecio()
{
    return Precio;
}
string Objeto::GetNombre()
{
    return Nombre;
}
Comprador::Comprador()
{   
    Nombre=" ";
    Contrasenia=" ";
    ID=" ";
    Balance=0;
}
Comprador::Comprador(string nombre,string contrasenia,string id,double balance)
{
    this->Nombre=nombre;
    this->Contrasenia=contrasenia;
    this->ID=id;
    this->Balance=balance;
}
void Comprador::SetBalance(double balance)
{
    this->Balance=Balance+balance;
}
double Comprador::GetBalance()
{
    return Balance;
}
void Comprador::AgregarCarrito(Objeto ob)
{
    carrito.SetCarrito(ob);
}
void Comprador::ComprarCarrito()
{
    double sum=0;
    //suma del precio de los objetos del carrito
    for (int i = 0; i < 20; i++)
    {
        sum+=carrito.GetObjeto(i).GetPrecio();
    }
    if(sum>Balance)
    {
        cout<<"No cuenta con los fondos necesarios"<<endl;
        cout<<"Fondos necesarios: "<< sum <<endl;
        cout<<"Fondos actuales: "<< Balance<<endl;
    }
    else
    {
        cout<<"Total a pagar: "<<sum<<endl;
        Balance-=sum;
        this->EliminarCarrito();
        cout<<"*Compra exitosa*"<<endl;
        cout<<"Dinero en la cuenta: "<<Balance<<endl;
    }
}
void Comprador::EliminarCarrito()
{
    cout<<"*Eliminando el carrito*"<<endl;
    Objeto vacio;
    for (int i = 0; i <20; i++)
    {
        if(carrito.GetObjeto(i).GetNombre()!=" ") //si el nombre del objeto no está en blanco, lo cambia por un objeto vacio
        {
            carrito.BorrarCarrito(vacio);
        }
    }
}
void Comprador::VerCarrito()
{
    carrito.ImprimirCarrito();
}
Carrito::Carrito()
{
    Objeto ObjetosC[20];
}
void Carrito::ImprimirCarrito()
{
    cout<<"*Viendo los objetos del carrito*"<<endl;
    for (int i = 0; i < 20; i++)
    {
        if(ObjetosC[i].GetNombre()==" ") //si el nombre del objeto del arreglo esta en blanco, lo salta
        {
            continue;
        }
        else
        {
            cout<<ObjetosC[i].GetNombre()<<", "; //muestra el nombre del objeto
        }
        
    }
    cout<<endl;
}
void Carrito::SetCarrito(Objeto obc)
{
    for (int i = 0; i < 20; i++)
    {
        if(ObjetosC[i].GetNombre()==" ") //si el nombre del objeto del arreglo esta en blanco, pone el objeto pedido en su lugar
        {
            ObjetosC[i]=obc;
            break;
        }
    }
}
Objeto Carrito::GetObjeto(int x)
{
    return ObjetosC[x]; //regresa el objeto con ese indice
}
void Carrito::BorrarCarrito(Objeto vacio)
{
    for (int i = 0; i < 20; i++)
    {
        if(ObjetosC[i].GetNombre()!=" ")    
        {
            ObjetosC[i]=vacio;  //si el nombre del objeto no está en blanco, lo cambia por un objeto vacio
            break;
        }
    }
}