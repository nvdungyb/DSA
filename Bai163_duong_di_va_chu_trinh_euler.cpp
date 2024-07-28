#include<bits/stdc++.h>
using namespace std;

// Đường đi và chu trình euler trong đồ thị vô hướng 
// Kiểm tra trên đồ thị vô hướng liên thông.

int v, e;

int euler(vector<int>vt[])
{
	int cnt = 0;
	for(int i = 1; i <= v; i++)
	{
		if(vt[i].size()%2 != 0)
			cnt++;
	}
	if(cnt == 0)
		return 2;
	else if(cnt == 2)
		return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		vector<int> vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		
		int ans = euler(vt);
		cout<<ans<<endl;
	}


	return 0;
}
