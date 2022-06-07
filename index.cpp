#include <iostream> 
#include <string>  
#include <conio.h>

using namespace std; 

int i,  jumlahmhs, jumlah, n,temp, nim[100], pilihan; 
char temp_nama, nama[100];
string ipk[100], nama_yang_dicari; 

void fungsi(int *jumlah,int *n){ 
	float ipk;
	ipk = (*jumlah) / (*n);
	cout << ipk << endl;
}

void cariMhs() {
	system("clear");
	string nama_yang_dicari;
	bool ketemu = false;
	int posisi;

	cout<<"Cari Mahasiswa"<<endl;
	cout<<"Nama Mahasiswa yang Dicari : ";
	cin>>nama_yang_dicari;

	for(int i = 0; i < jumlah_mhs; i++) {
		if(*(nama+i) == nama_yang_dicari) {
			ketemu = true;
			posisi = i;
			break;
		}
	}

	if(ketemu) {
		cout<<"Nama ditemukan, '"<<nama_yang_dicari<<"' ditemukan di posisi "<< posisi <<" indeks array"<<endl;
	} else {
		cout<<"Nama tidak ditemukan"<<endl;
	}
}


void input ( int *jml_mhs){ 
	int n, jumlah , nilai[100], i;

	for (int i = 0; i < jumlahmhs; i++)
	{
		jumlah = 0; 
		cout << "Inputkan Mahasiswa ke " << i+1 << endl; 
		cout << "Masukkan nama anda = " << endl; 
		cin >> nama[i]; 
		cout << "Masukkan nim anda = " << endl; 
		cin >> nim[i]; 
		cout << "inputkan banyak mata kuliah anda = " << endl; 
		cin >> n; 
		
		for (int i = 0; i < n; i++) 
		{
			cout << "Inputkan nilai mata kuliah ke " << i+1 << " = ";
			cin >> nilai[i]; 
			jumlah += nilai[i]; 
		}
		
		cout << "========================" << endl;
		cout << "Jumlah nilai : "<< jumlah << endl;
		cout << "========================" << endl;
		cout << "========================" << endl;
		cout << "IPK : " ;	
		fungsi(&jumlah, &n); // memanggil fungsi
		cout << "========================" << endl;
		
		cout << endl;	
	}
}
void bubbleSort(int jumlahmhs,int nim[]){
	for (int i = 0; i < (jumlahmhs-1); i++)
	{	
		for (int j = 0; j < (jumlahmhs-1); j++)
		{
			if(nim[j] > nim[j+1])
			{
				temp = nim[j];
				nim[j] = nim[j+1];
				nim[j+1] = temp;
			}
		}
	}
}

void selectionSort(int jumlahmhs,int nim[]){
	int maks;
	for (int i = 0; i < jumlahmhs; i++)
	{
		maks = i;
		for (int j = i+1; j < jumlahmhs; j++)
		{
			if (nim[maks] > nim[j])
			{
				maks = j;
			}
		}
		if (nim[i] != nim[maks])
		{
			temp = nim[i];
			nim[i] = nim[maks];
			nim[maks] = temp;
		}
	}
}

void insertionSort(int jumlahmhs,int nim[]){
	int j;
	for(i = 0; i < jumlahmhs; i++)
	{
		temp = nim[i];
		j = i - 1;
		while(nim[j] > temp && j >= 0)
		{
			nim[j+1] = nim[j];
			j--;
		}
		nim[j+1] = temp;
	}
}

int main(int argc, char const *argv[])
{
	cout << "Masukkan jumlah Mahasiswa = " << endl; 
	cin >> jumlahmhs;

	input(&jumlahmhs);

    do{
        cout << "========  SORTING  ========" << endl;
        cout<<"1. Bubble Sort"<<endl;
        cout<<"2. Selection Sort"<<endl;
        cout<<"3. Insertion Sort"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Masukan Pilihan anda = ";
        cin>>pilihan;
        cout<<"----------------------------"<<endl;
        switch(pilihan)
        {
            case 1: bubbleSort(jumlahmhs,nim);
            cout << "========================" << endl;
			for (int i = 0; i < jumlahmhs; i++)
			{
				cout << "Nama Mahasiswa ke - " << i+1 << " = " << nama[i]<<endl;
				cout << "NIM Mahasiswa ke - " << i+1 << " = " << nim[i] << endl; 	
			}cout << "========================" << endl;break;
            case 2: selectionSort(jumlahmhs,nim);
            cout << "========================" << endl;
			for (int i = 0; i < jumlahmhs; i++)
			{
				cout << "Nama Mahasiswa ke - " << i+1 << " = " << nama[i]<<endl;
				cout << "NIM Mahasiswa ke - " << i+1 << " = " << nim[i] << endl; 	
			}cout << "========================" << endl;break; 
            case 3: insertionSort(jumlahmhs,nim);
            cout << "========================" << endl;
			for (int i = 0; i < jumlahmhs; i++)
			{
				cout << "Nama Mahasiswa ke - " << i+1 << " = " << nama[i]<<endl;
				cout << "NIM Mahasiswa ke - " << i+1 << " = " << nim[i] << endl; 	
			}cout << "========================" << endl;break; 
        }
    }while(pilihan != 4);
   
	getch();
	return 0;
}
