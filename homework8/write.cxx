#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include "homework.h"

void write(){

    homework *Object = new homework(); //initialize object
    TFile *file = new TFile("tree_file.root", "RECREATE"); //root file to save tree
    TTree *tree = new TTree("tree", "Tree with objects from homework"); //create TTree

    tree->Branch("px", &(Object->px), "px/D");
    tree->Branch("py", &(Object->py), "py/D");
    tree->Branch("pz", &(Object->pz), "pz/D");

    Int_t nEvents = 1000;
    for (Int_t i{0}; i<nEvents; i++){
        Object->px = gRandom->Gaus(0,.02);
        Object->py = gRandom->Gaus(0,.02);
        Object->pz = gRandom->Gaus(0,.02);

        tree->Fill();

    } 
    
    tree->Write();
    file->Close();

    delete Object;
    delete file;

}

