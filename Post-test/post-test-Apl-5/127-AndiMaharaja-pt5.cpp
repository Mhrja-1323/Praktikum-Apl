#include <iostream>
#include <limits>
using namespace std;

struct User {
    string username;
    string nim;
};

struct Musik {
    int id;
    string judul;
    string artis;
    string genre;
    int tahun;
};

// ================== CRUD ==================

void tambahData(Musik *musik, int &jumlah) {
    cout << "\n=== Tambah Data Musik ===\n";

    cout << "ID Musik : ";
    cin >> musik[jumlah].id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Judul Lagu : ";
    getline(cin, musik[jumlah].judul);

    cout << "Artis : ";
    getline(cin, musik[jumlah].artis);

    cout << "Genre : ";
    getline(cin, musik[jumlah].genre);

    cout << "Tahun Rilis : ";
    cin >> musik[jumlah].tahun;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    jumlah++;
    cout << "Data berhasil ditambahkan!\n";
}

void lihatData(Musik *musik, int jumlah) {
    cout << "\n=== Daftar Koleksi Musik ===\n";

    if (jumlah == 0) {
        cout << "Belum ada data.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nID MUSIK    : " << musik[i].id;
        cout << "\nJudul LAGU  : " << musik[i].judul;
        cout << "\nArtis       : " << musik[i].artis;
        cout << "\nGenre       : " << musik[i].genre;
        cout << "\nTahun RILIS : " << musik[i].tahun << endl;
    }
}

void ubahData(Musik *musik, int jumlah) {
    int id;
    cout << "Masukkan ID : ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < jumlah; i++) {
        if (musik[i].id == id) {
            cout << "Judul baru : ";
            getline(cin, musik[i].judul);

            cout << "Artis baru : ";
            getline(cin, musik[i].artis);

            cout << "Genre baru : ";
            getline(cin, musik[i].genre);

            cout << "Tahun baru : ";
            cin >> musik[i].tahun;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Data berhasil diubah!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan!\n";
}

void hapusData(Musik *musik, int &jumlah) {
    int id;
    cout << "Masukkan ID : ";
    cin >> id;

    for (int i = 0; i < jumlah; i++) {
        if (musik[i].id == id) {
            for (int j = i; j < jumlah - 1; j++) {
                musik[j] = musik[j + 1];
            }
            jumlah--;
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan!\n";
}

// ================== SORTING ==================

void sortJudul(Musik *musik, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int min = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (musik[j].judul < musik[min].judul) {
                min = j;
            }
        }
        swap(musik[i], musik[min]);
    }
}

void sortTahun(Musik *musik, int jumlah) {
    for (int i = 1; i < jumlah; i++) {
        Musik key = musik[i];
        int j = i - 1;

        while (j >= 0 && musik[j].tahun < key.tahun) {
            musik[j + 1] = musik[j];
            j--;
        }
        musik[j + 1] = key;
    }
}

void sortId(Musik *musik, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (musik[j].id > musik[j + 1].id) {
                swap(musik[j], musik[j + 1]);
            }
        }
    }
}

// ================== MAIN ==================

int main() {
    User user = {"maharaja", "127"};
    string u, p;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "\nLOGIN\n";
        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;

        if (u == user.username && p == user.nim) break;

        cout << "Salah!\n";
        percobaan++;
        if (percobaan == 3) return 0;
    }

    Musik musik[100];
    int jumlah = 0;
    int pilihan;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Musik\n2. Lihat Musik\n3. Ubah Musik\n4. Hapus Musik\n";
        cout << "5. Sort Judul Musik\n6. Sort Tahun Musik\n7. Sort ID Musik\n8. Keluar\n";
        cout << "Pilih:";

        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (pilihan) {
            case 1: tambahData(musik, jumlah); break;
            case 2: lihatData(musik, jumlah); break;
            case 3: ubahData(musik, jumlah); break;
            case 4: hapusData(musik, jumlah); break;

            case 5:
                if (jumlah == 0) cout << "Kosong!\n";
                else { sortJudul(musik, jumlah); lihatData(musik, jumlah); }
                break;

            case 6:
                if (jumlah == 0) cout << "Kosong!\n";
                else { sortTahun(musik, jumlah); lihatData(musik, jumlah); }
                break;

            case 7:
                if (jumlah == 0) cout << "Kosong!\n";
                else { sortId(musik, jumlah); lihatData(musik, jumlah); }
                break;

            case 8:
                cout << "Keluar...\n";
                break;

            default:
                cout << "Menu tidak ada!\n";
        }

    } while (pilihan != 8);

    return 0;
}