#include "str.h"

/*
Function: my_fgets
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Reads at most one less than the number of characters specified by n, into the array pointed to by s, 
			 from the input pointed to by stream. No more characters are read after a newline is encountered or end
			 of file is encountered. The newline if encountered is stored by the array pointed to by s. A null 
			 character is appended to the end of string s. If the function is successful in reading characters into s, 
			 then s is returned; otherwise a NULL pointer is returned.
Input Parameters: char *s, int n, FILE *stream
Returns: char *
*/

char *my_fgets(char *s, int n, FILE *stream) {

	int counter = 0;

	while (!feof(stream) && n > 1) {

		*s = getc(stream);
		s++;
		counter++;
		n--;
		if (*(s - 1) == '\n') {
			break;
		}

	}

	*s = '\0';
	s = s - counter;

	if (s != NULL) {
		return s;
	}
	else {
		return NULL;
	}

}

/*
Function: my_fputs
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Writes s to the output specified by stream. If the function is successful, then it returns the number 
			 of characters written to the output; otherwise it returns MY_EOF (i.e. for cases where stream does not
			 point any where yet). Make sure you #define MY_EOF as -1.
Input Parameters: const char *s, FILE *stream
Returns: int
*/

int my_fputs(const char *s, FILE *stream) {

	int counter = 0;

	while (*s != '\0') {

		putc(*s, stream);
		s++;
		counter++;

	}

	if (stream == NULL) {
		return MY_EOF;
	}
	else {
		return counter;
	}

}

/*
Function: my_fgetc
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Reads the next character from the input pointed to by stream. If the input is at the end of file or a 
			 processing error occurs return MY_EOF; otherwise return the integer representation of the character read.
Input Parameters: FILE *stream
Returns: int
*/

int my_fgetc(FILE *stream) {

	int character = getc(stream);
	
	return character;

}

/*
Function: my_fputc
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Writes the character c (converted to a character) to the output specified by stream. If the write is 
			 successful the ascii value of the character is returned; otherwise MY_EOF is returned.
Input Parameters: int c, FILE *stream
Returns: int
*/

int my_fputc(int c, FILE *stream) {

	putc(c, stream);
	stream++;

	return c;

}

/*
Function: my_gets
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Reads characters from stdin into the array pointed to by s until a newline is encountered. The newline
			 character is NOT kept at the end of the array pointed to by s. A null character is written to the end 
			 of string s. The function returns s.
Input Parameters: char *s
Returns: char *
*/

char *my_gets(char *s) {

	int counter = 0;

		while (counter > -1) {

			*s = getc(stdin);
			if (*s == '\n') {

				*s = '\0';
				break;

			}
			counter++;
			s++;

		}

		s = s - counter;

		return s;

}

/*
Function: my_puts
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Writes the string pointed to by s to stdout. The function appends a newline to the output. 
			 The function returns the number of characters written to the output.
Input Parameters: const char *s
Returns: int
*/

int my_puts(const char *s) {

	int counter = 0;

	while (*s != '\0') {

		putc(*s, stdout);
		s++;
		counter++;

	}

	putc('\n', stdout);

	return counter;

}

/*
Function: my_getchar
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Returns the ascii value of the next character read from stdin.
Input Parameters: none
Returns: int
*/

int my_getchar(void) {

	int ascii = 0;
	ascii = getc(stdin);

	return ascii;

}

/*
Function: my_putchar
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: The function writes character c to stdout. The character c is returned.
Input Parameters: int c
Returns: int
*/

int my_putchar(int c) {

	putc(c, stdout);

	return c;

}

/*
Function: my_strcpy
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Copies all characters in the array pointed to by source into the array pointed to by destination. 
			 The null character is also copied. The function returns destination.
Input Parameters: char *destination, const char *source
Returns: char *
*/

char *my_strcpy(char *destination, const char *source) {

	int counter = 0;

	while (*source != NULL) {

		*destination = *source;
		source++;
		destination++;
		counter++;

	}

	while (*destination != NULL) {

		*destination = '\0';
		destination++;
		counter++;

	}

	destination -= counter;

	return destination;

}

/*
Function: my_strncpy
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: Copies no more than n characters from the string pointed to by source into the array pointed to by destination.
			 The function does not copy any characters past a null character. If the string pointed to by source is less 
			 than n characters, null characters are appended to the end of the array pointed to by destination until n 
			 characters have been written.
Input Parameters: char *destination, const char *source, int n
Returns: char *
*/

char *my_strncpy(char *destination, const char *source, int n) {

	int counter = 0;

	while (*source != NULL && n > 0) {

		*destination = *source;
		source++;
		destination++;
		counter++;
		n--;

	}

	if (n > 0) {

		while (n > 0 && *destination != NULL && *source != NULL) {
			*destination = '\0';
			destination++;
			counter++;
			n--;
		}

	}

	if (*destination != NULL) {

		while (*destination != NULL) {

			*destination = '\0';
			destination++;
			counter++;

		}

	}

	destination -= counter;

	return destination;

}

/*
Function: my_strcat
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: This function appends a copy of the string pointed to by source (including the null character) to the end of 
			 the string pointed to by destination. The append overwrites the null character at the end of destination. The
			 string pointed to by destination is returned.
Input Parameters: char *destination, const char *source
Returns: char *
*/

char *my_strcat(char *destination, const char *source) {

	int counter = 0;

	while (*destination != '\0') {

		destination++;
		counter++;

	}

	while (*source != NULL) {

		*destination = *source;
		destination++;
		source++;
		counter++;

	}

	destination -= counter;

	return destination;

}

/*
Function: my_strncat
Date Created: 4/23/2018
Date Last Modified: 4/23/2018
Description: This function appends no more than n characters from the string pointed to by source to the end of the array 
			 pointed to by destination. The null character is appended to the end of the result. The destination pointer 
			 is returned.
Input Parameters: char *destination, const char *source, int n
Returns: char *
*/

char *my_strncat(char *destination, const char *source, int n) {

	int counter = 0;

	while (*destination != '\0') {

		destination++;
		counter++;

	}

	while (*source != NULL && n > 0) {

		*destination = *source;
		destination++;
		source++;
		n--;
		counter++;

	}

	destination -= counter;

	return destination;

}

/*
Function: my_strcmp
Date Created: 4/23/2018
Date Last Modified: 4/27/2018
Description: This function compares the string pointed to by s1 to the string pointed to by s2. If the string pointed to by
			 s1 comes before the string pointed to by s2 in dictionary ordering, then -1 is returned. If the string pointed
			 to by s1 is the same as the string pointed to by s2, then 0 is returned (the compare function is case sensitive). Otherwise 1 is returned.
Input Parameters: const char *s1, const char *s2
Returns: int
*/

int my_strcmp(const char *s1, const char *s2) {

	while (*s1 == *s2 && *s1 && *s2) {

		s1++;
		s2++;

	}

	if (*s1 < *s2) {

		return -1;

	}
	else if (*s1 == *s2) {

		return 0;

	}
	else {

		return 1;

	}

}

/*
Function: my_strncmp
Date Created: 4/23/2018
Date Last Modified: 4/27/2018
Description: This function compares no more than n characters (characters following a null character are not compared) from
			 the string pointed to by s1 to the string pointed to by s2. If the string pointed to by s1 comes before the 
			 string pointed to by s2 in dictionary ordering, then -1 is returned. If the string pointed to by s1 is the 
			 same as the string pointed to by s2, then 0 is returned (the compare function is case sensitive). Otherwise 1 
			 is returned.
Input Parameters: const char *s1, const char *s2, int n
Returns: int
*/

int my_strncmp(const char *s1, const char *s2, int n) {

	while (*s1 == *s2 && *s1 && *s2 && n > 0) {

		if (*s1 == '\0' || *s2 == '\0') {
			break;
		}

		s1++;
		s2++;
		n--;

	}

	if (*s1 < *s2) {

		return -1;

	}
	else if (*s1 == *s2) {

		return 0;

	}
	else {

		return 1;

	}

}

/*
Function: my_strlen
Date Created: 4/23/2018
Date Last Modified: 4/27/2018
Description: This function returns the length of the string pointed to by s. The computation of length does NOT include 
			 the null character.
Input Parameters: const char *s
Returns: int
*/

int my_strlen(const char *s) {

	int length = 0;

	while (*s != '\0') {

		length++;
		s++;

	}

	return length;

}