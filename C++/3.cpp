#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include<sstream>
#include<iomanip>

using namespace std;

class NganHang
{
protected:
	string soTaiKhoan;
	string hoTen;
	string dayOpen;
	int soDu;
public:
	void setSoTaiKhoan(string);
	string getSoTaiKhoan();
	void setHoTen(string);
	string getHoTen();
	void setDayOpen(string);
	string getDayOpen();
	void setSoDu(int);
	int getSoDu();
	void nhapThongTin();
	void showThongTin();
	bool ktraSoTK(string);
	bool ktraHoTen(string);
	//bool ktraDayOpen(int a, int b, int c);
	//string chuanHoaDayOpen(int a, int b, int c);
	string ktraDayOpen1(string);
	//bool cmp(NganHang, NganHang);
};

void NganHang::setSoTaiKhoan(string in)
{
	soTaiKhoan = in;
}

string NganHang::getSoTaiKhoan()
{
	return soTaiKhoan;
}

void NganHang::setHoTen(string im)
{
	hoTen = im;
}

string NganHang::getHoTen()
{
	return hoTen;
}

void NganHang::setDayOpen(string ii)
{
	dayOpen = ii;
}

string NganHang::getDayOpen()
{
	return dayOpen;
}

void NganHang::setSoDu(int o)
{
	soDu = o;
}

int NganHang::getSoDu()
{
	return soDu;
}

void NganHang::nhapThongTin()
{
	cout << "nhap so tai khoan: ";
	cin >> soTaiKhoan;
	while (ktraSoTK(soTaiKhoan) == false)
	{
		cout << "nhap lai so nguyen duong 10 chu so" << endl;
		cin.ignore();
		cin >> soTaiKhoan;
	}
	cout << "nhap ho va ten: ";
	cin.ignore();
	getline(cin, hoTen);
	while (ktraHoTen(hoTen) == false)
	{
		cout << "nhap ten khong qua 40 ki tu" << endl;
		cin.ignore();
		getline(cin, hoTen);
	}
	cout << "nhap ngay mo tai khoan: ";
	cin >> dayOpen;
	ktraDayOpen1(dayOpen);
	cout << "nhap so du: ";
	cin >> soDu;
	while (soDu < 0)
	{
		cout << "nhap so du la so nguyen duong";
		cin >> soDu;
	}
}

void NganHang::showThongTin()
{
	cout << "so tai khoan: " << getSoTaiKhoan();
	cout << "\nHo va Ten: " << getHoTen();
	cout << "\nNgay mo tai khoan: " << getDayOpen();
	cout << "\nSo du: " << getSoDu();
}

bool NganHang::ktraSoTK(string a)
{
	regex pattern("^[0-9]\\d{9}$");
	return regex_match(a, pattern);
}

bool NganHang::ktraHoTen(string b)
{
	regex pattern("^(.{1,40})$");
	return regex_match(b, pattern);
}

//string NganHang::chuanHoaDayOpen(int a,int b,int c)
//{
//	stringstream ss;
//
//	ss << setw(2) << setfill('0') << a << "/";
//	ss << setw(2) << setfill('0') << b << "/";
//	ss << c;
//	return ss.str();
//}

//bool NganHang::ktraDayOpen(int a, int b, int c)
//{
//	if (c < 0)
//	{
//		return false;
//	}
//	if (b < 1 || b>12)
//	{
//		return false;
//	}
//	int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	if (a<1 || a>day[b])
//	{
//		return false;
//	}
//}

string NganHang::ktraDayOpen1(string g)
{
	if (g[2] != '/')
		g = "0" + g;
	if (g[5] != '/')
		g.insert(3, "0");
	return g;
}

//bool NganHang::cmp(NganHang a, NganHang b)
//{
//	return a.getSoDu() > b.getSoDu();
//}

class DoanhNghiep : public NganHang
{
protected:
	string maSoThue;
public:
	void setMaSoThue(string);
	string getMaSoThue();
	void inputDN();
	void showDN();
	bool checkMST(string);
};

void DoanhNghiep::setMaSoThue(string j)
{
	maSoThue = j;
}

string DoanhNghiep::getMaSoThue()
{
	return maSoThue;
}

void DoanhNghiep::inputDN()
{
	NganHang::nhapThongTin();
	cout << "nhap ma so thue: ";
	cin.ignore();
	getline(cin, maSoThue);
	while (checkMST(maSoThue) == false)
	{
		cout << "nhap lai dung 10 ki tu so" << endl;
		cin.ignore();
		getline(cin, maSoThue);
	}
	cout << "da nhap xong!" << endl;
}

void DoanhNghiep::showDN()
{
	NganHang::showThongTin();
	cout << "Ma so thue: " << getMaSoThue() << endl;
}

bool DoanhNghiep::checkMST(string a)
{
	regex pattern("^[0-9]\\d{10}$");
	return  regex_match(a, pattern);
}

class CaNhan :public NganHang
{
protected:
	string cccd;
public:
	void setCCCD(string);
	string getCCCD();
	void inputCN();
	void showCN();
	bool checkCC(string);
};

void CaNhan::setCCCD(string u)
{
	cccd = u;
}

string CaNhan::getCCCD()
{
	return cccd;
}

void CaNhan::inputCN()
{
	NganHang::nhapThongTin();
	cout << "Nhap so cccd: ";
	cin.ignore();
	getline(cin, cccd);
	while (checkCC(cccd) == false)
	{
		cout << "nhap cccd co dung 12 chu so: " << endl;
		cin.ignore();
		getline(cin, cccd);
	}
	cout << "da nhap xong!" << endl;
}

void CaNhan::showCN()
{
	NganHang::showThongTin();
	cout << "So CCCD: " << getCCCD() << endl;
}

bool CaNhan::checkCC(string a)
{
	regex pattern("d{12}$");
	return regex_match(a, pattern);
}

void QuanLyKhachHang()
{
	vector<DoanhNghiep> dn;
	vector<CaNhan> cn;
	vector<NganHang> NH;
	NganHang nh;
	CaNhan tkcn;
	DoanhNghiep tkdn;

	int n;

	cout << "---------------------------Menu-------------------------" << endl;
	cout << "1. Nhap thong tin khach hang." << endl;
	cout << "2. In danh sach khach hang ca nhan." << endl;
	cout << "3. In danh sach khach hang doanh nghiep." << endl;
	cout << "4. Tim khach hang theo so tai khoan." << endl;
	cout << "5. Sap xep so du giam dan cua khach hang." << endl;
	cout << "6. Xoa thong tin khach hang theo so tai khoan." << endl;
	while (true)
	{
		cout << "nhap lua chon: ";cin >> n;
		if (n == 1)
		{
			int m, p;
			cout << "nhap so luong: ";cin >> m;
			while (m--)
			{
				cout << "Nhap 1: Tai khoan ca nhan" << endl;
				cout << "Nhap 2: Tai khoan doanh nghiep" << endl;
				cin >> p;
				if (p == 1)
				{
					tkcn.inputCN();	
					cn.push_back(tkcn);
					NH.push_back(tkcn);
				}
				if (p == 2)
				{
					tkdn.inputDN();
					dn.push_back(tkdn);
					NH.push_back(tkdn);
				}
				if (p != 1 && p != 2)
				{
					cout << "nhap 1 hoac 2!" << endl;
					cin >> p;
					if (p == 1)
					{
						tkcn.inputCN();
						cn.push_back(tkcn);
						NH.push_back(tkcn);
					}
					if (p == 2)
					{
						tkdn.inputDN();
						dn.push_back(tkdn);
						NH.push_back(tkdn);
					}
				}
			}
		}
		if (n == 2)
		{
			for (auto x : cn)
			{
				x.showCN();
			}
		}
		if (n == 3)
		{
			for (auto x : dn)
			{
				x.showDN();
			}
		}
		if (n == 4)
		{
			string a;
			cout << "nhap so tai khoan muon tim kiem: ";
			cin.ignore();
			getline(cin, a);
			for (auto x : dn)
			{
				if (a == x.getSoTaiKhoan())
				{
					x.showDN();
				}
			}
			for (auto y : cn)
			{
				if (a == y.getSoTaiKhoan())
				{
					y.showCN();
				}
			}
		}
		/*if (n == 5)
		{
			sort(NH.begin(), NH.end());
			for (NganHang a : NH)
			{
				a.showThongTin();
			}
		}*/
	}
}

int main()
{
	QuanLyKhachHang();
	return 0;
}
