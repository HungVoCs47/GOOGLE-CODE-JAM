# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
# define fi first
# define se second
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
    for(int l=1;l<=t;l++)
    {
    	priority_queue<iii>q;
    	int n,k;
    	cin>>n>>k;
    	int a[n+10];
    	for(int i=0;i<n;i++) cin>>a[i];
    	for(int i=1;i<n;i++) 
    	{
    		q.push(iii(a[i]-a[i-1],ii(1,a[i]-a[i-1])));
		}
		while(k--)
		{
			iii now=q.top(); q.pop();
			//int res=now.top().fi;
			//int num=now.top().se.fi;
			//int delta=now.top().se.se;
			now.se.fi++;
			now.fi=now.se.se/now.se.fi;
			if(now.se.se%now.se.fi) now.fi++;
			q.push(now);
		}
		cout<<"CASE #"<<l<<": "<<q.top().fi<<"\n" ; 
	}
	return 0;
}
