#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <SFML/Graphics.hpp>
#include "Board.h"


class MainWindow
{
public:
	explicit MainWindow(const int& width, const int& height);

	void create();

private:
	int		m_width;
	int		m_height;

	double m_x;
	double m_y;
	bool m_pieceChoosed;

	Board	m_board;
};

#endif