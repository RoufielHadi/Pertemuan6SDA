/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "stack.h"
#include <stdlib.h>

boolean isEmptyStack(Stack S) {
    return (S.top == NULL);
}

void CreateStack(Stack *S) {
    S->top = NULL;
}

void Push(Stack *S, infotype nilai) {
    address PNew;
    Create_Node(&PNew);
    if (PNew != NULL) {
        Isi_Node(&PNew, nilai);
        PNew->next = S->top; // Perbaikan akses ke next
        S->top = PNew;
    } else {
        printf("Gagal mengalokasikan memori untuk elemen baru!\n");
    }
}

void Pop(Stack *S, infotype *X) {
    if (isEmptyStack(*S)) {
        printf("Stack kosong! Tidak dapat melakukan Pop.\n");
        return;
    }
    address temp = S->top;
    *X = info(temp);
    S->top = next(temp);
    DeAlokasi(&temp);
}

infotype Top(Stack S) {
    if (!isEmptyStack(S)) {
        return info(S.top);
    }
    printf("Stack kosong! Tidak ada elemen di puncak.\n");
    return -1; // Nilai default jika stack kosong
}

int NbElmtStack(Stack S) {
    return NbElmt(S.top);
}

void TampilStack(Stack S) {
    if (isEmptyStack(S)) {
        printf("Stack kosong!\n");
    } else {
        Tampil_List(S.top);
    }
}

void DeAlokasiStack(address *p) {
    if (*p != NULL) {
        DeAlokasi(p);
    }
}

