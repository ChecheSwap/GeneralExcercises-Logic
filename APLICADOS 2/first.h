#ifndef FIRST_H_INCLUDED
#define FIRST_H_INCLUDED
#define MAXEMP 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iomanip>
using namespace std;

typedef struct sempleados{
    int numero;
    char nombre[50];
    char puesto[50];
    double sueldodiario;
    int diastrabajados;
    int antiguedad;
    double sueldointegrado;

    sempleados(){
        this->numero = -1;

        for(int x=0; x<50; ++x){
            this->nombre[x] = NULL;
            this->puesto[x] = NULL;
        }

        this->sueldodiario = -1;
        this->diastrabajados = -1;
        this->antiguedad = -1;
        this->sueldointegrado = -1;
    }

    void cls(void){
        this->numero = -1;
        for(int x=0; x<50; ++x){
            this->nombre[x] = NULL;
            this->puesto[x] = NULL;
        }
        this->sueldodiario = -1;
        this->diastrabajados = -1;
        this->antiguedad = -1;
        this->sueldointegrado = -1;
    }

}empleado;

bool altaemp(empleado*,empleado&,int&);
bool existID(int,int,empleado*);
void busquedaempleado(empleado*,int);
bool calcnomina(empleado*,int&);
bool nominaordenada(empleado*, int,empleado&);
void busquedaempleado(empleado*,int);

void start(void){
    system("MODE CON COLS=220 LINES=50");
    int index = 0, option = -1;
    empleado empleados[MAXEMP];
    empleado temploc;

    while(!(option == 5)){
        system("cls");
        cout<<"->Opcion #1"<<endl<<"Alta de Empleados"<<endl<<endl;
        cout<<"->Opcion #2"<<endl<<"Calculo de Nomina"<<endl<<endl;
        cout<<"->Opcion #3"<<endl<<"Mostrar Nomina Ordenada por sueldo Integrado"<<endl<<endl;
        cout<<"->Opcion #4"<<endl<<"Busqueda de empleado"<<endl<<endl;
        cout<<"->Opcion #5"<<endl<<"Salir"<<endl<<endl;
        cout<<">>>Ingrese Opcion:";
        cin>>option;

        switch(option){
            case(1):{
                altaemp(empleados,temploc,index);
                break;
            }
            case(2):{
                calcnomina(empleados,index);
                break;
            }
            case(3):{
                nominaordenada(empleados,index,temploc);
                break;
            }
            case(4):{
                busquedaempleado(empleados,index);
                break;
            }
            case(5):{
                break;
            }
            default:{
                break;
            }
        }
    }

}

bool altaemp(empleado* emp,empleado &empleado,int&current){

     bool flag = false;

    if(current==MAXEMP){
        cerr<<"Se ha cumplido el cupo maximo permitido"<<endl;
        system("cls");
        return false;
    }
    else{

        while(true){
            system("cls");
            cout<<">Ingrese Numero de empleado (-1 = Salir a menu) :";
            cin>>empleado.numero;

            if(empleado.numero == -1){

                if(flag){
                    return true;
                }
                else{
                    return false;
                }

            }

            if(!(existID(empleado.numero,current,emp))){
                fflush(stdin);
                cout<<endl<<">Ingrese Nombre de empleado: ";
                gets(empleado.nombre);
                fflush(stdin);
                cout<<endl<<">Ingrese Puesto de empleado: ";
                gets(empleado.puesto);
                cout<<endl<<">Ingrese anios trabajados: ";
                cin>>empleado.antiguedad;
                cout<<endl<<">Ingrese Sueldo Diario: ";
                cin>>empleado.sueldodiario;

                cout<<endl;

                {
                    memcpy(&emp[current],&empleado,sizeof(empleado));
                    flag = true;
                }

                cout<<"Se ha dado de alta, satisfactoriamente el empleado con Numero: "<<empleado.numero<<endl;
                empleado.cls();
                ++current;

            }else{
                cerr<<"Este ID, ya existe!"<<endl;
            }
            system("pause");
        }
    }
}

bool calcnomina(empleado* emp,int&current){

    bool flag = false;

    if(current == 0){
        system("cls");
        cerr<<"No existe empleados!"<<endl;
        system("pause");
        return false;
    }

    for(int x=0; x<current; ++x){
        system("cls");
        cout<<">>>Numero Empleado = "<<emp[x].numero<<endl;
        cout<<">Ingrese Dias trabajados, (-1 Para Salir): ";
        cin>>emp[x].diastrabajados;

        if(emp[x].diastrabajados == -1){
            if(flag){
                return true;
            }
            else{
                return false;
            }
        }
        emp[x].sueldointegrado = (emp[x].sueldodiario*15)*(emp[x].antiguedad/100);
        emp[x].sueldointegrado += (emp[x].diastrabajados * emp[x].sueldodiario);
        flag = true;
        system("pause");
    }


    return true;
}

bool nominaordenada(empleado*emp, int current,empleado&temp){

    empleado empleados[current];
    system("cls");
    if(current == 0){
        cerr<<"No existen empleados!"<<endl;
        system("pause");
        return false;
    }

    for(int x=0; x<current; ++x){
        if(emp[x].sueldointegrado==-1){
            cerr<<"Debe de calcular nomina para todos los empleados!"<<endl;
            system("pause");
            return false;
        }
    }

    for(int x=0; x<current; ++x){
        memcpy(&empleados[x],&emp[x],sizeof(empleado));
    }

    for(int x=0; x<current; ++x){
        for(int y=0; y<(current - 1)-x&& empleados[y].sueldointegrado<empleados[y+1].sueldointegrado; ++y){
                memcpy(&temp,&empleados[y],sizeof(empleado));
                memcpy(&empleados[y],&empleados[y+1],sizeof(empleado));
                memcpy(&empleados[y+1],&temp,sizeof(empleado));
        }
    }

    temp.cls();
    cout<<left<<setw(25)<<"Numero de empleado"<<setw(50)<<"Nombre"<<setw(50)<<"Puesto"<<setw(20)<<"Sueldo Diario"<<setw(20)<<"Dias trabajados"<<setw(20)<<"Antiguedad"<<setw(20)<<"Sueldo Integrado"<<endl;
    for(int x=0; x<current; ++x){
        cout<<setw(25)<<empleados[x].numero<<setw(50);
        cout<<(empleados[x].nombre)<<setw(50)<<(empleados[x].puesto);
        cout<<setw(20)<<empleados[x].sueldodiario<<setw(20)<<empleados[x].diastrabajados<<setw(20)<<empleados[x].antiguedad<<setw(20)<<empleados[x].sueldointegrado<<endl;
    }
    system("pause");
    return true;
}

void busquedaempleado(empleado*empleados,int current){

    system("cls");
    if(current == 0){
        cerr<<"No existen empleados!"<<endl;
        system("pause");
        return;
    }

    int id = -1;

    while(true){
        bool flag=false;
        system("cls");
        cout<<"Ingrese numero de empleado, (-1 Para salir a menu)>> ";
        cin>>id;
        if(id==-1){
            return;
        }

        for(int x=0; x<current; ++x){
            if(empleados[x].numero == id){
                cout<<left<<setw(35)<<"Numero de empleado"<<setw(50)<<"Nombre"<<setw(50)<<"Puesto"<<setw(20)<<"Sueldo Diario"<<setw(20)<<"Dias trabajados"<<setw(20)<<"Antiguedad"<<setw(20)<<"Sueldo Integrado"<<endl;
                cout<<setw(35)<<empleados[x].numero<<setw(50);
                cout<<(empleados[x].nombre);
                cout<<setw(50)<<(empleados[x].puesto);
                cout<<setw(20)<<empleados[x].sueldodiario<<setw(20)<<empleados[x].diastrabajados<<setw(20)<<empleados[x].antiguedad<<setw(20)<<empleados[x].sueldointegrado<<endl;
                flag=true;
                break;
            }

        }
        if(!flag){
            cerr<<"No se ha encontrado dicho Id, intente de nuevo."<<endl;
        }

        system("pause");

    }
}

bool existID(int number, int index, empleado * empleados){
    for(int x=0; x<index;++x){
        if(empleados[x].numero == number){
            return true;
        }
    }
    return false;
}
#endif // FIRST_H_INCLUDED
