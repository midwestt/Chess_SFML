#include "MainWindow.h"


MainWindow::MainWindow(const int& width, const int& height) : m_width(width), m_height(height)
{}

void MainWindow::create()
{
	m_pieceChoosed = false;

	sf::RenderWindow window;
	window.create(sf::VideoMode(m_width, m_height), "Chess");

	sf::Event event;
	while (window.isOpen())
	{
		window.clear();

		m_board.draw(window);

		if (m_pieceChoosed)
			m_board.showHighlights(window, m_x, m_y);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				m_x = event.mouseButton.x;
				m_y = event.mouseButton.y;

				if (!m_pieceChoosed)
				{
					m_board.showHighlights(window, m_x, m_y);
					m_pieceChoosed = true;
				}
				else
				{
					m_board.makeMove(window, m_x, m_y);
					m_pieceChoosed = false;
				}
				

				break;
			}
		}

		window.display();
	}
}