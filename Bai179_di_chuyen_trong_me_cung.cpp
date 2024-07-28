#include<bits/stdc++.h>
using namespace std;

int a[10][10], n;
int visited[10][10];
pair<int,int>b[4]={{1,0},{0,1},{0,-1},{-1,0}};
vector<string>vt;
string s="";

void loang(int x, int y)
{
	for(int i = 0; i <= 3; i++)
	{
		int x_new = x+b[i].first;
		int y_new = y+b[i].second;
		if(x_new >= 0 && x_new < n && y_new >= 0 && y_new < n && a[x_new][y_new] && !visited[x_new][y_new])
		{
			visited[x_new][y_new] = 1;
			
			if(b[i].first == -1)
				s+='U';
			else if(b[i].second == -1)
				s+='L';
			else if(b[i].first == 1)
				s+='D';
			else if(b[i].second == 1)
				s+='R';
			
			if(x_new == n-1 && y_new == n-1)
			{
				vt.push_back(s);
			}else{
				loang(x_new,y_new);
			}
			
			s.erase(s.length()-1,1);
			visited[x_new][y_new] = 0;
		}
	}
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
		cin>>n;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cin>>a[i][j];
		}
		
		memset(visited, 0, sizeof(visited));
		
		if(!a[0][0])
		{
			cout<<"-1";
		}else{
			visited[0][0] = 1;
			vt.clear();
			loang(0,0);
			if(!vt.size())
				cout<<"-1";
			else{
				sort(vt.begin(),vt.end());
				for(auto x:vt)
					cout<<x<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}