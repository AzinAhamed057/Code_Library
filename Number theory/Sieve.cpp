#include<bits/stdc++.h>
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


int main()
{
    //Normal Sieve
    ll N=1e6;
    vector<char>sieve(N+1,true);
    for(ll i=2;i*i<=N;i++)
    {
        if(sieve[i])
        for(ll j=i*i;j<=N;j+=i)
            sieve[j]=false;
    }

    //Segmented Sieve
    ll l,r; cin>>l>>r;
    vector<ll>Prime;
    for(ll i=2;i*i<=r;i++)
        if(sieve[i])
            Prime.pb(i);
    vector<char>ans(r-l+1,true);
    for(auto &i:Prime)
    {
        for(ll j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
            ans[j-l]=0;
    }
    if(l==1) ans[0]=0;
}
