#include <stdio.h>
#include <time.h>  


int msleep(long miliseconds) {
   struct timespec rem;
   struct timespec req= {
       (int)(miliseconds / 1000),     /* secs (Must be Non-Negative) */ 
       (miliseconds % 1000) * 1000000 /* nano (Must be in range of 0 to 999999999) */ 
   };
   return nanosleep(&req , &rem);
}

static const char *alpha[] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
};

static const char *num[] = {
    "-----", //0
    ".----", //1
    "..---", //2
    "...--", //3
    "....-", //4
    ".....", //5
    "-....", //6
    "--...", //7
    "---..", //8
    "----.", //9
};

const char* encode(char c) {
	if (c > ('A' - 1) && c < ('Z' + 1)) {
		return alpha[c - 'A'];
	}
	if (c > ('a' - 1) && c < ('z' + 1)) {
		return alpha[c - 'a'];
	}
	return "";
}

void output(char* c) {
	for (char* ptr = c; *ptr; ptr++) {
		if (*ptr == '-') {
			printf("255\n");
			fflush(stdout);
			msleep(500);
			printf("0\n");
			fflush(stdout);
		}
		if (*ptr == '.') {
			printf("255\n");
			fflush(stdout);
			msleep(200);
			printf("0\n");
			fflush(stdout);
		}
		msleep(200);
	}
	msleep(900);
}

int main(void) {
	while (1) {
		char c = getc(stdin);
		if (c == ' ') {
			msleep(1000);
		}
		output(encode(c));
	}
}
