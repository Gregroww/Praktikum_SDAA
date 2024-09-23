#include <iostream>
using namespace std;

//Tema Review Tempat (Restoran,Toko)
//Menggunakan Struck,Array,Pointer,Fungsi/Prosedur

struct review{
    string nama_tempat;
    string alamat;
    string review_ulasan;
    int penilaian;
    int no;
};

void tambah_review(review arr[] , int* sisa){
    if (*sisa >= 100) { // menggunakan pointer untuk melihat nilai yang tersimpan pada alamat memori
        cout << "Kapasitas penuh, tidak bisa menambah review baru.\n";
        return;
    }
    review& review_baru = arr[*sisa]; // akses array langsung
    review_baru.no = *sisa + 1;

    cout << "Masukkan Nama Tempat: ";
    cin.ignore();
    getline(cin, review_baru.nama_tempat);
    cout << "Masukkan Alamat: ";
    getline(cin, review_baru.alamat);
    cout << "Masukkan Review/Ulasan: ";
    getline(cin, review_baru.review_ulasan);
    cout << "Masukkan Penilaian  (1-5): ";
    cin >> review_baru.penilaian; 

    (*sisa)++; // menambah reveiw yang tersimpan
    cout << "Berhasil Menambahkan Review\n";
}

void tampilkan_review(review arr[],int sisa){ 
    if (sisa == 0) {
        cout << "\nTidak Ada Review\n";
        return;
    }
    cout << "\nReview Tempat\n";
    for (int i = 0; i < sisa; ++i){
        cout << "Review #" << arr[i].no << "\n";
        cout << "--------------------------------\n";
        cout << "Nama Tempat    : " << arr[i].nama_tempat  << "\n";
        cout << "Alamat         : " << arr[i].alamat  << "\n";
        cout << "Review/Ulasan  : " << arr[i].review_ulasan  << "\n";
        cout << "Penilaian      : " << arr[i].penilaian << "/5\n";
        cout <<"" << endl;
    }
} 

void update_review(review arr[], int sisa){
    if (sisa == 0) {
        cout << "Tidak ada review untuk diupdate.\n";
        return;
    }

    tampilkan_review(arr, sisa);

    int indeks;
    cout<< "Pilih nomor review yang ingin di ubah: ";
    cin >> indeks;

    if (indeks >= 1 && indeks <= sisa){
        review& review_update = arr[indeks - 1];  // data yang baru disimpan dalam review_update
        cout << "Masukkan Nama Tempat yang Baru: ";
        cin.ignore();
        getline(cin, review_update.nama_tempat);
        cout << "Masukkan Alamat yang Baru: ";
        getline(cin, review_update.alamat);
        cout << "Masukkan Review/Ulasan yang Baru: ";
        getline(cin, review_update.review_ulasan);
        cout << "Masukkan Penilaian yang Baru (1-5): ";
        cin >> review_update.penilaian;
        cout << "Berhasil Memperbarui Review\n";
    } else {
        cout << "Nomor Review tidak valid\n";
    }
}

void menghapus_review(review* arr , int* sisa){
    if (*sisa == 0) {
        cout << "Tidak ada review untuk dihapus.\n";
        return;
    }

    tampilkan_review(arr, *sisa);

    int indeks;
    cout << "Pilih nomor review yang ingin dihapus: ";
    cin >> indeks;

    if (indeks >= 1 && indeks <= *sisa){
        for (int i = indeks - 1; i < *sisa - 1; ++i){
            arr[i] = arr[i + 1]; //geser array ke kiri agar urut kembali
        }
        (*sisa)--; // mengurangi jumlah review yang telah dihapus sebelumny
        cout << "Berhasil Menghapus Review\n";
    } else {
        cout << "Nomor Review tidak valid\n";
    }
}


int main(){
    review arr[100]; // sebanyak 100 array untuk menyimpan review
    int sisa = 0; // menyimpan jumlah review yg telah ditambahkan
    int pilihan;
    while (true){
        cout << "\nMenu Review Tempat\n";
        cout << "1. Menambahkan Review\n";
        cout << "2. Melihat Review\n";
        cout << "3. Mengedit Review\n";
        cout << "4. Menghapus Review\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan){
            case 1:
                tambah_review(arr, &sisa);
                break;
            case 2:
                tampilkan_review(arr, sisa);
                break;
            case 3:
                update_review(arr, sisa);
                break;
            case 4:
                menghapus_review(arr, &sisa);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid\n";
        }
    }
    return 0;
}