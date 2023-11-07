#include "tree_b.h"

int main() {

    std::string name_of_book1;
    std::string author_surname_initials1;
    int date_of_writing1;
    int number_of_copies1;
    int YDK1;
    char variantchar;
    BooksInformation* root = read_from_filetxt("book_info.txt");
    BooksInformation* found_1 = nullptr;
    BooksInformation* check = new BooksInformation("23-<><>-22", "23-<><>-22", -1, -10, -10);
    int name;
    std::string name_of_book;
    int variant = 0;
    std::cout << "1 Print\n2 Add\n3 Year Search\n4 Reverse order\n5 Remove book\n6 Write book info to new file\n"
        "7 Changing parameters\n8 Print in alphabetical order\n9 Print books that are in the same category "
        "\n10 Print books that were written before a year\n11 Book write-off\n12 Find in tree by name\n13.Exit\n";
    while (variant != 13) {
        if (root == nullptr) {
            std::cout << "There are no books left";
            return 1;
        }
        std::cin >> variant;
        switch (variant) {
        case 1:
            ouput_info_for_func(1);
            std::cin >> variantchar;
            if(variantchar == '1')
                print_tree(root);
            if (variantchar == '2')
                print_tree_titles(root);
            std::cout << "************************************************" << std::endl;
            break;
        case 2:
            std::cout <<"\nName_of_book: ";
            std::cin >> name_of_book1;

            std::cout << "\nAuthor surname initials: ";
            std::cin >> author_surname_initials1;

            std::cout << "\nDate_of_writing: ";
            std::cin >> date_of_writing1;

            std::cout << "\nNumber_of_copies: ";
            std::cin >> number_of_copies1;

            std::cout << "\nYDK: ";
            std::cin >> YDK1;

            add_to_tree(root, new BooksInformation(name_of_book1, author_surname_initials1, date_of_writing1, number_of_copies1, YDK1));
            std::cout << "************************************************" << std::endl;
            break;
        case 3:
            std::cout << "\nDate of writing: ";
            std::cin >> name;
            check = find_in_tree(root, name);
            std::cout << "\n";
            std::cout << check->to_string();
            std::cout << "\n************************************************" << std::endl;
            break;
        case 4:
            std::cout << "Print in reverse order:\n ";
            in_order_traversal(root);
            std::cout << "\n************************************************" << std::endl;
            break;
        case 5:
            std::cout << "Enter the name of book you want to delete: ";
            std::cin >> name_of_book;
            found_1 = find_in_tree_by_name(root, name_of_book);
            if (found_1 == nullptr) {
                std::cout << "\nThe book is not found\n";
                break;
            }
            root = remove_node(root, found_1->get_date_of_writing());
            std::cout << "\nSuccessfully\n";
            std::cout << "\n************************************************" << std::endl;
            break;
        case 6:
            std::cout << "write_book_info_to_file ";
            write_book_info_to_file(root, "new_book_info.txt");
            std::cout << "\n************************************************" << std::endl;
            break;
        case 7: 
            std::cout << "Enter the name of book you want to change: ";
            std::cin >> name_of_book;          
            changing_parameters(root, name_of_book);
            write_book_info_to_file(root, "new_book_info.txt");
            root = read_from_filetxt("new_book_info.txt");
            std::cout << "\n************************************************" << std::endl;
            break;
        
        case 8:           
            get_books_in_alphabetical_order(root);
            std::cout << "\n************************************************" << std::endl;
            break;
        case 9:
            output_book_UDC_number(root);
            std::cout << "\n************************************************" << std::endl;
            break;
        case 10:
            output_of_books_written_before(root);
            std::cout << "\n************************************************" << std::endl;
            break;
        case 11:
            del_num_of_copies(root);
            std::cout << "\n************************************************" << std::endl;
            break;
        case 12:  
            std::cout << "Enter the name of book: ";
            std::cin >> name_of_book;
            found_1 = find_in_tree_by_name(root, name_of_book);
            if (found_1 == nullptr)
                std::cout << "\nThe book is not found\n";
            else 
                std::cout << "\n************************************************\n";
                std::cout << found_1->to_string();
            
            std::cout << "\n************************************************" << std::endl;
            break;

        default:
            std::cout << "Error! Choose a variant from the variants given.\n";
        }

        std::cout << "1 Print\n2 Add\n3 Year Search\n4 Reverse order\n5 Remove book\n6 Write book info to new file\n"
            "7 Changing parameters\n8 Print in alphabetical order\n9 Print books that are in the same category "
            "\n10 Print books that were written before a year\n11 Book write-off\n12 Find in tree by name\n";
    }
}
