#include<bits/stdc++.h>
using namespace std;

#define maxn 1005

int n,
	pre_order[maxn],
	in_order[maxn];

struct node{
	int data;
	struct node* left, *right;
	node(int val){
		data = val;
		left = right = NULL;
	}
};

struct node *build_tree(int pre_start, int pre_end, int in_start, int in_end)
{
	if(pre_start > pre_end || in_start > in_end)
		return NULL;
	
	struct node *root = new node(pre_order[pre_start]);
	// tìm vị trí của root trong mảng in_order[].	=>  tức là từ in_start -> root_index-1 là các node con của cây con trái.
	int root_index;							 		//			  root_index+1 -> in_end  là các node của cây con phải.
	for(int i = in_start; i <= in_end; i++)
	{
		if(in_order[i] == root->data)
		{
			root_index = i;
			break;
		}
	}
	
	// Tiếp tục đệ qui xây dựng cây con trái và phải.
	root->left = build_tree(pre_start+1, pre_start+root_index-in_start, in_start, root_index-1);
	root->right = build_tree(pre_start+root_index-in_start+1, pre_end, root_index+1, in_end);
	
	return root;
}

void pos_order(struct node *root)
{
	if(root == NULL)
		return;
	
	pos_order(root->left);
	pos_order(root->right);
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
			cin>>in_order[i];
		for(int i = 1; i <= n; i++)
			cin>>pre_order[i];
		
		struct node *root = build_tree(1,n,1,n);
		
		pos_order(root);
		
		cout<<endl;
	}


	return 0;
}
