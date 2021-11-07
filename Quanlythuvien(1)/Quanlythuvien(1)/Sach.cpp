#include"Sach.h"

void InitList(LIST& l) {
	l.head = NULL;
	l.tail = NULL;
}
NODE* getNode(SACH s) {
	NODE* p = new NODE();
	p->data = s;
	p->next = NULL;
	return p;
}
void AddHead(LIST& l, NODE* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void AddTail(LIST& l, NODE* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//Đọc file ngày tháng năm
void doc_file_datetime(ifstream& filein, DATETIME& a) {
	filein >> a.ngay;
	filein.seekg(1, 1);
	filein >> a.thang;
	filein.seekg(1, 1);
	filein >> a.nam;
	filein.seekg(1, 1);
}
//Hàm đọc dữ liệu sinh viên từ file
void doc_1_quyen_sach(ifstream& filein, SACH& s) {
	filein >> s.ma;
	filein.seekg(2, 1);
	getline(filein, s.ten, ',');//nhap chuoi
	filein.seekg(1, 1);
	getline(filein, s.nxb, ',');//nhap chuoi
	filein.seekg(1, 1);
	filein >> s.gia;
	filein.seekg(1, 1);
	filein >> s.nam;
	filein.seekg(1, 1);
	filein >> s.page;
	filein.seekg(1, 1);
	doc_file_datetime(filein, s.ngay);
	filein.seekg(1, 1);
	filein >> s.status;
	string x;
	getline(filein, x);

}
bool kiem_tra(NODE* p, LIST& l, SACH& s) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.ma == s.ma) {
			return false;
		}
	}
	return true;
}
void nhap_thong_tin_sach(LIST& l, NODE* p, NODE* q, ifstream& filein) {//can sua
	SACH s;
	string m;
	bool b = true;
	while (b) {
		filein.open("Sach1.txt", ios_base::in);
		getline(filein, m);
		doc_all_sach(filein, l, p);
		cout << "Nhap vao ma sach           : ";
		while (cin >> s.ma) {
			if (s.ma > 0) {
				break;
			}
			else {
				xuatmenu();
				textcolor(12);
				cout << "Ma sach phai lon hon 0" << endl;
				textcolor(7);
				cout << "Nhap vao ma sach: ";
			}
		}
		bool a = kiem_tra(q, l, s);
		if (a) {
			cin.ignore();
			cout << "Nhap vao ten sach      : ";
			getline(cin, s.ten);
			cout << "Nhap vao nha xuat ban  : ";
			getline(cin, s.nxb);
			cout << "Nhap vao gia           : ";
			cin >> s.gia;
			cout << "Nhap vao nam phat hanh : ";
			cin >> s.nam;
			cout << "Nhap vao trang sach    : ";
			cin >> s.page;
			cout << "Nhap ngay nhap kho     : ";
			cin >> s.ngay.ngay;
			cout << "Nhap thang nhap kho    : ";
			cin >> s.ngay.thang; 
			cout << "Nhap nam nhap kho      : ";
			cin >> s.ngay.nam;
			cout << "Nhap vao trang thai    : ";
			while (cin >> s.status) {
				if (s.status == 0) {
					break;
				}
				else {
					xuatmenu();
					textcolor(12);
					cout << "Tinh trang sach phai bang 0" << endl;
					textcolor(7);
					cout << "Nhap vao trang thai: ";
				}
			}
			p = getNode(s);
			AddTail(l, p);
			filein.close();
			b = false;
		}
		else {
			xuatmenu();
			textcolor(12);
			cout << "Ma sach bi trung";
			textcolor(7);
			cout << endl;
			//giai_phong(l);
			system("pause");
			filein.close();
			break;
		}
	}
}
void Hoan_vi_2sach(LIST& l, NODE* p, NODE* q) {
	node* t = new node();
	t->data = q->data;
	q->data = p->data;
	p->data = t->data;
}
void sap_xep(NODE* p, LIST& l) {
	p = l.head;
	node* tmp = l.head;//nho phai khoi tao gia tri cho node
	//xap xep theo thu tu can hai vong lap for
	for (; p != NULL; p = p->next)
		for (node* q = p->next; q != NULL; q = q->next) {
			if (p->data.ma > q->data.ma) {
				Hoan_vi_2sach(l, p, q);
			}

		}
}

void doc_all_sach(ifstream& filein, LIST& l, NODE* p) {
	while (!filein.eof()) {
		SACH s;
		//Đọc thông tin 1 quyển sách
		doc_1_quyen_sach(filein, s);
		//Khởi tạo node
		p = getNode(s);
		if (l.head == NULL) {
			AddHead(l, p);
		}
		else {
			AddTail(l, p);

		}
	}
	sap_xep(p, l);
}

void xuat(SACH s) {
	textcolor(243);
	cout << setw(10) << left << s.ma << setw(20) << left << s.ten << setw(20) << left << s.nxb;
	cout << setw(10) << left << s.gia << setw(6) << left << s.nam << setw(10) << left << s.page;
	cout << setw(18) << left << s.status << setw(2) << s.ngay.ngay << "/" << s.ngay.thang << "/" << s.ngay.nam <<"          "<< endl;
	textcolor(7);
}
void xuat_tat_ca_sach(list l) {

	for (NODE* p = l.head; p != NULL; p = p->next) {
		xuat(p->data);
	}
	//giai_phong(l);
}
//Hàm giải phóng vùng nhớ cho danh sách liên kết
void giai_phong(LIST& l) {
	NODE* p = NULL;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete(p);
	}
}

void xoa(LIST& l, int& n) {
	NODE* p = l.head;
	NODE* q = l.head->next;
	if (l.head->data.ma == n) {
		node* k = l.head;
		l.head = k->next;
		delete k;
	}
	else
		while (q != NULL) {
			if (q->data.ma == n) {
				p->next = q->next;
				delete q;
				q = p->next;
			}
			else {
				p = q;
				q = q->next;
			}
		}

}
void ghi_sau_xoa(NODE* p, ofstream& fileout, LIST& l) {

	for (p = l.head; p != NULL; p = p->next) {
		ghi_11_quyen_sach(fileout, p->data);
	}
	giai_phong(l);
}
void ghi_11_quyen_sach(ofstream& fileout, SACH& s) {
	fileout << endl;
	fileout << s.ma << ", ";
	fileout << s.ten << ", ";
	fileout << s.nxb << ", ";
	fileout << s.gia << ", ";
	fileout << s.nam << ", ";
	fileout << s.page << ", ";
	fileout << s.ngay.ngay << "/" << s.ngay.thang << "/" << s.ngay.nam << ", ";
	fileout << s.status;
}
bool kiem_tra_masach(LIST& l, NODE* p, int& n) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.ma == n) {
			if (p->data.status == 0) {
				return true;
			}
		}
	}
	return false;
}
void cap_nhat_tinh_trang_sach_muon(LIST& l, NODE* p, int& n) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.ma == n) {
			p->data.status = 1;
		}
	}
}
void cap_nhat_tinh_trang_sach_tra(LIST& l, NODE* p, int& n) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.ma == n) {
			p->data.status = 0;
		}
	}
}
void xuatmenu() {
	system("cls");
	textcolor(245);
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
	cout << "* Lua chon chuc nang:                                                                                                                *" << endl;
	cout << "* 1.Xem thong tin sach                                                                                                               *" << endl;
	cout << "* 2.Them sach                                                                                                                        *" << endl;
	cout << "* 3.Xoa sach                                                                                                                         *" << endl;
	cout << "* 0.De thoat                                                                                                                         *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
	textcolor(7);
	cout << "\n\n\n\n";
}
bool kiem_tra_sach_xoa(LIST& l, NODE* p, int& n) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.ma == n) {
			return true;
		}
	}
	return false;
}
bool kiem_tra_sach_xoa_tinh_trang(LIST& l, NODE* p, int& n) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.ma == n) {
			if (p->data.status == 0) {
				return true;
			}
		}
	}
	return false;
}
void quanly_sach() {
	int chon1;
	string x;
	LIST a;
	SACH s;
	int n;
	NODE* p = NULL;
	NODE* q = new NODE();
	InitList(a);
	ifstream filein;
	ofstream fileout;
	bool menuconsach = true;
	while (menuconsach == true) {
		xuatmenu();
		cout << "Nhap vao lua chon: ";
		cin >> chon1;
		switch (chon1)
		{
		case 1:
			textcolor(244);
			cout << "\n\n\t\t\t\t\tThong tin sach co trong thu vien\n\n";
			textcolor(7);
			textcolor(245);
			cout << setw(10) << left << "Ma sach" << setw(20) << left << "Ten sach" << setw(20) << left << "Nha xuat ban";
			cout << setw(10) << left << "Gia" << setw(6) << left << "Nam" << setw(10) << left << "Trang"
				<< setw(18) << left << "Trang thai" << setw(20) << left << "Ngay nhap kho" << endl;
			textcolor(7);
			filein.open("Sach1.txt", ios_base::in);
			getline(filein, x);
			doc_all_sach(filein, a, p);
			xuat_tat_ca_sach(a);
			giai_phong(a);
			filein.close();
			system("pause");
			break;
		case 2:
			xuatmenu();
			nhap_thong_tin_sach(a, p, q, filein);
			fileout.open("Sach1.txt", ios_base::out);
			sap_xep(p, a);
			ghi_sau_xoa(p, fileout, a);
			fileout.close();
			break;
		case 3:
			while (true) {
				xuatmenu();
				filein.open("Sach1.txt", ios_base::in);
				getline(filein, x);
				doc_all_sach(filein, a, p);
				cout << "Nhap vao ma sach can xoa: ";
				cin >> n;
				bool b;
				b = kiem_tra_sach_xoa(a, p, n);
				filein.close();
				if (b) {
					giai_phong(a);
					filein.open("Sach1.txt", ios_base::in);
					getline(filein, x);
					doc_all_sach(filein, a, p);
					bool g = kiem_tra_sach_xoa_tinh_trang(a, p, n);
					filein.close();
					if (g) {
						xoa(a, n);
						fileout.open("Sach1.txt", ios_base::out);
						ghi_sau_xoa(p, fileout, a);
						fileout.close();
						filein.close();
						system("pause");
						break;
					}
					else {
						xuatmenu();
						textcolor(12);
						cout << "Sach dang duoc muon" << endl;
						textcolor(7);
						giai_phong(a);
						system("pause");
						break;
					}
				}
				else {
					xuatmenu();
					textcolor(12);
					cout << "Ma sach khong ton tai" << endl;
					textcolor(7);
					giai_phong(a);
					system("pause");
					break;
				}

			}
			break;
		case 0:
			giai_phong(a);
			menuconsach = false;
			break;
		default:
			textcolor(12);
			cout << "Vui long nhap lai";
			textcolor(7);
			cout << endl;
			system("pause");
		}
	}

}