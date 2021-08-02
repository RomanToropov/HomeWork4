#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define Escape 27
#define tab "\t"
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

void main()
{
	const int n = 10;
	const int n1 = 30;
	char nomer_programmu;
	char sdvig_v_storony;
	char sdvig;
	int sdvig_na_hislo;
	int buffer;
	unsigned long int chislo;
	int promejutochnuy_variant = 0;
	int bin = 0;
	int hex = 0;

	do
	{
		setlocale(LC_ALL, "Rus");
		int null = 0;
		int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
		int arr1[n] = { 1,2,3,4,5,6,7,8,9,10 };
		int arr2[n1] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		unsigned char arr3[n1] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		int razryad = 0;
		int razryad2 = 0;
		int chislo2 = 0;
		int table = 0;
		int a = 0;
		cout << "������� ����� ���������" << endl << "1 - �����(��� ������ ����� ����)" << endl << "2 - �����(��� ������ �������)" << endl << "3 - ������� ����� � 2 �������" << endl << "4 - ������� ����� 16 �������)" << endl << "Escape - ��� ������" << endl << "������� ����� ��������� : "; nomer_programmu = _getch();
		if (nomer_programmu != 27)
		{
			cout << nomer_programmu << endl << endl;
		}
		else
		{
			cout << "Escape" << endl;
		}
		switch (nomer_programmu)
		{
		case '1':
			cout << "������� ������� �������� (1 - �����, 2 - ������): "; sdvig_v_storony = _getch(); cout << sdvig_v_storony << endl;
			if (sdvig_v_storony == '1' || sdvig_v_storony == '2')
			{
				cout << "������� �� ������� ��������� �����: "; cin >> sdvig_na_hislo;
				cout << "������ �� ������:    ";
				for (int i = 0; i < n; i++)
				{
					cout << arr1[i] << "       ";
				}
				cout << endl;
				cout << "������ ����� ������: ";
			}
			switch (sdvig_v_storony)
			{
			case '1':
				for (int i = 0; i < sdvig_na_hislo; i++)
				{
					buffer = arr1[0];
					for (int i = 0; i < n - 1; i++)
					{
						arr1[i] = arr1[i + 1];
					}
					arr1[n - 1] = buffer;
				}
				for (int i = 0; i < n; i++)
				{
					cout << arr1[i] << "       ";
				}
				cout << endl << endl;
				break;
			case '2':
				for (int i = 0; i < sdvig_na_hislo; i++)
				{
					buffer = arr1[n - 1];
					for (int i = 8; i >= 0; i--)
					{
						arr1[i + 1] = arr1[i];
					}
					arr1[0] = buffer;
				}
				for (int i = 0; i < n; i++)
				{
					cout << arr1[i] << "       ";
				}
				cout << endl << endl;
				break;
			default:
				if (sdvig_v_storony != '1' && sdvig_v_storony != '2')
				{
					cout << "��� ����� ���������" << endl;
				}
				break;
			}
			break;
		case '2':
			cout << "������� ������� �����, ������� ������ ��� Escape - ��� ������"; cout << endl;
			do
			{
				sdvig = _getch();
				switch (sdvig)
				{
				case LEFT_ARROW:
					buffer = arr[0];
					for (int i = 0; i < n - 1; i++)
					{
						arr[i] = arr[i + 1];
					}
					arr[n - 1] = buffer;
					for (int i = 0; i < n; i++)
					{
						cout << arr[i] << "       ";
					}
					cout << " " << "\r";
					break;
				case RIGHT_ARROW:
					buffer = arr[n - 1];
					for (int i = 8; i >= 0; i--)
					{
						arr[i + 1] = arr[i];
					}
					arr[0] = buffer;
					for (int i = 0; i < n; i++)
					{
						cout << arr[i] << "       ";
					}
					cout << " " << "\r";
					break;
				case Escape:
					for (int i = 0; i < n; i++)
					{
						cout << arr[i] << "       ";
					}
					cout << endl << "�����" << endl;
					break;
				default:
					if (sdvig != LEFT_ARROW && sdvig != RIGHT_ARROW && sdvig != Escape && sdvig != -32)
					{
						cout << endl << "��� ����� ���������" << "\t\r";
					}
					break;
				}
			} while (sdvig != Escape);
			break;
		case '3':
			cout << "������� ����� ��� �������������� � �������� ���: "; cin >> chislo;
			cout << "����� " << chislo << " � �������� ������� ����� ";
			while (chislo != 1)
			{
				arr2[a] = chislo % 2;
				chislo /= 2;
				a++;
				razryad++;
			}
			arr2[a] = chislo;
			razryad++;
			for (int j = 0; j < razryad / 2; j++)
			{
				table = arr2[j];
				arr2[j] = arr2[razryad - (j + 1)];
				arr2[razryad - (j + 1)] = table;
			}
			razryad2 = razryad;
			while (razryad2 % 4 != 0)
			{
				for (int i = razryad; i >= 0; i--)
				{
					arr2[i + 1] = arr2[i];
				}
				arr2[0] = 0;
				razryad2++;
				razryad++;
			}
			for (int j = 0; j < razryad; j++)
			{
				if (j > 0 && (j % 4) == 0)
				{
					cout << "     ";
				}
				cout << arr2[j];
			}
			cout << endl << endl;
			break;
		case '4':
			cout << "������� ����� ��� �������������� � ����������������� ���: "; cin >> chislo;
			cout << "����� " << chislo << " � ����������������� ������� ����� ";
			while (chislo > 15)
			{
				if (chislo % 16 < 10)
				{
					arr3[a] = chislo % 16 + '0';
					chislo /= 16;
					a++;
					razryad++;
				}
				else
				{
					if (chislo % 16 == 15)
					{
						arr3[a] = 'F';
						chislo /= 16;
						a++;
						razryad++;
					}
					else if (chislo % 16 == 14)
					{
						arr3[a] = 'E';
						chislo /= 16;
						a++;
						razryad++;
					}
					else if (chislo % 16 == 13)
					{
						arr3[a] = 'D';
						chislo /= 16;
						a++;
						razryad++;
					}
					else if (chislo % 16 == 12)
					{
						arr3[a] = 'C';
						chislo /= 16;
						a++;
						razryad++;
					}
					else if (chislo % 16 == 11)
					{
						arr3[a] = 'B';
						chislo /= 16;
						a++;
						razryad++;
					}
					else if (chislo % 16 == 10)
					{
						arr3[a] = 'A';
						chislo /= 16;
						a++;
						razryad++;
					}
				}
			}
			if (chislo < 16)
			{
				if (chislo % 16 < 10)
				{
					arr3[a] = chislo + '0';
					a++;
					razryad++;
				}
				else
				{
					if (chislo % 16 == 15)
					{
						arr3[a] = 'F';
						a++;
						razryad++;
					}
					else if (chislo % 16 == 14)
					{
						arr3[a] = 'E';
						a++;
						razryad++;
					}
					else if (chislo % 16 == 13)
					{
						arr3[a] = 'D';
						a++;
						razryad++;
					}
					else if (chislo % 16 == 12)
					{
						arr3[a] = 'C';
						a++;
						razryad++;
					}
					else if (chislo % 16 == 11)
					{
						arr3[a] = 'B';
						a++;
						razryad++;
					}
					else if (chislo % 16 == 10)
					{
						arr3[a] = 'A';
						a++;
						razryad++;
					}
				}
			}
			for (int j = 0; j < razryad / 2; j++)
			{
				table = arr3[j];
				arr3[j] = arr3[razryad - (j + 1)];
				arr3[razryad - (j + 1)] = table;
			}
			for (int j = 0; j < razryad; j++)
			{
				if (j > 0 && (j % 4) == 0)
				{
					cout << "     ";
				}
				cout << arr3[j];
			}
			cout << endl << endl;
			break;
		case Escape:
			cout << "�����" << endl;
			break;
		default:
			if (nomer_programmu != '1' && nomer_programmu != '2' && nomer_programmu != '3' && nomer_programmu != '4' && nomer_programmu != Escape)
			{
				cout << "��� ����� ���������" << endl << endl;
			}
			break;
		}
	} while (nomer_programmu != Escape);
}