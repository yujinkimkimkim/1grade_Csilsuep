#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned char a1;
	char input[10];

	scanf_s("%s", input, sizeof(input));

	for (int i = 0; i < strlen(input); i += 2)
	{
		a1 = input[i];
		printf("%x", a1);
		a1 = input[i+1];
		printf("%x", a1);
		printf("\n");
	}
}