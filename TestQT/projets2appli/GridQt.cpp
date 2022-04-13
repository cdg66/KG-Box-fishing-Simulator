#include "GridQt.h"

GridQt::GridQt(QWidget* parent) {
    layout = new QGridLayout(parent);

    playBtn = new QPushButton(tr("Jouer"));
    yesBtn = new QPushButton(tr("Oui"));
    noBtn = new QPushButton(tr("Non"));
    leaderboardTitleLabel = new QLabel(tr("Classements"));

    layout->addWidget(playBtn, 1,1,1,1);

    setLayout(layout);
    setWindowTitle(tr("Main menu"));

}

void GridQt::btnChangeHover(int btn) {
    //boucle qui fait le tour des boutons pour les change//
    for (QPushButton* aBtn : listBtn)
    {
        aBtn->setFlat(false);

    }
    // lui quon veut mettre en évidence
    listBtn[btn]->setFlat(true);
}