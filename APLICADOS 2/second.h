#ifndef SECOND_H_INCLUDED
#define SECOND_H_INCLUDED
#define MAXAMIGOS 2


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct friends{

    char nombre[30];
    int edad;
    char direccion[50];

    friends(){
        for(int x=0; x<30; ++x){
            this->nombre[x]=NULL;
        }
        this->edad = -1;
        for(int x=0; x<50;++x){
            this->direccion[x]=NULL;
        }
    }

}samigos;


void start(void){

    samigos amigos[MAXAMIGOS];
    samigos temp;
    for(int x=0; x<MAXAMIGOS; ++x){
        system("cls");
        cout<<">Ingrese Nombre de Sujeto #"<<x+1<<":";
        gets(amigos[x].nombre);
        cout<<">Ingrese edad de Sujeto #"<<x+1<<":";
        cin>>amigos[x].edad;
        cout<<">Ingrese direccion de Sujeto #"<<x+1<<":";
        fflush(stdin);
        gets(amigos[x].direccion);
    }

    int in, out, t;
    system("cls");

    for(t = MAXAMIGOS/2; t>0; t/=2){
        for(in = t; in<MAXAMIGOS; ++in){
            for(out = in-t; out>=0 && amigos[out].edad > amigos[out+t].edad; out-=t){
                memcpy(&temp,&amigos[out],sizeof(samigos));
                memcpy(&amigos[out],&amigos[out+t],sizeof(samigos));
                memcpy(&amigos[out+t],&temp,sizeof(samigos));
            }
        }
    }

    cout<<left<<setw(15)<<"EDAD"<<setw(30)<<"NOMBRE"<<setw(50)<<"DIRECCION"<<endl;
    for(int x=0; x<MAXAMIGOS; ++x){
        cout<<setw(15)<<amigos[x].edad<<setw(30)<<amigos[x].nombre<<setw(50)<<amigos[x].direccion<<endl;
    }

}

#endif // SECOND_H_INCLUDED
