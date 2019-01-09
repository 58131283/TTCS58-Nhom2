#include<iostream>
#include<conio.h>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 
int a[100][100];//ma tran trong so cua do thi.
int n;//s dinh cua do thi
int m;//so canh cua do thi.
int socanh;//so canh cua c�y khung nho nhat.
int dodai;//�o d�i cua c�y khung nho nhat.
int chuaxet[100];//mang d�nh dau danh s�ch dinh d� th�m v�o c�y khung nho nhat.
int dsc[100][3];//danh s�ch canh cua c�y khung nho nhat.
void nhap(){
 int i, j, k;
 freopen("D:/58131283-vudat-tuan3/dothi.txt", "rt",stdin);
 cin>>n>>m;
 cout<<"So dinh cua do thi: "<<n<<endl;
 cout<<"So canh cua do thi: "<<m<<endl;
 //khoi tao ma tran trong so cua do thi a[i][j] = MAX.
 for (i = 1; i <= n; i++){
  chuaxet[i] = TRUE;//G�n nh�n cho c�c dinh.
  for (j = 1; j <= n; j++)
   a[i][j] = MAX;
 }
 
 //nhap danh s�ch canh.
 for (int c = 1; c <= m; c++){
  cin>>i>>j>>k;
  a[i][j] = k;
  a[j][i] = k;
 }
}
void PRIM(){
 int k, top, min, l, t, u;
 int s[100];//mang chua c�c dinh cua c�y khung nho nhat.
 socanh = 0; dodai = 0; u = 1;
 top = 1;
 s[top] = u;// th�m dinh u bat ki v�o mang s[]
 chuaxet[u] = FALSE;
 while (socanh<n - 1) {
  min = MAX;
  //t�m canh c� do d�i nho nhat voi c�c dinh trong mang s[].
  for (int i = 1; i <= top; i++){
   t = s[i];
   for (int j = 1; j <= n; j++){
    if (chuaxet[j] && min>a[t][j]){
     min = a[t][j];
     k = t;
     l = j;
    }
   }
  }
  socanh++;
  dodai = dodai + min;
  //th�m v�o danh s�ch canh cua c�y khung.
  dsc[socanh][1] = k;
  dsc[socanh][2] = l;
  chuaxet[l] = FALSE; 
  top++;
  s[top] = l;
 }
}
void ketqua(void){
 cout<<"Do dai ngan nhat:"<< dodai<<endl;
 cout<<"Cac canh cua cay khung nho nhat"<<endl;
 for (int i = 1; i <= socanh; i++)
  cout<< dsc[i][1]<<" "<< dsc[i][2]<<endl;
}
int main(){
 nhap(); 
 PRIM();
 ketqua();
 getch();
}
