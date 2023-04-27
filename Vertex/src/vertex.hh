#ifndef VERTEX_H
#define VERTEX_H

template <typename T>
class Vertex
{
public:
    T id;
    std::unordered_map<Vertex<T> *, std::set<double>> adjList;

    Vertex<T>(T id) : id{id} {}
};

#endif