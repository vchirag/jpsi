void chain()
{
	// Declaring a TChain by the name ch1
	TChain *ch1 = new TChain("h1");

	// Adding entries to the chain
	ch1->Add("data/mode1-script-*.root");

	 // Declaration of leaf types
   	Float_t         mas;
   	Float_t         ene;
   	Float_t         px;
   	Float_t         py;
   	Float_t         pz;
   	Float_t         pj;
   	Float_t         etag;
   	Float_t         mascf;

   	// List of branches
   	TBranch        *b_mas;   //!
   	TBranch        *b_ene;   //!
   	TBranch        *b_px;   //!
   	TBranch        *b_py;   //!
   	TBranch        *b_pz;   //!
   	TBranch        *b_pj;   //!
   	TBranch        *b_etag;   //!
   	TBranch        *b_mascf;   //!

   	ch1->SetBranchAddress("mas", &mas, &b_mas);
   	ch1->SetBranchAddress("ene", &ene, &b_ene);
   	ch1->SetBranchAddress("px", &px, &b_px);
   	ch1->SetBranchAddress("py", &py, &b_py);
   	ch1->SetBranchAddress("pz", &pz, &b_pz);
   	ch1->SetBranchAddress("pj", &pj, &b_pj);
   	ch1->SetBranchAddress("etag", &etag, &b_etag);
   	ch1->SetBranchAddress("mascf", &mascf, &b_mascf);


   	int entries = ch1->GetEntries();
   	TH1F *h_jpsi = new TH1F("h_jpsi", "mass", 500, 2.5, 3.5);

   	for (int idx = 0; idx < entries; idx++)
   	{
   		ch1 -> GetEntry (idx);
   	}

}


void mc_analysis()
{
	chain();
}