#include "ElfVillage.h"

// Конструктор по умолчанию, устанавливает рандомное количество больших и средних веток при создании объекта;
Tree::Tree()
{
	branches.resize(std::rand() % 3 + 3);
	for (int i = 0; i < branches.size(); ++i)
		{branches[i].resize((std::rand() % 2 + 2) + 1);}
}

// Приватный метод is_correct_name проверяет правильность ввода имени эльфа;

bool Tree::is_correct_name(const std::string& name)
{
	if (name[0] < 'A' || name[0] > 'Z') return false;
	for (int i = 1; i < name.length(); ++i)
		if (name[i] < 'a' || name[i] > 'z') return false;

	return true;
}

// Приватный метод find() ищет эльфа по имени;
int Tree::find(const std::string& name)
{
	for (int i = 0; i < branches.size(); ++i)
	{
		for (int j = 0; j < branches[i].size(); j++)
		{
			if (branches[i][j].elfName == name) return i;
		}
	}

	return -1;
}

// Метод populate_house() заселяет эльфов в дома; 
void Tree::populate_house()
{
	std::string elfName;
	for (int i = 0; i < branches.size(); ++i)
	{
		system("cls");
		for (int j = 0; j < branches[i].size(); ++j)
		{
			if (j == 0)
			{
				system("cls");
				std::cout << "The house on the big branch: " << i + 1 << std::endl;
				std::cout << "Enter the name of the inhabited elf: ";
				std::cin >> elfName;
			}
			else
			{
				std::cout << "House on the middle branch: " << j << " on a large branch: " << i + 1 << std::endl;
				std::cout << "Enter the name of the inhabited elf: ";
				std::cin >> elfName;
			}
			if (!is_correct_name(elfName))
			{
				std::cerr << "Error! Incorrect input name. Try again. " << std::endl;
				--j;
				continue;
			}

			branches[i][j].elfName = elfName;
		}
	}	
}

// Метод count_neighbors() считает количество соседей;
void Tree::count_neighbors()
{
	std::string name;

	std::cout << "Enter the name of the elf: ";
	std::cin >> name;

	int indexFoundElf = find(name);
	if (indexFoundElf == -1)
	{
		std::cerr << "Error! There is no elf with that name. " << std::endl;
		return;
	}
	int count = 0;

	for (int i = 0; i < branches[indexFoundElf].size(); ++i)
		if (branches[indexFoundElf][i].elfName != "None") ++count;

	// Сделал декремент у переменной count на случай одинаковых имён у искомого человека и его соседа;
	--count;

	std::cout << "Number of neighbors at " << name << ": " << count << std::endl;
}