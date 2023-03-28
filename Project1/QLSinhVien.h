#pragma once
#include "SinhVien.h"
class QLSinhVien {
private:
    SinhVien* dsSinhVien; // Mảng động chứa danh sách sinh viên
    int soSinhVien; // Số lượng sinh viên trong danh sách
    bool isLoaded; // Biến đánh dấu xem danh sách đã được tải từ file chưa

public:
    QLSinhVien(); // Constructor mặc định
    ~QLSinhVien(); // Destructor
    void themSinhVien(SinhVien); // Thêm một sinh viên mới vào danh sách
    void capNhatFile(); // Cập nhật danh sách sinh viên vào file
    void docDanhSach(); // Đọc danh sách sinh viên từ file
    void xuatDanhSach(); // Xuất danh sách sinh viên
    void timSinhVienYeu(); // Tìm và xuất danh sách sinh viên có điểm trung bình dưới trung bình lớp
    void xepLoaiSinhVien(); // Xếp loại sinh viên và xuất danh sách sinh viên có thông tin xếp loại
    void timSinhVienSinhTrongNgay(); // Tìm và xuất danh sách sinh viên có sinh nhật trong ngày hiện tại
};
