#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

// 1- Hasta bilgilerini tutan yapı
typedef struct {
    char name[50];
    int age;
    int priority;  
    int patientID;
    char diagnosis[100];
    char prescription[100];
} Patient; 

// 2- Öncelikli kuyruk (Max Heap)
typedef struct {
    Patient patients[MAX_PATIENTS];
    int size;
} PriorityQueue;

// 3-Öncelikli Kuyruğu Başlatma
void initializeQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// 4-Hasta Ekleme 
void insertPatient(PriorityQueue *pq, char name[], int age, int priority, int patientID) {
    if (pq->size >= MAX_PATIENTS) {
        printf("Kuyruk dolu!\n");
        return;
    }
    
    Patient newPatient;
    strcpy(newPatient.name, name);
    newPatient.age = age;
    newPatient.priority = priority;
    newPatient.patientID = patientID;
    strcpy(newPatient.diagnosis, "Bekleniyor");
    strcpy(newPatient.prescription, "Bekleniyor");

    int i = pq->size++;
    while (i > 0 && pq->patients[(i - 1) / 2].priority < priority) {
        pq->patients[i] = pq->patients[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->patients[i] = newPatient;
}

//5- En Acil Hastayı Alma
Patient removeHighestPriority(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Kuyruk boş!\n");
        Patient empty = {"", 0, 0, 0, "", ""};
        return empty;
    }

    Patient highestPriorityPatient = pq->patients[0];
    pq->patients[0] = pq->patients[--pq->size];

    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, maxIndex = i;
        
        if (left < pq->size && pq->patients[left].priority > pq->patients[maxIndex].priority)
            maxIndex = left;
        if (right < pq->size && pq->patients[right].priority > pq->patients[maxIndex].priority)
            maxIndex = right;
        if (maxIndex == i)
            break;

        Patient temp = pq->patients[i];
        pq->patients[i] = pq->patients[maxIndex];
        pq->patients[maxIndex] = temp;
        i = maxIndex;
    }
    return highestPriorityPatient;
}

// 6- Teşhis ve Reçete Yazma
void diagnosePatient(Patient *p, char diagnosis[], char prescription[]) {
    strcpy(p->diagnosis, diagnosis);
    strcpy(p->prescription, prescription);
}

// 7- Hasta Listesini Görüntüleme
void displayQueue(PriorityQueue *pq) {
    printf("\nHasta Kuyrugu:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("ID: %d | Ad: %s | Yas: %d | Oncelik: %d | Teshis: %s | Recete: %s\n",
               pq->patients[i].patientID, pq->patients[i].name, pq->patients[i].age,
               pq->patients[i].priority, pq->patients[i].diagnosis, pq->patients[i].prescription);
    }
}

// 8- Ana Program 
int main() {
    PriorityQueue pq;
    initializeQueue(&pq);
    
    insertPatient(&pq, "Ahmet Cakar", 45, 3, 10001);
    insertPatient(&pq, "Zeynep Marla", 70, 5, 10002);
    insertPatient(&pq, "Mehmet Bekir", 30, 2, 10003);
    insertPatient(&pq, "Ayse Durmaz", 50, 4, 10004);
    
    displayQueue(&pq);
    
    printf("\nEn yuksek oncelikli hasta isleniyor...\n");
    Patient p = removeHighestPriority(&pq);
    diagnosePatient(&p, "Grip", "Parol, Bol Sivi");
    printf("Hasta ID: %d | Ad: %s | Teshis: %s | Recete: %s\n", p.patientID, p.name, p.diagnosis, p.prescription);
    
    displayQueue(&pq);
    return 0;
}
