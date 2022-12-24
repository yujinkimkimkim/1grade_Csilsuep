/*선행처리기 뭐 상수 뭐시기 그대로 치환된다고 강조만 백번 하심
매크로 함수 사용 형식
#define swap(a) (a)*(a)*(a) //10*10*10 
*/

#include <stdio.h>

int main(void)
{
	unsigned char b1 = 0xb0;
	unsigned char b2;
	for (b2 = 0xa1; b2 <= 0xfe; b2++)
	{
		printf("%c%c%2x%2x", b1, b2, b1, b2);
		if (b2 % 10 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}