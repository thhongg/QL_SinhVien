#include <iostream>
#include "QLSinhVien.h"
#include "SinhVien.h"

using namespace std;

void Menu();
int ChonMenu();
void XuLyMenu();

static const string datafile = "sinhvien.txt";

int main() {
	Menu();
	while (true)
	{
		XuLyMenu();
	}
	return 1;
}

void Menu() {
	cout << "=================MENU================\n";
	cout << "0. Ket thuc chuong trinh\n";
	cout << "1. Ghi danh sach sinh vien len tap tin\n";
	cout << "2. Doc danh sach sinh vien tu tap tin\n";
	cout << "3. Tim cac sinh vien co diem trung binh nho hon diem trung binh cua lop va ghi vao tap tin\n";
	cout << "4. Them sinh vien vao danh sach va cap nhat len tap tin\n";
	cout << "5. Xep loai sinh vien\n";
	cout << "6. Xuat danh sach sinh vien co xep loai\n";
	cout << "7. Tim va xuat cac sinh vien sinh nhat hom nay\n";
	cout << "=====================================\n";
}

int ChonMenu()
{
	int n = 0;
	cout << "\n\nMoi chon menu: ";
	cin >> n;
	if (n > 0 || n < 10)
		return n;
	else return ChonMenu();
}

void XuLyMenu()
{
	int chon = ChonMenu();
	int a = 5; int b = 6;
	switch (chon)
	{
	
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
		
		break;
	case 4:
	
		break;
	case 5:
		
		break;
	case 6:
		
		break;
	case 7:
	
		break;
	case 8:
		
		break;
	case 9:
		
		break;
	case 0:
		break;

	}
}