#include <iostream>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>

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

            // userName = getFile();
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
           if (file.is_open()) 
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

int main(int argc, char * argv[]) 
{
    // Initialize and create window
    sf::RenderWindow window(sf::VideoMode(640,480), "RayIT coding");

    // Event
    sf::Event event;

    // Draw rectangle
    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(sf::Vector2f(320.0f, 240.0f));
    sf::Vector2f v = sf::Vector2f(rectangle.getSize().x /2, rectangle.getSize().y /2);
    rectangle.setOrigin(v);

    // Images (Textures)
    sf::Texture texture;
    if (!texture.loadFromFile("filename.jpg")) {
        cout << "Error: loading image filename.jpg failed \n";
        return 1;
    }

    // While loop
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window.close();
        }
    }
    window.clear(sf::Color(0,0,0,255));
    // Draw here.
    window.draw(rectangle);
    window.display();

    // loginManager app;
    // app.login();
    
    cin.get();
    return 0;
};
