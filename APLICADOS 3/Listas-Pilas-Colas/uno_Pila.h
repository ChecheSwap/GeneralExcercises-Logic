#ifndef UNO_PILA_H_INCLUDED
#define UNO_PILA_H_INCLUDED
#define slength 5
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;


int pilaLlena(void);
int pilaVacia();
void push(int);
int pop(void);
void listarPila(void);
int pila[slength];
void unoPila();
int indice = 0;

void unoPila(){
    int opcion = 5;

    while(opcion != -1){
        system("cls");
        int valor;
        cout<<"->[1] Ingresar Dato a la Pila."<<endl;
        cout<<"->[2] Sacar Dato de la Pila."<<endl;
        cout<<"->[3] Pila Llena."<<endl;
        cout<<"->[4] Pila Vacia."<<endl;
        cout<<"->[5] Listar Elementos de la pila."<<endl;
        cout<<"====> Ingrese Opcion: ";
        cin>>valor;
        cout<<endl;

        switch(valor){
            case(1):{
                if(!pilaLlena()){
                    cout<<"*Ingrese Valor:";
                    cin>>valor;
                    push(valor);
                }
                else{
                    cout<<"La pila esta llena!"<<endl;
                }
                break;
            }
            case(2):{
                if(pilaVacia()==0){
                    cout<<pop()<<endl;
                }
                else{
                    cout<<"La pila esta vacia!"<<endl;
                }
                break;
            }
            case(3):{
                if(pilaLlena()==1){
                    cout<<"La pila esta llena"<<endl;
                }
                else{
                    cout<<"La pila no esta llena"<<endl;
                }
                break;
            }
            case(4):{
                if(pilaVacia()==1){
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
                opcion = -1;
                break;
            }
            default:{
                cout<<"Ingrese Opcion Correcta!"<<endl;
                break;
            }

        }
        system("pause");
    }
}

void listarPila(void){
    for(int x=0; x<slength; ++x){
        cout<<pila[x]<<" ";
    }
    cout<<endl;
}

int pilaLlena(void){
    if(indice == slength){
        return 1;
    }
    else{
        return 0;
    }
}

int pilaVacia(void){
    if(!indice){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int number){
    pila[indice] = number;
    ++indice;
}

int pop(void){
    --indice;
    return pila[indice];
}
#endif // UNO_PILA_H_INCLUDED
