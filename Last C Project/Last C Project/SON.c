#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void fileDisplayer() {
	FILE *fileptr;
	fileptr = fopen("C:\\Users\\Hp\\Desktop\\ebook.txt", "r");

	char KARAKTER;
	KARAKTER = fgetc(fileptr);

	while (KARAKTER != EOF) {
		printf("%c", KARAKTER);
		KARAKTER = fgetc(fileptr);
	}

	fclose(fileptr);
}

void vowelReserver(char *harf1, char *harf2, char *harf3, char *harf4) {

	printf("Reversing words...");
	int remover;
	char word1[40];
	char ch;
	int worduzunluk = 0, iceriyormu = 0, sayac = 0, i = 0, cevirici;
	char tersword[40];
	FILE *fileptr, *fwriter;

	fileptr = fopen("C:\\Users\\Hp\\Desktop\\ebook.txt", "r");
	fwriter = fopen("C:\\Users\\Hp\\Desktop\\kopyatemp.txt", "w");
	printf("\n");

	while ((ch = fgetc(fileptr)) != EOF) {
		fscanf(fileptr, "%s", word1);
		while (word1[worduzunluk] != '\0' && word1[worduzunluk] != ',') {
			worduzunluk++;
		}
		while (sayac <= worduzunluk) {
			if (word1[sayac] == *harf1 || word1[sayac] == *harf2 || word1[sayac] == *harf3 || word1[sayac] == *harf4) {
				iceriyormu++;
			}
			sayac++;
		}
		if (iceriyormu == 0) {
			fputs(word1, fwriter);
			fputs(" ", fwriter);
		}
		else {
			cevirici = worduzunluk;
			while(i <= worduzunluk || cevirici >= 0) {
				tersword[i] = word1[cevirici-1];
				i++;
				cevirici--;
			}
			tersword[worduzunluk] = '\0';
			fputs(tersword, fwriter);
			fputs(" ", fwriter);
		}
	iceriyormu = 0;
	worduzunluk = 0;
	sayac = 0;
	cevirici = 0;
	i = 0;
	}
	fclose(fileptr);
	fclose(fwriter);

	fileptr = fopen("C:\\Users\\Hp\\Desktop\\kopyatemp.txt", "r");
	fwriter = fopen("C:\\Users\\Hp\\Desktop\\ebook.txt", "w");

	while ((ch = fgetc(fileptr)) != EOF) {
		fscanf(fileptr, "%s", word1);
		fputs(word1, fwriter);
		fputs(" ", fwriter);
	}

	fclose(fileptr);
	fclose(fwriter);

	remover = remove("C:\\Users\\Hp\\Desktop\\kopyatemp.txt");
}

void mostusedvowels(int *harf1tekrarsayisi, int *harf2tekrarsayisi, int *harf3tekrarsayisi, int *harf4tekrarsayisi, char *harf1, char *harf2, char *harf3, char *harf4) {
	
	printf("Counting vowels...");
	char word1[40], ch;
	int harfarray[15];
	int sayi = 0;
	FILE *fileptr;

	fileptr = fopen("C:\\Users\\Hp\\Desktop\\ebook.txt", "r");
	printf("\n");

	for (sayi = 0; sayi <= 10; sayi++) {
		harfarray[sayi] = 0;
	}

	int worduzunluk = 0;

	while ((ch = fgetc(fileptr)) != EOF) {
		fscanf(fileptr, "%s", word1);
		while (word1[worduzunluk] != '\0') {
			worduzunluk++;
		}
		if (word1[worduzunluk - 1] == ',' || word1[worduzunluk - 1] == '.' || word1[worduzunluk - 1] == '!' || word1[worduzunluk - 1] == '?' || word1[worduzunluk - 1] == ':' || word1[worduzunluk - 1] == ';') {
			worduzunluk -= 1;
		}
		for (sayi = 0; sayi <= worduzunluk; sayi++) {
			if (word1[sayi] == 'a' || word1[sayi] == 'A') {      //harfarray için : a e i o u sýrasýyla
				harfarray[0] = harfarray[0] + 1;
			}
			if (word1[sayi] == 'e' || word1[sayi] == 'E') {
				harfarray[1] = harfarray[1] + 1;
			}
			if (word1[sayi] == 'i' || word1[sayi] == 'I') {
				harfarray[2] = harfarray[2] + 1;
			}
			if (word1[sayi] == 'o' || word1[sayi] == 'O') {
				harfarray[3] = harfarray[3] + 1;
			}
			if (word1[sayi] == 'u' || word1[sayi] == 'U') {
				harfarray[4] = harfarray[4] + 1;
			}	
		}
		worduzunluk = 0;
	}

	fclose(fileptr);

	int maxcounteri, locationcounteri, sayac, temp;
	int maximum[10];
	char location[] = { 'a', 'e', 'i', 'o', 'u' };
	char gecicichar;		// location a e i o u yu tutacak. Ardýndan sýralamaya göre harfi aþaðýdaki pointera yollamalý.

	for (sayac = 0; sayac <= 5; sayac++) {
		maximum[sayac] = 0;
	}

	
	for (maxcounteri = 0; maxcounteri <= 4; ++maxcounteri) {
		for (locationcounteri = maxcounteri + 1; locationcounteri <= 4; ++locationcounteri) {
			if (harfarray[maxcounteri] < harfarray[locationcounteri]) {
				temp = harfarray[maxcounteri];
				harfarray[maxcounteri] = harfarray[locationcounteri];
				harfarray[locationcounteri] = temp;

				gecicichar = location[maxcounteri];
				location[maxcounteri] = location[locationcounteri];
				location[locationcounteri] = gecicichar;
			}
		}
	}



	*harf1 = location[0];
	*harf2 = location[1];
	*harf3 = location[2];
	*harf4 = location[3];

	*harf1tekrarsayisi = harfarray[0];
	*harf2tekrarsayisi = harfarray[1];
	*harf3tekrarsayisi = harfarray[2];
	*harf4tekrarsayisi = harfarray[3];
}

void WordDeleter(char *harfsilarr) {
	
	int remover;
	printf("Deleting your words...");
	char word1[40];
	char ch;
	int worduzunluk = 0, iceriyormu = 0;
	char char1, char2, char3, char4;
	FILE *fileptr, *fwriter;

	fileptr = fopen("C:\\Users\\Hp\\Desktop\\ebook.txt", "r");			//dosya yolunu pointer ile yollayýnca hata veriyor. dosya açmýyor.
	fwriter = fopen("C:\\Users\\Hp\\Desktop\\kopyatemp.txt", "w");
	printf("\n");

	
	char1 = *(harfsilarr);
	char2 = *(harfsilarr + 1);
	char3 = *(harfsilarr + 2);
	char4 = *(harfsilarr + 3);

	while ((ch = fgetc(fileptr)) != EOF) {
		fscanf(fileptr, "%s", word1);  // tek tek kelime al
		while (word1[worduzunluk] != '\0' && word1[worduzunluk] != ',') {
			worduzunluk++;
		}
		if (word1[worduzunluk-1] == char1 || word1[worduzunluk-1] == char2 || word1[worduzunluk-1] == char3 || word1[worduzunluk-1] == char4) {
			iceriyormu++;
		}
		if (iceriyormu == 0) {
			fputs(word1, fwriter);
			fputs(" ", fwriter);	
		}
		iceriyormu = 0;
		worduzunluk = 0;
	}

	fclose(fileptr);
	fclose(fwriter);

	fileptr = fopen("C:\\Users\\Hp\\Desktop\\kopyatemp.txt", "r");
	fwriter = fopen("C:\\Users\\Hp\\Desktop\\ebook.txt", "w"); 

	while ((ch = fgetc(fileptr)) != EOF) {
		fscanf(fileptr, "%s", word1);
		fputs(word1, fwriter);
		fputs(" ", fwriter);
	}

	fclose(fileptr);
	fclose(fwriter);

	remover = remove("C:\\Users\\Hp\\Desktop\\kopyatemp.txt");
}


int main() {

	char karakterler[10];
	int a, i;
	int h1tekrar = 0, h2tekrar = 0, h3tekrar = 0, h4tekrar = 0;
	char harf1, harf2, harf3, harf4;
	
	printf("Please enter 4 letters to delete words ending with that characters.\n");

	for (i = 0, a = 1; i <= 3, a <= 4; a++, i++) {
		printf("Enter %d. letter: ", a);
		scanf(" %c", karakterler+i);
		while (*(karakterler + i) == '0' || *(karakterler + i) == '1' || *(karakterler + i) == '2' || *(karakterler + i) == '3' || *(karakterler + i) == '4' || *(karakterler + i) == '5' || *(karakterler + i) == '6' || *(karakterler + i) == '7' || *(karakterler + i) == '8' || *(karakterler + i) == '9')
		{
			printf("Please enter letters instead of numbers.\n");
			scanf(" %c", karakterler+i);
		}
	}
	
	printf("Your letters are: ");
	for (i = 0; i <= 3; i++)
	{
		printf("%c ", karakterler[i]);
	}
	printf("\n\n");

	WordDeleter(karakterler);
	mostusedvowels(&h1tekrar, &h2tekrar, &h3tekrar, &h4tekrar, &harf1, &harf2, &harf3, &harf4);
	vowelReserver(&harf1,&harf2,&harf3,&harf4);

	printf("\n\n");

	printf("Vowel %c occured %d times\n", harf1, h1tekrar);
	printf("Vowel %c occured %d times\n", harf2, h2tekrar);
	printf("Vowel %c occured %d times\n", harf3, h3tekrar);
	printf("Vowel %c occured %d times\n", harf4, h4tekrar);

	fileDisplayer();
}
