#ifndef PIC_AEM_PROJEKT_GLOBALS_H
#define PIC_AEM_PROJEKT_GLOBALS_H
#include <QString>
QString changeHomepath();

/**
 * Class for all global static variables
 */
class Globals{
public:
    const static inline QString homepath = changeHomepath();
    const static inline QString soundpath = homepath + "/resources/sounds/";
    const static inline QString savespath = homepath + "/resources/saves/";
};



#endif //PIC_AEM_PROJEKT_GLOBALS_H
