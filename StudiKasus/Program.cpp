#include "Program.h"

Program::Program() {
    std::cout << "Program input mahasiswa dan nim, dan pencarian nya juga" << std::endl;
}

bool Program::Input() {
    std::cout << "Masukan jumlah mahasiswa yang akan di-input: "; std::cin >> Size;
    if (Size < 5) {
        std::cout << "Jumlah mahasiswa minimal 5" << std::endl;
        return false;
    }

    for (int i = 0; i < Size; i++) {    
        std::cin.ignore();

        Mahasiswa mhs;
        std::cout << "Masukan nama mahasiswa: "; std::getline(std::cin, mhs.Nama);
        std::cout << "Masukan NIM mahasiswa: "; std::cin >> mhs.NIM;
        List.push_back(mhs);
    }

    return true;
}

bool Program::Check() {
    return List.size() > 0;
}

std::vector<Mahasiswa> Program::SortByAscending() {
    std::vector<Mahasiswa> list_to_return(Size);
    for (int i = 0; i < Size; i++) {
        list_to_return[i] = List[i];
    }

    for (int i = 0; i < Size; i++) {
        for (int j = i + 1; j < Size; j++) {
            if (list_to_return[i].NIM > list_to_return[j].NIM) {
                Mahasiswa temp = list_to_return[i];
                list_to_return[i] = list_to_return[j];
                list_to_return[j] = temp;
            }
        }
    }

    return list_to_return;
}

Mahasiswa* Program::Cari(int NIM) {
    for (int i = 0; i < Size; i++) {
        if (List[i].NIM == NIM) {
            return &List[i];
        }
    }

    return nullptr;
}

Mahasiswa* Program::Cari(std::string Nama) {
    for (int i = 0; i < Size; i++) {
        if (List[i].Nama == Nama) {
            return &List[i];
        }
    }

    return nullptr;
}
