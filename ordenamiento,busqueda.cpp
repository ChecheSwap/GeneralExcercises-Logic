#include <iostream>
//Code By: Jesus Jose Navarrete Baca
using namespace std;
void shell()
{

    unsigned int n = 5;
	string s1[5] = { "roberto", "alex", "dia", "dado", "nicole" };

	for (unsigned int i = 0; i < n; i++) {
		cout << s1[i] << endl;
	}

	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			if (s1[i].at(0) < s1[j].at(0)) {
				string tmp = s1[i];
				s1[i] = s1[j];
				s1[j] = tmp;
			}
		}

	}
	cout<<endl;

	for (unsigned int i = 0; i < n; i++) {
		cout << s1[i] << endl;
	}
	
    /*

    srand(time(NULL));
    const string months[]{"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
    string capture[12];
    string local;

    for(int y=0; y<12; ++y){
            cin>>local;
        for(int x=0; x<12; x++){
            if(local==months[x]){
                capture[x] = local;
            }
        }
    }

   for(auto & x:capture)
    cout<<x<<endl;




    cout<<endl;
    int v[10];

    for(int g=0; g<10; ++g)
        v[g]=rand()%15000 + 1;

    int j, i, gap, temp, n=10;



    for(gap = n/2; gap>0; gap=gap/2){
        for(i=gap; i<n; ++i){
            for(j=i-gap; j>=0 && v[j]<v[gap+j]; j=j-gap){
                temp = v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;
    }}}
    for(int gap = n/2; gap>0; gap = gap /2){
    for(int j=gap; j<n; ++j){
        for(int i= j-gap; i>=0 && v[i]>v[i+gap]; i=i-gap){
            temp = v[i];
            v[i]=v[i+1];
            v[i+1]=temp;
        }
    }
}


    for(int x=0; x<n; x++)
        cout<<v[x]<<endl;

        for(int x=0; x<n; ++x){
            for(int y=0; y<n; ++y){
                int temp = v[y];
                if(v[y]>v[y+1]){
                    v[y]=v[y+1];
                    v[y+1]=temp;
                }
            }
        }


    for(int x=0; x<n; x++)
        cout<<v[x]<<endl;
*/
}

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
