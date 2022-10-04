#ifndef SETTINGS_PROVIDER_H
#define SETTINGS_PROVIDER_H


class SettingsProvider
{
public:
	static SettingsProvider getInstance()
	{
		static SettingsProvider settingsProvider{};
		return settingsProvider;
	}

	int getWidth() const
	{
		return m_width;
	}

	int getHeight() const
	{
		return m_height;
	}

	double getRectSize() const
	{
		return m_rectSize;
	}

	std::string getResImgPath() const
	{
		return m_resImgPath;
	}

private:
	explicit SettingsProvider()
	{}

private:
	const int m_width = 500; // WINDOW WIDTH
	const int m_height = 500; // WINDOW HEIGHT
	const double m_rectSize = 62.5; // SIZE OF ONE FIELD IN CHESSBOARD
	const std::string m_resImgPath = "../../res/img/"; // Image files path
};


#endif