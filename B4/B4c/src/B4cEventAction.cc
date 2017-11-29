//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B4cEventAction.cc 100946 2016-11-03 11:28:08Z gcosmo $
//
/// \file B4cEventAction.cc
/// \brief Implementation of the B4cEventAction class

#include "B4cEventAction.hh"
#include "B4cCalorimeterSD.hh"
#include "B4cCalorHit.hh"
#include "B4Analysis.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"


#include <string>
#include "B4cDetParams.hh"
//#include "B4cPionManager.hh"
#include "Randomize.hh"
#include <iomanip>
#include "TVector3.h"




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4cEventAction::B4cEventAction()
        : G4UserEventAction(),
        fAbsHCID(-1),
        fGapHCID(-1)
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4cEventAction::~B4cEventAction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
B4ROOTEvent* B4cEventAction::CalEvent()
{
        // check that the rootFile is open, if not, open it! Also create the tree and everything else with it

        if (!eventTree)
        {
                std::cout << "Attempting to open ROOT file " << "ECalEventTree" << std::endl;
                //rootFile = new TFile("ECalEventTree.root", "RECREATE");
                calEvent = new B4ROOTEvent();
                eventTree = new TTree("eventTree", "B4ROOT Event Tree");



                //std::cout<<"TilesX: "<<GetInst().GetnofTilesX()<<std::endl;
                //std::cout<<"TilesX: "<<calEvent->TilesX()<<std::endl;
                eventTree->Branch("EventBranch", "B4ROOTEvent", &calEvent);
                eventTree->SetAutoSave(1.99e9);
//		rootFile->SetCompressionLevel(9);
        }
        return calEvent;
}


void B4cEventAction::SetStepHit(G4double x, G4double y, G4double z, G4double eDep /*,G4int s, G4int phnr*/)
{
        B4ROOTHit hit;

        hit.SetCoordinates(x, y, z);
        //hit.SetCalorimeterSegment(s);
        hit.SetEnergyDeposit(eDep);
        //hit.SetPhotNr(phnr);

        //G4cout<<phnr<<" SetStepHit"<<hit.PhotNr()<<G4endl;
        this->CalEvent()->AddHit(hit);
        //G4cout << "Setting Hit! " << G4endl;

}





B4cCalorHitsCollection*
B4cEventAction::GetHitsCollection(G4int hcID,
                                  const G4Event* event) const
{
        auto hitsCollection
                = static_cast<B4cCalorHitsCollection*>(
                event->GetHCofThisEvent()->GetHC(hcID));

        if ( !hitsCollection ) {
                G4ExceptionDescription msg;
                msg << "Cannot access hitsCollection ID " << hcID;
                G4Exception("B4cEventAction::GetHitsCollection()",
                            "MyCode0003", FatalException, msg);
        }

        return hitsCollection;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4cEventAction::PrintEventStatistics(
        G4double absoEdep, G4double absoTrackLength,
        G4double gapEdep, G4double gapTrackLength) const
{
        // print event statistics
        // G4cout
        // << "(Not implemented)   Absorber: total energy: "
        // << std::setw(7) << G4BestUnit(absoEdep, "Energy")
        // << "       total track length: "
        // << std::setw(7) << G4BestUnit(absoTrackLength, "Length")
        // << G4endl
        // << "        Gap: total energy: "
        // << std::setw(7) << G4BestUnit(gapEdep, "Energy")
        // << "       total track length: "
        // << std::setw(7) << G4BestUnit(gapTrackLength, "Length")
        // << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4cEventAction::BeginOfEventAction(const G4Event* /*event*/)
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4cEventAction::EndOfEventAction(const G4Event* event)
{
        // Get hits collections IDs (only once)
        if ( fGapHCID == -1 ) {
                fGapHCID
                        = G4SDManager::GetSDMpointer()->GetCollectionID("GapHitsCollection");
        }

        // Get hits collection
        auto gapHC = GetHitsCollection(fGapHCID, event);
        G4cout<<gapHC->entries()<<G4endl;

        // Get hit with total values
        auto gapHit = (*gapHC)[gapHC->entries()-1];

        //G4int nIsTouch=0;

        // for (int i=0; i<gapHC->entries();i++){
        //
        //  auto hit=(*gapHC)[i];
        //  if (hit -> GetTouch()==true && hit->GetCellInfo()==true){
        //    //G4cout<<"X:"<<hit->GetX()<<"Y:"<<hit->GetY()<<"Z:"<<hit->GetZ()<<"E:"<<hit->GetEdep()<<"Touched?:"<<hit->GetTouch()<<G4endl;
        //    nIsTouch++;
        //  }
        //
        // }
        // G4cout<<"Touched hits:"<<nIsTouch<<G4endl;


        // Print per event (modulo n)
        //
        auto eventID = event->GetEventID();
        auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();
        if ( ( printModulo > 0 ) && ( eventID % printModulo == 0 ) ) {
                G4cout << "---> End of event: " << eventID << G4endl;

                PrintEventStatistics(
                        0, 0,
                        gapHit->GetEdep(), gapHit->GetTrackLength());
        }

        // Fill histograms, ntuple
        //

        // get analysis manager
        auto analysisManager = G4AnalysisManager::Instance();

        // fill histograms
        //analysisManager->FillH1(0, absoHit->GetEdep());
        analysisManager->FillH1(1, gapHit->GetEdep());
        // analysisManager->FillH1(2, absoHit->GetTrackLength());
        analysisManager->FillH1(3, gapHit->GetTrackLength());

        // fill ntuple
        //analysisManager->FillNtupleDColumn(0, absoHit->GetEdep());
        analysisManager->FillNtupleDColumn(1, gapHit->GetEdep());
        //analysisManager->FillNtupleDColumn(2, absoHit->GetTrackLength());
        analysisManager->FillNtupleDColumn(3, gapHit->GetTrackLength());
        analysisManager->AddNtupleRow();



        //fill ROOT Classes

        this->CalEvent()->SetEventNo(eventID);
        this->CalEvent()->SetGapThickness(GetInst().GetgapThickness());

        //std::cout<<"Gapthickness: "<<GetInst().GetgapThickness()<<std::endl;
        //std::cout<<"Gapthickness: "<<this->CalEvent()->GapThickness()<<std::endl;

        this->CalEvent()->SetAbsoThickness(GetInst().GetabsoThickness());
        this->CalEvent()->SetNumberOfLayers(GetInst().GetfNofLayers());
        this->CalEvent()->SetTilesizeX(GetInst().GettileLenX());
        this->CalEvent()->SetTilesizeY(GetInst().GettileLenY());
        this->CalEvent()->SetcalsizeXY(GetInst().GetcalorSizeXY());
        this->CalEvent()->SetAbsFirst(GetInst().GetAbsFirst());
        //this->CalEvent()->SetEnergyPhoton1(GetEInst().GetEnergyPh1());
        //this->CalEvent()->SetEnergyPhoton2(GetEInst().GetEnergyPh2());
        TVector3 vertpos(event->GetPrimaryVertex()->GetPosition().getX(),event->GetPrimaryVertex()->GetPosition().getY(),event->GetPrimaryVertex()->GetPosition().getZ());
        this->CalEvent()->SetGunPos(vertpos);

        G4ThreeVector mom1=event->GetPrimaryVertex()->GetPrimary()->GetMomentumDirection();
        this->CalEvent()->SetMomentumPh1(mom1.getX(), mom1.getY(),mom1.getZ());

        // G4ThreeVector mom2=GetEInst().GetMomPh2();
        // this->CalEvent()->SetMomentumPh2(mom2.getX(), mom2.getY(),mom2.getZ());



        //this->CalEvent()->SetMomentumPh2();
        //std::cout<<this->CalEvent()->EventNo()<<std::endl;

        // double tmpE1=0;
        // double tmpE2=0;
        // double seglistph1[6]={0,0,0,0,0,0};
        // double seglistph2[6]={0,0,0,0,0,0};
        //
        // double eseg1=0;
        // double eseg2=0;
        // int segph1=0;
        // int segph2=0;

        //  bool goodevent=false;

        //if(GetEInst().GetTD()==false) {
        auto ent=gapHC->entries();

        for (int i=0; i<ent; i++) {

                auto tHit=(*gapHC)[i];
                if (tHit->GetTouch()==true && tHit->GetCellInfo()==true) {
                        this->SetStepHit(tHit->GetX(),
                                         tHit->GetY(),
                                         tHit->GetZ(),
                                         tHit->GetEdep()/*,
                                                           tHit->GetCalorSeg(),
                                                           tHit->GetPhotonNumber()*/);

                        // if(tHit->GetPhotonNumber()==1) {
                        //
                        //         double e1=tHit->GetEdep();
                        //         tmpE1+=e1;
                        //
                        //         int seg1=tHit->GetCalorSeg()-1;
                        //         seglistph1[seg1]+=e1;
                        // }
                        //
                        // else if(tHit->GetPhotonNumber()==2) {
                        //         double e2=tHit->GetEdep();
                        //         tmpE2+=e2;
                        //
                        //         int seg2=tHit->GetCalorSeg()-1;
                        //         seglistph2[seg2]+=e2;
                        //
                        // }
                        //
                        // for(int k =0; k<6; k++) {
                        //
                        //         if(seglistph1[k]>eseg1) {
                        //                 segph1=k;
                        //                 eseg1=seglistph1[k];
                        //         }
                        //         if(seglistph2[k]>eseg2) {
                        //                 segph2=k;
                        //                 eseg2=seglistph2[k];
                        //         }
                        //
                        // }

                }
                if(i == ent-1) {
                        this->CalEvent()->SetGapEnergy(tHit->GetEdep());
                        //G4cout<<tHit->GetEdep()<<G4endl;
                }

        }

        // this->CalEvent()->SetSegmentph1(segph1+1);
        // this->CalEvent()->SetSegmentph2(segph2+1);
        //
        //
        // if(tmpE1*0.9<seglistph1[segph1] && tmpE2*0.9<seglistph2[segph2]) {

        //goodevent=true;
        eventTree->Fill();

        // }

        //}
        //std::cout<<"Gapthickness: "<<this->CalEvent()->GapThickness()<<std::endl;

        calEvent->Clear();

        //GetEInst().ReSetTD();
        //std::cout<<"Gapthickness: "<<this->CalEvent()->GapThickness()<<std::endl;
        //	}
        //if(event->GetEventID()==G4RunManager::GetCurrentRun()->GetNumberOfEventToBeProcessed()){
        //rootFile->Write();
        //rootFile->Close();
        //std::cout<<"Event done"<<std::endl;
        std::cout<<"Tree has now "<<eventTree->GetEntries()<<" entries"<<std::endl;
        //eventTree->Print();
        //}

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
