#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Merge(ll lw,ll md,ll hh,ll a[])
{
    ll n=hh-lw+1;
    ll arr[n];
    ll i=0,j=lw,k=md+1;
    for( i=0;i<n and j<=md and k<=hh;i++)
    {
        if(a[j]<=a[k])
            arr[i]=a[j++];
        else arr[i]=a[k++];
    }
    for(;j<=md;j++)
        arr[i++]=a[j];
    for(;k<=hh;k++)
        arr[i++]=a[k];
    for( i=0,j=lw;i<n;i++,j++)
        a[j]=arr[i];
    return;

}
void Merge_Sort(ll lw,ll hh,ll a[])
{
    if(lw<hh)
    {
        ll md=(lw+hh)/2;
        Merge_Sort(lw,md,a);
        Merge_Sort(md+1,hh,a);
        Merge(lw,md,hh,a);
    }
}
int main()
{
    ll n; cin>>n; ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Merge_Sort(0,n-1,a);

    for(ll i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
