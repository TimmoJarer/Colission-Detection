#include <SFML/Graphics.hpp>
#include<iostream>
int window_width = 900;
int window_height = 800;


int main()
{
    //Window and Shapes created here
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "FoodFinder", sf::Style::Close);
    sf::RectangleShape Border(sf::Vector2f(window_width, window_height));
    Border.setFillColor(sf::Color::Black);
    Border.setOutlineColor(sf::Color::Red);
    Border.setOutlineThickness(-10);
    sf::RectangleShape FoodFinder(sf::Vector2f(25.0f, 25.0f));
    FoodFinder.setFillColor(sf::Color(0, 200, 150));
    FoodFinder.setPosition(400, 450);
    sf::RectangleShape Food(sf::Vector2f(25.0f, 25.0f));
    Food.setFillColor(sf::Color(255,125,100));
    Food.setPosition(400,400);

    //Main window loop
    while(window.isOpen())
    {
        sf::Event FoodSearch;
        while(window.pollEvent(FoodSearch))
        {
            if(FoodSearch.type == FoodSearch.Closed)
            {
                window.close();
            }


            //Movement logic
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                FoodFinder.move(0, -2);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                FoodFinder.move(0, 2);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                FoodFinder.move(-2, 0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                FoodFinder.move(2, 0);
            }

            //Ensures boundaries can't be passed
            if(FoodFinder.getPosition().y <= 10)
            {
                FoodFinder.setPosition(FoodFinder.getPosition().x, 10);
            }
            if(FoodFinder.getPosition().y >=  765)
            {
                FoodFinder.setPosition(FoodFinder.getPosition().x, 765);
            }
            if(FoodFinder.getPosition().x < 10)
            {
                FoodFinder.setPosition(10, FoodFinder.getPosition().y);
            }
            if(FoodFinder.getPosition().x > 865)
            {
                FoodFinder.setPosition(865, FoodFinder.getPosition().y);
            }

            //Displays X and Y co-ordinates of FoodFinder
            sf::Vector2f FoodFinderPosition = FoodFinder.getPosition();
            sf::Vector2f FoodPosition = Food.getPosition();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << "FoodFinder X :"  << FoodFinderPosition.x << std::endl;
                std::cout << "FoodFinder Y :"  << FoodFinderPosition.y << std::endl;
                std::cout << "Food X :"  << FoodPosition.x << std::endl;
                std::cout << "Food Y :"  << FoodPosition.y << std::endl;
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                FoodFinder.setPosition(400, 400);
            }
            //Collision Detection

            if(FoodFinder.getPosition().y > Food.getPosition().y && FoodFinder.getPosition().y < Food.getPosition().y + 25 &&
               FoodFinder.getPosition().x > Food.getPosition().x && FoodFinder.getPosition().x < Food.getPosition().x + 25 )
            {
                Food.setPosition(1000,1000);
            }
            if(FoodFinder.getPosition().y > Food.getPosition().y && FoodFinder.getPosition().y < Food.getPosition().y + 25 &&
               FoodFinder.getPosition().x + 25 > Food.getPosition().x && FoodFinder.getPosition().x + 25 < Food.getPosition().x + 25 )
            {
                Food.setPosition(1000,1000);
            }
            if(FoodFinder.getPosition().y + 25 > Food.getPosition().y && FoodFinder.getPosition().y + 25 < Food.getPosition().y + 25 &&
               FoodFinder.getPosition().x > Food.getPosition().x && FoodFinder.getPosition().x < Food.getPosition().x + 25 )
            {
                Food.setPosition(1000,1000);
            }
            if(FoodFinder.getPosition().y + 25 > Food.getPosition().y && FoodFinder.getPosition().y + 25 < Food.getPosition().y + 25 &&
               FoodFinder.getPosition().x + 25 > Food.getPosition().x && FoodFinder.getPosition().x + 25 < Food.getPosition().x + 25 )
            {
                Food.setPosition(1000,1000);
            }
            if(FoodFinder.getPosition().y == Food.getPosition().y &&
               FoodFinder.getPosition().x < Food.getPosition().x + 25 && FoodFinder.getPosition().x > Food.getPosition().x )
            {
                Food.setPosition(1000,1000);
            }
            if(FoodFinder.getPosition().y == Food.getPosition().y &&
               FoodFinder.getPosition().x + 25 > Food.getPosition().x && FoodFinder.getPosition().x + 25 < Food.getPosition().x + 25 )
            {
                Food.setPosition(1000,1000);
            }
            if(FoodFinder.getPosition().x == Food.getPosition().x &&
               FoodFinder.getPosition().y + 25 > Food.getPosition().y  && FoodFinder.getPosition().y + 25 < Food.getPosition().y + 25 )
            {
                Food.setPosition(1000,1000);
            }
            if(FoodFinder.getPosition().x == Food.getPosition().x &&
               FoodFinder.getPosition().y > Food.getPosition().y  && FoodFinder.getPosition().y  < Food.getPosition().y + 25 )
            {
                Food.setPosition(1000,1000);
            }

            //Everything drawn here
            window.clear();
            window.draw(Border);
            window.draw(Food);
            window.draw(FoodFinder);
            window.display();
        }

    }
    return 0;
}
