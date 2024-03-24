/*
 * @file main.c
 * @description Projede istenilen fonksiyonların örneklerle denendiği main dosyası.
 * @assignment Proje 1
 * @date 28.11.2023
 * @author Hacer Ebra Özdemir hacerebra.ozdemir@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include "proje1.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Kullanım: %s <dosya_adı>\n", argv[0]);
        return 1;
    }

    // Ders oluştur ve her öğrenci için aldıgıDersler dizisi oluştur, her bir öğrencinin ortalamasını hesapla.
    struct Ders matematik1 = createDers("Matematik", 3, 60);
    struct Ders fizik1 = createDers("Fizik", 4, 32);
    struct Ders aldigiDersler1[10] = {matematik1, fizik1};
    float ortalamaA = notOrtalamasiniHesapla(aldigiDersler1, 2);

    struct Ders matematik2 = createDers("Matematik", 3, 30);
    struct Ders fizik2 = createDers("Fizik", 4, 60);
    struct Ders BP21 = createDers("BP2", 5, 80);
    struct Ders aldigiDersler2[10] = {matematik2, fizik2, BP21};
    float ortalamaE = notOrtalamasiniHesapla(aldigiDersler2, 3);

    struct Ders matematik3 = createDers("Matematik", 3, 73);
    struct Ders fizik3 = createDers("Fizik", 4, 59);
    struct Ders BP22 = createDers("BP2", 5, 82);
    struct Ders tarih1 = createDers("Tarih", 2, 98);
    struct Ders aldigiDersler3[10] = {matematik3, fizik3, BP22, tarih1};
    float ortalamaF = notOrtalamasiniHesapla(aldigiDersler3, 4);

    // Öğrenci oluştur
    struct Ogrenci ahmet = createOgrenci("Nisa", "Örnek", "Yazılım Mühendisliği", ortalamaA, aldigiDersler1);
    struct Ogrenci ebra = createOgrenci("Ela", "Adeka", "Bilgisayar Mühendisliği", ortalamaE, aldigiDersler2);
    struct Ogrenci elif = createOgrenci("Elif", "Özdemir", "Endüstri Mühendisliği", ortalamaF, aldigiDersler3);
    struct Ogrenci ogrenciler[] = {ahmet, ebra, elif};
    int boyut = sizeof(ogrenciler) / sizeof(ogrenciler[0]);

    // Öğrenci bilgilerini ekrana yazdır
    printf("Öğrenci Bilgileri:\n");
    printOgrenci(ahmet);
    printf("Öğrenci Bilgileri:\n");
    printOgrenci(ebra);
    printf("Öğrenci Bilgileri:\n");
    printOgrenci(elif);
    printf("\n**********************************\n");

    // Belirli bir dersten öğrencilerin aldığı notların ortalamasını hesapla
    char hedefDersAdi1[] = "Matematik";
    char hedefDersAdi2[] = "Fizik";
    float matOrtalama = calculateDersOrtalama(ogrenciler, boyut, hedefDersAdi1);
    float fizOrtalama = calculateDersOrtalama(ogrenciler, boyut, hedefDersAdi2);
    printf("%s dersinin ortalamasi: %.2f\n", hedefDersAdi1, matOrtalama);
    printf("%s dersinin ortalamasi: %.2f\n", hedefDersAdi2, fizOrtalama);
    printf("\n**********************************\n");

    // Belirli bir dersten öğrencilerin aldığı notların standart sapmasını hesapla
    float matStandartSapma = calculateDersStandartSapma(ogrenciler, boyut, hedefDersAdi1);
    float fizStandartSapma = calculateDersStandartSapma(ogrenciler, boyut, hedefDersAdi2);
    printf("%s dersinin standart sapması: %.2f\n", hedefDersAdi1, matStandartSapma);
    printf("%s dersinin standart sapması: %.2f\n", hedefDersAdi2, fizStandartSapma);
    printf("\n**********************************\n");

    // İki farklı dersin kovaryansını hesapla
    float kovaryans = calculateDersKovaryans(ogrenciler, boyut, matematik2, fizik2);
    printf("Matematik ve Fizik derslerinin kovaryansı: %.2f\n", kovaryans);
    printf("\n**********************************\n");

    // Belirli bir dersten; ders ortalamasından yüksek not alan öğrencileri ekrana yazdır
    printYuksekNotAlanOgrenciler(ogrenciler, boyut, hedefDersAdi1, matOrtalama);
    printYuksekNotAlanOgrenciler(ogrenciler, boyut, hedefDersAdi2, fizOrtalama);
    printf("\n**********************************\n");

    // Öğrenci bilgilerini dosyaya yaz
    writeOgrencilerDosyaya(ogrenciler, boyut, argv[1]);

    // Dosyadan öğrenci bilgilerini oku
    printf("\nDosyadan Okunan Öğrenci Bilgileri:\n");
    readOgrencilerDosyadan(ogrenciler, boyut, argv[1]);

    return 0;
}
