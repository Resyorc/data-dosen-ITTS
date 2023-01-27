#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char mapel[50];
    char kelamin[50];
    int nidn;
}datadosen;
// Input Data Dosen
void input(datadosen dsn[], int banding){
    for (int i = 0; i < banding; i++)
    {
        printf("Data-%d\n", i+1);
        printf("Masukkan Nama Dosen : ");
        fflush(stdin);
        scanf("%[^\n]s", &dsn[i].nama);
        printf("Masukkan NIDN/NIDK : ");
        scanf("%d", &dsn[i].nidn);
        printf("Masukkan Mapel : ");
        scanf("%s", &dsn[i].mapel);
        printf("Masukkan Jenis Kelamin L/P : ");
        fflush(stdin);
        scanf("%s", &dsn[i].kelamin);
        system("cls");
    }
    system("pause");
    system("cls");
}
// Lihat Data Dosen
void lihat(datadosen dsn[], int banding){
    int loop = 1;
    FILE *dosen;
    dosen = fopen("listdosen.txt", "r");
    printf("Jumlah data dosen : %d\n", banding);
    for (int i = 0; i < banding; i++)
    {
        printf("Data Dosen-%d\n", loop++);
        printf("Nama Dosen : %s\n", dsn[i].nama);
        printf("NIDN/NIDK : %d\n", dsn[i].nidn);
        printf("Mapel : %s\n", dsn[i].mapel);
        printf("Jenis Kelamin L/P : %s\n", dsn[i].kelamin);
        puts("");
    }
    fclose(dosen);
    system("pause");
    system("cls");
}
void search(datadosen dsn[], int banding){
    int a = 0;
    char caridosen[50];
    printf("Masukkan Nama Dosen yang ingin dicari : ");
    fflush(stdin);
    scanf("%[^\n]", &caridosen);
    for (int i = 0; i < banding; i++)
    {
        if (strstr(caridosen, dsn[i].nama))
        {
            a = 1;
            printf("Data dosen ditemukan pada urutan ke - %d\n", i+1);
            printf("Nama Dosen : %s\n", dsn[i].nama);
            printf("NIDN/NIDK : %d\n", dsn[i].nidn);
            printf("Mapel : %s\n", dsn[i].mapel);
            printf("Jenis Kelamin L/P : %s\n", dsn[i].kelamin);
        }    
    }
    if (!a)
    {
        printf("DOSEN TIDAK TERDAFTAR!!!\n");
    }
    system("pause");
    system("cls");
}
void edit(datadosen dsn[], int banding){
    char edit_nama[50];
    int a = 0;
    printf("Masukkan Nama Dosen yang ingin di edit : ");
    fflush(stdin);
    scanf("%[^\n]s", &edit_nama);
    for (int i = 0; i < banding; i++)
    {
        if (strstr(edit_nama, dsn[i].nama))
        {
            printf("Nama Dosen : ");
            fflush(stdin);
            scanf("%[^\n]s", &dsn[i].nama);
            printf("NIDN/NIDK : ");
            fflush(stdin);
            scanf("%d", &dsn[i].nidn);
            printf("Mapel : ");
            fflush(stdin);
            scanf("%s", &dsn[i].mapel);
            printf("Jenis Kelamin L/P : ");
            fflush(stdin);
            scanf("%s", &dsn[i].kelamin);
            a = 1;
            system("cls");
            printf("Data berhasil di edit\n");
            system("pause");
            system("cls");
        }
    }
    if (!a)
    {
        printf("DOSEN TIDAK TERDAFTAR!!!\n");
    }
}
void ascend(datadosen dsn[], int banding){
    for (int i = 0; i < banding; i++)
    {
        for (int j = i + 1; j < banding; j++)
        {
            if (strcmp(dsn[i].nama, dsn[j].nama) > 0)
            {
                datadosen temp = dsn[i];
                dsn[i] = dsn[j];
                dsn[j] = temp;
            }
            
        }
    }
    for (int a = 0; a < banding; a++)
        {
            printf("Data dosen urutan ke - %d\n", a+1);
            printf("Nama Dosen : %s\n", dsn[a].nama);
            printf("NIDN/NIDK : %d\n", dsn[a].nidn);
            printf("Mapel : %s\n", dsn[a].mapel);
            printf("Jenis Kelamin L/P : %s\n", dsn[a].kelamin);
            puts("");
        }
    system("pause");
    system("cls");
}
void simpan(datadosen dsn[], int banding){
    FILE *dosen;
    dosen = fopen("listdosen.txt", "a");
    for(int i = 0; i < banding; i++){
    fprintf(dosen, "%s_%d %s %s\n", dsn[i].nama, dsn[i].nidn, dsn[i].mapel, dsn[i].kelamin);
    }
    fclose(dosen);
}
void simpanedit(datadosen dsn[], int result){
    FILE *dosen;
    dosen = fopen("listdosen.txt", "w");
    for(int i = 0; i < result; i++){
    fprintf(dosen, "%s_%d %s %s\n", dsn[i].nama, dsn[i].nidn, dsn[i].mapel, dsn[i].kelamin);
    }
    fclose(dosen);
}
void muat(datadosen dsn[], int banding[]){
    FILE *dosen;
    dosen = fopen("listdosen.txt", "r");
    if (dosen == NULL)
    {
        printf("File Tidak Ditemukan\n");
    }
    
    *banding = 0;
    while(fscanf(dosen, "%[^_]_ %d %s %s\n", dsn[*banding].nama, &dsn[*banding].nidn, &dsn[*banding].mapel, dsn[*banding].kelamin) != EOF)
    {
        (*banding)++;
    }
    fclose(dosen);
}
// Main Menu Data Dosen
void main_menu(){
    datadosen dsn[50];
    int menu, total, pembanding;
    do
    {
        printf("Silahkan pilih menu dibawah ini\n");
        printf("1. Input Data Dosen\n");
        printf("2. Lihat Data Dosen\n");
        printf("3. Cari Data Dosen\n");
        printf("4. Edit Data Dosen\n");
        printf("5. Urutkan NIDK Dosen\n");
        printf("6. Keluar\n");
        printf("Masukkan nomor menu : ");
        scanf("%d", &menu);
        if (menu == 1)
        {
            system("cls");
            printf("Berapa banyak dosen yang mau di input : ");
            scanf("%d", &total);
            input(dsn, total);
            simpan(dsn, total);
        }
        if (menu == 2)
        {
            system("cls");
            muat(dsn, &pembanding);
            lihat(dsn, pembanding);
        }
        if (menu == 3)
        {
            system("cls");
            muat(dsn, &pembanding);
            search(dsn, pembanding);
        }
        if (menu == 4)
        {
            system("cls");
            muat(dsn, &pembanding);
            edit(dsn, pembanding);
            simpanedit(dsn, pembanding);
        }
        if (menu == 5)
        {
            system("cls");
            muat(dsn, &pembanding);
            ascend(dsn, pembanding);
        }
        
        }while(menu != 6);
        system("cls");
}
int main(){
    printf("Selamat Datang di menu Data Dosen\n");
    printf("----------------------------------\n");
    puts("");
    main_menu();
}