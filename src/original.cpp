#include <stdio.h>
#include "constant.h"

int main(){
    int P[M +1] = {0};
    int PAGENUMBER;
    int PAGEOFFSET;
    int ROWOFFSET;
    int C;
    int J;
    int K;
    bool JPRIME;
    int ORD;
    int SQUARE;
    int N;
    int MULT[ORDMAX +1 ] = {0};
    
    J = 1;
    K = 1;
    P[1] = 2;
    ORD = 2;
    SQUARE = 9;
    
    while (K<M){
        do {
            J = J + 2;
            if (J == SQUARE){
                ORD = ORD + 1;
                SQUARE = P[ORD] * P[ORD];
                MULT[ORD - 1] = J;
            };
            N = 2;
            JPRIME = true;
            while(N<ORD && JPRIME) {
                while(MULT[N] < J)
                    MULT[N] = MULT[N] + P[N] + P[N];
                if (MULT[N] == J)
                    JPRIME = false;
                N = N+1;
            };
        } while(!JPRIME);
        K = K+1;
        P[K] = J;
    };
    {
        PAGENUMBER =1 ;
        PAGEOFFSET = 1;
        while(PAGEOFFSET <= M){
            printf("The First %d Prime Numbers --- Page %d\n\n", M, PAGENUMBER);
            for(ROWOFFSET = PAGEOFFSET; ROWOFFSET < PAGEOFFSET + RR; ++ROWOFFSET){
                for(C=0;C<CC;++C)
                    if(ROWOFFSET + C*RR <= M)
                    printf("%.10d ", P[ROWOFFSET+C*RR]);
                printf("\n");
            };
            printf("\f");
            PAGENUMBER = PAGENUMBER + 1;
            PAGEOFFSET = PAGEOFFSET + RR*CC;
        };
    };
};