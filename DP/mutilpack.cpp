// f[n] 为背包容量为n时状态 
void zopack(int cost,int value,int V){  // V是总的容量
    for(int i=V;i>=cost;i--)
        f[i]=Max(f[i],f[i-cost]+value);
}
void compack(int cost,int value,int V){
    for(int i=cost;i<=V;i++)
        f[i]=Max(f[i],f[i-cost]+value);
}
void mutilpack(int cost,int value,int V,int num){
    if(cost*num>=V) {
        compack(cost,value,V); return;
    }
    int k=1;
    while(num>k){
        zopack(k*cost,k*value,V);
        num-=k;
        k<<=1;
    }
    zopack(num*cost,num*value,V);
}
