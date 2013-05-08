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
