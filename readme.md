# Hanoi Kuleleri Projesi

## Proje Açıklaması

Bu proje, klasik "Hanoi Kuleleri" problemini çözmek için üç farklı yöntemi içerir: rekursif çözüm, iteratif çözüm ve grafiksel gösterim. Program, kullanıcıya bu yöntemlerin her birini deneme imkanı sunar ve her iki çözüm türü için adım sayısını hesaplar. Grafiksel gösterim seçeneği, kullanıcıya çözüm sürecini görsel olarak sunar.

## İçerik

1. **Rekursif Çözüm**: Disklerin nasıl adım adım hedef kuleye taşındığını rekursif olarak gösterir.
2. **Iteratif Çözüm**: Iteratif bir yaklaşım kullanarak Hanoi Kuleleri problemini çözer.
3. **Grafiksel Gösterim**: Disklerin kuleler arasında hareketini grafiksel olarak gösterir.


## Fonksiyonlar

- **`lowestOneBitPos(int x)`**: 
  - Bir sayının en düşük anlamlı bitinin konumunu belirler.
  
- **`rekursifHanoi(int n, char kaynak, char yardimci, char hedef)`**: 
  - Rekursif olarak Hanoi Kuleleri problemini çözer.
  
- **`iteratifHanoi(int n, char kaynak, char yardimci, char hedef)`**: 
  - Iteratif bir yaklaşım kullanarak Hanoi Kuleleri problemini çözer.
  
- **`kuleleriGoster(const vector<vector<int>>& kuleler)`**: 
  - Kulelerin mevcut durumunu grafiksel olarak gösterir.
  
- **`diskTasi(vector<vector<int>>& kuleler, int from, int to)`**: 
  - Bir diski bir kuleden diğerine taşır ve kulelerin durumunu günceller.
  
- **`grafikselHanoi(int n, int from, int yardimci, int to, vector<vector<int>>& kuleler)`**: 
  - Grafiksel olarak Hanoi Kuleleri problemini çözer.

## Global Değişkenler

- **`int adimSayisi`**: 
  - Toplam adım sayısını tutar.