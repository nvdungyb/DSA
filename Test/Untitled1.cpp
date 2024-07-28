#include<bits/stdc++.h>
using namespace std;


// cho biết phép duyệt giữa và duyệt trước của cây, khôi phục lại cây.

#define maxn 1005

int n, preOrder[maxn], inOrder[maxn];

struct node{
	int data;
	struct node* pleft, *pright;
	node(int val)
	{
		data = val;
		pleft = pright = NULL;
	}
};

// Hàm khôi phục lại cây từ thứ tự duyệt trước và giữa.
struct node* recover_tree(int pre_start, int pre_end, int in_start, int in_end)
{
	if(pre_start > pre_end || in_start > in_end)
		return NULL;
		
	struct node *root = new node(preOrder[pre_start]);
	
	int root_index = -1;
	for(int i = in_start; i <= in_end; i++)
	{
		if(inOrder[i] == root->data){
			root_index = i;
			break;
		}
	}
	
	root->pleft = recover_tree(pre_start+1, pre_start+root_index-in_start, in_start, root_index-1);
	root->pright = recover_tree(pre_start+root_index-in_start+1, pre_end, root_index+1, in_end);	
	
	return root;
}

void posOrder(struct node *root)
{
	if(root == NULL)
		return;
		
	posOrder(root->pleft);
	posOrder(root->pright);
	cout<<root->data<<" ";
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
		for(int i = 1; i <= n; i++)
			cin>>inOrder[i];
		
		for(int i = 1; i <= n; i++)
			cin>>preOrder[i];	
		
		struct node *root = recover_tree(1,n,1,n);
		
		posOrder(root);
		
		cout<<endl;
	}
	

	return 0;
}
