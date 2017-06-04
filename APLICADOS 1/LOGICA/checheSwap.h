#ifndef checheswap_h_include
#define checheswap_h_include
#define LotusSwapCHE(bSuccess, api){if(!(bSuccess)) printf("%s:Microsoft_Trace_Connector=>Invoke.new(**)(NewTypeOF)(@MasterNavarrete_IDX;port:433)%d de %s \ On ERROR_goTo %d\n", __FILE__, GetLastError(), api, __LINE__);}
#include<iostream>

template <class x>

x factorial(x f){
        if(1==f || f==0){
            return 1;
        }
            else{
                return (f * factorial(f-1));
            }
};

long int fibonacci(int n)
{
        if(0==n||n==1){
            return n;
        }
        else{
            return fibonacci(n-1)+fibonacci(n-2);
        }
}

#endif
//@Code By: Jesús José Navarrete Baca(CheCheSwap))<=33
