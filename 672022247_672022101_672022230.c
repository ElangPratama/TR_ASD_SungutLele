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

void delete_room() {
    int room_number;
    printf("Masukkan nomor kamar yang akan dihapus: ");
    scanf("%d", &room_number);
    struct room *current_room = head;
    struct room *previous_room = NULL;
    while (current_room != NULL) {
        if (current_room->room_number == room_number) {
            if (previous_room == NULL) {
                head = current_room->next;
            } else {
                previous_room->next = current_room->next;
            }
            free(current_room);
            printf("Kamar berhasil dihapus!\n");
            return;
        }
        previous_room = current_room;
        current_room = current_room->next;
    }
    printf("Nomor kamar tidak ditemukan.\n");
}

void update_room() {
    int room_number;
    printf("Masukkan nomor kamar yang akan diubah: ");
    scanf("%d", &room_number);
    struct room *current_room = head;
    while (current_room != NULL) {
        if (current_room->room_number == room_number) {
            printf("Masukkan tipe kamar baru: ");
            scanf("%s", current_room->room_type);
            printf("Masukkan harga baru: ");
            scanf("%d", &current_room->price);
            printf("Masukkan ketersediaan baru (1=Tersedia,0=Tidak Tersedia): ");
scanf("%d", &current_room->availability);
printf("Informasi kamar berhasil diubah!\n");
return;
}
current_room = current_room->next;
}
printf("Nomor kamar tidak ditemukan.\n");
}
void sort_rooms() {
    if (head == NULL) {
        printf("Belum ada kamar yang ditambahkan.\n");
        return;
    }
    struct room *current_room = head;
    struct room *index = NULL;
    int temp_room_number, temp_price, temp_availability;
    char temp_room_type[20];

    while (current_room != NULL) {
        index = current_room->next;

        while (index != NULL) {
            if (current_room->room_number > index->room_number) {
                temp_room_number = current_room->room_number;
                current_room->room_number = index->room_number;
                index->room_number = temp_room_number;

                strcpy(temp_room_type, current_room->room_type);
                strcpy(current_room->room_type, index->room_type);
                strcpy(index->room_type, temp_room_type);

                temp_price = current_room->price;
                current_room->price = index->price;
                index->price = temp_price;

                temp_availability = current_room->availability;
                current_room->availability = index->availability;
                index->availability = temp_availability;
            }
            index = index->next;
        }
        current_room = current_room->next;
    }
    printf("Daftar kamar berhasil diurutkan berdasarkan nomor kamar.\n");
}
void search_room() {
    int room_number;
    printf("Masukkan nomor kamar yang ingin dicari: ");
    scanf("%d", &room_number);

    struct room *current_room = head;
    while (current_room != NULL) {
        if (current_room->room_number == room_number) {
            printf("Nomor Kamar: %d\n", current_room->room_number);
            printf("Tipe Kamar: %s\n", current_room->room_type);
            printf("Harga: %d\n", current_room->price);
            printf("Ketersediaan: %s\n", current_room->availability == 1 ? "Tersedia" : "Tidak Tersedia");
            printf("\n");
            return;
        }
        current_room = current_room->next;
    }
    printf("Kamar tidak ditemukan.\n");
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
delete_room();
break;
case 4:
update_room();
            break;
        case 5:
sort_room();
            break;
        case 6:
search_room();
            break;
        case 7:

            break;
        default:

            break;
    }
}while (choice!=7);
return 0;
}
