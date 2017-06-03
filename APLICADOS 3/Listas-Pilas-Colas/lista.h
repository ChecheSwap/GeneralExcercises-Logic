#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct xbase{
    int id;
    xbase * next;
}base;

base * lista = NULL;
base * driver;
base * tmp;

bool listavacia();
void insertarPrincipio(int);
void insertarFinal(int);
void eliminarPrincipio();
void eliminarFinal();
void listarLista();

void mlista(){

    int valor;

    while(true){

        system("cls");

        cout<<"-> 1 Agregar Numero Al principio."<<endl;
        cout<<"-> 2 Agregar Numero Al final."<<endl;
        cout<<"-> 3 Eliminar Numero Al princio."<<endl;
        cout<<"-> 4 Eliminar Numero Al final."<<endl;
        cout<<"-> 5 Listar Lista."<<endl;
        cout<<"-> 6 Salir."<<endl;
        cout<<"Ingrese Opcion:";
        cin>>valor;


        switch(valor){
            case(1):{
                cout<<"->Ingrese Valor: ";
                cin>>valor;
                insertarPrincipio(valor);
                break;
            }
            case(2):{
                cout<<"->Ingrese Valor: ";
                cin>>valor;
                insertarFinal(valor);
                break;
            }
            case(3):{
                if(listavacia()){
                    cerr<<"La lista esta vacia!"<<endl;
                    break;
                }
                eliminarPrincipio();
                break;
            }
            case(4):{
                if(listavacia()){
                    cerr<<"La lista esta vacia!"<<endl;
                    break;
                }
                eliminarFinal();
                break;
            }
            case(5):{
                if(listavacia()){
                    cerr<<"La lista esta vacia!"<<endl;
                    break;
                }
                listarLista();
                break;
            }
            case(6):{
                cout<<"Hasta Luego!"<<endl;
                system("pause");
                return;
            }

        }
       system("pause");
    }

}

void listarLista(){
    driver = lista;

    while(!(driver==NULL)){
        cout<<driver->id<<" ";
        driver=driver->next;
    }
    cout<<endl;
}

void insertarPrincipio(int n){
    tmp = (base*)malloc(sizeof(base));
    if(!tmp){
        cerr<<"Problema al inicializar lista."<<endl;
    }
    tmp->id = n;
    tmp->next=lista;
    lista=tmp;
}

void insertarFinal(int n){
    if(!lista){
        insertarPrincipio(n);
        return;
    }

    driver = lista;

    while(driver->next != NULL){
        driver = driver->next;
    }

    tmp = (base*)malloc(sizeof(base));
    tmp->id=n;
    tmp->next = NULL;
    driver->next=tmp;
}

void eliminarPrincipio(){
    tmp = lista;
    lista = lista->next;
    free(tmp);
}

void eliminarFinal(){
    driver = lista;

    if(driver->next == NULL){
        eliminarPrincipio();
        return;
    }

    while(!(driver->next->next==NULL)){
        driver= driver->next;
    }

    free(driver->next);
    driver->next = NULL;
}

bool listavacia(){
    if(!lista){
        return true;
    }
    else{
        return false;
    }
}

#endif // LISTA_H_INCLUDED
