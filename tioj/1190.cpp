#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}

bitset<250010> taken;
int main(){
	taken.reset();
	int n,m,k;n = R();m = R();k = R();
	vector<int> loop(n*n+1,0);
	int t=0;
	for(int i=1;i<=n*n;i++){
		if(!taken[i]){
			int j=0;
			for(;(j*(n-1)+i<=n*n) && ((j*(n-1)+i)%n)!=1 && (j*(n-1)+i) <= n*n-n;j++ ){
				loop[j*(n-1)+i]=++t;
				taken[(j*(n-1)+i)]=1;
			}
			loop[j*(n-1)+i]=++t;
			taken[(j*(n-1)+i)]=1;
		}
	}
	int ringlen=1;
	int cur = m;
	cur = loop[cur];
	while(cur!=m){
		ringlen+=1;
		cur = loop[cur];
	}
	k%=ringlen;
	for(int i=0;i<k;i++){
		m = loop[m];
	}
	printf("%d\n",m);
	return 0;
}

// this is a map from N^2 -> N^2 , so it is a bunch of rings, we can get the size of the ring and then mod k, O(n^2);
