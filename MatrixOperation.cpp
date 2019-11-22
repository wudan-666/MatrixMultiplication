void MatrixDefinition(double **Matrix,int m,int Bandwidth)

{
		int i,j,k;
		for(i=0;i<m;i++)
	{
		Matrix[i][i]=Bandwidth;
		if(i<=m-Bandwidth)
		{
			k=Bandwidth;
		}
		else
		{
			k=m-i;
		}
		for(j=1;j<k;j++)
		{
			Matrix[i][i+j]=Bandwidth-j;
			Matrix[i+j][i]=Bandwidth-j;
		}
	}
}
void Matrix2Definition(double **Matrix2,int m,int p)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		Matrix2[i][j]=1;
	}
}
void MatrixMultiply(double **Matrix1,double **Matrix2,double **Matrix3,int m,int n,int p)
{
	int i,j,k;
	int sum;
	for(i=0;i<m;i++)
	{
		for(k=0;k<p;k++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
			sum+=Matrix1[i][j]*Matrix2[j][k];
			Matrix3[i][k]=sum;
			}
		}
	}
}
void MatrixInverse(double **Matrix,int m,int n)