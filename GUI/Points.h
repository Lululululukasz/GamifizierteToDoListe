#ifndef PIC_AEM_PROJEKT_POINTS_H
#define PIC_AEM_PROJEKT_POINTS_H

class Points{
public:
private:
    Points(){};

    unsigned int nPoints;
    unsigned int dPoints;
public:
    static Points& getinstance();
    Points(Points const&) = delete;
    void operator=(Points const&) = delete;

    //Adds and sub
    void addPoints(unsigned int newpoints, double multi, char nORd);
    void subPoints(unsigned int leavepoints, char nORd);

    unsigned int getNPoints();
    unsigned int getDPoints();
    void setNPoints(unsigned int newpoints);
    void setDPoints(unsigned int newpoints);
};


#endif //PIC_AEM_PROJEKT_POINTS_H
