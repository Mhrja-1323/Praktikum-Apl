#include <iostream>
using namespace std;

struct Musik {
    int id;
    string nama;
};

// ===== DATA =====
Musik dataMusik[] = {
    {101, "Pop"},
    {102, "Rock"},
    {103, "Jazz"},
    {104, "HipHop"},
    {105, "Klasik"}
};

int n = 5;

// ===== LINEAR SEARCH (Nama) =====
void cariNama(string target) {
    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        if (dataMusik[i].nama == target) {
            cout << "Ditemukan!\n";
            cout << "ID: " << dataMusik[i].id << endl;
            cout << "Nama: " << dataMusik[i].nama << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan!\n";
    }
}

// ===== BINARY SEARCH (ID) =====
void cariID(int target) {
    int left = 0, right = n - 1;
    bool ketemu = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (dataMusik[mid].id == target) {
            cout << "Ditemukan!\n";
            cout << "ID: " << dataMusik[mid].id << endl;
            cout << "Nama: " << dataMusik[mid].nama << endl;
            ketemu = true;
            break;
        } else if (target < dataMusik[mid].id) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan!\n";
    }
}

// ===== MAIN =====
int main() {
    int pilihan;

    do {
        cout << "\n=== MENU PENCARIAN MUSIK ===\n";
        cout << "1. Cari berdasarkan ID (Binary Search)\n";
        cout << "2. Cari berdasarkan Nama (Linear Search)\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;
            cariID(id);
        } else if (pilihan == 2) {
            string nama;
            cout << "Masukkan Nama Musik: ";
            cin >> nama;
            cariNama(nama);
        }

    } while (pilihan != 3);

    cout << "Program selesai.\n";
    return 0;
}