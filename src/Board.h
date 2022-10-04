#ifndef BOARD_H
#define BOARD_H

#include <string>

#include "ChessPieces.h"
#include "SettingsProvider.h"

namespace sf {
	class RenderWindow;
}

class Board
{
public:
	Board();

	void draw(sf::RenderWindow& window);

private:
	std::vector<std::vector<IChessPiece*>> m_boardMatrix = {
		{new BlackRook{}, new BlackKnight{}, new BlackBishop{}, new BlackQueen{}, new BlackKing{}, new BlackBishop{}, new BlackKnight{}, new BlackRook{}},
		{new BlackPawn{}, new BlackPawn{}, new BlackPawn{}, new BlackPawn{}, new BlackPawn{}, new BlackPawn{}, new BlackPawn{}, new BlackPawn{}},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{new WhitePawn{}, new WhitePawn{}, new WhitePawn{}, new WhitePawn{}, new WhitePawn{}, new WhitePawn{}, new WhitePawn{}, new WhitePawn{}},
		{new WhiteRook{}, new WhiteKnight{}, new WhiteBishop{}, new WhiteQueen{}, new WhiteKing{}, new WhiteBishop{}, new WhiteKnight{}, new WhiteRook{}},
	};

	double m_rectSize;
};

#endif