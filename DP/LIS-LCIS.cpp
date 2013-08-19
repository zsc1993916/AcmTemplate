/*
最长上升子序列   O(n*log(n));
*/int g[5005];  //g[i]表示序列长度为i的最长不降序列的最小尾点
int f(int n,int num)
{
	int l=1,r=n,m;
	while(r>l){
		m=l+(r-l)/2;
		if(g[m]>=num) r=m; //改为>严格递增
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


/*
最长公共上升子序列 O(n^2)
a序列从左往右遍历
dp[i] 表示以b[i]结尾的序列的LCIS
必须二维纪录路径
*/
int f[N][N], dp[N];
int LCIS(int a[], int la, int b[], int lb, int ans[])
{   // a,b 序列下标从0开始
    int i, j, k, mx;
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= la; i++) {
        memcpy(f[i], f[i-1], sizeof(f[0]));
        for (k = 0, j = 1; j <= lb; j++) {
            if (b[j-1] < a[i-1] && dp[j] > dp[k]) k = j;
            if (b[j-1] == a[i-1] && dp[k] + 1 > dp[j]) {
                dp[j] = dp[k] + 1,
                f[i][j] = i * (lb + 1) + k;
            }
        }
    }
    for (mx = 0, i = 1; i <= lb; i++)
        if (dp[i] > dp[mx]) mx = i;
    for(i=la*lb+la+mx, j=dp[mx]; j;
        i=f[i/(lb+1)][i%(lb+1)],j--)
        ans[j-1] = b[i % (lb + 1) - 1];
    return dp[mx];
}
