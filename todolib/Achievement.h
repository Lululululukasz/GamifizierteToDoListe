//
// Created by trashpanda on 26.05.23.
//

#ifndef PIC_AEM_PROJEKT_ACHIEVEMENT_H
#define PIC_AEM_PROJEKT_ACHIEVEMENT_H

#include <string>

namespace todolib {

    class Achievement {
    private:
        std::string id;
        bool done{false};

    public:
        const std::string name;
        const std::string description;

        // Constructor
        explicit Achievement(const std::string &name, const std::string &description);

        std::string getID();

        bool getDoneStatus() const;

        void setAsDone();
    };

} // todolib

#endif //PIC_AEM_PROJEKT_ACHIEVEMENT_H
