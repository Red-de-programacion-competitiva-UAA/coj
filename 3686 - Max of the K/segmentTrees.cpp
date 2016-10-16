
#include <bits/stdc++.h>
using namespace std;
vector<long long> arr,tri;
void build(int n,int L,int R){
	if(L==R){
		tri[n]=arr[L];
		return;
	}
	build(n*2,L,(L+R)/2);
	build(n*2+1,(L+R)/2+1,R);
	tri[n]=max(tri[n*2],tri[n*2+1]);
}
long long rmq(int n,int L, int R,int x,int y){
    if(x>=L&&y<=R) return tri[n];
	if((y<L)||(x>R)||(x>y)) return LLONG_MIN;
	return max(rmq(n*2,L,R,x,(x+y)/2),rmq(n*2+1,L,R,(x+y)/2+1,y));
}
int main(){
    int t,N,k;
    long long aux;
    scanf("%d",&t);
    while(t--){
        arr.clear();
        scanf("%d %d",&N,&k);
        for(int i=0; i<N; i++){
            scanf("%lld",&aux);
            arr.push_back(aux);
        }
        tri.assign(4*arr.size(),0);
        build(1,0,arr.size()-1);
        for(int i=1; i<=N-k+1; i++)
            printf("%lld ",rmq(1,i,i+k-1,1,arr.size()));
        printf("\n");
    }
}
