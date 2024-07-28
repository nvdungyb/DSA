#include<bits/stdc++.h>
using namespace std;


#define maxn 1005

int n;
unordered_map<int,int> level_map;

struct node{
	int data;
	struct node *left, *right;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
};


struct node *build_tree(int in_order[], int level_order[], int in_start, int in_end)
{
	if(in_start > in_end)
		return NULL;
	
	int root_val = level_order[0];											// node gốc của cây.
	struct node *root = new node(root_val);
	
	int root_index = level_map[root_val];									// index của node gốc trong in_order[].
	
	int left_subtree_size = root_index - in_start;							// số node trong cây con trái.
	int right_subtree_size = in_end - root_index;							// số node trong cây con phải.
	
	int left_level_subtree[left_subtree_size+5], 							// khởi tạo hai mảng lưu level_order[] của cây con.
		right_level_subtree[right_subtree_size+5];
	
	int left_index = 0, right_index = 0;
	for(int i = 1; i <= left_subtree_size + right_subtree_size; i++)
	{
		if(level_map[level_order[i]] < root_index)
			left_level_subtree[left_index++] = level_order[i];
		else
			right_level_subtree[right_index++] = level_order[i];
	}
	
	root->left = build_tree(in_order, left_level_subtree, in_start, root_index-1);
	root->right = build_tree(in_order, right_level_subtree, root_index+1, in_end);
	
	
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
		
		level_map.clear();
		int level_order[n+5],
			in_order[n+5];
		for(int i = 0; i < n; i++)
		{
			cin>>in_order[i];
			level_map[in_order[i]] = i;
		}
		for(int i = 0; i < n; i++)
			cin>>level_order[i];
			
		struct node *root = build_tree(in_order, level_order,0,n-1);	
		
		pos_order(root);	
		
		cout<<endl;
	}


	return 0;
}

/* Tư tưởng là thế này: phần tử đầu tiên trong mảng level_order là gốc của cây.
	vị trí đó là root_index, vậy từ in_start -> root_index-1 là các node của cây con trái.
	vị trí từ root->index+1 -> in_end là các node của cây con phải.
	
tiếp tục xây dựng các cây con:
	để xây đựng được cây con thì phải biết phần tử root của cây con đó.
	từ hàm unordered_map: lưu chỉ số của các node thuộc in_order và theo level_order => xây dựng lại mảng level_order của cây con.
	

*/