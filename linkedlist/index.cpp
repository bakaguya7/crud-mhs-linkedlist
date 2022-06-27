#include <iostream>

using namespace std;

// Var global
int i;
char q;

struct Mahasiswa {
    int id;
    char nim[20];
    char nama[20];
    float ip_sd;
    float ip_hs;
    float ip_so;
    float ipk;
    struct Mahasiswa *next;
};

Mahasiswa *mhs = new Mahasiswa[10];

// Deklarasi fungsi
bool empty();
bool full();
void buat();
void tampil();

int main(){
    mhs->id = -1;
    do {
        cout << "[MAIN MENU]" << endl;
        cout << "1. BUAT \t 2. TAMPIL" << endl;
    } while(q != '5');
    
}

bool empty(){
    if(mhs->id == -1){
        return true;
    } else {
        return false;
    }
}

bool full(){
    if(mhs->id == 10){
        return true;
    } else {
        return false;
    }
}

void buat(){
    if(full() == true){
        cout << "DATA PENUH!" << endl;
    } else {
        do {
            //
        } while(q != 'y');
    }
}