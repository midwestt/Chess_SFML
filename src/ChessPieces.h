#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "SettingsProvider.h"


class IChessPiece
{
public:
	virtual void showMoves() = 0;
	virtual void draw(sf::RenderWindow& window, const double& x, const double& y) = 0;

	virtual double getX() const = 0;
	virtual double getY() const = 0;
};

class WhitePawn : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

protected:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_plt60.png";

	double m_x;
	double m_y;
};

class WhiteRook : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

protected:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_rlt60.png";

	double m_x;
	double m_y;
};

class WhiteKnight : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

private:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_nlt60.png";

	double m_x;
	double m_y;
};

class WhiteBishop : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

protected:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_blt60.png";

	double m_x;
	double m_y;
};

class WhiteQueen : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

private:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_qlt60.png";

	double m_x;
	double m_y;
};

class WhiteKing : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

private:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_klt60.png";
	double m_x;
	double m_y;
};

/////////////

class BlackPawn : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

protected:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_pdt60.png";

	double m_x;
	double m_y;
};

class BlackRook : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

protected:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_rdt60.png";

	double m_x;
	double m_y;
};

class BlackKnight : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

private:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_ndt60.png";

	double m_x;
	double m_y;
};

class BlackBishop : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

protected:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_bdt60.png";

	double m_x;
	double m_y;
};

class BlackQueen : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

private:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_qdt60.png";

	double m_x;
	double m_y;
};

class BlackKing : public IChessPiece
{
public:
	void showMoves() override;
	void draw(sf::RenderWindow& window, const double& x, const double& y) override;

	double getX() const override
	{
		return m_x;
	}

	double getY() const override
	{
		return m_y;
	}

private:
	const std::string m_filepath = SettingsProvider::getInstance().getResImgPath() + "Chess_kdt60.png";
	double m_x;
	double m_y;
};

#endif