#include <stdio.h>
#include "constant.h"


int main(){
    int Primes[NUMBEROFPRIMES +1] = {0};
    int pageNumber;
    int pageOffset;
    int rowOffset;
    int currentColumn;
    int candidatePrime;
    int primeIndex;
    bool possiblyPrime;
    int ord;
    int square;
    int n;
    int multiples[ORDMAX +1 ] = {0};
    
    candidatePrime= 1;
    primeIndex = 1;
    Primes[1] = 2;
    ord = 2;
    square = 9;
    
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
    
    {
        pageNumber=1 ;
        pageOffset= 1;
        while(pageOffset <= NUMBEROFPRIMES){
            printf("The First %d Prime Numbers --- Page %d\n\n", NUMBEROFPRIMES, pageNumber);
            for(rowOffset = pageOffset; rowOffset < pageOffset + NUMBEROFROWS; ++rowOffset){
                for(currentColumn=0;currentColumn<NUMBEROFCOLUMNS;++currentColumn)
                    if(rowOffset + currentColumn*NUMBEROFROWS <= NUMBEROFPRIMES)
                    printf("%.10d ", Primes[rowOffset+currentColumn*NUMBEROFROWS]);
                printf("\n");
            };
            printf("\f");
            ++pageNumber;
            pageOffset= pageOffset + NUMBEROFROWS*NUMBEROFCOLUMNS;
        };
    };
};