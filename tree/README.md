# Usage

```cpp
#include <iostream>
#include "./src/tree.hh"
using namespace std;

int main()
{
    // Creates a tree where the nodes are strings
    tree<string> t;

    // Add values to t
    t.insert("oradea");
    t.insert("sibiu");
    t.insert("zerind");

    return 0;
}
```
