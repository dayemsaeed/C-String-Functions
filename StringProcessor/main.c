#include "str.h"

int main() {
	char my_string[50] = { '\0' };
	char arr[20] = { '\0' };
	char str_copy[30] = { "This is a test" }, strn_copy[30] = "String prototype";

	FILE *infile = NULL;
	infile = fopen("test.txt", "r");

	FILE *outfile = NULL;
	outfile = fopen("out.txt", "w");

	if (infile != NULL) {

		printf_s("Testing FGet S to write from file 'test.txt' to my_string array\n");
		system("pause");
		system("cls");
		my_fgets(my_string, 15, infile);

		printf_s("%s", my_string);
		system("pause");
		system("cls");

	}
	else {

		printf_s("Failed to open file for reading\n");
		system("pause");
		system("cls");

	}

	if (outfile != NULL) {

		printf_s("Testing FPut S to write from my_string array to file 'out.txt'\n");
		system("pause");
		system("cls");
		my_fputs(my_string, outfile);
		system("pause");
		system("cls");

	}
	else {

		printf_s("Failed to open file for writing\n");
		system("pause");
		system("cls");

	}

	printf_s("Testing FGet C Function (getting from 'test.txt'\n");
	system("pause");
	system("cls");
	int c = my_fgetc(infile);
	printf_s("%d\n", c);
	system("pause");
	system("cls");

	printf_s("Testing FPut C Function (writing to 'out.txt'\n");
	system("pause");
	system("cls");
	int a = my_fputc(c, outfile);
	printf_s("%d\n", a);
	system("pause");
	system("cls");

	printf_s("Testing Get S Function\n");
	system("pause");
	system("cls");
	my_gets(arr);
	printf_s("array: %s\n", arr);
	system("pause");
	system("cls");

	printf_s("Testing Put S function\n");
	system("pause");
	system("cls");
	printf_s("Writing string pointed to by the previous array (which stored the input from stdin)\n");
	int character = my_puts(arr);
	system("pause");
	system("cls");

	printf_s("Testing Get Char Function\n");
	system("pause");
	system("cls");
	int ascii = my_getchar();
	printf_s("Character Ascii Value from my_getchar: %d\n", ascii);
	system("pause");
	system("cls");

	printf_s("Testing Put Char Function (Ascii Value 84, letter T)\n");
	system("pause");
	system("cls");
	printf_s("Writing character with ascii value 84 ('T') to stdout)\n");
	int f = my_putchar(84);
	printf_s("\n");
	system("pause");
	system("cls");

	printf_s("Testing String Copy Function\n");
	system("pause");
	system("cls");
	printf_s("Original str_copy string: %s\n", str_copy);
	my_strcpy(my_string, arr);
	printf_s("New str_copy string with value from arr array: %s\n", str_copy);
	system("pause");
	system("cls");

	printf_s("Testing String N Copy Function\n");
	system("pause");
	system("cls");
	printf_s("Original strn_copy string: %s\n", strn_copy);
	my_strncpy(my_string, arr, 5);
	printf_s("New strn_copy with 5 characters concatenated from arr array: %s\n", strn_copy);
	my_strncpy(my_string, arr, 15);
	printf_s("New strn_copy string with 15 characters concatenated from arr array (exceeding the limit of the src): %s\n", strn_copy);
	system("pause");
	system("cls");

	printf_s("Testing String Concatenation Function\n");
	system("pause");
	system("cls");
	printf_s("Original my_string: %s\n", my_string);
	my_strcat(my_string, str_copy);
	printf_s("New my_string concatenated with str_copy string: %s\n", my_string);
	system("pause");
	system("cls");

	printf_s("Testing String N Concatenation Function\n");
	system("pause");
	system("cls");
	printf_s("Original arr string: %s\n", my_string);
	my_strncat(arr, strn_copy, 4);
	printf_s("New arr string with 4 characters copied from strn_copy string: %s\n", my_string);
	system("pause");
	system("cls");

	printf_s("Testing String Compare Function\n");
	system("pause");
	system("cls");
	printf_s("Comparing 'hello' and 'hEllo' respectively as *s1 and *s2:\n");
	int b = my_strcmp("hello", "hEllo");
	printf_s("%d\n", b);
	system("pause");
	system("cls");

	printf_s("Testing String N Compare Function\n");
	system("pause");
	system("cls");
	printf_s("Comparing first 3 characters of 'hello' and 'hfil' as *s1 and *s2 respectively:\n");
	int k = my_strncmp("hello", "hfil", 3);
	printf_s("%d\n", k);
	system("pause");
	system("cls");

	printf_s("Testing String Length Function\n");
	system("pause");
	system("cls");
	int strlength = my_strlen("Testing string 1");
	printf_s("String length of 'Testing string 1': %d\n", strlength);

	system("pause");

	return 0;
}