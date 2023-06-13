#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>//для sqrt (square root - корень квадратный)

//Встраиваемая функция. Выполняется быстрее и не занимает место в памяти.
inline double absolute(double num) {
	//Если тело ф-ции не может быть встроено в то место кода где она вызывается
	//то компилятор превращает ее в обычную функцию.
	return (num < 0.0 ? -num : num);
}

//Перегруженная функция
int max(int num1, int num2) {
	std::cout << "TWO INT\n";
	return num1 > num2 ? num1 : num2;
}//если принимает два целых числа
double max(double num1, double num2) {
	std::cout << "TWO DOUBLE\n";
	return num1 > num2 ? num1 : num2;
}//если принимает два вещественных числа
char max(char num1, char num2) {
	std::cout << "TWO CHAR\n";
	return num1 > num2 ? num1 : num2;
}//если принимает два символа числа
int max(int num1, int num2, int num3) {
	std::cout << "THREE INT\n";
	int max = num1 > num2 ? num1 : num2;
	return num3 > max ? num3 : max;
}//если принимает три целых числа


//Шаблонная функция, работающая с любыми типами данных
template<typename T>
double mean(T num1, T num2) {
	return(num1 + num2) / 2.0;
}



//Шаблонная функция, выводящая массив любого типа в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }" << std::endl;
}

//задача4.
void decide(double a, double b) {
	std::cout<<"x = " <<(-b) / a<<std::endl;
}
void decide(double a, double b, double c) {
	double D = b * b - 4 * a * c;
	if (D > 0) {
		std::cout << "x1 = " << (-b - sqrt(D)) / (2.0 * a) << std::endl;
		std::cout << "x2 = " << (-b + sqrt(D)) / (2.0 * a) << std::endl;
		return;
	}
	if (D == 0) {
		std::cout << "x = " << (-b) / (2 * a);
		return;
	}
	std::cout << "Корней нет.\n";
}



int main() {
	system("chcp 1251>nul");
	int n, m;

	//встраивание функции
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << '|' << n << "| = " << absolute(n) << std::endl;

	//Перегрузка функции
	/*std::cout << max(15, 12) << std::endl;//15
	std::cout << max(7.2, 7.3) << std::endl;//7.3
	std::cout << max('a', 'A') << std::endl;//a
	std::cout << max(444, 777, 14) << std::endl;//777*/

	//Шаблонная функция
	std::cout << mean(5, 6) << std::endl;//5.5
	std::cout << mean(4.3, 4.4) << std::endl;//4.35


	int int_arr[3]{ 4,6,14 };
	double dbl_arr[4]{ 3.2, 4.4, 6.2, 9.2 };
	print_arr(int_arr, 3);
	print_arr(dbl_arr, 4);

	//Задача 4. Решения уравнений
	std::cout << "Задача 4.\n\nЛинейное уравнение:\n";
	int a, b, c;
	std::cout << "Введите два коэфициента -> ";
	std::cin >> a >> b;
	std::cout << a << "x + " << b << " = 0\n";
	decide(a, b);

	std::cout << "\nКвадратное уравнение:\n";
	std::cout << "Введите три коэфициента -> ";
	std::cin >> a >> b >> c;
	std::cout << a << "x^2 + " << b << "x + " << c << " = 0\n";
	decide(a, b, c);



	return 0;
}