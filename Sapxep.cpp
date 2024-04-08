#include <stdio.h>
#include <string.h>

struct NGAY {
    int ngay;
    int thang;
    int nam;
};

struct SANPHAM {
    char MaSP[10];
    char TenSP[255];
    struct NGAY NgaySX;
    int SoNamBH;
};

//Phương pháp Đổi chỗ trực tiếp (Interchange sort)
void InterchangeSort(SANPHAM dsSP[], int n){
    for(int i =0; i < n-1; i++){
        for(int j =i+1 ; j < n; j ++){
            if(strcmp(dsSP[i].MaSP, dsSP[j].MaSP) > 0){
                SANPHAM sp = dsSP[i];
                dsSP[i] = dsSP[j];
                dsSP[j] =  sp;
            }
        }
    }
}

//Phương pháp Nổi bọt (Bubble sort)
void BubbleSort(SANPHAM dsSP[], int  n){
    for(int i =0 ;  i < n-1;  i++){
        for(int j =0 ; j < n-i-1;  j++){
            if(strcmp(dsSP[j].MaSP  , dsSP[j+1].MaSP) > 0){
                SANPHAM sp = dsSP[j];
                dsSP[j] = dsSP[j+1];
                dsSP[j+1] = sp;
            }
        }
    }
}


//Phương pháp Chèn trực tiếp (Insertion sort)
void InsertionSort(SANPHAM dsSP[], int n){
    int i  ,j;
    SANPHAM key;
    for(i = 0;  i< n; i++){
        key = dsSP[i];
        j =i-1;
        while(j >= 0 && strcmp(dsSP[j].MaSP , key.MaSP)  > 0){
            dsSP[j+1] = dsSP[j];
            j =j-1;
        }
        dsSP[j +1] = key;
    }
}

 
//Phương pháp Chọn trực tiếp (Selection sort)
void SelectionSort(SANPHAM dsSP[], int n){
    for(int i = 0; i< n-1; i++){
        int min = i;
        for(int j = i+1;  j < n; j++){
            if(strcmp(dsSP[min].MaSP, dsSP[j].MaSP)  >  0){
                SANPHAM sp = dsSP[min];
                dsSP[min] = dsSP[j];
                dsSP[j] =  sp;
            }
        }
    }
}


//Phương pháp dựa trên phân hoạch (Quick sort)
void QuickSort(SANPHAM dsSP[] , int left , int right){
    char x[10];
    strcpy(x, dsSP[(left  + right)/2].MaSP);
    int i =  left;
    int j = right;
    while(i <= j){
        while(strcmp(x,  dsSP[i].MaSP) > 0)
            i++;
        while(strcmp(x, dsSP[j].MaSP) < 0)
            j--;
        if(i <=j){
            SANPHAM sp  = dsSP[i];
            dsSP[i] =  dsSP[j];
            dsSP[j] = sp;
            i++;
            j--;
        }
    }
    if(left < j)
        return QuickSort(dsSP, left,j);
    if(i < right)
        return QuickSort(dsSP , i,right);
}

// sap xep theo nam 
void sapxeptheonam(SANPHAM dsSP[], int n){
   for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n -i-1; j++){
        if(dsSP[j].NgaySX.nam > dsSP[j+1].NgaySX.nam ){
            SANPHAM sp = dsSP[j];
            dsSP[j] = dsSP[j +1];
            dsSP[j +1] = sp;
        }
    }
   }
}
 




void InThongTinSanPham(struct SANPHAM dsSP[], int n) {
    for(int i = 0; i < n; i++) {
        printf("MaSP: %s, TenSP: %s, NgaySX: %d/%d/%d, SoNamBH: %d\n", dsSP[i].MaSP, dsSP[i].TenSP, dsSP[i].NgaySX.ngay, dsSP[i].NgaySX.thang, dsSP[i].NgaySX.nam, dsSP[i].SoNamBH);
    }
} 



// tim kiem
//Tìm tuyến tính (Linear Search)
void LinearSearch(SANPHAM  dsSP[], int n , char *ten){
    int timkiem =  0;
    for(int i =0; i < n; i++){
        if(strcmp(dsSP[i].TenSP , ten) ==0){
            printf("------");
            InThongTinSanPham(&dsSP[i], 1);
            timkiem = 1;
        }
    }
    if(timkiem == 0)
        printf("khong tim thAY");
}

int BinarySearch(SANPHAM dsSP[], int left, int right, char *maSP) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Nếu mã sản phẩm tại vị trí mid khớp với mã sản phẩm cần tìm, trả về vị trí mid
        if (strcmp(dsSP[mid].MaSP, maSP) == 0)
            return mid;

        // Nếu mã sản phẩm tại vị trí mid lớn hơn mã sản phẩm cần tìm, tìm kiếm trong nửa trái của mảng
        if (strcmp(dsSP[mid].MaSP, maSP) > 0)
            return BinarySearch(dsSP, left, mid - 1, maSP);

        // Nếu mã sản phẩm tại vị trí mid nhỏ hơn mã sản phẩm cần tìm, tìm kiếm trong nửa phải của mảng
        return BinarySearch(dsSP, mid + 1, right, maSP);
    }

    // Trả về -1 nếu không tìm thấy mã sản phẩm trong mảng
    return -1;
}


void TimKiemSanPhamHetHanBaoHanh(struct SANPHAM dsSP[], int n, int namHienTai) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(dsSP[i].NgaySX.nam + dsSP[i].SoNamBH <namHienTai) {
            InThongTinSanPham(&dsSP[i], 1);
            found = 1;
           
        }
    }
    if(found == 0) {
        printf("Khong tim thay san pham nao da het han bao hanh.\n");
    }
}


int main() {
    struct SANPHAM dsSP[4] = {
        {"1", "SanPham1", {1, 1, 2018}, 3},
        {"9", "SanPham1", {1, 1, 2034}, 4},
        {"7", "SanPham7", {1, 1, 2019}, 4},
        {"4", "SanPham3", {1, 1, 2045}, 5}
    };
    int n = 4;
    int namHienTai = 2023;
    char ten[255];

    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Sap xep san pham\n");
        printf("2. Tim kiem san pham het han bao hanh\n");
        printf("3. Tim kiem theo ten\n");
        printf("4. sap  xep  theo nam \n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("DANH SACH SAN PHAM TRUOC KHI SAP XEP \n");
                InThongTinSanPham(dsSP, n);
                //QuickSort(dsSP, 0, n - 1);


                SelectionSort(dsSP, n);


                printf("\nDANH SACH SAN PHAM SAU KHI SAP XEP:\n");
                InThongTinSanPham(dsSP, n);
                break;
            case 2:
                printf("\nDanh sach san pham da het han bao hanh:\n");
                TimKiemSanPhamHetHanBaoHanh(dsSP, n, namHienTai);
                break;
            case 3:
                printf("\nNhap ten san pham can tim: ");
                scanf("%s", ten);
                LinearSearch(dsSP, n, ten);
                
                break;
            case 4:
                printf("\nSAP XEP THEO NAM\n");
                sapxeptheonam(dsSP, n);
                //sapxeptheonam(dsSP, 0, n - 1);
                InThongTinSanPham(dsSP , n);


                break;
            case 0:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}