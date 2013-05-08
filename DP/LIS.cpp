// 最长不降序列
int g[5005];  //g[i]表示序列长度为i的最长不降序列的最小尾点
int f(int n,int num)
{
	int l=1,r=n,m;
	while(r>l){
		m=l+(r-l)/2;
		if(g[m]>=num) r=m;  //改为>最长严格上升
		else l=m+1;
	}
	return r;
}
int LIS(int n,int *m){  //m数组的最长不降序列的长度
    int i,ans=-1;
    for(i=1;i<=n;i++) g[i]=INF;
    for(i=0;i<n;i++){
        int k=f(n,m[i]);
        if(k>ans) ans=k;
        g[k]=m[i];
    }
    return ans;
}
