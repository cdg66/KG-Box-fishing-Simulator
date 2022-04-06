TEMPLATE     = vcapp
TARGET       = projets2appli
CONFIG      += warn_on qt debug windows console
HEADERS     += projets2appli/coordinates.h projets2appli/fish.h projets2appli/Deserialisation.h projets2appli/grid.h projets2appli/gridObject.h projets2appli/leaderboards.h projets2appli/leurres.h projets2appli/menu.h projets2appli/json.hpp projets2appli/SerialPort.hpp projets2appli/Leaderboards.json projets2appli/monInterface.h
SOURCES     += projets2appli/appliS2.cpp projets2appli/fish.cpp projets2appli/grid.cpp projets2appli/Leaderboards.cpp projets2appli/leurres.cpp projets2appli/menu.cpp projets2appli/SerialPort.cpp projets2appli/monInterface.cpp
INCLUDEPATH += ../GraphicusGUI
LIBS        += ../GraphicusGUI/GraphicusGUI.lib
QT          += widgets

