/*
 * @file proje1.h
 * @description Projede istenilen fonksiyonların prototiplerinin yer aldığı dosya.
 * @assignment Proje 1
 * @date 28.11.2023
 * @author Hacer Ebra Özdemir hacerebra.ozdemir@stu.fsm.edu.tr
 */

#ifndef PROJE1_H
#define PROJE1_H

struct Ders
{
    char *dersAdi;
    unsigned short int kredi;
    unsigned short int puan;
};

struct Ogrenci
{
    char *ogrAdi;
    char *ogrSoyAdi;
    char *bolumu;
    float ortalama;
    struct Ders *aldigiDersler;
};

struct Ders createDers(char *dersAdi, unsigned short int kredi, unsigned short int puan);
float notOrtalamasiniHesapla(struct Ders dersler[], int dersSayisi);
struct Ogrenci createOgrenci(char *ogrAdi, char *ogrSoyAdi, char *bolumu, float ortalama, struct Ders *aldigiDersler);
void printOgrenci(struct Ogrenci ogrenci);
void printOgrenciler(struct Ogrenci *ogrenciler, int ogrenciSayisi);
float calculateDersOrtalama(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi);
float calculateDersStandartSapma(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi);
float calculateDersKovaryans(struct Ogrenci *ogrenciler, int ogrenciSayisi, struct Ders ders1, struct Ders ders2);
void printYuksekNotAlanOgrenciler(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi, float ortalamaPuan);
void writeOgrenciDosyaya(struct Ogrenci ogrenci, FILE *dosya);
void writeOgrencilerDosyaya(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dosyaAdi);
void readOgrencilerDosyadan(struct Ogrenci *ogrenciler, int ogrenciSayisi, char *dosyaAdi);

#endif
