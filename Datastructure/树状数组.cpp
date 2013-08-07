// 树状数组  动态 求前缀和
void add(int k){
    while(k < M){
        x[k] ++;
        k += lowbit[k];
    }
}
int sum(int k){
    int res = 0;
    while(k > 0){
        res += x[k];
        k -= lowbit[k];
    }
    return res;
}
