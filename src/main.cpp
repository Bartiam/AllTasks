#include <iostream>
#include <vector>
#include <unordered_set>
#include <filesystem>

int main()
{
	/*Task 1*/
	// *************************************************** //

	std::cout << "First task." << std::endl;
	int arr[5] = { 1,2,3,4,5 };
	for (auto it : arr)
		std::cout << it << " ";
	std::cout << std::endl << std::endl;

	// *************************************************** //
	
	/*Task 2*/
	// *************************************************** //

	std::cout << "=============================================" << std::endl << std::endl;
	std::cout << "Second task " << std::endl;

	std::vector<int> randomNumbers = { 2,7,1,9,9,13,2,1,13,128,82,0,19,1,128 };

	auto foo = [](std::vector<int>& randomNumbers)
		{
			auto set = new std::unordered_set<int>();
			auto result = std::make_unique<std::vector<int>>();
			for (auto& el : randomNumbers)
			{
				if (set->count(el)) std::cout << el << " ";
				set->insert(el);
				result->push_back(el);
			}
			std::cout << std::endl;
			return result;
		};

	auto unPtr = foo(randomNumbers);
	for (auto& el : *unPtr)
		std::cout << el << " ";
	std::cout << std::endl;

	// *************************************************** //

	/*Task 3*/
	// *************************************************** //
	
	std::cout << std::endl << "=============================================" << std::endl << std::endl;
	std::cout << "Third task " << std::endl;

	std::filesystem::path p("..//TestPath");
	std::string extension = ".jpg";

	auto recursiveGetFileNamesByExtension = [](const std::filesystem::path& path, const std::string& extension)
		{
			std::vector<std::filesystem::path> result;
			for (auto& p : std::filesystem::recursive_directory_iterator(path))
			{
				if (!(p.path().extension().compare(extension)))
				{
					result.emplace_back(p);
				}
			}

			return result;
		};

	std::cout << "Files to path: " << p << "\nWith extension: " << extension << std::endl;
	for (auto& path : recursiveGetFileNamesByExtension(p, extension))
	{
		std::cout << path << std::endl;
	}

	return 0;
}