#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;*/
struct dijkstra{
	int n;
	vector<vector<pair<int,ll> > > side;
	void init(int s){
		side.resize(s);
		n = s;
	}
	void add_edge(int a,int b,ll c){
		side[a].push_back({b,c});
	}
	vector<ll> mindis(int u){
		vector<ll> dis(n);
		fill(dis.begin(),dis.end(),1e18);
		dis[u] = 0;
		priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
		pq.push({0,u});
		while(pq.size()){
			auto cur = pq.top();
			pq.pop();
			if(dis[cur.second]!=cur.first) continue;
			for(auto i : side[cur.second]){
				if(dis[i.first]>dis[cur.second]+i.second){
					dis[i.first] = dis[cur.second]+i.second;
					pq.push({dis[i.first],i.first});
				}
			}
		}
		return dis;
	}
};
 
 
 
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	dijkstra graph;
	graph.init(n);
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		graph.add_edge(a,b,c);
	}
	vector<ll> dis = graph.mindis(0);
	for(int i=0;i<n;i++){
		cout<<dis[i]<<" \n"[i==n-1];
	}
	return 0;
}
