#include<bits/stdc++.h>
using namespace std;

int v, e;
int num[1005], parent[1005];

void make_set()
{
    for(int i = 1; i <= v; i++)
    {
        parent[i] = i;
        num[i] = 1;
    }
}

// Lưu ý nếu ta truyền mảng vào hàm Find, hàm này sẽ đệ quy có thể tới V lần => sẽ gây ra stack overflow.
int find(int u)
{
    if(u != parent[u])					// chỗ này thống nhất là code kiểu này nhé.
    {									// Cẩn thận chỗ này sai thì khó để kiểm tra lắm.
        parent[u] = find(parent[u]);		
    }

    return parent[u];
}

void Union(int x, int y)
{
	int a = find(x);
    int b = find(y);

    if(a != b)
    {
        if(num[a] < num[b])
        	swap(a,b);

    	num[a] += num[b]; 
		parent[b] = a;
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
        make_set();

        for(int i = 1; i <= e; i++)
        {
            int x,y;
            cin>>x>>y;
			Union(x,y); 
        }

        int cnt = 0;
        for(int i = 1; i <= v; i++)
        {
            if(i == parent[i])
                cnt++;
        }
        
        cout<<cnt<<endl;
    }
    

    return 0;
}
