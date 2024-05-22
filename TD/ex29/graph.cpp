#include "graph.h"

Graph::Graph(const string& n, size_t nb){
    name = n;
    vector<list<unsigned int>> adjacence(nb, list<unsigned int>(0));
    adj = adjacence;
}

size_t Graph::getNbEdges() const{
    size_t out = 0;
    unsigned int len = adj.size();
    for (unsigned int i = 0; i < len; i++)
    {
        out += adj[i].size();
    }
    return out/2;
}

void Graph::addEdge(unsigned int i, unsigned int j){
    adj[i].push_back(j);
}

void Graph::removeEdge(unsigned int i, unsigned int j){
    adj[i].remove(j);
}

const list<unsigned int>& Graph::getSuccessors(unsigned int i) const{
    return adj[i];
}

const list<unsigned int> Graph::getPredecessors(unsigned int i) const{
    list<unsigned int> out;
    unsigned int len = adj.size();
    for (unsigned int j = 0; j < len; j++)
    {
        for (auto it = adj[j].begin(); it != adj[j].end(); it++)
        {
            if (*it == i)
            {
                out.push_back(j);
            }
        }
    }
    return out;
}

ostream& operator<<(ostream& f, const Graph& G){
    f << G.getName()
    return f;
}