#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Tablonun bozulmamasi icin gereken max karakter sayisi: 13
#define ISLETME_1 "XXX"
#define ISLETME_2 "YYY"
#define ISLETME_3 "ZZZ"

// -- HELPER integer olarak para alir, string olarak para dondurur
char* para_format(int para) {
    // for example:  123456 -> 123.456
    int len = 0;
    // para uzunlugunu bul
    int temp = para;
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    char* str = malloc(len + 1);
    // uzunluk 7 ise
    if (len == 7)
    {
        sprintf(str, "%d.%d.%d", para / 1000000, (para % 1000000) / 1000, para % 1000);
    }
    // 5 ile 6 ise
    else
    {
        sprintf(str, "%d.%d", para / 1000, para % 1000);
    }
    return str;
}

// 10000 ile 300000 arasinda rastgele sayilar uretir ve bunu satislar dizisine atar.
void satis_doldur(int satislar[3][12], int satir, int sutun)
{
    int i, j;
    for (i = 0; i < satir; i++)
    {
        for (j = 0; j < sutun; j++)
        {
            // Rastgele sayilari uret ve arraye ekle
            satislar[i][j] = rand() % 290001 + 10000;
        }
    }
}

// satislar dizisindeki elemanlari tablo formatinda yazdirir
void satis_yazdir(int satislar[3][12], int satir, int sutun)
{
    int i, j;
    
    printf("\nRastgele olarak belirlenen satis miktarlari:\n\n");
    // Tablonun ust basligi
    printf("Isletme Adi: ");
    for (i = 0; i < 12; i++)
    {
        // Her ayin 10 karakterlik alani vardir, ve sola yaslanmistir.
        printf("%-10d", i + 1);
    }
    printf("\n");
    printf("-------------------------------------------------------------------");
    printf("------------------------------------------------------------------\n");

    // Tablonun geri kalan kismi
    for (i = 0; i < satir; i++)
    {
        // Isletme isimlerini yazdir
        if (i == 0)
        {
            printf("%-13s", ISLETME_1);
        }
        else if (i == 1)
        {
            printf("%-13s", ISLETME_2);
        }
        else if (i == 2)
        {
            printf("%-13s", ISLETME_3);
        }
        for (j = 0; j < sutun; j++)
        {
            // Her satisin 10 karakterlik alani vardir, ve sola yaslanmistir.
            printf("%-10s", para_format(satislar[i][j]));
        }
        printf("\n\n");
    }
}

// İşletmelerin her birinin en çok satış yaptığı ayı ve o aydaki satış miktarını ekrana yazdır
void en_cok_satis_ay(int satislar[3][12], int satir, int sutun)
{
    int i;
    int max_1, max_2, max_3;
    int ay_1, ay_2, ay_3;
    
    max_1 = satislar[0][0];
    max_2 = satislar[1][0];
    max_3 = satislar[2][0];

    ay_1 = ay_2 = ay_3 = 0;

    printf("\nIsletmelerin en cok satis yaptigi aylar:\n\n");
    // En cok satis yapan ayi
    for (i = 0; i < sutun; i++)
    {
        if (satislar[0][i] > max_1)
        {
            max_1 = satislar[0][i];
            ay_1 = i;
        }
        if (satislar[1][i] > max_2)
        {
            max_2 = satislar[1][i];
            ay_2 = i;
        }
        if (satislar[2][i] > max_3)
        {
            max_3 = satislar[2][i];
            ay_3 = i;
        }
    }

    printf("%s isletmesi en cok %d. ayda %s TL satis yapmistir.\n", ISLETME_1, ay_1 + 1, para_format(max_1));
    printf("%s isletmesi en cok %d. ayda %s TL satis yapmistir.\n", ISLETME_2, ay_2 + 1, para_format(max_2));
    printf("%s isletmesi en cok %d. ayda %s TL satis yapmistir.\n", ISLETME_3, ay_3 + 1, para_format(max_3));
    printf("-------------------------------------------------------------------");
    printf("------------------------------------------------------------------\n");
}

// Yıllık en fazla satış yapan işletmeyi bulan en_cok_satis isimli fonksiyon
void en_cok_satis(int satislar[3][12], int satir, int sutun)
{
    int i;
    int max_1, max_2, max_3;
    
    max_1 = max_2 = max_3 = 0;
    // En cok satis yapan ayi
    for (int i = 0; i < sutun; i++)
    {
        max_1 += satislar[0][i];
        max_2 += satislar[1][i];
        max_3 += satislar[2][i];
    }

    // Ilk isletme en cok satis yaptiysa
    if (max_1 > max_2 && max_1 > max_3)
    {
        printf("Yillik en fazla satis yapan isletme %s, yillik toplam %s TL satis yapmistir.\n", ISLETME_1, para_format(max_1));
    }
    // Ikinci isletme en cok satis yaptiysa
    else if (max_2 > max_1 && max_2 > max_3)
    {
        printf("Yillik en fazla satis yapan isletme %s, yillik toplam %s TL satis yapmistir.\n", ISLETME_2, para_format(max_2));
    }
    // Ucuncu isletme en cok satis yaptiysa
    else if (max_3 > max_1 && max_3 > max_2)
    {
        printf("Yillik en fazla satis yapan isletme %s, yillik toplam %s TL satis yapmistir.\n", ISLETME_3, para_format(max_3));
    }
    printf("-------------------------------------------------------------------");
    printf("------------------------------------------------------------------\n");
}

// Kullanıcı tarafından girilen ay bilgisine göre işletmelerin o ayda yaptıkları toplam satış
// miktarini hesaplayan aylik_toplam_satis fonksiyonu
void aylik_toplam_satis(int satislar[3][12])
{
    int i;
    int ay;
    int toplam;
    
    printf("Islem yapmak istediginiz ayi seciniz: ");
    scanf("%d", &ay);
    toplam = 0;
    // En cok satis yapan ayi
    toplam += satislar[0][ay - 1];
    toplam += satislar[1][ay - 1];
    toplam += satislar[2][ay - 1];
    printf("Isletmeler 2. ayda toplam %s TL satis yapmistir.\n", para_format(toplam));
    printf("-------------------------------------------------------------------");
    printf("------------------------------------------------------------------\n");
}


int main(void)
{
    srand(time(NULL));
    int satislar[3][12];
    int secim;

    satis_doldur(satislar, 3, 12);
    // Menu
    secim = 0;
    while (secim != 5)
    {
        printf("\n%50s\n", "**MENU**");
        printf("1. Isletmelerin yillik satislarini goruntuleme\n");
        printf("2. Isletmelerin en cok satis yaptigi aylari ve satis miktarlarini goruntuleme\n");
        printf("3. Yillik en fazla satis yapan isletmeyi goruntuleme\n");
        printf("Ay bilgisine gore toplam satis miktari goruntuleme\n");
        printf("5. Cikis\n");

        printf("\nYapmak istediginiz islemi seciniz: ");
        scanf("%d", &secim);
        switch (secim)
        {
            case 1:
                satis_yazdir(satislar, 3, 12);
                break;
            case 2:
                en_cok_satis_ay(satislar, 3, 12);
                break;
            case 3:
                en_cok_satis(satislar, 3, 12);
                break;
            case 4:
                aylik_toplam_satis(satislar);
                break;
            case 5:
                printf("Program sonlandiriliyor...\n");
                break;
            default:
                printf("Hatali secim yaptiniz.\n");
                break;
        }
    }


    return 0;
}