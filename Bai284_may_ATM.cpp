#include<bits/stdc++.h>
using namespace std;

int s, n, a[50] = {1};				// khởi tạo giá trị ban đầu là 1 để sử dụng kĩ thuật nhánh cận.
int visited[50], fopt, cnt, sum;

void Try(int i)
{
	for(int j = visited[i-1]-1; j >= 1; j--)
	{
		if(a[j] <= sum)
		{
			sum -= a[j];
			cnt++;
			visited[i] = j;
			
			if(sum == 0){
				if(cnt < fopt)
					fopt = cnt;
			}else if(sum > 0 && (cnt+sum/a[j-1]) < fopt){		// áp dụng nhánh cận vào quay lui giải toàn bộ.
				Try(i+1);
			}
			
			cnt--;
			sum += a[j];
		}
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
		cin>>n>>s;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		
		sum = s, cnt = 0; fopt = INT_MAX;
		visited[0] = n+1;
		
		Try(1);	
		
		if(fopt == INT_MAX)
			cout<<"-1";
		else
			cout<<fopt;
		cout<<endl;
	}


	return 0;
}
