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

