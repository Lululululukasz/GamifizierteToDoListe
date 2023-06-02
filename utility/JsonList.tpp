#ifndef PIC_AEM_PROJEKT_JSONLIST_TPP
#define PIC_AEM_PROJEKT_JSONLIST_TPP
#include <list>
#include <string>

#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QString>
#include <QtCore/QFile>

/**
 * templateclass expanding the std::list, with the function of converting a list to a QJsonarray
 * @tparam T type
 */
template<typename T>
struct JsonList : std::list<T> {
    /**
     * Function to convert a list to a QJsonArray
     * @return QJsonArray
     */
    QJsonArray toJson () {
        QJsonArray jsonArray;
        for (T &v: *this) {
            jsonArray.append(v.toJson());
        }
        return jsonArray;
    }
};


#endif PIC_AEM_PROJEKT_JSONLIST_TPP