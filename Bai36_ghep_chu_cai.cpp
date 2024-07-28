#include<bits/stdc++.h>
using namespace std;

bool visited[15];
int parent[15], n;

bool check()
{
	for(int i = 2; i < n; i++)
	{
		if(parent[i] == 1)
		{
			if(parent[i-1] != 5 && parent[i+1] != 5)	
				return false;
		}else if(parent[i] == 5)
		{
			if(parent[i-1] != 1 && parent[i+1] != 1)	
				return false;
		}
	}
	return true;
}

void display()
{
	for(int i = 1; i <= n; i++)
	{
		cout<<char(parent[i]-1+'A');
	}
	cout<<endl;
}

void Try(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(!visited[j])
		{
			parent[i] = j;
			visited[j] = true;
			if(i == n){
				if(check())
					display();
			}else
				Try(i+1);
			
			visited[j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char s;
	cin>>s;
	n = s-'A'+1;
	
	Try(1);


	return 0;
}
