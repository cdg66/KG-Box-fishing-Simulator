TEMPLATE     = vcapp
TARGET       = graphicus-03
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h canevas.h coordonnee.h couche.h forme.h
SOURCES     += graphicus-03.cpp monInterface.cpp canevas.cpp couche.cpp forme.cpp
INCLUDEPATH += ../GraphicusGUI
LIBS        += ../GraphicusGUI/graphicusGUI.lib
QT          += widgets