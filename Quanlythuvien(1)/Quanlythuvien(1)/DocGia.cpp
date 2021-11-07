#include"DocGia.h"
void InitList2(LIST2& l) {
	l.head = l.tail = NULL;
}
NODE2* getNode2(DOCGIA s) {
	NODE2* p = new NODE2();
	p->data = s;
	p->next = NULL;
	return p;
}
void AddHead2(LIST2& l, NODE2* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}
void doc_file_datetime2(ifstream& filein, DATETIME2& a) {
	filein >> a.ngay;
	filein.seekg(1, 1);
	filein >> a.thang;
	filein.seekg(1, 1);
	filein >> a.nam;
	filein.seekg(1, 1);
}
void AddTail2(LIST2& l, NODE2* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void doc_1_ban_doc(ifstream& filein, DOCGIA& s) {
	filein >> s.ma1;
	filein.seekg(2, 1);
	getline(filein, s.name, ',');
	filein.seekg(1, 1);
	doc_file_datetime2(filein, s.ngay);
	string x;
	getline(filein, x);
}
void doc_all_ban_doc(ifstream& filein, NODE2* p, LIST2& l) {
	while (!filein.eof()) {
		DOCGIA s;
		doc_1_ban_doc(filein, s);
		p = getNode2(s);
		AddTail2(l, p);
	}
}
void giai_phong2(LIST2& l) {
	NODE2* p = NULL;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete(p);
	}
}
void xuat2(DOCGIA s) {
	textcolor(12);
	cout << s.ma1 << " " << s.ngay.ngay;
}
void xuat_tat_ca_ban_doc(LIST2 l) {

	for (NODE2* p = l.head; p != NULL; p = p->next) {
		xuat2(p->data);
	}
	//giai_phong(l);
}
bool kiem_tra_ma_ban_doc(LIST2& l, NODE2* k, int& m) {
	for (k = l.head; k != NULL; k = k->next) {
		if (k->data.ma1 == m) {
			return true;
		}
	}
	return false;
}