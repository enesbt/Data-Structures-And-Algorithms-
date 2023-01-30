#ifndef KONTROL_HPP
#define KONTROL_HPP


#include "organizma.hpp"

class Kontrol
{
    public:
        bool dengeliMi(Organ*);
        bool mutasyonControl(Organ*);
        bool mutasyonUgradiMi(Organ*);              
};
#endif