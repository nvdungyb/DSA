#include<bits/stdc++.h>
using namespace std;

int n, x;
int visited[50], a[50], sum, cnt;

void insert(vector<int> adj[],int k)
{
	cnt++;
	for(int i = 1; i <= k; i++)
	{
		adj[cnt].push_back(a[visited[i]]);
	}
}

void Try(vector<int> adj[], int i)
{
	for(int j = visited[i-1]; j <= n; j++)
	{
		sum += a[j];
		visited[i] = j;
		if(sum == x)
			insert(adj,i);
		else if(sum < x)
			Try(adj,i+1);
		sum -= a[j];
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
		cin>>n>>x;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		
		vector<int> adj[1005];			// Lưu ý việc dùng mảng vector để lưu kết quả nhé, nếu khai báo toàn cục thì kết quả phương án trước vẫn còn trong mảng vector => sai đáp án.
		visited[0] = 1;
		sum = 0;
		cnt = 0;
		
		Try(adj,1);
		
		if(cnt == 0)
			cout<<"-1";
		else{
			cout<<cnt<<" ";
			for(int i = 1; i <= cnt; i++)
			{
				cout<<"{";
				for(auto ans = adj[i].begin(); ans != adj[i].end(); ans++)
				{
					if(ans == adj[i].begin())
						cout<<*ans;
					else
						cout<<" "<<*ans;
				}
				cout<<"} ";
			}
		}
		cout<<endl;
	}


	return 0;
}
