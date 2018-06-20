#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x){
    int i,sp;
    sp=0;
    for(i=0;i<n;i++){
        sp=sp+A[i]/x;
    }
    return sp>=k;
}


int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    lb=0;
    ub=1000000001;
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    while(ub-lb>1){
        int m=(ub+lb)/2;
        if(p(m)) lb=m;
        else ub=m;
    }
    printf("%d\n",lb);
    return 0;
}
