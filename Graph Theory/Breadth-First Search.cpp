/* Breadth-First Search (BFS)

	Applications: Transverse the graph starting at the node u, prioritizing its width rather than its depth
	
	Usage: Pass the node x as u to begin the transversal.
	
	Reference: Competitive Programming 3rd Ed.
	
	Obs.: Change MAXN during application accordingly

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAXN 10005

using namespace std;

vector<int> graph[MAXN];
bool vis[MAXN];

void bfs (int x)
{
	vis[x] = true;
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size(); ++i)
		{
			int y = graph[v][i];
			if (!vis[y])
			{
				q.push(y);
				vis[y] = true;
			}
		}
	}
}