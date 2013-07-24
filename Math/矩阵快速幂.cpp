/* 矩阵快速幂，矩阵最大为N*N,小心中间溢出
  size 矩阵边长   MOD 模  */
struct Matrix{
    int a[N][N];
    //乘法重载
 Matrix operator * (const Matrix &b) const{
		Matrix res;
		for (int i=0; i<size; i++)
			for (int j=0; j<size; j++) {
				res.a[i][j]=0;
				for (int k=0; k<size; k++){
					res.a[i][j]+= (a[i][k] * b.a[k][j])%MOD;
					res.a[i][j]%=MOD;
				}
			}
		return res;
	}
	Matrix matrix_pow(int n){  //矩阵快速幂 a^n
		Matrix res,x;
		for (int i=0; i<size; i++){
			for (int j=0; j<size; j++)
				res.a[i][j]=0, x.a[i][j]=a[i][j];
			res.a[i][i] = 1;
		}
		for(; n; n>>=1,x=x*x)
			if(n&1) res=res*x;
		return res;
	}
};
