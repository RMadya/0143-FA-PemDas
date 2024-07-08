/*! \mainpage Sistem Penilaian Mata Kuliah Pemrogaman dan Jaringan
 *
 * \section intro_sec Pengantar
 * Selamat datang di dokumentasi Sistem Penilaian Mata Kuliah Pemrogaman dan Jaringan,
 * Sistem ini dirancang untuk penilaian antara MK Pemrogaman dan Jaringan
 *
 * \section structure_sec Struktur Kode
 * Kode ini terdiri dari tiga kelas utama:
 * - \b MataKuliah: Memberikan informasi tentang presensi, activity, exercise dan tugas akhir
 * - \b Pemrogaman: Menangani informasi tentang nilai mata kuliah Pemrogaman
 * - \b Jaringan: Menangani informasi tentang nilai mata kuliah Jaringan
 *
 * \section setup_sec Setup dan Konfigurasi
 * Untuk menjalanka sistem ini, pastikan anda memili compiler yang mendukung
 * Konfigurasi dan jalankan file ini menggunakan compiler pilihan anda.
 *
 * \section author_sec Tentang Pengembang
 * Sistem ini dikembangkan oleh MuhammadRinaldi.id sebagai bagian dari UAS PemDas
 *
 * \section note_sec Catatan
 * Dokumentasi ini dihasilkan menggunakan Doxygen yang baru saya pahami*/

/**
 * @file PemrogamanDanJaringan.cpp
 * @author MuhammadRinaldi.id
 * @brief
 * @version 1.1
 * @date 2024-06-24
 *
 * @copyright Copyright (c) 2024
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @class MataKuliah
 * @brief initial class MataKuliah
 */
class MataKuliah
{
private: ///< access modifier yang dibutuhkan
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;

    // tambahkan dengan variabel lain yang dibutuhkan dibawah ini
public: ///< Pengisian access modifier yang dibutuhkan
    MataKuliah()
    {
        presensi = 0.0;
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;
        // isi dengan inisialisasi variabel yang dibutuhkan dibawah ini
    }
    virtual void namaMataKuliah() { return; }
    ///< virtual fungsi lain yang dibutuhkan
    void setPresensi(float nilai)
    {
        this->presensi = nilai;
    }
    float getPresensi()
    {
        return presensi;
    }
    void setActivity(float nilai)
    {
        this->activity = nilai;
    }
    float getActivity()
    {
        return activity;
    }
    void setExercise(float nilai)
    {
        this->exercise = nilai;
    }
    float getExercise()
    {
        return exercise;
    }
    void setTugasAkhir(float nilai)
    {
        this->tugasAkhir = nilai;
    }
    float getTugasAkhir()
    {
        return tugasAkhir;
    }
    float hitungNilaiAkhir()
    {
        return (presensi * 0.2) + (activity * 0.2) + (exercise * 0.3) + (tugasAkhir * 0.3);
    }
};
/**
 * @class Pemrogaman
 * @brief  initial class Pemrogaman
 */
class Pemrograman : public MataKuliah
{
public:
    void namaMataKuliah()
    {
        cout << "Pemrogaman" << endl;
    }
    // isi disini untuk mengisi kelas pemrograman
};
/**
 * @class Jaringan
 * @brief initial class Jaringan
 */
class Jaringan : public MataKuliah
{
public:
    void namaMataKuliah()
    {
        cout << "Jaringan" << endl;
    }
    // isi disini untuk mengisi kelas jaringan
};
int main()
{
    char pilih;
    MataKuliah *mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;
    cout << "Program Pertama Kali Dijalankan" << endl;
    do
    {
        cout << "Pilih Mata Kuliah: " << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case '1': 
            mataKuliah = &pemrograman;
            mataKuliah->namaMataKuliah();
            cout << "Masukkan nilai presensi: ";
            cin >> pemrograman.getPresensi();
            cout << "Masukkan nilai activity: ";
            cin >> pemrograman.getActivity();
            cout << "Masukkan nilai exercise: ";
            cin >> pemrograman.getExercise();
            cout << "Masukkan nilai tugas akhir: ";
            cin >> pemrograman.getTugasAkhir();
            cout << "Nilai Akhir: " << pemrograman.hitungNilaiAkhir() << endl;
            if (pemrograman.hitungNilaiAkhir()>= 65){
                cout << "Selamat Anda Dinyatakan Lulus" << endl;
            }
            else {
                cout << "Anda Dinyatakan Tidak Lulus" << endl;
            }
            break;
        case '2':
            mataKuliah = &jaringan;
            mataKuliah->namaMataKuliah();
            cout << "Masukkan Nilai presensi: ";
            cin >> jaringan.getPresensi();
            cout << "Masukkan Nilai activity: ";
            cin >> jaringan.getActivity();
            cout << "Masukkan Nila exerchise: ";
            cin >> jaringan.getExercise();
            cout << "Masukkan Nilai tugas akhir: ";
            cin >> jaringan.getTugasAkhir();
            cout << "Nilai Akhir: " << jaringan.hitungNilaiAkhir() << endl;
            if (pemrograman.hitungNilaiAkhir()>= 65) {
                cout << "Selamat Anda Dinyatakan Lulus" << endl;
            }
            else {
                cout << "Anda Dinyatakan Tidak Lulus" << endl;
            }
            break;
        case '3':
            cout << "Program Selesai" << endl;
            break;
        default:
            cout << "Inputan Salah!" << endl;
        }
    } while (pilih != '3');
}