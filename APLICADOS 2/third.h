#ifndef THIRD_H_INCLUDED
#define THIRD_H_INCLUDED
#define MAXCONT 100

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct sscontactos{
    int numero;
    char nombre[30];
    int dia,mes,anio;
    char telefono[20];
    char email[30];

    sscontactos(){
        this->cls();
    }

    void cls(void){

        this->numero=-1;
        for(int x=0; x<30;++x){
            this->nombre[x]=NULL;
        }
        this->dia=-1;
        this->mes=-1;
        this->anio=-1;
        for(int x=0; x<20;++x){
            this->telefono[x] = NULL;
        }
        for(int x=0; x<30;++x){
            this->email[x] = NULL;
        }
    }
}scontactos;

bool altacontacto(scontactos*,int&,scontactos&);
void sswap(scontactos&,scontactos&);
void modificar(scontactos*,int,scontactos&);
bool existe(scontactos*,int,int);
void printcontacto(scontactos&);
void cumpmes(scontactos*,int);
void cumpdia(scontactos*,int);
void edadcontactos(scontactos*,int);
void start(void){
    int opcion;
    scontactos contactos[MAXCONT];
    scontactos temp;
    int index =0;

    while(true){
        system("cls");
        cout<<"1) Alta de contacto. "<<endl;
        cout<<"2) Modificar contacto. "<<endl;
        cout<<"3) Cumpleaneros del mes. "<<endl;
        cout<<"4) Cumpleaneros del dia. "<<endl;
        cout<<"5) Edad de contacto. "<<endl;
        cout<<"6) Salir. "<<endl;
        cout<<endl<<">Ingrese Opcion: ";
        cin>>opcion;
        switch(opcion){
            case(1):{
                altacontacto(contactos,index,temp);
                break;
            }
            case(2):{
                modificar(contactos,index,temp);
                break;
            }
            case(3):{
                cumpmes(contactos,index);
                break;
            }
            case(4):{
                cumpdia(contactos,index);
                break;
            }
            case(5):{
                edadcontactos(contactos,index);
                break;
            }
            case(6):{
                cout<<"Hasta Luego!"<<endl;
                return;
            }

        }
    }
}

bool altacontacto(scontactos*contacto,int&index,scontactos&temp){
    bool flag =false;

    while(true){
        system("cls");

        if(index == MAXCONT){
            cerr<<"Cupo lleno!"<<endl;
            system("cls");
            return false;
        }
        cout<<"Desea Agregar Un Nuevo contacto? (-1 Para Salir, 1 Aceptar) >>";
        cin>>temp.numero;
        if(temp.numero == -1){
            if(!flag){
                return false;
            }
            else{
                return true;
            }
        }
        while(true){
            fflush(stdin);
            cout<<"Ingrese Nombre de Contacto: ";
            gets(temp.nombre);
            cout<<"Ingrese dia de nacimiento:";
            cin>>temp.dia;
            if(temp.dia > 31 || temp.dia < 1){
                cerr<<"Ingrese dia valido!"<<endl;
                break;
            }
            cout<<"Ingrese mes de nacimiento:";
            cin>>temp.mes;
            if(temp.mes > 12 || temp.mes < 1){
                cerr<<"Ingrese mes valido!"<<endl;
                break;
            }
            cout<<"Ingrese anio de nacimiento:";
            cin>>temp.anio;
            if(temp.anio < 1900 || temp.anio > 2017){
                cerr<<"Ingrese anio valido!"<<endl;
                break;
            }
            cout<<"Ingrese telefono de contacto: ";
            fflush(stdin);
            gets(temp.telefono);
            cout<<"Ingrese email de contacto: ";
            gets(temp.email);

            temp.numero = index;
            sswap(contacto[index],temp);
            flag=true;
            cout<<"Se ha dado de alta satisfactoriamente el contacto con numero: "<<index<<endl;
            temp.cls();
            ++index;
            break;
        }

        system("pause");

    }
}

void modificar(scontactos*contactos,int limit, scontactos& temp){
    bool flag = false;
    int exit = 0;
    char * prefix = new(nothrow)char[30]{NULL};

    while(true){
        system("cls");

        if(limit == 0){
            cerr<<"No existen contactos!";
            system("pause");
            return;
        }

        cout<<"Ingrese Iniciales de Nombre: ";
        fflush(stdin);
        gets(prefix);

        cout<<left<<setw(15)<<"Numero(ID)"<<setw(30)<<"Nombre"<<setw(25)<<"Fecha de nacimiento"<<setw(20)<<"Telefono"<<setw(30)<<"Email"<<endl;

        for(int x=0; x<limit; ++x){
            if(!(strstr(contactos[x].nombre,prefix)==NULL)){
                printcontacto(contactos[x]);
                if(!flag){
                    flag = true;
                }
            }
        }

        if(!flag){
            cerr<<"No existen coincidencias!"<<endl;
        }
        else{
            cout<<">>Ingrese Id:";
            cin>>temp.numero;
            if(existe(contactos,limit,temp.numero)){
                cout<<"Desea Modificar Contacto (1-Si , 2-Cualquier otra tecla) ?>>";
                cin>>temp.dia;

                if(temp.dia == 1){
                        int option=0;
                        while(option != 7){

                            system("cls");
                            cout<<left<<setw(15)<<"Numero(ID)"<<setw(30)<<"Nombre"<<setw(25)<<"Fecha de nacimiento"<<setw(20)<<"Telefono"<<setw(30)<<"Email"<<endl;
                            printcontacto(contactos[temp.numero]);
                            cout<<endl<<"Seleccione Opcion: "<<endl;
                            cout<<"1) Modificar Nombre"<<endl;
                            cout<<"2) Dia de nacimiento"<<endl;
                            cout<<"3) Mes de nacimiento"<<endl;
                            cout<<"4) Anio de nacimiento"<<endl;
                            cout<<"5) Telefono"<<endl;
                            cout<<"6) Correo electronico"<<endl;
                            cout<<"7) Regresar"<<endl;
                            cout<<"Opcion>>";
                            cin>>option;
                            system("cls");
                            fflush(stdin);
                            switch(option){
                                case(1):{

                                    cout<<"Ingrese nuevo nombre: ";
                                    gets(contactos[temp.numero].nombre);
                                    break;
                                }
                                case(2):{

                                    cout<<"Dia de nacimiento: ";
                                    cin>>contactos[temp.numero].dia;
                                    break;
                                }
                                case(3):{

                                    cout<<"Ingrese mes de nacimiento: ";
                                    cin>>contactos[temp.numero].mes;
                                    break;
                                }
                                case(4):{

                                    cout<<"Ingrese anio de nacimiento: ";
                                    cin>>contactos[temp.numero].anio;
                                    break;
                                }
                                case(5):{

                                    cout<<"Ingrese telefono: ";
                                    gets(contactos[temp.numero].telefono);
                                    break;
                                }
                                case(6):{
                                    cout<<"Ingrese correo: ";
                                    gets(contactos[temp.numero].email);
                                    break;
                                }
                                case(7):{
                                    break;
                                }
                                default:{
                                    cerr<<"Ingrese Opcion valida!"<<endl;
                                    break;
                                }

                            }
                            getchar();
                        }
                }
            }
            else{
                cerr<<"No existe contacto!"<<endl;
            }


        }

    cout<<"Desea regresar a menu> (1-Si, 2-No): ";
    cin>>exit;
    if(1==exit){
        return;
    }
    cout<<endl;
    system("pause");
    }
}
void edadcontactos(scontactos*contactos,int lim){

 if(lim==0){
   cerr<<"No existe contactos!"<<endl;
   system("pause");
   return;
 }

 int dia = 0, mes = 0, anio = 0,edad;
 while(true){
  system("cls");
  cout<<"Ingrese -1 Para salir..."<<endl<<endl;

  while(true){
   cout<<">>Ingrese dia Actual: ";
   cin>>dia;
   if(dia==-1){
    return;
   }
   if(dia<1 || dia > 31){
    cerr<<"Ingrese Dia Valido:";
    break;
   }
   cout<<">>Ingrese mes actual: ";
   cin>>mes;

   if(mes==-1){
    return;
   }

   if(mes>12 || mes<1){
    cerr<<"Ingrese mes valido!"<<endl;
    break;
   }

   cout<<">>Ingrese anio actual: ";
   cin>>anio;

   if(anio==-1){
    return;
   }

   if(anio>2017 || anio<1900){
    cerr<<"Ingrese anio valido!"<<endl;
    break;
   }
   cout<<endl<<endl;

   cout<<left<<setw(50)<<"Nombre"<<setw(25)<<"Edad"<<endl;
   for(int x=0; x<lim; ++x){

    if(mes < contactos[x].mes){
     edad = anio -contactos[x].anio;
    }
    else if(mes == contactos[x].mes){
     if(dia <= contactos[x].dia){
      edad = anio -contactos[x].anio;
     }
     else{
      edad = anio -contactos[x].anio - 1;
      if(edad < 0){
        ++edad;
      }
     }
    }
    else{
     edad = anio - contactos[x].anio - 1;
        if(edad < 0){
            ++edad;
        }
    }
    cout<<setw(50)<<contactos[x].nombre<<edad<<" Anios"<<endl;
   }
   break;
  }
  system("pause");
 }
}

void cumpmes(scontactos*contactos, int lim){
    int mes;
    bool flag = false;


    while(true){
        flag = false;
        system("cls");

        if(0==lim){
            cerr<<"No existen contactos!"<<endl;
            system("pause");
            return;
        }

            cout<<"Instrucciones: Ingrese mes, -1 para salir"<<endl<<endl<<">>>";
            cin>>mes;

            if(-1==mes){
                return;
            }
            else if(mes < 1 && 12 < mes){
                    cerr<<"Ingrese Mes Valido!"<<endl;
            }
            else{
                cout<<left<<setw(15)<<"Numero(ID)"<<setw(30)<<"Nombre"<<setw(25)<<"Fecha de nacimiento"<<setw(20)<<"Telefono"<<setw(30)<<"Email"<<endl;
                for(int x=0; x<lim;++x){

                    if(mes==contactos[x].mes){
                        printcontacto(contactos[x]);
                        if(!flag){
                            flag = true;
                        }
                    }

                }
                if(!flag){
                    cerr<<"No existen cumpleaneros en este mes!"<<endl;
                }
            }

        system("pause");
    }
}

void cumpdia(scontactos*contactos, int lim){
    int mes,dia;
    bool flag = false;


    while(true){
        flag = false;
        system("cls");

        if(0==lim){
            cerr<<"No existen contactos!"<<endl;
            system("pause");
            return;
        }

            cout<<"Instrucciones: Ingrese mes y dia, -1 para salir"<<endl<<endl<<">>Dia: ";
            cin>>dia;
            if(-1==dia){
                return;
            }
            else if(dia<1 || dia > 31){
                cerr<<"Ingrese dia valido!"<<endl;
            }
            else{
                cout<<">>Mes:";
                cin>>mes;

                if(-1==mes){
                    return;
                }
                else if(mes < 1 && 12 < mes){
                    cerr<<"Ingrese Mes Valido!"<<endl;
                }
                else{
                    cout<<left<<setw(15)<<"Numero(ID)"<<setw(30)<<"Nombre"<<setw(25)<<"Fecha de nacimiento"<<setw(20)<<"Telefono"<<setw(30)<<"Email"<<endl;
                    for(int x=0; x<lim;++x){

                        if(mes==contactos[x].mes&&dia==contactos[x].dia){
                            printcontacto(contactos[x]);
                            if(!flag){
                                flag = true;
                            }
                        }

                    }
                    if(!flag){
                        cerr<<"No existen cumpleaneros en este mes!"<<endl;
                    }
                }
            }
        system("pause");
    }
}

bool existe(scontactos*contactos,int lim, int id){
    for(int x=0; x<lim; ++x){
        if(contactos[x].numero==id){
            return true;
        }
    }

    return false;
}

void printcontacto(scontactos&pref){

    cout<<setw(15)<<pref.numero<<setw(30)<<pref.nombre<<setw(2)<<pref.dia<<"/"<<setw(2)<<pref.mes<<"/"<<pref.anio<<setw(15)<<" "<<setw(20)<<pref.telefono<<setw(30)<<pref.email<<endl;
}

void sswap(scontactos&DI,scontactos&SI){
    memcpy(&DI,&SI,sizeof(scontactos));
}


#endif // THIRD_H_INCLUDED
