#include "menuQt.h"

MenuQt::MenuQt(QWidget* parent)
{
	layoutChoiceBtn = new QHBoxLayout();
	layoutMainMenuShow = new QVBoxLayout();

	btnShowSettings = new QPushButton();
	btnStartNewGame = new QPushButton();

	lblWelcome = new QLabel(tr("Bienvenue au jeu \"Fishing Simulator\"!"));
	choicesUser = new QLabel();
	asciiArt = new QLabel();
	leaderboardTitleLabel = new QLabel(tr("Classements du jeu"));

	layoutChoiceBtn->addWidget(leaderboardTitleLabel);
	layoutChoiceBtn->addWidget(btnShowSettings);
	layoutChoiceBtn->addWidget(btnStartNewGame);

	layoutMainMenuShow->addLayout(layoutChoiceBtn);

	setLayout(layoutMainMenuShow);
	setWindowTitle(tr("Fishing Simulator"));
}