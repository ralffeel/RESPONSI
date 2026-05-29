#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string username, password;

    string tugas[100];
    string matkul[100];
    string deadline[100];
    bool selesai[100];

    int jumlah = 0;
    int pilihan;

    cout << "===== LOGIN TASKKU =====\n";
    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    if(username == "Raka" && password == "123") {

        do {

            cout << "\n===== MENU TASKKU =====\n";
            cout << "1. Tambah Tugas\n";
            cout << "2. Lihat Tugas Aktif\n";
            cout << "3. Tandai Selesai\n";
            cout << "4. Hapus Tugas\n";
            cout << "5. Riwayat Selesai\n";
            cout << "6. Simpan ke File\n";
            cout << "7. Keluar\n";
            cout << "Pilih Menu : ";
            cin >> pilihan;

            switch(pilihan) {

                case 1:

                    cin.ignore();

                    cout << "Nama Tugas : ";
                    getline(cin, tugas[jumlah]);

                    cout << "Mata Kuliah : ";
                    getline(cin, matkul[jumlah]);

                    cout << "Deadline : ";
                    getline(cin, deadline[jumlah]);

                    selesai[jumlah] = false;

                    jumlah++;

                    cout << "Tugas berhasil ditambahkan!\n";

                    break;

                case 2:

                    cout << "\n===== TUGAS AKTIF =====\n";

                    for(int i=0; i<jumlah; i++) {

                        if(selesai[i] == false) {

                            cout << i+1 << ". "
                                 << tugas[i]
                                 << " | "
                                 << matkul[i]
                                 << " | "
                                 << deadline[i]
                                 << endl;
                        }
                    }

                    break;

                case 3:

                    int nomor;

                    cout << "Nomor tugas selesai : ";
                    cin >> nomor;

                    selesai[nomor-1] = true;

                    cout << "Tugas selesai!\n";

                    break;

                case 4:

                    int hapus;

                    cout << "Nomor tugas dihapus : ";
                    cin >> hapus;

                    for(int i=hapus-1; i<jumlah; i++) {

                        tugas[i] = tugas[i+1];
                        matkul[i] = matkul[i+1];
                        deadline[i] = deadline[i+1];
                        selesai[i] = selesai[i+1];
                    }

                    jumlah--;

                    cout << "Tugas berhasil dihapus!\n";

                    break;

                case 5:

                    cout << "\n===== RIWAYAT =====\n";

                    for(int i=0; i<jumlah; i++) {

                        if(selesai[i] == true) {

                            cout << i+1 << ". "
                                 << tugas[i]
                                 << endl;
                        }
                    }

                    break;

                case 6:

                    ofstream file("arsip_tugas.txt");

                    for(int i=0; i<jumlah; i++) {

                        file << tugas[i] << " | "
                             << matkul[i] << " | "
                             << deadline[i] << " | ";

                        if(selesai[i] == true)
                            file << "Selesai";
                        else
                            file << "Aktif";

                        file << endl;
                    }

                    file.close();

                    cout << "Data berhasil disimpan!\n";

                    break;

                case 7:

                    cout << "Program selesai.\n";

                    break;

                default:

                    cout << "Menu tidak tersedia!\n";
            }

        } while(pilihan != 7);

    } else {

        cout << "Login gagal!\n";
    }

    return 0;
}
