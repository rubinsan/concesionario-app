#include "sistema.h"
#include <vector>

Sistema::Sistema(Fecha _f)
{
    f=_f;
}

Sistema::~Sistema(){}

void Sistema::bienvenida()
{
    cout<<"\n\n***********************************\nCONCESIONARIO DE NAVES ESPACIALES"<<endl;
    cout<<"***********************************"<<endl;
}

void Sistema::menu()
{
    vector <Nave*>lista_naves(0);
    vector <Propietario*>lista_propietarios(0);
    vector <Ventas>lista_ventas(0);
    string opcion1, opcion, idnave, idprop, especie, idhumano, idextraterrestre;
    unsigned short  num, nump, i;
    bool validar;

    lista_naves=CargarNaves (lista_naves);//carga de los datos de las naves en el sistema
    lista_propietarios=CargarPropietarios (lista_propietarios);//carga de los datos de los propietarios en el sistema
    lista_ventas=CargarVentas(lista_ventas);//carga de los datos de las ventas en el sistema

    do
    {
        cout<<"\n==========================\n     MENÚ  PRINCIPAL\n=========================="<<endl;
        cout<<"\nSeleccione un departamento de gestión:\n\n1.Naves\n2.Propietarios\n3.Ventas\n0.Salir\n\nOpción: ";
        cin>>opcion1;
        cout<<endl;
        while((opcion1[0]!='1' && opcion1[0]!='2' && opcion1[0]!='3' && opcion1[0]!='0') || opcion1.length()!=1)
        {
            cout<<"ERROR, por favor introduzca una opción correcta: ";
            cin>>opcion1;
            cout<<endl;
        }
        switch(opcion1[0])
        {
        case '1'://menu Naves
            do
            {
                cout<<"\n=======================\n   GESTIÓN DE NAVES\n======================="<<endl;
                cout<<"\nSeleccione una opción:\n1. Alta nave\n2. Modificar Nave\n3. Mostrar Naves\n4. Dar de baja una nave\n5. Ordenar naves por potencia\n0. Menú principal\n\nOpción: ";
                cin>>opcion;
                cout<<endl;
                while((opcion[0]!='1' && opcion[0]!='2' && opcion[0]!='3' && opcion[0]!='4' && opcion[0]!='5' && opcion[0]!='0') || opcion.length()!=1)
                {
                    cout<<"ERROR, por favor introduzca una opción correcta: ";
                    cin>>opcion;
                    cout<<endl;
                }
                switch(opcion[0])
                {
                case '1'://alta nave
                    lista_naves=AltaNaves (lista_naves, lista_propietarios, f);
                    break;

                case '2'://Modificar Nave
                    if(lista_naves.empty())
                    {
                        cout<<"\nNo hay naves registradas en el sistema"<<endl;
                        break;
                    }
                    cout<<"Introduzca el número de identificación de la nave (LNNNNLLL): ";
                    cin>>idnave;
                    cout<<endl;
                    while(ValidaIdNave(idnave))
                    {   cout<<"ERROR, por favor introduzca un número de identificación válido (LNNNNLLL): ";
                        cin>>idnave;
                        cout<<endl;
                    }
                    for (i=0; i<lista_naves.size(); i++)
                    {
                        if (lista_naves[i]->obtenerid()==idnave)
                        {
                            validar=true;
                            num=i;
                            break;
                        }
                        validar=false;
                    }
                    if (!validar)
                    {
                        cout<<"La nave no está dada de alta."<<endl;
                        break;
                    }
                    lista_naves[num]->modificar();
                    lista_naves[num]->mostrar();
                    break;

                case '3'://Mostrar naves

                    MostrarNaves (lista_naves);

                    break;

                case '4'://Eliminar naves
                    if(lista_naves.empty())
                    {
                        cout<<"\nNo hay naves registradas en el sistema.\n"<<endl;
                        break;
                    }
                    MostrarNaves (lista_naves);
                    cout<<"\n\nIntroduzca el número de identificación de la nave que va a ser eliminada (LNNNNLLL): ";
                    cin>>idnave;
                    cout<<endl;
                    while(ValidaIdNave(idnave))
                    {
                        cout<<"ERROR, por favor introduzca un número de identificación válido (LNNNNLLL): ";
                        cin>>idnave;
                        cout<<endl;
                    }
                    for (i=0; i<lista_naves.size(); i++)
                    {
                        if (lista_naves[i]->obtenerid()==idnave)
                        {
                            validar=true;
                            num=i;
                            break;
                        }
                        validar=false;
                    }
                    if (!validar)
                    {
                        cout<<"La nave no está dada de alta."<<endl;
                        break;
                    }
                    delete lista_naves[num];//liberamos memoria dinámica
                    lista_naves.erase(lista_naves.begin() + num);//eliminamos al propietario del vector
                    cout<<"\nLa nave se ha eliminado del sistema con éxito."<<endl;
                    break;

                case '5'://Potencia naves
                    if(lista_naves.empty())
                    {
                        cout<<"\nNo hay naves registradas.\n"<<endl;
                        break;
                    }

                    int potenciaarmas[lista_naves.size()],aux;//array de enteros para guardar las potencias de las naves
                    for(i=0;i<lista_naves.size();i++)//se guardan los valores de las potencias de forma desordenada
                    {
                        potenciaarmas[i]=lista_naves[i]->potencia_destructiva();
                    }
                    for(i=0;i<lista_naves.size();i++)//Meotdo burbuja para ordenar potencia de menor a mayor
                    {
                        for(unsigned int j=0;j<lista_naves.size();j++)
                        {
                            if(potenciaarmas[j] > potenciaarmas[j+1])
                            {
                                aux=potenciaarmas[j];
                                potenciaarmas[j]=potenciaarmas[j+1];
                                potenciaarmas[j+1]=aux;
                            }
                        }
                    }
                    cout<<"\nMATRÍCULA\tPOTENCIA"<<endl;
                    cout<<"==========================="<<endl;
                    for (int i=lista_naves.size(); i>=0; i--)//imprimir de mayor a menor
                    {
                        for(unsigned int j=0;j<lista_naves.size();j++)
                        {
                            if((lista_naves[j]->potencia_destructiva()==potenciaarmas[i]) && potenciaarmas[i]!=0)//no imprimimos la potencia de las naves que no tienen armas
                                cout<<lista_naves[j]->obtenerid()<<"\t"<<potenciaarmas[i]<<endl;
                        }

                    }

                }//fin switch de Menú naves
            }//fin do while de menu naves
            while(opcion[0]!='0'); break;

        case '2'://menú propietarios
            do
            {
                cout<<"\n==========================\n GESTIÓN DE PROPIETARIOS\n=========================="<<endl;
                cout<<"\n1. Alta propietario\n2. Modificar propietario\n3. Mostrar propietarios\n4. Baja propietario\n0. Menú principal\n\nOpción: ";
                cin>>opcion;
                cout<<endl;
                while((opcion[0]!='1' && opcion[0]!='2' && opcion[0]!='3' && opcion[0]!='4' && opcion[0]!='0') || opcion.length()!=1)
                {
                    cout<<"ERROR, por favor introduzca una opción correcta: ";
                    cin>>opcion;
                    cout<<endl;
                }

                switch(opcion[0])
                {
                case '1'://Alta propietario
                    lista_propietarios=AltaPropietarios (lista_propietarios);
                    break;

                case '2'://Modificar propietario
                    if(lista_propietarios.empty())
                    {
                        cout<<"\nNo hay propietarios registrados en el sistema"<<endl;
                        break;
                    }
                    cout<<"Por favor, la especie del propietario que desea modificar:\n1. Humano.\n2. Extraterrestre."<<endl;
                    cin>>especie;
                    cout<<endl;
                    while((especie[0]!='1' && especie[0]!='2') || especie.length()!=1)
                    {
                        cout<<"ERROR, por favor introduzca una opcion correcta: ";
                        cin>>especie;
                        cout<<endl;
                    }
                    if (especie[0]=='1')
                    {
                        cout<<"Introduzca el número de identificación del humano (NNNNNNNNL): "<<endl;
                        cin>>idhumano;
                        cout<<endl;
                        while(ValidaIdHumano(idhumano))
                        {
                            cout<<"ERROR, por favor asegúrese de que el formato sea el correcto (NNNNNNNNL): ";
                            cin>>idhumano;
                            cout<<endl;
                        }
                        for (i=0; i<lista_propietarios.size(); i++)
                        {
                            if (lista_propietarios[i]->obtenerid()==idhumano)
                            {
                                validar=true;
                                num=i;
                                break;
                            }
                            validar=false;
                        }
                        if (!validar)
                        {
                            cout<<"El humano no está dado de alta."<<endl;
                            break;
                        }
                        lista_propietarios[num]->modificar();
                        lista_propietarios[num]->mostrar();
                        break;
                    }

                    if (especie[0]=='2')
                    {
                        cout<<"Introduzca el número de identificación del extraterrestre (NNNNNNNNNN): "<<endl;
                        cin>>idextraterrestre;
                        cout<<endl;
                        while(ValidaIdExtra(idextraterrestre))
                        {
                            cout<<"ERROR, por favor asegúrese de que el formato sea el correcto (NNNNNNNNNN): ";
                            cin>>idextraterrestre;
                            cout<<endl;
                        }
                        for (i=0; i<lista_propietarios.size(); i++)
                        {
                            if (lista_propietarios[i]->obtenerid()==idextraterrestre)
                            {
                                validar=true;
                                num=i;
                                break;
                            }
                            validar=false;
                        }
                        if (!validar)
                        {
                            cout<<"El extraterrestre no está dado de alta."<<endl;
                            break;
                        }
                        lista_propietarios[num]->modificar();
                        lista_propietarios[num]->mostrar();
                        break;
                    }

                case '3'://mostrar propietarios
                    MostrarPropietarios (lista_propietarios);
                    break;

                case '4'://Baja propietario
                    if(lista_propietarios.empty())
                    {
                        cout<<"\nNo hay propietarios registrados en el sistema\n"<<endl;
                        break;
                    }
                    cout<<"Introduzca el número de identificación del propietario que desea dar de baja: ";
                    cin>>idprop;
                    cout<<endl;
                    while(ValidaIdHumano(idprop) && ValidaIdExtra(idprop))
                    {
                        cout<<"ERROR por favor, introduzca una identificación de propietario válida: ";
                        cin>>idprop;
                        cout<<endl;
                    }
                    for (i=0; i<lista_propietarios.size(); i++)
                    {
                        if (lista_propietarios[i]->obtenerid()==idprop)
                        {
                            validar=true;
                            num=i;
                            break;
                        }
                        validar=false;
                    }
                    if (!validar)
                    {
                        cout<<"El usuario no está dado de alta."<<endl;
                        break;
                    }
                    delete lista_propietarios[num];//liberamos memoria dinámica
                    lista_propietarios.erase(lista_propietarios.begin() + num);//eliminamos al propietario del vector
                    cout<<"\nEl propietario se ha eliminado del sistema con éxito."<<endl;
                    break;
                }//fin switch menú propietarios
            }//fin do while menú propietarios
            while(opcion[0]!='0');break;

        case '3'://Menú Ventas
            do
            {
                cout<<"\n=======================\n   GESTIÓN DE VENTAS\n======================="<<endl;
                cout<<"\n1. Mostrar Ventas.\n2. Buscar ventas por fecha.\n3. Venta Nave\n4. Buscar compras de un propietario\n5. Mostrar ventas por intervalos de tiempo.\n0. Menú principal\n\nOpción: ";
                cin>>opcion;
                cout<<endl;
                while((opcion[0]!='1' && opcion[0]!='2' && opcion[0]!='3' && opcion[0]!='4' && opcion[0]!='5' && opcion[0]!='0') || opcion.length()!=1)
                {
                    cout<<"ERROR, por favor introduzca una opción correcta: ";
                    cin>>opcion;
                    cout<<endl;
                }
                switch(opcion[0])
                {
                case '1'://Mostrar Ventas
                    if(lista_ventas.empty())
                    {
                        cout<<"\nNo hay ventas registradas.\n"<<endl;
                        break;
                    }
                    cout<<"\n\tVENTAS\n"<<endl;
                    cout<<"FECHA\t\tCOMPRADOR\tNAVE"<<endl;
                    cout<<"=========================================="<<endl;
                    for (i=0; i<lista_ventas.size(); i++)
                    {
                        lista_ventas[i].mostrar();
                    }
                    break;

                case '2'://buscar ventas por fecha
                {
                    if(lista_ventas.empty())
                    {
                        cout<<"\nNo hay ventas registradas.\n"<<endl;
                        break;
                    }
                    Fecha busqueda=IntroducirFecha();
                    validar=true;
                    for(i=0;i<lista_ventas.size();i++)
                    {
                        if(busqueda==lista_ventas[i].obtenerFecha())
                        {
                            lista_ventas[i].mostrar();
                            validar=false;
                        }
                    }
                    if (validar)cout<<"\nNo existen ventas registradas en esa fecha."<<endl;
                    break;
                }

                case '3'://Venta de nave
                    if(lista_propietarios.empty())
                    {
                        cout<<"\nNo hay propietarios registrados a los que vender una nave.\n"<<endl;
                        break;
                    }
                    if(lista_naves.empty())
                    {
                        cout<<"\nNo hay naves disponibles para la venta.\n"<<endl;
                        break;
                    }
                    MostrarNaves (lista_naves);
                    cout<<"\n\nIntroduzca el número de identificación de la nave que va a ser vendida (LNNNNLLL): ";
                    cin>>idnave;
                    cout<<endl;
                    while(ValidaIdNave(idnave))
                    {
                        cout<<"ERROR, por favor introduzca un número de identificación válido (LNNNNLLL): ";
                        cin>>idnave;
                        cout<<endl;
                    }
                    for (i=0; i<lista_naves.size(); i++)
                    {
                        if (lista_naves[i]->obtenerid()==idnave)
                        {
                            validar=true;
                            num=i;
                            break;
                        }
                        validar=false;
                    }
                    if (!validar)
                    {
                        cout<<"La nave no está dada de alta."<<endl;
                        break;
                    }
                    MostrarPropietarios (lista_propietarios);
                    cout<<"\n\nIntroduzca el número de identificación del comprador: ";
                    cin>>idprop;
                    cout<<endl;
                    while(ValidaIdHumano(idprop) && ValidaIdExtra(idprop))
                    {
                        cout<<"ERROR por favor, introduzca una identificación de propietario válida: ";
                        cin>>idprop;
                        cout<<endl;
                    }
                    for (i=0; i<lista_propietarios.size(); i++)
                    {
                        if (lista_propietarios[i]->obtenerid()==idprop)
                        {
                            validar=true;
                            nump=i;
                            break;
                        }
                        validar=false;
                    }
                    if (!validar)
                    {
                        cout<<"El propietario no está dado de alta.";
                        break;
                    }
                    if (PermitirVenta(lista_naves[num], lista_propietarios[nump]))
                    {
                        cout<<"La especie del propietario no puede manejar esa nave. Recuerda:\nLos humanos no pueden comprar destructores y los extraterrestres no pueden comprar estaciones espaciales";
                        break;
                    }
                    if(idprop==lista_naves[num]->obtenerprop())
                    {
                        cout<<"ERROR: La nave ya pertenece a ese propietario"<<endl; break;
                    }
                    lista_naves[num]->asignar_propietario(lista_propietarios[nump]->obtenerid());
                    lista_ventas.push_back(Ventas(f,lista_propietarios[nump]->obtenerid(),lista_naves[num]->obtenerid()));

                    delete lista_naves[num];//liberamos memoria dinámica
                    lista_naves.erase(lista_naves.begin() + num);//eliminamos la nave del vector

                    cout<<"La transacción se ha realizado con exito.";
                    break;

                case '4'://Buscar compras de un propietario
                    cout<<"\nIntroduzca el número de identificación del propietario: ";
                    cin>>idprop;
                    cout<<endl;
                    while(ValidaIdHumano(idprop) && ValidaIdExtra(idprop))
                    {
                        cout<<"ERROR por favor, introduzca una identificación de propietario válida: ";
                        cin>>idprop;
                        cout<<endl;
                    }
                    validar=true;
                    for (i=0; i<lista_ventas.size(); i++)
                    {
                        if (lista_ventas[i].obtenerComprador()==idprop)
                        {
                            lista_ventas[i].mostrar();
                            validar=false;
                        }
                    }
                    if (validar) cout<<"No se han encontrado compras por parte del usuario "<<idprop<<endl;
                    break;

                case '5'://mostrar las ventas realizadas en un intervalo de tiempo
                {
                    if(lista_ventas.empty())
                    {
                        cout<<"\nNo hay ventas registradas.\n"<<endl;
                        break;
                    }
                    cout<<"A continuación intoduzca la fecha a partir de la cual se van a mostar las ventas."<<endl;
                    Fecha limitinf=IntroducirFecha();
                    cout<<endl;
                    cout<<"Ahora intoduzca la fecha límite."<<endl;
                    Fecha limitsup=IntroducirFecha();
                    cout<<endl;
                    validar=true;
                    for (i=0; i<lista_ventas.size(); i++)//una vez creados los limites se comparan con el calcular de cada fecha y si encaja se imprime
                    {
                        if (lista_ventas[i].calculo()<=limitsup.calculo() && lista_ventas[i].calculo()>=limitinf.calculo())
                        {
                            lista_ventas[i].mostrar();
                            validar=false;
                        }
                    }
                    if (validar) cout<<"No se han encontrado compras por parte del usuario "<<idprop<<endl;
                    break;
                }

                }//fin de switch menú ventas
            }//fin do while menú ventas

            while(opcion[0]!='0');break;

        case '0'://Cerrar programa y escribir en ficheros
            ofstream escribenaves("Naves.txt");
            ofstream escribeprop("Propietarios.txt");
            ofstream escribeventas("Ventas.txt");
            for (i=0; i<lista_naves.size(); i++)
            {
                escribenaves<<lista_naves[i]->display();
            }
            for (i=0; i<lista_propietarios.size(); i++)
            {
                escribeprop<<lista_propietarios[i]->display();
            }
            for (i=0; i<lista_ventas.size(); i++)
            {
                escribeventas<<lista_ventas[i].display();
            }

            cout<<"\n*********************************FIN DEL PROGRAMA*********************************"<<endl;break;

        }//switch de Menu principal

    }while(opcion1[0]!='0');//fin do while menu principal
}//fin del método Menu de sistema
