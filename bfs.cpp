#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	vector<int> v[100005];
	int visited[100005];
	for(int i=0;i<100005;i++)
	{
		v[i].clear();
		visited[i] = -1;
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
	int count =0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i] == -1)
		{
			count++;
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				int s = v[u].size();
				for(int j=0;j<s;j++)
				{
					int w = v[u][j];
					if(visited[w] == -1)
					{
						visited[w] = 1;
						q.push(w);
					}
				}
			}
		}
	}
	cout<<"The number of connected component in the graph is: "<<count<<endl;
	
	return 0;
	
}
