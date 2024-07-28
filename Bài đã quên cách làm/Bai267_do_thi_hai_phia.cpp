#include<bits/stdc++.h>
using namespace std;

// Đồ thị hai phía là đồ thị có thể chia thành hai tập không giao nhau thỏa 
// mãn điều kiện không có cạnh nối hai đỉnh bất kì thuộc cùng một tập hợp.

// Tư tưởng rằng ta cố tô mầu sao cho hai đỉnh kề nhau có mầu khác nhau.
// Nếu ko tô được thì đồ thị đó ko phải là đồ thị hai phía.

int v, e;
int color[1005];

bool check(vector<int>adj[], int u)
{
	queue<int> que; 
	que.push(u);
	color[u] = 0;
	while(!que.empty())
	{
		int v = que.front(); que.pop();
		for(int i : adj[v])
		{
			if(color[i] == -1)				// Nếu đỉnh chưa được duyệt.
			{
				color[i] = 1 - color[v];	// hai đỉnh kề nhau mầu khác nhau.
				que.push(i);
			}else{							// Nếu đã duyệt rồi, mà hai đỉnh kề nhau cùng mầu thì đồ thị không phải hai phía.
				if(color[i] == color[v])
					return false;
			}
		}
	}
	return true;
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
		cin>>v>>e;
		vector<int> adj[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		memset(color, -1, sizeof(color));
		int ok =  0;
		for(int i = 1; i <= v; i++)
		{
			if(color[i] == -1)
			{
				if(!check(adj,i)){
					ok =  1;
					break;
				}
			}
		}
		
		if(!ok)	
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}


	return 0;
}
