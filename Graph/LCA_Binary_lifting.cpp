/*There is no salvation without suffering*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
#include<iterator>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define pb push_back
#define pf push_front
#define tt ll t;cin>>t;while(t--)
#define nn cout<<endl;
#define ff(i,a,n) for(ll i=a;i<n;i++)
#define f(i,n,a) for(ll i=n;i>=a;i--)
#define fr(x, a) for(auto &x:a)
#define F(a) for(auto &x:a) cin>>x
#define cY cout<<"YES\n"
#define cN cout<<"NO\n"
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define sc second
#define fs first
#define c(a) cout<<a<<endl
#define all(a) a.begin(),a.end()
#define pi 3.14159265359
#define Popcount(x) __builtin_popcountll(x)
#define Ctz(x) __builtin_ctzll(x)
ll M=1e9+7;
ll mod(ll x){return ((x%M+M)%M);}
ll gcd(ll a,ll b);
ll lcm(ll a,ll b);
bool prime(ll n);
ll BinExp(ll base,ll power);
ll ModInverse(ll base);
ll nCr(ll n,ll r);
ll fact(ll n){ return (n<=1)? 1 : n*fact(n-1);}

/* Read the damn question carefully*/
ll n,m,l;
ll timer;
vector<ll>tin,tout;
vector<ll>g[100];
vector<vector<ll>>up;
void dfs(ll node,ll p)
{
    tin[node]=timer++;
    up[node][0]=p;
    for(ll i=1;i<=l;i++)
    {
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(auto&next:g[node])
        if(next!=p)
            dfs(next,node);
    tout[node]=timer++;
}
bool ancestor(ll u,ll v)
{
    return tin[u]<=tin[v] and tout[u]>=tout[v];
}
ll lca(ll u,ll v)
{
    if(ancestor(u,v))
        return u;
    if(ancestor(v,u))
        return v;
    for(ll i=l;i>=0;i--)
        if(!ancestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}
void solve()
{
    ll n,m; cin>>n>>m; l=ceil(log2(n));
    tin.resize(n+1);
    tout.resize(n+1);
    up.resize(n+1,vector<ll>(l+1));
    timer=0;
    ff(i,0,m)
    {
        ll a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,1);
    tt
    {
        ll a,b; cin>>a>>b;
        c(lca(a,b));
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//tt
	solve();
}
/*

15 14
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
100



*/
ll gcd(ll a,ll b){
	if(a==0) return b;
	return (a==1) ? a:gcd(b%a,a);
}
ll lcm(ll a,ll b) {return (a/gcd(a,b))*b; }
bool prime(ll n){
	if(n<2) return false;
	for(ll i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}
ll BinExp(ll base,ll power){
	if(!power)
		return 1;
	ll res=1;
	while(power>1){
		if(power%2){
			power--;
			res*=base;
		}
		else{
			base*=base;
			power/=2;
		}
	}
	return base*res;
}
ll ModInverse(ll base){
	ll power=M-2;
	if(!power)
		return 1;
	ll res=1;
	while(power>1){
		if(power%2){
			power--;
			res=mod(res*base);
		}
		else{
			base=mod(base*base);
			power/=2;
		}
	}
	return mod(base*res);
}
