#include <stdio.h>
#include "constant.h"

inline void printPrimes(int Primes[]) {
    int pageNumber=1 ;
    int pageOffset= 1;
    int rowOffset;
    int currentColumn;
    while(pageOffset <= NUMBEROFPRIMES){
        printf("The First %d Prime Numbers --- Page %d\n\n", NUMBEROFPRIMES, pageNumber);
        for(rowOffset = pageOffset; rowOffset < pageOffset + NUMBEROFROWS; ++rowOffset){
            for(currentColumn=0; currentColumn<NUMBEROFCOLUMNS; ++currentColumn)
                if(rowOffset + currentColumn*NUMBEROFROWS <= NUMBEROFPRIMES)
                printf("%.10d ", Primes[rowOffset+currentColumn*NUMBEROFROWS]);
            
            printf("\n");
        };
        printf("\f");
        ++pageNumber;
        pageOffset= pageOffset + NUMBEROFROWS*NUMBEROFCOLUMNS;
    };
};
inline void generatePrimes(int Primes[]) {
    
    int candidatePrime = 1;
    int primeIndex = 1;
    bool possiblyPrime;
    int ord = 2;
    int square = 9;
    int multiples[ORDMAX +1 ] = {0};
    int n;
    
    Primes[1] = 2;
    
    while (primeIndex<NUMBEROFPRIMES){
        do {
            candidatePrime+=2;
            if (candidatePrime == square){
                ++ord;
                square= Primes[ord] * Primes[ord];
                multiples[ord - 1] = candidatePrime;
            };
            n = 2;
            possiblyPrime= true;
            while(n<ord && possiblyPrime) {
                while(multiples[n] < candidatePrime)
                    multiples[n] = multiples[n] + Primes[n] + Primes[n];
                if (multiples[n] == candidatePrime)
                    possiblyPrime= false;
                ++n;
            };
        } while(!possiblyPrime);
        ++primeIndex;
        Primes[primeIndex] = candidatePrime;
    };
    
};

int main(){
    int Primes[NUMBEROFPRIMES +1] = {0};
    generatePrimes(Primes);
    printPrimes(Primes);
    
    return 0;
};

