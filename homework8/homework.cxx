#include <homework.h>
#include <TMath.h>
#include <TRandom.h>

ClassImp(homework)


homework::homework() : px(0), py(0), pz(0)
{   
}

homework::homework(Int_t variable) : px(0), py(0), pz(0)
{
}

homework::~homework()
{
}

Double_t homework::Magnitude() const {
    return TMath::Sqrt(px * px + py * py + pz * pz);
}