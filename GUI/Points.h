#ifndef PIC_AEM_PROJEKT_POINTS_H
#define PIC_AEM_PROJEKT_POINTS_H


class Points {
private:
    Points(unsigned int np, unsigned int dp);
    unsigned int nPoints;
    unsigned int dPoints;
public:
    void addPoints(unsigned int newpoints, double multi, char nORd);
    void subPoints(unsigned int leavepoints, char nORd);

    unsigned int * getNPoints();
    unsigned int * getDPoints();
};


#endif //PIC_AEM_PROJEKT_POINTS_H
