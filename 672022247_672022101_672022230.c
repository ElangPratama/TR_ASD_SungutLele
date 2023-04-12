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
// Fungsi untuk menambah kamar baru ke linked list
void add_room() {
    struct room *new_room = (struct room *) malloc(sizeof(struct room));
    printf("Masukkan nomor kamar: ");
    scanf("%d", &new_room->room_number);
    printf("Masukkan tipe kamar: ");
    scanf("%s", new_room->room_type);
    printf("Masukkan harga: ");
    scanf("%d", &new_room->price);
    printf("Masukkan ketersediaan (1=Tersedia, 0=Tidak Tersedia): ");
    scanf("%d", &new_room->availability);
    new_room->next = head;
    head = new_room;
    printf("Kamar berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan daftar kamar hotel
void show_rooms() {
    if (head == NULL) {
        printf("Belum ada kamar yang ditambahkan.\n");
        return;
    }
    printf("Daftar kamar:\n");
    struct room *current_room = head;
    while (current_room != NULL) {
        printf("Nomor Kamar: %d\n", current_room->room_number);
        printf("Tipe Kamar: %s\n", current_room->room_type);
        printf("Harga: %d\n", current_room->price);
        printf("Ketersediaan: %s\n", current_room->availability == 1 ? "Tersedia" : "Tidak Tersedia");
        printf("\n");
        current_room = current_room->next;
    }
}



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
add_room();
break;
case 2:
show_rooms();
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
