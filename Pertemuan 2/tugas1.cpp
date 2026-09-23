#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// TODO : Insert di Depan
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

// TODO : Insert di belakang
void insertLast(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        tail = head;
     } else {
        tail -> next = newNode;
        tail = newNode;
     }

}

// TODO : Insert setelah nilai tertentu
void insertAfter(int n, int check) {
    if(head == NULL){
        cout << "List Kosong, Silahkan insert di depan \n";
        return;
    }

    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head;
    while(p != NULL && p->value != check) {
        p = p -> next;
    }

    if (p == NULL){
        cout << "Node dengan nilai  " << check << "Tidak Ketemu \n";
        delete newNode;
    } else {
        newNode -> next = p->next;
        p->next = newNode;
        if(p == tail){
            tail = newNode;
        }
    }

}

// TODO : Hapus node
void hapusNode(int n) {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->value != n) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Nilai " << n << " tidak ditemukan.\n";
        return;
    }

    if (temp == head) {
        head = head->next;

        if (head == NULL) {
            tail = NULL;
        }

        delete temp;
        return;
    }

    prev->next = temp->next;

    if (temp == tail) {
        tail = prev;
    }

    delete temp;
}

// Cetak linked list
void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

void tampilkanMenu() {
    cout << "\n=== MENU PENGELOLAAN NILAI MAHASISWA ===\n";
    cout << "1. Tambah nilai di awal\n";
    cout << "2. Tambah nilai di akhir\n";
    cout << "3. Tambah nilai setelah nilai tertentu\n";
    cout << "4. Hapus nilai\n";
    cout << "5. Tampilkan isi list\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
}

int main () {
    int pilihan;
    int nilai;
    int a;

    do {
        tampilkanMenu();
        cin >> pilihan;
 
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                insertFirst(nilai);
                printList();
                break;
 
            case 2:
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                insertLast(nilai);
                printList();
                break;
 
            case 3:
                cout << "Masukkan nilai sebelum nilai baru : ";
                cin >> a;
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                insertAfter(nilai, a);
                printList();
                break;
 
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusNode(nilai);
                printList();
                break;
 
            case 5:
                printList();
                break;
 
            case 0:
                cout << "Program selesai. Terima kasih.\n";
                break;
 
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
 
    } while (pilihan != 0);
    return 0;
}