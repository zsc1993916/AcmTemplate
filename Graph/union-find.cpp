/*
并查集，加了路径压缩和合并时小树并到大树优化
*/

int fa[N], rank[N];

int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) fa[y] = x;
    else{
        if (rank[x] == rank[y]) rank[y]++;
        fa[x] = y;
    }
}
