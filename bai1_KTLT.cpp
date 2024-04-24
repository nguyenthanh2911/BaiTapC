#include <stdio.h>
typedef struct ps
 {
	int tuso;
	int mauso;
	
 }PS;
 
 
void input(PS &phanso){
	printf("nhap tu so :");
	scanf("%d", &phanso.tuso);
	printf("nhap mau so :");
	scanf("%d", &phanso.mauso);
	
}

void output(PS phanso){
	printf("%d/%d", phanso.tuso , phanso.mauso);
}

int ucln(int a, int b){
	if(b == 0){
		return a;
	}
	return ucln(b, a%b);
}

void toigian(PS &phanso){
	int tg = ucln(phanso.tuso, phanso.mauso);
	phanso.tuso /= tg;
	phanso.mauso  /= tg;
}

int main()
{
 PS p;
 printf("\nNhap phan so:"); 
 input(p);
 printf("\nPhan so vua nhap:"); 
 output(p);
 toigian(p);
 printf("\nPhan so sau khi toi gian:");
  output(p);
 return 0;
}


