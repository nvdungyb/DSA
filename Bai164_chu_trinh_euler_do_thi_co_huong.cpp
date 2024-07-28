#include<bits/stdc++.h>
using namespace std;

// Tìm chu trình euler trong đồ thị có hướng
// Khi tất cả các đỉnh của đồ thị có bán bậc ra bằng bán bậc vào.

int a[1001][1001];
int out[1001], in[1001];
int v, e;

bool euler_cercle()
{
	for(int i = 1; i <= v; i++)
	{
		for(int j = 1; j <= v; j++)
		{
			if(a[i][j])
				out[i]++;
			if(a[j][i])
				in[i]++;
		}
		if(out[i] != in[i])
			return false;
	}
	return true;
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
		memset(a, 0, sizeof(a));
		int x, y;
		for(int i = 0; i < e; i++)
		{
			cin>>x>>y;
			a[x][y] = 1;
		}
		
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		
		if(euler_cercle())
			cout<<"1";
		else
			cout<<"0";
		cout<<endl;
	}


	return 0;
}

// Giang hồ đồn đại là vẫn có cách giải nhanh và tiết kiệm hơn.