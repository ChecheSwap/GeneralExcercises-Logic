#include <iostream>

using namespace std;

void quicksort(int*arr,int lef,int rig){
    int pivot = arr[lef+(rig-lef)/2];
    int i= lef;
    int j = rig;

    while(i<=j){
        while(arr[i]<pivot){
            ++i;
        }
        while(arr[j]>pivot){
            --j;
        }
        if(i<=j){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            ++i;
            --j;
        }
        if(lef < j){
            quicksort(arr,lef,j);
        }
        if(rig > i){
            quicksort(arr,i,rig);
        }
    }
}

void binarysearch(int*arr,int left, int right,int numero){
    int temp;

    while(left<=right){

        temp = (right + left ) / 2;

        if(arr[temp]==numero){
        cout<<"Si se encuentra numero en posicion "<<temp<<endl;
        return;
        }
        else if(numero<arr[temp]){
            right = temp - 1;
        }
        else{
            left = temp + 1;
        }
    }
    if(!(numero==arr[temp])){
        cout<<"No se ha encontrado!"<<endl;
        return;
    }

}

void insertion(int * arr, int length){

    int j, temp;

    for(int x=0; x<length;++x){
        j=x;

        while(j>0 && arr[j]<arr[j-1]){
            temp = arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            --j;
        }
    }
}

void selection(int*arr,int n){
    int posmin;
    int temp;

    for(int x=0; x<n-1; x++){
        posmin = x;

        for(int y=x+1; y<n; ++y){
            if(arr[y]<arr[posmin]){
                posmin = y;
            }
        }
        if(!(posmin == x)){
            temp = arr[x];
            arr[x] = arr[posmin];
            arr[posmin]=temp;
        }
    }
}

int main()
{

    int rx[]{6,0,1,3,50,7,1};

    for(int x=0; x<7; ++x){
        cout<<rx[x]<<" ";
    }
    cout<<endl;

    selection(rx,7);

    for(int x=0; x<7; ++x){
        cout<<rx[x]<<" ";
    }

    //insertion(rx,7);

    //binarysearch(rx,0,6,50);
    cout <<endl;

    return 0;
}
