#include <iostream>
#include <cmath>
#include <stdio.h>
#define N 100
#define T pow(10,-8)
using namespace std;

double sign(float e){
    if(e>=0)
        return 1;
    else
        return -1;
}

int main(){
int n,i,j,k,m,p,q;
cout<<"Enter size of Matrix: ";
cin>>n;
float a[n][n],d[n][n],r[n][n],R[n][n],x[n][n],l,e,t,c,s,sum;
///take the input
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        cout<<"Enter element a"<<i<<j<<": ";
        cin>>a[i][j];
    }
}
///equate dij with aij
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        d[i][j]=a[i][j];
    }
}
///initialise an identity matrix R
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i==j)
            R[i][j]=1;
        else
            R[i][j]=0;
    }
}

for(k=1;k<=N;k++)
    {
///find maximum of the absolute value in the given matrix
    l=fabs(a[1][2]);
    p=1;
    q=2;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            if(fabs(a[i][j])>l){
                l=fabs(a[i][j]);
                p=i;
                q=j;
            }
        }
    }
    ///define all the terms
    e=(a[q][q]-a[p][p])/(2*a[p][q]);
    t=sign(e)/(fabs(e)+sqrt(e*e+1));
    c=1/sqrt(1+t*t);
    s=c*t;
    ///define all the main 4 elements whose both the indices come from p and q
    d[p][q]=0;
    d[q][p]=0;
    d[p][p]=c*c*a[p][p]+s*s*a[q][q]-2*c*s*a[p][q];
    d[q][q]=c*c*a[q][q]+s*s*a[p][p]+2*c*s*a[p][q];
    ///define djp and djq
    for(j=1;j<=n;j++){
        if(j!=p && j!=q){
            d[j][p]=c*a[j][p]-s*a[j][q];
            d[p][j]=d[j][p];
            d[j][q]=c*a[j][q]+s*a[j][p];
            d[q][j]=d[j][q];
        }
    }
    ///define the new a matrix after multiplying with the rotation matrix
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=d[i][j];
        }
    }
    ///now let's look what the rotation matrix look like
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
			if(i==j)
				r[i][j]=1;
			else
				r[i][j]=0;
		}
	}
	r[p][p]=c;
	r[q][q]=c;
	r[p][q]=s;
	r[q][p]=-s;
	///multiply it with the previous rotation matrix
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            x[i][j]=0;
            for(m=1;m<=n;m++){
                x[i][j]=x[i][j]+R[i][m]*r[m][j];
            }
        }
    }
    ///modify the rotation matrix
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            R[i][j]=x[i][j];
        }
    }
///sum up all the off-diogonal elements to check the boundary condition
    sum=0;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            sum=sum+fabs(d[i][j]);
        }
    }
    if(sum<T)
        break;
}
///print out the matrix which contains the eigenvalue
cout<<"\nDiagonalised Matrix D is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf("%f\t",d[i][j]);
    }
    cout<<endl;
}
///print out the final transformation matrix
cout<<"\nFinal Transformation Matrix R is:\n";
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        printf("%f\t",R[i][j]);
    }
    cout<<endl;
}
return 0;
}
