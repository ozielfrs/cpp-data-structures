/**
 * @file Tree.hpp
 * @author Oziel Ferreira (https://github.com/ozielfrs)
 * @brief Tree class.
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 * ! Do not copy or distribute.
 */

#define NULL __null

#pragma once
/**
 * @brief A Tree of any class of data.
 *
 * @tparam T Class of data.
 */
template <class T>
class Tree {
 private:
  Tree<T> *L = NULL, *R = NULL;
  T data;

  /**
   * @brief Inserts a source Tree in the left branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param source The data to be stored in the left branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  Tree<T> &insertInL(Tree<T> source = Tree<T>(T())) {
    if (!L) L = new Tree<T>(source);
    return *this;
  }
  /**
   * @brief Inserts a value in the left branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param val The value to be stored in the left branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  Tree<T> &insertInL(T val = T()) {
    if (!L) L = new Tree<T>(val);
    return *this;
  }

  /**
   * @brief Inserts a source Tree in the right branch.
   *
   * NOTE: If the branch is already in use, the insertion isn't done.
   * @param source The data to be stored in the right branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  Tree<T> &insertInR(Tree<T> source = Tree<T>(T())) {
    if (!R) R = new Tree<T>(source);
    return *this;
  }
  /**
   * @brief Inserts a value in the right branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param val The value to be stored in the right branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  Tree<T> &insertInR(T val = T()) {
    if (!R) R = new Tree<T>(val);
    return *this;
  }

  /**
   * @brief Finds a value.
   * NOTE: If the value is not found it returns an empty Tree.
   *
   * @param val Wanted value.
   * @return Tree<T>* Branch where the value was found.
   */
  Tree<T> *findBranch(T val = T()) {
    if (val < data) return (L ? L->findBranch(val) : new Tree<T>(T()));
    if (val > data) return (R ? R->findBranch(val) : new Tree<T>(T()));
    return this;
  }
  /**
   * @brief Finds the parent Tree of a value.
   * NOTE: If the value is not found it returns an empty Tree.
   *
   * @param val Wanted value.
   * @return Tree<T>* Parent branch where the value was found.
   */
  Tree<T> *findParentBranch(T val = T()) {
    if (L || R) {
      if (L)
        if (L->data == val) return this;
      if (R)
        if (R->data == val) return this;
    }
    if (val < data)
      if (L) return L->findParentBranch(val);
    if (val > data)
      if (R) return R->findParentBranch(val);
    return new Tree<T>(T());
  }

 public:
  /**
   * @brief Construct a new Tree< T> object
   *
   */
  Tree<T>() { data = T(); }
  /**
   * @brief Construct a new Tree< T> object
   *
   * @param val Data value.
   */
  Tree<T>(T val) { data = val; }
  /**
   * @brief Construct a new Tree< T> object
   *
   * @param source Data value.
   */
  Tree<T>(const Tree<T> &source) {
    data = source.data;
    L = source.L;
    R = source.R;
  }
  ~Tree<T>() {}

  /**
   * @brief Inserts a value in the Tree following the principles of a Binary
   * Search Tree.
   * NOTE: If the value is in the Tree it isn't inserted again.
   *
   * @param val Value wanted to be stored.
   * @return Tree<T>& The self Tree.
   */
  Tree<T> &insert(T val = T()) {
    if (val < data) (L ? L->insert(val) : insertInL(val));
    if (val > data) (R ? R->insert(val) : insertInR(val));
    return *this;
  }
  /**
   * @brief Inserts a branch in the Tree following the principles of a Binary
   * Search Tree.
   * NOTE: If the branch data value is in the Tree it isn't inserted.
   *
   * @param source Branch wanted to be stored.
   * @return Tree<T>& The self Tree.
   */
  Tree<T> &insert(Tree<T> source = Tree<T>(T())) {
    if (source.data < data) (L ? L->insert(source) : insertInL(source));
    if (source.data > data) (R ? R->insert(source) : insertInR(source));
    return *this;
  }

  /**
   * @brief Finds a value.
   * NOTE: If the value is not found it returns an empty Tree.
   *
   * @param val Wanted value.
   * @return Tree<T>& Branch where the value was found.
   */
  Tree<T> &find(T val = T()) { return *findBranch(val); }
  /**
   * @brief Finds the parent Tree of a value.
   * NOTE: If the value is not found it returns an empty Tree.
   *
   * @param val Wanted value.
   * @return Tree<T>& Parent branch where the value was found.
   */
  Tree<T> &findParent(T val = T()) { return *findParentBranch(); }

  /**
   * @brief Returns data of the left branch.
   * NOTE: If there isn't a value it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContentOnLeft() { return (L ? L->data : T()); }
  /**
   * @brief Returns data of the right branch.
   * NOTE: If there isn't a value it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContentOnRight() { return (R ? R->data : T()); }
  /**
   * @brief Returns data of the self branch.
   * NOTE: If there isn't a value it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContent() { return data; }
};