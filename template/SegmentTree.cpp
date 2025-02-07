#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>ja
//__gnu_pbds

struct SEG{
	vector<int> arr;
	void init(int n){
		arr.resize(4*n,0);
	}
	void modify(int ind,int v,int L,int R,int arri){
			if(L==ind && R-L==1){
				arr[arri] = v;
				return ;
			}
			int M = (R+L)/2;
			if(ind<M) modify(ind,v,L,M,2*arri);
			else if(ind>=M) modify(ind,v,M,R,2*arri+1);
			arr[arri] = max(arr[2*arri],arr[2*arri+1]);
	}
	int query(int l,int r,int L,int R,int arri){
		if(l==L && r==R) return arr[arri];
		int M = (R+L)/2;
		if(r<=M) return query(l,r,L,M,2*arri);
		else if(l>=M) return query(l,r,M,R,2*arri+1);
		else{
			return max(query(l,M,L,M,2*arri),query(M,r,M,R,2*arri+1));
		}
	}
};

