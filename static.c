

#include <stdio.h>
#include <unistd.h>

int	increaseNum(void)
{
	static int	num;
	num += 1;

	return (num);
}

int main()
{

	printf("num : %d\n", increaseNum());
	increaseNum();
	printf("num : %d\n", increaseNum());
	printf("num : %d\n", increaseNum());
	printf("num : %d\n", increaseNum());

}
