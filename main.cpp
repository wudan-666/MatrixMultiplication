#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Initialization.h"
#include "PrintToFile.h"
#include "MatrixOperation.h"

int main(int argc,char *argv[])
{
	int i;
	char *Directory1,*Directory2;
	Directory1 = "C:\\Users\\wudan\\c\\Array.txt";
	Directory2 = "C:\\Users\\wudan\\c\\Matrix1.txt";

	//************动态数组（一维）***********//
	//声明//
	//printf("Please set array size\n");
	//scanf("%d",&i);
	//double *CoordX,*CoordY,*CoordZ;
	//CoordX = (double*)malloc(i*sizeof(double));
	//CoordY = (double*)malloc(i*sizeof(double));
	//CoordZ = (double*)malloc(i*sizeof(double));
	//
	//InitializeArray(CoordX,i,0.0);
	//InitializeArray(CoordY,i,1.0);
	//InitializeArray(CoordZ,i,2.0);

	//************动态数组（二维）***********//
	double *x,*b,*r,*r_new,*p,*ArrayTemp;
	double **Matrix1;
	double alpha,beta;
	//double **Matrix2,**Matrix3;
	double error,error0=1E-06;
	int n = 20,m = n;
	//int p = 1;
	int Bandwidth = 5;
	Matrix1 = (double**)malloc(n*sizeof(double*));
	for(i=0;i<n;i++)
	{
		*(Matrix1+i) = (double*)malloc(n*sizeof(double));
	} 
	//Matrix2 = (double**)malloc(n*sizeof(double*));
	//for(i=0;i<m;i++)
	//{
	//	*(Matrix2+i) = (double*)malloc(p*sizeof(double));
	//} 
	//Matrix3 = (double**)malloc(m*sizeof(double*));
	//for(i=0;i<m;i++)
	//{
	//	*(Matrix3+i) = (double*)malloc(p*sizeof(double));
	//} 
	x = (double*)malloc(n*sizeof(double));
	b = (double*)malloc(n*sizeof(double));
	r = (double*)malloc(n*sizeof(double));
	r_new= (double*)malloc(n*sizeof(double));
	p = (double*)malloc(n*sizeof(double));
	ArrayTemp = (double*)malloc(n*sizeof(double));
	InitializeArray(x,n,0.0);
	InitializeArray(b,n,1.0);
	InitializeMatrix(Matrix1,n,n,0.0);
    //InitializeMatrix(Matrix2,n,p,0.0);
	//InitializeMatrix(Matrix3,m,p,0.0);
	//Matrix2Definition(Matrix2,n,p);
	MatrixDefinition(Matrix1,n,Bandwidth);
	//Initialization//
	//Conjugate Gradient//
	InitializeArray(x,n,0.0);
	MatrixMultiply(Matrix1,x,ArrayTemp,n,n);
	for(i=0;i<n;i++)
	{
		r[i]=b[i]-ArrayTemp[i];
		p[i]=r[i];
	}
	int k = 0;
	error=sqrt(Dotproduct(r,r,n));
	while (error>error0)
	{
		MatrixMultiply(Matrix1,p,ArrayTemp,n,n);
		alpha=Dotproduct(r,r,n)/Dotproduct(p,ArrayTemp,n);
		for(i=0;i<n;i++)
		{
			x[i]+=alpha*p[i];
			r_new[i]=r[i]-alpha*ArrayTemp[i];
		}
		error = sqrt(Dotproduct(r_new,r_new,n));
		beta=Dotproduct(r_new,r_new,n)/Dotproduct(r,r,n);
		for(i=0;i<n;i++)
		{
			p[i] = r_new[i]+beta*p[i];
			r[i] = r_new[i];
		}
		k++;
	}
	//MatrixMultiply(Matrix1,Matrix2,Matrix3,m,n,p);
	//MatrixMultiply(Matrix1,x,b,m,n);
	//PrintMatrix(Matrix1,Directory2,"A",m,n);
	//PrintMatrix(Matrix2,Directory2,"x",n,p);
	//PrintMatrix(Matrix3,Directory2,"b",m,p);
	printf("Iteration number = %d, error=%12E\n",k,error);
	//PrintMatrix(Matrix1,Directory2,"A",n,n);
	PrintArray(x,Directory1,"x",n);
	//PrintArray(b,Directory1,"b",n);
	system("pause");

	//************从文件读取***********//
	//FILE *fp;
	//double x,y,z;
	//for(j=0;j<i;j++)
	//{
	//	fscanf(fp,"%lf %lf %lf",&x,&y,&z);
	//	CoordX[j] = x;
	//	CoordY[j] = y;
	//	CoordZ[j] = z;
	//}
	//fclose(fp);
	//
	//printf("Which row would you like to check?\n");
	//scanf("%d",&i);
	//printf("%lf %lf %lf\n",CoordX[i],CoordY[i],CoordZ[i]);
	//
	//system("pause");

	//************基本变量***********//
	//声明//
	//char *aaa = "hahahaha";
	//char *bbb = "国庆节！";
	//double pi = 3.14159265358;
	//int c = 10;
	//int i,j;
	//
	//printf("Hello World.\n\n");
	//printf("%s, %s\n\n",aaa,bbb);
	//printf("%-16.11lf,%16.11lf\n",pi,pi);
	//printf("%f,%20e\n",pi,pi);
	//printf("%d,%10d\n",c,c);

	//************静态数组***********//
	//声明//
	//int Array1[10];
	//float Array2[10];
	//double Array3[10];
	////初始化//
	//for(i=0;i<10;i++)
	//{
	//	Array1[i] = 0;
	//	Array2[i] = 0.0;
	//	Array3[i] = (double)i;
	//}
	////声明//
	//double Matrix[5][5];
	////初始化//
	//for(i=0;i<5;i++)
	//{
	//	for(j=0;j<5;j++)
	//	{
	//		Matrix[i][j] = 0.0;
	//	}
	//}

	//************条件判断***********//
	//If Else//
	//for(i=0;i<m;i++)
	//{
	//	for(j=0;j<n;j++)
	//	{
	//		if(i == j)
	//		{
	//			Matrix[i][j] = 1.0;
	//		}
	//		else if(i < j)
	//		{
	//			Matrix[i][j] = 0.0;
	//		}
	//		else
	//		{
	//			Matrix[i][j] = 2.0;
	//		}
	//		printf("%6.2lf ",Matrix[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	//Switch//
	//for(i=0;i<m;i++)
	//{
	//	for(j=0;j<n;j++)
	//	{
	//		switch (i)
	//		{
	//		case 0:
	//			Matrix[i][j] = 0.0;
	//			break;
	//		case 1:
	//			Matrix[i][j] = 1.0;
	//			break;
	//		case 2:
	//			Matrix[i][j] = 2.0;
	//			break;
	//		case 3:
	//			Matrix[i][j] = 3.0;
	//			break;
	//		case 4:
	//			Matrix[i][j] = 4.0;
	//			break;
	//		}
	//		printf("%6.2lf ",Matrix[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");

	//************循环结构***********//
	//double error = 10.0;
	//int num = 0;
	//while(error > 1.0)
	//{
	//	error -= 1.0;
	//	num++;
	//}
	//printf("%d\n",num);
	//
	//system("pause");

	return 0;
}