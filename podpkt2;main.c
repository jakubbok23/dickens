#include <stdio.h>
#include <stdlib.h>
#define MODULUS 1000000007



unsigned long Catalan(unsigned short n){
    if(n <= 1){
        return 1;
    }
    long c = 0;
    for(int i = 0;i<n;i++){
        long left = Catalan(i)%MODULUS;
        long right = Catalan(n-i-1)%MODULUS;
        c = (c + (left * right) %MODULUS) % MODULUS;
    }
    return c;
}


int main()
{
    int n;
    scanf("%d", &n);
    printf("%li", Catalan(n));
    return 0;
}
