#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){int ar[n];
    for(int i=0;i<n;++i) cin>>ar[i];
    sort(ar,ar+n);
    for(int i=0;i<n;++i) cout<<ar[i]<<" ";
    cout<<"\n";}
    
    
}