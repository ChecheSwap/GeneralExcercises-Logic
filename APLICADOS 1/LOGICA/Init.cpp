//@Code By: Jesús José Navarrete Baca(CheCheSwap))<=33
#include <iostream>
#include <locale>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include "checheSwap.h"
#include <new>
#include <time.h>
#include <algorithm>
#include <random>

void one(void);
void two(void);
void three(void);
void four(void);
void five(void);
void six(void);
void seven(void);
void eight(void);
void nine(void);
void ten(void);
void eleven(void);
void twelve(void);
void thirteen(void);
void fourteen(void);
void fifteen(void);
void sixteen(void);
void seventeen(void);
void eighteen(void);
void nineteen(void);
void twenty(void);
using namespace std;

int main()
{
    eighteen();
    return 0;
}

void one(void){

    bool flag = false;
    while(!flag)
    {
        char month[20]; int day = -1, year = 0; bool bisiesto = false;
        system("cls");
        flag = true;

        while(flag){
        cout<<"Ingrese dia: ";
        cin>>day;
        cin.ignore();
        cout<<endl<<"Ingrese Mes:";
        gets(month);
        cout<<endl<<"Ingrese Year:";
        cin>>year;
        cout<<endl;
            if(year > 0 && day >0){
               flag=false;
            }
            else{
            cerr<<"***********************************"<<endl<<"Ingrese datos Validos!"<<endl;
            }
        }

        if((year%100 != 0 && year%4 ==0)||(year%400 ==0)){
            bisiesto = true;
        }

        for(int x =0; x<strlen(month); x++)
        {
            month[x]=toupper(month[x]);
        }

        if((strcmp(month,"ENERO"))==0){
           if(day>=1 && 19>=day){
               cout<<"Capricornio!"<<endl;
           }
           else if(day>=20 && 31>=day){
               cout<<"Acuario!"<<endl;
           }
           else{
            cerr<<"Enero Solo tiene 31 dias."<<endl;
           }
           flag = true;
        }

        if((strcmp(month,"FEBRERO"))==0){
            if(day>=1 && 18>=day){
                cout<<"Acuario!"<<endl;
            }
            else if(day>=19 && 28>=day){
                cout<<"Piscis!"<<endl;
            }
            else if(bisiesto){
                if(29 == day){
                    cout<<"Piscis!"<<endl;
                }}
                else{
                    cerr<<"Dia Invalido!"<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"MARZO"))==0){
            if(day>=1 && 20>=day){
                cout<<"Piscis!"<<endl;
            }
            else if(day>=21 && 31>=day){
                cout<<"Aries!"<<endl;
            }
                else{
                    cerr<<"Marzo solo tiene 31 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"ABRIL"))==0){
            if(day>=1 && 19>=day){
                cout<<"Aries!"<<endl;
            }
            else if(day>=20 && 30>=day){
                cout<<"Tauro!"<<endl;
            }
                else{
                    cerr<<"Abril solo tiene 30 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"MAYO"))==0){
            if(day>=1 && 20>=day){
                cout<<"Tauro!"<<endl;
            }
            else if(day>=21 && 31>=day){
                cout<<"Geminis!"<<endl;
            }
                else{
                    cerr<<"Mayo solo tiene 31 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"JUNIO"))==0){
            if(day>=1 && 20>=day){
                cout<<"Geminis!"<<endl;
            }
            else if(day>=21 && 30>=day){
                cout<<"Cancer!"<<endl;
            }
                else{
                    cerr<<"Junio solo tiene 30 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"JULIO"))==0){
            if(day>=1 && 22>=day){
                cout<<"Cancer!"<<endl;
            }
            else if(day>=23 && 31>=day){
                cout<<"Leo!"<<endl;
            }
                else{
                    cerr<<"Julio solo tiene 31 dias."<<endl;
                }
                flag = true;
        }


        if((strcmp(month,"AGOSTO"))==0){
            if(day>=1 && 22>=day){
                cout<<"Leo!"<<endl;
            }
            else if(day>=23 && 31>=day){
                cout<<"Virgo!"<<endl;
            }
                else{
                    cerr<<"Agosto solo tiene 31 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"SEPTIEMBRE"))==0){
            if(day>=1 && 22>=day){
                cout<<"Virgo!"<<endl;
            }
            else if(day>=23 && 30>=day){
                cout<<"Libra!"<<endl;
            }
                else{
                    cerr<<"Septiembre solo tiene 30 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"OCTUBRE"))==0){
            if(day>=1 && 22>=day){
                cout<<"Libra!"<<endl;
            }
            else if(day>=23 && 31>=day){
                cout<<"Escorpio!"<<endl;
            }
                else{
                    cerr<<"Octubre solo tiene 31 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"NOVIEMBRE"))==0){
            if(day>=1 && 21>=day){
                cout<<"Escorpio!"<<endl;
            }
            else if(day>=22 && 30>=day){
                cout<<"Sagitario!"<<endl;
            }
                else{
                    cerr<<"Noviembre solo tiene 30 dias."<<endl;
                }
                flag = true;
        }

        if((strcmp(month,"DICIEMBRE"))==0){
            if(day>=1 && 21>=day){
                cout<<"Sagitario!"<<endl;
            }
            else if(day>=22 && 31>=day){
                cout<<"Capricornio!"<<endl;
            }
                else{
                    cerr<<"Diciembre solo tiene 31 dias."<<endl;
                }
                flag = true;
        }

        if(!flag){
            cerr<<"Ingrese Mes Valido!"<<endl;
        }

        cout<<"Presione Ctrl+Z para salir, de lo contrario presione 2...";
        cin>>day;

        if(2 == day){
            flag = false;
        }
        system("pause");
}}

void two(void){
    bool flag = false;

    while(!flag)
    {
        system("cls");
        double monedas[6], billetes[6];
        const double xbilletes[]{500,200,100,50,20},xmonedas[]{10,5,2,1,0.50};
        billetes[5] = 0;
        monedas[5]=0;

        for(int x=0; x<5; ++x){
            cout<<"Billetes de $"<<xbilletes[x]<<":";
            cin>>billetes[x];
            cout<<endl;
        }

        for(int x=0; x<5; ++x){
            cout<<"Monedas de $"<<xmonedas[x]<<":";
            cin>>monedas[x];
            cout<<endl;
        }

        for(int out=1; out<=2; ++out){//1 billetes 2 monedas

            for(int x=0; x<5; ++x){
                if(1==out){
                    billetes[5]+=billetes[x]*xbilletes[x];
                }
                else{
                    monedas[5]+=monedas[x]*xmonedas[x];
                }
            }
        }

        cout<<"Total de dinero en Billetes: $"<<billetes[5]<<endl;
        cout<<"Total de dinero en Monedas: $"<<monedas[5]<<endl;
        cout<<"Total Neto: $"<<billetes[5]+monedas[5]<<endl;

        cout<<"Desea Salir? 1-SI , NO: Cualquier otra tecla...";
        cin>>monedas[0];
        if(monedas[0]==1){
            flag = true;
        }
    }
}

void three(void){
    char h = (char)205, v = (char)186;
    double records[4]={}, base[4]={},temp=0;
    bool flag = true;
    for(int x=0; x<21; ++x){
        cout<<h;
    }
    cout<<endl;
    cout<<"       HORARIO    "<<endl;
     for(int x=0; x<21; ++x){
        cout<<h;
    }
    cout<<endl;
    cout<<"1|  8 AM -  4 PM"<<endl;
    cout<<"2|  4 PM -  8 PM"<<endl;
    cout<<"3|  8 PM - 12 AM"<<endl;
    cout<<"4| 12 AM -  8 AM"<<endl;
    for(int x=0; x<21; ++x){
        cout<<h;
    }
    cout<<endl<<"Ingrese sueldo Base por 8 Horas : ";
    cin>>base[0];
    base[0]/=8;
    base[1]=((base[0]/100)*25)+base[0];
    base[2]=((base[0]/100)*50)+base[0];
    base[3]=2*base[0];
    while(flag){
        for(int x=0; x<4; ++x){
        cout<<endl<<"Ingrese Horas trabajadas de acuerdo al apartado "<<x+1<<":";
        cin>>records[x];
        }
        if(!(records[0]>8||records[1]>4||records[2]>4||records[3]>8)){
            flag=false;
        }else{
        cerr<<"Ingrese Horas Validas!"<<endl;
        system("pause");
        }
    }

    for(int x=0; x<4; ++x){
        cout<<"Parte "<<x+1<<":$"<<records[x]*base[x];
        temp  += records[x]*base[x];
            cout<<endl;
    }
    cout<<endl<<"@Pago total: $"<<temp<<endl;
}

void four(void){
    system("cls");
    char mychar; int numb;
    cout<<"Ingrese caracter:";
    cin>>mychar;
    cout<<endl<<"Numero de veces que se imprimira el caracter:";
    cin>>numb;
    for(int y=0; y<numb; ++y){
        cout<<mychar;
    }
    cout<<endl;
}

void five(void){

    for(int x=1; x<11; ++x){
            cout<<"*Numero: "<<x<<endl<<endl;
        for(int w=1; w<5; ++w){
            cout<<"exp("<<w<<") = "<<pow(x,w)<<"    ";
        }
    cout<<endl<<endl;
    }
}

void six(void){
    int x;
    cout<<"Ingrese Numero a calcular factorial: ";
    cin>>x;
    cout<<endl<<x<<"!="<<factorial(x)<<endl;
}

void seven(void){
     int n;
     cout<<"Ingrese numero de pasos: ";
     cin>>n;
     cout<<endl;
     if(n>0){
       for(int x=1; x<=n; ++x)  {
        cout<<fibonacci(x)<<" ";
       }
       cout<<endl;
     }
     else{
        cerr<<"Repeticion Invalida!";
     }
}

void eight(void){
    int number=0, base =1;
    cout<<"Ingrese numero para calcular sus multiplos: ";
    cin>>number;
    cout<<endl<<"***Multiplos de "<<number<<"***"<<endl;
    if(number > 0){
        while(100>(base*number)){
            cout<<base*number<<" ";
            ++base;
        }
    }
    else{
        cout<<"No existen Multiplos!"<<endl;
    }
    cout<<endl;
}

void nine(void){

    const int monedas[]{1,5,10,25,50,100,200,500};
    int quantity[8];

    double import = 0;
    cout<<"Ingrese Cantidad: ";
    cin>>import;
    cout<<endl;

    if(import<0){
        import*=-1;
    }

    for(int q=0; q<8; q++){
        quantity[q] = import/monedas[q];
    }

    cout<<"Cantidad Minima de Monedas que usted puede tener con el importe dado>>"<<endl;

    cout<<"Monedas de $01 Pesetas: "<<quantity[0]<<endl;
    cout<<"Monedas de $05 Pesetas: "<<quantity[1]<<endl;
    cout<<"Monedas de $10 Pesetas: "<<quantity[2]<<endl;
    cout<<"Monedas de $25 Pesetas: "<<quantity[3]<<endl;
    cout<<"Monedas de $50 Pesetas: "<<quantity[4]<<endl;
    cout<<"Monedas de $100 Pesetas: "<<quantity[5]<<endl;
    cout<<"Monedas de $200 Pesetas: "<<quantity[6]<<endl;
    cout<<"Monedas de $500 Pesetas: "<<quantity[7]<<endl;
}

void ten(void){
    int number;
    cout<<"Ingrese numero entero para calcular sus numeros primos antecesores: ";
    cin>>number;
    cout<<endl;

    for(int x=1; x<=number; ++x){
        int temp = 0;
        for(int y=1; y<=x; ++y){
          if(x%y==0){
            ++temp;
          }
        }
        if(!(temp>2)){
            cout<<x<<" ";
        }
    }
    cout<<endl;
}

void eleven(void){
    int option = 0, div = 0, mult = 0; double one, two, result=0;
    cout<<"LISTA DE OPCIONES: "<<"1.- MULTIPLICAR, 2.- DIVIDIR"<<endl<<"Ingrese Opcion: ";
    cin>>option;
    cout<<endl<<endl<<endl;
    cout<<"Ingrese Numero 1: ";
    cin>>one;
    cout<<endl<<"Ingrese Numero 2: ";
    cin>>two;
    cout<<endl;
    if(0!=one&&two!=0){
        if(one<0){
            one*=-1;
        }
        if(two<0){
            two*=-1;
        }
        switch(option){
            case 1:{
                cout<<one<<"x"<<two<<"=";
                while(two>mult){
                    result += one;
                    ++mult;
                }
                cout<<result<<endl;
            break;
            }
            case 2:{
                cout<<one<<"/"<<two<<"=";
                while(0<=(one-two)){
                    one -= two;
                    ++div;
                }
                cout<<div<<endl;
                break;
            }
            default:{
            cerr<<"No existe esta opcion!"<<endl;
            }
        }
    }
    else{
        cerr<<"Ingrese numeros validos!"<<endl;
    }
}
void twelve(void){
    int number[10];
        bool finally[10]{false};
            int temp = 0;

                for(int x=0; x<10; ++x){
                    cout<<"Ingrese Numero "<<x+1<<":";
                    cin>>number[x];
                    cout<<endl;
                    for(int g=1; g<=number[x]; ++g){
                        if(number[x]%g == 0){
                            ++temp;
                        }
                    }
                    if(2>=temp){
                        finally[x] = true;
                    }
                    temp=0;
                }

                    system("cls");
                        cout<<"Lista Inicial:"<<endl;
                            for(int q = 0; q<10; ++q){
                                cout<<number[q]<<" ";
                            }
                                cout<<endl<<"Lista Primos:"<<endl;
                                    for(int q = 0; q<10; ++q){
                                            if(finally[q]){
                                                cout<<number[q]<<" ";
                                            }
                                    }
}

void thirteen(void){
    double initial[5],finalt[5];

        for(int x=0; x<5; ++x){
            cout<<"Ingrese Numero "<<x+1<<":";
            cin>>initial[x];
            finalt[x] = 2*initial[x];
            cout<<endl;
        }

        cout<<"Segundo Arreglo: "<<endl;

        for(int y=0; y<5; ++y){
            cout<<finalt[y]<<" ";
        }
        cout<<endl;
}

void fourteen(void){
    double xarray[3][5];
    long double byrow = 0, bycol =0, temp=0;

    for(int y=0; y<3; ++y){
        for(int g=0; g<5; ++g){
            cout<<"Elemento ["<<y+1<<"]["<<g+1<<"]>>";
            cin>>xarray[y][g];
            system("cls");
        }
    }
    system("cls");
    for(int y=0; y<3; ++y){
        for(int g=0; g<5; ++g){
            cout<<xarray[y][g]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"#Suma por filas#"<<endl;

    for(int h=0; 3>h; ++h){
        cout<<"Fila["<<1+h<<"]=";

        for(int x=4; 0<=x; --x){
            temp+=xarray[h][x];
        }

        cout<<temp<<endl;
        byrow+=temp;
        temp =0;
    }

    cout<<endl<<"#Suma por Columnas#"<<endl;

    for(int h=0; 5>h; ++h){
        cout<<"Columna["<<1+h<<"]=";

        for(int x=2; 0<=x; --x){
            temp+=xarray[x][h];
        }

        cout<<temp<<endl;
        bycol+=temp;
        temp =0;
    }

    cout<<endl<<"...Sumatoria..."<<endl;
    cout<<"Suma por columnas ="<<bycol<<endl<<"Suma por filas ="<<byrow<<endl<<"@Suma Total de Valores = "<<byrow<<endl;
}

void fifteen(void){
    int op = 0;
    char * sealed;
    char * Tsealed;
    size_t mysize;

    cout<<"Desea definir longitud de leyenda? 1.-SI, 2.-NO(SEVERUS)"<<endl;
    cin>>op;

    switch(op){

    case 1:{
          cout<<"Ingrese size de leyenda: ";
          cin>>mysize;

            {
                sealed = new (nothrow)char[static_cast<int>(mysize)-mysize];
                {
                    Tsealed = new (nothrow)char[static_cast<int>(mysize)-(sizeof(sealed)/sizeof(char))];
                }
            }

          cout<<endl<<"Ingrese leyenda:";
          cin.ignore();
            gets(sealed);
            system("cls");
            for(int t=0; t<strlen(sealed); ++t){
                *(Tsealed+t)=(char)((int)*(sealed+t))+(3);
            }

        break;
    }
    case 2:{
            {
                sealed = new (nothrow)char[1];
                {
                    Tsealed = new (nothrow)char[1];
                }
            }

          cout<<endl<<"Ingrese leyenda:";
          cin.ignore();
            gets(sealed);
            system("cls");
            for(int t=0; t<strlen(sealed); ++t){
                *(Tsealed+t)=(char)((int)*(sealed+t))+(3);
            }
        break;
    }
    default:{
        cerr<<"Opcion No valida!"<<endl;
    break;
    }

    }
    if(op==1||2==op){
        cout<<"Leyenda Base: "<<sealed<<endl<<"Leyenda Encriptada: "<<Tsealed<<endl;
        delete [] sealed;
        delete [] Tsealed;
    }
}
void sixteen(void){
    char names[10][21];
    double scores[10][6];

    for(int x=0; x<10; ++x){
        names[x][21]='\n';
    }

    for(int x=0; x<10; ++x){
        scores[x][5]=0;
    }
    for(int o=0; o<10; ++o){
                cout<<"Ingrese Nombre de Alumno "<<o+1<<":";
                gets(names[o]);
                cout<<endl;

                for(int f=0; f<5;++f){
                    cout<<"Ingrese calificacion "<<f+1<<":";
                    cin>>scores[o][f];
                    scores[o][5]+=scores[o][f];
                }

                scores[o][5]/=5;
                system("cls");
                cin.ignore();
            }

            for(int y=0; 10>y; ++y){
                cout<<"Nombre: ";
                puts(names[y]);
                cout<<endl<<"Promedio: "<<scores[y][5]<<"%"<<endl<<endl;
            }
}

void seventeen(void){
    int * numbers = new (nothrow)int[1];
    for(int b = 0; 101>b; ++b){
        if(b%3==0){
         *(numbers+b)=b;
         cout<<b<<" ";
        }
    }
    cout<<endl;
    delete [] numbers;
}

void eighteen(void){
    double one[10], two[10];

    mt19937 baseloop;
    {
    baseloop.seed(random_device()());
    }
    uniform_int_distribution<mt19937::result_type> myRoot(50,100);

    cout<<"Arreglo 1:"<<endl;
    for(int x=0; 10>x;++x){
        one[x]=myRoot(baseloop);
        cout<<one[x]<<" ";
    }
    cout<<endl<<"Arreglo 2:"<<endl;
    for(int c=0; 10>c;++c){
        two[c]=.5*one[c];
        cout<<two[c]<<" ";
    }
    cout<<endl;
}

void nineteen(void){

    int matA[3][4], matT[4][3]{};
    int MAX = 9, MIN = 0;
    cout<<"Matriz [F]"<<endl<<endl;
    for(int r = 0; r<3; ++r){
        for(int c=0; c<4; ++c){
            matA[r][c] = rand() % (MAX - MIN) + MIN;
            cout<<matA[r][c]<<" ";
        }
        cout<<endl;
    }

    for(int c = 0; c<3; ++c){
        for(int r=0; r<4; ++r){
            matT[r][c]=matA[c][r];
        }
        cout<<endl;
    }

    cout<<"Matriz Transpuesta de [F]"<<endl<<endl;
    for(int z=0; z<4; ++z){
        for(int s=0; s<3; ++s){
            cout<<matT[z][s]<<" ";
        }
        cout<<endl;
    }
}

void twenty(void){
    int matA[3][4]{}, matB[4][2]{}, matc[3][2]{};

    srand(time(NULL));

    for(int y=2; y>-1;--y){
        for(int l=0; l<4;++l){
            matA[y][l]=rand()%8+1;
        }
    }

    for(int h=3; h>-1; --h){
        for(int j=0; j<2; ++j){
            matB[h][j]=rand()%8+1;
        }
    }

    for(int x = 0; x<3; ++x){
        for(int z=0;z<4;++z){
            cout<<matA[x][z]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int x = 0; x<4; ++x){
        for(int z=0;z<2;++z){
            cout<<matB[x][z]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int index=0; index<2;++index){
        for(int y=0; y<3; ++y){
            for(int x=0; x<4;++x){
                matc[y][index]+=matA[y][x]*matB[x][index];
            }
        }
    }

    for(int z=0; 3>z; ++z){
        for(int y=0; 2>y; ++y){
            cout<<matc[z][y]<<" ";
        }
        cout<<endl;
    }

}
//@Code By: Jesús José Navarrete Baca(CheCheSwap))<=33
