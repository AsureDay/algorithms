#include "shortest_path.h"

using namespace std;

vector<int> build_path(map<int, int> parent, int start, int end)
{
    list<int> res;
    int pred = end;
    while (pred != start)
    {
        std::map<int, int>::iterator elem = parent.find(pred);
    	if(elem == parent.end())
    	{
            return vector<int>{};
    	}
        res.push_back(pred);
        pred = (*elem).second;
    }
    res.push_back(start);
    vector<int> result(res.size());
	for(auto i = result.begin();i != result.end();++i)
	{
        *i = res.back();
        res.pop_back();
	}
    return result;
}

int get_v_with_min_dist(list<int>& verts,map<int,double>& dist)
{
    double min = dist[verts.front()];
    auto iter = verts.begin();
	for(auto i = verts.begin();i != verts.end();++i)
	{
		if(dist[*i] < min)
		{
            min = dist[*i];
            iter = i;
		}
	}
    int v_min = *iter;
    verts.remove(*iter);
    return v_min;
}
vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex) {
    // Return shortest path in the graph from start vertex to end vertex as array of vertices.
    // First item in the result should be start vertex, last - end vertex.
    // Return empty array if there is no path.
    if (end_vertex == start_vertex) return vector<int> {};
	vector<int> vert_vec = graph.get_vertices();
    map<int, double> distance;
    map<int, int> parent;
    list<int> Q;
	for(auto i = vert_vec.begin();i != vert_vec.end();++i)
	{
        distance[*i] = DBL_MAX;
        Q.push_back(*i);
	}
    vert_vec.clear();
    distance[start_vertex] = 0;

    while (Q.size() != 0)
    {
        int u = get_v_with_min_dist(Q,distance);
        if (u == end_vertex) {
            return build_path(parent, start_vertex, end_vertex);
        }
    	
    	auto adj_verts = graph.get_adjacent_edges(u);
    	for(auto i = adj_verts.begin(); i != adj_verts.end();++i)
    	{
            double uv_dist = graph.edge_weight(u, (*i).first);

    		if( distance[(*i).first] > distance[u] + uv_dist)
    		{
                distance[(*i).first] = distance[u] + uv_dist;
                parent[(*i).first] = u;
    		}
    	}
    }
    return vector<int> {};
}
