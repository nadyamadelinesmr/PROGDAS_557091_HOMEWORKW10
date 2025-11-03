#include <iostream>
#include <string>
#include <iomanip> // Diperlukan untuk setprecision

// Menggunakan namespace std
using namespace std;

// --- Konstanta ---
const int JUMLAH_NILAI = 3;
const int JUMLAH_MAHASISWA = 3;

/**
 * 1. Definisi struct (Record) [cite: 157, 160-163]
 * Ini adalah "cetakan" untuk data mahasiswa, sesuai
 * dengan konsep 'struct' dari PDF.
 */
struct Student {
    string nama;
    int nilai[JUMLAH_NILAI]; // Array di dalam struct [cite: 300]
    double rataRata;
};

// --- Fungsi Utama ---
int main() {

    /**
     * 2. Deklarasi Array dari Struct 
     * Kita membuat 3 variabel Student dan langsung 
     * menginisialisasi member 'nama' nya.
     */
    Student daftarMahasiswa[JUMLAH_MAHASISWA] = {
        {"Nadya Madeline"},
        {"Mariah Carrey"},
        {"Billie Elish"}
    };

    cout << "--- INPUT NILAI " << JUMLAH_MAHASISWA << " MAHASISWA ---" << endl;

    // Loop untuk mengisi nilai setiap mahasiswa
    for (int i = 0; i < JUMLAH_MAHASISWA; ++i) {
        
        // Nama sudah ada, langsung minta nilai
        cout << "\nMasukkan " << JUMLAH_NILAI << " nilai untuk " 
             << daftarMahasiswa[i].nama << " (dipisah spasi): ";

        double totalNilai = 0;

        // Loop untuk mengisi 3 nilai tes
        for (int j = 0; j < JUMLAH_NILAI; ++j) {
            cin >> daftarMahasiswa[i].nilai[j];
            // Nilai langsung dijumlahkan
            totalNilai += daftarMahasiswa[i].nilai[j];
        }

        /**
         * 3. Manipulasi Data Struct [cite: 143]
         * Menghitung rata-rata dan menyimpannya 
         * ke member 'rataRata'.
         */
        daftarMahasiswa[i].rataRata = totalNilai / JUMLAH_NILAI;
    }

    // --- Bagian Output ---
    cout << "\n\n--- HASIL DATA NILAI MAHASISWA ---" << endl;
    
    // Mengatur format desimal (2 angka di belakang koma)
    cout << fixed << setprecision(2); 

    // Loop untuk menampilkan data 
    for (int i = 0; i < JUMLAH_MAHASISWA; ++i) {
        cout << "-----------------------------------" << endl;
        // Mengakses member struct untuk output 
        cout << "Nama       : " << daftarMahasiswa[i].nama << endl;
        cout << "Nilai      : ";
        
        // Loop kecil untuk cetak 3 nilai
        for (int j = 0; j < JUMLAH_NILAI; ++j) {
            cout << daftarMahasiswa[i].nilai[j] << " ";
        }
        
        cout << "\nRata-rata  : " << daftarMahasiswa[i].rataRata << endl;
    }
    cout << "-----------------------------------" << endl;

    return 0;
}