+ Disjoint set Union (DSU: cấu trúc dữ liệu rời nhau)
: Giúp hợp hai phần tử vào cùng một tập hợp.
: Chỉ ra một phần tử thuộc tập hợp nào đó rất nhanh.

+ Có hai thao tác chính: hợp hai tập lại với nhau, chỉ ra các phần tử của một tập hợp.

_ Thao tác make_set(a); tạo một tập hợp a với đại diện là chính nó.
_ Thao tác union(a,b); gộp hai tập hợp, a thuộc tập thứ 1, b thuộc tập thứ 2.
_ Thao tác Find(a); tìm đại diện của tập hợp chứa a.



int parent[];	// lưu đại diện của các phần tử.
int size[];		// lưu số lượng phần tử trong tập hợp.
int n;

void make_set()
{
	for(int i = 1; i <= n; i++)
	{
		parent[i] = i;			// mỗi phần tử riêng biệt thì nó đại diện cho chính nó.
		size[i] = 1;			// số lượng phần tử trong tập hợp.	
	}
} 

int find(v)
{
	if(v == parent[v])			// nếu phần tử mà đại diện là chính nó thì phần tử đó đại diện cho cả tập hợp.
		return v;
	return parent[v] = find(parent[v]);		// path compression.
}

void union(a,b)
{
	int x = find(a);				// Tìm đại diện của tập chứa phần tử a, b.
	int y = find(b);
	
	if(x != y)
	{
		if(size[x] < size[y])
			swap(x,y);			
		paren[y] = x;				// Gán đại diện của tập nhỏ hơn là đại diện của tập lớn.
		size[x] += size(y);			// kích thước của tập sau khi gộp.
	}
}






