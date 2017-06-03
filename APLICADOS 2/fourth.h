#ifndef FOURTH_H_INCLUDED
#define FOURTH_H_INCLUDED

#define MAXROW 20
#define MAXCOL 6
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

enum pago{TARJETA_CREDITO = 2, EFECTIVO = 1};

typedef struct sspasajeros{
    bool reservado;
    char nombre[30];
    char fecha[25];
    int tipopago;

    sspasajeros(){
        this->cls();
    }
    void cls(){
        this->reservado = false;
        for(int x=0; x<30; ++x){
            this->nombre[x] = NULL;
        }
        for(int x=0; x<10; ++x){
            this->fecha[x]= NULL;
        }
        this->tipopago = NULL;
    }
}spasajeros;

void reservar(spasajeros[MAXROW][MAXCOL]);
char * getdate(void);
int getcolumnint(char);
void cancelar(spasajeros[MAXROW][MAXCOL]);
char getcolumnchar(int);
void reservados(spasajeros[MAXROW][MAXCOL]);
void disponibles(spasajeros[MAXROW][MAXCOL]);



void start(void){
    int opcion;

    spasajeros reservaciones[MAXROW][MAXCOL];

    while(true){
        system("cls");
        cout<<"1) Reservar Asiento."<<endl;
        cout<<"2) Cancelar una reservacion."<<endl;
        cout<<"3) Consultar reservaciones."<<endl;
        cout<<"4) Asientos disponibles."<<endl;

        cout<<">>Ingrese opcion: ";
        cin>>opcion;

        switch(opcion){
            case(1):{
                reservar(reservaciones);
                break;
            }
            case(2):{
                cancelar(reservaciones);
                break;
            }
            case(3):{
                reservados(reservaciones);
                break;
            }
            case(4):{
                disponibles(reservaciones);
                break;
            }
            case(5):{
                cout<<"Hasta luego"<<endl;
                return;
                break;
            }
            default:{
                break;
            }

        }
    }
}

void disponibles(spasajeros pasajeros[MAXROW][MAXCOL]){
    system("cls");

    cout<<"Asientos disponibles"<<endl<<endl<<"    A  B  C  D  E  F"<<endl<<endl;
    for(int x = 0; x<MAXROW; ++x){
        cout<<setw(4)<<left<<x+1;
        for(int y=0; y<MAXCOL; ++y){
            if(!pasajeros[x][y].reservado){
            cout<<"x  ";
            }
            else{
                cout<<"   ";
            }
        }
        cout<<endl;
    }
    system("pause");
    return;
}

void reservados(spasajeros pasajeros[MAXROW][MAXCOL]){
    bool flag = false;

    system("cls");
    cout<<left<<setw(30)<<"Nombre "<<setw(28)<<"Fecha"<<setw(25)<<"Tipo Pago"<<"Asiento"<<endl;

    for(int x = 0; x<MAXROW; ++x){
        for(int y=0; y<MAXCOL; ++y){
            if(pasajeros[x][y].reservado){
                if(!flag){
                    flag = true;
                }
                cout<<setw(30)<<pasajeros[x][y].nombre<<setw(28)<<pasajeros[x][y].fecha<<setw(25);
                if(pasajeros[x][y].tipopago == TARJETA_CREDITO){
                    cout<<"Tarjeta de credito";
                }else{
                    cout<<"Efectivo";
                }
                cout<<getcolumnchar(y)<<x+1;
                cout<<endl;
            }
        }
    }
    if(!flag){
        cerr<<"No existe reservaciones aun!"<<endl;
    }
    system("pause");
}

void cancelar(spasajeros pasajeros[MAXROW][MAXCOL]){
    char col;
    int column;
    int row;
    int ok;
    while(true){
        system("cls");
        cout<<"Regresar a menu = Z..."<<endl;

        cout<<"Ingrese Columna: ";
        cin>>col;
        if(col == 'z' || col =='Z'){
            return;
        }
        cout<<"Ingrese fila: ";
        cin>>row;

        if(row == 'z' || row =='Z'){
            return;
        }

        column = getcolumnint(col);
        --row;
        if(column > -1 && row > -1 && row < 21){
            if(pasajeros[row][column].reservado){
                cout<<"Desea cancelar esta reservacion? (1-SI,2-NO): ";
                cin>>ok;
                if(ok == 1){
                    pasajeros[row][column].cls();
                    cout<<"Se ha cancelado esta reservacion!"<<endl;
                }
            }
            else{
                cout<<"Este aciento esta disponible!"<<endl;
            }
        }
        else{
            cerr<<"Ingrese Fila/Columna valida!"<<endl;
        }
        system("pause");
    }
}

void reservar(spasajeros pasajeros[MAXROW][MAXCOL]){
    char column;
    int col;
    int row;

    while(true){
        system("cls");
        cout<<"INGRESE (z) PARA PARA REGRESAR A MENU..."<<endl<<endl;
        cout<<">>Ingrese Columna: ";
        cin>>column;

        if(column=='z'||column=='Z'){
            return;
        }
        cout<<">>Ingrese Fila: ";
        cin>>row;
        if((char)row == 'z'||(char)row=='Z'){
            return;
        }
        col = getcolumnint(column);

        if(col > -1 && row >= 0 && row <21){
            --row;
            if(!pasajeros[row][col].reservado){
                cout<<">>Ingrese Nombre del pasajero: ";
                fflush(stdin);
                gets(pasajeros[row][col].nombre);
                cout<<">>Tipo de pago (1-Efectivo, 2-Tarjeta): ";
                cin>>pasajeros[row][col].tipopago;
                if(pasajeros[row][col].tipopago == TARJETA_CREDITO || pasajeros[row][col].tipopago == EFECTIVO){
                    strcpy(pasajeros[row][col].fecha,getdate());
                    pasajeros[row][col].reservado = true;
                    cout<<"Se ha reservado el asiento!"<<endl;
                }
                else{
                    cerr<<"Tipo de pago invalido!"<<endl;
                    pasajeros[row][col].cls();
                }
            }
            else{
                cerr<<"Este asiento ya se ha reservado!"<<endl;
            }
        }
        else{
            cerr<<"Ingrese fila/columna valida!"<<endl;
        }

        system("pause");
    }

}


char getcolumnchar(int c){
    switch(c){
        case(0):{
            return 'A';
            break;
        }

        case(1):{
            return 'B';
            break;
        }
        case(2):{
            return 'C';
            break;
        }
        case(3):{
            return 'D';
            break;
        }
        case(4):{
            return 'E';
            break;
        }
        case(5):{
            return 'F';
            break;
        }
        default:{
            break;
        }
    }
    return NULL;
}

int getcolumnint(char c){
    switch(c){
        case('a'):
        case('A'):{
            return 0;
            break;
        }
        case('b'):
        case('B'):{
            return 1;
            break;
        }
        case('c'):
        case('C'):{
            return 2;
            break;
        }
        case('d'):
        case('D'):{
            return 3;
            break;
        }
        case('e'):
        case('E'):{
            return 4;
            break;
        }
        case('f'):
        case('F'):{
            return 5;
            break;
        }
        default:{
            break;
        }
    }
    return -1;
}
char * getdate(void){
    time_t seed = time(NULL);
    char * arr = ctime(&seed);
    arr[24]=NULL;
    return arr;
}

#endif // FOURTH_H_INCLUDED
