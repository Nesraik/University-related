//NIM : 2602160750
//Nama : Bryan Orville Audric
//Kelas : LB20

#include <stdio.h>//Menggunakan Library standard input output untuk menerima input user dan menampilkan output kepada user
#include <string.h>//Menggunakan Library string.h untuk menggunakan beberapa syntax seperti strlen() = menghitung string
                   // dan strcpy() untuk mengcopy string ke variable baru
int hitung_vokal(char input_string[]){//fungsi untuk menghitung huruf vokal dengan parameter char input_string[]
                                      //agar string yang diinput dari user di fungsi main bisa dipass di fungsi hitung_vokal
	int hitung;//mendeclare variable hitung sebagai data integer
	int panjang_vokal = strlen(input_string);//menghitung string dan menyimpan valuenya didalam variable data integer 
	char huruf_vokal[] = {'a','i','u','e','o','A','E','I','U','O'};//menyimpan huruf vokal didalam string huruf_vokal[]
	for(int i=0; i<panjang_vokal; i++){//"for"loop untuk menghitung huruf vokal
		for(int j = 0; j<10; j++){// "for" loop untuk mengurutkan huruf vokal dalam string huruf_vokal[] saat pengecekan
			if(input_string[i]==huruf_vokal[j]){//apabila isi input_string sama dengan huruf vokal yang tersimpan dalam string huruf_vokal[]
			                                    //maka statement didalam "if" akan dijalankan 
				hitung++;//value variable hitung akan bertambah saat kondisi if diatas terpenuhi
			}
		}
	}
	return hitung;// mengembalikan value variable hitung
}
int hapus_vokal(char input_string[],char *result_string){//fungsi untuk menghapus huruf vokal dengan parameter char input_string[]
                                                          //agar string yang diinput dari user di fungsi main bisa dipass di fungsi
                                                        //hapus_vokal
                                                        //menggunakan parameter char *result_string agar bisa dipass ke fungsi lain
                                                        //untuk dicetak
                                                      
	int panjang_string;//mendeclare variable untuk menampung panjang string  
	panjang_string = strlen(input_string);//menghitung panjang dari input_string dan menyimpannya ke dalam variable panjang_string
	strcpy(result_string,input_string);//mengcopy string dari variable input_string ke variable result_string agar string variable input_string
	                                   //tidak terubah 
	for(int i=0;i<panjang_string; i++){//"for"loop untuk pengecekan dan penghapusan huruf hidup
		if(result_string[i]== 'a' || result_string[i]== 'A'||result_string[i]== 'e' || result_string[i]== 'E'|| result_string[i]=='i' || result_string[i]== 'I'|| result_string[i]== 'u' || result_string[i]== 'U'|| result_string[i] == 'o'|| result_string[i]== 'O'){
			//fungsi "if"diatas merupakan pengecekan huruf hidup
			for(int j=i; j<panjang_string; j++){//"for"loop untuk mengambil huruf yang bukan huruf hidup kemudian menyimpannya
			                                    // dalam string variabl result_string
				result_string[j]=result_string[j+1];
			}
			panjang_string--;//value variable panjang_string akan berkurang
			                 // syntax ini digunakan untuk mengurangi ukuran string variable result_string saat huruf vokal tidak diambil
			i--;//syntax ini digunakan agar saat pengecekan kata yang memiliki huruf vokal berdempetan, huruf vokal itu juga 
			    //tidak akan diambil/ditampung ke dalam string result_string		  
	 	}
	 }
}
int cetak_hasil(char result_string[]){//mendeclare parameter char result_string[] agar variable result_string dari fungsi hapus_vokal
                                      //bisa dipass ke fungsi cetak_hasil 
	printf("hasil output: %s\n",result_string);//menampilkan isi dari variable string result_string
}

int main(){
	int hasil_hitung;//mendeclare hasil_hitung sebagai untuk menampung data integer saat value hitung dari fungsi
	 				//hitung_vokal direturn ke fungsi main
	char input_string[300], result_string[300];//mendeclare string input_string untuk menampung input string dari user
	                                           //mendeclare string result_string untuk menampung string setelah dari pengolahan
	                                           //fungsi hapus_vokal dan untuk menampilkannya di fungsi main melalui fungsi cetak_hasil saat
	                                          //pemanggilan
	printf("masukan string: \n");//menampilkan tulisan "masukan string: " sebagai petunjuk untuk user saat input
	gets(input_string);//menangkap input string dari user dan disimpan dalam string variable input_string
	hasil_hitung = hitung_vokal(input_string);//memanggil fungsi hitung_vokal dan menyimpan hasil return fungsi tersebut kedalam variable
	                                          //hasil_hitung
	printf("jumlah vocal: %d\n",hasil_hitung);//menampilkan isi dari variable hasil_hitung
	hapus_vokal(input_string,result_string);//memanggil fungsi hapus_vokal untuk mengolah string variable input_string
	cetak_hasil(result_string);//memanggil fungsi cetak_hasil untuk menampilkan hasil pengolahan dari input_string yang di simpan didalam 
	                           //string variable result_string
	
	return 0;
}
