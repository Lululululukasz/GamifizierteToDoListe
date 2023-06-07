#ifndef PIC_AEM_PROJEKT_GLOBALS_H
#define PIC_AEM_PROJEKT_GLOBALS_H
#include <QtCore/QString>
QString changeHomepath();

/**
 * Class for all global static variables
 */
class Globals{
public:
    /**
     * homepath is the rootpath of the installfolder
     */
    const static inline QString homepath = changeHomepath();

    /**
     * soundpath is the rootpath of the sounds for simpler access
     */
    const static inline QString soundpath = homepath + "/resources/sounds/";

    /**
     * savespath is the rootpath of the savestates for simpler access
     */
    const static inline QString savespath = homepath + "/saves/";

    /**
     * debug variable if debugmessages should be printed
     */
    static bool inline debug = false;
};



#endif //PIC_AEM_PROJEKT_GLOBALS_H
