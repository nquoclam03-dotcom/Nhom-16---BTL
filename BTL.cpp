void themCuoi(DoubleLinkedList &list, SinhVien sv) {
    Node* pNode = taoNode(sv);
    if (pNode == NULL) return;
    if (list.head == NULL) { 
        list.head = list.tail = pNode;
    } else {
        list.tail->next = pNode;
        pNode->prev = list.tail;
        list.tail = pNode;
    }
}

Node* timKiemTuyenTinh(DoubleLinkedList list, string maSV) {
    for (Node* k = list.head; k != NULL; k = k->next) {
        if (k->data.maSV == maSV) return k;
    }
    return NULL;
}

void xoaSinhVien(DoubleLinkedList &list, string maSV) {
    Node* p = timKiemTuyenTinh(list, maSV);
    if (p == NULL) {
        cout << "Khong tim thay sinh vien ma: " << maSV << endl;
        return;
    }
    
    if (p == list.head) {
        list.head = list.head->next;
        if (list.head != NULL) list.head->prev = NULL;
        else list.tail = NULL;
    } else if (p == list.tail) {
        list.tail = list.tail->prev;
        list.tail->next = NULL;
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    delete p;
    cout << "Da xoa sinh vien ma: " << maSV << endl;
}
