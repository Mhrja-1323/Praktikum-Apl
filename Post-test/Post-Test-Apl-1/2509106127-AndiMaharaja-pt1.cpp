#include <iostream>
using namespace std;

int main() {
    string username_benar = "shas";   // input nama 
    string password_benar = "127";    // Paswword nim terakir (127)
    string nama, password;
    int kesempatan = 0;

    // ===== LOGIN =====
    while (kesempatan < 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan Password (3 digit terakhir NIM): ";
        cin >> password;

        if (nama == username_benar && password == password_benar) {
            cout << "\nLogin berhasil!\n";
            break;
        } else {
            kesempatan++;
            cout << "Login salah! Pe1rcobaan ke-" << kesempatan << endl;
        }
    }

    if (kesempatan == 3) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    double meter, km, cm;

    // ===== MENU LOOPING =====
    do {
        cout << "\n=== MENU KONVERSI PANJANG ===\n";
        cout << "1. Meter ~~> Kilometer dan Centimeter\n";
        cout << "2. Kilometer ~~> Meter dan Centimeter\n";
        cout << "3. Centimeter ~~> Meter dan Kilometer\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai Meter: ";
                cin >> meter;
                km = meter / 1000;
                cm = meter * 100;
                cout << "Hasil: " << km << " km dan " << cm << " cm\n";
                break;

            case 2:
                cout << "Masukkan nilai Kilometer: ";
                cin >> km;
                meter = km * 1000;
                cm = km * 100000;
                cout << "Hasil: " << meter << " m dan " << cm << " cm\n";
                break;

            case 3:
                cout << "Masukkan nilai Centimeter: ";
                cin >> cm;
                meter = cm / 100;
                km = cm / 100000;
                cout << "Hasil: " << meter << " m dan " << km << " km\n";
                break;

            case 4:
                cout << "Terima kasih. Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}
