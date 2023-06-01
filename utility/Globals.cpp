#include <QDir>
#include "Globals.h"
#include <QtCore/QJsonArray>

/**
 * Function to shorten the currentPath depending on where the Program is started from.
 * @return {homepath} the shortend currentPath
 */
QString changeHomepath() {
    QString homepath = QDir::currentPath();
    // Path in the deployment, where the executable is in.
    // This is the case, when the Executable is started directly in folder instead of the windows-menu
    int binTrue = homepath.indexOf("/bin", homepath.length() - 4);
    if (binTrue != -1) {
        homepath.remove(binTrue, 4);
    }
    // Path in windows-debugging, where the build executable is started from, when no working directory is declared
    int debugDirectory = homepath.indexOf("/cmake-build-debug", homepath.length() - 18);
    if (debugDirectory != -1) {
        homepath.remove(debugDirectory, 18);
    }
    return homepath;
}
