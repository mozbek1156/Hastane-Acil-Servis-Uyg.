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
