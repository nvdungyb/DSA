#include<bits/stdc++.h>
using namespace std;


int a[10000];
void sivie()
{
	a[0] = a[1] = 1;
	for(int i = 2; i <= 100; i++)
	{
		for(int j = i*i; j <= 10000; j+=i)
			a[j] = 1;
	}
}

bool visited[10000];
void insert(queue<pair<string,int>> &que, pair<string,int> ans)
{
	for(int i = 0; i < 4; i++)
	{
		string s = ans.first;
		for(int j = 0; j <= 9; j++)
		{
			if(i+j > 0)
			{
				s[i] = j+'0';
				long long tmp = stoi(s);
				if(a[tmp] == 0 && !visited[tmp]){
					que.push({s,ans.second+1});
					visited[tmp] = 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	sivie();
	cin>>t;
	while(t--)
	{
		string s, t;
		cin>>s>>t;
		queue<pair<string,int>> que;
		que.push({s,0});
		memset(visited, false, sizeof(visited));
		while(!que.empty())
		{
			pair<string,int> ans = que.front(); que.pop();
			if(ans.first == t){
				cout<<ans.second<<endl;
				break;
			}
			
			insert(que,ans);
			
		}
	}


	return 0;
}
