#include <stdio.h>

int main(){
    int N, nfactors = 1, nprimes = 0;
    printf("Check primes till number: ");
    scanf("%i", &N);
    for(int i=1; i<=N; i++){ // num to be checked if prime
        nfactors = 0;
        for(int j=1; j<=i/2; j++){ // numbers to divisibility with num is prime
            if(i%j==0)
                nfactors++;
        }
        if (nfactors == 2)
            printf("prime: %i\n", i), nprimes++;
    }
    printf("Number of primes from 1 to %i are %i", N, nprimes);
    return 0;
}