#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Soal Quiz No 2
struct StakeHolder{
	char nama[100];
	char alamat[100];
	char NoHP[13];
	char TipePartner[50];
};

struct Product{
	char NamaProduk[100];
	float HargaSatuan;
	int stok;
};

struct User{
	char username[100];
	char password[100];
};
void StakeHolderAdd(){
	struct StakeHolder StakeHolderData;
	FILE*fptr;
	fptr=fopen("StakeHolder.txt","a");
		printf("Nama: ");
		fflush(stdin);
		scanf("%[^\n]",StakeHolderData.nama);
		getchar();
	
		printf("Alamat: ");
		fflush(stdin);
		scanf("%[^\n]",StakeHolderData.alamat);
		getchar();
		
		printf("No HP: ");
		scanf("%s",StakeHolderData.NoHP);
		getchar();
		
		printf("Tipe Partner: ");
		scanf("%s",StakeHolderData.TipePartner);
		getchar();
	
	fprintf(fptr,"\n%s;%s;%s;%s\n",StakeHolderData.nama,StakeHolderData.alamat,StakeHolderData.NoHP,StakeHolderData.TipePartner);
	fclose(fptr);
}

void StakeHolderRead(struct StakeHolder StakeHolderData[100],int *x){
	FILE *fptr;
	int limit=*x;
	fptr=fopen("StakeHolder.txt","r");
	printf("Nama\t\t\t\t Alamat\t\t\t No HP\t\t\t Tipe Partner\n");
	printf("==============================================================================================\n");
	while(fscanf(fptr,"\n%[^\';'];%[^\';'];%[^\';'];%s\n",&StakeHolderData[limit].nama,&StakeHolderData[limit].alamat, &StakeHolderData[limit].NoHP, &StakeHolderData[limit].TipePartner)!=EOF){
		printf("%-20s\t\t %-10s\t\t %-10s\t\t %-10s\n",StakeHolderData[limit].nama,StakeHolderData[limit].alamat,StakeHolderData[limit].NoHP, StakeHolderData[limit].TipePartner);
		limit++;
	}
	*x=limit;
	printf("\n");
	fclose(fptr);
}

void StakeHolderDelete(struct StakeHolder StakeHolderData[100], int *x){
	FILE *fptr;
	int found=0;
	char nametest[100];
	StakeHolderRead(StakeHolderData,x);
	int limit=*x;
	fptr=fopen("StakeHolder.txt","w");
	printf("Masukan nama dari data yang ingin dihapus: ");
	fflush(stdin);
	scanf("%[^\n]",nametest);
	getchar();
	
	for(int i=0; i<limit; i++){
		if((strcmp(StakeHolderData[i].nama,nametest))==0){
			found=1;
			printf("test\n");
			continue;
		}else{
			if(i == limit - 1){
            	fprintf(fptr, "%s;%s;%s;%s", StakeHolderData[i].nama, StakeHolderData[i].alamat, StakeHolderData[i].NoHP, StakeHolderData[i].TipePartner);
			}else{
				fprintf(fptr, "%s;%s;%s;%s\n", StakeHolderData[i].nama, StakeHolderData[i].alamat, StakeHolderData[i].NoHP, StakeHolderData[i].TipePartner);
			}
		}
	}

	if(found==0){
		printf("Nama tidak ditemukan\n");
	}else{
		system("cls");
		printf("--------------------Data terhapus--------------------\n");
	}
	fclose(fptr);
}

void StakeHolderUpdate(struct StakeHolder StakeHolderData [100], int *x){
	FILE*fptr;
	int found=0;
	int indubah;
	char nametest[100];
	StakeHolderRead(StakeHolderData,x);
	int limit=*x;
	printf("Masukan nama dari data yang ingin diubah: ");
	fflush(stdin);
	scanf("%[^\n]",nametest);
	getchar();
	for(int i=0;i<limit;i++){
		if((strcmp(StakeHolderData[i].nama,nametest))==0){
			found=1;
			indubah=i;
			break;
		}
	}
	if(found==0){
		printf("Nama dari data tidak ditemukan\n");
		indubah=0;
		system("cls");
		system("pause");
	}else{
		fptr=fopen("StakeHolder.txt","w");
		int menu;
		do{
		system("cls");
		printf("Data yang ingin diubah\n");
		printf("1. Nama\n");
		printf("2. Alamat\n");
		printf("3. No HP\n");
		printf("4. Tipe Partner\n");
		printf("5. Exit\n");
		printf("Pilih data yang ingin diubah: ");
		scanf("%d",&menu);	
		switch(menu){
			case 1:
				system("cls");
				printf("Nama: ");
				fflush(stdin);
				scanf("%[^\n]",StakeHolderData[indubah].nama);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 2:
				system("cls");
				printf("Alamat: ");
				fflush(stdin);
				scanf("%[^\n]",StakeHolderData[indubah].alamat);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 3:
				system("cls");
				printf("No HP: ");
				fflush(stdin);
				scanf("%[^\n]",StakeHolderData[indubah].NoHP);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 4:
				system("cls");
				printf("Tipe Partner: ");
				fflush(stdin);
				scanf("%[^\n]",StakeHolderData[indubah].TipePartner);
				getchar();
				printf("\n");
				system("pause");
				break;
			case 5:
				for (int i = 0; i < limit; i++)
                {
                    if(i == limit-1){
                    	fprintf(fptr, "%s;%s;%s;%s", StakeHolderData[i].nama, StakeHolderData[i].alamat, StakeHolderData[i].NoHP, StakeHolderData[i].TipePartner);
					}else{
						fprintf(fptr, "%s;%s;%s;%s\n", StakeHolderData[i].nama, StakeHolderData[i].alamat,StakeHolderData[i].NoHP, StakeHolderData[i].TipePartner);
					}
                }			
			}			
		}while(menu!=5);
	}
	system("cls");
	printf("\n");
	printf("--------------------Data terupdate------------------------\n");
	fclose(fptr);
}
void StakeHolder(){
	int menu;
	struct StakeHolder StakeHolderData [100];
	do{
	int limit=0;
	printf("--------------Menu StakeHolder--------------\n");
	printf("1. Create/Add Data\n");
	printf("2. Read Data\n");
	printf("3. Delete Data\n");
	printf("4. Update Data\n");
	printf("5. Exit\n");
	printf("\nMenu: ");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			system("cls");
			StakeHolderAdd();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			StakeHolderRead(StakeHolderData,&limit);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			StakeHolderDelete(StakeHolderData,&limit);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			StakeHolderUpdate(StakeHolderData,&limit);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			printf("------------------------------Kembali ke menu utama----------------------------\n\n");	
			}
		}while(menu!=5);
}
void ProdukAdd(){
	struct Product ProductData;
	FILE*fptr;
	fptr=fopen("Product.txt","a");
		printf("Nama Produk: ");
		fflush(stdin);
		scanf("%[^\n]",ProductData.NamaProduk);
		getchar();
	
		printf("Harga Satuan: ");
		fflush(stdin);
		scanf("%f",&ProductData.HargaSatuan);
		getchar();
		
		printf("Stok: ");
		scanf("%d",&ProductData.stok);
		getchar();	
	
	fprintf(fptr,"\n%s;%.2f;%d\n",ProductData.NamaProduk,ProductData.HargaSatuan,ProductData.stok);
	fclose(fptr);
}

void ProdukRead(struct Product ProductData[100],int *x){
	FILE *fptr;
	int limit=*x;
	fptr=fopen("Product.txt","r");
	printf("Nama Produk\t\t\t Harga Satuan\t\t\t Stok\n");
	printf("==============================================================================================\n");
	while(fscanf(fptr,"\n%[^\';'];%f;%d\n",&ProductData[limit].NamaProduk,&ProductData[limit].HargaSatuan, &ProductData[limit].stok)!=EOF){
		printf("%-20s\t\t %-20.2f\t\t %-10d\n",ProductData[limit].NamaProduk,ProductData[limit].HargaSatuan,ProductData[limit].stok);
		limit++;
	}
	*x=limit;
	printf("\n");
	fclose(fptr);
}

void ProdukDelete(struct Product ProductData[100], int *x){
	FILE *fptr;
	int found=0;
	char nametest[100];
	ProdukRead(ProductData,x);
	int limit=*x;
	fptr=fopen("Product.txt","w");
	printf("Masukan nama produk dari data yang ingin dihapus: ");
	fflush(stdin);
	scanf("%[^\n]",nametest);
	getchar();
	
	for(int i=0; i<limit; i++){
		if((strcmp(ProductData[i].NamaProduk,nametest))==0){
			found=1;
			continue;
		}else{
			if(i == limit - 1){
            	fprintf(fptr, "%s;%.2f;%d", ProductData[i].NamaProduk, ProductData[i].HargaSatuan, ProductData[i].stok);
			}else{
				fprintf(fptr, "%s;%.2f;%d\n", ProductData[i].NamaProduk, ProductData[i].HargaSatuan, ProductData[i].stok);
			}
		}
	}

	if(found==0){
		printf("Nama produk tidak ditemukan\n");
	}else{
		system("cls");
		printf("--------------------Data terhapus--------------------\n");
	}
	fclose(fptr);
}

void ProdukUpdate(struct Product ProductData [100], int *x){
	FILE*fptr;
	int found=0;
	int indubah;
	char nametest[100];
	ProdukRead(ProductData,x);
	int limit=*x;
	printf("Masukan nama dari produk yang ingin diubah: ");
	fflush(stdin);
	scanf("%[^\n]",nametest);
	getchar();
	for(int i=0;i<limit;i++){
		if((strcmp(ProductData[i].NamaProduk,nametest))==0){
			found=1;
			indubah=i;
			break;
		}
	}
	if(found==0){
		printf("Nama produk tidak ditemukan\n");
		indubah=0;
		system("cls");
		system("pause");
	}else{
		fptr=fopen("Product.txt","w");
		int menu;
		do{
		system("cls");
		printf("Data yang ingin diubah\n");
		printf("1. Nama Produk\n");
		printf("2. Harga Satuan\n");
		printf("3. Stok\n");
		printf("4. Exit\n");
		printf("Pilih data yang ingin diubah: ");
		scanf("%d",&menu);	
		switch(menu){
			case 1:
				system("cls");
				printf("Nama Produk: ");
				fflush(stdin);
				scanf("%[^\n]",ProductData[indubah].NamaProduk);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 2:
				system("cls");
				printf("Harga Satuan: ");
				fflush(stdin);
				scanf("%f",&ProductData[indubah].HargaSatuan);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 3:
				system("cls");
				printf("Stok: ");
				fflush(stdin);
				scanf("%d",&ProductData[indubah].stok);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 4:
				for (int i = 0; i < limit; i++)
                {
                	printf("%d",limit);
                    if(i == limit-1){
                    	fprintf(fptr, "%s;%.2f;%d", ProductData[i].NamaProduk, ProductData[i].HargaSatuan, ProductData[i].stok);
					}else{
						fprintf(fptr, "%s;%.2f;%d\n", ProductData[i].NamaProduk, ProductData[i].HargaSatuan,ProductData[i].stok);
					}
                }
				break;			
			}			
		}while(menu!=4);
	}
	system("cls");
	printf("\n");
	printf("--------------------Data terupdate------------------------\n");
	fclose(fptr);
}
void Product(){
	int menu;
	struct Product ProductData [100];
	do{
	int limit=0;
	printf("--------------Menu Produk--------------\n");
	printf("1. Create/Add Data\n");
	printf("2. Read Data\n");
	printf("3. Delete Data\n");
	printf("4. Update Data\n");
	printf("5. Exit\n");
	printf("\nMenu: ");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			system("cls");
			ProdukAdd();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			ProdukRead(ProductData,&limit);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			ProdukDelete(ProductData,&limit);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			ProdukUpdate(ProductData,&limit);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			printf("------------------------------Kembali ke menu utama----------------------------\n\n");	
			}
		}while(menu!=5);
}

void UserAdd(){
	struct User UserData;
	FILE*fptr;
	fptr=fopen("User.txt","a");
		printf("Username: ");
		fflush(stdin);
		scanf("%s",UserData.username);
		getchar();
	
		printf("Password: ");
		fflush(stdin);
		scanf("%s",UserData.password);
		getchar();
			
	fprintf(fptr,"\n%s;%s\n",UserData.username,UserData.password);
	fclose(fptr);
}

void UserRead(struct User UserData[100],int *x ){
	FILE *fptr;
	int limit=*x;
	fptr=fopen("User.txt","r");
	printf("Username\t\t\t Password\n");
	printf("==============================================================================================\n");
	while(fscanf(fptr,"\n%[^';'];%s\n",&UserData[limit].username,&UserData[limit].password)!=EOF){
		printf("%-20s\t\t %-20s\n",UserData[limit].username,UserData[limit].password);
		limit++;
	}
	*x=limit;
	printf("\n");
	fclose(fptr);
}

void UserDelete(struct User UserData[100],int *x){
	FILE *fptr;
	int found=0;
	char nametest[100];
	UserRead(UserData,x);
	int limit=*x;
	fptr=fopen("User.txt","w");
	printf("Masukan username dari akun yang ingin dihapus: ");
	fflush(stdin);
	scanf("%s",nametest);
	getchar();
	
	for(int i=0; i<limit; i++){
		if((strcmp(UserData[i].username,nametest))==0){
			found=1;
			continue;
		}else{
			if(i == limit - 1){
            	fprintf(fptr, "%s;%s", UserData[i].username, UserData[i].password);
			}else{
				fprintf(fptr, "%s;%s\n", UserData[i].username, UserData[i].password);
			}
		}
	}

	if(found==0){
		printf("Username tidak ditemukan\n");
	}else{
		system("cls");
		printf("--------------------Akun terhapus--------------------\n");
	}
	fclose(fptr);
}

void UserUpdate(struct User UserData [100], int *x){
	FILE*fptr;
	int found=0;
	int indubah;
	char nametest[100];
	UserRead(UserData,x);
	int limit=*x;
	printf("Masukan nama dari produk yang ingin diubah: ");
	fflush(stdin);
	scanf("%[^\n]",nametest);
	getchar();
	for(int i=0;i<limit;i++){
		if((strcmp(UserData[i].username,nametest))==0){
			found=1;
			indubah=i;
			break;
		}
	}
	if(found==0){
		printf("Username tidak ditemukan\n");
		indubah=0;
		system("cls");
		system("pause");
	}else{
		fptr=fopen("User.txt","w");
		int menu;
		do{
		system("cls");
		printf("Data yang ingin diubah\n");
		printf("1. Username\n");
		printf("2. Password\n");
		printf("3. Exit\n");
		printf("Pilih data yang ingin diubah: ");
		scanf("%d",&menu);	
		switch(menu){
			case 1:
				system("cls");
				printf("Username: ");
				fflush(stdin);
				scanf("%s",UserData[indubah].username);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 2:
				system("cls");
				printf("Password: ");
				fflush(stdin);
				scanf("%s",UserData[indubah].password);
				getchar();
				printf("\n");
				system("pause");
				break;

			case 3:
				for (int i = 0; i < limit; i++)
                {
                	printf("%d",limit);
                    if(i == limit-1){
                    	fprintf(fptr, "%s;%s", UserData[i].username, UserData[i].password);
					}else{
						fprintf(fptr, "%s;%s\n", UserData[i].username, UserData[i].password);
					}
                }
				break;			
			}			
		}while(menu!=3);
	}
	system("cls");
	printf("\n");
	printf("--------------------Akun terupdate------------------------\n");
	fclose(fptr);
}
void User(){
	int menu;
	struct User UserData [100];
	do{
	int limit=0;
	printf("--------------Menu Admin--------------\n");
	printf("1. Create/Add Account\n");
	printf("2. Read Account\n");
	printf("3. Delete Account\n");
	printf("4. Update Account\n");
	printf("5. Exit\n");
	printf("\nMenu: ");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			system("cls");
			UserAdd();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			UserRead(UserData,&limit);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			UserDelete(UserData,&limit);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			UserUpdate(UserData,&limit);
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			printf("------------------------------Kembali ke menu utama----------------------------\n\n");	
			}
		}while(menu!=5);
}

int main(){
	int menu;
	char pass[]="admin";
	char test[10];
	do{
	printf("----------Menu------------\n");
	printf("1. Manage Stakeholder\n");
	printf("2. Manage Product\n");
	printf("3. Manage User\n");
	printf("4. Exit\n");
	printf("\nMenu: ");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			system("cls");
			StakeHolder();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			Product();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			printf("Masukan Password: ");
			scanf("%s",test);
			getchar();
			while(strcmp(test,pass)!=0){
				system("cls");
				printf("---------------------------Invalid Password----------------------------\n");
				printf("Masukan password lagi: ");
				scanf("%s",test);
				getchar();
			}
			system("cls");
			User();
			system("pause");
			system("cls");
			break;
		}
	}while(menu!=4);
	system("cls");
	printf("-------------------------Program ditutup--------------------------------\n");
}
