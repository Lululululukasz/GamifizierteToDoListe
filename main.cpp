#include "todolib/todolib.h"
#include "GUI/ToDoListWindow.h"

#include <QApplication>

#include <QFile>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

void readJson()
{
    QString val;
    QFile file;
    file.setFileName(QDir::currentPath() + "/test.json");
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
}

int main(int argc, char** argv) {

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    todolib::ToDoList todoList;

    ToDoListWindow window {todoList};

    readJson();

    // Starten der QApplication
    return app.exec();

}
