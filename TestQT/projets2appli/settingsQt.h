
#include <qwidget.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qlabel.h>

class SettingsQt : public QWidget
{
	Q_OBJECT
public slots:
	void btnChangeHover(int btn);
public:
	SettingsQt(QWidget* parent = nullptr);
	QLabel* textDif;
	QLabel* textGridSize;

	QPushButton* gridSize4;
	QPushButton* gridSize5;
	QPushButton* gridSize7;

	QPushButton* diffSet1;
	QPushButton* diffSet2;
	QPushButton* diffSet3;

	QHBoxLayout* diffBtnLayout;
	QHBoxLayout* gridSizeLayout;
	
	QPushButton* listBtn[6];

};
