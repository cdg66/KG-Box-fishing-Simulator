#include "GridQt.h"

GridQt::GridQt(QWidget* parent) {
    actionBtnLayout = new QHBoxLayout();
    layout = new QGridLayout(parent);
    
    case1_1 = new QGraphicsRectItem();
    case1_2 = new QGraphicsRectItem();
    case1_3 = new QGraphicsRectItem();
    case2_1 = new QGraphicsRectItem();
    case2_2 = new QGraphicsRectItem();
    case2_3 = new QGraphicsRectItem();
    case3_1 = new QGraphicsRectItem();
    case3_2 = new QGraphicsRectItem();
    case3_3 = new QGraphicsRectItem();

    labelCase1_1 = new QLabel();
    labelCase1_2 = new QLabel();
    labelCase1_3 = new QLabel();
    labelCase2_1 = new QLabel();
    labelCase2_2 = new QLabel();
    labelCase2_3 = new QLabel();
    labelCase3_1 = new QLabel();
    labelCase3_2 = new QLabel();
    labelCase3_3 = new QLabel();




    yesBtn = new QPushButton(tr("Oui"));
    noBtn = new QPushButton(tr("Non"));

    //layout->addLayout(actionBtnLayout);

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