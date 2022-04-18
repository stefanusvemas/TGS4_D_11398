#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[30];


int main(int argc, char *argv[]) {
	string nama,  username, password, kodeKamar, kodeKamar1, kodeKamar2, kodeKamar3, kodeKamar4, namaKamar1, namaKamar2, namaKamar3, namaKamar4, fasilitasKamar1, 
		fasilitasKamar2, fasilitasKamar3, fasilitasKamar4, diskonDisplay, konfirmasi;
	int pil, noTelp, umur, lamaSewa;
	float hargaKamar1, hargaKamar2, hargaKamar3, hargaKamar4,  hargaTotal, uang, diskon;
	bool menu, loginStatus, inputStatus;
	menu=true;
	loginStatus=false;
	inputStatus=false;
	strcpy(diskonDisplay,"Tidak Mendapat Diskon");
	strcpy(nama,"-");
	
	strcpy(kodeKamar1,"KL");
	strcpy(namaKamar1,"Luxury");
	hargaKamar1=2000000;
	strcpy(fasilitasKamar1,"Ya");
	
	strcpy(kodeKamar2,"KB");
	strcpy(namaKamar2,"Business");
	hargaKamar2=1500000;
	strcpy(fasilitasKamar2,"Ya");
	
	strcpy(kodeKamar3,"KE");
	strcpy(namaKamar3,"Eksekutif");
	hargaKamar3=1000000;
	strcpy(fasilitasKamar3,"Ya");
	
	strcpy(kodeKamar4,"KR");
	strcpy(namaKamar4,"Reguler");
	hargaKamar4=800000;
	strcpy(fasilitasKamar4,"Tidak");
	
	
	while(menu==true){
		system("cls");
		printf("====Kost Putra Sejahtera====");
		printf("\nCalon Penyewa	: %s", nama);
		printf("\n1. Login");	
		printf("\n2. Display");
		printf("\n3. Reservasi");
		printf("\n4. Pembayaran");
		printf("\n0. Exit");
		printf("\nPilih menu : "); scanf("%d", &pil);
		
		switch(pil){
			case 1:
				if(loginStatus==false){
					printf("\n\t[LOGIN]");
					printf("\n\tUsername : "); fflush(stdin); gets(username);
					printf("\tPassword : "); fflush(stdin); gets(password);
					
					if(strcmpi(username, "stefanus")==0 && strcmp(password, "11398")==0){
						printf("\t[Berhasil login sebagai %s]", username);
						loginStatus=true;
					}else if(strcmpi(username, "admin")==0 && strcmp(password, "admin")==0){
						printf("\t[Berhasil login sebagai %s]", username);
						loginStatus=true;
					}else{
						printf("\tPASSWORD/USERNAME SALAH");
					}
					
				}else{
					printf("\tSUDAH LOGIN");
				}
			break;
			case 2:
				if(loginStatus==true){
					printf("\n\t===Kamar Kost===");
					
					printf("\n[1] Kamar %s", namaKamar1);
					printf("\n\tHarga sewa/bulan	: Rp%.2f", hargaKamar1);
					printf("\n\tKode kamar		: %s", kodeKamar1);
					printf("\n\tFasilitas lengkap	: %s", fasilitasKamar1);
					
					printf("\n[2] Kamar %s", namaKamar2);
					printf("\n\tHarga sewa/bulan	: Rp%.2f", hargaKamar2);
					printf("\n\tKode kamar		: %s", kodeKamar2);
					printf("\n\tFasilitas lengkap	: %s", fasilitasKamar2);
					
					printf("\n[3] Kamar %s", namaKamar3);
					printf("\n\tHarga sewa/bulan	: Rp%.2f", hargaKamar3);
					printf("\n\tKode kamar		: %s", kodeKamar3);
					printf("\n\tFasilitas lengkap	: %s", fasilitasKamar3);
					
					printf("\n[4] Kamar %s",namaKamar4);
					printf("\n\tHarga sewa/bulan	: Rp%.2f", hargaKamar4);
					printf("\n\tKode kamar		: %s", kodeKamar4);
					printf("\n\tFasilitas lengkap	: %s", fasilitasKamar4);
				}else{
					printf("\tBELUM LOGIN");
				}
			break;
			case 3:
				if(loginStatus==true){
					printf("\n\tNama		: "); fflush(stdin); gets(nama);
					if(strlen(nama)<1){
						printf("\n\tNAMA TIDAK BOLEH KOSONG");
						break;
					}
					printf("\tUmur		: "); scanf("%d", &umur);
					if(umur<=0){
						printf("\n\tUMUR TIDAK BOLEH 0");
						break;
					}
					printf("\tNo telp		: "); scanf("%d", &noTelp);
					if(noTelp<=0){
						printf("\n\tNO TELP TIDAK BOLEH 0 atau kurang dari");
						break;
					}
					printf("\tLama sewa	: "); scanf("%d", &lamaSewa);
					if(lamaSewa<1){
						printf("\n\tLAMA SEWA TIDAK BOLEH 0 atau kurang dari");
						break;
					}
					printf("\tKode kamar	: "); fflush(stdin); gets(kodeKamar);
					if ((strcmpi(kodeKamar,"KL")==0) || (strcmpi(kodeKamar,"KB")==0) || (strcmpi(kodeKamar,"KE")==0) || (strcmpi(kodeKamar,"KR")==0)){
						printf("\n\tYakin dengan pesanan ini? [ya/tidak] : "); scanf("%s", &konfirmasi);
						if (strcmpi(konfirmasi, "ya")==0){
							printf("\n\tBerhasil Input data");
							inputStatus=true;
						}else if(strcmpi(konfirmasi, "tidak")==0){
							strcpy(nama,"-");
							umur=0;
							noTelp=0;
							lamaSewa=0;
							printf("\n\tBatal Input data");
						}else{
							printf("\n\tGagal Input data");
						}
					}else{
						printf("\n\tKAMAR TIDAK DITEMUKAN");
						break;
					}
					if(lamaSewa>5){
						diskon=0.06;
						strcpy(diskonDisplay,"6%");
						printf("\n\tANDA MENDAPATKAN DISKON %s", diskonDisplay);
					}
				}else{
					printf("\tBELUM LOGIN");
				}
			break;
			case 4:
				if(loginStatus==false){
					printf("\tBELUM LOGIN");
				}else if(inputStatus==false){
					printf("\tBELUM RESERVASI");
				}else{
					if(strcmpi(kodeKamar,"KL")==0){
						printf("\n\tKamar		: %s", namaKamar1);
						printf("\n\tUmur		: %d", umur);
						printf("\n\tNo Telp		: %d", noTelp);
						printf("\n\tHarga		: Rp%.2f", hargaKamar1);
						printf("\n\tLama Sewa	: %d Bulan", lamaSewa);
						printf("\n\tDiskon		: %s", diskonDisplay);
						printf("\n\t============================");
						hargaTotal = lamaSewa*hargaKamar1;
						hargaTotal = hargaTotal-(hargaTotal*diskon);
						printf("\n\tTotal Harga	: Rp%.2f", hargaTotal);
						printf("\n\tUang anda	: "); scanf("%f", &uang);
						
					}else if(strcmpi(kodeKamar,"KB")==0){
						printf("\n\tKamar		: %s", namaKamar2);
						printf("\n\tUmur		: %d", umur);
						printf("\n\tNo Telp		: %d", noTelp);
						printf("\n\tHarga		: Rp%.2f", hargaKamar2);
						printf("\n\tLama Sewa	: %d Bulan", lamaSewa);
						printf("\n\tDiskon		: %s", diskonDisplay);
						printf("\n\t============================");
						hargaTotal = lamaSewa*hargaKamar2;
						hargaTotal = hargaTotal-(hargaTotal*diskon);
						printf("\n\tTotal Harga	: Rp%.2f", hargaTotal);
						printf("\n\tUang anda	: "); scanf("%f", &uang);
						
					}else if(strcmpi(kodeKamar,"KE")==0){
						printf("\n\tKamar		: %s", namaKamar3);
						printf("\n\tUmur		: %d", umur);
						printf("\n\tNo Telp		: %d", noTelp);
						printf("\n\tHarga		: Rp%.2f", hargaKamar3);
						printf("\n\tLama Sewa	: %d Bulan", lamaSewa);
						printf("\n\tDiskon		: %s", diskonDisplay);
						printf("\n\t============================");
						hargaTotal = lamaSewa*hargaKamar3;
						hargaTotal = hargaTotal-(hargaTotal*diskon);
						printf("\n\tTotal Harga	: Rp%.2f", hargaTotal);
						printf("\n\tUang anda	: "); scanf("%f", &uang);
						
					}else if(strcmpi(kodeKamar,"KR")==0){
						printf("\n\tKamar		: %s", namaKamar4);
						printf("\n\tUmur		: %d", umur);
						printf("\n\tNo Telp		: %d", noTelp);
						printf("\n\tHarga		: Rp%.2f", hargaKamar4);
						printf("\n\tLama Sewa	: %d Bulan", lamaSewa);
						printf("\n\tDiskon		: %s", diskonDisplay);
						printf("\n\t============================");
						hargaTotal = lamaSewa*hargaKamar4;
						hargaTotal = hargaTotal-(hargaTotal*diskon);
						printf("\n\tTotal Harga	: Rp%.2f", hargaTotal);
						printf("\n\tUang anda	: "); scanf("%f", &uang);
						
					}else{
						printf("\n\tError");
					}
					if(uang<hargaTotal){
						printf("\n\tMAAF UANG ANDA KURANG");
					}else{
						printf("\n\tKembalian       : Rp%2.f", (uang - hargaTotal));
                        printf("\n\tPEMBAYARAN BERHASIL");
                        loginStatus = false;
                        inputStatus = false;
                        strcpy(username, "-");
					}
				}
			break;
			case 0:
				printf("\n\tStefanus Vemas Aditya Mahardika | 210711398 | D");
				printf("\n\tMengerjakan UGD dengan jujur");
				menu=false;
			break;
			default:
				printf("\n\tERROR");
			break;
		
		}getch();
	}
	
	
	
	return 0;
}
