// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

char inpt()
{
	char letter;
	printf("Введити БУКВУ. \n");
	//scanf_s("%c", &letter);
	letter = _getch();
	if ((letter >= 'а' && letter <= 'я') || (letter >= 'a' && letter <= 'z')) //Проверка на мальникие буквы русского и английского алфавитов 
	{
		return letter;
	}
	else if (letter >= 'А' && letter <= 'Я')//Проверка на Большие буквы русского алфавита
	{
		letter += ('а' - 'А');
		return letter;
	}
	else if (letter >= 'A' && letter <= 'Z')//Проверка на Большие буквы английского алфавита
	{
		letter += ('a' - 'A');
		return letter;
	}
	else
	{

		return inpt();
	}

}

char* findWords(char* stringChek, char letter, char str1[])
{
	char str[512];
	char wrd[32];
	int  size = 0;
	int beg = 0, en = 0;
	memset(str, 0, sizeof str);
	memset(wrd, 0, sizeof wrd);
	for (int i = 0; stringChek[i - 1] != '\0'; i++)
	{
		//if ((stringChek[i] == ' ') || (stringChek[i] == '"') || (stringChek[i] == ':') || (stringChek[i] == ';') || (stringChek[i] == '\0') || (stringChek[i] == ',') || (stringChek[i] == '.'))
		if ((stringChek[i] < 'а' || stringChek[i] > 'я') && (stringChek[i] < 'a' || stringChek[i] > 'z') && (stringChek[i] < 'А' || stringChek[i] > 'Я') && (stringChek[i] < 'A' || stringChek[i] > 'Z') && (stringChek[i] != '-'))
		{
			if (stringChek[i - 1] == letter)
			{
				int k = i;
				for (int j = 0; j < size; j++)
				{

					wrd[j] = stringChek[k - size];
					k++;
				}
				strcat_s(str, wrd);
				strcat_s(str, " ");
				printf(" \n");
			}
			beg = i + 1;
			memset(wrd, 0, sizeof wrd);
			size = 0;
		}
		else
		{
			if (stringChek[i] >= 'А' && stringChek[i] <= 'Я')
			{
				stringChek[i] += ('а' - 'А');
			}
			else if (stringChek[i] >= 'A' && stringChek[i] <= 'Z')
			{
				stringChek[i] += ('a' - 'A');
			}
			size++;
			en = i;
		}
	}
	for (int i = 0; str[i - 1] != '\0'; i++)
	{
		str1[i] = str[i];
	}

	printf("%s \n", str1);
	return str1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char letter;
	char string[1000];
	char string2[100];
	printf("Введите строку для поиска слов. \n");
	gets_s(string);
	printf("Введите букву, на которую должно оканчиваться слово. \n");
	letter = inpt();
	char* result = findWords(string, letter, string2);
	printf("%s", result);
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
