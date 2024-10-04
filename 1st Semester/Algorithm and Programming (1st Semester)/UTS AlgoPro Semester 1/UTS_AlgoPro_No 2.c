//NIM : 2602160750
//Nama : Bryan Orville Audric
//Kelas : LB20
#include <stdio.h>//menggunakan library standard input output untuk menerima input dan menampilkan output kepada user 

int main(){
	char KarakterPenyusun;//mendeclare variable KarakterPenyusun sebagai data karakter untuk menampung input user
	int KetinggianMenara, Space, KetentuanSpace;//mendeclare variable sebagai data integer untuk menampung input user
	printf("PENCETAKAN MENARA\n");// menampilkan tulisan diikuti oleh "\n" yang memiliki fungsi untuk mendisplay tulisan selanjutnya di line baru
	printf("=================\n");// menampilkan karakter"=================" 
								//	diikuti oleh "\n" yang  memiliki fungsi untuk mendisplay tulisan selanjutnya di line baru
	printf("\nIsi karakter yang menyusun: ");//mendisplay tulisan "isi karakter yang menyusun: " untuk memberikan petunjuk kepada user
											// saat menginput
	scanf("%c",&KarakterPenyusun);//mendapatkan input karakter dari user dan disimpan di variable KarakterPenyusun
	printf("\n");//memiliki fungsi untuk mendisplay output selanjutnya di line baru
	while(1){// "While" memiliki fungsi untuk meloopkan/mengulang statement didalam dengan terus menerus
	         // karena kondisi "While" adalah satu yang artinya benar
	printf("Tentukan Ketinggian Menara: ");//mendisplay tulisan "Tentukan Ketinggian Menara: " untuk memberikan petunjuk kepada user
											// saat menginput 
	scanf("%d",&KetinggianMenara);//mendapatkan input angka dari user dan di simpan di variable KetinggianMenara
	if(KetinggianMenara == 0){//pengecekan apakah input user sebelumnya yang disimpan pada variable KetinggianMenara sama dengan 0
		break;//apabila kondisi if diatas terpenuhi,"While" loop yang terus berjalan akan berhenti
	}
	Space = KetinggianMenara - 1;//mengset value variable Space sama dengan KetinggianMenara - 1
	for(int i = 1; i<=KetinggianMenara; i++){// di dalam loop for(), variable i diset valuenya menjadi satu dan akan terus bertambah valuenya 
	                                         //dengan satu
	                                        //statement didalam akan berjalan selama variable i kurang dari sama dengan KetinggianMenara
		KetentuanSpace=1;//mengset value variable KetentuanSpace sama dengan 1 
		printf("\t");//Memposisikan semua karakter yang akan diprintkan didalam loop for ke tengah
		while (KetentuanSpace <= Space){//mengecek apabila value variable KetentuanSpace kurang dari sama dengan value variable Space 
										// apabila kondisi "While" terpenuhi, statement didalam "While" loop akan terus berjalan sampai
										// kondisi "While" loop tidak terpenuhi			
			printf(" ");//jika kondisi while terpenuhi, statement di samping akan di jalankan
			KetentuanSpace++;//Value variable KetentuanSpace terus bertambah satu agar fungsi while tetap berjalan
		}
		for(int j=1; j<=i; j++){// di dalam loop for(), variable j diset valuenya menjadi satu dan akan terus bertambah valuenya 
	                            //dengan satu
	                            //statement didalam akan berjalan selama variable j kurang dari sama dengan variable i
			printf("%c ",KarakterPenyusun);//statement disamping akan terus dijalankan selama kondisi "for" loop masih terpenuhi
		}printf("\n");//memiliki fungsi untuk mendisplay output selanjutnya di line baru 
		Space--;//value variable Space akan berkurang terus menerus seiiring variable i bertambah
	}
	printf("\n");//memiliki fungsi untuk mendisplay output selanjutnya di line baru
}	
	printf("\nPencetakan Menara Telah Diakhiri");//menampilkan tulisan "Pencetakan Menara Telah Diakhiri"
	                                            // "\n" digunakan sebelum "printf()" agar "printf()"
	                                            // menampilkan output/tulisan di line baru
	return 0;
}
