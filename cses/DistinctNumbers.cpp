#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	set<int> s;
	while(n--){
		int a;cin>>a;
		s.insert(a);
	}
	cout<<s.size()<<"\n";

	return 0;
}
