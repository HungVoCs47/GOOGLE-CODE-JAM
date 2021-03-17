# include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	for(int testcase=1;testcase<=t;testcase++)
	{
		int n,k;
		cin>>n>>k;
		int a[n+10];
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		//a[0]=0;
		int ans=1e9;
		int counting[100005];
		memset(counting,0,sizeof(counting));
		for(int i=1;i<=n;i++)
		{
			counting[i]=a[i]+counting[i-1];
		}
		//for(int i=1;i<=n;i++) cout<<counting[i]<<" ";
		for(int i=k;i<=n;i++)
	    {
	    	int s=counting[i]-counting[i-k];
	    	int sum=a[i]*k-s;
	    	ans=min(ans,sum);
		}
		cout<<"CASE #"<<testcase<<": "<<ans<<"\n";
	}
	return 0;
}
