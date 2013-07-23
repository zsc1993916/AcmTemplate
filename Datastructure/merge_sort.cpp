// tot为数组a[]区间[x,y)逆序数对数
void merge_sort(int x,int y)
{
  int mid=x+(y-x)/2;
  if(y-x>1){
		merge_sort(x,mid);
		merge_sort(mid,y);
		int p=x,q=mid,i=x;
		while(p<mid||q<y){
			if(q>=y||(p<mid&&a[p]<=a[q]))
				t[i++]=a[p++]; 
			else{ t[i++]=a[q++]; tot+=mid-p; }
		}
		for(i=x;i<y;i++) a[i]=t[i];
	}
}
