#pragma once
class SinhVien {
private:
    char* hoTen; // Họ và tên
    char* maSV; // Mã số sinh viên
    char* ngaySinh; // Ngày sinh
    float marks[3]; // Mảng điểm: bài tập, thi giữa kỳ, thi cuối kỳ
    float stdAvg; // Điểm trung bình

public:
    SinhVien(); // Constructor mặc định
    SinhVien(char* hoTen, char* maSV, char* ngaySinh, float* marks); // Constructor có tham số
    SinhVien(const SinhVien& sv); // Constructor sao chép
    ~SinhVien(); // Destructor
    SinhVien& operator=(const SinhVien& sv); // Toán tử gán bằng
    void nhapThongTin(); // Nhập thông tin sinh viên
    void xuatThongTin(); // Xuất thông tin sinh viên
    void tinhDiemTrungBinh(); // Tính điểm trung bình
};
