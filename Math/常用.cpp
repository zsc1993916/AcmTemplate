/*
素数筛法  O(n)
*/
bool isPrime[N] ; //数组定义该数字是否为素数
int prime[N] ; // 存下素数
int tot = 0 ; //第几个素数

void seive(){
        memset( isPrime, 1, sizeof(isPrime));
        memset( prime , 0, sizeof(prime));
        isPrime[0] = 0;
        isPrime[1] = 1;
        for ( int i=2 ; i<=N; i++) {
          if (isPrime[i]) prime[++total] = i ;
          for(int j=1 ; j<=total && i*prime[j]<=Max; j++){
              isPrime[i*prime[j]] = 0;
              if (!(i%prime[j])) break;
            }
        }
}
/*
反素数就是满足对于任意i(0<i<x),都有g(i)<g(x),(g(x)是x的因子个数),则x为一个反素数
*/
const int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,  
                       7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,  
                       166320,221760,277200,332640,498960,554400,665280};  
