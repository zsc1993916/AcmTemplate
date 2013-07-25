/* 划分树求区间K大数  询问log(n)
每次二分，左子树中所有数小于右子树
记录进入左子树的个数，可以判断k大数在下一层的位置  */
int tr[20][N],lsum[20][N],sor[N];  //lsum[i]为第i个数之前分到左子树的个数
void build(int l, int r, int c) {        //c是层数
    if(l==r) return;
    int mid=(l+r)>>1;
    int cl=l, cr=mid+1, i, num= 0;
    for(i=mid; i>=l; i--)
        if(sor[i]== sor[mid]) num++;
    for(i=l; i<=r; i++) {
        if(i==l) lsum[c][i]=0;
        else lsum[c][i]=lsum[c][i-1];
        if(tr[c][i]<sor[mid] || (num&&tr[c][i]==sor[mid])) {
            tr[c+1][cl++]=tr[c][i];
            lsum[c][i]++;
            if(tr[c][i]==sor[mid]) num--;
        }
        else tr[c+1][cr++]=tr[c][i];
    }
    build(l,mid,c+1);
    build(mid+1,r,c+1);
}
int query(int l,int r,int ql,int qr,int k,int c) {      //l,r为总区间，ql，qr为要求区间，k大数
    if(ql==qr) return tr[c][qr];
    int mid=(l+r)>>1, ll,tol, lst,led,rst,red;
    if(ql==l) ll=0;
    else ll=lsum[c][ql-1];
    tol=lsum[c][qr]-ll;
    lst=l+ll;
    led=l+lsum[c][qr]-1;
    rst=mid+(ql-l-ll+1);
    red=mid+(qr-l+1-lsum[c][qr]);
    if(tol>=k) return query(l,mid,lst,led,k,c+1);
    else   return query(mid+1,r,rst,red,k-tol,c+1);
}
