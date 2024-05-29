#include "graph.h"

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
    if(i>=getNbVertices() || j>=getNbVertices())
        throw GraphException("addEdge: vertex out of range");
    if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end())
        throw GraphException("addEdge: edge already exists");
    adj[i].push_back(j);
}

void Graph::removeEdge(unsigned int i, unsigned int j){
    if(i>=getNbVertices() || j>=getNbVertices())
        throw GraphException("addEdge: vertex out of range");
    list<unsigned int>::iterator it = find(adj[i].begin(), adj[i].end(), j);
    if (it != adj[i].end()){
        adj[i].erase(it);
    }
    else throw "bad argument.";
}

const list<unsigned int>& Graph::getSuccessors(unsigned int i) const{
    if (i >= getNbVertices())
        throw GraphException("getSuccessors: vertex out of range");
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
    size_t len = G.getNbVertices();
    f << "graph " << G.getName() << " (" << G.getNbVertices() << " vertices and " << G.getNbEdges() << " edges)" << endl;
    for (size_t i = 0; i < len; i++)
    {
        f << i <<":";
        for (auto j = G.getSuccessors(i).begin(); j != G.getSuccessors(i).end(); j++)
        {
            f << *j << " ";
        }
        f << endl;
         
    }
    
    return f;
}