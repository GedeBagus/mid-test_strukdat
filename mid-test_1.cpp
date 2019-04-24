/*
Nama: Gede Bagus Darmagita
NPM: 140810180068
Tanggal: 24-04-2019
Deskripsi: Soal 1 uts praktikum strukdat
*/

#include<iostream>
using namespace std;

struct ElemtList {
	int omelet;
    int nasgil;
    int chikat;
    int aygep;
    int nago;
	ElemtList* next; 
}; 
typedef ElemtList* pointer; 
typedef pointer List;

void createList (List& First){
	First = NULL;
}

void createElmt (pointer& pBaru){
	pBaru = new ElemtList;
	cout << "Omelet Rendang: "; cin >> pBaru->omelet;
    cout << "Nasi Gila: "; cin >> pBaru->nasgil;
    cout << "Chicken Katsu: "; cin >> pBaru->chikat;
    cout << "Ayam Geprek: "; cin >> pBaru->aygep;
    cout << "Nasi Goreng: "; cin >> pBaru->nago;
	pBaru->next = NULL;
}

void insertFirst (List& First, pointer pBaru){	
	if (First == NULL) 		
			First = pBaru;
	else {					
		pBaru->next = First;	
		First = pBaru;		
	}
}

void traversal (List First){
    pointer pBantu;
    if (First == NULL){
        cout << "BLOM ADA PEMBELI!" << endl;
    }
    else {
		pBantu = First;					
		do {
			cout << "Omelet Rendang: " << pBantu->omelet << endl;
            cout << "Nasi Gila: " << pBantu->nasgil << endl;
            cout << "Chicken Katsu: " << pBantu->chikat << endl;
            cout << "Ayam Geprek: " << pBantu->aygep << endl;
            cout << "Nasi Goreng: " << pBantu->nago << endl;	
			pBantu = pBantu->next;		
		} while (pBantu != NULL);	
	}
}

void linearSearch (List First, int key, int& found, pointer& pCari){
	found = 0;				
	pCari = First;			
	while (found == 0 && pCari != NULL){
		if (pCari->omelet == key){
			found = 1;
		}
		else {
			pCari = pCari->next;
		}
	}
}

void update (List& First, pointer& pUpdate, pointer pCari){
    pUpdate = pCari;
    cout << "Omelet Rendang: "; cin >> pUpdate->omelet;
    cout << "Nasi Gila: "; cin >> pUpdate->nasgil;
    cout << "Chicken Katsu: "; cin >> pUpdate->chikat;
    cout << "Ayam Geprek: "; cin >> pUpdate->aygep;
    cout << "Nasi Goreng: "; cin >> pUpdate->nago;
}

void bubbleSort(List First){
    int tukar, i;
    pointer pBantu;
    pointer last = NULL;

    if (First == NULL){
        return;
    }
    do{
        tukar = 0;
        pBantu = First;
        while (tukar = 0){
            if (pBantu->omelet > pBantu->nasgil){
                swap(pBantu->omelet, pBantu->nasgil);
                tukar = 1;
            }
            pBantu = pBantu->next;
        }
        last = pBantu;
    }
    while (tukar);
}

main(){
    List lalala;
    pointer makanan;
    pointer cari;
    int kunci, ketemu;

    createList(lalala);
    cout << "PROMO BULAN PUASA!" << endl;
    cout << "Omelet Rendang 8.000 \n";
    cout << "Nasi Gila 10.000\n";
    cout << "Chicken Katsu 12.000\n";
    cout << "Ayam Geprek 10.000\n";
    cout << "Nasi Goreng 8.000\n\n";

    cout << "Masukan pesanan" << endl;
    createElmt(makanan);
    insertFirst(lalala, makanan);
    cout << "Pesanan saat ini" << endl;
    traversal(lalala);

    cout << "\nUpdate pesanan melalui KUNCI\n";
    cout << "Kunci: "; cin >> kunci;
    linearSearch(lalala, kunci, ketemu, cari);
    if (ketemu){
        cout << "DITEMUKAN!" << endl;
		update(lalala, makanan, cari);
	}
	else {
		cout << "Tidak ditemukan data yang dicari" << endl;
	}
    cout << "\nTotal Pesanan Saat Ini!\n";
    traversal(lalala);

    //cout << "";

}