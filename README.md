# Hastane-Acil-Servis-Uyg. Proje Dökümanı

## 1- Proje Tanıtımı

Bu projemizde, bir hastane acil servisinde hastaların kabulü, önceliklendirmeli sistem, muayene edilmesi, teşhis,ilaç yazzımı ve hastanın çıkış işlemlerini yöneten bir sistem geliştirmeyi amaçlayan porjedir. Sistem C programlama dili kullanılarak geliştirilecek olup, öncelikli kuyruk(Priority Queue) yapısını kullanarak hastanın aciliyet ciddilik durumuna göre öncelik verilmesini sağlayacaktır.

## 2- Projemizin Amaçları

-Acil serviste hasta kabul sürecini otomatikleştirmek.
-Hastaların aciliyet(ciddilik) derecesini göre sıralama.
-Hastaların muayene süreçlerini ve teşhis işlemlerini yönetmek.
-Reçete numarası üretme ve ileç yazma işlemlerini gerçekleştirmek.
-Hasta çıkışı ve kayıt güncelleme süreçlerini yönetmek

## 3- Kullanılan Veri Yapıları Ve Algoritmalar

-STRUCT: Hasta bilgilerini saklamak için kullanıldı.

-UNİON: Farklı türde hasta bilgilerini depolamak için düşünülebilir.

-BAĞLI LİSTE: Hasta geçmişi haydı için düşünülebilir.

-STACK/QUEUE: Stack ilaç geçmişi için, Queue hasta kabul sırası için kullanılabilir.

-ÖNCELİKLİ KUYRUK(PRİORİTY QUEUE): Hastaların aciliyet seviyelerine göre sıralamak için Max-Heap algoritması kullanıldı.

-FLOYD-FOYU ALGORİTMASI: Acil servis içindeki hastaların yönlendrimesini optimize etmek için düşünülebilir. Gelecek geliştirmeler için.

-İNFİX-POSTFİX DÖNÜŞÜMÜ: Reçete numarası üretiminde kullanılabilir. Geliştirmeye açıktır aynı zamanda.

## 4- Sistem işleyişi

#### 1- Hasta kabul:

Hasta bilgileri(ad,yas,vs...) sisteme girilir.

#### 2- Önceliklendirme(Triage):

-Hastalar öncelik seviyelerine göre sıralanır(5:Çok Acil, 1:Normal).
-Öncelikli kuyruk algoritması (Heap) kullanılarak, en acil hasta her zaman listenin başında tutulur.

#### 3- Muayene & Test Süreçleri:

-En acil hasta sistemden çıkarılırve teşhis sürecine alınır.
-Doktor hastaya teşhis koyar ve uygun tedaviye belirler.

#### 4- Reçete No Üretme & İlaç Yazımı:

-Hastaya özel reçete oluşturulur.
-İlaç bilgileri kaydedilir.

#### 5- Hasta çıkışı & Kayıt Güncelleme:

-Hasta taburcu edilir ve sistemdeki kaydı güncellenir.

## 5- Teknik detaylar

### Veri Yapıları

### Hasta Struct Tanımı:

typedef struct {
char name[50];
int age;
int priority;
int patientID;
char diagnosis[100];
char prescription[100];
} Patient;

### Öncelikli Kuyruk Tanımı

      typedef struct {
          Patient patients[MAX_PATIENTS];
           int size;
      } PriorityQueue;

### Fonksiyonlar

-initializeQueue: Öncelikli kuyruğu başlatır.

-insertPatient:Hastayı Öncelikli kuyruğa ekler.

-removeHighestPriority: En acil hastayı çıkarır.

-diagnosePatient: Hastayı teşhis koyar ve reçete ekler.

-displayQueue: Mevcut hasta listesini görüntüler.

## 6- Kullanıcı Senaryosu

1-"Ahmet Çakar" isiimli hasta acil servise başvurur.

2-Sistem hastanın yaşının ve sağlık durumunu analiz eder ve öncelik seviyesini belirler.

3-Hasta öncelikli kuyruğa eklenir.

4-En yüksek önceliğe sahip hasta çağrılır ve muayane edilir.

5-Doktor, hastaya teşhisi koayr ve reçete oluşturur.

6-Hasta tedavi sonrası taburcu edilir ve sistemden çıkarılır.

## 7- Uygulama Tasarımı ve Akış Şemaları

### Hasta Kabul Akış Şeması:

    1-Hasta acil servise giriş yapar.

    2-Hasta bilgileri sisteme girilir

    3-Öncelik seviyesi belirlenir.

    4-Hasta öncelikli kuyruğa eklenir.

### Hasta Önceliklendirme (Triage) Akış Şeması:

    1-Hastanın öncelik seviyesi belirlenir.

    2-Öncelik sırasına göre hasta listelenir.

    3-En acil hastalar önce işleme alınır.

### Muayene ve Teşhis Akış Şeması:

    1-Hasta muayene edilir

    2-Doktor teşhisi koyar

    3-Hasta için tedaavisi plan oluşturulur.

    4-Reçete hazırlanır.

### Reçete ve Hasta Çıkışı Akış Şeması:

    1-Hastaya reçete yazılır.

    2-Hasta tedavisi tamamlanınca sistemde güncellenir.

    3-Hasta taburcu edilir.

## 8- Geliştirme ve Gelecek Çalışmalar:

-Hasta geçmişi kaydı için bağlı liste (linked list) entagrasyonu

-Grafiksel arayüz(GUI) geliştirem

-Reçete no üretimi için infix-postfix dönüşümü.

-Gerçek zamanlı hasta bekelem süresi hesaplama.

## 9-Sonuç

Projemizde, acil servislerde hasta kabul ve yönetim süreçlerini otomatikleştirerek, doktor ve hemşirelerin iş yükünü hafifletmeyi hedeflemektedir. Öncelikli kuyruk algoritması sayeside en acil hastaların öncelikli olarak tedavi edilmesi sağlanmaktadır.
