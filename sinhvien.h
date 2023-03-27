
#include <iostream>
using namespace std;

struct Marks {
	double baiTap;
	double giuaKy;
	double cuoiKy;
};

class SinhVien {
private:
	char* hoten;
	char* id;
	Marks diem;
	char* date;
public:
	SinhVien();
	~SinhVien();
	// overload istream/ostream operator
	friend ostream& operator << (ostream& out, SinhVien& std);
	friend istream& operator >> (istream& in, SinhVien& std);
	// lay diem trung binh
	double getAvg();
	void input_std(SinhVien& std);
	char XepLoai();
	string getDate;
};




