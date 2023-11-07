#include "tree_b.h"

BooksInformation::BooksInformation(std::string name_of_book, std::string author_surname_initials, int date_of_writing, int number_of_copies, int YDK) {
    this->name_of_book = name_of_book;
    this->author_surname_initials = author_surname_initials;
    this->date_of_writing = date_of_writing;
    this->number_of_copies = number_of_copies;
    this->YDK = YDK;

    this->left = nullptr;
    this->right = nullptr;
}

std::string BooksInformation::to_string() const {
    return "Name of book: " + (name_of_book) + "\nAuthor surname and initials: " + (author_surname_initials) + 
        "\nDate of writing: " + std::to_string(date_of_writing) + "\nNumber of copies: " + std::to_string(number_of_copies) + "\nYDK: " + std::to_string(YDK) + "\n";
}

std::string BooksInformation::get_name_of_book() {
    return this->name_of_book;
}

std::string BooksInformation::get_author_surname_initials() {
    return this->author_surname_initials;
}

int BooksInformation::get_date_of_writing() {
    return this->date_of_writing;
}

int BooksInformation::get_number_of_copies() {
    return this->number_of_copies;
}

int BooksInformation::get_YDK() {
    return this->YDK;
}


void BooksInformation::set_name_of_book(std::string name_of_book) {
    this->name_of_book = name_of_book;
}

void BooksInformation::set_author_surname_initials(std::string author_surname_initials) {
    this->author_surname_initials = author_surname_initials;
}

void BooksInformation::set_date_of_writing(int date_of_writing) {
    this->date_of_writing = date_of_writing;
}

void BooksInformation::set_number_of_copies(int number_of_copies) {
    this->number_of_copies = number_of_copies;
}

void BooksInformation::set_YDK(int YDK) {
    this->YDK = YDK;
}

bool BooksInformation::operator<(const BooksInformation& other) const {
    return this->date_of_writing < other.date_of_writing;
}

bool BooksInformation::operator<=(const BooksInformation& other) const {
    return this->date_of_writing <= other.date_of_writing;
}


bool BooksInformation::operator>(const BooksInformation& other) const {
    return this->date_of_writing > other.date_of_writing;
}

bool BooksInformation::operator>=(const BooksInformation& other) const {
    return this->date_of_writing >= other.date_of_writing;
}

bool BooksInformation::operator==(const BooksInformation& other) const {
    return this->date_of_writing == other.date_of_writing;
}

BooksInformation* generate_tree(int count_nodes) {
    std::string name_of_book1;
    std::string author_surname_initials1;
    int date_of_writing1;
    int number_of_copies1;
    int YDK1;
    std::cout << "name_of_book1: ";
    std::cin >> name_of_book1;

    std::cout << "\nauthor_surname_initials1:  ";
    std::cin >> author_surname_initials1;

    std::cout << "\ndate_of_writing1: ";
    std::cin >> date_of_writing1;

    std::cout << "\nnumber_of_copies1";
    std::cin >> number_of_copies1;

    std::cout << "\nYDK1: ";
    std::cin >> YDK1;

    BooksInformation* root = new BooksInformation(name_of_book1, author_surname_initials1, date_of_writing1, number_of_copies1, YDK1);

    for (int i = 1; i < count_nodes; i++) {
        std::cout << "name_of_book1: ";
        std::cin >> name_of_book1;

        std::cout << "\nauthor_surname_initials1:  ";
        std::cin >> author_surname_initials1;

        std::cout << "\ndate_of_writing1: ";
        std::cin >> date_of_writing1;

        std::cout << "\nnumber_of_copies1";
        std::cin >> number_of_copies1;

        std::cout << "\nYDK1: ";
        std::cin >> YDK1;
        add_to_tree(root, new BooksInformation(name_of_book1, author_surname_initials1, date_of_writing1, number_of_copies1, YDK1));
    }

    return root;
}

void add_to_tree(BooksInformation* root, BooksInformation* node) {
    if ((*node) < (*root)) {
        if (root->left)
            add_to_tree(root->left, node);
        else
            root->left = node;
    }
    else {
        if (root->right)
            add_to_tree(root->right, node);
        else
            root->right = node;
    }
}

BooksInformation* remove_node(BooksInformation* root, int date_of_writing) {
    if (not root) {
        return root;
    }

    if (find_in_tree(root->left, date_of_writing)) {
        root->left = remove_node(root->left, date_of_writing);
    }
    else if (find_in_tree(root->right, date_of_writing)) {
        root->right = remove_node(root->right, date_of_writing);
    }
    else {
        if (root->get_date_of_writing() != date_of_writing)
            return root;


        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        if (root->left == nullptr) {
            BooksInformation* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            BooksInformation* temp = root->left;
            delete root;
            return temp;
        }

        BooksInformation* successor = root->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        root->set_name_of_book(successor->get_name_of_book());
        root->set_author_surname_initials(successor->get_author_surname_initials());
        root->set_date_of_writing(successor->get_date_of_writing());
        root->set_number_of_copies(successor->get_number_of_copies());
        root->set_YDK(successor->get_YDK());
        root->right = remove_node(root->right, successor->get_date_of_writing());
    }

    return root;
}


void print_tree(const BooksInformation* root) {
    if (root->left)
        print_tree(root->left);
    std::cout << root->to_string() << "\n";
    if (root->right)
        print_tree(root->right);
}

void print_tree_titles(BooksInformation* root) {
    if (root->left)
        print_tree_titles(root->left);
    std::cout << "\n" << root->get_name_of_book() << "\n";
    if (root->right)
        print_tree_titles(root->right);
}

BooksInformation* find_in_tree_(BooksInformation* root, const BooksInformation node) {
    if ((*root) == node)
        return root;
    if (node < (*root)) {
        if (root->left)
            return find_in_tree_(root->left, node);
    }
    else if (root->right)
        return find_in_tree_(root->right, node);
    return nullptr;
}

BooksInformation* find_in_tree(BooksInformation* root, int date_of_writing) {
    if (not root)
        return root;
    return find_in_tree_(root, BooksInformation("23-<><>-22", "23-<><>-22", date_of_writing, -10, -10));
}


BooksInformation* find_in_tree_by_name(BooksInformation* root, std::string name_of_book) {
    if (not root)
        return nullptr;
    if (root->get_name_of_book() == name_of_book)
        return root;
    BooksInformation* found_1 = nullptr;
    BooksInformation* found_2 = nullptr;
    if (root->left)
        found_1 = find_in_tree_by_name(root->left, name_of_book);
    if (root->right)
        found_2 = find_in_tree_by_name(root->right, name_of_book);
    return found_1 ? found_1 : found_2;
}

void in_order_traversal(BooksInformation* root) {
    if (not root)
        return;
    in_order_traversal(root->right);
    std::cout << root->to_string() << std::endl;
    in_order_traversal(root->left);
}


void write_book_info_to_file_(const BooksInformation* book, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); 

    if (file.is_open()) {
        file << book->to_string() << std::endl;  
        file.close();  
    }
    else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void write_book_info_to_file(const BooksInformation* root, const std::string& filename) {
    if (root->left)
        write_book_info_to_file(root->left, filename);
    write_book_info_to_file_(root, filename);
    if (root->right)
        write_book_info_to_file(root->right, filename);
}


BooksInformation* read_from_filetxt(std::string file_name) {
    BooksInformation* book = nullptr;
    std::string name_of_book;
    std::string initials;
    int date;
    int num_of_copies;
    int YDK;
    int count = 0;
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return nullptr;
    }
    std::string line;
    getline(file, line);
    if (line.find("Name of book:") == std::string::npos) {
        std::cout << "File empty. Please press 1 and formation.";
        return nullptr;
    }

    while (file.good()) {

        count++;
        if (line.find("Name of book:") != std::string::npos) {
            name_of_book = line.substr(14);
        }
        else if (line.find("Author surname and initials:") != std::string::npos) {
            initials = line.substr(29);
        }

        else if (line.find("Date of writing:") != std::string::npos) {
            date = stoi(line.substr(16));
        }

        else if (line.find("Number of copies:") != std::string::npos) {
            num_of_copies = stoi(line.substr(18));
        }
        else if (line.find("YDK:") != std::string::npos) {
            YDK = stoi(line.substr(5));
        }
        getline(file, line);

        if (count % 6 == 0) {
            if (count == 6) {
                book = new BooksInformation(name_of_book, initials, date, num_of_copies, YDK);
                continue;
            }
            add_to_tree(book, new BooksInformation(name_of_book, initials, date, num_of_copies, YDK));
        }
    }
    file.close();
    return book;
}

void changing_parameters_(BooksInformation* root) {
    int answer;
    std::string set_name;
    std::string author_surname;
    int set_date;
    int set_num_cop;
    int set_ydk;
    ouput_info_for_func(3);
    std::cin >> answer;
    switch (answer) {
    case 1:
        std::cout << "Enter new name of book: ";
        std::cin >> set_name;
        root->set_name_of_book(set_name);
        return;
    case 2:
        std::cout << "Enter new initials: ";
        std::cin >> author_surname;
        root->set_author_surname_initials(author_surname);
        return;
    case 3:
        std::cout << "Enter new date of writing: ";
        std::cin >> set_date;
        root->set_date_of_writing(set_date);
        return;
    case 4:
        std::cout << "Enter new num copies: ";
        std::cin >> set_num_cop;
        root->set_number_of_copies(set_num_cop);
        return;
    case 5:
        std::cout << "Enter new number UDC: ";
        std::cin >> set_ydk;
        root->set_YDK(set_ydk);
        return;
    default:
        return;
    }
    
}

void changing_parameters(BooksInformation* root, std::string name_of_book) {
    std::ofstream file("new_book_info.txt", std::ios::out);
    file.open("new_book_info.txt", std::ios::out | std::ios::trunc);
    file.close();
    root = find_in_tree_by_name(root, name_of_book);
    if (not root) {
        std::cout << "No book with this name found.";
        return;
    }
    changing_parameters_(root);
}
void get_books_in_alphabetical_order_(BooksInformation* root, char check, char variant) {

    if (!root) 
        return;

    get_books_in_alphabetical_order_(root->left, check, variant);
    
    if (root->get_name_of_book()[0] == check && variant == '1') {
        std::cout << root->to_string() << "\n";
    }
    if (root->get_name_of_book()[0] == check && variant == '2') {
        std::cout << root->get_name_of_book() << "\n\n";
    }
    get_books_in_alphabetical_order_(root->right, check, variant);
}

void get_books_in_alphabetical_order(BooksInformation* root) {
    char variant;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ouput_info_for_func(1);
    std::cin >> variant;

    if (variant != '1' && variant != '2')
        return;
    if (variant == '2')
        std::cout << "\nAll the books in the library:\n\n";

    for (int i = 0; i < 26; i++) {
        get_books_in_alphabetical_order_(root, alphabet[i], variant);
    }
}

void output_of_books_written_before_(BooksInformation* root, int date, char answer) {
    if (not root)
        return;
    output_of_books_written_before_(root->left, date, answer);

    if (root->get_date_of_writing() < date && answer == '1') {
        std::cout << root->to_string() << "\n";
    }
    if (root->get_date_of_writing() < date && answer == '2') {
        std::cout << root->get_name_of_book() <<", year: " << root->get_date_of_writing() << "\n\n";
    }

    output_of_books_written_before_(root->right, date, answer);
}

void output_of_books_written_before(BooksInformation* root) {
    char answer;
    int date;
    std::cout << "\nWhat year do you need to get the information out?\n";
    std::cin >> date;

    ouput_info_for_func(1);
    std::cin >> answer;
    if (answer != '1' && answer != '2')
        return;
    if (answer == '2')
        std::cout << "\nAll the books in the library:\n\n";

    output_of_books_written_before_(root, date , answer);
}


void output_book_UDC_number_(BooksInformation* root, int UDC, char variant, short &check) {
    if (not root)
        return;

    output_book_UDC_number_(root->left, UDC, variant, check);

    if (root->get_YDK() == UDC && variant == '1') {
        check = 1;
        std::cout << root->to_string() << "\n";
    }
    if (root->get_YDK() == UDC && variant == '2') {
        check = 1;
        std::cout << root->get_name_of_book() << "\n\n";
    }

    output_book_UDC_number_(root->right, UDC, variant, check);
}


void output_book_UDC_number(BooksInformation* root) {
    int UDC[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    short answer;
    char variant;
    short check = 0;

    ouput_info_for_func(2);
    std::cin >> answer;
    
    ouput_info_for_func(1);
    std::cin >> variant;
    std::cout << "\n\n\n";

    if (variant != '1' && variant != '2') {
        std::cout << "\nWrong answer\n";
        return;
    }
    while (1) {
        switch (answer) {
        case 1:
            output_book_UDC_number_(root, UDC[0], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 2:
            output_book_UDC_number_(root, UDC[1], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 3:
            output_book_UDC_number_(root, UDC[2], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 4:
            output_book_UDC_number_(root, UDC[3], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 5:
            output_book_UDC_number_(root, UDC[4], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 6:
            output_book_UDC_number_(root, UDC[5], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 7:
            output_book_UDC_number_(root, UDC[6], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 8:
            output_book_UDC_number_(root, UDC[7], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        case 9:
            output_book_UDC_number_(root, UDC[8], variant, check);
            if (!check)
                std::cout << "No book with this number is available";
            return;
        default:
            std::cout << "No such UDC number, please choose another option or press 10 to exit: ";
            std::cin >> answer;
            if (answer == 10)
                return;
            break;
        }
    }

}


void ouput_info_for_func(short answer) {

    switch (answer) {
    case 1:
        std::cout << "\nHow do you see the output of books?\n";
        std::cout << "1.All Information\n";
        std::cout << "2.Book titles only\n";
        std::cout << "(Any key).Return to the main menu\n";
        return;
    case 2:
        std::cout << "\n0 Science and Knowledge. Computer Science. Documentation. Librarianship. Publications\n"
            "1 Philosophy.Psychology\n"
            "2 Religion.Theology\n"
            "3 Social Sciences\n"
            "4 vacant\n"
            "5 Mathematics.Natural Sciences\n"
            "6 Applied Sciences.Medicine, Technology\n"
            "7 The Arts.Entertainment.Sport\n"
            "8 Linguistics.Literature\n"
            "9 Geography.History\n";
        return;
    case 3:
        std::cout << "\n1.Edit Name\n";
        std::cout << "2.Edit the initials of the author.\n";
        std::cout << "3.Edit the date of writing.\n";
        std::cout << "4.Edit number of copies.\n";
        std::cout << "5.Edit UDC number \n";
        std::cout << "(Any key).Return to the main menu\n";
        return;
    }
}


void del_num_of_copies(BooksInformation*& root) {
    std::string name_of_book;
    int setting;
    std::cout << "What book did you take?: ";
    std::cin >> name_of_book;
    while (1) {
        if (name_of_book == "exit")
            return;
                
        BooksInformation* book = find_in_tree_by_name(root, name_of_book);
        if (not book) {
            std::cout << "No book found, write again name of book.\n(For exit write \"exit\")\n";
            std::cin >> name_of_book;
            continue;
        }     
        while (1) {
            setting = book->get_number_of_copies();
            std::cout << "How many books are taken (" << setting << " books left)\n";
            std::cin >> setting;
            if (setting > book->get_number_of_copies()) {
                std::cout << "You can’t write off more books than have! \n";
                continue;
            }
            book->set_number_of_copies(book->get_number_of_copies() - setting);
            setting = book->get_date_of_writing();
            std::cout << "\nSuccessfully\n";
            if (book->get_number_of_copies() == 0) {
                root = remove_node(root, setting);
                std::cout << "Took the last book";      
                return;
            }
            return;
        }
    }
}