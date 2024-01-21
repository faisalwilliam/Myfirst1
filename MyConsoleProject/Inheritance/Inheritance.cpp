
#include <iostream>
#include <string>
#include <vector>
#ifndef BANK_MENU_HPP
#define BANK_MENU_HPP
class Menu {
public:
    enum class ID {
        MAIN,
        ACCOUNT,
        TRANSFER,
        EXCHANGE,
        NONE = -1,
    };
private:
    Menu* parent_;
    std::string title_;
    std::vector<Menu*> sub_menus_;
    ID id_;
public:
    Menu() : parent_(nullptr), id_(ID::NONE) { }
    Menu(const std::string& title, ID id) : parent_(nullptr), title_(title), id_(id) { }
    ~Menu() {
        for (auto menu_ptr : sub_menus_) {
            delete menu_ptr;
        }
    }
    void display() {
        std::cout << title_ << '\n';
        for (size_t i = 0; i < title_.length(); ++i)
            std::cout << '=';
        std::cout << '\n';
        for (size_t i = 0; i < sub_menus_.size(); ++i) {
            std::cout << (i + 1) << ". " << sub_menus_[i]->title_ << '\n';
        }
        if (parent_ != nullptr) {
            std::cout << "0. Back" << std::endl;
        }
        else {
            std::cout << "0. Exit" << std::endl;
        }
    }
    Menu* enter(size_t submenu) {
        if (submenu == 0)
            return parent_;
        if (submenu > sub_menus_.size()) {
            std::cout << "Invalid submenu\n";
            return this;
        }
        return sub_menus_[submenu - 1];
    }
    void addItem(const std::string& title, ID id = ID::NONE) {
        Menu* item = new Menu(title, id);
        item->parent_ = this;
        sub_menus_.push_back(item);
    }
    void addSubmenu(Menu* submenu) {
        submenu->parent_ = this;
        sub_menus_.push_back(submenu);
    }
};
#endif // BANK_MENU_HPP
class Navigation {
private:
    Menu main_menu;
public:
    Navigation() : main_menu("Bank", Menu::ID::MAIN) {
        Menu* account_menu = new Menu("Account and balance", Menu::ID::ACCOUNT);
        account_menu->addItem("Salary account");
        account_menu->addItem("Savings account");
        main_menu.addSubmenu(account_menu);
        Menu* transfer_menu = new Menu("Transfer", Menu::ID::TRANSFER);
        main_menu.addSubmenu(transfer_menu);
        Menu* exchange_menu = new Menu("Exchange", Menu::ID::EXCHANGE);
        main_menu.addSubmenu(exchange_menu);
    }
    void run() {
        Menu* current = &main_menu;
        while (current != nullptr) {
            current->display();
            size_t choice;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear(); // clear input buffer to restore cin to a usable state
                std::cin.ignore(INT_MAX, '\n'); // ignore last input
                std::cout << "You can only enter numbers.\n";
                continue;
            }
            current = current->enter(choice);
        }
        std::cout << "Exit.\n";
    }
};


int main() {
    Navigation nav;
    nav.run();
    return 0;
}