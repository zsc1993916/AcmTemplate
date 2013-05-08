// ���������
int g[5005];  //g[i]��ʾ���г���Ϊi����������е���Сβ��
int f(int n,int num)
{
	int l=1,r=n,m;
	while(r>l){
		m=l+(r-l)/2;
		if(g[m]>=num) r=m;  //��Ϊ>��ϸ�����
		else l=m+1;
	}
	return r;
}
int LIS(int n,int *m){  //m�������������еĳ���
    int i,ans=-1;
    for(i=1;i<=n;i++) g[i]=INF;
    for(i=0;i<n;i++){
        int k=f(n,m[i]);
        if(k>ans) ans=k;
        g[k]=m[i];
    }
    return ans;
}
