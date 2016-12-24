#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

bool compare(std::pair<int, char> const &a, std::pair<int, char> const &b)
{
	if(a.first != b.first)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main(int argv, char* argc[])
{
	std::string line;
	std::ifstream input_file;
	int sector_sum = 0;
	input_file.open(argc[1]);

	while(getline(input_file, line))
	{
		std::map<char, int> chars_in_line;

		for(auto &c : line.substr(0, line.length() - 10))
		{
			if(c != '-')
			{
				chars_in_line[c]++;
			}
		}

		std::vector<std::pair<int, char> > values;
		std::map<char, int>::iterator map_itr = chars_in_line.begin();

		while(map_itr != chars_in_line.end())
		{
			values.push_back(std::make_pair(map_itr->second, map_itr->first));
			++map_itr;
		}

		std::stable_sort(values.begin(), values.end(), compare);
		std::string most_frequent_letters;

		for(int i=1; i<6; ++i)
		{
			most_frequent_letters += values[values.size() - i].second;
		}

		if(most_frequent_letters.compare(line.substr(line.size() - 6, 5)) == 0)
		{
			sector_sum += std::atoi(line.substr(line.size() - 10, 3).c_str());
		}

	}

	std::cout << sector_sum << std::endl;

	input_file.close();
}