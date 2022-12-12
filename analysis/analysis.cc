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
#include "TText.h"

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
/*  Float_t         ene;
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
/*  TBranch        *b_ene;   //!
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
   	
/*  ch1->SetBranchAddress("ene", &ene, &b_ene);
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

    TNtuple* n_jpsi = new TNtuple ( "n_jpsi", "Invariant Mass", "mass");
    //TH1F *h_jpsi = new TH1F ( "h_jpsi", "Invariant Mass", 140, 2.7, 3.4 );

    int count_sigregion = 0, count_sideband = 0;
   	int NEvents = ch1->GetEntries();

   	for (int k = 0; k < NEvents; k++)
   	{
   		ch1->GetEntry(k);
   		int NParticles = iloop;

   		for (int i = 0; i < NParticles; i++)
   		{
			if (mas > 2.8 && mas < 3.2)
                	n_jpsi -> Fill(mas);
   		}
   	}

   	//ROOFIT

   	//Observable
    RooRealVar mass("mass","invariant mass (GeV)", 2.8, 3.2);
    
    //Signal Model
    RooRealVar mean("mean","mean", 3.1, 2.8, 3.2 );
    RooRealVar width("width","width", 0.1, 0, 5);
	RooGaussian sig("gaussian","signal pdf",mass,mean,width);

	//Background model
    RooRealVar c1("c1","coefficient #1",0, -10, 10.);
    RooRealVar c2("c2","coefficient #2",0, -10, 10.);
    RooRealVar c3("c3","coefficient #3",0, -10, 10.);
    RooChebychev bkg("background pdf","background pdf",mass,RooArgList(c1, c2, c3));
    
    //Signal to Noise Ratio
    RooRealVar fsig("fsig", "signal fraction", 0, 0., 1.); 
    
    //model(mass) = fsig*sig(mass) + (1-fsig)*bkg(mass);
    RooAddPdf model("model", "model", RooArgList(sig, bkg), fsig); 
    
 /*   //Original Gaussian

    RooRealVar mean_or("mean_or", "mean_or", 3.0969, 2.9, 3.2);
    RooRealVar width_or("width_or", "width_or", 0.00929, 0, 5);
    RooGaussian sig_or("gaussian_or", "gaussian_or", mass, mean_or, width_or);
*/
    RooDataSet *data = new RooDataSet("data","data",n_jpsi,RooArgSet(mass));
    
    model.fitTo(*data);
    
    TCanvas* canvas = new TCanvas("c1","c1",600,400);

    RooPlot* frame = mass.frame(Title("PDF + Data"));

    //  Adding parameters' box on the plot
    RooArgSet params_model = RooArgList(mean, width);
    model.paramOn(frame, Parameters(params_model), Layout(0.1, 0.5, .22));
    data->statOn(frame, Layout(0.1, 0.5, .9));
    
    data->plotOn(frame, Binning(100));
    model.plotOn(frame,LineWidth(3));

    frame->Draw(); 	
}


void analysis()
{
	chain();
}


/*
   	int entries = ch1->GetEntries();
   	TH1F *hist = new TH1F("hist", "mass", 500, 2.5, 3.5);

   	for(int i = 0; i < entries; i++)
   	{
   		ch1->GetEntry(i);
   		hist->Fill(mas);
   	}

   	TCanvas *c1 = new TCanvas();
   	hist->Draw();
*/