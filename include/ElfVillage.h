#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>


class Tree
{
private:
	class Branch
	{
	public:
		std::string elfName = " ";
		const int HOUSE = 1;
	};
	std::vector<std::vector<Branch>> branches;

	// Эти методы объявлены приватными для недоступности из вне класса;
	bool is_correct_name(const std::string& name);
	int find(const std::string& name);

public:
	Tree();
	void count_neighbors();
	void populate_house();
};
