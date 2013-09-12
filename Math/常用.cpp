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
