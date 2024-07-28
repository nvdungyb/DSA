#include<bits/stdc++.h>
using namespace std;


int n, s, a[40] = {1}, 						// Phần tử đầu tiên của mảng là 1 để thỏa mãn sử dụng đk nhánh cận, hoặc chỉ cần thêm đk là j != 1 thì không đệ qui thêm là ok
		x[40], sum, result = 40;

void Try(int i)
{
	for(int j = x[i-1]-1; j >= 1; j--)
	{
		if(a[j] <= s)
		{
			sum += a[j];
			x[i] = j;
			
			if(sum == s){
				if(i < result)
					result = i;
			}else if((s-sum) > 0 && (i + (s-sum)/a[j-1]) < result)
				Try(i+1);
				
			sum -= a[j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>s;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	
	sort(a+1,a+n+1);
	
	x[0] = n+1;
	Try(1);
	
	if(result == 40)
		cout<<"-1";
	else 
		cout<<result;


	return 0;
}
