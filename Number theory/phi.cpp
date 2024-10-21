
#define N 5000008
vector<ll>phi(N+1);
void Phi(){
    phi[0]=0;
    phi[1]=1;
    for (ll i=2;i<=N;i++)
        phi[i]=i-1;

    for (ll i=2;i<=N;i++) {
        if (phi[i]==i) {
            for (ll j=i;j<=N; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}
