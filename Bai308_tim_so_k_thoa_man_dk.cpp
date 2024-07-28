#include<bits/stdc++.h>
using namespace std;


bool visited[6];
int a[100005];

void pre()
{
 	queue<int> que;
 	que.push(1);
 	que.push(2);
 	que.push(3);
 	que.push(4);
 	que.push(5);
 	while(!que.empty())
 	{
 		int x = que.front();
		que.pop();
		if(x > 100000)
			break;
		
		a[x] = 1;	
			
		memset(visited, false, sizeof(visited));
		int ans = x;
		while(ans)
		{
			int res = ans%10;
			visited[res] = true;
			ans /= 10;
		}
		
		for(int i = 0; i <= 5; i++)
		{
			if(!visited[i])
				que.push(x*10+i);
		}
	}
	
	for(int i = 1; i <= 100000; i++)
	{
		a[i] += a[i-1];
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
 	
 	int t;
 	pre();
 	cin>>t;
 	while(t--)
 	{
 		int l, r;
		cin>>l>>r;
		cout<<a[r]-a[l-1]<<endl;
	}
  
		
	return 0;
}
