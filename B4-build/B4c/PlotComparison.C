{
        TFile * f1= new TFile("AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel/Analysis/ROOT/ResPCA_68Quantil.root");
        TCanvas * c1=(TCanvas*)f1->Get("c2p");
        TGraph * g1=(TGraph*)c1->GetListOfPrimitives()->Last();


        TFile * f2= new TFile("AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead2mm_Polystyrene5mm_14mmTitanVessel/Analysis/ROOT/ResPCA_68Quantil.root");
        TCanvas * c2=(TCanvas*)f2->Get("c2p");
        TGraph * g2=(TGraph*)c2->GetListOfPrimitives()->Last();

        TFile * f3= new TFile("AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead1mm_Polystyrene5mm_20mmSteelVessel/Analysis/ROOT/ResPCA_68Quantil.root");
        TCanvas * c3=(TCanvas*)f3->Get("c2p");
        TGraph * g3=(TGraph*)c3->GetListOfPrimitives()->Last();

        TFile * f4= new TFile("AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead2mm_Polystyrene5mm_20mmSteelVessel/Analysis/ROOT/ResPCA_68Quantil.root");
        TCanvas * c4=(TCanvas*)f4->Get("c2p");
        TGraph * g4=(TGraph*)c4->GetListOfPrimitives()->Last();

        TFile * f5= new TFile("AngReso_IT20_OT20_noVessel_25Inner_50Outer_lead1mm_Polystyrene5mm/Analysis/ROOT/ResPCA_68Quantil.root");
        TCanvas * c5=(TCanvas*)f5->Get("c2p");
        TGraph * g5=(TGraph*)c5->GetListOfPrimitives()->Last();

        TFile * f6= new TFile("AngReso_IT20_OT20_noVessel_25Inner_50Outer_lead2mm_Polystyrene5mm/Analysis/ROOT/ResPCA_68Quantil.root");
        TCanvas * c6=(TCanvas*)f6->Get("c2p");
        TGraph * g6=(TGraph*)c6->GetListOfPrimitives()->Last();

//Standard is 1cm Lead, NO Vessel

        Int_t nofPoints=g1->GetN();
        std::cout<<nofPoints<<std::endl;

        Double_t energy[nofPoints];

        Double_t r1[nofPoints];
        Double_t r2[nofPoints];
        Double_t r3[nofPoints];
        Double_t r4[nofPoints];
        Double_t r5[nofPoints];
        Double_t r6[nofPoints];


        for(Int_t i=0; i < nofPoints; i++) {

                Double_t stax,stay;
                g5->GetPoint(i, stax, stay);

                energy[i]=stax;

                Double_t x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;

                g1->GetPoint(i,x1, y1);
                r1[i]=(y1/stay)-1 ;

                g2->GetPoint(i,x2, y2);
                r2[i]=(y2/stay) -1;

                g3->GetPoint(i,x3, y3);
                r3[i]=(y3/stay) -1;

                g4->GetPoint(i,x4, y4);
                r4[i]=(y4/stay) -1;

                g5->GetPoint(i,x5, y5);
                r5[i]=(y5/stay) -1;

                g6->GetPoint(i,x6, y6);
                r6[i]=(y6/stay) -1;
        }

        TGraph * rat1=new TGraph(nofPoints,energy, r1);
        TGraph * rat2=new TGraph(nofPoints,energy, r2);
        TGraph * rat3=new TGraph(nofPoints,energy, r3);
        TGraph * rat4=new TGraph(nofPoints,energy, r4);
        TGraph * rat5=new TGraph(nofPoints,energy, r5);
        TGraph * rat6=new TGraph(nofPoints,energy, r6);

        TCanvas * ratio1=new TCanvas("GeometryRating", "GeometryRating");

        rat1->SetMarkerSize(1.5);
        rat1->SetMarkerStyle(24);
        rat1->SetMarkerColor(kRed);

        rat2->SetMarkerSize(1.5);
        rat2->SetMarkerStyle(20);
        rat2->SetMarkerColor(kRed);

        rat3->SetMarkerSize(1.5);
        rat3->SetMarkerStyle(24);
        rat3->SetMarkerColor(kBlack);

        rat4->SetMarkerSize(1.5);
        rat4->SetMarkerStyle(20);
        rat4->SetMarkerColor(kBlack);

        rat5->SetMarkerSize(1.5);
        rat5->SetMarkerStyle(25);
        rat5->SetMarkerColor(kBlue);

        rat6->SetMarkerSize(1.5);
        rat6->SetMarkerStyle(21);
        rat6->SetMarkerColor(kBlue);

        TLegend * l1= new TLegend(0.5,0.7,0.9,0.9);
        l1->AddEntry(rat1, "1mmLeadAbsorber_14mmTitanVessel", "p");
        l1->AddEntry(rat2, "2mmLeadAbsorber_14mmTitanVessel", "p");
        l1->AddEntry(rat3, "1mmLeadAbsorber_20mmSteelVessel", "p");
        l1->AddEntry(rat4, "2mmLeadAbsorber_20mmSteelVessel", "p");
        l1->AddEntry(rat5, "1mmLeadAbsorber_NOVessel_standard", "p");
        l1->AddEntry(rat6, "2mmLeadAbsorber_NOVessel", "p");

        ratio1->cd(0);
        rat1->GetYaxis()->SetRangeUser(-0.2,0.8);

        rat1->Draw("AP");
        rat2->Draw("P");
        rat3->Draw("P");
        rat4->Draw("P");
        rat5->Draw("P");
        rat6->Draw("P");
        l1->Draw();

        ratio1->Print("GeometryRating_AngleDiff_40InnerLayers.pdf");
        ratio1->Print("GeometryRating_AngleDiff_40InnerLayers.C");


        g1->SetMarkerSize(1.5);
        g1->SetMarkerStyle(24);
        g1->SetMarkerColor(kRed);

        g2->SetMarkerSize(1.5);
        g2->SetMarkerStyle(20);
        g2->SetMarkerColor(kRed);

        g3->SetMarkerSize(1.5);
        g3->SetMarkerStyle(24);
        g3->SetMarkerColor(kBlack);

        g4->SetMarkerSize(1.5);
        g4->SetMarkerStyle(20);
        g4->SetMarkerColor(kBlack);

        g5->SetMarkerSize(1.5);
        g5->SetMarkerStyle(25);
        g5->SetMarkerColor(kBlue);

        g6->SetMarkerSize(1.5);
        g6->SetMarkerStyle(21);
        g6->SetMarkerColor(kBlue);

        TLegend * l2= new TLegend(0.5,0.7,0.9,0.9);
        l2->AddEntry(g1, "1mmLeadAbsorber_14mmTitanVessel", "p");
        l2->AddEntry(g2, "2mmLeadAbsorber_14mmTitanVessel", "p");
        l2->AddEntry(g3, "1mmLeadAbsorber_20mmSteelVessel", "p");
        l2->AddEntry(g4, "2mmLeadAbsorber_20mmSteelVessel", "p");
        l2->AddEntry(g5, "1mmLeadAbsorber_NOVessel", "p");
        l2->AddEntry(g6, "2mmLeadAbsorber_NOVessel", "p");


        TCanvas * comp1 = new TCanvas("Comparison", "Comparison");
        g1->GetYaxis()->SetRangeUser(0.0,0.5);
        g1->GetYaxis()->SetTitleOffset(1.23);
        g1->Draw("AP");
        g2->Draw("P");
        g3->Draw("P");
        g4->Draw("P");
        g5->Draw("P");
        g6->Draw("P");

        l2->Draw();

        comp1->Print("GeometryComparison_AngleDiff_40InnerLayers.C");
        comp1->Print("GeometryComparison_AngleDiff_40InnerLayers.pdf");
}
