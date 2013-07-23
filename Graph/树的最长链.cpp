/*
树形DP 求树的最长链
结果保存在lon中
*/

struct edge{
    int u,v,w;
}e[N*2];
int first[N],next[N*2],vis[N],lon,mt;

void adde(int a,int b,int c) {   //邻接表 c为权值
    e[mt].u=a; e[mt].v=b; e[mt].w=c;
    next[mt]=first[a]; first[a]=mt++;
}
void init(int n){
    memset(first,-1,sizeof(first));
    memset(vis,0,sizeof(vis));
    mt=0;
    lon=0;
}
int l_lian(int s) {   //lon为树的最长链，函数返回该节点下的最长支 
    int i,re,m1=0,m2=0;
    for(i=first[s];i!=-1;i=next[i]) {
        if(!vis[e[i].v]){
            vis[e[i].v]=1;
            re=l_lian(e[i].v)+e[i].w;
            if(re>m2) m2=re;
            if(m2>m1) m2^=m1^=m2^=m1;
            if(m1+m2>lon) lon=m1+m2;
        }
    }
    return m1;
}

