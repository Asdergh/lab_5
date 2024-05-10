#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

class FileBookManager
{

private:

	std::fstream file_object;
	std::string buffer_string;
	std::string manager_place_path;
	int number_of_books;

public:

	FileBookManager(std::string);
	void delete_book_from_file(int);
	void summary_of_all_books();
	void change_book_note_by_number(std::string, std::string, std::string, int, int);
	void add_new_book_note(std::string, std::string, std::string, int);
	


};

