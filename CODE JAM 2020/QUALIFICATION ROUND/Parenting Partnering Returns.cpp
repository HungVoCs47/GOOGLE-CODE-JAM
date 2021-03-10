# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef pair<ii,int>iii;
# define fi first
# define se second
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int n;
		cin>>n;
		vector<iii>adj;
	    for(int i=0;i<n;i++)
	    {
	        int s,e;
	        cin>>s>>e;
	        adj.push_back(iii(ii(s,e),i));
		}
		sort(adj.begin(),adj.end());
		int jamie=adj[0].fi.se;
		int cam=0;
		bool done=true;
		string ans(n,'J');
		for(int i=1;i<n;i++)
		{
			if(adj[i].fi.fi<jamie)
			{
				if(adj[i].fi.fi<cam)
				{
					done=false;
					break;
				}
				else
				{
				   ans[adj[i].se]='C';
				   cam=adj[i].fi.se;
				}
			}
			else
			{
				jamie=adj[i].fi.se;
			}
		}
		cout<<"CASE #"<<k<<": ";
		if(!done) cout<<"IMPOSSIBLE\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
