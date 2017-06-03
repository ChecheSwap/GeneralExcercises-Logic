#ifndef COLA_1_H_INCLUDED
#define COLA_1_H_INCLUDED

#define slength 50
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <ctime>

using namespace std;

typedef struct xcliente{
    char nombre[20];
    char tramite[20];
    char horaLlegada[20];
    int numero;
}cliente;

void push(cliente);
cliente pop(void);
int colaLlena(void);
int colaVacia(void);
void listarCola(void);
int indice = 0, numero = 0;
char * getmytime(void);
time_t seed;
tm * hh;

cliente tmp;

char * btime = "%d:%d:%d";
char *etime;


cliente cola[slength];

void cola1(){
        int opcion;
        numero = 1;
        while(opcion != 4){

            system("cls");
            cout<<"*Opcion 1: Registro de cliente."<<endl;
            cout<<"*Opcion 2: Atender cliente."<<endl;
            cout<<"*Opcion 3: Clientes pendientes."<<endl;
            cout<<"*Opcion 4: Salir."<<endl;
            cout<<endl<<"->Ingrese Opcion: ";
            cin>>opcion;
            fflush(stdin);
            switch(opcion){
                case(1):{
                    if(colaLlena()==1){
                        cout<<"Cola llena."<<endl;
                        break;
                    }
                    cout<<"--Lugar #"<<numero<<endl;
                    cout<<"@Ingrese Nombre:";
                    gets(tmp.nombre);
                    cout<<"@Ingrese Tramite:";
                    gets(tmp.tramite);
                    strcpy(tmp.horaLlegada,getmytime());
                    tmp.numero = numero;
                    push(tmp);
                    break;
                }
                case(2):{
                    if(colaVacia()==1){
                        cout<<"No hay cliente en espera!"<<endl;
                        break;
                    }
                    tmp = pop();
                    cout<<"--Lugar #"<<tmp.numero<<endl;
                    cout<<"@Nombre: "<<tmp.nombre<<endl;
                    cout<<"@Tramite: "<<tmp.tramite<<endl;
                    cout<<"@Hora de llegada: "<<tmp.horaLlegada<<endl;
                    cout<<endl;
                    break;
                }
                case(3):{
                    if(indice == 0){
                        cout<<"No hay clientes en espera!"<<endl;
                    }
                    else{
                        listarCola();
                    }

                    break;
                }
                case(4):{
                    break;
                }
            }
            system("pause");
    }

}

void push(cliente cs){
        cola[indice]=cs;
        ++indice;
        ++numero;
}

cliente pop(void){
    tmp = cola[0];
    for(int x=1; x<indice; ++x){
        cola[x-1]=cola[x];
    }
    --indice;
    return tmp;
}

int colaLlena(void){
    if(indice==slength){
        return 1;
    }
    else{
        return 2;
    }
}
int colaVacia(void){
    if(indice == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void listarCola(void){
    for(int x=0; x<indice; ++x){
        cout<<"->Turno: "<<cola[x].numero<<endl;
        cout<<"-Nombre: "<<cola[x].nombre<<endl;
        cout<<"-Tramite: "<<cola[x].tramite<<endl;
        cout<<"-Hora de llegada: "<<cola[x].horaLlegada<<endl;
    }
    cout<<endl;
}

char* getmytime(void){
    seed = time(0);
    hh = localtime(&seed);
    if(etime){
        free(etime);
    }
    etime= new char[8]();
    sprintf(etime,btime,hh->tm_hour,hh->tm_min,hh->tm_sec);
    return etime;
}


#endif // COLA_1_H_INCLUDED
