#include<stdio.h>
#include<string.h>
struct HoTen {
	char ho[20];
	char dem[20];
	char ten[20];
};
struct SinhVien{
    int TT;
    int MSSV;
    struct HoTen hoVaTen;
    float GPA;
    char  khoahoc[20];
};
///////////////////////////////////////////////////////////////////////////////////////////////
void nhapHoTen(struct HoTen* ten) {
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Dem: ");
	getchar();
	// gets(ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}
///////////////////////////////////////////////////////////////////////////////////////////////
void Nhap(SinhVien sv[], int n)
{
    for(int i=0; i<n ; i++)
    {
        
        printf("\nNhap sinh vien thu  %d \n",i+1);
        printf("\nNhap thu tu sinh vien:");
        scanf("%d", &sv[i].TT);
        printf("\nNhap MSSV sinh vien:");
        scanf("%d", &sv[i].MSSV);
        nhapHoTen(&sv[i].hoVaTen);
        printf("\nNhap diem GPA:");
        scanf("%f", &sv[i].GPA);
        printf("\nNhap vao mon hoc: ");
        scanf("%s", &sv[i].khoahoc);
    }
}
////////////////////////////////////////////////////////////////
void Xuat(SinhVien sv[], int n)
{

		printf("\n%-10s %-10s %-10s %-15s %-10s%-10s %-10s","STT","MSSV","HO","DEM","TEN","Diem GPA","Khoa Hoc");
	for(int i = 0;i <n; i++){
		printf("\n%-10d %-10d %-10s %-15s %-10s %-10.1f %-10s", sv[i].TT,sv[i].MSSV,sv[i].hoVaTen.ho, sv[i].hoVaTen.dem, sv[i].hoVaTen.ten, sv[i].GPA,sv[i].khoahoc);
	}
}
///////////////////////////////////////////////////////////////////
void nhapsonguyenduong(int &x)
{
	
	do
	{
		scanf("%d", &x);
		if (x <= 0)
			printf("nhap sai r. vui long nhap lai:");

	} while (x<=0);

}
/////////////////////////////////////////////////////////////////////////////
void ThemSV(SinhVien sv[], int n)
{
    n++;
    printf("\nNhap thong tin sinh vien muon them:\n");
    for(int i = n - 1 ; i > 0 ; i--)
    {
    	printf("\nNhap sinh vien thu  %d \n",i+1);
        printf("\nNhap thu tu sinh vien:");
        scanf("%d", &sv[i].TT);
        printf("\nNhap MSSV sinh vien:");
        scanf("%d", &sv[i].MSSV);
        nhapHoTen(&sv[i].hoVaTen);
        printf("\nNhap diem GPA:");
        scanf("%f", &sv[i].GPA);
        printf("\nNhap vao mon hoc: ");
        scanf("%s", &sv[i].khoahoc);
	
    }
    printf("\nDanh sach sinh vien sau khi them la:\n");
    Xuat(sv,n);
}
/////////////////////////////////////////////////////////////////////////////

int xoaSinhVien( SinhVien sv[], int* count, int tt) {
    int found = 0;

    for (int i = 0; i < *count; i++) {
        if (sv[i].TT == tt) {
            found = 1;

            // Shift elements to the left to remove the student from the array
            for (int j = i; j < (*count) - 1; j++) {
                sv[j] = sv[j + 1];
            }

            (*count)--;
            break;
        }
    }

    return found;
}
/////////////////////////////////////////////////////////////////////////////
void Timkiem(SinhVien sv[], int n)
{
    int x;
    printf("\nNhap STT sinh vien can tim:");
    scanf("%d", &x);
   	printf("\n%-10s %-10s %-10s %-15s %-10s%-10s %-10s","STT","MSSV","HO","DEM","TEN","Diem GPA","Khoa Hoc");
    for(int i=0;i<n;i++)
    {
        
        if(sv[i].TT == x)
        {
           	printf("\n%-10d %-10d %-10s %-20s %-10s %-10.1f %-10s", sv[i].TT,sv[i].MSSV,sv[i].hoVaTen.ho, sv[i].hoVaTen.dem, sv[i].hoVaTen.ten, sv[i].GPA,sv[i].khoahoc);
        }
    } 
}

/////////////////////////////////////////////////////////////////////////////

void timsvtheoten( SinhVien sv[], int n){

char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	int i, timSV = 0;
	for(i = 0; i < n; i++) {
		if(stricmp(ten, sv[i].hoVaTen.ten) == 0) {
			printf("\n%-10s %-10s %-10s %-15s %-10s%-10s %-10s","STT","MSSV","HO","DEM","TEN","Diem GPA","Khoa Hoc");
			printf("\n%-10d %-10d %-10s %-15s %-10s %-10.1f %-10s", sv[i].TT,sv[i].MSSV,sv[i].hoVaTen.ho, sv[i].hoVaTen.dem, sv[i].hoVaTen.ten, sv[i].GPA,sv[i].khoahoc);
			timSV = 1;
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}

}

void timsvtheokhoahoc(SinhVien sv[], int n)
{
    char khoahoc[20];
    printf("Nhap vao khoa hoc: ");
    scanf("%s", khoahoc);
    
    int timSV = 0;
    for(int i = 0; i < n; i++)
    {
        if(strcmp(khoahoc, sv[i].khoahoc) == 0)
        {
        	printf("\n%-10s %-10s %-10s %-15s %-10s%-10s %-10s","STT","MSSV","HO","DEM","TEN","Diem GPA","Khoa Hoc");
            printf("\n%-10d %-10d %-10s %-15s %-10s %-10.1f %-10s", sv[i].TT, sv[i].MSSV, sv[i].hoVaTen.ho, sv[i].hoVaTen.dem, sv[i].hoVaTen.ten, sv[i].GPA, sv[i].khoahoc);
            timSV = 1;
        }
    }
    
    if(timSV == 0)
    {
        printf("Khong co sinh vien trong khoa hoc %s!\n", khoahoc);
    }
}


void capNhatSinhVien( SinhVien sv[], int n) {
    int found = 0;
    int choice;
    int mssv;
    printf("\nNhap MSSV sinh vien can cap nhat thong tin:");
    scanf("%d", &mssv);
    for (int i = 0; i < n; i++) {
        if (sv[i].MSSV == mssv) {
            found = 1;

            printf("\nCap nhat thong tin sinh vien co MSSV %d:\n", mssv);
            printf("1. Cap nhat ho\n");
            printf("2. Cap nhat dem\n");
            printf("3. Cap nhat ten\n");
            printf("4. Cap nhat CGPA\n");
            printf("5. Cap nhat mon hoc\n");
            printf("Chon truong can cap nhat (1-5): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Ho: ");
                    scanf("%s", sv[i].hoVaTen.ho);
                    break;
                case 2:
                    printf("Dem: ");
                    getchar();
                    fgets(sv[i].hoVaTen.dem, sizeof(sv[i].hoVaTen.dem), stdin);
                    sv[i].hoVaTen.dem[strlen(sv[i].hoVaTen.dem) - 1] = '\0';
                    break;
                case 3:
                    printf("Ten: ");
                    scanf("%s", sv[i].hoVaTen.ten);
                    break;
                case 4:
                    printf("CGPA: ");
                    scanf("%f", &sv[i].GPA);
                    break;
                case 5:
                    printf("Mon hoc: ");
                    getchar();
                    fgets(sv[i].khoahoc, sizeof(sv[i].khoahoc), stdin);
                    sv[i].khoahoc[strlen(sv[i].khoahoc) - 1] = '\0';
                    break;
                default:
                    printf("Lua chon khong hop le.\n");
                    break;
            }

            printf("Da cap nhat thong tin sinh vien co MSSV %d.\n", mssv);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co MSSV %d.\n", mssv);
    }
}
/////////////////////////////////////////////////////////////////////////////
void showmenu()
{
    printf("\n\n     CHUONG TRINH SYSTUM QUAN LY SINH VIEN C/C++\n");
    printf("\n*****************************************************");
    printf("\n*                      MENU                         *");
    printf("\n*1. Nhap thong tin sinh vien                        *");
    printf("\n*2. Them sinh vien                                  *");
    printf("\n*3. Xoa sinh vien theo STT                          *");
    printf("\n*4. Tiem kiem theo STT                              *");
    printf("\n*5. Tiem kiem sinh vien theo ten                    *");
    printf("\n*6. Tiem kiem sinh vien theo khoa hoc               *");
    printf("\n*7. Update sinh vien                                *");
    printf("\n*8. Show thong tin sinh vien                        *");
    printf("\n*0. Thoat chuong trinh.                             *");
    printf("\n*****************************************************");
}

int process()
{
	SinhVien sv[100];
    int n;
	int chon;
	do
	{
		showmenu();
		printf("\nBan hay chon chuc nang\n");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
		 printf("Nhap so sinh vien:");
		 nhapsonguyenduong(n);
		 Nhap(sv, n);
                 printf("\nDanh sach cac sinh vien la:\n");
                 Xuat(sv,n);
			break;
		case 2:
		 ThemSV(sv,n);
		  n++; 
			break;
		case 3:
		            int tt;
                    printf("Nhap STT: ");
                    scanf("%d", &tt);
                    if (xoaSinhVien(sv, &n, tt)) {
                        printf("Da xoa sinh vien co STT %d.\n", tt);
                    } else {
                        printf("Khong tim thay sinh vien co STT %d.\n", tt);
                    } 
		
			break;
		case 4:
		 Timkiem(sv,n);
			break;
		case 5:
		 timsvtheoten(sv,n);
			break;
		case 6:
		timsvtheokhoahoc(sv,n);
			break;
		case 7:
		capNhatSinhVien(sv,n);
			break;
		case 8:
		Xuat(sv,n);
			break;
			
		}

	} while (chon!=0);
	
	return 0;
}



int main()
{
	process();

}
