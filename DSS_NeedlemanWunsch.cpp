// DSS_NeedlemanWunsch.cpp 
// Algoritma Penentuan Plagiarisme menggunakan metode Needleman Wunsch berbasis C++
// 2018 Hansrenee Wilysandro
#include "pch.h"
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>

using namespace std;


//Fungsi Untuk Menampilkan Matriks
void printMatrix(int** matrix_masukan, int baris, int kolom) {
	for (int i = 0; i < baris; i++) {
		for (int z = 0; z < kolom; z++) {
			cout << matrix_masukan[i][z] << " ";
		}
		cout << "" << endl;

	}
}

//Fungsi Untuk mengambil nilai tertinggi 
int max(int angka1, int angka2, int angka3) {
	if ((angka1 > angka2) && (angka1 > angka3)) {
		return angka1;
	}
	else if ((angka2 > angka1) && (angka2 > angka3)) {
		return angka2;
	}
	else {
		return angka3;
	}
}
//fungsi untuk mencocokan karakter
int cocokKarakter(char k1, char k2) {
	if (k1 == k2) {
		return 5;
	}
	else {
		return -3;
	}
}

//fungsi untuk Data Cleansing
string bersihData(string masukan) {
	string append = "";
	string temp;
	vector<string> list;
	stringstream deretStream(masukan);

	while (getline(deretStream, temp, ' ')) {
		list.push_back(temp);
		//cout << temp <<endl ;
	}

	for (int i = 0; i < list.size(); i++) {
		append += list[i];
		//cout << append << endl;
	}

	return append;
}


int main()
{
	//Deklarasi Variabel untuk algoritma
	string deret1;
	string deret2;
	int panjangDeret1;
	int panjangDeret2;
	///////////////////////////////////////
	cout << "------------------------------" << endl;
	cout << "Demonstrasi Algoritma Needleman Wunsch" << endl;
	cout <<"Untk mendeteksi Plagiarisme"<<endl << "Dibuat Oleh Hansrenee Willysandro" << endl;
	cout << "Berbasis C++" << endl << "------------------------------" << endl << "Ketentuan yang telah ditetapan: " << endl;
	cout << "Nilai untuk karakter yang sama: +1\nNilai untuk karakter yang beda: -1\nNilai untuk Karakter celah/kosong: -2" << endl;
	cout << "------------------------------" << endl;
	cout << "Masukan deret kata pertama (Tekan enter untuk memasukan input): ";
	getline(cin, deret1);
	cout << "masukan deret kata kedua: "; 
	getline(cin, deret2);
	

	//Memanggil fungsi Data Cleansing, membuang spasi dan pengambilan panjang karakter
	deret1 = bersihData(deret1);
	deret2 = bersihData(deret2);
	cout << deret1 << endl;
	cout << deret2 << endl;
	
	panjangDeret1 = deret1.size() + 1;
	panjangDeret2 = deret2.size() + 1;

	//Buat Matriks untuk menampung nilai
	int** matrix = new int*[panjangDeret1];
	for (int i = 0; i < panjangDeret1; i++) {
		matrix[i] = new int[panjangDeret2];
	}
    
	//Isi base dasar pada baris dan kolom indeks ke 0 sampai akhir
	for (int i = 0; i < panjangDeret1; i++) {
		if (i==0) {
			for (int z = 0; z < panjangDeret2; z++) {
				matrix[i][z] = 0;
			}
		}
		else {
			for (int z = 1; z < panjangDeret2; z++) {
				matrix[i][z] = NULL; //Untuk mencegah kebingungan assign nilai yang kosong sewaktu di print
			}
		}
		matrix[i][0] = 0;
	}
	//Opsional untuk membuat print matriks
	printMatrix(matrix, panjangDeret1, panjangDeret2);

	//Perhitungan Nilai
	for (int i = 1; i < panjangDeret1; i++) {
		for (int z = 0; z < panjangDeret2; z++) {
			//matrix[i][z] = max((matrix[i-1][z] + cocokKarakter()
		}
	}

	system("pause");

}
