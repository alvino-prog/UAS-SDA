#include <iostream>
#include <string>
using namespace std;

struct Person {
    string nama;
    string alamat;
};

void bubbleSort(Person data[], int n, bool sortByNama) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (sortByNama ? data[j].nama > data[j + 1].nama : data[j].alamat > data[j + 1].alamat) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(Person data[], int n, bool sortByNama) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (sortByNama ? data[j].nama < data[minIndex].nama : data[j].alamat < data[minIndex].alamat)
                minIndex = j;
        }
        swap(data[i], data[minIndex]);
    }
}

int main() {
    Person data[8] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    int n = sizeof(data) / sizeof(data[0]);

    // Sorting using Bubble Sort based on 'Nama'
    bubbleSort(data, n, true);
    cout << "Hasil Bubble Sort berdasarkan Nama:\n";
    cout << "Nama\tAlamat\n";
    for (int i = 0; i < n; i++)
        cout << data[i].nama << "\t" << data[i].alamat << endl;
    cout << endl;

    // Restore the original data
    Person data2[8] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    // Sorting using Selection Sort based on 'Alamat'
    selectionSort(data2, n, false);
    cout << "Hasil Selection Sort berdasarkan Alamat:\n";
    cout << "Nama\tAlamat\n";
    for (int i = 0; i < n; i++)
        cout << data2[i].nama << "\t" << data2[i].alamat << endl;

    return 0;
}

