void docFileCSV(DoubleLinkedList &list, string tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        ofstream newFile(tenFile);
        newFile << "SV01,Nguyen Quoc Lam,3.8,Xuat sac\n";
        newFile << "SV02,Nguyen Van Hoang Ly,3.2,Gioi\n";
        newFile << "SV03,Doan Nghia Loc,2.8,Kha\n";
        newFile << "SV04,Le Minh Quan,3.9,Xuat sac\n";
        newFile << "SV05,Nguyen Hoang Duy,2.7,Kha\n";
        newFile.close();
        file.open(tenFile);
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string field;
        SinhVien sv;

        getline(ss, sv.maSV, ',');
        getline(ss, sv.hoTen, ',');
        getline(ss, field, ',');
        try { sv.diemGPA = stof(field); } catch (...) { sv.diemGPA = 0; }
        getline(ss, sv.xepLoai);
        themCuoi(list, sv);
    }
    file.close();
}


void ghiFileCSV(DoubleLinkedList list, string tenFile) {
    ofstream file(tenFile);
    for (Node* k = list.head; k != NULL; k = k->next) {
        file << k->data.maSV << "," << k->data.hoTen << "," 
             << k->data.diemGPA << "," << k->data.xepLoai << "\n";
    }
    file.close();
    cout << "Da luu du lieu vao " << tenFile << endl;
}
