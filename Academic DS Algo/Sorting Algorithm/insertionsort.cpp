#include<iostream>
using namespace std;
#define ll int
int main()
{
    int N=10;
    int a[N]={8,1,3,6,23,78,2,-54,76,0};
    for(ll i=0;i<N-1;i++)
    {
        if(a[i]>a[i+1])
        for(ll j=i+1;j>0 and a[j-1]>a[j];j--)
            swap(a[j-1],a[j]);
    }
    for(ll i=0;i<N;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

