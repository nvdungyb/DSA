#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, c, n;
	t = 1;
	while(t--)
	{
		cin>>c>>n;
		int a[n+5];
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		int resul[n+1][c+5];
		memset(resul, 0, sizeof(resul));
		
		// i đại diện cho số đồ vật trong túi, j đại diện cho khối lượng túi.
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= c; j++)
			{
				resul[i][j] = resul[i-1][j];		// th1: túi không nhận đồ vật i với trọng lượng túi là j..
				if(a[i] <= j)						// th2: túi nhận đồ vật i thỏa trọng lượng túi j lớn hơn trọng lượng vật i.
					resul[i][j] = max(resul[i][j],resul[i-1][j-a[i]]+a[i]);					
			}
		}
		
		cout<<resul[n][c]<<endl;
	}


	return 0;
}

// Đây là bài quy hoạch động trạng thái.
