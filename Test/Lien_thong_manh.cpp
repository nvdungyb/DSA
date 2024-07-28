#include<bits/stdc++.h>
using namespace std;


int v, e,
	id[1005],			// Mảng định danh cho đỉnh. 
	low[1005], 			// Mảng giá trị định danh nhỏ nhất mà đỉnh có thể tới.
	on_stack[1005], 	// Mảng kiểm tra xem đỉnh có trong stack hay ko?.
	cnt, ans;
vector<int> adj[1005];	
vector<vector<int>> result;			// vector lưu các thành phần liên thông mạnh.
stack<int> st;						

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt;
	st.push(u);
	on_stack[u] = 1;
	
	for(int v : adj[u])			
	{
//		if(v == p)					// Đk này cần thiết khi tìm đỉnh trụ, cạnh cầu của đồ thị vô hướng thôi.
//			continue;				// Đơn đồ thị có hướng thì ko cần thiết, nhưng đa đồ thị có hướng thì sẽ sai nếu từ đỉnh v có đường đi tới u  => vẫn là thành phần liên thông mạnh.
		if(id[v])
		{
			if(on_stack[v])
				low[u] = min(low[u],id[v]);
		}else{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
		}
	}
	
	if(id[u] == low[u])						// Nếu id[u] == low[u] thì u là đỉnh gốc của 1 tp liên thông mạnh của đồ thị.
	{
		vector<int> component;
		int v;
		do{
			v = st.top();
			st.pop();
			on_stack[v] = 0;
			component.push_back(v);
		}while(v != u);
		
		ans++;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	t = 1;
	while(t--)
	{
		cin>>v>>e;
		for(int i = 1; i <= v; i++)
		{
			adj[i].clear();
			id[i] = 0;
			low[i] = 0;
			on_stack[i] = 0;
		}
		
		for(int i = 1; i <= e; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		
		cnt = 0;
		result.clear();
		dfs(1,0);
		
		cout<<ans;
		
		cout<<endl;
	}


	return 0;
}

/*	lí giải mảng đánh dấu on_stack tại sao lại cần thiết.
+ Một thành phần liên thông mạnh là duy nhất. => không tồn tại hai tp liên thông mạnh mà có chung đỉnh.
+ Nếu không có đk on_stack thì các đỉnh trong tp liên thông mạnh có thể có các đỉnh kề với nó mà không thuộc cùng tp liên thông mạnh.
*/