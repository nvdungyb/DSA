#include<bits/stdc++.h>
using namespace std;


int a[10000];
bool visited[10000];

struct var{
	string st;
	int num;
};
 
void insert(var ans, queue<var> &que)
{
	for(int i = 0; i <= 3; i++)
	{
		string ss = ans.st;
		for(int j = 0; j <= 9; j++)
		{
			if(i+j > 0)						// phải có đk này nhé, nếu string có '0' ở đầu thì ảnh hưởng gì tới kết quả ?.
			{
				ss[i] = (j+'0');
				long long tmp = stoi(ss);
				if(a[tmp] == 0 && visited[tmp] == false)
				{
					visited[tmp] = true;
					que.push({ss,ans.num+1});
				}
			}
		}
	}
}

void sevie()
{
	a[0] = 1; a[1] = 1;
	for(int i = 2; i <= 100; i++)
	{
		for(int j = i*i; j <= 10000; j += i)
		{
			if(!a[j])
				a[j] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
 	
 	int t;
 	sevie();
 	cin>>t;
 	while(t--)
 	{
 		string s, ss;
		cin>>s>>ss;
		
		queue<var> que;
		que.push({s,0});
		memset(visited, false, sizeof(visited));
		while(!que.empty())
		{
			var ans = que.front();
			que.pop();
			if(ans.st == ss){
				cout<<ans.num<<endl;
				break;
			}
				
			insert(ans,que);
		
		}
	}
		
		
	return 0;
}
