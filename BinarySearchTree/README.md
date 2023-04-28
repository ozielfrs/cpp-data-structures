# Usage

```cpp
#include <iostream>
#include "./tree.hh"
using namespace std;

int main()
{
    // Creates a tree where the vertices are strings
    Tree<string> tree;

    // Adds branches to the tree
    tree.insert("oradea");
    tree.insert("sibiu");
    tree.insert("zerind");

    return 0;
}
```
