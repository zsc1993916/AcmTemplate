/*
筛素数 O(n)
*/
const int N=100;
bool isPrime[N] ; //数组定义该数字是否为素数
int prime[N] ; // 存下素数
int total = 0 ; //第几个素数

void seive(){
        memset( isPrime , true , sizeof( isPrime ));
        memset( prime , 0 , sizeof( prime ));
        isPrime[0 ] = false ;
        isPrime[1] = false ;
        for ( int i = 2 ; i <= N ; i++ ){
              if ( isPrime[i] )  prime[ ++ total ] = i ;
              for ( int j = 1 ; j <= total && i * prime[j] <= N ; j++) {
                  isPrime[ i * prime[j] ] = false ;
                  if (!( i % prime[j])) break;
              }
        }
}




/*
反素数就是满足对于任意i(0<i<x),都有g(i)<g(x),(g(x)是x的因子个数),则x为一个反素数
*/
const int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,  
                       7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,  
                       166320,221760,277200,332640,498960,554400,665280,720720,1081080};
/*
下面是反素数表打印的代码
*/
LL bestNum;   //约数最多的数
LL bestSum;   //约数最多的数的约数数
const int M=1000; //反素数的个数
LL Maxn=1000000;//  求n以内的 所有反素数
LL rprim[M][2];     // rprim 代表反素数
LL prim[]={2,3,5,7,11,13,17,19,23,29,31,33,37};
void getNum(LL num,LL k,LL sum,LL limit)  {
     if(num>Maxn)return;
     if(sum>bestSum)
         bestSum = sum, bestNum = num;
     else if(sum == bestSum && num < bestNum)
         bestNum = num;
     if(k>=9) return;
     for(LL i=1,p=1;i<=limit;i++){
         p*=prim[k];
         getNum(num*p,k+1,sum*(i+1),i);
     }
}
LL log2(LL n){   //求大于等于log2（n）的最小整数
     LL i = 0, p = 1;
     while(p<n) p*=2, i++;
     return i;
}
int getrprim(){//反素数的个数
     int i = 0;
     while(Maxn>0){
         bestNum = 1, bestSum = 1;
         getNum(1,0,1,log2(Maxn));
         Maxn = bestNum - 1;
         rprim[i][0]=bestNum;
         rprim[i][1]=bestSum;
         i++;
     }
     return i;
}
int main(){
    int tot = getrprim();
    printf("%d\n",tot);
    for(int i=tot-1; i>=0; i--) printf("%d : %I64d %I64d\n", i, rprim[i][0], rprim[i][1] );
    return 0;
}

