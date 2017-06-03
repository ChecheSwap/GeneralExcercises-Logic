#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

void printMenu();
int getIndexColumn(char);
char getCharColumn(int);

int main(void){

    int asientos[20][6];
    char nombres[120][20];
    int option = 0; int index = -1; int current = 0; int fila=-1;
    char asientoColumna;

    for(int x=0; x<20; x++)
    {
        for(int y=0; y<6; y++)
        {
            asientos[x][y]=-1;
        }
    }

    while(option != 5)
    {
        system("cls");
        printMenu();
        cout<<"Ingrese Opcion: ";
        cin>>option;
        cout<<endl;
        switch(option)
        {
                case 1:
                {
                    cout<<"Ingrese Columna del asiento que desea reservar: ";
                    cin>>asientoColumna;
                    cout<<endl<<"Ingrese Fila del asiento que desea reservar: ";
                    cin>>fila;
                    cout<<endl;

                    if(asientos[fila-1][getIndexColumn(asientoColumna)] == -1)
                    {
                        ++current;
                        ++index;
                        cin.ignore();
                        cout<<"Ingrese Nombre del Pasajero: ";
                        fflush(stdin);
                        gets(nombres[index]);
                        asientos[fila-1][getIndexColumn(asientoColumna)] = index;
                        cout<<endl<<"Se ha reservado dicho evento!"<<endl;

                    }
                    else
                    {
                        cout<<"Dicho Asiento esta ocupado, pruebe con otro!"<<endl;
                    }
                    break;
                }
                case 2:
                {
                    cout<<"Cancelar Reservacion"<<endl<<"Ingrese Letra de columna asiento:";
                    cin>>asientoColumna;
                    cout<<endl<<"Ingrese Fila de asiento:";
                    cin>>fila;
                    if(asientos[fila-1][getIndexColumn(asientoColumna)] == -1)
                    {
                        cout<<"Este asiento esta vacio! "<<endl;
                    }
                    else
                    {
                        cout<<"Desea Calcelar La reservacion ? (1-Si)";
                        cin>>option;
                        if(option == 1){
                            asientos[fila-1][getIndexColumn(asientoColumna)] = -1;
                            --current;
                            cout<<"Se ha cancelado la reservacion"<<endl;
                        }

                    }
                    break;
                }
                case 3:
                {
                    cout<<"Reservaciones..."<<endl;
                    if(current > 0)
                    {
                    for(int asientoFila = 0; asientoFila<20; asientoFila++)
                    {
                        for(int ascol = 0; ascol<6; ascol++)
                        {
                            if(!(asientos[asientoFila][ascol]==-1))
                            {

                                cout<<"Asiento: ";
                                cout<<asientoFila+1<<" "<<getCharColumn(ascol)<<" ";
                                int temp = asientos[asientoFila][asientoColumna];
                                fflush(stdout);
                                cout<<nombres[temp]<<endl;

                            }
                        }
                    }
                    }
                    else
                    {
                        cout<<"No existen Reservaciones!"<<endl;
                    }
                    break;
                }
                case 4:
                {
                    cout<<"Asientos Disponibles..."<<endl;
                    cout<<"   A  B  C  D  E  F"<<endl;
                    for(int asientoFila = 0; asientoFila<20; asientoFila++)
                    {
                        if(asientoFila+1 < 10){
                            cout<<asientoFila+1<<"  ";
                        }
                        else{
                            cout<<asientoFila+1<<" ";
                        }


                        for(int ascol = 0; ascol<6; ascol++)
                        {
                            if(asientos[asientoFila][ascol]==-1)
                            {
                                cout<<"+  ";
                            }
                            else{
                                cout<<"   ";
                            }
                        }
                        cout<<endl;
                    }
                    break;
                }
                case 5:
                {
                    cout<<"Hasta Luego!"<<endl;
                    break;
                }
        }
        system("pause");
    }
}


void printMenu(void)
{
	for(int x=0; x<=55; x++)
	{
		cout<<"*";
	}
	cout<<endl<<"    1.- RESERVAR ASIENTO"<<endl;
	cout<<"    2.- CANCELAR RESERVACION"<<endl;
	cout<<"    3.- CONSULTAR RESERVACIONES"<<endl;
	cout<<"    4.- MOSTRAR ASIENTOS DISPONIBLES"<<endl;
	cout<<"    5.- SALIR"<<endl;
	for(int x=0; x<=55; x++)
	{
		cout<<"*";
	}
	cout<<endl;
	return;
}


char getCharColumn(int c){

char val = (char)NULL;

switch(c)
{
	case 0:
	{
	val = 'A';
	break;
	}
	case 1:
	{
	val = 'B';
	break;
	}

	case 2:
	{
	val = 'C';
	break;
	}

	case 3:
	{
	val = 'D';
	break;
	}

	case 4:
	{
	val = 'E';
	break;
	}
	case 5:
	{
	val = 'F';
	break;
	}
	default:
	{
		//There is not possible
	 break;
	}
}
return val;
}

int getIndexColumn(char c)
{
int val = -1;

switch(c)
{
	case 'a':
	case 'A':
	{
	val = 0;
	break;
	}
	case'b':
	case'B':
	{
	val = 1;
	break;
	}
	case 'c':
	case 'C':
	{
	val = 2;
	break;
	}
	case 'D':
	case 'd':
	{
	val = 3;
	break;
	}
	case 'e':
	case 'E':
	{
	val = 4;
	break;
	}
	case 'F':
	case 'f':
	{
	val = 5;
	break;
	}
	default:
	{
	 break;
	 //There is not possible
	}
}

return val;
}


