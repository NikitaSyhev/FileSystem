//Шаблон

#include <iostream>
#include <string>
#include <fstream> // 



bool statistic(std::string word) {
	std::string path = "file.txt";
	std::ofstream out;
	out.open(path, std::ios::app);


	if (out.is_open()) {
		out << word + ' ' << word.length() << '\n';
		out.close();
		return true;
	}
	else
		out.close();
		return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
		int n;
		std::string path = "file.txt";  // путь к файлу



		//Запись с файла
			std::ofstream out;

			out.open(path, std::ios::app);

			if (out.is_open()) { //true если файл открыт успешно
				std::cout << "Файл открыт для записи.\n";
				std::string tmp;
				std::cout << "Введите строку: ";
				std::getline(std::cin, tmp);
				out << tmp + '\n'; // добавление записи в файл, где + - конкатинация строк
			}
			else
				std::cout << "Ошибка открытия файла.\n";

			out.close(); //закрытие файла
			
		
		//Чтение из файла
		std::ifstream in;
		in.open(path);

		if (in.is_open()) {
			std::cout << "Файл открыт для чтения.\nСодержимое файла:\n";
			//Первый способ - посимвольное счиитывание
			char sym;
			while (in.get(sym))
				std::cout << sym;

			//Второй способ - пословное считывание
			while (!in.eof()) {   // пока не дойдем до конца файла
				std::string tmp;
				in >> tmp;
				std::cout << tmp << ' ';
			}
			//Третий способ - построчный способ считывания
		std::string str;
		while (getline(in, str))
			std::cout << str << '\n';
		}
		else
			std::cout << "Ошибка открытия файла.\n";

		in.close();

		remove(path.c_str()); // применяется к объектам класса ыring, метод возвращающий сишный символьный массив



		//Удаление файла
		if (!remove(path.c_str()))
			std::cout << "Файл удален.\n";
		else
			std::cout << "Ошибка удаления файла.\n";





		std::cout << "Задача 1.\nВведите 1ое слово: \n";
		std::string str;
		std::cin >> str;
		if (statistic(str))
			std::cout << "Первое слово успешно записано.\n";
		else
			std::cout << "Ошибка записи.\n";
		std::cout << "Введите второе слово:\n";
		std::cin >> str;
		if (statistic(str))
			std::cout << "Второе слово успешно записано.\n\n";
		else
			std::cout << "Ошибка записи.\n\n";





	return 0;
}

