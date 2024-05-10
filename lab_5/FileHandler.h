#pragma once
#include<fstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>

class FileHandler
{

private:

	std::string file_data_line;
	std::fstream file_object;

public:


	void find_words_count(std::string word_to_count, std::string file_path)
	{
		file_object.open(file_path, std::ios::in);
		int result_word_count = 0;

		while (getline(file_object, file_data_line))
		{
			if (file_data_line.find(word_to_count))
			{
				result_word_count += 1;
			}
		}

		file_data_line = " ";
		std::cout << "\nTotal count of word: [" << word_to_count << "] in file: [" << file_path << "] is: [" << result_word_count << "]!!!\n";
		file_object.close();
	}

	void write_matrix_to_file(std::vector<std::vector<float>> matrix_object, std::string file_path, int matrix_width, int matrix_height)
	{
		file_object.open(file_path, std::ios::out);
		for (int iter_i = 0; iter_i < matrix_height; iter_i++)
		{
			for (int iter_j = 0; iter_j < matrix_width; iter_j++)
			{
				file_object << int(matrix_object[iter_i][iter_j]) << "\t";
			}
			file_object << "\n";
		}
		file_object.close();
	}

	std::vector<std::vector<double>> read_matrix_from_file(std::string file_path, int matrix_width, int matrix_height)
	{
		file_object.open(file_path, std::ios::in);
		int iter_j = 0;
		int iter_i = 0;

		float buffer;
		std::vector<std::vector<double>> result_matrix;
		result_matrix.resize(matrix_height, std::vector<double>(matrix_width));

		while (file_object)
		{
			getline(file_object, file_data_line);

			for (int string_parser = 0; string_parser < file_data_line.size(); string_parser++)
			{
				if (file_data_line[string_parser] == '\t')
				{
					if (iter_i == 3)
					{
						iter_i = 0;
					}
					char tmp_string[2];
					tmp_string[0] = char(file_data_line[string_parser - 2]);
					tmp_string[1] = char(file_data_line[string_parser - 1]);

					result_matrix[iter_j][iter_i] = std::atof(tmp_string);
					iter_i += 1;

				}
			}
			iter_j += 1;

		}

		return result_matrix;
	}
	
};

