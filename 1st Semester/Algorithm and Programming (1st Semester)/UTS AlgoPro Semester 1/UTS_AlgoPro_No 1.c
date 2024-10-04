//NIM :2602160750
//Nama : Bryan Orville Audric
//Kelas :LB20
#include <stdio.h>//menggunakan library standard input output untuk mendapatkan input dan menampilkan output

int main(){
	int Binusian, JumlahAbsen, MaksimalAbsen, Semester;// mendeclare variable sebagai data integer untuk menampung input yang akan diberikan user
	scanf("%d %d %d",&Binusian, &JumlahAbsen, &MaksimalAbsen);//meminta user untuk menginput tahun binusian, jumlah absen,
															//dan maksimal absen yang dimiliki
															
	if(Binusian > 2026){//mengecek apabila tahun binusian berada diatas tahun 2026.
		printf("Anda belum terdaftar sebagai mahasiswa BINUS\n");//jika tahun binusian berada diatas 2026, statement disamping akan dijalankan
		
	}else if(Binusian<=2026 && Binusian >=2021){//mengecek apabila tahun binusian berada diantara tahun 2026 dan 2021
		if(Binusian == 2026){//mengecek tahun binusian apakah sama dengan 2026
			printf("Anda Semester 1,");//menjalankan statement disamping saat tahun binusian sama dengan 2026
		}
		if(Binusian == 2025){//mengecek tahun binusian apakah sama dengan 2025
			printf("Anda Semester 3,");//menjalankan statement disamping saat tahun binusian sama dengan 2025
		}
		if(Binusian == 2024){//mengecek tahun binusian apakah sama dengan 2024
			printf("Anda Semester 5,");//menjalankan statement disamping saat tahun binusian sama dengan 2024
		}
		if(Binusian == 2023){//mengecek tahun binusian apakah sama dengan 2023
			printf("Anda Semester 7,");//menjalankan statement disamping saat tahun binusian sama dengan 2023
		}
		if(Binusian == 2022){//mengecek tahun binusian apakah sama dengan 2022
			printf("Anda Semester 9,");//menjalankan statement disamping saat tahun binusian sama dengan 2022
		}
		if(Binusian == 2021){//mengecek tahun binusian apakah sama dengan 2021
			printf("Anda Semester 11,");//menjalankan statement disamping saat tahun binusian sama dengan 2021
		}
			if(JumlahAbsen < MaksimalAbsen){//akan ada pengecekan lagi terkait dengan jumlah absen terhadap maksimal absen
			
			printf(" Status Hijau, Tetap Semangat Kuliahnya\n");//jika jumlah absen lebih besar dari maksimal absen yang dimiliki
																//statement disamping akan dijalankan
											
			}
			if(JumlahAbsen == MaksimalAbsen){//Pengecekan lagi terkait jumlah absen terhadap maksimal absen apabila kondisi if sebelumnya belum terpenuhi
										
			printf(" Status Kuning, Ingat Anda tidak boleh absen lagi !!!\n");//jika jumlah absen sama dengan maksimal absen yang dimiliki
																			// statement disamping akan dijalankan
			}
			if(JumlahAbsen > MaksimalAbsen){//Pengecekan lagi terkait jumlah absen terhadap maksimal absen apabila kondisi if sebelumnya belum terpenuhi
			printf(" Status Merah, Anda sudah tidak bisa mengikuti ujian !!!\n");//jika jumlah absen kurang dari maksimal absen yang dimiliki
																				// statement disamping akan dijalankan	
			}
			}else if(Binusian < 2021){//mengecek apabila tahun binusian berada dibawah tahun 2021
			printf("Anda seharusnya sudah lulus dari BINUS\n");//jika tahun binusian berada dibawah tahun 2021,
				
															//statement disamping akan dijalankan
	}else{//jika semua kondisi if sebelumnya tidak terpenuhi, program tidak akan menjalankan statement apapun
}
	return 0;
}
