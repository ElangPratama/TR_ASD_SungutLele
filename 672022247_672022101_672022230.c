
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>

void delay(void){
int delay;
delay=1;
while(delay<100000){
    delay++;
}
}


COORD coord = {X:0,Y:0};
void gotoxy(int x,int y){
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


//KODE PANAH_________________________________________________________________________________________________________________________________
void panah(int posisiMenu, int posisiPanah){
    if(posisiPanah==posisiMenu)
    printf("==>");
    else printf("   ");
}


void login_(){

    //LOGIN-------------------------------------------------------------
system("color 07");
char username[50];
char pass[50];
login:

printf("-----------------------------------\n");

printf("[Username]:");

printf("                        |");
printf("\n-----------------------------------");
gotoxy(12,1);
scanf("%[^\n]s",&username);
system("cls");

printf("-----------------------------------\n");
printf("[CODE]:");
printf("                            |");
printf("\n-----------------------------------");
fflush(stdin);

char ch;
int l=0;
int x=10;
while ((ch=(char)_getch())!='\r'){


    if(ch==8){
    pass[l]='\0';
    gotoxy(x-1,1);
    printf(" ");
    x--;
    l--;
    }
    else{
pass[l]=ch;
gotoxy(x,1);
printf("*");
   x++;
   l++;}

}
if(strcmp(username,"admin")==0){
if(strcmp(pass,"ganteng")==0){
    printf("\n\n\nLOGIN SUKSES !!");
}
else{

printf("\n\n SALAH, MOHON CEK KEMBALI\n\n");
system("pause");
system("cls");
goto login;
}
}
else{
    printf("\n\n SALAH,MOHON CEK KEMBALI\n\n");
    system("pause");
    system("cls");
    goto login;
}
int m;
//LOADING_--------------------------------------------------------------------------------------------------------------------
load:
for(m=1;m<=100;m++){
      int i;
      int j;

    // Calculate the center of the screen
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    int center_x = info.dwSize.X / 2;
    int center_y = info.dwSize.Y / 2;
    int line_y = center_y - 2;

    // garis loading atas
    gotoxy(center_x - 22, line_y);
    for(j = 0; j < 44; j++){
        printf("-");}

    // garis loading bawah
    gotoxy(center_x - 22, line_y + 4);
    for(j = 0; j < 44; j++){
        printf("-");}

    for(m = 1; m <= 100; m++){
        // loading______________________________________________________________________
        gotoxy(center_x - 7, center_y);
        system("color A");
        printf("L O A D I N G %i%% ", m);
        delay();
    }
    system("cls");

}

 }

// Struktur data untuk kamar hotel
struct ruang {
    int nomor_ruang;
    char ruang_type[20];
    int price;
    int ketersediaan;
    struct ruang *next;
};
// Linked list untuk menyimpan daftar kamar hotel
struct ruang *head = NULL;
// Fungsi untuk menambah kamar baru ke linked list
void tambah_ruang() {
    struct ruang *tambah_ruang = (struct ruang *) malloc(sizeof(struct ruang));
    printf("Masukkan nomor kamar: ");
    scanf("%d", &tambah_ruang->nomor_ruang);
    printf("Masukkan tipe kamar: ");
    scanf("%s", tambah_ruang->ruang_type);
    printf("Masukkan harga: ");
    scanf("%d", &tambah_ruang->price);
    printf("Masukkan ketersediaan (1=Kamar Tersedia, 0= Kamar Tidak Tersedia): ");
    scanf("%d", &tambah_ruang->ketersediaan);

    tambah_ruang->next = head;
    head = tambah_ruang;
    printf("Kamar berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan daftar kamar hotel
void tampil_ruang() {
    if (head == NULL) {
        printf("Belum ada kamar yang ditambahkan.\n");
        return;
    }
    printf("Daftar kamar:\n");
    struct ruang *informasi_ruang = head;
    while (informasi_ruang != NULL) {
        printf("Nomor Kamar: %d\n", informasi_ruang->nomor_ruang);
        printf("Tipe Kamar: %s\n", informasi_ruang->ruang_type);
        printf("Harga: %d\n", informasi_ruang->price);
        printf("Ketersediaan: %s\n", informasi_ruang->ketersediaan == 1 ? "Tersedia" : "Tidak Tersedia");
        printf("\n");
        informasi_ruang = informasi_ruang->next;
    }
}

//delete----------------------------------------------------------
void delete_ruang() {
    int nomor_ruang;
    printf("Masukkan nomor kamar yang akan dihapus: ");
    scanf("%d", &nomor_ruang);
    struct ruang *informasi_ruang = head;
    struct ruang *ruang_sebelumny = NULL;
    while (informasi_ruang != NULL) {
        if (informasi_ruang->nomor_ruang == nomor_ruang) {
            if (ruang_sebelumny == NULL) {
                head = informasi_ruang->next;
            } else {
                ruang_sebelumny->next = informasi_ruang->next;
            }
            free(informasi_ruang);
            printf("Kamar berhasil dihapus!\n");
            return;
        }
        ruang_sebelumny = informasi_ruang;
        informasi_ruang = informasi_ruang->next;
    }
    printf("Nomor kamar tidak ditemukan.\n");
}

//update------------------------------------------------------------
void update_ruang() {
    int nomor_ruang;
    printf("Masukkan nomor kamar yang akan diubah: ");
    scanf("%d", &nomor_ruang);
    struct ruang *informasi_ruang = head;
    while (informasi_ruang != NULL) {
        if (informasi_ruang->nomor_ruang == nomor_ruang) {
            printf("Masukkan tipe kamar baru: ");
            scanf("%s", informasi_ruang->ruang_type);
            printf("Masukkan harga baru: ");
            scanf("%d", &informasi_ruang->price);
            printf("Masukkan ketersediaan baru (1=Tersedia,0=Tidak Tersedia): ");
            scanf("%d", &informasi_ruang->ketersediaan);

            printf("Informasi kamar berhasil diubah!\n");
return;
}
informasi_ruang = informasi_ruang->next;
}
printf("Nomor kamar tidak ditemukan.\n");
}


//S O R T I N G______________________________________________
void sort_ruang() {
if (head == NULL) {
printf("Belum ada kamar yang ditambahkan.\n");
return;
}
struct ruang *informasi_ruang = head;
struct ruang *next_ruang = NULL;
int ganti;
do {

ganti = 0;
informasi_ruang = head;
while (informasi_ruang->next != next_ruang) {
if (informasi_ruang->nomor_ruang > informasi_ruang->next->nomor_ruang) {
int temp_number = informasi_ruang->nomor_ruang;
char temp_type[20];
int temp_price = informasi_ruang->price;
int temp_ketersediaan = informasi_ruang->ketersediaan;

strcpy(temp_type, informasi_ruang->ruang_type);
informasi_ruang->nomor_ruang = informasi_ruang->next->nomor_ruang;
strcpy(informasi_ruang->ruang_type, informasi_ruang->next->ruang_type);
informasi_ruang->price = informasi_ruang->next->price;
informasi_ruang->ketersediaan = informasi_ruang->next->ketersediaan;
informasi_ruang->next->nomor_ruang = temp_number;
strcpy(informasi_ruang->next->ruang_type, temp_type);
informasi_ruang->next->price = temp_price;
informasi_ruang->next->ketersediaan = temp_ketersediaan;
ganti = 1;
}
informasi_ruang = informasi_ruang->next;
}
next_ruang = informasi_ruang;
} while (ganti);
printf("Daftar kamar berhasil diurutkan berdasarkan nomor kamar!\n");
}



//SEARCHING________________________________________________________________

void search_ruang() {
int nomor_ruang;
printf("Masukkan nomor kamar yang dicari: ");
scanf("%d", &nomor_ruang);
struct ruang *informasi_ruang = head;
while (informasi_ruang != NULL) {
if (informasi_ruang->nomor_ruang == nomor_ruang) {
printf("Nomor Kamar: %d\n", informasi_ruang->nomor_ruang);
printf("Tipe Kamar: %s\n", informasi_ruang->ruang_type);
printf("Harga: %d\n", informasi_ruang->price);
printf("Ketersediaan: %s\n", informasi_ruang->ketersediaan == 1 ? "Tersedia" : "Tidak Tersedia");
printf("\n");
return;
}
informasi_ruang = informasi_ruang->next;
}
printf("Nomor kamar tidak ditemukan.\n");
}


//MAIN__________________________________________________________________________________________________________

int main() {

login_();
int keyPressed=0;
int posisi=1;
int menu;
int k,l;
while(keyPressed!=13){
system("cls");
printf("\n");

 CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    int center_x = info.dwSize.X / 2;
    int center_y = info.dwSize.Y / 2;
    // Calculate the position for the lines
    int line_y = center_y - 2;


menu:
     // garis  atas
    gotoxy(center_x - 20, line_y-11);
    for(k = 0; k < 44; k++){
        printf("#");}

    // garis bawah
    gotoxy(center_x - 20, line_y + 4);
    for(k = 0; k < 44; k++){
        printf("#");}

system("COLOR 3F");
gotoxy(center_x - 4, center_y-12);
printf("H O T E L  N G A W I ! !\n");
gotoxy(center_x - 7, center_y-9);
panah(1, posisi);printf("1. Tambah kamar baru\n");
gotoxy(center_x - 7, center_y-8);
panah(2, posisi);printf("2. Tampilkan daftar kamar\n");
gotoxy(center_x - 7, center_y-7);
panah(3, posisi);printf("3. Hapus kamar\n");
gotoxy(center_x - 7, center_y-6);
panah(4, posisi);printf("4. Ubah informasi kamar\n");
gotoxy(center_x - 7, center_y-5);
panah(5, posisi);printf("5. Urutkan daftar kamar\n");
gotoxy(center_x - 7, center_y-4);
panah(6, posisi);printf("6. Cari kamar\n");
gotoxy(center_x - 7, center_y-3);
panah(7, posisi);printf("7. Keluar\n");


        keyPressed=getch();
        if(keyPressed==72)posisi--;
        else if(keyPressed==80)posisi++;
        else posisi=posisi;
        if(posisi>7)posisi=1;
        if(posisi<1)posisi=7;}


switch (posisi) {
case 1:
system("cls");
printf("Daftar jenis kamar:\n");
printf("KAMAR KECIL||Nomor 10-20||200K\n");
printf("KAMAR REGULER||Nomor 30-40||500K\n");
printf("KAMAR PREMIUM||Nomor 50-60||1JT\n");
printf("KAMAR VIP||Nomor 70-100||1,5JT\n\n");


tambah_ruang();
getch();
system("cls");
goto menu;


case 2:
    system("cls");
tampil_ruang();
getch();
system("cls");
goto menu;

case 3:
    system("cls");
delete_ruang();
getch();
system("cls");
goto menu;

case 4:
system("cls");
update_ruang();
getch();
system("cls");
goto menu;

case 5:
system("cls");
sort_ruang();
getch();
system("cls");
goto menu;

case 6:
system("cls");
search_ruang();
getch();
system("cls");
goto menu;


case 7:

break;


    }
}


