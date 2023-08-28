#include "ElfVillage.h"

int main()
{
	std::srand(std::time(NULL));
	
	std::vector<Tree> trees(5);
	std::string name;

	for (int i = 0; i < trees.size(); ++i)
	{
		std::cout << "Settlement of the " << i + 1 << " tree. " << std::endl;
		trees[i].populate_house();
	}
	
	for (int i = 0; i < trees.size(); ++i)
		trees[i].count_neighbors();

	return 0;
}
