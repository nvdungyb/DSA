#include<bits/stdc++.h>
using namespace std;

// Tìm chu trình euler của đồ thị có hướng, vô hướng.
/*
+) đk để đồ thị vô hướng là đồ thị euler khi và chỉ khi đồ thị liên thông và các đỉnh thuộc đồ thị có bậc chẵn.
+) đk để đồ thị có hướng là đồ thị euler khi và chỉ khi đồ thị liên thông yếu và các đỉnh thuộc đồ thị có bán bậc ra bằng bán bậc vào.

*/


/* Thuật toán này cũng có thể dùng để tìm đường đi euler
+) đk để đồ thị vô hướng là đồ thị nửa euler khi và chỉ khi đồ thị liên thông và có số đỉnh bậc lẻ không lớn hơn 2.
+) đk để đồ thị có hướng là đồ thị nửa euler khi và chỉ khi đồ thị liên thông yếu và số đỉnh có bán bậc vào chênh lệch với bán bậc ra bằng 1 không vượt quá 2.


+) đối với đồ thị vô hướng thì đỉnh bắt đầu u là đỉnh có bậc lẻ đầu tiên, đỉnh kết thúc là đỉnh bậc lẻ còn lại.
+) đối với đồ thị có hướng thì đỉnh bắt đầu u là đỉnh có bán bậc ra hơn bán bậc vào là 1, đỉnh kết thúc là đỉnh có bán bậc vào lớn hơn bán bậc ra là 1.

*/


vector<int> resul;
bool visited[30][30];
int v, e;

void euler_circle(set<int> adj[], int u)
{
	for(int x:adj[u])
	{	
		if(!visited[u][x])
		{	
			visited[u][x] = true;
			visited[x][u] = true;
			euler_circle(adj,x);
		}
	}
	resul.push_back(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	v = 10, e = 17;
	set<int> adj[v+5];
	for(int i = 1; i <= e; i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].insert(y);
	}
	
	
	memset(visited, false, sizeof(visited));
	euler_circle(adj,2);
	
	for(auto it = resul.rbegin(); it != resul.rend(); it++)
		cout<<*it<<" ";
		

	return 0;
}
