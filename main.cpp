#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class loginManager 
{
    public:
        string userNameAttempt;
        string passWordAttempt;

        loginManager() {
            accessGranted = false;
        };
        ~loginManager() {
        };

        void login() {
            cout << "Please enter password and username.\nUsername:";
            cin >> userNameAttempt;

            userName = getFile();
            if ( userNameAttempt == userName ) {
                cout << "Password:";
                cin >> passWordAttempt;
                if ( passWordAttempt == passWord ) {
                    cout << "Hey, thats right.";
                }
            }
        }

        string getFile(const char* p_fileName) {
           string line;
           fstream file;
           file.open(p_fileName, ios::in);
           if (file.is_open) 
           {
               getline(file, line);
           }
           file.close();

           return line;
        }
    private:
        string userName = "rayit";
        string passWord = "rayrayray";
        bool accessGranted;
};

int main() 
{
    loginManager app;
    app.login();
    
    cin.get();
    return 0;
};
