#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void showData(double *a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i+1)%M == 0) cout << endl;
        else cout << " ";
    }
}
void randData(double *b,int N,int M){
    for(int i = 0; i < N*M; i++){
      b[i]= (rand()%101)/100.00;
    }
}
void findRowSum(const double *B,double *a,int K,int A){
	int N = 0;
	for (int j = 0; j < A ; j++) a[j] = 0;
	if (A == 1) for (int i  = 0; i < K*A; i++) a[i] = B[i];
	else{
		for (int i  = 0; i < K*A; i++){
			a[N] += B[i];
			if((i+1)%A == 0){
		    	N++;
        	}
		}
	}
}
void findColSum(const double *P,double *U,int B,int G){
	if(B == 1){
		for (int i  = 0; i < G; i++){
			U[i] = P[i];
		}
	}
	else{
		for (int j  = 0; j < B*G; j++){
			U[j%G] += P[j];
		}
        for (int k = 0; k < G ; k++){
             U[k] = 0;
        }
	    for (int n  = 0; n < B*G; n++){
		    U[n%G] += P[n];  
        }
    }
} 
