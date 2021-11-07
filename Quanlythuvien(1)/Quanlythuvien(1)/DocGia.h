#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"DoHoa.h"
using namespace std;

struct datetime2 {
	int ngay;
	int thang;
	int nam;
}; typedef struct datetime2 DATETIME2;
struct docgia {
	int ma1;
	string name;
	DATETIME2 ngay;
}; typedef struct docgia DOCGIA;
struct node2 {
	DOCGIA data;
	node2* next;
}; typedef struct node2 NODE2;
struct list2 {
	node2* head;
	node2* tail;
}; typedef struct list2 LIST2;
void InitList2(LIST2& l);
NODE2* getNode2(DOCGIA s);
void AddHead2(LIST2& l, NODE2* p);
void doc_file_datetime2(ifstream& filein, DATETIME2& a);
void AddTail2(LIST2& l, NODE2* p);
void doc_1_ban_doc(ifstream& filein, DOCGIA& s);
void doc_all_ban_doc(ifstream& filein, NODE2* p, LIST2& l);
void giai_phong2(LIST2& l);
void xuat2(DOCGIA s);
void xuat_tat_ca_ban_doc(LIST2 l);
bool kiem_tra_ma_ban_doc(LIST2& l, NODE2* k, int& m);