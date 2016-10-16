#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    for(int i=0; i<s.size()/2; i++)
        if(s[i]!=s[s.size()-i-1]) return false;
        return true;
}
int main(){
    string str,tmp;
    int T,iniC;
    scanf("%d\n",&T);
    while(T--){
        iniC=0;
        getline(cin,str);
        if(str.size()%2) printf("NO\n");
        else{
            for(int i=1; i<=str.size()/2; i++){
                tmp=string(str.begin(),str.begin()+(i*2));
                if(isPalindrome(tmp)){
                    str.erase(str.begin(),str.begin()+(i*2));
                    i=0;
                }
            }
            if(!str.size()) printf("YES\n");
            else printf("NO\n");
        }
    }
}

