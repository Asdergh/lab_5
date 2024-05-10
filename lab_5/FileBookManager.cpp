#include "FileBookManager.h"



FileBookManager::FileBookManager(std::string _manager_place_path)
{
	manager_place_path = _manager_place_path;
}

void FileBookManager::summary_of_all_books()
{
	file_object.open(manager_place_path, std::ios::in);
	while (file_object)
	{
		getline(file_object, buffer_string);
		std::cout << buffer_string << "\n";
	}
	buffer_string = "";
	file_object.close();
}

void FileBookManager::delete_book_from_file(int book_number)
{
	file_object.open(manager_place_path, std::ios::in);
	std::vector<std::string> tmp_string_buffer;
	int curent_book_number = 0;

	while (file_object)
	{
		if (curent_book_number !=  book_number)
		{
			tmp_string_buffer.push_back(buffer_string);
		}

		getline(file_object, buffer_string);
		file_object << "";
		curent_book_number += 1;
		
	}
	file_object.close();
	file_object.open(manager_place_path, std::ios::out | std::ios::trunc);

	curent_book_number = 0;
	while (file_object)
	{
		file_object << tmp_string_buffer[curent_book_number];
		curent_book_number += 1;
	}

	file_object.close();
}

void FileBookManager::add_new_book_note(std::string id_string, std::string book_name, std::string book_title, int pages_number)
{
	std::string new_book_note = id_string + "\t" + book_name + "\t" + book_title + "\t" + char(pages_number) + "\t";
	file_object.open(manager_place_path, std::ios::app);
	file_object << new_book_note;
	file_object.close();
}

void FileBookManager::change_book_note_by_number(std::string id_string, std::string book_name, std::string book_title, int pages_number, int note_number)
{
	file_object.open(manager_place_path, std::ios::in);
	std::vector<std::string> tmp_string_buffer;

	int curent_book_number = 0;

	while (file_object)
	{
		if (curent_book_number == note_number)
		{
			std::string new_note = id_string + "\t" + book_name + "\t" + book_title + "\t" + char(pages_number) + "\t";
			tmp_string_buffer.push_back(new_note);
		}
		else
		{
			tmp_string_buffer.push_back(buffer_string);
		}

		getline(file_object, buffer_string);
		file_object << "";
		curent_book_number += 1;

	}
	file_object.close();
	file_object.open(manager_place_path, std::ios::out | std::ios::trunc);

	curent_book_number = 0;
	while (file_object)
	{
		file_object << tmp_string_buffer[curent_book_number];
		curent_book_number += 1;
	}

	file_object.close();
}