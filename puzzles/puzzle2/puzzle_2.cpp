#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() 
{
	std::string line;
	std::vector<std::string> input_lines;

	std::ifstream input_file;
	input_file.open("input.txt");

	while(getline(input_file, line))
	{
		input_lines.push_back(line);
	}

	int lock_pad [3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int start_x = 1;
	int start_y = 1;

	std::vector<int> combination;

	for(int i=0; i<input_lines.size(); ++i)
	{
		for(int j=0; j<input_lines[i].size(); ++j) {
			std::string command = input_lines[i].substr(j, 1);

			if(command.compare("U") == 0)
			{
				--start_y;
			}
			else if(command.compare("D") == 0)
			{
				++start_y;
			}
			else if(command.compare("L") == 0)
			{
				--start_x;
			}
			else if(command.compare("R") == 0)
			{
				++start_x;
			}

			if(start_y < 0)
			{
				start_y = 0;
			}
			if(start_y > 2)
			{
				start_y = 2;
			}

			if(start_x < 0)
			{
				start_x = 0;
			}
			if(start_x > 2)
			{
				start_x = 2;
			}
		}

		combination.push_back(lock_pad[start_y][start_x]);
	}

	for(int i=0; i<combination.size(); ++i)
	{
		std::cout << combination[i] << "\n";
	}
}