#include <bits/stdc++.h>
using namespace std;
double myrand()
{
return rand()/(RAND_MAX+1.0);
//return 1;
}

int RANDNODE(int N){
return N*(rand()/(RAND_MAX+1.0))+1;
}
double fitness(int type,double epsilon){

	double rA=1;
	double rB=1;
	double randnum;
	randnum=myrand()>0.5?+1:-1;
	if(type==0)return rA+randnum*epsilon; else if(type==1)return rB+randnum*epsilon;else{cout<<"Error\n";}
	//if(type==0)return rA; else if(type==1)return rB;else{cout<<"Error\n";}
	//if(type==0)return rA+epsilon; else if(type==1)return rB-epsilon;else	{cout<<"Error\n";}

}

double death(int type,double epsilon){

	double dA=1;
	double dB=1;
	/*double randnum;
	randnum=myrand()>0.5?+1:-1;
	if(type==0)return dA+randnum*epsilon; else if(type==1)return dB+randnum*epsilon;else{cout<<"Error\n";}*/
	if(type==0)return dA; else if(type==1)return dB;else{cout<<"Error\n";}
	//if(type==0)return dA+epsilon; else if(type==1)return dB-epsilon;else	{cout<<"Error\n";}

}
int main(){
double epsilon;
double rr;
double jam=0.0;
int sample;
double p;
int typeforbirth;
double t,tm,t2;
int n,N;
int i,k,j;
cin>>N;
srand(time(NULL));
int **a;
a= new int *[(int)N+1];
for(i=0;i<=N;i++) a[i]=new int [(int)N+1];
int *b;
double variance;
b=new int [(int)N+1];
double P;
double **F;
F=new double *[2];
for(i=0;i<2;i++)F[i]=new double [(int)N+1];
double **D;
D=new double *[2];
for(i=0;i<2;i++)D[i]=new double [(int)N+1];
double rA,rB,dA,dB,RA,RB,DA,DB;
int rand1,ABFORB,ABFORD,rand2;
double sum,sum1;
double f_sum,f_sumd;
ofstream out("1.txt");
//complete
for(i=1;i<=N;i++)
for(j=1;j<=N;j++){
if(i==j)a[i][j]=0; else a[i][j]=1;}

//circle
/*int z=1;//h=2;
if(z>(N-1)/2){cout<<"Decrease z ....\n";exit(1);}
for(k=1;k<=z;k++){
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){if(i==((N+j-k)%N) || i==((j+k)%N))a[i+1][j+1]=1;}
	}
}*/

//Line
/*for(i=1;i<=N;i++)
for(j=1;j<=N;j++){
if(j==i-1 || j==i+1 )a[i][j]=1; else a[i][j]=0;}
a[1][1]=1;a[N][N]=1;*/

/*for(i=1;i<=N;i++){
    for(j=1;j<=N;j++){
        cout<<a[i][j]<<"  ";
    }
    cout<<'\n';
}*/

sample=1000000;
double deltaepsilon=0.1;
	for(epsilon=0.0;epsilon<=0.9;epsilon+=deltaepsilon){
		//if(epsilon>0.9) deltaepsilon=0.08;
	jam=0.0;
	tm=0.0;
	for(k=1;k<=sample;k++){	
	t=0.0;		
	RA=fitness(0,epsilon);
	RB=fitness(1,epsilon);
	DA=death(0,epsilon);
	DB=death(1,epsilon);	
	for(i=1;i<=N;i++){b[i]=0;F[0][i]=RA;F[1][i]=RB;
   	 D[0][i]=DA;D[1][i]=DB;}
	   rand1=RANDNODE(N);
	   b[rand1]=1;
	//b[1]=1;
	   n=1;
	//while(1){rand2=RANDNODE(N);if(rand2!=rand1)break;}b[rand2]=1;  n=2;	
while(n!=0 && n!=N){
	f_sum=0.0;
	for(i=1;i<=N;i++){f_sum+=(F[b[i]][i]);}
		sum=0.0;
		rr=myrand();
		typeforbirth=0;
		for(typeforbirth=1;typeforbirth<=N;typeforbirth++){
			sum+=F[b[typeforbirth]][typeforbirth]/f_sum;
			if(rr<=sum)break;
		}
		f_sumd=0.0;
		for(i=1;i<=N;i++)if(a[typeforbirth][i]==1){f_sumd+=(D[b[i]][i]);}
		rr=myrand();
		sum1=0.0;
		for(ABFORD=1;ABFORD<=N;ABFORD++){
			if(a[typeforbirth][ABFORD]==1){
				sum1+=D[b[ABFORD]][ABFORD]/f_sumd;
			}
			if(rr<=sum1)break;
		}
		n+=(b[typeforbirth]-b[ABFORD]);	
		b[ABFORD]=b[typeforbirth];
		t++;
		RA=fitness(0,epsilon);
		RB=fitness(1,epsilon);
		DA=death(0,epsilon);
		DB=death(1,epsilon);	
		/*for(i=1;i<=N;i++){F[0][i]=RA;F[1][i]=RB;
   			 D[0][i]=DA;D[1][i]=DB;}*/
		for(i=1;i<=N;i++){
		if(b[i]==0){F[0][i]=RA;D[0][i]=DA;}
		else {F[1][i]=RB;D[1][i]=DB;}}
		
   }//w
	
    if(n==N ){
       jam++;
       tm+=t;
   }//else k--;
}//k

/*if(jam>0) tm/=jam;
if(jam>0)out<<epsilon<<'\t'<<tm<<'\n';
cout<<epsilon<<'\t'<<tm<<'\n';*/

cout<<epsilon<<'\t'<<jam/sample<<'\n';
out<<epsilon<<'\t'<<jam/sample<<'\t'<<'\n';

}//epsilon	
return 0;
}
