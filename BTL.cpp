#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    float diemGPA;
    string xepLoai;
};


struct Node {
    SinhVien data;
    Node* prev;
    Node* next;
};


struct DoubleLinkedList {
    Node* head;
    Node* tail;
};


void khoiTaoDanhSach(DoubleLinkedList &list) {
    list.head = NULL;
    list.tail = NULL;
}


string phanLoaiHocLuc(float gpa) {
    if (gpa >= 3.6) return "Xuat sac";
    if (gpa >= 3.2) return "Gioi";
    if (gpa >= 2.5) return "Kha";
    if (gpa >= 2.0) return "Trung binh";
    return "Yeu";
}


Node* taoNode(SinhVien sv) {
    Node* pNode = new Node;
    if (pNode == NULL) return NULL;
    pNode->data = sv;
    pNode->prev = NULL;
    pNode->next = NULL;
    return pNode;
}
