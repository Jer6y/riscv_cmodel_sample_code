
#include <printf.h>

char stack[4096];

int c = 2314;
int* b = &c;

int main(void)
{
	riscv_printf("===================================================\n");
	int* p = &c;
	riscv_printf("value of c         : %d\n",c);
	riscv_printf("addrs of c (use b) : %p\n",b);
	riscv_printf("addrs of c (use p) : %p\n",p);
	riscv_printf("===================================================\n");
	return 0;
}

