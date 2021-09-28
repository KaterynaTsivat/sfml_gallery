#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> //б-ка содержит rand() и srand()
#include <time.h>  //б-ка содержит функцию time() 
#include <string>
#include <ctime>
class Window : public sf::RenderWindow {
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture texture5;
	sf::Color _bgColor;
	sf::Text text;
	sf::Font font;
	int j = 0, i = 0, z = 0;
public:
	Window(int width, int heigth) : sf::RenderWindow(sf::VideoMode(width, heigth), "Hello sfml!") {
		_bgColor = sf::Color::Black;
		font.loadFromFile("arial.ttf");
		text.setFont(font); // font is a sf::Font

		// set the string to display
		text.setString("Hello!!!");

		// set the character size
		text.setCharacterSize(67); // in pixels, not points!
		// set the color
		text.setFillColor(sf::Color::White);

		// set the text style
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	}
	void show() {

		while (this->isOpen())
		{
			sf::Event event;
			while (this->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					this->close();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == true) {
					std::cout << j << "\n"; j++;
					srand(time(0));
					switch (j) {
					case 1: this->setBgColor(rand() % 255 + 1, rand() % 251 + 1, rand() % 251 + 1);
						texture.loadFromFile("background1.png");
						text.setString("Picture 1");
						break;
					case 2: this->setBgColor(rand() % 255 + 1, rand() % 251 + 1, rand() % 251 + 1);
						texture2.loadFromFile("background2.png");
						text.setString("Picture 2");
						break;
					case 3: this->setBgColor(rand() % 255 + 1, rand() % 251 + 1, rand() % 251 + 1);
						texture3.loadFromFile("background3.png");
						text.setString("Picture 3");
						break;
					case 4: this->setBgColor(rand() % 255 + 1, rand() % 251 + 1, rand() % 251 + 1);
						texture4.loadFromFile("background4.png");
						text.setString("Picture 4");
						break;
					case 5: this->setBgColor(rand() % 255 + 1, rand() % 251 + 1, rand() % 251 + 1);
						texture5.loadFromFile("background5.png");
						text.setString("Picture 5");
						j = 0;
						break;
					}
				}
			}
			this->clear(this->_bgColor);
			sf::Sprite sprite(texture);
			sf::Sprite sprite2(texture2);
			sf::Sprite sprite3(texture3);
			sf::Sprite sprite4(texture4);
			sf::Sprite sprite5(texture5);
			sprite.move(0, 0);
			this->draw(sprite);
			this->draw(sprite2);
			this->draw(sprite3);
			this->draw(sprite4);
			this->draw(sprite5);
			this->draw(text);
			this->display();
		}
	}

	void setBgColor(int r, int g, int b) {
		this->_bgColor.r = r;
		this->_bgColor.g = g;
		this->_bgColor.b = b;
	}
	void setBgColor(const sf::Color& _color) {
		this->_bgColor = sf::Color(_color);
	}
	~Window() {}
};

int main()
{
	Window* window = new Window(1450, 850);
	window->show();
	delete window;
	return 0;
}
