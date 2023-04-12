#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk kamar hotel
struct room {
    int room_number;
    char room_type[20];
    int price;
    int availability;
    struct room *next;
};
// Linked list untuk menyimpan daftar kamar hotel
struct room *head = NULL;
int main() {
int choice;
do {
printf("\n");
printf("Menu:\n");
printf("1. Tambah kamar baru\n");
printf("2. Tampilkan daftar kamar\n");
printf("3. Hapus kamar\n");
printf("4. Ubah informasi kamar\n");
printf("5. Urutkan daftar kamar\n");
printf("6. Cari kamar\n");
printf("7. Keluar\n");
printf("Masukkan pilihan Anda: ");
scanf("%d", &choice);
switch (choice) {
case 1:

break;
case 2:

break;
case 3:

break;
case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        default:

            break;
    }
}while (choice!=7);
return 0;
}
