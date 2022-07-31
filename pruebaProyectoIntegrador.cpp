/*
Hecho por: 
José Carlos Sánchez Gómez A01174050
José Andres Orantes Guillen A01174130
03/12/2021
*/
#include <iostream>
#include <locale.h>
#include <math.h>
#include <string>
#include <locale.h>
using namespace std;
#include "Proyecto.h"
#include "ProyectoClases.cpp"

int main()
{
    setlocale(LC_ALL, "");
    int op=0,op1=0; 
    bool continuar=true,entrar=true,comprando=true;
    string ID, password;
    Tienda tienda("Resposteria de los Pepes"); //Creamos nuestro objeto tienda
    //Creamos todos nuestros objetos a vender
    Objeto ob1("Pastel de MilkyWay",200.0,1),ob2("Magdalena",9.0,2),ob3("Pan tradicional (5)",20.99,3);
    Objeto ob4("Muffin",20.0,4),ob5("Pepito",30,5),ob6("Cupcake",15,6);
    Objeto ob7("Pastel helado",350,7),ob8("Pastisetas (10)",99.99,8),ob9("Frappuccino",60,9),ob10("Cafe americano",30.0,10);
    //Creamos a los dos compradores
    Comprador usuario1("José Sánchez","perritos","jcsg",500.0);
    Comprador usuario2("José Orantes","pillo1","shadow",500);
    while(entrar)
    {
        cout<<"Ingrese su ID: ";
        cin>>ID;
        cout<<"Ingrese su contrasenia: ";
        cin>>password;
        if(usuario1.GetID()==ID && usuario1.GetContrasenia()==password)
        {
            cout<<"Bienvenido a "<<tienda.GetNombre()<<" "<<usuario1.GetNombre()<<endl;
            while(continuar)
            {
                //mostramos el menu de opciones del comprador
                cout<<"¿Qué desea hacer?"<<endl;
                cout<<"1.-Ver objetos disponibles"<<endl;
                cout<<"2.-Ver Carrito"<<endl;
                cout<<"3.-Eliminar Carrito"<<endl;
                cout<<"4.-Comprar Carrito"<<endl;
                cout<<"5.-Ingresar dinero"<<endl;
                cout<<"6.-Ver Datos"<<endl;
                cout<<"7.-Salir"<<endl;
                cin>>op;
                if (op==1)
                {
                    //se muestran todas las opciones con nombre y precio
                    comprando=true;
                    cout<<"Los articulos disponibles son: "<<endl;
                    cout<<"1.-"<<ob1.GetNombre()<<" $"<<ob1.GetPrecio()<<endl;
                    cout<<"2.-"<<ob2.GetNombre()<<" $"<<ob2.GetPrecio()<<endl;
                    cout<<"3.-"<<ob3.GetNombre()<<" $"<<ob3.GetPrecio()<<endl;
                    cout<<"4.-"<<ob4.GetNombre()<<" $"<<ob4.GetPrecio()<<endl;
                    cout<<"5.-"<<ob5.GetNombre()<<" $"<<ob5.GetPrecio()<<endl;
                    cout<<"6.-"<<ob6.GetNombre()<<" $"<<ob6.GetPrecio()<<endl;
                    cout<<"7.-"<<ob7.GetNombre()<<" $"<<ob7.GetPrecio()<<endl;
                    cout<<"8.-"<<ob8.GetNombre()<<" $"<<ob8.GetPrecio()<<endl;
                    cout<<"9.-"<<ob9.GetNombre()<<" $"<<ob9.GetPrecio()<<endl;
                    cout<<"10.-"<<ob10.GetNombre()<<" $"<<ob10.GetPrecio()<<endl;
                    while(comprando)
                    {
                        cout<<"¿Qué quiere agregar a su carrito? (ingresa el número, 11 para terminar)"<<endl;
                        cin>>op1;
                        //se agrega el objeto escogido al carrito
                        switch (op1)
                        {
                        case 1:
                            usuario1.AgregarCarrito(ob1);
                            break;
                        case 2:
                            usuario1.AgregarCarrito(ob2);
                            break;
                        case 3:
                            usuario1.AgregarCarrito(ob3);
                            break;
                        case 4:
                            usuario1.AgregarCarrito(ob4);
                            break;
                        case 5:
                            usuario1.AgregarCarrito(ob5);
                            break;
                        case 6:
                            usuario1.AgregarCarrito(ob6);
                            break;
                        case 7:
                            usuario1.AgregarCarrito(ob7);
                            break; 
                        case 8:
                            usuario1.AgregarCarrito(ob8);
                            break; 
                        case 9:
                            usuario1.AgregarCarrito(ob9);
                            break; 
                        case 10:
                            usuario1.AgregarCarrito(ob10);
                            break;
                        case 11:
                            comprando=false;
                            break;                          
                        default:
                            cout<<"Ingrese una opción correcta"<<endl;
                            break;
                        }
                    }
                }
                else if (op==2)
                {
                    //se muestran todos los objetos en el carro
                    usuario1.VerCarrito();
                }
                else if (op==3)
                {
                    //se eliminan todos los objetos en el carro
                    usuario1.EliminarCarrito();
                    cout<<endl;
                }
                else if (op==4)
                {
                    //se compran los objetos en el carrito, y se resta el total del balance
                    usuario1.ComprarCarrito();
                    cout<<endl;
                }
                else if (op==5)
                {
                    //se añade dinero al balance del comprador, y se muestra
                    double balanceN=0;
                    cout<<"Balance actual: "<<usuario1.GetBalance()<<endl;
                    cout<<"¿Cuánto dinero gusta ingresar? ";
                    cin>>balanceN;
                    usuario1.SetBalance(balanceN);
                    cout<<"Balance actual: "<<usuario1.GetBalance()<<endl;
                    cout<<endl;
                }
                else if (op==6)
                {
                    //se muestran los datos del comprador
                    cout<<"ID: "<<usuario1.GetID()<<endl;
                    cout<<"Usuario: "<<usuario1.GetNombre()<<endl;
                    cout<<"Contraseña: "<<usuario1.GetContrasenia()<<endl;
                    cout<<"Balance actual: "<<usuario1.GetBalance()<<endl;
                    cout<<endl;
                }
                else if (op==7)
                {
                    //se termina el programa
                    cout<<"Gracias por usar nuestro servicio"<<endl;
                    break;
                }
                else
                {
                    //en caso de elegir una opcion no especificada
                    cout<<"Ingrese una opcion correcta"<<endl;
                    cout<<endl;
                }
            }
            break;
        }
        else if(usuario2.GetID()==ID && usuario2.GetContrasenia()==password)
        {
            cout<<"Bienvenido a "<<tienda.GetNombre()<<" "<<usuario2.GetNombre()<<endl;
            while(continuar)
            {
                //mostramos el menú de opciones del comprador
                cout<<"¿Qué desea hacer?"<<endl;
                cout<<"1.-Ver objetos disponibles"<<endl;
                cout<<"2.-Ver Carrito"<<endl;
                cout<<"3.-Eliminar Carrito"<<endl;
                cout<<"4.-Comprar Carrito"<<endl;
                cout<<"5.-Ingresar dinero"<<endl;
                cout<<"6.-Ver Datos"<<endl;
                cout<<"7.-Salir"<<endl;
                cin>>op;
                if (op==1)
                {
                    //se muestran todas las opciones con nombre y precio
                    comprando=true;
                    cout<<"Los articulos disponibles son: "<<endl;
                    cout<<"1.-"<<ob1.GetNombre()<<" $"<<ob1.GetPrecio()<<endl;
                    cout<<"2.-"<<ob2.GetNombre()<<" $"<<ob2.GetPrecio()<<endl;
                    cout<<"3.-"<<ob3.GetNombre()<<" $"<<ob3.GetPrecio()<<endl;
                    cout<<"4.-"<<ob4.GetNombre()<<" $"<<ob4.GetPrecio()<<endl;
                    cout<<"5.-"<<ob5.GetNombre()<<" $"<<ob5.GetPrecio()<<endl;
                    cout<<"6.-"<<ob6.GetNombre()<<" $"<<ob6.GetPrecio()<<endl;
                    cout<<"7.-"<<ob7.GetNombre()<<" $"<<ob7.GetPrecio()<<endl;
                    cout<<"8.-"<<ob8.GetNombre()<<" $"<<ob8.GetPrecio()<<endl;
                    cout<<"9.-"<<ob9.GetNombre()<<" $"<<ob9.GetPrecio()<<endl;
                    cout<<"10.-"<<ob10.GetNombre()<<" $"<<ob10.GetPrecio()<<endl;
                    while(comprando)
                    {
                        cout<<"¿Qué quiere agregar a su carrito? (ingresa el número, 11 para terminar)"<<endl;
                        cin>>op1;
                        //se agrega el objeto escogido al carrito
                        switch (op1)
                        {
                        case 1:
                            usuario2.AgregarCarrito(ob1);
                            break;
                        case 2:
                            usuario2.AgregarCarrito(ob2);
                            break;
                        case 3:
                            usuario2.AgregarCarrito(ob3);
                            break;
                        case 4:
                            usuario2.AgregarCarrito(ob4);
                            break;
                        case 5:
                            usuario2.AgregarCarrito(ob5);
                            break;
                        case 6:
                            usuario2.AgregarCarrito(ob6);
                            break;
                        case 7:
                            usuario2.AgregarCarrito(ob7);
                            break; 
                        case 8:
                            usuario2.AgregarCarrito(ob8);
                            break; 
                        case 9:
                            usuario2.AgregarCarrito(ob9);
                            break; 
                        case 10:
                            usuario2.AgregarCarrito(ob10);
                            break;
                        case 11:
                            comprando=false;
                            break;                          
                        default:
                            cout<<"Ingrese una opción correcta"<<endl;
                            break;
                        }
                    }
                }
                else if (op==2)
                {
                    //se muestran todos los obejtos en el carro
                    usuario2.VerCarrito();
                    cout<<endl;
                }
                else if (op==3)
                {
                    //se eliminan todos los objetos del carro
                    usuario2.EliminarCarrito();
                    cout<<endl;
                }
                else if (op==4)
                {
                    //se compran los objetos en el carrito, y se resta el total del balance
                    usuario2.ComprarCarrito();
                    cout<<endl;
                }
                else if (op==5)
                {
                    //se añade dinero al balance del comprador, y se muestra
                    double balanceN=0;
                    cout<<"Balance actual: "<<usuario2.GetBalance()<<endl;
                    cout<<"¿Cuánto dinero gusta ingresar? ";
                    cin>>balanceN;
                    usuario2.SetBalance(balanceN);
                    cout<<"Balance actual: "<<usuario2.GetBalance()<<endl;
                    cout<<endl;
                }
                else if (op==6)
                {
                    //se muestran los datos del comprador
                    cout<<"ID: "<<usuario2.GetID()<<endl;
                    cout<<"Usuario: "<<usuario2.GetNombre()<<endl;
                    cout<<"Contraseña: "<<usuario2.GetContrasenia()<<endl;
                    cout<<"Balance actual: "<<usuario2.GetBalance()<<endl;
                    cout<<endl;
                }
                else if (op==7)
                {
                    //se termina el programa
                    cout<<"Gracias por usar nuestro servicio"<<endl;
                    break;
                }
                else
                {
                    //en caso de elegir una opcion no especificada
                    cout<<"Ingrese una opcion correcta"<<endl;
                    cout<<endl;
                }
            }
            break;
        }
        else
        {
            cout<<"La contraseña o el usuario son incorrectos"<<endl;
        }
    }
    system("pause");
    return 0; 
}