#ifndef VERTEX_H
#define VERTEX_H

#include <set>
#include <unordered_map>

/**
 * @brief A vertex with identifier of any type.
 *
 * @tparam T Type of the identifier.
 */
template <typename T>
class vertex {
 public:
  T id;
  std::unordered_map<vertex<T> *, std::set<double>> adjList;

  /**
   * @brief Construct a new Vertex< T> object
   *
   * @param id Identifier of type T.
   */
  vertex<T>(T id) : id{id} {}
};

#endif