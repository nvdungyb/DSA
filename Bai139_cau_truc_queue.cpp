#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int x, y;
		queue<int> que;
		while(n--)
		{
			cin>>x;
			if(x == 1)
				cout<<que.size()<<endl;
			else if(x == 2){
				if(que.empty())
					cout<<"YES";
				else
					cout<<"NO";
				cout<<endl;
			}else if(x == 3){
				cin>>y;
				que.push(y);
			}else if(x == 4){
				if(!que.empty())
					que.pop();
			}else if(x == 5){
				if(!que.empty())
					cout<<que.front();
				else 
					cout<<"-1";
				cout<<endl;
			}else if(x == 6){
				if(!que.empty())
					cout<<que.back();
				else
					cout<<"-1";
				cout<<endl;
			}
		}
	}
	

	return 0;
}
