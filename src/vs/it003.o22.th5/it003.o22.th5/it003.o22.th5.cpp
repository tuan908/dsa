/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/
#include <fstream>
#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M;  // Kich thuoc bang bam
    int n;  // so phan tu trong bang bam
    Hocsinh *table;
};

void CreateHashtable(Hashtable &, int);
int Insert(Hashtable &, Hocsinh);
void PrintHashtable(Hashtable, ofstream &);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main() {
    ofstream file;
    file.open("D:\\Projects\\it003.o22\\bin\\out.txt");

    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable, file);
    file.close();
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m) {
    ht.table = new Hocsinh[m];
    if (ht.table == NULL) exit(1);
    for (int i = 0; i < m; i++) {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht, ofstream &file) {
    for (int i = 0; i < ht.M; i++) {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            file << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh
                 << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        // cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh
        //      << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            file << "[" << hs.Maso << ",  "
                 << "  , "
                 << ", "
                 << ", "
                 << "]\n";
        // cout << "[" << hs.Maso << ",  " << "  , " << ", " << ", " << "]\n";
    }
}
void DeleteHashtable(Hashtable &ht) {
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable &ht, Hocsinh x) {
    if (ht.n > ht.M * LOAD) {  // Kiểm tra hệ số tải
        return 0;
    }

    auto hashedValue = x.Maso % ht.M;

    for (int i = 0; i < ht.M; ++i) {
        int index = (hashedValue + i) % ht.M;
        if (ht.table[index].Maso == EMPTY || ht.table[index].Maso == DELETE) {
            ht.table[index] = x;
            ht.n++;
            return 1;
        } else {
            ht.table[index].Maso = EMPTY;
            return 0;
        }
    }
    return 0;
}