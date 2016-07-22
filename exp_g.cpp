/*********************************************************************************
* This file is part of the Generalized Simulated Annealing (GSA-1.0) program
* John Peter Oyardo Manrique <johnp067@usr.br>
* Copyright (c) 2016-2025 John Oyardo.  All Rights Reserved.
* GSA-1.0-LICENSE file has the license that must be included with GSA-1.0 code.
* Citations: MANRIQUE, John Peter Oyardo/ Manrique, J. P. O.(2015).
*********************************************************************************/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <new>
#include <string.h>
#include <iomanip>
#include <vector>
/********************************************************************************/
using namespace std;

const float pi=3.141592;

float a,b,xa,ya;

float exp_g(float q_, float z)
	{
	   if (q_ == 0)
       return exp(z);
       else
	   return pow((1+q_*z),1/q_);
	}

void imprime_matriz(vector<vector<float>> A) {
    ofstream fw;                            //FILE  *fw;
    int i, j;
    fw.open("exp_g.dat",ios::app);         //fw = fopen ("saidam.dat", "w");

    if (fw == NULL) {
      perror("saidam2.dat");
      exit(-1);  /* Abandona o programa */
    }
    fw<<"Matrix\n"<<endl;
    int n=A.size();
    int m=A[0].size();
    for (j=0; j< m; j++){
        for (i=0; i< n; i++){
            fw<<A[i][j]<<" ";//fw<<" "<<setw(width)<<v[i]<<" "<<setw(width)<<u[i];/
            cout<<A[i][j]<<" ";//fprintf(fw," %d %d ", v[i]," ",u[j]);
        }
        fw<<" \n";
        cout<<" \n";
    }

    fw.close( );                            //fclose(fw);
}
main(){
int i,j,it,n,nx,Td;
float a,b,h,q,xi,xf,sum,x_sem1,x_sem2;double err;
const float pi=3.141592;
float  v1[5000],v2[5000],r[5000],w[5000],s[5000],y[5000];
char filename[20];

std::vector <float> u1,u2,x;
std::vector<std::vector<float>> A;

ofstream fw("exp_g.dat");
cout<<"Exponential Generalized Function"<<endl;
fw<<"Exponential Generalized Function"<<endl;
cout<<"Ingress bin size (default> h=0.01):"<<endl;cin>>h;
q=-1; h=0.01; xi=-3;xf=3;//q=-1;n=2001;n=601; h=0.01;xi=-3;
n=round((xf-(xi-h))/h);
x.resize(n);
for (i = 0;i< n; i++){
x[i]=xi+i*h;
}
A.resize(9);
for (i = 0;i< 9; i++)
    A[i].resize(n);
for (j=0; j<n; j++)
    A[0][j]=x[j];
for (i=1; i<=8; i++){
    for (j=0; j<n; j++){
    A[i][j]=exp_g(q+0.5*(i-1),x[j]);//q=q+0.1*j;
    }
}
fw<<" \n"<<endl;
cout<<" \n"<<endl;
imprime_matriz(A);

return(0);
}
