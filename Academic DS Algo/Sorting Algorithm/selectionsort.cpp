#include<iostream>
using namespace std;
#define ll int
int main()
{
    int N=10;
    int a[N]={8,1,3,6,23,78,2,-54,76,0};
    for(ll i=0;i<N-1;i++)
    {
        ll idx=i;
        for(ll j=i;j<N;j++)
        {
            if(a[idx]>a[j])
            {
                idx=j;
            }
        }
        swap(a[i],a[idx]);
    }
    for(ll i=0;i<N;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

