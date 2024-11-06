#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include "homework.h"
#include <iostream>

void read(){
    homework *Object = new homework();
    TFile *file = TFile::Open("tree_file.root");
    TTree *tree = (TTree*)file->Get("tree");

    tree->SetBranchAddress("px", &(Object->px));
    tree->SetBranchAddress("py", &(Object->py));
    tree->SetBranchAddress("pz", &(Object->pz));

    TH2F *histogram = new TH2F("histogram", "2D Histogram;px;py", 50, 0.0, 10.0, 50, -5.0, 5.0);
    
    Int_t N = tree->GetEntries();
    
    for (Int_t i{0}; i<N; i++){ // loop over the whole tree
        tree->GetEntry(i);
        //std::cout << "Entry " << i << ": px = " << Object->px << ", py = " << Object->py << std::endl;
        histogram->Fill(Object->px, Object->py);

    }

    histogram->Draw();

    file->Close();
    delete Object;
}