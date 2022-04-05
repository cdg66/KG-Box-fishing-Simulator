TEMPLATE     = vcapp
TARGET       = projets2appli
CONFIG      += warn_on qt debug windows console
HEADERS     += projets2appli/coordinates.h projets2appli/fish.h projets2appli/Deserialisation.h projets2appli/grid.h projets2appli/gridObject.h projets2appli/leaderboards.h projets2appli/leurres.h projets2appli/menu.h projets2appli/Poisson.h
SOURCES     += projets2appli/appliS2.cpp projets2appli/fish.cpp projets2appli/grid.cpp projets2appli/Leaderboards.cpp projets2appli/leurres.cpp projets2appli/menu.cpp projets2appli/Poisson.cpp projets2appli/SerialPort.cpp
INCLUDEPATH += ../GraphicusGUI
LIBS        += ../GraphicusGUI/graphicusGUI.lib
QT          += widgets

