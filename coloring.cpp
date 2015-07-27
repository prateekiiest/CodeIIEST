#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	vector<int> v[100005];
	int color[100005];
	for(int i=0;i<100005;i++)
	{
		v[i].clear();
		color[i] = -1;
	}
	cout<<"Enter the number of vertices in the graph: ";
	int n,e;
	cin>>n;
	cout<<"Enter the number of edges in the graph: ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter an edge: ";
		int x,y;
		cin>>x;
		cin>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	} 
	queue<int> q;
	q.push(1);
	color[1] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		int s = v[u].size();
		for(int j=0;j<s;j++)
		{
			int w = v[u][j];
			if(color[w] == -1)
			{
				color[w] = 1-color[u];
				q.push(w);
			}
			else if(color[w] == color[u])
			{
				cout<<"Bipartite partitioning is not possible"<<endl;
				return 0;
			}
		}
	}
		
	cout<<"Coloring of the graph is as follows: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<color[i];
	}
	cout<<endll;
	
	return 0;
	
}
