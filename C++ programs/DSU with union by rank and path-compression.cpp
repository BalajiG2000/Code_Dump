/*
*
*Problem Link : No Link
*comment: template of disjoint-set union data structure
*Status: correct
*Author: Mayukh Chakrabarti (https://github.com/MayukhC99)
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;

//normal dsu with path-compression
class dsu{
	vector<lld> parent;
	lld total_components;
	
	public:
		dsu(lld n){
			parent.resize(n);
			for(lld i=0 ; i<n ; i++)
				parent[i] = i;
			
			total_components = n;
		}
		
		lld find(lld a){
			if(a==parent[a])
				return a;
			return parent[a]= find(parent[a]); //path_compression
		}
		
		lld union_set(lld a,lld b){
			a = find(a); //finding root node of a
			b = find(b); //finding root node of b
			if(a != b){
				parent[a] = b;
				total_components--;
			}
		}
		
};

//dsu with union by size/rank and path-compression
class dsu2{
	vector<lld> parent,rank;
	lld total_components;
	
	public:
		dsu2(lld n){
			parent.resize(n);
			rank.resize(n);
			for(lld i=0 ; i<n ; i++)
				parent[i] = i, rank[i] = 0;
				
			total_components = n;
		}
		
		lld find(lld a){
			if(a==parent[a])
				return a;
			return parent[a] = find(parent[a]);
		}
		
		lld union_set(lld a,lld b){
			a = find(a); //finding root node of a
			b = find(b); //finding root node of b
			if( a != b ){
				if(rank[a]<rank[b])
					swap(a,b);
				else if(rank[a] == rank[b])
					rank[a]++;
					
				parent[b] = a;
				total_components--;
			}
		}
};

int main(){
	
	return 0;
}

