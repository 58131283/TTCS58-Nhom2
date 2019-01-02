#include<stdio.h>
#include<stdlib.h>
void nhapmang(int a[100][100],int n1,int n2){
	for (int i=0;i<n1;i++)
		for (int j=0;j<n2;j++)
			{
				a[i][j]=0+rand()%100;
			}
	
}
void xuatmang(int a[][100],int n1,int n2)
{
	for (int i=0;i<n1;i++)
		{
			for (int j=0;j<n2;j++)
			{
				printf("%4d",a[i][j]);
				
			}
				printf("\n");
		}
}
void xoadongi(int a[][100],int n1,int n2)
{
		int d;
 		printf("xoa dong thu : ");
 		scanf("%d",&d);
 		for (int i=d;i<n1;i++)
 			for (int j=0;j<n2;j++){
 				a[i][j]=a[i+1][j];
 			}
 			n1--;
 		xuatmang(a,n1,n2);
}
void xoacotj(int a[][100],int n1, int n2){
	int c;
	printf("xoa cot thu :");
	scanf("%d",&c);
	 		for (int i=0;i<n1;i++)
 				for (int j=c;j<n2;j++){
 					a[i][j]=a[i][j+1];
 				}
 			
 					n2--;
 		
 				xuatmang(a,n1,n2);
}
void duongcheochinh(int a[][100],int n1)
{
    FILE *f;
    f=fopen("D:/58131283-tuan2/output1.txt","wt");
    fprintf(f,"%3d",n1);
    for(int i = 0 ; i < n1 ; i++)
        fprintf(f,"%3d",a[i][i]);
    fclose(f);
}
void  maxdong(int a[][100],int n1){
	FILE *f;
    f=fopen("D:/58131283-tuan2/output1.txt","wt");
    fprintf(f,"%3d",n1);
	int dong=1;
 		fprintf(f," %3d ",dong);
	int max=a[0][0];
	for (int i=dong;i<n1;i++){
			if (a[dong][i]>max)
			max=a[dong][i];
		}
		 fprintf(f,"%3d",max);
    fclose(f);
		
	}
void  maxcot(int a[][100],int n2){
	FILE *f;
    f=fopen("D:/58131283-tuan2/output1.txt","wt");
    fprintf(f,"%3d",n2);
	int cot=2;
 		fprintf(f," %3d ",cot);
	int max=a[0][0];
	for (int i=cot;i<n2;i++){
			if (a[i][cot]>max)
			max=a[i][cot];
		}
		fprintf(f,"%3d",max);
    fclose(f);
		
	}
void duongcheophu(int a[][100],int n1){
	FILE *f;
    f=fopen("D:/58131283-tuan2/output1.txt","wt");
    fprintf(f,"%3d",n1);
	for (int i=0;i<n1;i++)
			fprintf(f,"%3d",a[i][i+1]);
	fclose(f);
}
int main(){
	int a[100][100],n1,n2;
	while(n1<3||n1>10&&n2<3||n2>10){
	printf("nhap so dong n1 :");
	scanf("%d",&n1);
	printf("\nnhap so cot n2 :");
	scanf("%d",&n2);
	}
	nhapmang(a,n1,n2);
	printf("mang truoc la : \n");
	xuatmang(a,n1,n2);
	//printf("mang sau:\n");
	//xoacotj(a,n1,n2);
	
//	int t=maxcot(a,n1,n2);
//	printf("%d",t);
	printf("\nduong cheo chinh :");
	duongcheochinh(a,n1);
	duongcheophu(a,n1);
	maxcot(a,n1);
	//printf("\nduong cheo phu :");
	//duongcheophu(a,n1);
	
}
