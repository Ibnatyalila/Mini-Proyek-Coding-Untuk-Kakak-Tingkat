#include <stdio.h>
#include <string.h>
#define MAX_TUGAS 10 //Untuk menentukan jumlah max tugas yang bisa disimpan.

char tugas[MAX_TUGAS][100]; //Menggunakan array untuk menyimpan tugas dengan tugas berisi 100 karakter.
int jumlahTugas = 0; //Untuk menyimpan banyaknya tugas.

//Membuat fungsi tambahTugas untuk pilihan "Tambah tugas".
void tambahTugas() {
    if(jumlahTugas < MAX_TUGAS) {
        printf("Masukkan tugas: ");
        //Untuk membaca suatu kalimat sesuai dengan apa yang diinput oleh user, gunakan fgets.
        //Dalam fgets, terdapat variabel untuk menyimpan input, ukuran buffer (batas ukuran panjang string yang diinput oleh user), dan sumber input). 
        fgets(tugas[jumlahTugas], sizeof(tugas[jumlahTugas]), stdin);
        //Menghitung panjang string menggunakan strlen.
        int panjang = strlen(tugas[jumlahTugas]);
        //Memeriksa 2 kondisi, apakah panjang string > 0 dan apakah karakter terakhir pada string adalah newline?
        //Jika kondisi benar, ganti karakter terakhir dengan '\0' (null-terminator) agar lebih rapi.
        if(panjang > 0 && tugas[jumlahTugas][panjang-1] == '\n') {
            tugas[jumlahTugas][panjang-1] = '\0';
        }
        jumlahTugas++;
        printf("Tugas berhasil ditambahkan.\n");
    } else {
        printf("Daftar tugas sudah penuh! Hapus tugas yang sudah selesai untuk menambah tugas lagi.\n");
    }
}

//Membuat fungsi tampilkanTugas untuk pilihan "Tampilkan daftar tugas".
void tampilkanTugas() {
    if(jumlahTugas == 0) {
        printf("Belum ada tugas.\n");
    } else {
        printf("Daftar tugas: \n");
        //Jika kondisi i < jumlahTugas, maka nomor akan bertambah sesuai dengan jumlah tugas yang ditambahkan user
        //dan disimpan ke dalam array.
        for(int i = 0; i < jumlahTugas; i++) {
            printf("%d. %s\n", i+1, tugas[i]);
        }
    }
}

//Membuat fungsi hapusTugas untuk pilihan "Hapus tugas".
void hapusTugas() {
    if(jumlahTugas == 0) {
        printf("Tidak dapat menghapus tugas karena daftar tugas belum terisi.\n");
        return;
    }
    int angka;
    printf("Masukkan nomor tugas yang ingin dihapus: ");
    scanf("%d", &angka);
    //getchar() digunakan untuk menginput suatu kalimat sampai user menekan enter.
    while(getchar() != '\n');

    if(angka < 1 || angka > jumlahTugas) {
        printf("Nomor tugas tidak valid, coba lagi.\n");
        return;
    }
    for(int i = angka-1; i < jumlahTugas-1; i++){
        //Menggeser tugas (setelah tugas yang dihapus) sesudahnya menjadi ke posisi sebelumnya.
        //Sederhananya, meng-copy string dari variabel ke variabel lain.
        strcpy(tugas[i], tugas[i+1]);
    }
    jumlahTugas--;
    printf("Tugas berhasil dihapus.\n");
}

//Mulai menjalankan program setelah membuat beberapa fungsi.
int main() {
    int angka;

    //Menampilkan beberapa pilihan yang harus dipilih oleh user.
    while(1) {
        printf("**************************\n");
        printf("=== TO DO LIST ===\n");
        printf("1. Tambah tugas\n");
        printf("2. Tampilkan daftar tugas\n");
        printf("3. Hapus tugas\n");
        printf("4. Keluar\n");
        printf("**************************\n");
        printf("Pilih angka: ");
        scanf("%d", &angka);
        while(getchar() != '\n');

        //Menjalankan fungsi sesuai dengan pilihan user.
        switch(angka) {
            case 1:
                tambahTugas();
                break;
            case 2:
                tampilkanTugas();
                break;
            case 3:
                hapusTugas();
                break;
            case 4:
                printf("Anda keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    }
    return 0;
}