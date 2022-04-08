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