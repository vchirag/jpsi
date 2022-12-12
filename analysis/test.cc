#include "TFile.h"
#include "TTree.h"
#include "TNtuple.h"
#include "TCanvas.h"
#include "TMath.h"
#include "RooRealVar.h"
#include "RooGaussian.h"
#include "RooAddPdf.h"
#include "RooDataSet.h"
#include "RooChebychev.h"
#include "RooPlot.h"
#include "RooVoigtian.h"

using namespace RooFit;
void chain()
{
	// Declaring a TChain by the name ch1
	TChain *ch1 = new TChain("h1");

	// Adding entries to the chain
	ch1->Add("datapsiskim-61-*.root");

	 // Declaration of leaf types
   	Float_t         iloop;
   	Float_t         mas;
   	Float_t         pxm;
   	Float_t         pym;
   	Float_t         pzm;
   	Float_t         pem;
    Float_t         ene;
/*  
   	Float_t         px;
   	Float_t         py;
   	Float_t         pz;
   	Float_t         pj;
   	Float_t         etag;
   	Float_t         mascf;
   	Float_t         exp;
   	Float_t         run;
   	Float_t         evtno;
   	Float_t         pxp;
   	Float_t         pyp;
   	Float_t         pzp;
   	Float_t         pep;		
*/

   	// List of branches
   	TBranch        *b_iloop;   //!
   	TBranch        *b_mas;   //!
	TBranch        *b_pxm;   //!
   	TBranch        *b_pym;   //!
   	TBranch        *b_pzm;   //!
   	TBranch        *b_pem;   //!
    TBranch        *b_ene;   //!
/*  
   	TBranch        *b_px;   //!
   	TBranch        *b_py;   //!
   	TBranch        *b_pz;   //!
   	TBranch        *b_pj;   //!
   	TBranch        *b_etag;   //!
   	TBranch        *b_mascf;   //!
   	TBranch        *b_exp;   //!
   	TBranch        *b_run;   //!
   	TBranch        *b_evtno;   //!
   	TBranch        *b_pxp;   //!
   	TBranch        *b_pyp;   //!
   	TBranch        *b_pzp;   //!
   	TBranch        *b_pep;   //!	
*/

   	ch1->SetBranchAddress("iloop", &iloop, &b_iloop);
   	ch1->SetBranchAddress("mas", &mas, &b_mas);
	ch1->SetBranchAddress("pxm", &pxm, &b_pxm);
   	ch1->SetBranchAddress("pym", &pym, &b_pym);
   	ch1->SetBranchAddress("pzm", &pzm, &b_pzm);
   	ch1->SetBranchAddress("pem", &pem, &b_pem);
    ch1->SetBranchAddress("ene", &ene, &b_ene);
   	
/*  
   	ch1->SetBranchAddress("px", &px, &b_px);
   	ch1->SetBranchAddress("py", &py, &b_py);
   	ch1->SetBranchAddress("pz", &pz, &b_pz);
   	ch1->SetBranchAddress("pj", &pj, &b_pj);
   	ch1->SetBranchAddress("etag", &etag, &b_etag);
   	ch1->SetBranchAddress("mascf", &mascf, &b_mascf);
   	ch1->SetBranchAddress("exp", &exp, &b_exp);
   	ch1->SetBranchAddress("run", &run, &b_run);
   	ch1->SetBranchAddress("evtno", &evtno, &b_evtno);
   	ch1->SetBranchAddress("pxp", &pxp, &b_pxp);
   	ch1->SetBranchAddress("pyp", &pyp, &b_pyp);
   	ch1->SetBranchAddress("pzp", &pzp, &b_pzp);
   	ch1->SetBranchAddress("pep", &pep, &b_pep);	
*/

    int entries = ch1->GetEntries();
    TH1F *hist = new TH1F("hist", "energy; energy (GeV); entries/0.017", 500, 1.5, 10);

    for(int i = 0; i < entries; i++)
    {
        ch1->GetEntry(i);
        hist->Fill(ene);
    }

    TCanvas *c1 = new TCanvas();
    hist->Draw();
   	}

   	
void test()
{
	chain();
}


/*

    TFile ofile("n_jpsi.root", "RECREATE");
    n_jpsi -> Write();
    ofile.Close();
*/