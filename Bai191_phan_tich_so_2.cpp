#include<bits/stdc++.h>
using namespace std;

int n, sum, cnt;
int visited[15];

void insert(vector<int> vt[], int k)
{
	cnt++;
	for(int i = 1; i <= k; i++)
		vt[cnt].push_back(visited[i]);
}

void Try(vector<int> vt[], int i)
{
	for(int j = visited[i-1]; j >= 1; j--)
	{
		sum += j;
		visited[i] = j;
		if(sum == n)
			insert(vt,i);
		else if(sum < n)
			Try(vt, i+1);
		sum -= j;
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
		
		visited[0] = n;
		sum = 0;
		cnt = 0;
		vector<int> vt[100];
		
		Try(vt,1);
		
		cout<<cnt<<endl;
		for(int i = 1; i <= cnt; i++)
		{
			cout<<"(";
			for(auto x = vt[i].begin(); x != vt[i].end(); x++)
			{
				if(x == vt[i].begin())
					cout<<*x;
				else
					cout<<" "<<*x;
			}
			cout<<") ";
		}
		cout<<endl;
	}


	return 0;
}
