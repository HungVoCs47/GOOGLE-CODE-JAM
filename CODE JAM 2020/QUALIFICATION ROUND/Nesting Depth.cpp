# include <bits/stdc++.h>
using namespace std;
# define ll long long
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		string s;
		cin>>s;
		string ans="";
		ll open=0;
		for(ll i=0;i<s.size();i++)
		{
			ll x=s[i]-'0';
	        while(open<x)
	        {
	        	ans+="(";
	        	open++;
			}
			while(open>x)
			{
				ans+=")";
				open--;
			}
			//assert(open==x);
			ans+=s[i];
		}
		while(open>0)
		{
			ans+=")";
			open--;
		}
		cout<<"Case #"<<k<<": "<<ans;
		cout<<"\n";
	}
	return 0;
}
