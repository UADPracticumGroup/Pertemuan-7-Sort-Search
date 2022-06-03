#pragma once

#include <iostream>
#include <vector>

struct Mahasiswa {
    std::string Nama;
    int NIM;
};

class Program {
    public:
        Program();
        bool Input();
        bool Check();
        std::vector<Mahasiswa> SortByAscending();
        Mahasiswa* Cari(int NIM);
        Mahasiswa* Cari(std::string Nama);

    private:
        std::vector<Mahasiswa> List;
        int Size;
};
