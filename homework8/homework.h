#ifndef __HOMEWORK_H__
#define __HOMEWORK_H__

#include <TObject.h>

class homework : public TObject {
    public:
        homework();
        homework(Int_t variable);
        virtual ~homework();

        Double_t Magnitude() const;

        Double_t px; 
        Double_t py;
        Double_t pz;

    private: 

        ClassDef(homework, 1);
};

#endif // __HOMEWORK_H__
