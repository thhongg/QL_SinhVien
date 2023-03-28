#include "SinhVien.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
SinhVien::SinhVien() {
    hoTen = nullptr;
    maSV = nullptr;
    ngaySinh = nullptr;
    marks[0] = 0;
    marks[1] = 0;
    marks[2] = 0;
}

SinhVien::SinhVien(char* hoTen, char* maSV, char* ngaySinh, float* marks) {
    this->hoTen = new char[strlen(hoTen) + 1];
    strcpy_s(this->hoTen, 100, hoTen);
    this->maSV = new char[strlen(maSV) + 1];
    strcpy_s(this->maSV, 100, maSV);
    this->ngaySinh = new char[strlen(ngaySinh) + 1];
    strcpy_s(this->ngaySinh, 11, ngaySinh);
    this->marks[0] = marks[0];
    this->marks[1] = marks[1];
    this->marks[2] = marks[2];
}

SinhVien::SinhVien(const SinhVien& sv) {
    hoTen = new char[strlen(sv.hoTen) + 1];
    strcpy_s(hoTen, 100, sv.hoTen);
    maSV = new char[strlen(sv.maSV) + 1];
    strcpy_s(maSV, 100, sv.maSV);
    ngaySinh = new char[strlen(sv.ngaySinh) + 1];
    strcpy_s(ngaySinh, 11, sv.ngaySinh);
    marks[0] = sv.marks[0];
    marks[1] = sv.marks[1];
    marks[2] = sv.marks[2];
}

SinhVien::~SinhVien() {
    if (hoTen != nullptr) delete[] hoTen;
    if (maSV != nullptr) delete[] maSV;
    if (ngaySinh != nullptr) delete[] ngaySinh;
}

SinhVien& SinhVien::operator=(const SinhVien& sv) {
    if (this != &sv) {
        if (hoTen != nullptr) delete[] hoTen;
        if (maSV != nullptr) delete[] maSV;
        if (ngaySinh != nullptr) delete[] ngaySinh;
        hoTen = new char[strlen(sv.hoTen) + 1];
        strcpy_s(hoTen, 100, sv.hoTen);
        maSV = new char[strlen(sv.maSV) + 1];
        strcpy_s(maSV, 100, sv.maSV);
        ngaySinh = new char[strlen(sv.ngaySinh) + 1];
        strcpy_s(ngaySinh, 100, sv.ngaySinh);
        marks[0] = sv.marks[0];
        marks[1] = sv.marks[1];
        marks[2] = sv.marks[2];
    }
    return *this;
}

void SinhVien::nhapThongTin() {
    hoTen = new char[100];
    maSV = new char[10];
    ngaySinh = new char[11];
    cout << "Nhap ho va ten: ";
    cin.ignore();
    cin.getline(hoTen, 100);
    cout << "Nhap ma sinh vien: ";
    cin.getline(maSV, 10);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin.getline(ngaySinh, 11);
    cout << "Nhap diem bai tap: ";
    cin >> marks[0];
    cout << "Nhap diem thi giua ky: ";
    cin >> marks[1];
    cout << "Nhap diem thi cuoi ky: ";
    cin >> marks[2];
}

void SinhVien::xuatThongTin() {
    cout << "Ho va ten: " << hoTen << endl;
    cout << "Ma sinh vien: " << maSV << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Diem bai tap: " << marks[0] << endl;
    cout << "Diem thi giua ky: " << marks[1] << endl;
    cout << "Diem thi cuoi ky: " << marks[2] << endl;
    cout << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
}

float SinhVien::tinhDiemTrungBinh() {
    return float((marks[0] + marks[1] + marks[2]) / 3.0);
}

bool SinhVien::sinhNhatTrongNgay(int day, int month) {

    char* token = strtok_s(ngaySinh, "/", &ngaySinh);
    int ngay = atoi(token);
    token = strtok_s(NULL, "/", &ngaySinh);
    int thang = atoi(token);


    if (day == ngay && month == thang) {
        return true;
    }

    return false;
}

char* SinhVien::toString() {
    char* result = new char[100];

    sprintf_s(result, 300, "%s %s %s %f %f %f", hoTen, maSV, ngaySinh, marks[0], marks[1], marks[2]);

    return result;
}