#include <iostream>
#include <locale.h>
#include <Windows.h>

using namespace std;

float girdiSicaklik, girdiNem;
int flitrelenenSicaklikDegeriSayisi = 0, flitrelenenNemDegeriSayisi = 0;
float cokDüsükSon = 0.75, düsükSon = 1.5, ortaSon = 3, yüksekSon = 4.25, cokYüksekSon = 4.875; 

void MaxOrtaMethod(float x, float x1) {
    float res = x + x1;
    float y = res / 2;
    cout << y;
}

class nem
{
public:
    nem() {};

    nem(string derece, float deger)
    {
        nemDerecesi = derece;
        nemDegeri = deger;
    }

    void nemBastir()
    {
        cout << "Nem Derecesi: " << nemDerecesi << "  " << "Nem Derecesinin Değeri: " << nemDegeri << "\n";
    }

    float nemDegeriniAl()
    {
        return nemDegeri;
    }
    string nemDerecesiniAl()
    {
        return nemDerecesi;
    }

private:
    string nemDerecesi;
    float  nemDegeri;
};

class sicaklik
{
public:
    sicaklik() {};

    sicaklik(string derece, float deger)
    {
        sicaklikDerecesi = derece;
        sicaklikDegeri = deger;
    }

    void sicaklikBastir()
    {
        cout << "Sıcaklık Derecesi: " << sicaklikDerecesi << "  " << "Sıcaklık Derecesinin Değeri: " << sicaklikDegeri << "\n";
    }

    float sicaklikDegeriniAl()
    {
        return sicaklikDegeri;
    }

    string sicaklikDerecesiniAl()
    {
        return sicaklikDerecesi;
    }

private:
    string sicaklikDerecesi;
    float  sicaklikDegeri;

};

class isitma
{
public:
    isitma() {};

    isitma(string derece, float deger)
    {
        isitmaDerecesi = derece;
        isitmaDegeri = deger;
    }
    void isitmaBastir()
    {
        cout << "Isıtma Derecesi: " << isitmaDerecesi << "  " << "Isıtma Derecesinin Değeri: " << isitmaDegeri << "\n";
    }

    float isitmaDegeriniAl()
    {
        return isitmaDegeri;
    }
    string isitmaDerecesiniAl()
    {
        return isitmaDerecesi;
    }
private:
    string isitmaDerecesi;
    float isitmaDegeri;
};

sicaklik sicaklik_degerleri[5];
nem nem_degerleri[5];
isitma isitma_degerleri[25]; 
sicaklik flitreSicaklikDegerleri[5];
nem flitreNemDegerleri[5];
isitma flitreIsıtmaDegerleri[5];
float durulastırmaOrtaNoktaları[5] = { cokDüsükSon, düsükSon, ortaSon, yüksekSon, cokYüksekSon};

void kararSicaklik()
{   
    if (girdiSicaklik > 10)
    {
        sicaklik_degerleri[0] = sicaklik("Çok Düşük", 0);

    }
    else
    {
        if ((-10) <= girdiSicaklik && girdiSicaklik <= 0)
        {
            sicaklik_degerleri[0] = sicaklik("Çok Düşük", 1);

        }
        else if (0 <= girdiSicaklik && girdiSicaklik <= 10)
        {

            float cokDüsükFormul1 = ((10) - girdiSicaklik) / 10;
            sicaklik_degerleri[0] = sicaklik("Çok Düşük", cokDüsükFormul1);

        }
    }
    
    if (girdiSicaklik < 0 || girdiSicaklik > 15)
    {
        sicaklik_degerleri[1] = sicaklik("Düşük", 0);
    }
    else
    {
        if ((0) <= girdiSicaklik && girdiSicaklik <= 7.5)
        {
            float düsükFormul1 = girdiSicaklik / 7.5;
            sicaklik_degerleri[1] = sicaklik("Düşük", düsükFormul1);

        }
        else if (7.5 <= girdiSicaklik && girdiSicaklik <= 15)
        {

            float düsükFormul2 = ((15) - girdiSicaklik) / 7.5;
            sicaklik_degerleri[1] = sicaklik("Düşük", düsükFormul2);
        }
    }
    
    if (girdiSicaklik < 14 || girdiSicaklik> 26)
    {
        sicaklik_degerleri[2] = sicaklik("Orta", 0);
    }
    else
    {
        if ((14) <= girdiSicaklik && girdiSicaklik <= 20)
        {
            float ortaFormul1 = ((girdiSicaklik - (14)) / 6);
            sicaklik_degerleri[2] = sicaklik("Orta", ortaFormul1);

        }
        else if (20 <= girdiSicaklik && girdiSicaklik <= 26)
        {
            float ortaFormul2 = ((26) - girdiSicaklik) / 6;
            sicaklik_degerleri[2] = sicaklik("Orta", ortaFormul2);
        }

    }
    
    if (girdiSicaklik < 20 || girdiSicaklik> 40)
    {
        sicaklik_degerleri[3] = sicaklik("Yüksek", 0);
    }
    else
    {
        if ((20) <= girdiSicaklik && girdiSicaklik <= 30)
        {
            float yüksekFormul1 = (girdiSicaklik - (20)) / 10;
            sicaklik_degerleri[3] = sicaklik("Yüksek", yüksekFormul1);
        }
        else if (30 <= girdiSicaklik && girdiSicaklik <= 40)
        {
            float yüksekFormul2 = ((40) - girdiSicaklik) / 10;
            sicaklik_degerleri[3] = sicaklik("Yüksek", yüksekFormul2);
        }
    }
    
    if (girdiSicaklik < 30 || girdiSicaklik> 50)
    {
        sicaklik_degerleri[4] = sicaklik("Çok Yüksek", 0);
    }
    else
    {
        if ((30) <= girdiSicaklik && girdiSicaklik <= 40)
        {
            float cokYüksekFormul1 = (girdiSicaklik - (30)) / 10;
            sicaklik_degerleri[4] = sicaklik("Çok Yüksek", cokYüksekFormul1);
        }
        else if (40 <= girdiSicaklik && girdiSicaklik <= 50)
        {
            sicaklik_degerleri[4] = sicaklik("Çok Yüksek", 1);
        }
    }

}    

void kararNem()
{
    if (girdiNem > 40)
    {
        nem_degerleri[0] = nem("Çok Düşük", 0);
    }
    else
    {
        if ((0) <= girdiNem && girdiNem <= 20)
        {
            nem_degerleri[0] = nem("Çok Düşük", 1);
        }
        else if (20 <= girdiNem && girdiNem <= 40)
        {
            float FormulNem = ((40) - girdiNem) / 20;
            nem_degerleri[0] = nem("Çok Düşük", FormulNem);
        }
    }

    if (girdiNem < 0 || girdiNem > 59)
    {
        nem_degerleri[1] = nem("Düşük", 0);
    }
    else
    {
        if ((20) <= girdiNem && girdiNem <= 39.5)
        {
            float düsükFormul1 = ((girdiNem)-20) / 19.5;
            nem_degerleri[1] = nem("Düşük", düsükFormul1);

        }
        else if (39.5 <= girdiNem && girdiNem <= 59)
        {
            float formulNem2 = ((59) - girdiNem) / 19.5;
            nem_degerleri[1] = nem("Düşük", formulNem2);
        }
    }

    if (girdiNem < 50 || girdiNem > 70)
    {
        nem_degerleri[2] = nem("Orta", 0);
    }
    else
    {
        if ((50) <= girdiNem && girdiNem <= 60)
        {
            float formulOrta = ((girdiNem - (54)) / 10);
            nem_degerleri[2] = nem("Orta", formulOrta);
        }
        else if (60 <= girdiNem && girdiNem <= 70)
        {
            float formulOrta2 = ((70) - girdiNem) / 10;
            nem_degerleri[2] = nem("Orta", formulOrta2);

        }
    }
    

    if (girdiNem < 60 || girdiNem > 90)
    {
        nem_degerleri[3] = nem("Yüksek", 0);
    }
    else
    {
        if ((60) <= girdiNem && girdiNem <= 75)
        {

            float yüksekFormul1 = (girdiNem - (60)) / 15;
            nem_degerleri[3] = nem("Yüksek", yüksekFormul1);

        }
        else if (75 <= girdiNem && girdiNem <= 90)
        {

            float yüksekFormul2 = ((90) - girdiNem) / 15;
            nem_degerleri[3] = nem("Yüksek", yüksekFormul2);

        }
    }
    
    if (girdiNem < 80 || girdiNem > 100)
    {
        nem_degerleri[4] = nem("Çok Yüksek", 0);
    }
    else
    {
        if ((80) <= girdiNem && girdiNem <= 90)
        {
            float cokYüksekFormul1 = (girdiNem - (80)) / 10;
            nem_degerleri[4] = nem("Çok Yüksek", cokYüksekFormul1);

        }
        else if (90 <= girdiNem && girdiNem <= 100)
        {
            nem_degerleri[4] = nem("Çok Yüksek", 1);
        }
    }
}

string isitmaTablosu[5][5] = {
    {"Çok Yüksek", "Çok Yüksek", "Yüksek", "Yüksek", "Yüksek"},
    {"Yüksek", "Yüksek", "Yüksek", "Orta", "Orta"},
    {"Orta", "Orta", "Orta", "Orta", "Düşük"},
    {"Düşük", "Düşük", "Düşük", "Düşük", "Düşük"},
    {"Çok Düşük", "Çok Düşük", "Çok Düşük", "Çok Düşük", "Çok Düşük"}
};

void kararIsitma()
{
    int sicaklikIndex;
    int nemIndex;

    for (int i = 0; i < flitrelenenSicaklikDegeriSayisi; i++) 
    {
        for (int j = 0; j < flitrelenenNemDegeriSayisi; j++)  
        {
            if (flitreSicaklikDegerleri[i].sicaklikDerecesiniAl() == "Çok Düşük")
                sicaklikIndex = 0;
            else if (flitreSicaklikDegerleri[i].sicaklikDerecesiniAl() == "Düşük")
                sicaklikIndex = 1;
            else if (flitreSicaklikDegerleri[i].sicaklikDerecesiniAl() == "Orta")
                sicaklikIndex = 2;
            else if (flitreSicaklikDegerleri[i].sicaklikDerecesiniAl() == "Yüksek")
                sicaklikIndex = 3;
            else if (flitreSicaklikDegerleri[i].sicaklikDerecesiniAl() == "Çok Yüksek")
                sicaklikIndex = 4;


            if (flitreNemDegerleri[j].nemDerecesiniAl() == "Çok Düşük")
                nemIndex = 0;
            else if (flitreNemDegerleri[j].nemDerecesiniAl() == "Düşük")
                nemIndex = 1;
            else if (flitreNemDegerleri[j].nemDerecesiniAl() == "Orta")
                nemIndex = 2;
            else if (flitreNemDegerleri[j].nemDerecesiniAl() == "Yüksek")
                nemIndex = 3;
            else if (flitreNemDegerleri[j].nemDerecesiniAl() == "Çok Yüksek")
                nemIndex = 4;

            cout << "\n\nIsıtma Derecesi: " << isitmaTablosu[sicaklikIndex][nemIndex];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish");
sicaklikMenu:
    cout << "Sıcaklık giriniz: ";
    cin >> girdiSicaklik;
nemMenu:
    cout << "Nem giriniz     : ";
    cin >> girdiNem;
    cout << endl;

    if (girdiSicaklik >= (-10) && girdiSicaklik <= 50)
    {
        kararSicaklik();

        for (int i = 0; i < 5; i++)
        {
            sicaklik_degerleri[i].sicaklikBastir();
        }
    }
    else
    {
        cout << "Girilen Sıcaklık: " << girdiSicaklik << "ºС\n";
        goto sicaklikMenu;
    }
    if (girdiNem >= 0 && girdiNem <= 100)
    {
        kararNem(); 
        cout << endl;
        for (int i = 0; i < 5; i++)
        {
            nem_degerleri[i].nemBastir();
        }
    }
    else
    {
        cout << "Girilen Nem: " << girdiNem << "%\n";
        goto nemMenu;
    }

    int indisSicaklik = 0;
    int indisNem = 0;
    for (int i = 0; i < 5; i++)
    {
        if (sicaklik_degerleri[i].sicaklikDegeriniAl() != 0)
        {
            flitreSicaklikDegerleri[indisSicaklik++] = sicaklik_degerleri[i];
            flitrelenenSicaklikDegeriSayisi++;
        }
        if (nem_degerleri[i].nemDegeriniAl() != 0)
        {
            flitreNemDegerleri[indisNem++] = nem_degerleri[i];
            flitrelenenNemDegeriSayisi++;
        }
    }

    cout << "\n ####### Filitrelenen değerleri bastırıyoruz. \n" << endl;
    for (int i = 0; i < flitrelenenSicaklikDegeriSayisi; i++)
    {
        flitreSicaklikDegerleri[i].sicaklikBastir();
    }

    for (int i = 0; i < flitrelenenNemDegeriSayisi; i++)
    {
        flitreNemDegerleri[i].nemBastir();
    }

    cout << "\n ####### Isıtılan Değerlerin sonuçlarını bastırıyoruz." << endl;
    kararIsitma();
}