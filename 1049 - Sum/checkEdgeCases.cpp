#include <cstdio>
#define ABS(x) (x<0?-x:x) 
using namespace std;
int main(){
    int n,n2;
    scanf("%d",&n);
    n2=(ABS(n)*ABS(n)+ABS(n));
    if(n<0) printf("-%d",(n2-1)/2);
    else printf("%d",n2/2);
}
