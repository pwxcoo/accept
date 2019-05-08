## Eulerian Path

### Concept

- 欧拉路径：如果图G中的一个路径包括每个边恰好一次，则该路径称为欧拉路径(Euler path)。
- 欧拉回路：如果一个回路是欧拉路径，则称为欧拉回路(Euler circuit)。
- 欧拉图：具有欧拉回路的图称为欧拉图。
- 半欧拉图：具有欧拉路径但不具有欧拉回路的图称为半欧拉图。


### Properties

#### Euler Cycle

A necessary and sufficient condition:

- Undirected Graph
    1. if and only if every vertex has even degree
    2. all of its vertices with nonzero degree belong to a single connected component
- Directed Graph
    1. if and only if every vertex has equal in degree and out degree
    2. all of its vertices with nonzero degree belong to a single connected component

#### Euler Path

A necessary and sufficient condition:

- Undirected Graph
    1. if and only if exactly zero or two vertices have odd degree
    2. all of its vertices with nonzero degree belong to a single connected component
- Directed Graph
    1.  if and only if at most one vertex has `(out-degree) − (in-degree) = 1`, at most one vertex has `(in-degree) − (out-degree) = 1`, every other vertex has equal in-degree and out-degree,
    2. all of its vertices with nonzero degree belong to a single connected component