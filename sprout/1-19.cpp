#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
    stack<int> stop;
    queue<int> order;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        order.push(a);
    }
    int train_now=1;
    while(!order.empty() && train_now<=n+1){
        if(!stop.empty()){
            if(stop.top()==order.front()){
                stop.pop();
                order.pop();
            }else{
                stop.push(train_now);
                train_now++;
            }
        }else{
            stop.push(train_now);
            train_now++;
        }
    }
    if(order.empty()){
        cout<<"Yes"<<endl;
    }else if(train_now>n+1){
        cout<<"No"<<endl;
    }else{
        cout<<order.front();
    }
    }
    
}