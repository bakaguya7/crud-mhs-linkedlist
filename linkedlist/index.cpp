#include <iostream>
#include <iomanip>

using namespace std;

// Var global
int i, nm;
char q;

struct Mahasiswa {
    char nim[15];
    char nama[15];
    float ip_sd;
    float ip_hs;
    float ip_so;
    float ipk;
    Mahasiswa *next;
};
Mahasiswa *head = NULL;

// Deklarasi fungsi
bool empty();
bool full();
void clear();
void buat();
void tampil();
void urutkan();
void cari();

int main(){
    do {
        cout << "[MAIN MENU]" << endl;
        cout << "1. BUAT \t 2. TAMPIL \t 3. URUTKAN \t 4. CARI" << endl; 
        cout << "MASUKKAN NOMOR MENU : "; cin >> nm;
        switch(nm){
            case 1 :
                clear(); buat();
            break;
            case 2 :
                clear(); tampil();
            break;
            case 3 :
                clear(); urutkan();
            break;
            case 4 :
                clear(); cari();
            break;
        }
    } while(q != '5');
}

void clear(void){
    system("clear || cls");
    return;
}

void buat(){
    cout << "[MAIN MENU/BUAT]" << endl;
    do {
        Mahasiswa *newnode = new Mahasiswa;
        cout << "MASUKKAN NIM : "; cin.ignore(); cin.getline(newnode->nim, sizeof(newnode->nim));
        cout << "MASUKKAN NAMA : "; cin.getline(newnode->nama, sizeof(newnode->nama));
        cout << "MASUKKAN INDEKS PRESTASI SD : "; cin >> newnode->ip_sd;
        cout << "MASUKKAN INDEKS PRESTASI SO : "; cin >> newnode->ip_so;
        cout << "MASUKKAN INDEKS PRESTASI HS : "; cin >> newnode->ip_hs;
        newnode->ipk = (newnode->ip_sd + newnode->ip_so + newnode->ip_hs) / 3;
        cout << endl;

        if(head == NULL){
            head = newnode;
            newnode->next = NULL;
        } else {
            newnode->next = head;
            head = newnode;
        }

        cout << "BUAT DATA LAGI? [y/n] "; cin >> q;
    } while(q != 'n');
}

void tampil(){
    cout << "[MAIN MENU/TAMPIL]" << endl;
    if(head == NULL){
        cout << "DATA KOSONG!" << endl;
    } else {
        do {
            Mahasiswa *current = head;
            cout << "=================================================================" << endl;
            cout << "| NIM \t\t| NAMA \t\t| IP SD | SO \t| HS \t| IPK \t|" << endl;
            cout << "=================================================================" << endl;
            while(current != NULL){
                cout << "| "<< current->nim << "\t\t| " << current->nama << " \t| "
                << fixed << setprecision(2) << current->ip_sd << " \t| " << current->ip_so << " \t| "
                << current->ip_hs << " \t| " << current->ipk << " \t|" << endl;
                cout << "=================================================================" << endl;
                current = current->next;
            }
            cout << "KEMBALI KE MAIN MENU : [y/n] "; cin >> q;
        } while(q != 'y');
    }
}

void urutkan(){
    cout << "[MAIN MENU/SORTING]" << endl;
    if(head == NULL){
        cout << "DATA KOSONG!" << endl;
    } else {
        do {
            Mahasiswa *current = head, *indeks = NULL;
            while(current != NULL){
                indeks = current->next;
                while(indeks != NULL){
                    if(current->ipk > indeks->ipk){
                        swap(current->nim, indeks->nim);
                        swap(current->nama, indeks->nama);
                        swap(current->ip_sd, indeks->ip_sd);
                        swap(current->ip_so, indeks->ip_so);
                        swap(current->ip_hs, indeks->ip_hs);
                        swap(current->ipk, indeks->ipk);
                    }
                    indeks = indeks->next;
                }
                current = current->next;
            }

            cout << "SORTING BERHASIL!" << endl;
            cout << "KEMBALI KE MAIN MENU? [y/n] "; cin >> q;
        } while(q != 'y');
    }
}

void cari(){
    if(head == NULL){
        cout << "DATA KOSONG!" << endl;
    } else {
        do {
            char t_nama[15]; bool lock;
            Mahasiswa *current = head;
            cout << "MASUKKAN NAMA MAHASISWA : "; cin >> t_nama;
            while(current != head){
                if(current->nama == t_nama){
                    lock = true;
                    break;
                }
                current = current->next;
            }
            if(lock == true){
                cout << "=================================================================" << endl;
                cout << "| NIM \t\t| NAMA \t\t| IP SD | SO \t| HS \t| IPK \t|" << endl;
                cout << "=================================================================" << endl;
                cout << "| "<< current->nim << "\t\t| " << current->nama << " \t| "
                << fixed << setprecision(2) << current->ip_sd << " \t| " << current->ip_so << " \t| "
                << current->ip_hs << " \t| " << current->ipk << " \t|" << endl;
                cout << "=================================================================" << endl;
            }
            cout << "KEMBALI KE MAIN MENU? [y/n] "; cin >> q;
        } while(q != 'y');
    }
}