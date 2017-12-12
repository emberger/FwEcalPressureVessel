{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Dec  6 09:17:42 2017) by ROOT version5.34/36
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
   graph->SetPoint(0,50,0.3275254749);
   graph->SetPoint(1,150,0.2409420069);
   graph->SetPoint(2,250,0.2069044675);
   graph->SetPoint(3,350,0.1898746505);
   graph->SetPoint(4,450,0.1910577804);
   graph->SetPoint(5,550,0.1816793439);
   graph->SetPoint(6,650,0.1781734428);
   graph->SetPoint(7,750,0.180144191);
   graph->SetPoint(8,850,0.1768903396);
   graph->SetPoint(9,950,0.1728423603);
   graph->SetPoint(10,1500,0.1621192744);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Res",100,0,1645);
   Graph_Graph1->SetMinimum(0.1455787);
   Graph_Graph1->SetMaximum(0.3440661);
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
   
   
   TF1 *rms = new TF1("rms","sqrt(([0]*[0]/x)+([2]*[2])+([1]*[1]/(x*x)))",0,1645);
   rms->SetFillColor(19);
   rms->SetFillStyle(0);
   rms->SetLineColor(2);
   rms->SetLineWidth(2);
   rms->SetChisquare(0.0001944247);
   rms->SetNDF(8);
   rms->GetXaxis()->SetLabelFont(42);
   rms->GetXaxis()->SetLabelSize(0.035);
   rms->GetXaxis()->SetTitleSize(0.035);
   rms->GetXaxis()->SetTitleFont(42);
   rms->GetYaxis()->SetLabelFont(42);
   rms->GetYaxis()->SetLabelSize(0.035);
   rms->GetYaxis()->SetTitleSize(0.035);
   rms->GetYaxis()->SetTitleFont(42);
   rms->SetParameter(0,2.047526);
   rms->SetParError(0,0.0415877);
   rms->SetParLimits(0,0,0);
   rms->SetParameter(1,-0.4314276);
   rms->SetParError(1,2.901495);
   rms->SetParLimits(1,0,0);
   rms->SetParameter(2,0.1604892);
   rms->SetParError(2,0.002242563);
   rms->SetParLimits(2,0,0);
   graph->GetListOfFunctions()->Add(rms);
   graph->Draw("ap");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
