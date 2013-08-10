// 树状数组  动态 求前缀和

#define lowbit(a) (a&(-a))

void add(int k, int ad) {
    for(; k<=n; k += lowbit(k))
        tr[k] += ad;
}

LL sum(int k) {
    LL res = 0;
    for(; k>0; k -= lowbit(k))
        res += tr[k];
    return res;
}
