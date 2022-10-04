#include "MainWindow.h"


MainWindow::MainWindow(const int& width, const int& height) : m_width(width), m_height(height)
{}

void MainWindow::create()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(m_width, m_height), "Chess");

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				m_board.showHighlights(event.mouseButton.x, event.mouseButton.y);
				break;
			}
		}
		window.clear();
		m_board.draw(window);
		window.display();
	}
}