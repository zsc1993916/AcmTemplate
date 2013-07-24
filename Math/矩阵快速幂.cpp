/*
 矩阵快速幂，矩阵大小为N*N
 小心溢出
*/
class Matrix {   
public:
    int m[N][N]; //二维数组存放矩阵
    Matrix(){}  //对数组的初始化
    void init(int num[N][N]){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                m[i][j] = num[i][j];
    }
    //重载矩阵的乘法运算
    friend Matrix operator*(Matrix &m1 ,Matrix &m2) {
        int i,j,k;
        Matrix t;
        for (i=0;i<N; i++) {
            for (j=0; j<N;j++) {
                t.m[i][j]=0;
                for(k=0;k<N;k++)
                    t.m[i][j]+=(m1.m[i][k]* m2.m[k][j])%MOD;
                t.m[i][j]%=MOD;
           }
        }
        return t;
    }
    //矩阵的快速幂
    friend Matrix quickpow(Matrix &M , int n){  //M是底数 返回M^n
        Matrix ans;
        for(int i=0;i<N;i++)  //初始化为单位矩阵
            for(int j=0;j<N;j++)
                    ans.m[i][j]= (i==j);
        //快速幂
        while(n){
            if(n&1)  ans=ans*M;
            n>>=1;
            M=M*M;
        }
       return ans;
    }
};
