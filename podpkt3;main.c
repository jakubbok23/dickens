#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MODULUS 102348769

struct mem_entry {
unsigned long value;
bool valid;
};

struct mem_entry memory[MODULUS];

unsigned long CatalanMem(unsigned short n){
    long c, left, right;
    if(n <= 1){
        return 1;
    }
    c = 0;
    for(int i = 0;i<n;i++){
        if(memory[i].valid == true){
            left = memory[i].value;
        }
        else{
            left = CatalanMem(i)%MODULUS;
        }
        memory[i].value = left;
        memory[i].valid = true;
        if(memory[n-i-1].valid == true){
            right = memory[n-i-1].value;
        }
        else{
            right = CatalanMem(n-i-1)%MODULUS;
        }
        memory[n-i-1].value = right;
        memory[n-i-1].valid = true;
        c = (c + (left * right) %MODULUS) % MODULUS;
    }
    return c;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%li", CatalanMem(n));
    return 0;
}
