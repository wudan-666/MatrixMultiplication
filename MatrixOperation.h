#ifndef _MATRIXOPERATION_ 
#define _MATRIXOPERATION_ 

void  MatrixDefinition(double **Matrix,int m,int Bandwidth);
void  Matrix2Definition(double **Matrix,int m,int k);
//void  MatrixMultiply(double **Matrix1,double **Matrix2,double **Matrix3,int m,int n,int p);
void  MatrixMultiply(double **Matrix1,double *x,double *b,int m,int n);
double Dotproduct(double *a,double *b,int n);
#endif
