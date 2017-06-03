#ifndef DOS_PILA_H_INCLUDED
#define DOS_PILA_H_INCLUDED

#define slength 5
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct xamigos{
    char nombre[30];
    char direccion[20];
    int edad;
}amigos;

int pilaLlena(void);
int pilaVacia();
void push(amigos);
amigos pop(void);
void listarPila(void);
amigos pila[slength];
int indice = 0;
amigos tmp;

void dosPila(){
    int opcion = 5;

    while(opcion != -1){
        system("cls");
        int valor;
        cout<<"->[1] Ingresar Amigo a la Pila."<<endl;
        cout<<"->[2] Sacar Amigo de la Pila."<<endl;
        cout<<"->[3] Pila Llena."<<endl;
        cout<<"->[4] Pila Vacia."<<endl;
        cout<<"->[5] Listar Amigos de la pila."<<endl;
        cout<<"====> Ingrese Valor: ";
        cin>>valor;
        cout<<endl;
        switch(valor){
            case(1):{
                if(pilaLlena()==0){
                    fflush(stdin);
                    cout<<"*Ingrese Nombre: ";
                    gets(tmp.nombre);
                    cout<<"*Ingrese direccion: ";
                    gets(tmp.direccion);
                    cout<<"*Ingrese edad: ";
                    cin>>tmp.edad;
                    push(tmp);
                }
                else{
                    cout<<"La pila esta llena!"<<endl;
                }
                break;
            }
            case(2):{
                if(pilaVacia()==0){
                    tmp = pop();
                    cout<<"*Nombre: "<<tmp.nombre<<endl;
                    cout<<"*Direccion: "<<tmp.direccion<<endl;
                    cout<<"*Edad: "<<tmp.edad<<endl<<endl;
                }
                else{
                    cout<<"La pila esta vacia!"<<endl;
                }
                break;
            }
            case(3):{
                if(pilaLlena()){
                    cout<<"La pila esta llena"<<endl;
                }
                else{
                    cout<<"La pila no esta llena"<<endl;
                }
                break;
            }
            case(4):{
                if(pilaVacia()){
                    cout<<"La pila esta vacia"<<endl;
                }
                else{
                    cout<<"La pila no esta vacia!"<<endl;
                }
                break;
            }
            case(5):{
                    listarPila();
                break;
            }
            case(-1):{
                cout<<"Hasta luego!"<<endl;
                break;
            }
            default:{
                cout<<"Ingrese Valor Correcto!"<<endl;
            }

        }
        system("pause");
    }
}


int pilaLlena(){
    if(indice == slength){
        return 1;
    }
    else{
        return false;
    }
}

int pilaVacia(){
    if(indice==0){
        return 1;
    }
    else{
        return 0;
    }
}

void push(amigos amigo){
    memcpy(&pila[indice],&amigo,sizeof(amigo));
    ++indice;
}

amigos pop(void){
    --indice;
    return pila[indice];
}

void listarPila(){
    for(int x=0; x<indice; ++x){
        cout<<"-Elemento #"<<x+1<<":"<<endl;
        cout<<"*Nombre: "<<pila[x].nombre<<endl;
        cout<<"*Direccion: "<<pila[x].direccion<<endl;
        cout<<"*Edad: "<<pila[x].edad<<endl<<endl;
    }
}
#endif // DOS_PILA_H_INCLUDED
