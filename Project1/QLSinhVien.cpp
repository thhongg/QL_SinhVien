#include "QLSinhVien.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

QLSinhVien::QLSinhVien() {
	dsSinhVien = nullptr;
	soSinhVien = 0;
	isLoaded = false;
}

QLSinhVien::~QLSinhVien() {
	delete[] dsSinhVien;
}

void QLSinhVien::themSinhVien(SinhVien sv) {
	// Tạo mảng tạm mới với kích thước lớn hơn 1 đơn vị so với mảng cũ
	SinhVien* temp = new SinhVien[soSinhVien + 1];

	// Sao chép toàn bộ dữ liệu từ mảng cũ sang mảng mới
	for (int i = 0; i < soSinhVien; i++) {
		temp[i] = dsSinhVien[i];
	}

	// Thêm sinh viên mới vào cuối mảng
	temp[soSinhVien] = sv;

	// Xóa mảng cũ và cập nhật lại con trỏ và số lượng sinh viên
	delete[] dsSinhVien;
	dsSinhVien = temp;
	soSinhVien++;
}


void QLSinhVien::capNhatFile() {
	ofstream fout("sinhvien.txt");

	// Ghi số lượng sinh viên vào file đầu tiên
	fout << soSinhVien << endl;

	// Ghi thông tin từng sinh viên vào file
	for (int i = 0; i < soSinhVien; i++) {
		fout << dsSinhVien[i].toString() << endl;
	}

	fout.close();
}

void QLSinhVien::docDanhSach() {
	ifstream fin("sinhvien.txt");
	if (!fin.is_open()) {
		cout << "Khong the mo file!" << endl;
		return;
	}

	// Đọc số lượng sinh viên từ file
	fin >> soSinhVien;

	// Tạo mảng động chứa danh sách sinh viên
	dsSinhVien = new SinhVien[soSinhVien];

	// Đọc thông tin từng sinh viên từ file và lưu vào mảng
	for (int i = 0; i < soSinhVien; i++) {
		char* hoTen = new char[100];
		char* ngaySinh = new char[100];
		char* maSV = new char[100];
		float Marks[3];

		fin >> hoTen >> ngaySinh >> maSV >> Marks[0] >> Marks[1] >> Marks[2];
		dsSinhVien[i] = SinhVien(hoTen, ngaySinh, maSV, Marks);
	}

	fin.close();
	isLoaded = true;
}

void QLSinhVien::xuatDanhSach() {
	if (!isLoaded) {
		docDanhSach();
	}

	if (soSinhVien == 0) {
		cout << "Khong co sinh vien nao trong danh sach." << endl;
		return;
	}

	cout << "Danh sach sinh vien:" << endl;
	for (int i = 0; i < soSinhVien; i++) {
		cout << "STT " << i + 1 << ":" << endl;
		dsSinhVien[i].xuatThongTin();
	}
}


void QLSinhVien::timSinhVienYeu() {
	float trungBinhLop = 0;
	for (int i = 0; i < soSinhVien; i++) {
		trungBinhLop += dsSinhVien[i].tinhDiemTrungBinh();
	}
	trungBinhLop /= soSinhVien;

	cout << "Danh sach sinh vien yeu:" << endl;
	for (int i = 0; i < soSinhVien; i++) {
		if (dsSinhVien[i].tinhDiemTrungBinh() < trungBinhLop) {
			dsSinhVien[i].xuatThongTin();
		}
	}
}

void QLSinhVien::xepLoaiSinhVien() {
	for (int i = 0; i < soSinhVien; i++) {
		if (dsSinhVien[i].tinhDiemTrungBinh() >= 8)
			cout << "Loai Gioi " << endl;
		else if (dsSinhVien[i].tinhDiemTrungBinh() >= 7)
			cout << "Loai Kha " << endl;
		else if (dsSinhVien[i].tinhDiemTrungBinh() >= 5)
			cout << "Loai trung binh " << endl;
		dsSinhVien[i].xuatThongTin();
	}
}

void QLSinhVien::timSinhVienSinhTrongNgay() {
	time_t t = time(0);
	struct tm timePtr;
	localtime_s(&timePtr, &t);
	int day = timePtr.tm_mday;
	int month = timePtr.tm_mon + 1;

	cout << "Danh sach sinh vien sinh trong ngay " << day << "/" << month << ":" << endl;
	for (int i = 0; i < soSinhVien; i++) {
		if (dsSinhVien[i].sinhNhatTrongNgay(day, month)) {
			dsSinhVien[i].xuatThongTin();
		}
	}
}
