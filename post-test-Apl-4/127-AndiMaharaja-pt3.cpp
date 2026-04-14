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

// ================== FUNGSI ==================

void tambahData(Musik *musikPtr, int *jumlahPtr) {
    cout << "\n=== Tambah Data Musik ===\n";
    
    cout << "ID Musik : ";
    cin >> musikPtr[*jumlahPtr].id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Judul Lagu : ";
    getline(cin, musikPtr[*jumlahPtr].judul);

    cout << "Artis : ";
    getline(cin, musikPtr[*jumlahPtr].artis);

    cout << "Genre : ";
    getline(cin, musikPtr[*jumlahPtr].genre);

    cout << "Tahun Rilis : ";
    cin >> musikPtr[*jumlahPtr].tahun;

    (*jumlahPtr)++;

    cout << "Data berhasil ditambahkan!\n";
}

void lihatData(Musik *musikPtr, int jumlah) {
    cout << "\n=== Daftar Koleksi Musik ===\n";

    if (jumlah == 0) {
        cout << "Belum ada data musik.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nID : " << musikPtr[i].id << endl;
        cout << "Judul : " << musikPtr[i].judul << endl;
        cout << "Artis : " << musikPtr[i].artis << endl;
        cout << "Genre : " << musikPtr[i].genre << endl;
        cout << "Tahun : " << musikPtr[i].tahun << endl;
    }
}

void ubahData(Musik *musikPtr, int jumlah) {
    int id;
    cout << "\nMasukkan ID Musik yang ingin diubah : ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < jumlah; i++) {
        if (musikPtr[i].id == id) {

            cout << "Judul baru : ";
            getline(cin, musikPtr[i].judul);

            cout << "Artis baru : ";
            getline(cin, musikPtr[i].artis);

            cout << "Genre baru : ";
            getline(cin, musikPtr[i].genre);

            cout << "Tahun baru : ";
            cin >> musikPtr[i].tahun;

            cout << "Data berhasil diubah!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan.\n";
}

void hapusData(Musik *musikPtr, int *jumlahPtr) {
    int id;
    cout << "\nMasukkan ID Musik yang ingin dihapus : ";
    cin >> id;

    for (int i = 0; i < *jumlahPtr; i++) {
        if (musikPtr[i].id == id) {

            for (int j = i; j < *jumlahPtr - 1; j++) {
                musikPtr[j] = musikPtr[j + 1];
            }

            (*jumlahPtr)--;
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan.\n";
}

// ================== MAIN ==================

int main() {

    User user;
    user.username = "maharaja";
    user.nim = "127";

    string usernameInput, nimInput;
    int percobaan = 0;

    // LOGIN
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

    // DATA
    Musik musik[100];
    int jumlah = 0;

    Musik *musikPtr = musik;
    int *jumlahPtr = &jumlah;

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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {

        case 1:
            tambahData(musikPtr, jumlahPtr);
            break;

        case 2:
            lihatData(musikPtr, jumlah);
            break;

        case 3:
            ubahData(musikPtr, jumlah);
            break;

        case 4:
            hapusData(musikPtr, jumlahPtr);
            break;

        case 5:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia.\n";
        }

    } while (pilihan != 5);

    return 0;
    