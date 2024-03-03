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
        /*double randnum;
	randnum=myrand()>0.5?+1:-1;
	if(type==0)return rA+randnum*epsilon; else if(type==1)return rB+randnum*epsilon;else{cout<<"Error\n";}*/
	if(type==0)return rA; else if(type==1)return rB;else{cout<<"Error\n";}
	

}
double death(int type,double epsilon){

	double dA=1;
	double dB=1;
	double randnum;
	randnum=myrand()>0.5?+1:-1;
	if(type==0)return dA+randnum*epsilon; else if(type==1)return dB+randnum*epsilon;else{cout<<"Error\n";}
	//if(type==0)return dA; else if(type==1)return dB;else{cout<<"Error\n";}

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
b=new int [(int)N+1];
double **F;
F=new double *[2];
for(i=0;i<2;i++)F[i]=new double [(int)N+1];
double **D;
D=new double *[2];
for(i=0;i<2;i++)D[i]=new double [(int)N+1];
double rA,rB,dA,dB,RA,RB,DA,DB;
int rand1,ABFORB,ABFORD,rand2,rand3,rand4,rand5;
double sum,sum1;
double f_sum,f_sumd;
double sumin,sumde,m,noise,noisep;
double aa=1;
double bb=-1;
double tau=0.0001;
double delta=0.01;
double randnum;
double mua;//=aa/((aa-bb)*tau);
double mub;//=-bb/((aa-bb)*tau);
double P1;//=(mub/(mua+mub))+(mua/(mua+mub))*exp(-1*(mua+mub)*delta);
double P2;//=(mub/(mua+mub))-(mub/(mua+mub))*exp(-1*(mua+mub)*delta);
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
}
*/
//Line
/*for(i=1;i<=N;i++)
for(j=1;j<=N;j++){
if(j==i-1 || j==i+1 )a[i][j]=1; else a[i][j]=0;}
a[1][1]=1;a[N][N]=1;*/

sample=1000000;
double deltaepsilon=0.1;
	for(epsilon=0.0;epsilon<=1;epsilon+=deltaepsilon){
	//tau=0.5*epsilon;
 mua=aa/((aa-bb)*tau);
 mub=-bb/((aa-bb)*tau);
 P1=(mub/(mua+mub))+(mua/(mua+mub))*exp(-1*(mua+mub)*delta);
 P2=(mub/(mua+mub))-(mub/(mua+mub))*exp(-1*(mua+mub)*delta);

	jam=0.0;
	tm=0.0;sumin=0;sumde=0;
	for(k=1;k<=sample;k++){	
	t=0.0;	
	RA=fitness(0,epsilon);
	RB=fitness(1,epsilon);
	DA=death(0,epsilon);
	DB=death(1,epsilon);	
	for(i=1;i<=N;i++){b[i]=0;F[0][i]=RA;F[1][i]=RB;
   	 D[0][i]=DA;D[1][i]=DB;}
	   rand1=RANDNODE(N);
	 b[rand1]=1;n=1;
randnum=myrand()>0.5?noise=aa:noise=bb;	
//noise=aa;
while(n!=0 && n!=N){
noisep=noise;

		f_sumd=0.0;
		for(i=1;i<=N;i++){f_sumd+=(D[b[i]][i]);}
		rr=myrand();
		sum1=0.0;
		for(ABFORD=1;ABFORD<=N;ABFORD++){
				sum1+=D[b[ABFORD]][ABFORD]/f_sumd;
			if(rr<=sum1)break;
		}
		f_sum=0.0;
		for(i=1;i<=N;i++)if(a[ABFORD][i]==1){f_sum+=(F[b[i]][i]);}
		rr=myrand();
		sum=0.0;
		for(typeforbirth=1;typeforbirth<=N;typeforbirth++){
			if(a[ABFORD][typeforbirth]==1){
				sum+=F[b[typeforbirth]][typeforbirth]/f_sum;
			}
			if(rr<=sum)break;
		}
		n+=(b[typeforbirth]-b[ABFORD]);	
		b[ABFORD]=b[typeforbirth];
		

if(noise==aa){
rr=myrand();
if(rr<=P1)
noise=aa;
else
noise=bb;
}	              

else if (noise==bb)
{
	rr=myrand();
	if(rr<=P2)
	noise=aa;
	else
	noise=bb;
	}

//cout<<noisep<<'\t'<<noise<<'\n';
		if(noisep!=noise){
		//if(noisep==noise){
		RA=fitness(0,epsilon);
		RB=fitness(1,epsilon);
		DA=death(0,epsilon);
		DB=death(1,epsilon);	
		for(i=1;i<=N;i++){F[0][i]=RA;F[1][i]=RB;
   			 D[0][i]=DA;D[1][i]=DB;}
		}
		t++;

		//for(i=1;i<=N;i++) cout<<F[0][i]<<'\t'<<F[1][i]<<'\n';


		
   }//w
	
    if(n==N ){
       jam++;
       tm+=t;
   }//else k--;
}//k

tm/=jam;


cout<<epsilon<<'\t'<<jam/sample<<'\t'<<'\n';
out<<epsilon<<'\t'<<jam/sample<<'\t'<<'\n';

}//epsilon	
return 0;
}
