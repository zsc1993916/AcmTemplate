/*KMP总结：
重点是构建状态图。失配边表示当在某个状态匹配失败时，状态转移的方向。
匹配过程的复杂度为O(n)
状态图构建时实际上就是自己匹配自己复杂度为O(m);
所以KMP的总复杂度为O(n+m); */
void get_next(char *a,int len){        //构建状态图
  int i=0,j=-1;
	next[0]=-1;
	while(i<len){
		if(j==-1 || a[i]==a[j]){
			i++; j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
int kmp(char *p, char *t){         //检查模式串p在主串t中是否存在
	int i=0,j=0;
	int lenp=strlen(p), lent=strlen(t);
	get_next(p,lenp);
	while(i<lent){
		  if(j==-1|| t[i]==p[j]) {
			   i++; j++;
			   if(j==lenp)
				   return 1;
		  }
		   else j=next[j];
	 }
	return 0;
}
/*
******最小表示法 ***********

可用于判断字符串的循环同构。O（n）的复杂度。最小表示法 求出字符串所有循环同构中字典序最小的字符串的起点位置。
例如 helloworld 的最小表示法为 dhelloworl 。所以起点为10
*/
iint minSub(char * a )             //返回字符串a的最小表示法的起点
{
	int i=0,j=1,len=strlen(a),k=0;
	while(i<len && j<len &&k< len)
	{
		if(k==len) break;
		if(i==j) j++;
		int ni=i+k , nj=j+k;
		if(ni>=len) ni-=len;
		if(nj>=len) nj-=len;
		if(a[ni] > a[nj]) { i+=k+1; k=0; }
		else if(a[ni] < a[nj]) { j+=k+1; k=0; }
		else 	k++;
	}
	return i;
}
