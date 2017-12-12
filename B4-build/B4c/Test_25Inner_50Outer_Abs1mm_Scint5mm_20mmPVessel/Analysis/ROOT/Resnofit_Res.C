{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec  6 09:01:01 2017) by ROOT version5.34/36
   TCanvas *c1 = new TCanvas("c1", "c1",65,52,700,500);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(11);
   graph->SetName("Graph0");
   graph->SetTitle("Res");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(3);
   graph->SetPoint(0,50,0.3596687595);
   graph->SetPoint(1,150,0.2738091109);
   graph->SetPoint(2,250,0.2442575781);
   graph->SetPoint(3,350,0.2307666641);
   graph->SetPoint(4,450,0.2139448449);
   graph->SetPoint(5,550,0.1968647349);
   graph->SetPoint(6,650,0.1918826443);
   graph->SetPoint(7,750,0.1835506925);
   graph->SetPoint(8,850,0.1735318579);
   graph->SetPoint(9,950,0.1664467685);
   graph->SetPoint(10,1500,0.1312610991);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Res",100,0,1645);
   Graph_Graph1->SetMinimum(0.1084203);
   Graph_Graph1->SetMaximum(0.3825095);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("Energy[MeV]");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("#frac{RMS_x}{1000mm}");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("ap");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
