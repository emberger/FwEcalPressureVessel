#!/bin/bash


foldername=AngReso_IT20_OT20_25Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_25Inner_50Outer_lead2mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_25Inner_50Outer_lead1mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_25Inner_50Outer_lead2mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead2mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead1mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead2mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files
FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res



