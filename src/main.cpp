#include "MainWindow.h"
#include "SettingsProvider.h"


int main()
{
	MainWindow mw{ SettingsProvider::getInstance().getWidth(), SettingsProvider::getInstance().getHeight()};
	mw.create();
}