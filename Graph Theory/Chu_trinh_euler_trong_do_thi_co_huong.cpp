#include<bits/stdc++.h>
using namespace std;

int v, e;
set<int>adj[1005];
vector<int>EL;

void euler(int u)
{
	stack<int> st; 
	st.push(u);
	while(!st.empty())
	{
		int x = st.top();
		if(adj[x].size())			// Tìm số cạnh liên thuộc với đỉnh x.
		{
			int y = *adj[x].begin();	// lấy đỉnh đầu tiên trong set.
			st.push(y);					// rồi push vào stack
			adj[x].erase(y);			// Lần lượt xóa cạnh (x,y) và (y,x) trên đồ thị.
			adj[y].erase(x);
		}else{						// Nếu đỉnh không còn cạnh liên thuộc thì push vào chu trình Euler.
			st.pop();
			EL.push_back(x);		// và loại khỏi stack.
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
		cin>>v>>e;
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			adj[x].insert(y);
			adj[y].insert(x);
		}
		
		EL.clear();
		
		euler(1);
		
		for(int x:EL)
			cout<<x<<" ";
		cout<<endl;
	}


	return 0;
}

// Tìm chu trình euler trong đồ thị vô hướng.
// Giả sử đồ thị có chu trình euler.
// Dùng mảng set để lưu danh sách kề, tiện cho việc xóa cạnh.
/*
2
5 6
1 2
2 3
3 1
2 4
4 5
2 5

6 10  
1 2 
1 3 
2 3 
2 4 
2 5 
3 4 
3 5 
4 5 
4 6 
5 6
*/