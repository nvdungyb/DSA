#include<bits/stdc++.h>
using namespace std;

int a[10], parent[10];
long long sum;
bool visited[10];


// biến sum không thể khởi đầu là 0 được, bởi vì sẽ có th i == 1  mà sum *= a[i] điều đó khiến sum đáng lẽ phải là a[i] mà thành 0.

bool Try(int i)
{
	for(int j = 1; j <= 5; j++)
	{
		if(!visited[j])
		{
			visited[j]  = true;
			for(int k = 1; k <= 3 ; k++)
			{
				if(i == 1)
					sum = a[j];
				else{
					if(k == 1)
					{
						sum += a[j];
					}else if(k == 2)
					{
						sum -= a[j];
					}else{
						sum *= a[j];
					}
				}
				
				if(i == 5)
				{
					if(sum == 23)
						return true;
				}else{
					if(Try(i+1))
						return true;
				}
				
				if(i == 1)		// th i == 1 thì sẽ không cần hoán vị giữa các toán tử.
					break;
				
				if(k == 1)
				{
					sum -= a[j];
				}else if(k == 2)
				{
					sum += a[j];
				}else{
					sum /= a[j];
				}
			}	
			
			visited[j] = false;
		}
	}
	
	return false;
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
		for(int i = 1; i <= 5; i++)
			cin>>a[i];
		
		memset(visited, false, sizeof(visited));
		if(Try(1))
			cout<<"YES";
		else
			cout<<"NO";
			
		cout<<endl;
	}


	return 0;
}
