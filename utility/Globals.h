#ifndef PIC_AEM_PROJEKT_GLOBALS_H
#define PIC_AEM_PROJEKT_GLOBALS_H
QString changeHomepath();

class globals{
public:
    const static inline QString homepath = changeHomepath();
};



#endif //PIC_AEM_PROJEKT_GLOBALS_H
