#include "mainQt.h"

void MainQt::showMenuWidget()
{
	gridQtWidget->hide();
	settingsQtWidget->hide();
	menuQtWidget->show();

}

void MainQt::showSettingsWidget()
{
	menuQtWidget->hide();
	gridQtWidget->hide();
	settingsQtWidget->show();

}

MainQt::MainQt(QWidget* parent = nullptr) {
	gridQtWidget = new GridQt();
	menuQtWidget = new MenuQt();
	settingsQtWidget = new SettingsQt();
}

void MainQt::showGridWidget() {
	settingsQtWidget->hide();
	menuQtWidget->hide();
	gridQtWidget->show();

}