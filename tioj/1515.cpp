#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct st{
	int id;
	pair<int,int> rank;
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	cin.ignore();
	string s;
	getline(cin,s);
	s+='$';
	n++;
	assert(s.size()==n);
	int sfa[n]={0};
	st temp[n];
	for(int i=0;i<n;i++){
		temp[i].id = i;
		temp[i].rank={(int)s[temp[i].id],0};
	}
	for(int k=0;k<=__lg(n)+1;k++){
		sort(temp,temp+n,[](const st &a,const st &b){return a.rank<b.rank;});
		for(int i=0;i<n;i++){
			if(i && temp[i].rank == temp[i-1].rank) sfa[temp[i].id] = sfa[temp[i-1].id];
			else sfa[temp[i].id] = i;
		}
		for(int i=0;i<n;i++){
			temp[i].rank.first = sfa[temp[i].id];
			temp[i].rank.second = sfa[(temp[i].id+(1<<k))%n];
		}
	}
	int lcp[n]={0};
	int k=0;
	for(int i=0;i<n-1;i++){
		int pi = sfa[i];
		int j = temp[pi-1].id;
		while(j+k<n && i+k<n && s[i+k]==s[j+k]) k++;
		lcp[pi] = k;
		k = max(0,k-1);
	}
	/*for(int i=0;i<n;i++){
		for(int j=temp[i].id;j<n;j++) cout<<s[j];
		cout<<"\n";
	}*/
	int ans=0;
	for(int i=1;i<n;i++){
		ans = max(lcp[i],ans);
	}
	cout<<ans<<"\n";

	return 0;
}
