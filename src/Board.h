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
	void showHighlights(sf::RenderWindow& window, const double& x, const double& y);
	void makeMove(sf::RenderWindow& window, const double& x, const double& y);

private:
	/*std::vector<std::vector<ChessPiece*>> m_boardMatrix = {
		{new Rook{EBlack}, new Knight{EBlack}, new Bishop{EBlack}, new Queen{EBlack}, new King{EBlack}, new Bishop{EBlack}, new Knight{EBlack}, new Rook{EBlack}},
		{new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}},
		{new Rook{EWhite}, new Knight{EWhite}, new Bishop{EWhite}, new Queen{EWhite}, new King{EWhite}, new Bishop{EWhite}, new Knight{EWhite}, new Rook{EWhite}},
	};*/

	std::vector<std::vector<ChessPiece*>> m_boardMatrix = {
		{new Rook{EBlack},  nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new Rook{EBlack}},
		{new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}, new Pawn{EBlack}},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
		{new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}, new Pawn{EWhite}},
		{new Rook{EWhite},  nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new Rook{EWhite}},
	};

	double m_rectSize;
	bool m_isWhiteTurn;
};

#endif