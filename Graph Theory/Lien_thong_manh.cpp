#include<bits/stdc++.h>
using namespace std;


#define maxn 10005
int v, e,
	id[maxn],			// Mảng định danh cho đỉnh. 
	low[maxn], 			// Mảng giá trị định danh nhỏ nhất mà đỉnh có thể tới.
	on_stack[maxn], 	// Mảng kiểm tra xem đỉnh có trong stack hay ko?.
	cnt;
vector<int> adj[maxn];	
vector<vector<int>> result;			// vector lưu các thành phần liên thông mạnh.
stack<int> st;						

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt;
	st.push(u);								// Các đỉnh được đẩy vào trong stack, và được đánh dấu là đã có trong stack.
	on_stack[u] = 1;
	
	for(int v : adj[u])						// Xét các đỉnh kề với u.
	{
		if(!id[v])
		{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
		}else if(on_stack[v])				// Nếu đỉnh v đã định danh rồi và vẫn tồn tại trong stack => tức nghĩa là chúng cùng thuộc thành phần liên thông mạnh.	
		{
			low[u] = min(low[u],id[v]);
		}
	}
	
	if(id[u] == low[u])						// Nếu id[u] == low[u] thì u là đỉnh gốc của 1 tp liên thông mạnh của đồ thị.
	{
		vector<int> component;
		int v;
		do{
			v = st.top();
			st.pop();
			on_stack[v] = 1;				// Đánh dấu các đỉnh thuộc cùng một thành phần liên thông mạnh.
			component.push_back(v);
		}while(v != u);
		
		result.push_back(component);
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
		for(int i = 1; i <= v; i++)
		{
			if(!on_stack[i])
				dfs(i,0);
		}
		
		int ans = result.size();
		cout<<ans;
		
		cout<<endl;
	}


	return 0;
}

/*	lí giải mảng đánh dấu on_stack tại sao lại cần thiết.
+ Một thành phần liên thông mạnh là duy nhất. => không tồn tại hai tp liên thông mạnh mà có chung đỉnh.
+ Nếu không có đk on_stack thì các đỉnh trong tp liên thông mạnh có thể có các đỉnh kề với nó mà không thuộc cùng tp liên thông mạnh.
*/