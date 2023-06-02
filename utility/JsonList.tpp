#ifndef PIC_AEM_PROJEKT_JSONLIST_TPP
#define PIC_AEM_PROJEKT_JSONLIST_TPP
#include <list>
#include <string>

#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QString>
#include <QtCore/QFile>

template<typename T>
struct JsonList : std::list<T> {
    QJsonArray toJson () {
        QJsonArray jsonArray;
        for (T &v: *this) {
            jsonArray.append(v.toJson());
        }
        return jsonArray;
    }
};


#endif PIC_AEM_PROJEKT_JSONLIST_TPP