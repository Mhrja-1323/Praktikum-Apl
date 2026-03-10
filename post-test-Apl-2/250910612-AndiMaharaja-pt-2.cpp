#include <iostream>
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

Musik musik[100];
int jumlah = 0;

void tambahData() {
    cout << "\n=== Tambah Data Musik ===\n";
    cout << "ID Musik : ";
    cin >> musik[jumlah].id;
    cin.ignore();

    cout << "Judul Lagu : ";
    getline(cin, musik[jumlah].judul);

    cout << "Artis : ";
    getline(cin, musik[jumlah].artis);

    cout << "Genre : ";
    getline(cin, musik[jumlah].genre);

    cout << "Tahun Rilis : ";
    cin >> musik[jumlah].tahun;

    jumlah++;

    cout << "Data berhasil ditambahkan!\n";
}

void lihatData() {
    cout << "\n=== Daftar Koleksi Musik ===\n";

    if (jumlah == 0) {
        cout << "Belum ada data musik.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nID : " << musik[i].id << endl;
        cout << "Judul : " << musik[i].judul << endl;
        cout << "Artis : " << musik[i].artis << endl;
        cout << "Genre : " << musik[i].genre << endl;
        cout << "Tahun : " << musik[i].tahun << endl;
    }
}

void ubahData() {
    int id;
    cout << "\nMasukkan ID Musik yang ingin diubah : ";
    cin >> id;
    cin.ignore();

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

            cout << "Data berhasil diubah!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan.\n";
}

void hapusData() {
    int id;
    cout << "\nMasukkan ID Musik yang ingin dihapus : ";
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

    cout << "Data tidak ditemukan.\n";
}

int main() {

    User user;
    user.username = "maharaja";
    user.nim = "127";

    string usernameInput, nimInput;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "\n=== LOGIN ===\n";
        cout << "Username (Nama) : ";
        cin >> usernameInput;

        cout << "Password (NIM) : ";
        cin >> nimInput;

        if (usernameInput == user.username && nimInput == user.nim) {
            cout << "Login berhasil!\n";
            break;
        } else {
            percobaan++;
            cout << "Login gagal! Percobaan ke-" << percobaan << endl;
        }

        if (percobaan == 3) {
            cout << "Anda gagal login 3 kali. Program berhenti.\n";
            return 0;
        }
    }

    int pilihan;

    do {
        cout << "\n===== SISTEM MANAJEMEN KOLEKSI MUSIK =====\n";
        cout << "1. Tambah Data Musik\n";
        cout << "2. Lihat Data Musik\n";
        cout << "3. Ubah Data Musik\n";
        cout << "4. Hapus Data Musik\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            tambahData();
            break;

        case 2:
            lihatData();
            break;

        case 3:
            ubahData();
            break;

        case 4:
            hapusData();
            break;

        case 5:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia.\n";
        }

    } while (pilihan != 5);

    return 0;
}