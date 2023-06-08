#ifndef PIC_AEM_PROJEKT_JSON_H
#define PIC_AEM_PROJEKT_JSON_H

#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QDebug>
#include <string>

#include "Globals.h"


class Json {
public:
    /**
     * Function to write a given QJsonObject to a json-file
     * @param jsonObject
     * @return bool if the writing succeeded
     */
    static bool writeJsonObjectToFile(QJsonObject jsonObject, std::string subsavepathString) {
        QDir savepath(Globals::savespath);
        QDir subsavepath(Globals::savespath + subsavepathString.c_str());
        if (!savepath.exists()) {
            QDir().mkdir(Globals::savespath);
        }
        if (!subsavepath.exists()) {
            QDir().mkdir(Globals::savespath + subsavepathString.c_str());
        }
        QJsonDocument document;
        document.setObject(jsonObject);
        QByteArray bytes = document.toJson(QJsonDocument::Indented);
        QString filepath = Globals::savespath + subsavepathString.c_str() + jsonObject.value("id").toString() + ".json";
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QTextStream iStream(&file);
            iStream.setCodec("utf-8");
            iStream << bytes;
            file.close();
            return true;
        } else {
            if (Globals::debug) {
                qWarning() << "file open failed: " << Globals::savespath << subsavepathString.c_str() << jsonObject.value("id").toString() << ".json";
            }
            return false;
        }
    }

    /**
     * read all jsonfiles from the saves directory
     * @return QJsonArray of every json-file
     */
    static QJsonArray getAllSaves(QString subsavepath) {
        QString path = Globals::savespath + subsavepath;
        QDir directory(path);
        QJsonArray saves;
        QStringList savesFilenames = directory.entryList(QStringList() << "*.json", QDir::Files);
                foreach(QString filename, savesFilenames) {
                saves.append(readJsonFile(filename, subsavepath));
            }
        return saves;
    }

    /**
     * read a single jsonfile and return it's jsonobject as QJsonFile
     * @param filename name of the file
     * @return the read json-object. return a empty jsonobject if failed
     */
    static QJsonObject readJsonFile(QString &filename, QString &subsavepath) {
        QFile file(Globals::savespath + subsavepath + filename);
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

    static bool deleteJson (QString &&filename) {
        QFile file (Globals::savespath + filename);
        return file.remove();
    }
};


#endif //PIC_AEM_PROJEKT_JSON_H
