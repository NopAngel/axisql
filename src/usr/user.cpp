#include <iostream>
#include <vector>
#include <unordered_map>

const std::string log_path = "./logs/main.log";

class User {
public:
    int id;
    std::string name;
    std::string password;

    User(int _id, std::string _name, std::string _password)
        : id(_id), name(_name), password(_password) {}
};

class UserManager {
private:
    std::unordered_map<int, User> users;
    int nextId = 1;

public:
   
    void createUser(std::string name, std::string password) {
        
    }

    
    void removeUser(int id) {
        
    }

  
    void listUsers() {
        
    }

   
    void viewUser(int id) {
        
    }
};


int main() {
    UserManager userManager;
   /*userManager.createUser("name", "password");


    userManager.listUsers();
    userManager.viewUser(1);

    userManager.removeUser(1);
    userManager.listUsers();*/

    return 0;
}
