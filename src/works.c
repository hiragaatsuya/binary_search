#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x){
    int s,w,i,h;
    s=1;w=0;h=1;
    for(i=0;i<n&&s;i++){
        if(A[i]>x) s=0;
    }
    for(i=0;i<n;i++){
        if(x>=w+A[i]) w=w+A[i];
        else w=A[i],h=h+1;
    }
    return k>=h&&s;
}


int sum(){
	int s,i;
	s=0;
	for(i=0;i<n;i++){
		s=s+A[i];
	}
	return s;
}


int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    int s=sum();
    lb=s/k+(2*(s%k))/((s%k+1))-1;
    ub=(n/k+1)*10000;
    while(ub-lb>1){
        int m=(ub+lb)/2;
        if(p(m)) ub=m;
        else lb=m;
    }
    printf("%d\n",ub);
    return 0;
}
