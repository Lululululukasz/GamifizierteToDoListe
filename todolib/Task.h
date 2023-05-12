//
// Created by helen on 12.05.2023.
//

#ifndef PIC_AEM_PROJEKT_TASK_H
#define PIC_AEM_PROJEKT_TASK_H

#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string id;
    bool done {false};
    // TODO datetimes

public:
    string name;
    string description;

    Task(string n, string d);
    bool getDoneStatus();
    void setAsDone();
    void setAsUndone();

};


#endif //PIC_AEM_PROJEKT_TASK_H
