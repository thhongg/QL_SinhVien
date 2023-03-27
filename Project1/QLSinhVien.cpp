#include "QLSinhVien.h"
#include <ctime>

void QLSinhVien::timSinhVienYeu() {
	//tìm điểm trung bình lớp
	float avr = 0;
	float sum = 0;
	for (int i = 0; i < soSinhVien; i++) {
		sum += dsSinhVien[i].tinhDiemTrungBinh();
	}
	avr = sum / soSinhVien;

	//tạo danh sách sinh viên mới để lưu trữ
	QLSinhVien Yeu;
	for (int i = 0; i < soSinhVien; i++) {
		if (dsSinhVien[i].tinhDiemTrungBinh() < avr) {
			Yeu.themSinhVien(dsSinhVien[i]);
		}
	}


	//xuất danh sách sinh viên
	Yeu.xuatDanhSach();
}

void xepLoaiSinhVien() {
	//Y: < 5.0
	//T: < 6.5
	//K: < 8.0
	//G: >= 8.0

	//Tao 4 ds Y T K G chua cac sinh vien y t k g
	//xuat 4 ds theo thu tu
}

void timSinhVienSinhTrongNgay() {
	//tim ngay va thang hien tai
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int currentday = timeinfo->tm_mday;
	int currentmonth = timeinfo->tm_mon;

	//so sanh va lap danh sach
	//xuat ds

}