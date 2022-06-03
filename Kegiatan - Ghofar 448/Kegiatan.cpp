#include <iostream>

class Sorting {
    friend std::istream& operator>>(std::istream&, Sorting&);
    friend std::ostream& operator<<(std::ostream&, Sorting&);

    public:
        void selection_sort();
        int pencarianBiner();

    private:
        void minimum(int, int, int&);
        void tukar(int&, int&);

        int data[10], n;
};

void Sorting::minimum(int low, int high, int& min) {
    min = low;
    for (int i = low + 1; i <= high; i++) {
        if (data[i] < data[min]) {
            min = i;
        }
    }
}

void Sorting::tukar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Sorting::selection_sort() {
    int min;
    for (int i = 0; i < n; i++) {
        minimum(i, n, min);
        tukar(data[i], data[min]);
        std::cout << "data ke-" << i + 1 << ": " << data[i] << std::endl;
    }
}

int Sorting::pencarianBiner() {
    int kunciPencarian;

    std::cout << "Masukan data yang dicari: "; std::cin >> kunciPencarian;

    int low = 0, high = n - 1, mid = (low + high) / 2;
    while (low <= high) {
        if (data[mid] == kunciPencarian) {
            return mid;
        } else if (data[mid] < kunciPencarian) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }

    if (low > high) {
        std::cout << "Data tidak ditemukan" << std::endl;
        return -1;
    }
}

std::istream& operator>>(std::istream& in, Sorting& s) {
    std::cout << "Masukkan jumlah data: ";
    in >> s.n;
    for (int i = 0; i < s.n; i++) {
        std::cout << "Masukan data ke-" << i + 1 << ": ";
        in >> s.data[i];
    }

    std::cout << "Data setelah diurutkan: \n";
    s.selection_sort();

    return in;
}

std::ostream& operator<<(std::ostream& out, Sorting& s) {
    int index = s.pencarianBiner();
    std::cout << "Data berada pada index: " << index << " (atau data ke-" << index + 1 << ")" << std::endl;

    return out;
}

int main() {
    Sorting s;
    std::cin >> s;
    std::cout << s;

}
