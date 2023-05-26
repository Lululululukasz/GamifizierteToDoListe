#include <QDir>
#include "Globals.h"
#include <QtCore/QJsonArray>


QString changeHomepath() {
    QString homepath = QDir::currentPath();
    int binTrue = homepath.indexOf("/bin", homepath.length() - 4);
    if (binTrue != -1) {
        homepath.remove(binTrue, 4);
    }
    int debugDirectory = homepath.indexOf("/cmake-build-debug", homepath.length() - 18);
    if (debugDirectory != -1) {
        homepath.remove(debugDirectory, 18);
    }
    return homepath;
}
