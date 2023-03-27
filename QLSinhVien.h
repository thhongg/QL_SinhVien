#pragma once
#include "sinhvien.h"
#include <string>
#include <vector>
using namespace std;

class QLSinhVien
{
private:
	vector<SinhVien> ds;
public:
	QLSinhVien();
	~QLSinhVien();

public:
	void input5SV();
	void writeFile(const string);
	void readFile(const string);
	void print();
	QLSinhVien findLowerAVG();
	void add(SinhVien, const string);
	void xepLoai();
	void printXepLoai();
	QLSinhVien findBirthday();
};

