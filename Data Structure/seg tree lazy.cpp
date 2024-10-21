#include<iostream>
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
#define c(a) cout<<a<<endl

const ll mx=2e5+5;
ll st[4*mx],lazy[4*mx]={0};
vector<ll>a;
//idx=index of tree
//begin,end =beginning and ending positon of array for tree index idx
void build(ll idx,ll begin,ll end)
{
	if(begin==end)
	{
		st[idx]=a[begin]; return;
	}
	ll md=(begin+end)/2;
	build(2*idx,begin,md);
	build(2*idx+1,md+1,end);
	st[idx]=st[2*idx]+st[2*idx+1];
}
// query to find value at position pos
ll query(ll idx,ll begin,ll end,ll pos)
{
	if(pos<begin or pos>end)
		return 0;
	if(lazy[idx]!=0)
	{
		st[idx]+=(end-begin+1)*lazy[idx];
		if(begin!=end)
		{
			lazy[2*idx]+=lazy[idx];
			lazy[2*idx+1]+=lazy[idx];
		}
		lazy[idx]=0;
	}
	if(begin==end)
		return st[idx];

	ll md=(begin+end)/2;
	ll sum=query(2*idx,begin,md,pos);
	sum+=query(2*idx+1,md+1,end,pos);
	return sum;
}
//update: add val in range [left,right]
void update(ll idx,ll begin,ll end,ll left,ll right,ll val)
{
	if(lazy[idx]!=0)
	{
		st[idx]+=(end-begin+1)*lazy[idx];
		if(begin!=end)
		{
			lazy[2*idx]+=lazy[idx];
			lazy[2*idx+1]+=lazy[idx];
		}
		lazy[idx]=0;
	}
	if(end<left or right<begin or begin>end)
		return;
	if(left<=begin and end<=right)
	{
		st[idx]+=(end-begin+1)*val;
		if(begin!=end)
		{
			lazy[2*idx]+=val;
			lazy[2*idx+1]+=val;
		}
		return;
	}
	ll md=(begin+end)/2;
	update(2*idx,begin,md,left,right,val);
	update(2*idx+1,md+1,end,left,right,val);
	st[idx]=st[2*idx]+st[2*idx+1];
}
void solve()
{
	ll n,q; cin>>n>>q;
	for(ll i=0;i<n;i++)
	{
		ll x; cin>>x; a.pb(x);
	}
	build(1,0,n-1);
	while(q--)
	{
		ll k; cin>>k;
		if(k==1)
		{
			ll x,y,z; cin>>x>>y>>z; x--; y--;
			update(1,0,n-1,x,y,z);
		}
		else
		{
			ll x; cin>>x; x--;
			c(query(1,0,n-1,x));
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//tt
	solve();
}
