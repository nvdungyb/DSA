#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int k,s,t;
	cin>>k;
	while(k--)
	{
		cin>>s>>t;
		int a[50000];
		memset(a,0,sizeof(a));
		
		queue<int> que;
		que.push(s);
		a[s] = 0;
		while(!que.empty())
		{
			int x = que.front();
			que.pop();
			if(a[x*2] == 0 && x <= t)
			{
				a[x*2] = a[x]+1;
				que.push(x*2);
			}
			if(x-1 > 0 && a[x-1] == 0)
			{
				a[x-1] = a[x]+1;
				que.push(x-1);
			}
			
			if(a[t] != 0)
				break;
		}
			
		cout<<a[t]<<endl;
	}
	
	
	return 0;
}