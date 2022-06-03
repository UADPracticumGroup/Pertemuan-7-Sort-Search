#include "Program.h"

int main() {
    Program* app = new Program;

    int pilihan = 0;
    std::cout << "Pilih menu yang ingin anda lakukan" << std::endl;
    std::cout << "1. Input data" << std::endl;
    std::cout << "2. Sort data (secara Ascending)" << std::endl;
    std::cout << "3. Cari data" << std::endl;
    std::cout << "4. Keluar" << std::endl;

    bool loop = true;
    while (loop) {
        std::cout << "Masukan pilihan anda: "; std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                app->Input();
                break;
            }

            case 2: {
                if (app->Check() == false) {
                    std::cout << "Data masih kosong" << std::endl;
                    break;
                }

                auto sortedList = app->SortByAscending();
                std::cout << "Data yang telah diurutkan secara Ascending" << std::endl;
                for (int i = 0; i < sortedList.size(); i++) {
                    auto Mahasiswa = sortedList[i];
                    std::cout << i << " - " << Mahasiswa.Nama << " - " << Mahasiswa.NIM << std::endl;
                }
                break;
            }
            
            case 3: {
                if (app->Check() == false) {
                    std::cout << "Data masih kosong" << std::endl;
                    break;
                }

                int NIM;
                std::cout << "Masukan NIM yang ingin anda cari: "; std::cin >> NIM;
                auto Mahasiswa = app->Cari(NIM);
                if (Mahasiswa != nullptr) {
                    std::cout << "Data yang anda cari adalah: " << std::endl;
                    std::cout << "Nama: " << Mahasiswa->Nama << std::endl;
                    std::cout << "NIM: " << Mahasiswa->NIM << std::endl;
                } else {
                    std::cout << "Data tidak ditemukan" << std::endl;
                }
                break;
            }

            case 4: {
                if (app->Check() == false) {
                    std::cout << "Data masih kosong" << std::endl;
                    break;
                }

                std::string nama;

                std::cin.ignore();
                std::cout << "Masukan Nama yang dicari: "; std::getline(std::cin, nama);
                auto Mahasiswa = app->Cari(nama);
                if (Mahasiswa != nullptr) {
                    std::cout << "Data yang anda cari adalah: " << std::endl;
                    std::cout << "Nama: " << Mahasiswa->Nama << std::endl;
                    std::cout << "NIM: " << Mahasiswa->NIM << std::endl;
                } else {
                    std::cout << "Data tidak ditemukan" << std::endl;
                }
                break;
            }

            case 5: {
                std::cout << "Terima kasih telah menggunakan program ini" << std::endl;
                loop = false;
                break;
            }

            default: {
                std::cout << "Pilihan tidak ditemukan" << std::endl;
                break;
            }
        }
    }
}
