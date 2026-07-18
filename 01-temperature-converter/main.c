/*
 * main.c
 *
 *  Created on: Jul 13, 2026
 *      Author: shade-akinremi
 *
 *      This programme converts temperature values input in by the user to either Celcius or Fahrenheit as decided by the user.
 *      The conversion is done by a function, Covert, and the number of times the user carries out a conversion in that session is also counted.
 *
 *
 *While coding this project, I understood:
 *Buffering, which I solved using fflush(stdout);
 *Static storage class, static*
 *Function
 *do{}while();
 *how to navigate using printf() and return, when I want a function to give two outputs.
 */

#include <stdio.h>
int Convert(char A, int B);

int main()

{
	char letter, again;

	int temp;

	do {
		printf("Would you like to convert a temperature to Fahrenheit or Celsius? Enter F if you want to convert to Fahrenheit or C if you want to convert to Celsius: ");
		fflush(stdout);
		scanf(" %c", &letter);
		if (letter == 'C'|| letter == 'c')
		{
			printf("Please enter the temperature value you want to convert to Celcius: ");
			fflush(stdout);
			scanf("%d", &temp);
			printf(".Temperature conversion was carried out %d time(s) in this programme.\n",Convert(letter, temp));
		}
		else if (letter == 'F' || letter == 'f')
		{
			printf("Please enter the temperature value you want to convert to Fahrenheit: ");
			fflush(stdout);
			scanf("%d", &temp);
			printf(". Temperature conversion was carried out %d time(s) in this programme.\n",Convert(letter, temp));
		}
		printf("Would you like to carry out another conversion? Enter 'Y' or 'N': ");
		fflush(stdout);
		scanf(" %c", &again);
	} while (again == 'Y'|| again == 'y');

	return 0;
}

int Convert(char A, int B)

{
	static int count = 0;

	count += 1;

	float calc;

	if (A == 'C' || A == 'c')
	{
		calc = ((B - 32) * 5) / (float) 9;
		fflush(stdout);
		printf("%d°F was converted to %.1f°C", B, calc);

	}
	else if (A == 'F' || A == 'f')
	{
		calc = ((B * 9) / (float) 5) + 32;
		fflush(stdout);
		printf("%d°C was converted to %.1f°F", B, calc);
	}

	return count;
}

