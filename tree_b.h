#include <iostream>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>


class BooksInformation {
    std::string name_of_book;
    std::string author_surname_initials;
    int date_of_writing;
    int number_of_copies;
    int YDK;
public:
    BooksInformation* left;
    BooksInformation* right;

public:
    BooksInformation(std::string name_of_book, std::string author_surname_initials, int date_of_writing, int number_of_copies, int YDK);

    std::string to_string() const;

    std::string get_name_of_book();
    std::string get_author_surname_initials();
    int get_date_of_writing();
    int get_number_of_copies();
    int get_YDK();

    void set_name_of_book(std::string name_of_book);
    void set_author_surname_initials(std::string author_surname_initials);
    void set_date_of_writing(int date_of_writing);
    void set_number_of_copies(int number_of_copies);
    void set_YDK(int YDK);

    bool operator<(const BooksInformation& other) const;
    bool operator<=(const BooksInformation& other) const;
    bool operator>(const BooksInformation& other) const;
    bool operator>=(const BooksInformation& other) const;
    bool operator==(const BooksInformation& other) const;
};

BooksInformation* generate_tree(int count_nodes);

void add_to_tree(BooksInformation* root, BooksInformation* node);
BooksInformation* remove_node(BooksInformation* root, int date_of_writing);

void print_tree(const BooksInformation* root);
BooksInformation* find_in_tree(BooksInformation* root, int date_of_writing);
BooksInformation* find_in_tree_by_name(BooksInformation* root, std::string name_of_book);
void in_order_traversal(BooksInformation* root);
void write_book_info_to_file(const BooksInformation* book, const std::string& filename);
void write_book_info_to_file_(const BooksInformation* book, const std::string& filename);
BooksInformation* read_from_filetxt(std::string file_name);
void changing_parameters(BooksInformation* root, std::string name_of_book);
void get_books_in_alphabetical_order(BooksInformation* root);
void output_of_books_written_before(BooksInformation* root);
void output_book_UDC_number(BooksInformation* root);
void ouput_info_for_func(short answer);
void del_num_of_copies(BooksInformation*& root);
void print_tree_titles(BooksInformation* root);