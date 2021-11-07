#pragma warning(disable:4996)
#include"Phieumuon.h"
#include "Sach.h"
#include"DocGia.h"
void InitList1(LIST1& l) {
	l.head = l.tail = NULL;
}
NODE1* getNode1(PHIEUMUON s) {
	NODE1* p = new NODE1();
	p->data = s;
	p->next = NULL;
	return p;
}
void AddHead1(LIST1& l, NODE1* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}
void doc_file_datetime1(ifstream& filein, DATETIME1& a) {
	filein >> a.ngay;
	filein.seekg(1, 1);
	filein >> a.thang;
	filein.seekg(1, 1);
	filein >> a.nam;
	filein.seekg(1, 1);
}

void doc_1_phieu_muon(ifstream& filein, PHIEUMUON& s) {
	filein >> s.sophieu;
	filein.seekg(1, 1);
	filein >> s.madg;
	filein.seekg(1, 1);
	filein >> s.masach;
	filein.seekg(2, 1);
	doc_file_datetime1(filein, s.ngaymuon);
	filein.seekg(1, 1);
	doc_file_datetime1(filein, s.ngaytra);
	filein.seekg(1, 1);
	filein >> s.status;
	string x;
	getline(filein, x);
}
void doc_all_file_phieumuon(ifstream& filein, NODE1* p, LIST1& l) {
	while (!filein.eof()) {
		PHIEUMUON s;
		doc_1_phieu_muon(filein, s);
		p = getNode1(s);
		AddTail1(l, p);
	}
}
void xuat_tat_phieu_muon(LIST1& l) {

	for (NODE1* p = l.head; p != NULL; p = p->next) {
		xuat1(p->data);
	}
	//giai_phong(l);
}
void AddTail1(LIST1& l, NODE1* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}
void xuatmenu1() {
	system("cls");
	textcolor(243);
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
	cout << "* Lua chon chuc nang:                                                                                                                *" << endl;
	cout << "* 1.Xem thong phieu muon                                                                                                             *" << endl;
	cout << "* 2.Muon sach                                                                                                                        *" << endl;
	cout << "* 3.Tra sach                                                                                                                         *" << endl;
	cout << "* 0.De thoat                                                                                                                         *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
	textcolor(7);
	cout << "\n\n\n\n";
}
void xuat1(PHIEUMUON s) {
	textcolor(246);
	cout << setw(10) << left << s.sophieu << setw(20) << left << s.madg << setw(20) << left << s.masach;
	cout << setw(18) << left << s.status << setw(2) << s.ngaymuon.ngay << "/" << s.ngaymuon.thang << "/" << s.ngaymuon.nam << "         ";
	cout << setw(2) << s.ngaytra.ngay << "/" << s.ngaytra.thang << "/" << s.ngaytra.nam << endl;
	textcolor(7);
}
void giai_phong1(LIST1& l) {
	NODE1* p = NULL;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete(p);
	}
}

void quanly_phieumuon() {
	LIST1 l;
	LIST2 i;
	LIST e;
	SACH z;
	int n, m, u, o;
	NODE* p = NULL;
	NODE1* v = NULL;
	NODE2* k = NULL;
	PHIEUMUON s;
	string x;
	InitList(e);
	InitList1(l);
	InitList2(i);
	ifstream filein;
	ofstream fileout;
	bool a;
	bool b;
	bool c;
	int chon2;
	bool menu_phieu_muon = true;
	while (menu_phieu_muon) {
		xuatmenu1();
		cout << "Nhap vao lua chon: ";
		cin >> chon2;
		switch (chon2)
		{
		case 1://thong tin phieu muon
			xuatmenu1();
			textcolor(244);
			cout << "\n\n\t\t\t\tThong tin phieu muon co trong thu vien\n\n";
			textcolor(7);
			textcolor(243);
			cout << setw(10) << left << "Sophieu" << setw(20) << left << "Ma doc gia" << setw(20) << left << "Ma sach";
			cout << setw(18) << left << "Trang thai" << setw(3) << "Ngay muon" << "         ";
			cout << left << setw(7) << "Ngay tra   " << endl;
			textcolor(7);
			filein.open("Phieumuon.txt", ios_base::in);
			getline(filein, x);
			doc_all_file_phieumuon(filein, v, l);
			xuat_tat_phieu_muon(l);
			giai_phong1(l);
			filein.close();
			system("pause");
			break;
		case 2://muon
			xuatmenu1();
			while (true) {
				xuatmenu1();
				filein.open("Sach1.txt", ios_base::in);
				getline(filein, x);
				doc_all_sach(filein, e, p);
				cout << "Nhap vao ma sach: ";
				cin >> n;
				a = kiem_tra_masach(e, p, n);
				filein.close();
				if (a) {
					filein.open("DocGia.txt", ios_base::in);
					getline(filein, x);
					doc_all_ban_doc(filein, k, i);
					xuatmenu1();
					cout << "Nhap vao ma ban doc: ";
					cin >> m;
					b = kiem_tra_ma_ban_doc(i, k, m);
					filein.close();
					if (b) {
						filein.open("Phieumuon.txt", ios_base::in);
						getline(filein, x);
						doc_all_file_phieumuon(filein, v, l);
						fileout.open("Sach1.txt", ios_base::out);
						cap_nhat_tinh_trang_sach_muon(e, p, n);
						ghi_sau_xoa(p, fileout, e);//giai phong vung nho
						fileout.close();
						Muon_Sach(s, n, m, l, v);
						fileout.open("Phieumuon.txt", ios_base::app);
						ghi_phieu_muon(fileout, s, l);
						fileout.close();
						giai_phong1(l);
						filein.close();
						giai_phong(e);
						break;
					}
					else {
						textcolor(12);
						cout << "Ma ban doc khong ton tai";
						textcolor(7);
						giai_phong1(l);
						giai_phong(e);
						system("pause");
						break;
					}
				}
				else {
					bool x = kiem_tra_sach_xoa(e, p, n);
					if (x) {
						xuatmenu1();
						textcolor(12);
						cout << "Sach da duoc muon" << endl;
						textcolor(7);
						giai_phong1(l);
						giai_phong(e);
						system("pause");

					}
					else {
						xuatmenu();
						textcolor(12);
						cout << "Ma sach khong ton tai" << endl;
						textcolor(7);
						giai_phong(e);
						system("pause");
						break;
					}
					break;

				}
			}
			break;
		case 3://tra phieu muon
			while (true) {
				xuatmenu1();
				filein.open("Phieumuon.txt", ios_base::in);
				getline(filein, x);
				doc_all_file_phieumuon(filein, v, l);
				cout << "Nhap vao so phieu muon: ";
				cin >> u;
				c = kiem_tra_phieu_muon(l, v, u);
				filein.close();
				if (c) {
					xuatmenu1();
					filein.open("Sach1.txt", ios_base::in);
					getline(filein, x);
					doc_all_sach(filein, e, p);
					fileout.open("Sach1.txt", ios_base::out);
					o = dem(l, v, u);
					cap_nhat_tinh_trang_sach_tra(e, p, o);
					ghi_sau_xoa(p, fileout, e);//giai phong vung nho
					fileout.close();
					Tra_Sach(fileout, l, v, u);
					filein.close();
					giai_phong1(l);
					break;
				}
				else {
					xuatmenu1();
					textcolor(12);
					cout << "Phieu muon khong hop le " << endl;
					textcolor(7);
					system("pause");
					giai_phong1(l);
					break;
				}
				filein.close();
			}
			break;
		case 0:
			menu_phieu_muon = false;
			break;
		default:
			break;
		}
	}
}
int dem(LIST1& l, NODE1* p, int& n) {
	int dem = 0;
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.sophieu == n) {
			dem = p->data.masach;
			return dem;
		}
	}
}
void ghi_phieu_muon(ofstream& fileout, PHIEUMUON& s, LIST1& l) {
	fileout << endl;
	fileout << s.sophieu << ", ";
	fileout << s.madg << ", ";
	fileout << s.masach << ", ";
	fileout << s.ngaymuon.ngay << "/" << s.ngaymuon.thang << "/" << s.ngaymuon.nam << ", ";
	fileout << s.ngaytra.ngay << "/" << s.ngaytra.thang << "/" << s.ngaytra.nam << ", ";
	fileout << s.status;
}
void Muon_Sach(PHIEUMUON& s, int& n, int& m, LIST1& l, NODE1* p) {
	time_t now;
	struct tm t;
	now = time(NULL);
	t = *localtime(&now);
	int dem = 0;
	for (p = l.head; p != NULL; p = p->next) {
		dem++;
	}
	s.sophieu = dem + 1;
	s.madg = m;
	s.masach = n;
	s.ngaymuon.ngay = t.tm_mday;
	s.ngaymuon.thang = 1 + t.tm_mon;
	s.ngaymuon.nam = 1900 + t.tm_year;
	s.ngaytra.ngay = 7 + t.tm_mday;
	s.ngaytra.thang = 1 + t.tm_mon;
	s.ngaytra.nam = 1900 + t.tm_year;
	s.status = 1;
}
bool kiem_tra_phieu_muon(LIST1& l, NODE1* p, int& n) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.sophieu == n) {
			if (p->data.status != 0) {
				return true;
			}
		}
	}
	return false;
}
void Tra_Sach(ofstream& fileout, LIST1& l, NODE1* p, int& n) {
	tim_phieu_muon(l, p, n);
	fileout.open("Phieumuon.txt", ios_base::out);
	ghi_all_phieu_muon(fileout, l, p);
	fileout.close();
	giai_phong1(l);
}
void tim_phieu_muon(LIST1& l, NODE1* p, int& n) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.sophieu == n) {
			p->data.status = 0;
		}
	}
}
void ghi_all_phieu_muon(ofstream& filleout, LIST1& l, NODE1* p) {
	for (p = l.head; p != NULL; p = p->next) {
		ghi_phieu_muon(filleout, p->data, l);
	}
}