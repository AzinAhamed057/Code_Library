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
#define pb push_back
#define pf push_front
#define mp make_pair
#define tt ll t;cin>>t;while(t--)
#define nn cout<<endl;
#define ff(i,a,n) for(ll i=a;i<n;i++)
#define f(i,n,a) for(ll i=n;i>=a;i--)
#define fr(x, a) for(auto &x:a)
#define F(a) for(auto &x:a) cin>>x
#define cY c("YES")
#define cN c("NO")
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
#define inf LLONG_MAX
/* Read the damn question carefully*/
struct edge
{
    ll a,b,z;
};
vector<edge>e;
void solve()
{
    ll n,m; cin>>n>>m;
    vector<ll>d(n,inf);
    ff(i,0,m)
    {
        ll a,b,c; cin>>a>>b>>c;
        e.pb({a,b,c});
    }
    for(; ;)
    {
        bool any=true;
        for(ll i=0;i<n-1;i++)
        {
            if(e[i].a<inf)
            {
                if(d[e[i].b]<d[e[i].a]+e[i].z)
                {
                    d[e[i].b]=d[e[i].a]+e[i].z;
                    any=false;
                }
            }
        }
        if(any)
            break;
    }
    ff(i,0,n)
        cout<<d[i]<<" "; nn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//tt
	solve();
}
/*




*/
ll nCr(ll n,ll r)
{
	r=(n-r<=r) ? n-r : r;
	ll ans=1;
	for(ll i=0;i<r;i++)
	{
		ans*=(n-i);
		ans/=(i+1);
	}
	return ans;
}
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
