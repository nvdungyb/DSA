#include<bits/stdc++.h>
using namespace std;


struct node{
	int data;
	struct node *left, *right;
	int level;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

bool visited[10005];

struct node *make_tree(struct node *root, int a, int b, int c)
{
	if(root == NULL)
		return NULL;
	
	if(root->data == a)
	{
		if(c == 'L' && root->left == NULL && !visited[b]){
			root->left = new node(b);
			visited[b] = true;
		}
		else if(c == 'R' && root->right == NULL && !visited[b]){
			root->right = new node(b);
			visited[b] = true;
		}
			
	}else{
		if(!visited[b])
			root->left = make_tree(root->left, a, b, c);
		if(!visited[b])
			root->right = make_tree(root->right, a, b, c);
	}
	
	return root;
}

long long level_order(struct node *root)
{
	long long sum = 0;
	queue<struct node*> que;
	que.push(root);
	while(!que.empty())
	{
		struct node *ans = que.front();	
		que.pop();
			
		if(ans->left != NULL)
			que.push(ans->left);
		if(ans->right != NULL)
		{
			if(ans->right->right == NULL && ans->right->left == NULL)
				sum += ans->right->data;
			else
				que.push(ans->right);
		}
	}
	
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m;
	cin>>t;
	while(t--)
	{
		int a, b;
		char c;
		memset(visited, false, sizeof(visited));
		cin>>n;
	
		cin>>a>>b>>c;
		struct node *root = new node(a);
		root = make_tree(root, a, b, c);
		n--;
		
		while(n--)
		{							
			cin>>a>>b>>c;
			root = make_tree(root, a, b, c);
		}
		
	 	long long result = level_order(root);
		
		cout<<result<<endl;
	}
	

	return 0;
}

/*	Các th không thể tạo ra cây nhị phân.
	+) thêm node vào bên trái (phải) mà node đó đã tồn tại node trái (phải).
	+) một node không thể có hai node khác cùng trỏ tới.
	
*/

