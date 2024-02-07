#define NULL __null

template <class T>
class list final {
 private:
  list<T>*next = NULL, *previous = NULL;
  T data;

 public:
  list() {}
  list(T _data) { data = _data; }
  ~list() {}
  list<T> insert(T _data) {
    if (!next) {
      next = new list<T>(_data);
      return *this;
    }
    list<T>* current = next;
    list<T>* previous = this;
    while (current) {
      if (current->data >= _data) {
        previous->next = new list<T>(_data);
        previous->next->next = current;
        return *this;
      }
      previous = current;
      current = current->next;
    }
    previous->next = new list<T>(_data);
    return *this;
  }

  list<T> remove(T _data) {
    list<T>* current = this->next;
    list<T>* previous = this;
    while (current) {
      if (current->data == _data) {
        previous->next = current->next;
        delete current;
        break;
      }
      previous = current;
      current = current->next;
    }
    return *this;
  }

  list<T> find(T _data) {
    list<T>* current = this->next;
    if (current->data == _data) {
      return *current;
    }
    while (current) {
      if (current->data == _data) {
        return *current;
      }
      current = current->next;
    }
    return *this;
  }

  list<T> operator[](int index) {
    list<T>* current = this->next;
    for (int i = 0; i < index; i++) {
      if (current->next) {
        current = current->next;
      } else {
        return *this;
      }
    }
    return *current;
  }
};