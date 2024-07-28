#include<bits/stdc++.h>
using namespace std;


struct point{
	int first, second;
	int num;
};

pair<int,int> b[9] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{1,-2},{-1,-2}}; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		char s1,s2,s3,s4;
		cin>>s1>>s2>>s3>>s4;
		int x = s1-'a'+1, y = s2-'0';
		int n = s3-'a'+1, m = s4-'0';
		
		queue<point> que;
		que.push({x,y,0});
		while(!que.empty())
		{
			point ans = que.front();
			if(ans.first == n && ans.second == m)
			{
				cout<<ans.num<<endl;
				break;
			}
			que.pop();
			for(int i = 0; i <= 7; i++)
			{
				int X = ans.first+b[i].first;
				int Y = ans.second+b[i].second;
				int Z = ans.num;
				if(X >= 1 && X <= 8 && Y >= 1 && Y <= 8)				// Có thể đánh dấu a[X][Y] đã duyệt rồi thì không duyệt qua nữa.
				{
					que.push({X,Y,Z+1});
				}
			}			
		}
	}
		
	
	return 0;
}