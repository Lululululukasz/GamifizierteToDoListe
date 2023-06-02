#ifndef PIC_AEM_PROJEKT_JSON_H
#define PIC_AEM_PROJEKT_JSON_H

#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QDir>

#include "Globals.h"


class Json {
public:
    /**
     * Function to write a given QJsonObject to a json-file
     * @param jsonObject
     * @return bool if the writing succeeded
     */
    static bool writeJsonObjectToFile(QJsonObject jsonObject) {
        QJsonDocument document;
        document.setObject(jsonObject);
        QByteArray bytes = document.toJson(QJsonDocument::Indented);
        QFile file(Globals::savespath + jsonObject.value("id").toString() + ".json");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QTextStream iStream(&file);
            iStream.setCodec("utf-8");
            iStream << bytes;
            file.close();
            return true;
        } else {
            if (Globals::debug) {
                qWarning() << "file open failed: " << Globals::savespath << jsonObject.value("id").toString() << ".json";
            }
            return false;
        }
    }

    /**
     * read all jsonfiles from the saves directory
     * @return QJsonArray of every json-file
     */
    static QJsonArray getAllSaves() {
        QDir directory(Globals::savespath);
        QJsonArray saves;
        QStringList savesFilenames = directory.entryList(QStringList() << "*.json", QDir::Files);
                foreach(QString filename, savesFilenames) {
                saves.append(readJsonFile(filename));
            }
        return saves;
    }

    /**
     * read a single jsonfile and return it's jsonobject as QJsonFile
     * @param filename name of the file
     * @return the read json-object. return a empty jsonobject if failed
     */
    static QJsonObject readJsonFile(QString filename) {
        QFile file(Globals::savespath + filename);
        if (file.open(QIODevice::ReadOnly)) {
            QString val = file.readAll();
            file.close();

            QJsonParseError jsonError;
            QJsonDocument document = QJsonDocument::fromJson(val.toUtf8(), &jsonError);
            if (jsonError.error != QJsonParseError::NoError) {
                if (Globals::debug) {
                    qWarning() << "fromJson failed: " << jsonError.errorString();
                }
                return QJsonObject();
            }
            if (document.isObject()) {
                QJsonObject jsonObj = document.object();
                return jsonObj;
            }
        }
        return QJsonObject();
    }
};


#endif //PIC_AEM_PROJEKT_JSON_H
