#include <iostream>
using namespace std;

// Cau truc Node dai dien cho mot nguoi choi trong vong tron
struct Node {
    int data;   // So thu tu cua nguoi choi
    Node *link; // Con tro tro den nguoi choi tiep theo
};

// Ham khoi tao danh sach lien ket vong voi N nguoi
void khoiTaoDanhSachVong(Node *&head, int N) {
    head = nullptr;
    Node *prev = nullptr;
    for (int i = 0; i <= N; ++i) {
        Node *newNode = new Node;
        newNode->data = i;
        newNode->link = head;
        if (head == nullptr) {
            head = newNode;
        } else {
            prev->link = newNode;
        }
        prev = newNode;
    }
    // Tao lien ket vong
    prev->link = head;
}

// Ham giai quyet bai toan Josephus
int josephus(int N, int M) {
    if (N == 1) return 1; // Neu chi co 1 nguoi thi nguoi do la nguoi chien thang

    Node *head = nullptr;
    khoiTaoDanhSachVong(head, N);

    Node *current = head;
    Node *prev = nullptr;

    // Vong lap cho den khi chi con mot nguoi
    while (N > 1) {
        // Di chuyen M-1 buoc de den nguoi bi loai
        for (int i = 1; i < M; ++i) {
            prev = current;
            current = current->link;
        }

        // Loai bo nguoi choi hien tai
        prev->link = current->link;
        delete current;
        current = prev->link;
        --N; // Giam so nguoi choi con lai
    }

    // Nguoi chien thang cuoi cung
    int winner = current->data;
    delete current; // Giai phong bo nho
    return winner;
}

// Ham main de chay chuong trinh
int main() {
    int N, M;

    // Nhap gia tri N va M
    cout << "Nhap so nguoi choi (N): ";
    cin >> N;
    cout << "Nhap so buoc dem (M): ";
    cin >> M;

    // Giai bai toan Josephus va in ra ket qua
    int nguoiChienThang = josephus(N, M);
    cout << "Nguoi chien thang la nguoi thu " << nguoiChienThang << endl;

    return 0;
}

