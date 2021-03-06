/**
 * @file Tree.hpp
 * @author Oziel Ferreira (https://github.com/ozielfrs)
 * @brief Tree class.
 * @version 0.1.1
 * @date 2022-07-17
 *
 * @copyright Copyright (c) 2022
 * ! Do not copy or distribute.
 * * Or, if you do, at least let my credits on it. ;)
 */

#define NULL __null

#include <stdexcept>

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
   * @brief Inserts a data in the left branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param val The data to be stored in the left branch.
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
   * @brief Inserts a data in the right branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param val The data to be stored in the right branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  Tree<T> &insertInR(T val = T()) {
    if (!R) R = new Tree<T>(val);
    return *this;
  }

  /**
   * @brief Removes the left branch if it contains a Tree<T> object.
   *
   * @return Tree<T>& Tree with the branch removed.
   */
  Tree<T> &removeInL() {
    if (L) L = NULL;
    return *this;
  }
  /**
   * @brief Removes the right branch if it contains a Tree object.
   *
   * @return Tree<T>& Tree with the branch removed.
   */
  Tree<T> &removeInR() {
    if (R) R = NULL;
    return *this;
  }
  /**
   * @brief Removes the left or right branch if the parameter data is found in
   * one of them.
   * NOTE: If the data isn't found in any branch it returns the self Tree.
   *
   * @param val Data to be removed.
   * @return Tree<T>& Tree with the branch removed.
   */
  Tree<T> &removeTBranch(T val = T()) {
    if (R)
      if (R->data == val) removeInR();
    if (L)
      if (L->data == val) removeInL();
    return *this;
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
   * @param val Data.
   */
  Tree<T>(T val) { data = val; }

  /**
   * @brief Construct a new Tree< T> object
   *
   * @param source Source data.
   */
  Tree<T>(const Tree<T> &source) {
    data = source.data;
    L = source.L;
    R = source.R;
  }
  /**
   * @brief Destroy the Tree object
   *
   */
  ~Tree<T>() {}

  /**
   * @brief Operator overload for comparisons.
   *
   * @param rvalue Tree to be compared with.
   * @return true The Trees are the same.
   */
  bool operator==(const Tree<T> rvalue) {
    return (data == rvalue.data && L == rvalue.L && R == rvalue.R);
  }
  /**
   * @brief Operator overload for validation.
   * NOTE: A Tree different from default constructor is a valid Tree.
   *
   * @return true If the Tree isn't valid.
   */
  bool operator!() { return (*this == Tree<T>(T())); }

  /**
   * @brief Inserts a data in the Tree following the principles of a Binary
   * Search Tree.
   * NOTE: If the data is in the Tree it isn't inserted again.
   *
   * @param val data wanted to be stored.
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
   * NOTE: If the branch data is in the Tree it isn't inserted.
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
   * @brief Finds a data.
   * NOTE: If the data is not found it returns an empty Tree.
   *
   * @param val Wanted data.
   * @return Tree<T>& Branch where the data was found.
   */
  Tree<T> &find(T val = T()) {
    if (val < data) return (L ? L->find(val) : *(new Tree<T>(T())));
    if (val > data) return (R ? R->find(val) : *(new Tree<T>(T())));
    return *this;
  }
  /**
   * @brief Finds the parent Tree of a data.
   * NOTE: If the data is not found it returns an empty Tree.
   *
   * @param val Wanted data.
   * @return Tree<T>& Parent branch where the data was found.
   */
  Tree<T> &findParent(T val = T()) {
    if (L || R) {
      if (L)
        if (L->data == val) return *this;
      if (R)
        if (R->data == val) return *this;
    }
    if (val < data)
      if (L) return L->findParent(val);
    if (val > data)
      if (R) return R->findParent(val);
    return *(new Tree<T>(T()));
  }

  /**
   * @brief Removes a data from the Tree.
   * NOTE:If the data isn't in the Tree it returns the self Tree.This method
   * will self balance the Tree object.
   *
   * @param val Data to remove.
   * @return Tree<T>& Tree with data removed.
   */
  Tree<T> &remove(T val = T()) {
    Tree<T> *temp = &findParent(val), *_temp;
    bool valOnLeft = bool();
    if (temp->L || temp->R) {
      if (temp->L)
        if (temp->L->data == val) {
          _temp = temp->L;
          valOnLeft = true;
        }
      if (temp->R)
        if (temp->R->data == val) {
          _temp = temp->R;
          valOnLeft = false;
        }
    } else
      return *this;

    if (!_temp->L && !_temp->R)
      temp->removeTBranch(val);
    else if (!_temp->L)
      (valOnLeft ? temp->L = _temp->R : temp->R = _temp->R);
    else if (!_temp->R)
      (valOnLeft ? temp->L = _temp->L : temp->R = _temp->L);
    else {
      Tree<T> *_temp0 = _temp->R;
      while (_temp0->L) _temp0 = _temp0->L;
      _temp->data = _temp0->data;
      return _temp->R->remove(_temp0->data);
    }

    return *this;
  }

  /**
   * @brief Returns data of the left branch.
   * NOTE: If there isn't a data it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContentOnLeft() { return (L ? L->data : T()); }
  /**
   * @brief Returns data of the right branch.
   * NOTE: If there isn't a data it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContentOnRight() { return (R ? R->data : T()); }
  /**
   * @brief Returns data of the self branch.
   * NOTE: If there isn't a data it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContent() { return data; }
};