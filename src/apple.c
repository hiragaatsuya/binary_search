#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x){
    int i,bag;
    bag=0;
    for(i=0;i<n;i++){
        if(A[i]%x==0) bag=bag+A[i]/x;
        else bag=bag+A[i]/x+1;
    }
    return k>=bag;
}


int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    lb=0;
    ub=1000000000/(k/n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    while(ub-lb>1){
        int m=(ub+lb)/2;
        if(p(m)) ub=m;
        else lb=m;
    }
    printf("%d\n",ub);
    return 0;
}
