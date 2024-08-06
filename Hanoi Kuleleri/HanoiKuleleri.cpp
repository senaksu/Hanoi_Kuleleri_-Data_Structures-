#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <windows.h> // Sleep icin

using namespace std;

int adimSayisi = 0; // Toplam adým sayýsýný tutan global deðiþken

// En dusuk anlamli bitin konumunu bulan fonksiyon
int lowestOneBitPos(int x) {
    int position = 0;
    while ((x & 1) == 0) { // En düþük anlamlý biti bulana kadar saða kaydýr
        x >>= 1;
        position++;
    }
    return position;
}

// Rekursif Hanoi cozumu
void rekursifHanoi(int n, char kaynak, char yardimci, char hedef) {
    if (n == 1) { // Tek disk kaldýðýnda, doðrudan hedefe taþýr
        cout << "Disk 1'i " << kaynak << " kulesinden " << hedef << " kulesine tasi" << endl;
        adimSayisi++;
        return;
    }
    rekursifHanoi(n - 1, kaynak, hedef, yardimci); // En büyük disk hariç diðerlerini yardýmcýya taþýr
    cout << "Disk " << n << "i " << kaynak << " kulesinden " << hedef << " kulesine tasi" << endl;
    adimSayisi++;
    rekursifHanoi(n - 1, yardimci, kaynak, hedef); // Yardýmcýdaki diskleri hedefe taþýr
}

// Iteratif Hanoi cozumu
void iteratifHanoi(int n, char kaynak, char yardimci, char hedef) {
    int toplamAdim = static_cast<int>(pow(2, n)) - 1; // Toplam adim sayisi
    vector<char> kuleler = { kaynak, yardimci, hedef };

    if (n % 2 == 0) {
        swap(kuleler[1], kuleler[2]); // Eger disk sayisi ciftse hedef ve yardimci kuleyi degistir
    }

    for (int i = 1; i <= toplamAdim; i++) { // Iteratif olarak tüm adýmlarý gerçekleþtir
        int from = (i & (i - 1)) % 3; // Kaynak kulenin indexini belirle
        int to = ((i | (i - 1)) + 1) % 3; // Hedef kulenin indexini belirle
        int disk = lowestOneBitPos(i) + 1; // Taþýnacak diskin büyüklüðünü belirle
        cout << "Disk " << disk << "i " << kuleler[from] << " kulesinden " << kuleler[to] << " kulesine tasi" << endl;
        adimSayisi++;
    }
}

// Grafiksel gosterim icin yardimci fonksiyonlar
void kuleleriGoster(const vector<vector<int>>& kuleler) {
    int maxDisk = 0;
    for (const auto& kule : kuleler) {
        if (!kule.empty() && kule.front() > maxDisk) {
            maxDisk = kule.front(); // En büyük diskin büyüklüðünü bul
        }
    }

    for (int i = maxDisk; i >= 1; --i) { // Her diski yukarýdan aþaðýya doðru göster
        for (int j = 0; j < 3; ++j) {
            if (kuleler[j].size() >= i) {
                cout << string(maxDisk - kuleler[j][i - 1], ' ') << string(kuleler[j][i - 1] * 2, '*') << string(maxDisk - kuleler[j][i - 1] + 1, ' ');
            }
            else {
                cout << string(maxDisk * 2 + 1, ' '); // Disk yoksa boþluk býrak
            }
        }
        cout << endl;
    }

    // Harfleri ortalama
    int ortalama = maxDisk * 2;
    cout << string(ortalama / 2 - 1, ' ') << "A" << string(ortalama, ' ') << "B" << string(ortalama, ' ') << "C" << endl;
    cout << string(ortalama * 3 + 3, '-') << endl;
    // Adim sayisini yazdir
    cout << "Adim Sayisi: " << adimSayisi << endl;
}

// Diski bir kuleden digerine tasima fonksiyonu
void diskTasi(vector<vector<int>>& kuleler, int from, int to) {
    if (kuleler[from].empty()) { // Eger kaynak kule boþsa hata ver
        cerr << "Hata: Tasýnacak disk yok!" << endl;
        return;
    }
    int disk = kuleler[from].back(); // Kaynak kulenin son diskini al
    kuleler[from].pop_back();
    kuleler[to].push_back(disk); // Diski hedef kuleye ekle
    adimSayisi++; // Her disk tasima isleminde adim sayisini artir
    kuleleriGoster(kuleler); // Kulelerin güncel durumunu göster
    Sleep(500); // 0.5 saniye bekleme (milisaniye cinsinden)
}

// Grafiksel Hanoi cozumu
void grafikselHanoi(int n, int from, int yardimci, int to, vector<vector<int>>& kuleler) {
    if (n == 1) { // Tek disk kaldýðýnda, doðrudan hedefe taþýr
        diskTasi(kuleler, from, to);
        return;
    }
    grafikselHanoi(n - 1, from, to, yardimci, kuleler); // En büyük disk hariç diðerlerini yardýmcýya taþýr
    diskTasi(kuleler, from, to); // En büyük diski hedefe taþýr
    grafikselHanoi(n - 1, yardimci, from, to, kuleler); // Yardýmcýdaki diskleri hedefe taþýr
}

int main() {
    int secim;
    int diskSayisi;

    do {
        cout << "\nHanoi Kuleleri Menu\n";
        cout << "1. Rekursif Cozum\n";
        cout << "2. Iteratif Cozum\n";
        cout << "3. Grafiksel Gosterim\n";
        cout << "4. Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim != 4) { // Çýkýþ seçilmediyse disk sayýsýný al
            cout << "Disk Sayisi: ";
            cin >> diskSayisi;
        }

        switch (secim) {
        case 1:
            adimSayisi = 0;
            rekursifHanoi(diskSayisi, 'A', 'B', 'C');
            cout << "Toplam adim sayisi: " << adimSayisi << endl;
            cout << endl; // Menu sonrasi bos satir
            break;
        case 2:
            adimSayisi = 0;
            iteratifHanoi(diskSayisi, 'A', 'B', 'C');
            cout << "Toplam adim sayisi: " << adimSayisi << endl;
            cout << endl; // Menu sonrasi bos satir
            break;
        case 3:
        {
            adimSayisi = 0;
            vector<vector<int>> kuleler(3); // Üç kuleyi temsil eden vektör
            for (int i = diskSayisi; i >= 1; --i) {
                kuleler[0].push_back(i); // Tüm diskleri ilk kuleye ekle
            }
            kuleleriGoster(kuleler); // Kulelerin baþlangýç durumunu göster
            grafikselHanoi(diskSayisi, 0, 1, 2, kuleler); // Grafiksel Hanoi çözümünü baþlat
            cout << endl; // Menu sonrasi bos satir
        }
        break;
        case 4:
            cout << "Cikiliyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim, lutfen tekrar deneyin." << endl;
            cout << endl; // Menu sonrasi bos satir
        }
    } while (secim != 4);

    return 0;
}