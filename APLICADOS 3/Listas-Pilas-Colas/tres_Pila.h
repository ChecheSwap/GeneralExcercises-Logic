#ifndef TRES_PILA_H_INCLUDED
#define TRES_PILA_H_INCLUDED
//EVALUACION DE EXPRESIONES MATEMATICAS EN POSTORDEN
#define slength 20
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int pila[slength];
int v1, v2;
char temporal =(char)NULL;
char expresion[20];

void push(int);
int pop(void);
int pilaLlena();
int pilaVacia();
void listarPila();
int indice = 0;

void tresPila(){
    cout<<"->Ingrese Expresion:";
    gets(expresion);

    if(strlen(expresion)<3){
        cout<<"Ingrese Cadena Valida!"<<endl;
    }
    else if(isdigit(expresion[0])&&isdigit(expresion[1])){
        for(int x=0; x<strlen(expresion); ++x){
            temporal = expresion[x];
            if(isdigit(temporal)){
                push(temporal-48);
            }
            else{

                v1 = pop();
                v2 = pop();

                switch(temporal){

                    case('+'):{
                        push(v2+v1);
                        break;
                    }
                    case('-'):{
                        push(v2-v1);
                        break;
                    }
                    case('*'):{
                        push(v2*v1);
                        break;
                    }
                    case('/'):{
                        push(v2/v1);
                        break;
                    }
                }
            }
        }
        cout<<"El resultado de la expresion es: "<<pop()<<endl;
    }
    else{
        cout<<"Ingrese Cadena Valida!"<<endl;
    }
}

void push(int n){
    pila[indice]=n;
    ++indice;
}

int pop(void){
    --indice;
    return pila[indice];
}

int pilaLlena(){
    if(indice == slength){
        return 1;
    }
    else{
        return 0;
    }
}

int pilaVacia(){
    if(indice == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void listarPila(){
    for(int x=0; x<indice; ++x){
        cout<<pila[indice]<<" ";
    }
    cout<<endl;
}



#endif // TRES_PILA_H_INCLUDED
