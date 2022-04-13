/*
#include "settingsQt.h"

SettingsQt::SettingsQt(QWidget* parent)
{
	
	diffBtnLayout = new QHBoxLayout();
	gridSizeLayout = new QHBoxLayout();

	gridSize4 = new QPushButton(tr("4 X 4"));
	gridSize5 = new QPushButton(tr("5 X 5"));
	gridSize7 = new QPushButton(tr("7 X 7"));

	gridSizeLayout->addWidget(gridSize4);
	gridSizeLayout->addWidget(gridSize5);
	gridSizeLayout->addWidget(gridSize7);

	diffSet1 = new QPushButton(tr("Facile"));
	diffSet2 = new QPushButton(tr("Medium"));
	diffSet3 = new QPushButton(tr("Difficile"));

	diffBtnLayout->addWidget(diffSet1);
	diffBtnLayout->addWidget(diffSet2);
	diffBtnLayout->addWidget(diffSet3);

	//add les boutons dans une liste de boutons pour changer hover//
	//QPushButton* listBtn[6];
	listBtn[0] = gridSize4;
	listBtn[1] = gridSize5;
	listBtn[2] = gridSize7;
	listBtn[3] = diffSet1;
	listBtn[4] = diffSet2;
	listBtn[5] = diffSet3;

	/*QPalette maybe pour mettre ça en couleur?*/

/*
	//setLayout();
	setWindowTitle(tr("Modifier les paramètres"));
}

void SettingsQt::btnChangeHover(int btn)
{
	//boucle qui fait le tour des boutons pour les change//
	for  (QPushButton * aBtn : listBtn)
	{
		aBtn->setFlat(false);

	}
	// lui quon veut mettre en évidence
	listBtn[btn]->setFlat(true);
}

*/