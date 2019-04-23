/*
Program		: Case 1
Nama		: Aprischa Nauva
NPM		    : 140810180063
Deskripsi	: UTS Prak
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

struct ElemtList{
	char no[2];
	char nama[25];
	char asal[50];
	int gol;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst(List& First, pointer pBaru);
void traversal(List First);
void deleteFirst(List& First, pointer& pHapus);
void insertLast(List& First, pointer pBaru);
void deleteLast(List& First, pointer& pHapus);
void bubbleSort(List First);

int main(){
	pointer p;
	List list;
	int in, n;
	char loop='Y';
	do{
		cout << "Banyak TIM : ";
		cin >> n;
		createList(list);
		for(int i=0; i<n; i++){
			cout << endl << "Data tim ke-" << i+1 << endl;
			createElmt(p);
			insertLast(list,p);
		}
		do{
			cout << "[1] Tambah gol" << endl;
			cout << "[2] Cetak Data" << endl;

			do{
				cin >> in;
			}while(in<1 || in>2);
			switch(in){
				case 1:
					createElmt(p);
					insertFirst(list,p);
					getch();
					break;
				case 2:
					bubbleSort(list);
					traversal(list);
					cout << endl << "Kembali ke menu? (Y/N)";
					do{
						cin >> loop;
					}
					while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
					break;
				case 6:
					loop='s';
					break;
			}
		}while(loop=='Y' || loop=='y');
	}while(loop=='s');
}

void createList(List& First){
	First=NULL;
}
void createElmt(pointer& pBaru){
	pBaru=new ElemtList;
	cout << "No : ";
	cin >> pBaru->no;
	cout << "TIM : ";
	cin.ignore();
	cin.getline(pBaru->nama,25);
	cout << "Asal : ";
	cin>>pBaru->asal;
	cout << "Gol :";
	cin >> pBaru->gol;
	pBaru->next=NULL;
}
void insertFirst(List& First, pointer pBaru){
	if(First==NULL){
		First=pBaru;
	}else{
		pBaru->next=First;
		First=pBaru;
	}
}
void traversal(List First){
	pointer pBantu;
	int i=1;
	if(First==NULL){
		cout << "List kosong" << endl;
	}else{
		pBantu=First;
		do{
			cout << endl << " Data TIM ke-" << i << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << "\nNo : "<<pBantu->no<<endl;
			cout << "Tim : "<<pBantu->nama<< endl;
			cout << "Gol : "<<pBantu->gol << endl;

			pBantu=pBantu->next;
			i++;
		}while(pBantu!=NULL);
	}
	cout<<endl;
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if(First==NULL){
		First=pBaru;
	}else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
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
        while (pBantu->next != last){
            if (pBantu->gol > pBantu->next->gol){
                swap(pBantu->gol, pBantu->next->gol);
                tukar = 1;
            }
            pBantu = pBantu->next;
        }
        last = pBantu;
    }
    while (tukar);
}
