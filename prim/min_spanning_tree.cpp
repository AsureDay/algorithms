#include "min_spanning_tree.h"

using namespace std;


int get_v_with_min_weight(list<int>& verts, map<int, double>& dist)
{
	double min = dist[verts.front()];
	auto iter = verts.begin();
	for (auto i = verts.begin(); i != verts.end(); ++i)
	{
		if (dist[*i] < min)
		{
			min = dist[*i];
			iter = i;
		}
	}
	int v_min = *iter;
	verts.remove(*iter);
	return v_min;
}
vector<pair<int, int>> min_spanning_tree(const Graph& graph) {
	
	vector<int> vert_vec = graph.get_vertices();

	if (vert_vec.size() < 2)
		return vector<pair<int, int>> {};

	map<int, double> minWeight;
	list<int> Q;
	int s = vert_vec.front();
	for (auto v = vert_vec.begin(); v != vert_vec.end(); ++v)
	{
		minWeight[*v] = DBL_MAX;
		Q.push_back(*v);
	}
	minWeight[s] = 0;
	

	map<int, int> parent;
	while (Q.size() != 0)
	{
		int u = get_v_with_min_weight(Q, minWeight);
		auto adj_verts = graph.get_adjacent_edges(u);
		for (auto v = adj_verts.begin(); v != adj_verts.end(); ++v)
		{
			double uv_dist = graph.edge_weight(u, (*v).first);
			if( (find(Q.begin(),Q.end(),(*v).first) != Q.end()) && minWeight[(*v).first] > (*v).second)
			{
				minWeight[(*v).first] = (*v).second;
				parent[(*v).first] = u;
			}
		}
	}
	vector<pair<int,int>> MST;
	for (auto v =  ++vert_vec.begin(); v != vert_vec.end(); ++v)
	{
		MST.push_back(make_pair(*v, parent[*v]));
	}
	return MST;
}