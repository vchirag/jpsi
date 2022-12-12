//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct  1 16:54:35 2021 by ROOT version 6.24/02
// from TTree h1/jpsi
// found on file: datapsiskim-61-1.root
//////////////////////////////////////////////////////////

#ifndef testclass_h
#define testclass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class testclass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         mas;
   Float_t         ene;
   Float_t         px;
   Float_t         py;
   Float_t         pz;
   Float_t         pj;
   Float_t         etag;
   Float_t         mascf;
   Float_t         exp;
   Float_t         run;
   Float_t         evtno;
   Float_t         iloop;
   Float_t         pxm;
   Float_t         pym;
   Float_t         pzm;
   Float_t         pem;
   Float_t         pxp;
   Float_t         pyp;
   Float_t         pzp;
   Float_t         pep;

   // List of branches
   TBranch        *b_mas;   //!
   TBranch        *b_ene;   //!
   TBranch        *b_px;   //!
   TBranch        *b_py;   //!
   TBranch        *b_pz;   //!
   TBranch        *b_pj;   //!
   TBranch        *b_etag;   //!
   TBranch        *b_mascf;   //!
   TBranch        *b_exp;   //!
   TBranch        *b_run;   //!
   TBranch        *b_evtno;   //!
   TBranch        *b_iloop;   //!
   TBranch        *b_pxm;   //!
   TBranch        *b_pym;   //!
   TBranch        *b_pzm;   //!
   TBranch        *b_pem;   //!
   TBranch        *b_pxp;   //!
   TBranch        *b_pyp;   //!
   TBranch        *b_pzp;   //!
   TBranch        *b_pep;   //!

   testclass(TTree *tree=0);
   virtual ~testclass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef testclass_cxx
testclass::testclass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("datapsiskim-61-1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("datapsiskim-61-1.root");
      }
      f->GetObject("h1",tree);

   }
   Init(tree);
}

testclass::~testclass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t testclass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t testclass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void testclass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("mas", &mas, &b_mas);
   fChain->SetBranchAddress("ene", &ene, &b_ene);
   fChain->SetBranchAddress("px", &px, &b_px);
   fChain->SetBranchAddress("py", &py, &b_py);
   fChain->SetBranchAddress("pz", &pz, &b_pz);
   fChain->SetBranchAddress("pj", &pj, &b_pj);
   fChain->SetBranchAddress("etag", &etag, &b_etag);
   fChain->SetBranchAddress("mascf", &mascf, &b_mascf);
   fChain->SetBranchAddress("exp", &exp, &b_exp);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("evtno", &evtno, &b_evtno);
   fChain->SetBranchAddress("iloop", &iloop, &b_iloop);
   fChain->SetBranchAddress("pxm", &pxm, &b_pxm);
   fChain->SetBranchAddress("pym", &pym, &b_pym);
   fChain->SetBranchAddress("pzm", &pzm, &b_pzm);
   fChain->SetBranchAddress("pem", &pem, &b_pem);
   fChain->SetBranchAddress("pxp", &pxp, &b_pxp);
   fChain->SetBranchAddress("pyp", &pyp, &b_pyp);
   fChain->SetBranchAddress("pzp", &pzp, &b_pzp);
   fChain->SetBranchAddress("pep", &pep, &b_pep);
   Notify();
}

Bool_t testclass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void testclass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t testclass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef testclass_cxx
