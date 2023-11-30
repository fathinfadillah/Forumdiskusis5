#include <stdio.h>

int main() {
    // Deklarasi variabel
    int var1, var2, var3;
    char operator1, operator2;

    // Menerima input dari pengguna
    printf("Masukkan ekspresi matematika (misal: 3 + 8 * 4): ");
    
	// Validasi jumlah input dan operator
    if (scanf("%Ld %c %Ld %c %Ld", &var1, &operator1, &var2, &operator2, &var3) != 5 ||
        (operator1 != '+' && operator1 != '-' && operator1 != '*' && operator1 != '/') ||
        (operator2 != '\0' && operator2 != '+' && operator2 != '-' && operator2 != '*' && operator2 != '/') ||
        getchar() != '\n') {
        printf("Error: Harap masukkan ekspresi dengan format yang benar.\n");
        return 1; // Keluar dari program dengan status error
    }
    
    // Melakukan perhitungan dengan memperhatikan prioritas operator
    int hasil;
    
    if (operator1 == '*' && operator2 == '+') {
        hasil = var2 * var3 + var1;
    } else if (operator1 == '+' && operator2 == '*') {
        hasil = var1 + var2 * var3;
    } else if (operator1 == '*' && operator2 == '-') {
        hasil = var2 * var3 - var1;
    } else if (operator1 == '-' && operator2 == '*') {
        hasil = var1 - var2 * var3;
    } else if (operator1 == '/' && operator2 == '*') {
    	if (var2 !=0){
    		hasil = var1 / var2 * var3;
		} else {
			printf("Error: Pembagian dengan nol tidak diizinkan.\n");
            return 1; // Keluar dari program dengan status error
		}
    } else if (operator1 == '*' && operator2 == '/') {
    	if (var3 !=0){
    		hasil = var1 * var2 / var3;
		} else {
			printf("Error: Pembagian dengan nol tidak diizinkan.\n");
            return 1; // Keluar dari program dengan status error
		}
    } else if (operator1 == '*' && operator2 == '*') {
        hasil = var1 * var2 * var3;
    } else if (operator1 == '/' && operator2 == '+') {
    	if (var2 !=0){
    		hasil = var1 / var2 + var3;
		} else {
			printf("Error: Pembagian dengan nol tidak diizinkan.\n");
            return 1; // Keluar dari program dengan status error
		}
    } else if (operator1 == '+' && operator2 == '/') {
    	if (var3 !=0){
    		hasil = var1 + var2 / var3;
		} else {
			printf("Error: Pembagian dengan nol tidak diizinkan.\n");
            return 1; // Keluar dari program dengan status error
		}
    } else if (operator1 == '/' && operator2 == '-') {
    	if (var2 !=0){
    		hasil = var1 / var2 - var3;
		} else {
			printf("Error: Pembagian dengan nol tidak diizinkan.\n");
            return 1; // Keluar dari program dengan status error
		}
    } else if (operator1 == '-' && operator2 == '/') {
    	if (var3 !=0){
    		hasil = var1 - var2 / var3;
		} else {
			printf("Error: Pembagian dengan nol tidak diizinkan.\n");
            return 1; // Keluar dari program dengan status error
		}
    } else if (operator1 == '/' && operator2 == '/') {
    	if (var2 !=0 && var3 !=0){
    		hasil = var1 / var2 / var3;
		} else {
			printf("Error: Pembagian dengan nol tidak diizinkan.\n");
            return 1; // Keluar dari program dengan status error
		}
    } else if (operator1 == '+' && operator2 == '-') {
        hasil = var1 + var2 - var3;
    } else if (operator1 == '-' && operator2 == '+') {
        hasil = var1 - var2 + var3;
    } else if (operator1 == '+' && operator2 == '+') {
        hasil = var1 + var2 + var3;
    } else if (operator1 == '-' && operator2 == '-') {
        hasil = var1 - var2 - var3;
    } else {
        printf("Operasi tidak valid. Pastikan format input benar.\n");
        return 1; // Keluar dari program dengan kode error
    }

    // Menampilkan hasil perhitungan
    printf("Hasil: %d\n", hasil);
    
    getchar(); //Menunggu pengguna menekan Enter

    return 0; // Keluar dari program tanpa error
}

