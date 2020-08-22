#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool pred(pair<ll,char> a, pair<ll,char> b){
	if(a.first!=b.first)
		return a.first<b.first;
	else
		return a.second<b.second;
}
int main()
{
	ll s,p;
	cin>>s>>p;
	vector<pair<ll,char> > seg;
	for(ll i=0;i<s;i++)
   {
		ll a,b;
		cin>>a>>b;
		seg.push_back(pair<ll,char>(a,'l'));
		seg.push_back(pair<ll,char>(b,'r'));
	}
	vector<ll> orig;
	for(ll i=0;i<p;i++)
    {
		ll a;
		cin>>a;
		orig.push_back(a);
		seg.push_back(pair<ll,char>(a,'p'));
	}
	sort(seg.begin(),seg.end(),pred);
	vector<ll>val;map<ll,ll> m;
	ll c=0;
	for(auto x:seg)
        {
		if(x.second=='l')
			c++;
		else if(x.second=='r')
			c--;
		if(x.second=='p')
			m[x.first]=c;
		}
	for(ll a:orig)
		val.push_back(m[a]);
    for(ll ans:val)
		cout<<ans<<" ";
	cout<<endl;
}
