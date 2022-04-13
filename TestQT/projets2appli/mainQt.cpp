#include "mainQt.h"

void MainQt::showMenuWidget()
{
	gridQtWidget->hide();
	settingsQtWidget->hide();
	menuQtWidget->show();

}

void MainQt::showSettingsWidget()
{
	menuQtWidget->show();
	gridQtWidget->hide();
	settingsQtWidget->show();

}

MainQt::MainQt(QWidget* parent) {
	gridQtWidget = new GridQt();
	menuQtWidget = new MenuQt();
	settingsQtWidget = new SettingsQt();
}

void MainQt::showGridWidget() {
	settingsQtWidget->hide();
	menuQtWidget->hide();
	gridQtWidget->show();

}