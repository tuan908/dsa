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
int Delete(Hashtable &, int, int &);
void PrintHashtable(Hashtable, ofstream &);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
int main() {
    ofstream file;
    file.open("../bin/output8.txt");
    Hashtable hashtable;

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0) hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Delete(hashtable, k, nprob)) {
            file << "THAM DO " << nprob << endl;
        } else {
            file << "KHONG XOA DUOC" << endl;
        }
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
        else
            file << "[" << hs.Maso << ",  " << "  , " << ", " << ", " << "]\n";
    }
}

void DeleteHashtable(Hashtable &ht) {
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int hashFn(int key, int M) { return key % M; }

int quadraticProbe(int key, int i, int M) {
    return (hashFn(key, M) + i * i) % M;
}

int Delete(Hashtable &ht, int maso, int &nprob) {
    nprob = 0;
    int moduloedValue = maso % ht.M;

    for (int i = 0; i < ht.M; i++) {
        int index = (moduloedValue + i * i) % ht.M;

        if (ht.table[index].Maso == EMPTY) {
            return 0;
        }

        if (ht.table[index].Maso == maso) {
            ht.table[index].Maso = DELETE;
            ht.n--;
            return 1;
        }

        nprob++;
    }
    return 0;
}
