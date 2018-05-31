#include <stdio.h>
#include <stdlib.h>

void initTonine(int tonine[], int i) {
	if (i == 9) {
		return;
	}
	tonine[i] = 0;
	initTonine(tonine, ++i);
}

int checkTonine(int tonine[], int i) {
	if (i == 9) {
		return 1;
	}

	if (tonine[i] == 0) {
		return 0;
	}

	// printf("Tonine i %d vale %d\n", i, tonine[i]);

	return checkTonine(tonine, ++i);
}

void play(int games, int i) {
	if (i == games) {
		return;
	}

	int mov00;
	mov00 = 0;
	int mov01;
	mov01 = 0;
	int mov02;
	mov02 = 0;
	int mov03;
	mov03 = 0;
	int mov04;
	mov04 = 0;
	int mov05;
	mov05 = 0;
	int mov06;
	mov06 = 0;
	int mov07;
	mov07 = 0;
	int mov08;
	mov08 = 0;

	int mov10;
	mov10 = 0;
	int mov11;
	mov11 = 0;
	int mov12;
	mov12 = 0;
	int mov13;
	mov13 = 0;
	int mov14;
	mov14 = 0;
	int mov15;
	mov15 = 0;
	int mov16;
	mov16 = 0;
	int mov17;
	mov17 = 0;
	int mov18;
	mov18 = 0;

	int mov20;
	mov20 = 0;
	int mov21;
	mov21 = 0;
	int mov22;
	mov22 = 0;
	int mov23;
	mov23 = 0;
	int mov24;
	mov24 = 0;
	int mov25;
	mov25 = 0;
	int mov26;
	mov26 = 0;
	int mov27;
	mov27 = 0;
	int mov28;
	mov28 = 0;

	int mov30;
	mov30 = 0;
	int mov31;
	mov31 = 0;
	int mov32;
	mov32 = 0;
	int mov33;
	mov33 = 0;
	int mov34;
	mov34 = 0;
	int mov35;
	mov35 = 0;
	int mov36;
	mov36 = 0;
	int mov37;
	mov37 = 0;
	int mov38;
	mov38 = 0;

	int mov40;
	mov40 = 0;
	int mov41;
	mov41 = 0;
	int mov42;
	mov42 = 0;
	int mov43;
	mov43 = 0;
	int mov44;
	mov44 = 0;
	int mov45;
	mov45 = 0;
	int mov46;
	mov46 = 0;
	int mov47;
	mov47 = 0;
	int mov48;
	mov48 = 0;

	int mov50;
	mov50 = 0;
	int mov51;
	mov51 = 0;
	int mov52;
	mov52 = 0;
	int mov53;
	mov53 = 0;
	int mov54;
	mov54 = 0;
	int mov55;
	mov55 = 0;
	int mov56;
	mov56 = 0;
	int mov57;
	mov57 = 0;
	int mov58;
	mov58 = 0;

	int mov60;
	mov60 = 0;
	int mov61;
	mov61 = 0;
	int mov62;
	mov62 = 0;
	int mov63;
	mov63 = 0;
	int mov64;
	mov64 = 0;
	int mov65;
	mov65 = 0;
	int mov66;
	mov66 = 0;
	int mov67;
	mov67 = 0;
	int mov68;
	mov68 = 0;

	int mov70;
	mov70 = 0;
	int mov71;
	mov71 = 0;
	int mov72;
	mov72 = 0;
	int mov73;
	mov73 = 0;
	int mov74;
	mov74 = 0;
	int mov75;
	mov75 = 0;
	int mov76;
	mov76 = 0;
	int mov77;
	mov77 = 0;
	int mov78;
	mov78 = 0;

	int mov80;
	mov80 = 0;
	int mov81;
	mov81 = 0;
	int mov82;
	mov82 = 0;
	int mov83;
	mov83 = 0;
	int mov84;
	mov84 = 0;
	int mov85;
	mov85 = 0;
	int mov86;
	mov86 = 0;
	int mov87;
	mov87 = 0;
	int mov88;
	mov88 = 0;

	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &mov00, &mov01, &mov02, &mov03, &mov04, &mov05, &mov06, &mov07, &mov08, &mov10, &mov11, &mov12, &mov13, &mov14, &mov15, &mov16, &mov17, &mov18, &mov20, &mov21, &mov22, &mov23, &mov24, &mov25, &mov26, &mov27, &mov28, &mov30, &mov31, &mov32, &mov33, &mov34, &mov35, &mov36, &mov37, &mov38, &mov40, &mov41, &mov42, &mov43, &mov44, &mov45, &mov46, &mov47, &mov48, &mov50, &mov51, &mov52, &mov53, &mov54, &mov55, &mov56, &mov57, &mov58, &mov60, &mov61, &mov62, &mov63, &mov64, &mov65, &mov66, &mov67, &mov68, &mov70, &mov71, &mov72, &mov73, &mov74, &mov75, &mov76, &mov77, &mov78, &mov80, &mov81, &mov82, &mov83, &mov84, &mov85, &mov86, &mov87, &mov88);

	
	int sumvalid, valid;
	sumvalid = 0;
	valid = 0;

	printf("Instancia %d\n", i + 1);

	int tonine[9];
	
initTonine(tonine, 0); //1
	tonine[mov00-1] = 1; //printf("vale %d\n", mov00);
	tonine[mov01-1] = 1; //printf("vale %d\n", mov01);
	tonine[mov02-1] = 1; //printf("vale %d\n", mov02);
	tonine[mov10-1] = 1; //printf("vale %d\n", mov10);
	tonine[mov11-1] = 1; //printf("vale %d\n", mov11);
	tonine[mov12-1] = 1; //printf("vale %d\n", mov12);
	tonine[mov20-1] = 1; //printf("vale %d\n", mov20);
	tonine[mov21-1] = 1; //printf("vale %d\n", mov21);
	tonine[mov22-1] = 1; //printf("vale %d\n", mov22);
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //2
	tonine[mov03-1] = 1;
	tonine[mov04-1] = 1;
	tonine[mov05-1] = 1;
	tonine[mov13-1] = 1;
	tonine[mov14-1] = 1;
	tonine[mov15-1] = 1;
	tonine[mov23-1] = 1;
	tonine[mov24-1] = 1;
	tonine[mov25-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //3
	tonine[mov06-1] = 1;
	tonine[mov07-1] = 1;
	tonine[mov08-1] = 1;
	tonine[mov16-1] = 1;
	tonine[mov17-1] = 1;
	tonine[mov18-1] = 1;
	tonine[mov26-1] = 1;
	tonine[mov27-1] = 1;
	tonine[mov28-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //4
	tonine[mov30-1] = 1;
	tonine[mov31-1] = 1;
	tonine[mov32-1] = 1;
	tonine[mov40-1] = 1;
	tonine[mov41-1] = 1;
	tonine[mov42-1] = 1;
	tonine[mov50-1] = 1;
	tonine[mov51-1] = 1;
	tonine[mov52-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //5
	tonine[mov33-1] = 1;
	tonine[mov34-1] = 1;
	tonine[mov35-1] = 1;
	tonine[mov43-1] = 1;
	tonine[mov44-1] = 1;
	tonine[mov45-1] = 1;
	tonine[mov53-1] = 1;
	tonine[mov54-1] = 1;
	tonine[mov55-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //6
	tonine[mov36-1] = 1;
	tonine[mov37-1] = 1;
	tonine[mov38-1] = 1;
	tonine[mov46-1] = 1;
	tonine[mov47-1] = 1;
	tonine[mov48-1] = 1;
	tonine[mov56-1] = 1;
	tonine[mov57-1] = 1;
	tonine[mov58-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //7
	tonine[mov60-1] = 1;
	tonine[mov61-1] = 1;
	tonine[mov62-1] = 1;
	tonine[mov70-1] = 1;
	tonine[mov71-1] = 1;
	tonine[mov72-1] = 1;
	tonine[mov80-1] = 1;
	tonine[mov81-1] = 1;
	tonine[mov82-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //8
	tonine[mov63-1] = 1;
	tonine[mov64-1] = 1;
	tonine[mov65-1] = 1;
	tonine[mov73-1] = 1;
	tonine[mov74-1] = 1;
	tonine[mov75-1] = 1;
	tonine[mov83-1] = 1;
	tonine[mov84-1] = 1;
	tonine[mov85-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //9
	tonine[mov66-1] = 1;
	tonine[mov67-1] = 1;
	tonine[mov68-1] = 1;
	tonine[mov76-1] = 1;
	tonine[mov77-1] = 1;
	tonine[mov78-1] = 1;
	tonine[mov86-1] = 1;
	tonine[mov87-1] = 1;
	tonine[mov88-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;







// linhas
initTonine(tonine, 0); //1
	tonine[mov00-1] = 1; 
	tonine[mov01-1] = 1; 
	tonine[mov02-1] = 1; 
	tonine[mov03-1] = 1; 
	tonine[mov04-1] = 1; 
	tonine[mov05-1] = 1; 
	tonine[mov06-1] = 1; 
	tonine[mov07-1] = 1; 
	tonine[mov08-1] = 1; 
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //2
	tonine[mov10-1] = 1;
	tonine[mov11-1] = 1;
	tonine[mov12-1] = 1;
	tonine[mov13-1] = 1;
	tonine[mov14-1] = 1;
	tonine[mov15-1] = 1;
	tonine[mov16-1] = 1;
	tonine[mov17-1] = 1;
	tonine[mov18-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //3
	tonine[mov20-1] = 1;
	tonine[mov21-1] = 1;
	tonine[mov22-1] = 1;
	tonine[mov23-1] = 1;
	tonine[mov24-1] = 1;
	tonine[mov25-1] = 1;
	tonine[mov26-1] = 1;
	tonine[mov27-1] = 1;
	tonine[mov28-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //4
	tonine[mov30-1] = 1;
	tonine[mov31-1] = 1;
	tonine[mov32-1] = 1;
	tonine[mov33-1] = 1;
	tonine[mov34-1] = 1;
	tonine[mov35-1] = 1;
	tonine[mov36-1] = 1;
	tonine[mov37-1] = 1;
	tonine[mov38-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //5
	tonine[mov40-1] = 1;
	tonine[mov41-1] = 1;
	tonine[mov42-1] = 1;
	tonine[mov43-1] = 1;
	tonine[mov44-1] = 1;
	tonine[mov45-1] = 1;
	tonine[mov46-1] = 1;
	tonine[mov47-1] = 1;
	tonine[mov48-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //6
	tonine[mov50-1] = 1;
	tonine[mov51-1] = 1;
	tonine[mov52-1] = 1;
	tonine[mov53-1] = 1;
	tonine[mov54-1] = 1;
	tonine[mov55-1] = 1;
	tonine[mov56-1] = 1;
	tonine[mov57-1] = 1;
	tonine[mov58-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //7
	tonine[mov60-1] = 1;
	tonine[mov61-1] = 1;
	tonine[mov62-1] = 1;
	tonine[mov63-1] = 1;
	tonine[mov64-1] = 1;
	tonine[mov65-1] = 1;
	tonine[mov66-1] = 1;
	tonine[mov67-1] = 1;
	tonine[mov68-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //8
	tonine[mov70-1] = 1;
	tonine[mov71-1] = 1;
	tonine[mov72-1] = 1;
	tonine[mov73-1] = 1;
	tonine[mov74-1] = 1;
	tonine[mov75-1] = 1;
	tonine[mov76-1] = 1;
	tonine[mov77-1] = 1;
	tonine[mov78-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //9
	tonine[mov80-1] = 1;
	tonine[mov81-1] = 1;
	tonine[mov82-1] = 1;
	tonine[mov83-1] = 1;
	tonine[mov84-1] = 1;
	tonine[mov85-1] = 1;
	tonine[mov86-1] = 1;
	tonine[mov87-1] = 1;
	tonine[mov88-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;







initTonine(tonine, 0); //1
	tonine[mov00-1] = 1; //printf("vale %d\n", mov00);
	tonine[mov10-1] = 1; //printf("vale %d\n", mov01);
	tonine[mov20-1] = 1; //printf("vale %d\n", mov02);
	tonine[mov30-1] = 1; //printf("vale %d\n", mov10);
	tonine[mov40-1] = 1; //printf("vale %d\n", mov11);
	tonine[mov50-1] = 1; //printf("vale %d\n", mov12);
	tonine[mov60-1] = 1; //printf("vale %d\n", mov20);
	tonine[mov70-1] = 1; //printf("vale %d\n", mov21);
	tonine[mov80-1] = 1; //printf("vale %d\n", mov22);
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //2
	tonine[mov01-1] = 1;
	tonine[mov11-1] = 1;
	tonine[mov21-1] = 1;
	tonine[mov31-1] = 1;
	tonine[mov41-1] = 1;
	tonine[mov51-1] = 1;
	tonine[mov61-1] = 1;
	tonine[mov71-1] = 1;
	tonine[mov81-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //3
	tonine[mov02-1] = 1;
	tonine[mov12-1] = 1;
	tonine[mov22-1] = 1;
	tonine[mov32-1] = 1;
	tonine[mov42-1] = 1;
	tonine[mov52-1] = 1;
	tonine[mov62-1] = 1;
	tonine[mov72-1] = 1;
	tonine[mov82-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //4
	tonine[mov03-1] = 1;
	tonine[mov13-1] = 1;
	tonine[mov23-1] = 1;
	tonine[mov33-1] = 1;
	tonine[mov43-1] = 1;
	tonine[mov53-1] = 1;
	tonine[mov63-1] = 1;
	tonine[mov73-1] = 1;
	tonine[mov83-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //5
	tonine[mov04-1] = 1;
	tonine[mov14-1] = 1;
	tonine[mov24-1] = 1;
	tonine[mov34-1] = 1;
	tonine[mov44-1] = 1;
	tonine[mov54-1] = 1;
	tonine[mov64-1] = 1;
	tonine[mov74-1] = 1;
	tonine[mov84-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //6
	tonine[mov05-1] = 1;
	tonine[mov15-1] = 1;
	tonine[mov25-1] = 1;
	tonine[mov35-1] = 1;
	tonine[mov45-1] = 1;
	tonine[mov55-1] = 1;
	tonine[mov65-1] = 1;
	tonine[mov75-1] = 1;
	tonine[mov85-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //7
	tonine[mov06-1] = 1;
	tonine[mov16-1] = 1;
	tonine[mov26-1] = 1;
	tonine[mov36-1] = 1;
	tonine[mov46-1] = 1;
	tonine[mov56-1] = 1;
	tonine[mov66-1] = 1;
	tonine[mov76-1] = 1;
	tonine[mov86-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //8
	tonine[mov07-1] = 1;
	tonine[mov17-1] = 1;
	tonine[mov27-1] = 1;
	tonine[mov37-1] = 1;
	tonine[mov47-1] = 1;
	tonine[mov57-1] = 1;
	tonine[mov67-1] = 1;
	tonine[mov77-1] = 1;
	tonine[mov87-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;

	initTonine(tonine, 0); //9
	tonine[mov08-1] = 1;
	tonine[mov18-1] = 1;
	tonine[mov28-1] = 1;
	tonine[mov38-1] = 1;
	tonine[mov48-1] = 1;
	tonine[mov58-1] = 1;
	tonine[mov68-1] = 1;
	tonine[mov78-1] = 1;
	tonine[mov88-1] = 1;
	valid = checkTonine(tonine, 0);
	sumvalid = sumvalid + valid;




	if (sumvalid == 27) {
		printf("SIM\n\n");
	} else {
		printf("NAO\n\n");
	}





	// int m1, m2, m3, m4, m5, m6, m7, m8, m9;
	// m1 = mov00 + mov01 + mov02 + mov10 + mov11 + mov12 + mov20 + mov21 + mov22;
	// m2 = mov03 + mov04 + mov05 + mov13 + mov14 + mov15 + mov23 + mov24 + mov25;
	// m3 = mov06 + mov07 + mov08 + mov16 + mov17 + mov18 + mov26 + mov27 + mov28;

	// m4 = mov30 + mov31 + mov32 + mov40 + mov41 + mov42 + mov50 + mov51 + mov52;
	// m5 = mov33 + mov34 + mov35 + mov43 + mov44 + mov45 + mov53 + mov54 + mov55;
	// m6 = mov36 + mov37 + mov38 + mov46 + mov47 + mov48 + mov56 + mov57 + mov58;

	// m7 = mov60 + mov61 + mov62 + mov70 + mov71 + mov72 + mov80 + mov81 + mov82;
	// m8 = mov63 + mov64 + mov65 + mov73 + mov74 + mov75 + mov83 + mov84 + mov85;
	// m9 = mov66 + mov67 + mov68 + mov76 + mov77 + mov78 + mov86 + mov87 + mov88;



	// printf("Instancia %d\n", i + 1);

	// printf("%d %d %d %d %d %d %d %d %d \n", m1, m2, m3, m4, m5, m6, m7, m8, m9);

	// if (m1 == 45 && m1 == 45 && m1 == 45 && m1 == 45 && m1 == 45 && m1 == 45 && m1 == 45 && m1 == 45 && m1 == 45) {
	// 	printf("SIM\n\n");
	// } else {
	// 	printf("NAO\n\n");
	// }

	play(games, ++i);
}


int main() {
	int games;
	scanf("%d", &games);
	play(games, 0);



	return 0;
}