#include<iostream>
using namespace std;
#define ll int
int main()
{
    int N=10;
    int a[N]={8,1,3,6,23,78,2,-54,76,0};
    for(ll i=0;i<N-1;i++)
    {
        for(ll j=0;j<N-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]^=a[j+1];
                a[j+1]^=a[j];
                a[j]^=a[j+1];
            }
        }
    }
    for(ll i=0;i<N;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
