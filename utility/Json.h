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
            qWarning() << "file open failed: " << Globals::savespath << "test.json";
            return false;
        }
    }

    static QJsonArray getAllSaves() {
        QDir directory(Globals::savespath);
        QJsonArray saves;
        QStringList savesFilenames = directory.entryList(QStringList() << "*.json", QDir::Files);
                foreach(QString filename, savesFilenames) {
                saves.append(readJsonFile(filename));
            }
        return saves;
    }

    static QJsonObject readJsonFile(QString filename) {
        QFile file(Globals::savespath + filename);
        if (file.open(QIODevice::ReadOnly)) {
            QString val = file.readAll();
            file.close();

            QJsonParseError jsonError;
            QJsonDocument document = QJsonDocument::fromJson(val.toUtf8(), &jsonError);
            if (jsonError.error != QJsonParseError::NoError) {
                qWarning() << "fromJson failed: " << jsonError.errorString();
                return QJsonObject();
            }
            if (document.isObject()) {
                QJsonObject jsonObj = document.object();
                return jsonObj;
            }
        }
        return QJsonObject();
    }

    void readJson1() {
        QString val;
        QFile file;
        file.setFileName(Globals::savespath + "test.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
        qWarning() << val;
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();
        QJsonValue value = sett2.value(QString("appName"));
        qWarning() << value;
        QJsonObject item = value.toObject();
        qWarning().noquote() << "\nQJsonObject of description: " << item;

        /* in case of string value get value and convert into string*/
        qWarning().noquote() << "\nQJsonObject[appName] of description: " << item["description"];
        QJsonValue subobj = item["description"];
        qWarning() << subobj.toString();

        /* in case of array get array and convert into string*/
        qWarning().noquote() << "\nQJsonObject[appName] of value: " << item["imp"];
        QJsonArray test = item["imp"].toArray();
        qWarning() << test[1].toString();
    };

    bool writeToFile() {
        return true;
    };
};


#endif //PIC_AEM_PROJEKT_JSON_H
