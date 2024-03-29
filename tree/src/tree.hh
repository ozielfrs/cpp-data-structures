#define NULL __null

#pragma once
/**
 * @brief A Tree of any class of data.
 *
 * @tparam T Class of data.
 */
template <class T>
class tree final {
 private:
  tree<T> *L = NULL, *R = NULL;
  T data;

  /**
   * @brief Inserts a source Tree in the left branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param source The data to be stored in the left branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  tree<T> &insertInL(tree<T> source = tree<T>(T())) {
    if (!L) L = new tree<T>(source);
    return *this;
  }
  /**
   * @brief Inserts a data in the left branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param val The data to be stored in the left branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  tree<T> &insertInL(T val = T()) {
    if (!L) L = new tree<T>(val);
    return *this;
  }

  /**
   * @brief Inserts a source Tree in the right branch.
   *
   * NOTE: If the branch is already in use, the insertion isn't done.
   * @param source The data to be stored in the right branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  tree<T> &insertInR(tree<T> source = tree<T>(T())) {
    if (!R) R = new tree<T>(source);
    return *this;
  }
  /**
   * @brief Inserts a data in the right branch.
   * NOTE: If the branch is already in use, the insertion isn't done.
   *
   * @param val The data to be stored in the right branch.
   * @return Tree<T>& Parent of inserted branch.
   */
  tree<T> &insertInR(T val = T()) {
    if (!R) R = new tree<T>(val);
    return *this;
  }

  /**
   * @brief Removes the left branch if it contains a Tree<T> object.
   *
   * @return Tree<T>& Tree with the branch removed.
   */
  tree<T> &removeInL() {
    if (L) delete L;
    return *this;
  }
  /**
   * @brief Removes the right branch if it contains a Tree object.
   *
   * @return Tree<T>& Tree with the branch removed.
   */
  tree<T> &removeInR() {
    if (R) delete R;
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
  tree<T> &removeTBranch(T val = T()) {
    if (R)
      if (R->data == val) removeInR();
    if (L)
      if (L->data == val) removeInL();
    return *this;
  }

 public:
  /**
   * @brief Construct a new Tree<T> object
   *
   */
  tree<T>() { data = T(); }
  /**
   * @brief Construct a new Tree<T> object
   *
   * @param val Data.
   */
  tree<T>(T val) { data = val; }

  /**
   * @brief Construct a new Tree<T> object
   *
   * @param source Source data.
   */
  tree<T>(const tree<T> &source) {
    data = source.data;
    L = source.L;
    R = source.R;
  }
  /**
   * @brief Destroy the Tree object
   *
   */
  ~tree<T>() {}

  /**
   * @brief Operator overload for comparisons.
   *
   * @param rval Tree to be compared with.
   * @return true The Trees are the same.
   */
  bool operator==(const tree<T> rval) {
    bool l(!L && !rval.L), r(!R && !rval.R);
    if (data == rval.data && r && l) {
      return true;
    } else if (data == rval.data) {
      if (!l && rval.L) l = (L->operator==(*rval.L));
      if (!r && rval.R) r = (R->operator==(*rval.R));
    }
    return l && r;
  }
  /**
   * @brief Operator overload for validation.
   * NOTE: A Tree different from default constructor is a valid Tree.
   *
   * @return true If the Tree isn't valid.
   */
  bool operator!() { return (*this == tree<T>(T())); }
  /**
   * @brief Operator overload for less or equal comparison.
   *
   * @return true If the Tree root is less or equal to the right Tree root.
   */
  bool operator<=(const tree<T> rval) { return (data <= rval.data); };
  /**
   * @brief Operator overload for greater comparison.
   *
   * @return true If the Tree root is greater to the right Tree root.
   */
  bool operator>(const tree<T> rval) { return (data > rval.data); };

  /**
   * @brief Inserts a data in the Tree following the principles of a Binary
   * Search Tree.
   * NOTE: If the data is in the Tree it isn't inserted again.
   *
   * @param val data wanted to be stored.
   * @return Tree<T>& The self Tree.
   */
  tree<T> &insert(T val = T()) {
    if (val <= data) (L ? L->insert(val) : insertInL(val));
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
  tree<T> &insert(tree<T> source = tree<T>(T())) {
    if (source.data <= data) (L ? L->insert(source) : insertInL(source));
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
  tree<T> &find(T val = T()) {
    if (val < data) return (L ? L->find(val) : NULL);
    if (val > data) return (R ? R->find(val) : NULL);
    return *this;
  }
  /**
   * @brief Finds the parent Tree of a data.
   * NOTE: If the data is not found it returns an empty Tree.
   *
   * @param val Wanted data.
   * @return Tree<T>& Parent branch where the data was found.
   */
  tree<T> &findParent(T val = T()) {
    if (L)
      if (L->data == val) return *this;
    if (R)
      if (R->data == val) return *this;

    if (val < data) return (L ? L->findParent(val) : NULL);
    if (val > data) return (R ? R->findParent(val) : NULL);
  }

  /**
   * @brief Removes a data from the Tree.
   * NOTE:If the data isn't in the Tree it returns the self Tree.This method
   * will self balance the Tree object.
   *
   * @param val Data to remove.
   * @return Tree<T>& Tree with data removed.
   */
  tree<T> &remove(T val = T()) {
    tree<T> *pT = &findParent(val), *t = &pT->find(val);
    if (t == tree<T>(T())) return *this;

    if (!t->L && !t->R)
      pT->removeTBranch(val);
    else if (!t->L && t->R) {
      t->L->R = t->R;
      t = t->L;
    } else if (!t->R && t->L) {
      t->R->L = t->L;
      t = t->R;
    } else {
      tree<T> *aT = t->R;
      while (aT->L) aT = aT->L;
      t->data = aT->data;
      return t->R->remove(aT->data);
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
  T returnContentOnLeft() { return (L ? L->data : NULL); }
  /**
   * @brief Returns data of the right branch.
   * NOTE: If there isn't a data it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContentOnRight() { return (R ? R->data : NULL); }
  /**
   * @brief Returns data of the self branch.
   * NOTE: If there isn't a data it returns the default constructor for the
   * class of data wanted.
   *
   * @return T
   */
  T returnContent() { return data; }
};