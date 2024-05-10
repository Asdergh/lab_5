#include<iostream>
#include<vector>
#include<math.h>
#include<iostream>
#include<fstream>
#include"FileHandler.h"
#include"fileBookManager.h"

std::string file_path = "C:\\Users\\1\\Desktop\\MachineLearningStud\\test_text.txt";
std::string matrix_file_path = "C:\\Users\\1\\Desktop\\MachineLearningStud\\matrix.txt";
std::string file_manager_path = "";

int main()
{
	FileHandler simple_object;
	/*
	std::vector<std::vector<float>> test_matrix;
	test_matrix.resize(3, std::vector<float>(3));

	for (int iter_i = 0; iter_i < 3; iter_i++)
	{
		for (int iter_j = 0; iter_j < 3; iter_j++)
		{
		
			test_matrix[iter_i][iter_j] = float((rand() % 100) + 10);
		}
	}

	simple_object.write_matrix_to_file(test_matrix, matrix_file_path, 3, 3);
	
	std::vector<std::vector<double>> result_tensor = simple_object.read_matrix_from_file(matrix_file_path, 3, 3);

	for (int iter_i = 0; iter_i < 3; iter_i++)
	{
		for (int iter_j = 0; iter_j < 3; iter_j++)
		{
			std::cout << result_tensor[iter_i][iter_j] << "\t";
		}
		std::cout << "\n";
	}
	*/

	simple_object.find_words_count("test", file_path);
	return 0;
}

