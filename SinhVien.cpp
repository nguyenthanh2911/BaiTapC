#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

// Khai bao cau truc du lieu cua sinh vien 
struct sv
{
    char id[11];               // MSSV
    char forename[20];         // Ho va ten lot
    char surname[30];          // Ten
    char fullname[50];         // Ho va ten day du
    char gender;               // Gioi tinh
    char branch[20];           // Nganh
    char date[10];             // Ngay thi
    float ltw, ktlt, trr, avr; // Lan luot la diem Lap trinh Web, Ky thuat lap trinh, Toan roi rac, trung binh;
};

// Ham menu
void menu()
{
    printf("\n------------------------w----------------------\n");
    printf("1 -> Nhap danh sach sinh vien \n");
    printf("2 -> Xuat danh sach sinh vien \n");
    printf("3 -> Tinh diem trung binh cua sinh vien \n");
    printf("4 -> Dem sinh vien co diem trung binh lon hon 5 \n");
    printf("5 -> Sap xep danh sach sinh vien theo diem trung binh tang dan \n");
    printf("Lua chon cua ban : ");
}

void inputListStudent(sv a[], int n) // Nhap danh sach sinh vien
{
    for (int i = 0; i < n; i++)
    {
        printf("\nSinh vien thu %d: \n", i + 1);
        printf("Nhap ma so sinh vien: ");
        fflush(stdin);
        gets(a[i].id);
        printf("Nhap ho va ten dem: ");
        fflush(stdin);
        gets(a[i].forename);
        printf("Nhap ten sinh vien ");
        fflush(stdin);
        gets(a[i].surname);
        strcat(a[i].fullname, a[i].surname);
        strcat(a[i].fullname, " ");
        strcat(a[i].fullname, a[i].forename);
        do
        {
            printf("Nhap gioi tinh sinh vien  (x = Nam, y = Nu) : ");
            fflush(stdin);
            a[i].gender = getche();
        } while (a[i].gender != 'x' && a[i].gender != 'y');
        gets(a[i].branch);
        printf("Nganh cua sinh vien : ");
        fflush(stdin);
        gets(a[i].branch);
        printf("Nhap ngay thi : ");
        fflush(stdin);
        gets(a[i].date);
        fflush(stdin);
        printf("Nhap diem mon lap trinh web : ");
        scanf("%f", &a[i].ltw);
        printf("Nhap diem ky thuat lap trinh :");
        scanf("%f", &a[i].ktlt);
        printf("Nhap diem mon toan roi rac :");
        scanf("%f", &a[i].trr);
        a[i].avr = (a[i].ltw + a[i].ktlt + a[i].trr) / 3;
    }
}
void outputListStudent(sv a[], int n) // Xuat danh sach sinh vien
{
    printf("Danh sach sinh vien : \n");
    printf("%3s|%20s|%11s|%11s|%20s|%20s|%15s|%15s|%15s|\n", "STT", "Ho va ten", "Gioi tinh", "MSSV", "Nganh", "Ngay thi", "Lap trinh web", "KTLT", "Toan roi rac");
    for (int i = 0; i < n; i++)
    {
        if (a[i].gender == 'x')
        {
            printf("%3d|%20s|%11s|%11s|%20s|%20s|%15.2f|%15.2f|%15.2f|\n", i + 1, a[i].fullname, "Nam", a[i].id, a[i].branch, a[i].date, a[i].ltw, a[i].ktlt, a[i].trr);
        }
        else
            printf("%3d|%20s|%11s|%11s|%20s|%20s|%15.2f|%15.2f|%15.2f|\n", i + 1, a[i].fullname, "Nu", a[i].id, a[i].branch, a[i].date, a[i].ltw, a[i].ktlt, a[i].trr);
    }
}
void averageListStudent(sv a[], int n) // In ra danh sach sinh vien nhung co them theo cot diem Trung binh
{
    printf("Danh sach sinh vien : \n");
    printf("%3s|%20s|%11s|%11s|%20s|%20s|%15s|%15s|%15s|%15s|\n", "STT", "Ho va ten", "Gioi tinh", "MSSV", "Nganh", "Ngay thi", "Lap trinh web", "KTLT", "Toan roi rac", "Trung binh");
    for (int i = 0; i < n; i++)
    {
        if (a[i].gender == 'x')
        {
            printf("%3d|%20s|%11s|%11s|%20s|%20s|%15.2f|%15.2f|%15.2f|%15.2f|\n", i + 1, a[i].fullname, "Nam", a[i].id, a[i].branch, a[i].date, a[i].ltw, a[i].ktlt, a[i].trr, a[i].avr);
        }
        else
            printf("%3d|%20s|%11s|%11s|%20s|%20s|%15.2f|%15.2f|%15.2f|%15.2f|\n", i + 1, a[i].fullname, "Nu", a[i].id, a[i].branch, a[i].date, a[i].ltw, a[i].ktlt, a[i].trr, a[i].avr);
    }
}
void quickSortStruct(sv a[], int left, int right) // Sap xep nhanh danh sach sinh vien theo chieu tang dan cua diem trung binh
{
    float x = a[(left + right) / 2].avr;
    int i = left, j = right;
    while (i <= j)
    {
        while (a[i].avr < x)
            i++;
        while (a[j].avr > x)
            j--;
        if (i <= j)
        {
            sv tg = a[i];
            a[i] = a[j];
            a[j] = tg;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSortStruct(a, left, j); 
    if (i < right)
        quickSortStruct(a, i, right); 
}
int countPassAvr(sv a[], int n) // Dem so luong sinh vien co diem trung binh cao hon 5
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].avr > 5.0)
            dem++;
    }
    return dem;
}
// Ham main 
int main()
{
    sv a[100];
    int n, key, test = -1;
    do
    {
        menu();
        scanf("%d", &key);
        switch (key)
        {
        case 1:
        {
            printf("Nhap so luon sinh vien : ");
            scanf("%d", &n);
            inputListStudent(a, n);
            test = 1;
            break;
        }

        case 2:
        {
            if (test == 1)
            {   
                system("cls"); // Xoa man hinh
                outputListStudent(a, n);
            }
            else
                printf("\n Hay nhap danh sach sinh vien truoc !");
            break;
        }

        case 3:
        {
            if (test == 1)
            {   
                system("cls"); 
                averageListStudent(a, n);
            }
            else
                printf("\n Hay nhap danh sach sinh vien truoc !");
            break;
        }

        case 4:
        {
            if (test == 1)
            {   
                system("cls");
                printf("\nCo %d sinh vien co diem trung binh tren 5.", countPassAvr(a, n));
            }
            else
                printf("\n Hay nhap danh sach sinh vien truoc !");
            break;
        }

        case 5:
        {
            if (test == 1)
            {   
                system("cls");
                quickSortStruct(a, 0, n - 1); // Sap xep cau truc sinh vien
                averageListStudent(a, n);     // In ra danh sach sinh vien kem diem trung binh sau khi da sap xep
            }
            else
                printf("\n Hay nhap danh sach sinh vien truoc !");
            break;
        }

        default:
        {   
            system("cls");
            printf("Lua chon khong hop le!");
            break;
        }
        }
    } while (key > 0); // Dieu kien de thoat khoi chuong trinh gia dinh là lua chon < 0;
    return 0;
}