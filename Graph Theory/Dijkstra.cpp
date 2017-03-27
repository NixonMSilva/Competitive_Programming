/* Dijkstra Algorithm

	Applications: Calculation of the shortest distance between a node u and all other v nodes.
	
	Usage: Pass s as the node u. The shortest distance between (u, v) is stored on dist[v];
	
	Reference: Competitive Programming 3rd Ed.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define maxn 1005

using namespace std;

int dist[maxn];
vector< pair<int, int> >g[maxn];   // Adjacency list: first = vertex, second = edge cost;

void dijkstra (int s)
{
	memset(dist, INF, sizeof dist);
	dist[s] = 0;
	priority_queue< pair<int, int> >pq;
	pq.push(make_pair(-dist[s], s));
	int x, y, d;
	while(!pq.empty())
	{
		x = pq.top().second; d = -pq.top().first;
		pq.pop();
		if (d > dist[x]) continue;
		for (int i = 0; i < g[x].size(); ++i)
		{
			int custo;
			y = g[x][i].first;
			custo = g[x][i].second;
			if (d + custo < dist[y])
			{
				dist[y] = d + custo;
				pq.push(make_pair(-dist[y], y));
			}
		}
	}
}

