
#include "EResShowerProf.hh"


void EResShowerProf::EResAndProfile(std::string pth){

        TCanvas * ca1=new TCanvas("c2p","c2p");
        Cevent=new B4ROOTEvent();



        Int_t Estart=50;
        Double_t x[11];
        Double_t eres[11];

        std::string fileName;

        for(Int_t i=0; i<10; i++) {

                fileName=pth+"/gamma"+std::to_string(Estart)+"MeV_0.4:0.4_.root";
                std::unique_ptr<TChain> ch1(new TChain("eventTree"));
                ch1->Add(fileName.c_str());
                ch1->Draw("");

                std::cout<<"hello"<<std::endl;
                std::unique_ptr<TTree> EcalTree(ch1->GetTree());
                Int_t nofEvents=EcalTree->GetEntries();



                EcalTree->SetBranchAddress("EventBranch", &Cevent);



                std::unique_ptr<TCanvas> profileC(new TCanvas("profileC", "profileC"));
                std::unique_ptr<TH1D> profile(new TH1D("showerprofile", "showerprofile",100, 0, 100));

                std::unique_ptr<TH1D> edepdistribution(new TH1D("edep","edep",100,0,Estart));

                for(Int_t j=0; j<nofEvents; j++) {

                        EcalTree->GetEntry(j); //grab event from tree
                        Double_t Eges = Cevent->GapEnergy();

                        edepdistribution->Fill(Eges);
                        Int_t cnh = Cevent->NHits();
                        Double_t integral;

                        for(Int_t i=0; i<Cevent->NumberOfInnerLayers(); i++) { //loop over all inner layers in event
                                std::string cp="InnerGapLV";

                                for(Int_t j =0; j<cnh; j++) { //loop over all hits in layer i

                                        //std::cout<<Cevent->Hit(j)->PhotNr()<<std::endl;
                                        Double_t edep= Cevent->Hit(j)->EnergyDeposit();
                                        if(Cevent->Hit(j)->Z()==i && Cevent->Hit(j)->CalorimeterPart()==cp) {

                                                profile->Fill(i, edep);

                                        } //fill histogram with hits of layer i
                                }
                                //std::cout<<photonNR<<" : "<<std::endl;


                        }
                        for(Int_t i=0; i<Cevent->NumberOfOuterLayers(); i++) { //loop over all outer layers in event
                                std::string cp="OuterGapLV";

                                for(Int_t j =0; j<cnh; j++) { //loop over all hits in laver i

                                        Double_t edep= Cevent->Hit(j)->EnergyDeposit();
                                        if(Cevent->Hit(j)->Z()==i && Cevent->Hit(j)->CalorimeterPart()==cp) {

                                                profile->Fill(i+Cevent->NumberOfInnerLayers(), edep);

                                        } //fill histogram with hits of layer i
                                }

                        } //end of event

                }
                eres[i]=(edepdistribution->GetRMS(1)/edepdistribution->GetMean());

                EcalTree->GetEntry(0);
                std::unique_ptr<TLine> line_x(new TLine(Cevent->NumberOfInnerLayers()-1,0,Cevent->NumberOfInnerLayers()-1,profile->GetMaximum()));

                profileC->cd(0);
                profile->Draw();
                line_x->Draw();
                profile->GetXaxis()->SetTitle("Layerindex");
                profile->GetYaxis()->SetTitle("Energy of Run[MeV]");

                std::string path=pth+"/Showerprofile"+std::to_string(Estart)+".C";
                profileC->Print(path.c_str());
                path=pth+"/Showerprofile"+std::to_string(Estart)+".pdf";
                profileC->Print(path.c_str());



                x[i]=Estart;
                Estart+=100;
        }
        Estart=1500;

        fileName=pth+"/gamma"+std::to_string(Estart)+"MeV_.4:.4_.root";
        std::unique_ptr<TChain> ch1(new TChain("eventTree"));
        ch1->Add(fileName.c_str());
        ch1->Draw("");

        std::unique_ptr<TTree> EcalTree(ch1->GetTree());
        Int_t nofEvents=EcalTree->GetEntries();

        EcalTree->SetBranchAddress("EventBranch", &Cevent);

        std::unique_ptr<TCanvas> profileC(new TCanvas("profileC", "profileC"));
        std::unique_ptr<TH1D> profile(new TH1D("showerprofile", "showerprofile",100, 0, 100));

        std::unique_ptr<TH1D> edepdistribution(new TH1D("edep","edep",100,0,Estart));

        for(Int_t j=0; j<nofEvents; j++) {

                EcalTree->GetEntry(j); //grab event from tree
                Double_t Eges = Cevent->GapEnergy();
                edepdistribution->Fill(Eges);
                Int_t cnh = Cevent->NHits();
                Double_t integral;

                for(Int_t i=0; i<Cevent->NumberOfInnerLayers(); i++) { //loop over all inner layers in event
                        std::string cp="InnerGapLV";

                        for(Int_t j =0; j<cnh; j++) { //loop over all hits in layer i

                                //std::cout<<Cevent->Hit(j)->PhotNr()<<std::endl;
                                Double_t edep= Cevent->Hit(j)->EnergyDeposit();
                                if(Cevent->Hit(j)->Z()==i && Cevent->Hit(j)->CalorimeterPart()==cp) {

                                        profile->Fill(i, edep);

                                } //fill histogram with hits of layer i
                        }
                        //std::cout<<photonNR<<" : "<<std::endl;


                }
                for(Int_t i=0; i<Cevent->NumberOfOuterLayers(); i++) { //loop over all outer layers in event
                        std::string cp="OuterGapLV";

                        for(Int_t j =0; j<cnh; j++) { //loop over all hits in laver i

                                Double_t edep= Cevent->Hit(j)->EnergyDeposit();
                                if(Cevent->Hit(j)->Z()==i && Cevent->Hit(j)->CalorimeterPart()==cp) {

                                        profile->Fill(i+Cevent->NumberOfInnerLayers(), edep);

                                } //fill histogram with hits of layer i
                        }

                } //end of event

        }
        eres[10]=(edepdistribution->GetRMS(1)/edepdistribution->GetMean());

        EcalTree->GetEntry(0);
        std::unique_ptr<TLine> line_x(new TLine(Cevent->NumberOfInnerLayers()-1,0,Cevent->NumberOfInnerLayers()-1,profile->GetMaximum()));

        profileC->cd(0);
        profile->Draw();
        line_x->Draw();
        profile->GetXaxis()->SetTitle("Layerindex");
        profile->GetYaxis()->SetTitle("Energy of Run[MeV]");
        std::string path=pth+"/Showerprofile"+std::to_string(Estart)+".C";
        profileC->Print(path.c_str());
        path=pth+"/Showerprofile"+std::to_string(Estart)+".pdf";
        profileC->Print(path.c_str());

        ch1->Reset();

        x[10]=Estart;

        std::unique_ptr<TGraph> Eres(new TGraph(11, x, eres));

        TF1 * resolution = new TF1("resolution", "sqrt(([0] * [0] / x) + ([2]*[2])  + ([1]*[1]/(x*x)))");

        ca1->cd(0);
        //Eres->Fit(resolution);
        Eres->GetXaxis()->SetTitle("Energy[MeV]");
        Eres->GetYaxis()->SetTitle("#frac{#sigma}{E_{mean}}");
        Eres->GetYaxis()->SetTitleOffset(1.2);
        gStyle->SetOptFit(111111111);
        Eres->SetMarkerStyle(23);
        Eres->SetMarkerSize(1.1);
        Eres->Draw("ap");
        path=pth+"/EnergyResolution.C";
        ca1->Print(path.c_str());
        path=pth+"/EnergyResolution.pdf";
        ca1->Print(path.c_str());
        path=pth+"/EnergyResolution.root";
        ca1->Print(path.c_str());

}
