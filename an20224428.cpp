
#include <iostream>
#include <cstddef>
#include <cstring>
#include <cstdlib>  // for nullptr

using namespace std;

struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char hoTen[50];
    char maSV[8];
    Ngay ngaySinh;
    char gioiTinh[10];
    char khoa[7];
    char diaChi[100];
    char lop[12];
};

struct Node {
    SinhVien data;
    Node *link;
};

struct List {
    Node *first;
    Node *last;
};

void nhapSinhVien(SinhVien &sv) {
    cout << "Nhap ma so sinh vien: ";
    cin.getline(sv.maSV, 8);
    cout << "Nhap ho ten: ";
    cin.getline(sv.hoTen, 50);
    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
    cin.ignore();
    cout << "Nhap gioi tinh: ";
    cin.getline(sv.gioiTinh, 10);
    cout << "Nhap khoa: ";
    cin.getline(sv.khoa, 7);
    cout << "Nhap dia chi: ";
    cin.getline(sv.diaChi, 100);
    cout << "Nhap lop: ";
    cin.getline(sv.lop, 12);
}

void inSinhVien(const SinhVien &sv) {
    cout << "Ma so sinh vien: " << sv.maSV << endl;
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Ngay sinh: " << sv.ngaySinh.ngay << "/" << sv.ngaySinh.thang << "/" << sv.ngaySinh.nam << endl;
    cout << "Gioi tinh: " << sv.gioiTinh << endl;
    cout << "Khoa: " << sv.khoa << endl;
    cout << "Dia chi: " << sv.diaChi << endl;
    cout << "Lop: " << sv.lop << endl;
}

void sapXepSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ds[i].maSV, ds[j].maSV) > 0) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void nhapDanhSachSinhVien(SinhVien ds[], int &n) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        nhapSinhVien(ds[i]);
        cout << endl;
    }
}

void inDanhSachSinhVien(const SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin sinh vien thu " << i + 1 << ":" << endl;
        inSinhVien(ds[i]);
    }
}

void themSinhVien(List &list, SinhVien sv) {
    Node *newNode = new Node;
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->data = sv;
    newNode->link = nullptr;
    if (list.first == nullptr) {
        list.first = newNode;
        list.last = newNode;
    } else {
        Node *current = list.first;
        Node *previous = nullptr;
        while (current != nullptr && strcmp(current->data.maSV, sv.maSV) < 0) {
            previous = current;
            current = current->link;
        }
        if (previous == nullptr) {
            newNode->link = list.first;
            list.first = newNode;
        } else {
            newNode->link = previous->link;
            previous->link = newNode;
        }
        if (newNode->link == nullptr) {
            list.last = newNode;
        }
    }
}

void inSinhVienCungNgaySinh(const List &list, int ngay, int thang, int nam) {
    Node *current = list.first;
    bool found = false;
    while (current != nullptr) {
        if (current->data.ngaySinh.ngay == ngay && current->data.ngaySinh.thang == thang && current->data.ngaySinh.nam == nam) {
            inSinhVien(current->data);
            found = true;
        }
        current = current->link;
    }
    if (!found) {
        cout << "Khong tim thay sinh vien cung ngay sinh" << endl;
    }
}

void loaiBoSinhVienCungNgaySinh(List &list, int ngay, int thang, int nam) {
    Node *current = list.first;
    Node *previous = nullptr;
    while (current != nullptr) {
        if (current->data.ngaySinh.ngay == ngay && current->data.ngaySinh.thang == thang && current->data.ngaySinh.nam == nam) {
            if (previous == nullptr) {
                list.first = current->link;
            } else {
                previous->link = current->link;
            }
            Node *temp = current;
            current = current->link;
            delete temp;
        } else {
            previous = current;
            current = current->link;
        }
    }
    if (list.first == nullptr) {
        list.last = nullptr;
    }
}

int main() {
    List list;
    list.first = nullptr;
    list.last = nullptr;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        nhapSinhVien(sv);
        themSinhVien(list, sv);
    }
    cout << "Danh sach sinh vien sau khi sap xep theo ma sinh vien:" << endl;
    Node *current = list.first;
    while (current != nullptr) {
        inSinhVien(current->data);
        current = current->link;
    }
    int ngay, thang, nam;
    cout << "Nhap ngay sinh de tim sinh vien: ";
    cin >> ngay >> thang >> nam;
    inSinhVienCungNgaySinh(list, ngay, thang, nam);
    cout << "Nhap ngay sinh de loai bo sinh vien: ";
    cin >> ngay >> thang >> nam;
    loaiBoSinhVienCungNgaySinh(list, ngay, thang, nam);
    cout << "Danh sach sinh vien sau khi loai bo:" << endl;
    current = list.first;
    while (current != nullptr) {
        inSinhVien(current->data);
        current = current->link;
    }
    return 0;
}

