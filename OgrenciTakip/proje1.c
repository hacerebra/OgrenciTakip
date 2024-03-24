/*
 * @file proje1.c
 * @description Projede istenilen; createDers, createOgrenci, notOrtalamasiniHesapla, printOgrenci, printOgrenciler, calculateDersOrtalama, calculateDersStandartSapma, calculateDersKovaryans, printYuksekNotAlanOgrenciler, writeOgrencilerDosyaya, readOgrencilerDosyadan fonksiyonları içeren dosya.
 * @assignment Proje 1
 * @date 28.11.2023
 * @author Hacer Ebra Özdemir hacerebra.ozdemir@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "proje1.h"

// İlgili değerleri alıp bir Ders struct döndüren fonksiyon
struct Ders createDers(char *dersAdi, unsigned short int kredi, unsigned short int puan)
{
    struct Ders yeniDers;
    yeniDers.dersAdi = (char *)malloc(256 * sizeof(char));
    strcpy(yeniDers.dersAdi, dersAdi);
    yeniDers.kredi = kredi;
    yeniDers.puan = puan;
    return yeniDers;
    free(yeniDers.dersAdi);
}

// Öğrenci oluşturulurken parametre olarak girilen ortalamanın hesaplanmasını sağlayan fonksiyon.
float notOrtalamasiniHesapla(struct Ders dersler[], int dersSayisi)
{
    float toplamPuan = 0.0;
    int toplamKredi = 0;

    for (int i = 0; i < dersSayisi; ++i)
    {
        toplamPuan += dersler[i].puan * dersler[i].kredi;
        toplamKredi += dersler[i].kredi;
    }
    // Not ortalamasını hesapla
    if (toplamKredi > 0)
    {
        return toplamPuan / toplamKredi;
    }
    else
    {
        // Eğer hiç kredi alınmamışsa -1 değeri döner.
        return -1.0;
    }
}

// İlgili değerleri alıp bir Ogrenci struct döndüren fonksiyon.
struct Ogrenci createOgrenci(char *ogrAdi, char *ogrSoyAdi, char *bolumu, float ortalama, struct Ders *aldigiDersler)
{
    struct Ogrenci yeniOgrenci;
    yeniOgrenci.ogrAdi = (char *)malloc(256 * sizeof(char));
    strcpy(yeniOgrenci.ogrAdi, ogrAdi);
    yeniOgrenci.ogrSoyAdi = (char *)malloc(256 * sizeof(char));
    strcpy(yeniOgrenci.ogrSoyAdi, ogrSoyAdi);
    yeniOgrenci.bolumu = (char *)malloc(256 * sizeof(char));
    strcpy(yeniOgrenci.bolumu, bolumu);
    yeniOgrenci.ortalama = ortalama;
    yeniOgrenci.aldigiDersler = (struct Ders *)malloc(10 * sizeof(struct Ders));
    for (int i = 0; i < 10; i++)
    {
        if (aldigiDersler[i].dersAdi != NULL)
        {
            yeniOgrenci.aldigiDersler[i] = aldigiDersler[i];
        }
        else
        {
            // Ders adı NULL ise, diğer alanları da sıfırla.
            yeniOgrenci.aldigiDersler[i].dersAdi = NULL;
            yeniOgrenci.aldigiDersler[i].kredi = 0;
            yeniOgrenci.aldigiDersler[i].puan = 0;
        }
    }
    return yeniOgrenci;
    free(yeniOgrenci.aldigiDersler);
    free(yeniOgrenci.bolumu);
    free(yeniOgrenci.ogrAdi);
    free(yeniOgrenci.ogrSoyAdi);
}

// Öğrenci bilgilerini yazdıran fonksiyon.
void printOgrenci(struct Ogrenci ogrenci)
{
    printf("Ogrenci Adi: %s %s\n", ogrenci.ogrAdi, ogrenci.ogrSoyAdi);
    printf("Bolumu: %s\n", ogrenci.bolumu);
    printf("Ortalama: %.2f\n", ogrenci.ortalama);

    // Dersleri yazdırma
    for (int i = 0; i < 10; i++)
    {
        if (ogrenci.aldigiDersler[i].dersAdi != NULL)
        {
            printf("Ders Adı: %s, Kredi: %hu, Puan: %hu\n", ogrenci.aldigiDersler[i].dersAdi, ogrenci.aldigiDersler[i].kredi, ogrenci.aldigiDersler[i].puan);
        }
    }
    printf("\n");
}

// Parametre olarak Ogrenci türünden bir dizi alıp bilgilerini yazdıran fonksiyon.
void printOgrenciler(struct Ogrenci *ogrenciler, int ogrenciSayisi)
{
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        printf("Öğrenci Adı: %s %s\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi);
        printf("Bölümü: %s\n", ogrenciler[i].bolumu);
        printf("Ortalama: %.2f\n", ogrenciler[i].ortalama);

        // Dersleri yazdırma
        for (int j = 0; j < 10; j++)
        {
            if (ogrenciler[i].aldigiDersler[j].dersAdi != NULL)
            {
                printf("Ders Adı: %s, Kredi: %hu, Puan: %hu\n", ogrenciler[i].aldigiDersler[j].dersAdi, ogrenciler[i].aldigiDersler[j].kredi, ogrenciler[i].aldigiDersler[j].puan);
            }
        }
        printf("\n");
    }
}

// Parametre olarak aldığı dersAdi değerine göre bir dersin aritmetik ortalamasını hesaplayan fonksiyon.
float calculateDersOrtalama(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi)
{
    float toplamPuan = 0;
    int ogrenciSayac = 0;

    for (int i = 0; i < ogrenciSayisi; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0)
            {
                toplamPuan += ogrenciler[i].aldigiDersler[j].puan;
                ogrenciSayac++;
                break;
            }
        }
    }

    return toplamPuan / ogrenciSayac;
}

// Parametre olarak aldığı dersAdi değerine göre bir dersin standart sapmasını hesaplayan fonksiyon.
float calculateDersStandartSapma(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi)
{
    float ortalama = calculateDersOrtalama(ogrenciler, ogrenciSayisi, dersAdi);
    float toplamKareFark = 0;
    int ogrenciSayac = 0;

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        for (int j = 0; j < ogrenciSayisi; j++)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0)
            {
                toplamKareFark += pow(ogrenciler[i].aldigiDersler[j].puan - ortalama, 2);
                ogrenciSayac++;
                break;
            }
        }
    }
    return sqrt(toplamKareFark / ogrenciSayac);
}

// Parametre olarak aldığı Ders türünden iki dersin kovaryansını hesaplayan fonksiyon.
float calculateDersKovaryans(struct Ogrenci *ogrenciler, int ogrenciSayisi, struct Ders ders1, struct Ders ders2)
{

    float ortalamaDers1 = calculateDersOrtalama(ogrenciler, ogrenciSayisi, ders1.dersAdi);
    float ortalamaDers2 = calculateDersOrtalama(ogrenciler, ogrenciSayisi, ders2.dersAdi);

    float Kovaryans = 0;
    int Ders1Alansayisi = 0;
    int Ders2Alansayisi = 0;

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, ders1.dersAdi) == 0)
            {
                float fark1 = ogrenciler[i].aldigiDersler[j].puan - ortalamaDers1;
                for (int k = 0; k < 10; k++)
                {
                    if (strcmp(ogrenciler[i].aldigiDersler[k].dersAdi, ders2.dersAdi) == 0)
                    {
                        float fark2 = ogrenciler[i].aldigiDersler[k].puan - ortalamaDers2;
                        Kovaryans += fark1 * fark2;
                        Ders1Alansayisi++;
                        Ders2Alansayisi++;
                        break;
                    }
                }
                break;
            }
        }
    }

    if (Ders1Alansayisi == 0 || Ders2Alansayisi == 0)
    {
        printf("Belirtilen derslerden en az birini alan ogrenci bulunamadi.\n");
        return -1;
    }

    return Kovaryans / (Ders1Alansayisi - 1);
}

// Parametre olarak aldığı dersAdi değerine göre bir dersin ortalama puanından daha yüksek not almış öğrencileri listeleyen fonksiyon.
void printYuksekNotAlanOgrenciler(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi, float ortalamaPuan)
{
    if (ortalamaPuan == -1)
    {
        return;
    }

    printf("%s dersinden %.2f puanın üzerinde not alan öğrenciler:\n", dersAdi, ortalamaPuan);
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        for (int j = 0; j < ogrenciSayisi; j++)
        {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0)
            {
                if (ogrenciler[i].aldigiDersler[j].puan > ortalamaPuan)
                {
                    printf("%s %s\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi);
                }

                break; // Her öğrenciyi sadece bir kez yazdırmak için
            }
        }
    }
}

// writeOgrencilerDosyaya fonksiyonu için kullandığım tek bir öğrencinin bilgilerinin dosyaya yazan fonksiyon.
void writeOgrenciDosyaya(struct Ogrenci ogrenci, FILE *dosya)
{
    fprintf(dosya, "Ogrenci Adi: %s %s\n", ogrenci.ogrAdi, ogrenci.ogrSoyAdi);
    fprintf(dosya, "Bolumu: %s\n", ogrenci.bolumu);
    fprintf(dosya, "Ortalama: %.2f\n", ogrenci.ortalama);
    // Dersleri dosyaya yazdırma
    for (int i = 0; i < 10; i++)
    {
        if (ogrenci.aldigiDersler[i].dersAdi != NULL)
        {

            fprintf(dosya, "Ders Adı: %s, Kredi: %hu, Puan: %hu\n", ogrenci.aldigiDersler[i].dersAdi, ogrenci.aldigiDersler[i].kredi, ogrenci.aldigiDersler[i].puan);
        }
    }
    fprintf(dosya, "\n");
}

// Tüm öğrenci bilgilerini bir dosyaya yazan fonksiyon.
void writeOgrencilerDosyaya(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL)
    {
        perror("Dosya açma hatası");
        return;
    }

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        writeOgrenciDosyaya(ogrenciler[i], dosya);
    }
    fclose(dosya);
}

// Dosyadan öğrenci bilgilerini okuyan fonksiyon.
void readOgrencilerDosyadan(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL)
    {
        perror("Dosya açma hatası");
        return;
    }
    printOgrenciler(ogrenciler, ogrenciSayisi);
    printf("Dosyadan öğrenci bilgileri okunudu.");
    int i = 0;
    while (fscanf(dosya, "Öğrenci Adı: %s %s", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi) == 2)
    {
        fscanf(dosya, "Bölümü: %s", ogrenciler[i].bolumu);
        fscanf(dosya, "Ortalama: %f", &ogrenciler[i].ortalama);

        for (int j = 0; j < 10; j++)
        {
            if (fscanf(dosya, "Ders Adı: %s, Kredi: %hu, Puan: %hu",
                       ogrenciler[i].aldigiDersler[j].dersAdi,
                       &ogrenciler[i].aldigiDersler[j].kredi,
                       &ogrenciler[i].aldigiDersler[j].puan) != 3)
            {
                fprintf(stderr, "Dosya format hatası: Ders bilgileri okunamadı.\n");
                fclose(dosya);
                return;
            }
        }
        i++;
        fclose(dosya);
    }
}
