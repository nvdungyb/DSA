#include<bits/stdc++.h>
using namespace std;

int a[400] ={0}, n, p ,s, sum, cnt;
int visited[20];
vector<int> resul[30];

void sive()
{
	a[1] = 1,a[0] = 1;
	for(int i = 2; i <= 20; i++)
	{
		for(int j = i*i; j <= 400; j+=i)
		{
			a[j] = 1;
		}
	}
}

void insert(int k)
{
	cnt++;
	for(int i = 1; i <= k; i++)
	{
		resul[cnt].push_back(visited[i]);
	}
}

void Try(int i)
{
	for(int j = visited[i-1]+1; j < s; j++)
	{
		if(!a[j])
		{
			sum += j;
			visited[i] = j;
			if(i == n){
				if(sum == s)
					insert(i);
			}else if(i < n && sum < s){
				Try(i+1);
			}
			sum -= j;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sive();
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>p>>s;
		
		sum = 0;
		visited[0] = p;
		cnt = 0;
		
		memset(resul, 0, sizeof(resul));
		
		Try(1);
		
		cout<<cnt<<endl;
		for(int i = 1; i <= cnt; i++)
		{
			for(int x:resul[i])
				cout<<x<<" ";
			cout<<endl;
		}
	}


	return 0;
}
