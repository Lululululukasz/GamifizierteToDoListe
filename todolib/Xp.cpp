//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include <QtCore/QJsonObject>
#include "Xp.h"
#include "../../utility/Json.h"


using namespace todolib;
using namespace std;

Xp::Xp() {
    QJsonArray xpArray = Json::getAllSaves("xp/");
            foreach(QJsonValue xpValue, xpArray) {
            if (xpValue.isObject()) {
                QJsonObject taskObject = xpValue.toObject();
                QStringList keys = taskObject.keys();
                // Check if the QJsonObject is convertable to a task
                int checksum = 0;
                        foreach(QString key, keys) {
                        if (key == "id") {
                            checksum += 1;
                        } else if (key == "xptrueNumber") {
                            checksum += 2;
                        } else if (key == "levelNumber") {
                            checksum += 4;
                        }
                    }
                if (checksum == 7) {
                    this->levelNumber = static_cast<unsigned int>(taskObject.value("levelNumber").toInt());
                    this->xptrueNumber = taskObject.value("xptrueNumber").toInt();
                }
            }
        }

}

void Xp::setlevelNumber(unsigned int level) {
    this->levelNumber = level;
    saveToJson();
}

void Xp::setxptrueNumber(int xp) {
    this->xptrueNumber = xp;
    saveToJson();
}

void Xp::saveToJson() {
    QJsonObject json;
    json.insert("id", "xp");
    json.insert("xptrueNumber", this->xptrueNumber);
    json.insert("levelNumber", static_cast<int>(this->levelNumber));
    Json::writeJsonObjectToFile(json, "xp/");
}
