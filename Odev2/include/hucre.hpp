#ifndef HUCRE_HPP
#define HUCRE_HPP
#include<iostream>
using namespace std;


class Hucre
{
private:
    int dnaUzunluk;
public:
    Hucre(int);
    Hucre(Hucre&);
    int getDnaUzunluk() const;
    void mutation(Hucre&);
    ~Hucre();
};
#endif
