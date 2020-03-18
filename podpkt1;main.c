#include <stdio.h>
#include <stdlib.h>





unsigned long Catalan(unsigned short n){
    if(n <= 1){
        return 1;
    }
    long c = 0;
    for(int i = 0;i<n;i++){
        c += Catalan(i) * Catalan(n-i-1);
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
