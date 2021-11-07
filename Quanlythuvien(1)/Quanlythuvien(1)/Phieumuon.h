#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"DoHoa.h"
#include <conio.h>
#include <ctime>
//#include "Sach.h"
using namespace std;

struct datetime1 {
	int ngay;
	int thang;
	int nam;
}; typedef struct datetime1 DATETIME1;
struct phieumuon {
	int sophieu;
	int madg;
	int masach;
	DATETIME1 ngaymuon;
	DATETIME1 ngaytra;
	int status;
}; typedef struct phieumuon PHIEUMUON;
struct node1 {
	PHIEUMUON data;
	struct node1* next;
}; typedef struct node1 NODE1;
struct list1 {
	NODE1* head;
	NODE1* tail;
};
typedef struct list1 LIST1;
void InitList1(LIST1& l);
//hàm khởi tạo node
NODE1* getNode1(PHIEUMUON s);
void AddHead1(LIST1& l, NODE1* p);
void AddTail1(LIST1& l, NODE1* p);
void quanly_phieumuon();
void doc_file_datetime1(ifstream& filein, DATETIME1& a);
void doc_1_phieu_muon(ifstream& filein, PHIEUMUON& s);
void doc_all_file_phieumuon(ifstream& filein, NODE1* p, LIST1& l);
void xuat1(PHIEUMUON s);
void giai_phong1(LIST1& l);
void xuat_tat_phieu_muon(LIST1& l);
void ghi_phieu_muon(ofstream& fileout, PHIEUMUON& s,LIST1& l);
void Muon_Sach(PHIEUMUON& s, int& n, int& m, LIST1& l, NODE1* p);
void xuatmenu1();
void tim_phieu_muon(LIST1& l, NODE1* p, int& n);
void ghi_all_phieu_muon(ofstream & filleout, LIST1 & l, NODE1 * p);
bool kiem_tra_phieu_muon(LIST1& l, NODE1* p, int& n);
void Tra_Sach(ofstream& fileout, LIST1& l, NODE1* p, int& n);
int dem(LIST1& l, NODE1* p, int& n);