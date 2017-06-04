
#define MAXALUMNOS 10

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

typedef struct xmaterias{
int clave;
char descripcion[50];
double calificacion;

    xmaterias(){
        this->cls();
    }

    void cls(){
        this->clave=-1;
        for(int x=0; x<50; ++x){
            this->descripcion[x]=NULL;
        }
        this->calificacion=-1;
    }

}materias;


typedef struct xalumnos{
    bool flag;
    int matricula;
    char nombre[30];
    materias amaterias[5];
    double promedio;
    xalumnos(){
    this->cls();
    }

    void cls(void){
        this->flag  = false;
        this->matricula = -1;
        for(int x=0; x<30; ++x){
            this->nombre[x]=NULL;
        }
        this->promedio = -1;
    }
}alumno;

alumno alumnos[MAXALUMNOS];
alumno ordenI[MAXALUMNOS];

void print();
bool altaalumno(int&);
bool existMatricula(int);
int getindexmatricula(int);
bool regcal(int &);
bool cambiarcal(int);
bool calcprom();
void generarorden(int);
bool calcpromall(int);
void imprimirorden(int);
int main()
{
    int opcion = 33,index = 0;

    while(true){
        system("cls");

        print();
        cin>>opcion;

        switch(opcion){
            case(1):{
                altaalumno(index);
                break;
            }
            case(2):{
                if(index == 0){
                    cerr<<"No existen Alumnos!"<<endl;
                    system("pause");
                    break;
                }
                regcal(index);
                break;
            }
            case(3):{
                if(index == 0){
                    cerr<<"No existen Alumnos!"<<endl;
                    system("pause");
                    break;
                }
                cambiarcal(index);
                break;
            }
            case(4):{
                if(index == 0){
                    cerr<<"No existen Alumnos!"<<endl;
                    system("pause");
                    break;
                }
                calcprom();
                break;
            }
            case(5):{
                if(index == 0){
                    cerr<<"No existen Alumnos!"<<endl;
                    system("pause");
                    break;
                }
                generarorden(index);
                break;
            }
            case(6):{
                if(index == 0){
                    cerr<<"No existen Alumnos!"<<endl;
                    system("pause");
                    break;
                }
                imprimirorden(index);
                break;
            }
            case(7):{
                cout<<endl<<"->Hasta Luego!";
                return 33;
            }
        }

    }
}

void imprimirorden(int index){

    system("cls");

    cout<<left<<setw(15)<<"Matricula"<<setw(20)<<"Nombre"<<setw(15)<<"Promedio"<<endl;

    for(int x=0; x<index;++x){
        cout<<setw(15)<<ordenI[x].matricula<<setw(20)<<ordenI[x].nombre<<setw(15)<<ordenI[x].promedio<<endl;
    }

    system("pause");
}

void generarorden(int index){

    int grid[index][6], matrep=0,temp=33;

    for(int x=0; x<index;++x){
        for(int y=0; y<6; ++y){
            grid[x][y]=-1;
        }
    }

    for(int x=0; x<index; ++x){
        if(!(alumnos[x].flag)){
            system("cls");
            cerr<<"Debe capturar calificaciones para todos los alumnos!"<<endl;
            system("pause");
            return;
        }
    }

    calcpromall(index);

    memcpy(&ordenI,&alumnos,sizeof(alumno)*index);

    for(int x=0; x<index; ++x){
        for(int y=0; y<5; ++y){
            if(alumnos[x].amaterias[y].calificacion<60){
                ++matrep;
            }
        }
        grid[x][matrep]=x;
        matrep = 0;
    }

    for(int cs = 0; cs<6; ++cs){
        for(int sup = index / 2; sup>0; sup/=2){
            for(int med=sup; med<index; ++med){
                for(int on = med - sup; on>=0 && grid[on][cs]<grid[on+sup][cs]; on-=sup){
                    temp = grid[on][cs];
                    grid[on][cs]=grid[on+sup][cs];
                    grid[on+sup][cs] = temp;
                }
            }
        }
    }

    for(int x=0; x<index; ++x){
        for(int y=0; y<6; ++y){
            cout<<grid[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    alumno stud;

    int lim =0;

    for(int cs = 0; cs<6; ++cs){

        for(int x=0; x<index; ++x){
            if(!(grid[x][cs]==-1)){
                ++lim;
            }
        }

        for(int x=0; x<lim; ++x){
            for(int y=0; y<lim-1-x; ++y){
                if(alumnos[grid[y][cs]].promedio < alumnos[grid[y+1][cs]].promedio){
                    temp = grid[y][cs];
                    grid[y][cs]=grid[y+1][cs];
                    grid[y+1][cs]=temp;
                }
            }
        }

        for(int x=0; x<lim; ++x){
            memcpy(&ordenI[x],&alumnos[grid[x][cs]],sizeof(alumno));
        }

        lim = 0;
    }

    for(int x=0; x<index; ++x){
        for(int y=0; y<6; ++y){
            cout<<grid[x][y]<<" ";
        }
        cout<<endl;
    }

    system("pause");

}

bool calcpromall(int index){

    double prom = 0;

    for(int x=0; x<index; ++x){
        for(int y=0; y<5; ++y){
            prom +=alumnos[x].amaterias[y].calificacion;
        }
        prom/=5;
        alumnos[x].promedio = prom;
        prom = 0;
    }
}

bool calcprom(){
    int matricula, pos;
    double prom;

    while(true){
        system("cls");
        cout<<"(-1 Para salir) Ingrese Matricula: ";
        cin>>matricula;

        if(matricula == -1){
            return false;
        }
        if(existMatricula(matricula)){

            pos = getindexmatricula(matricula);

            if(alumnos[pos].flag){
                for(int x=0; x<5; ++x){
                    prom+=alumnos[pos].amaterias[x].calificacion;
                }
                prom/=5;
                alumnos[pos].promedio = prom;
                cout<<"Matricula: "<<matricula<<endl<<"Nombre: "<<alumnos[pos].nombre<<endl<<"Promedio: "<<alumnos[pos].promedio<<"%"<<endl;
            }
            else{
                cerr<<"No existen calificaciones para Alumno!"<<endl;
            }
        }
        else{
            cerr<<"No existe matricula!"<<endl;
        }
        system("pause");
    }

    return true;
}

bool cambiarcal(int index){

    int position, matricula;

    while(true){
        system("cls");
        cout<<"(-1 Para Salir...) Ingrese Matricula: ";
        cin>>matricula;
        if(matricula==-1){
            return false;
        }

        if(existMatricula(matricula)){
            position = getindexmatricula(matricula);

            if(!(alumnos[position].flag)){
                cerr<<"No existen calificaciones! "<<endl;
            }
            else{

                    system("cls");
                    cout<<"->Matricula:"<<matricula<<endl;
                    cout<<"->Nombre: "<<alumnos[position].nombre<<endl;
                    cout<<"->Calificaciones: "<<endl;
                    cout<<left<<setw(8)<<"Clave"<<setw(20)<<"Nombre"<<"Calificacion"<<endl;

                    for(int x=0; x<5; ++x){
                        cout<<setw(8)<<alumnos[position].amaterias[x].clave<<setw(20)<<alumnos[position].amaterias[x].descripcion<<alumnos[position].amaterias[x].calificacion<<endl;
                    }

                    int clave = -1, mpos = -1;

                    while(true){
                        cout<<"->(-1 Para regresar)Ingrese Clave de Materia: ";
                        cin>>clave;

                        if(clave == -1){
                            break;
                        }

                        for(int x=0; x<5; ++x){
                            if(alumnos[position].amaterias[x].clave == clave){
                                mpos = x;
                            }
                        }

                        if(mpos==-1){
                            cerr<<"No existe esta clave de materia."<<endl;
                        }
                        else{

                            int dos = -1;
                            double calif = -1;
                            cout<<"Desea modificar descripcion?(1-SI, (2-*)-NO)";
                            cin>>dos;
                            if(dos == 1){
                                cout<<"Ingrese Nuevo Nombre: ";
                                fflush(stdin);
                                gets(alumnos[position].amaterias[mpos].descripcion);
                            }
                            cout<<"Nombre Materia: "<<alumnos[position].amaterias[mpos].descripcion<<endl;

                            while(true){
                                cout<<"Ingrese Calificacion Nueva: ";

                                cin>>calif;
                                if(calif>0&&calif<101){
                                    alumnos[position].amaterias[mpos].calificacion = calif;
                                    cout<<"Calificacion Modificada adecuadamente"<<endl;
                                    break;
                                }
                                else{
                                    cerr<<"Calificacion Invalida"<<endl;
                                }

                                system("pause");
                            }

                        }
                    }
                }

        }
        else{
            cerr<<"Matricula Inexistente!"<<endl;
        }
        system("pause");
    }

}

bool regcal(int & index){

    int matricula = 0, position = -1;
    materias tempmat[5];


    while(true){
        system("cls");
        cout<<"-1 Para salir..."<<endl<<"Ingrese Matricula:";
        cin>>matricula;

        if(matricula == -1){
            return false;
        }

        if(existMatricula(matricula))  {
            position = getindexmatricula(matricula);

                for(int x=0; x<5; ++x){
                    system("cls");

                    while(true){

                        bool flag= true;

                        cout<<"(-1 Para salir) Ingrese Clave "<<x+1<<": ";
                        cin>>tempmat[x].clave;

                        if(tempmat[x].clave == -1){
                            return false;
                        }

                        for(int y=x-1; y>=0&&x>0; --y){
                            if(tempmat[x].clave == tempmat[y].clave){
                                cerr<<"Esta clave de materia ya existe!"<<endl;
                                flag = false;
                                break;
                            }
                        }
                        if(flag){
                            break;
                        }
                    }

                    cout<<"Ingrese descripcion "<<x+1<<": ";
                    fflush(stdin);
                    gets(tempmat[x].descripcion);

                    while(true){

                        cout<<"Ingrese Calificacion "<<x+1<<": ";
                        cin>>tempmat[x].calificacion;

                        if(tempmat[x].calificacion > -1 && tempmat[x].calificacion < 101){
                           break;
                        }

                        cerr<<"Calificacion Invalida!"<<endl;
                    }
            }

            memcpy(&alumnos[position].amaterias,&tempmat,sizeof(materias)*5);
            alumnos[position].flag = true;
            cout<<"Se han grabado las materias en memoria!"<<endl;
        }
        else{
            cerr<<"Matricula Invalida!"<<endl;
        }
        system("pause");
    }

    return true;
}

bool altaalumno(int & index){

        xalumnos temp;

        while(true){

            if(index == 10){
                cerr<<"No existe cupo."<<endl;
            }
            else{

                while(true){
                    system("cls");
                    cout<<"Ingrese -1 Para salir..."<<endl<<endl<<"Ingrese Matricula: ";

                    cin>>temp.matricula;

                    if(temp.matricula == -1){
                        return false;
                    }

                    if(existMatricula(temp.matricula)){
                        cerr<<"Esta matricula ya existe!"<<endl;
                        break;
                    }

                    cout<<"Ingrese Nombre: ";
                    fflush(stdin);
                    gets(temp.nombre);
                    memcpy(&alumnos[index],&temp,sizeof(xalumnos));
                    ++index;
                    cout<<"Se ha agregado alumno!"<<endl;
                    temp.cls();
                    break;
                }
            }
            system("pause");
        }


    return true;
}

void print(){

    cout<<"1) Alta de Alumnos."<<endl;
    cout<<"2) Registro de Calificaciones."<<endl;
    cout<<"3) Modificar Calificaciones."<<endl;
    cout<<"4) Calcular Promedio"<<endl;
    cout<<"5) Generar Orden de inscripcion"<<endl;//PRIMERO 0 MATERIAS REPOBADAS Y MAYOR PROMEDIO,ASI SUCESIVAMENTE.
    cout<<"6) Imprimir Orden de inscripcion"<<endl;
    cout<<"7) Salir"<<endl<<endl;
    cout<<"->Ingrese Opcion: ";
}

int getindexmatricula(int matricula){
    for(int x=0; x<MAXALUMNOS; ++x){
        if(alumnos[x].matricula == matricula){
            return x;
        }
    }
    return -1;
}

bool existMatricula(int matricula){

    for(int x=0; x<MAXALUMNOS; ++x){
        if(alumnos[x].matricula == matricula){
            return true;
        }
    }
    return false;
}


