#include <stdio.h>
#include <locale.h>

int main()
{
	
	setlocale(LC_ALL, "RUS");
	sum(2, 5);
	razn(5, 2);
	ymn(-5, -2);
	del(10, -5);
	del_oct(20, 7);
	crav(1, 5);
	crav_3(4, 2, 4);
	swap(5, 1);
}

int sum(int a, int b)
{
	int otv;
	__asm
	{
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov otv, eax
	}
	printf("Сумма: %d\n", otv);
}

int razn(int a, int b)
{
	int otv;
	__asm
	{
		mov eax, a
		mov ebx, b
		sub eax, ebx
		mov otv, eax
	}
	printf("Разность: %d\n", otv);
}

int ymn(int a, int b)
{
	int otv;
	__asm
	{
		mov eax, a
		mov ebx, b
		imul ebx 
		mov otv, eax
	}
	printf("Умножение: %d\n", otv);
}

int del(int a, int b)
{
	int otv;
	__asm
	{
		mov eax, a
		mov ebx, b
		mov edx, 0
		idiv ebx 
		mov otv, eax
	}
	printf("Деление: %d\n", otv);
}

int del_oct(int a, int b)
{
	int otv;
	__asm
	{
		mov eax, a
		mov ecx, b
		mov edx, 0
		div ecx
		mov otv, edx //остаток от деления

	}
	printf("Остаток от деления: %d\n", otv);
}

int crav(int a, int b)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		cmp eax, ebx

		je equal
		jg greater
		jmp less

		equal :
		mov a, 0
			jmp exit

			greater :
		mov a, 1
			jmp exit

			less :
		mov a, 2
			jmp exit

			exit :
	}
	printf("Сравнение 2 чисел: %d\n", a);
}

int crav_3(int a, int b, int c)
{
	_asm
	{
		mov eax, a
		mov ebx, b
		mov ecx, c
		cmp eax, ebx
		je equal
		jg greater
		jmp less


		equal :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			greater :
		cmp eax, ecx
			je equal2
			jg greater2
			jmp less2

			less :
		cmp ebx, ecx
			je equal2
			jg greater3
			jmp less2

			equal2:

		mov a, 0
			jmp exit

			greater2 :
		mov a, 1
			jmp exit

			less2 :
		mov a, 3
			jmp exit

			greater3 :
		mov a, 2
			jmp exit

			exit :
	}
	printf("Сравнение 3 чисел : %d\n", a);
}

 /*int* Swap(int* massiv, int m, int mm)
{
	int a = massiv[m], b = massiv[mm];
	_asm
	{
		mov eax, a
		mov ebx, b
		mov ecx, eax
		mov ebx, eax
		mov ebx, ecx
		mov a, eax
		mov b, ebx
	}
	massiv[m] = a;
	massiv[mm] = b;
	return massiv;
} */


int swap(int a, int b)
{
	int c;
	__asm
	{
		mov eax, a
		mov ebx, b

		mov ecx, eax
		mov eax, ebx
		mov ebx, ecx

		mov a, eax
		mov b, ebx

	}
	printf("Замена : %d\n", a,b);

}