



vector<ll> prefix_function(string s)
{
	ll n=s.length();
	vector<ll>pi(n); pi[0]=0;
	for(ll i=1;i<n;i++)
	{
		ll j=pi[i-1];
		while(j>0 and s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i]=j;
	}
	return pi;
}