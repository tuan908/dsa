#include <iostream>
#include <vector>

using namespace std;

class Node {
   public:
    int mssv;
    Node* next;

    Node(int mssv) {
        this->mssv = mssv;
        this->next = nullptr;
    }
};

class SinhVien {
   private:
    Node* head;
    Node* tail;

   public:
    SinhVien() { head = tail = nullptr; }

    // Thêm sinh viên vào cuối hàng
    void ThemSinhVien(int mssv) {
        Node* newNode = new Node(mssv);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Xếp hàng lại sau khi được gọi
    void XepHangLai(int mssv) {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->mssv != mssv) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (current == head) {
            head = head->next;
        } else {
            prev->next = current->next;
        }

        current->next = head;
        head = current;
    }

    // In ra thứ tự xếp hàng hiện tại
    void InThuTu() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->mssv << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    SinhVien danhSach;
    for (int i = 1; i <= n; ++i) {
        danhSach.ThemSinhVien(i);
    }

    vector<int> danhSachGoi;
    for (int i = 0; i < m; ++i) {
        int mssv;
        cin >> mssv;
        danhSachGoi.push_back(mssv);
    }

    for (int i = 0; i < m; ++i) {
        danhSach.XepHangLai(danhSachGoi[i]);
    }

    danhSach.InThuTu();

    return 0;
}
