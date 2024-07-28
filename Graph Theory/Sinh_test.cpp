#include<bits/stdc++.h>
using namespace std;


struct point{
	int x, y, step;
	string kind;
};

pair<int,int> b[10] = {{-1,-2},{1,-2},{2,-1},{2,1},{-1,2},{1,2},{-2,1},{-2,-1}};
pair<int,int> c[10] = {{0,1},{1,1},{0,1},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	point ma, vua;
	ma.kind = "ma", ma.step = 0,
	vua.kind = "vua", vua.step = 0;

	cin>>n;
	int count[n+5][n+5];
	char a[n+5][n+5];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin>>a[i][j];
			count[i][j] = 0;
			if(a[i][j] == 'M')
				ma.x = i, ma.y = j;
			if(a[i][j] == 'T')
				vua.x = i, vua.y = j;
		}
	}
	
	bool visited_ma[n+5][n+5];
	memset(visited_ma, false, sizeof(visited_ma));
	bool visited_vua[n+5][n+5];
	memset(visited_vua, false, sizeof(visited_vua));
	
	visited_ma[ma.x][ma.y] = true,
	visited_vua[vua.x][vua.y] = true;
	
	queue<pair<point,point>> que;
	que.push({ma,vua});
	while(!que.empty())
	{
		pair<point,point> ans = que.front();	que.pop();
		point ans1 = ans.first;											// ma
		point ans2 = ans.second;										// vua
		if(ans1.x == ans2.x && ans1.y == ans2.y){
			cout<<ans1.step<<endl;
			break;
		}
		
		point res, pos;
		for(int i = 0; i < 8; i++)
		{
			res.x = ans1.x+b[i].first;
			res.y = ans1.y+b[i].second;
			if(res.x >= 1 && res.x <= n && res.y >= 1 && res.y <= n && a[res.x][res.y] == '.')
			{
				res.step = ans1.step+1;
				for(int j = 0; j < 8; j++)
				{
					pos.x = ans2.x+c[j].first;
					pos.y = ans2.y+c[j].second;
					if(pos.x >= 1 && pos.x <= n && pos.y >= 1 && pos.y <= n && a[pos.x][pos.y] == '.')
					{
						que.push({res,pos});
					}
				}
			}
		}
		
	}
 	

	return 0;
}
