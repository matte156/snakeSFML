#include<SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace sf;
using namespace std;

int main(){
    /* con height e weight si definisce la grandezza della finestra*/
    int height = 900;
    int weight = 1700;
    /*si crea la finestra*/
    RenderWindow window (VideoMode(weight, height), "Snake Game!");
    /* si creano i rettangoli background1, snake, fruit con dimensioni 20x20 e colore bianco, rosso, verde*/
    RectangleShape background1(Vector2f(20, 20));
    RectangleShape snake(Vector2f(20, 20));
    snake.setFillColor(Color::Red);
    RectangleShape fruit(Vector2f(20, 20));
    fruit.setFillColor(Color::Green);
    // viene definita la direzione del serpente
    int direction = 1;
    // x e y corrispondono alle coordinate del serpente
    int x = 0;
    int y = 0;
    bool gameOver = false;
    // fruitX e fruitY corrispondono alle coordinate della frutta
    int fruitX, fruitY;
    // con questi comandi si ottengono due valori random: uno varia da 0-85, l'altro da 0-45
    fruitX = rand() % 85;
    fruitY = rand() % 45;
    // il vettore code serve a immagazzinare le direzioni dadare alla coda
    vector<int> code;
    // numero dei pezzi della coda e la presenza della coda
    
    bool codaPresente = false;
    int num = 3;
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();


        // viene "disegnato" lo sfondo
        for (int i = 0; i < (weight/20); i++){
            for (int j = 0; j < (height/20); j++){
                background1.setPosition(i*20, j*20);
                window.draw(background1);
            }
        }

        //viene disegnata la frutta
        fruit.setPosition(fruitX*20, fruitY*20);
        window.draw(fruit);

        if (gameOver == false){

            // si implementa una "Key listener"
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                if (direction != 4){
                    direction = 2;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)){
                if (direction != 3){
                    direction = 1;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                if (direction != 2) {
                    direction = 4;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)){
                if (direction != 1) {
                    direction = 3;
                }
            }
            
            //viene disegnata la testa del serpente

            snake.setPosition(x*20, y*20);
            window.draw(snake);
            
        }

        
        if (x == fruitX && y == fruitY) {
            fruitX = rand() % 85;
            fruitY = rand() % 45;
        }

        

        if (direction == 2) {
            x--;
        }
        if (direction == 1) {
            y++;
        }
        if (direction == 4) {
            x++;
        }
        if (direction == 3) {
            y--;
        }

        if (y > 45) {
            y = 0;
        }
        if (y < 0) {
            y = 45;
        }
        if (x > 85) {
            x = 0;
        }
        if (x < 0) {
            x = 85;
        }

        /* int temporaryX, temporaryY, temporaryDirection;

        if (temporaryDirection == 2) {
            x--;
        }
        if (temporaryDirection == 1) {
            y++;
        }
        if (temporaryDirection == 4) {
            x++;
        }
        if (temporaryDirection == 3) {
            y--;
        }

        snake.setPosition(temporaryX*20, temporaryY*20);
        window.draw(snake);

        temporaryX = x;
        temporaryY = y;
        temporaryDirection = direction; */

        window.display();
        this_thread::sleep_for(chrono:: milliseconds(50));
    }
    return 15;
}