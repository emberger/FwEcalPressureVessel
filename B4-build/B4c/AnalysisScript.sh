#!/bin/bash

foldername=AngReso_IT20_OT20_25Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_25Inner_50Outer_lead2mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_25Inner_50Outer_lead1mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_25Inner_50Outer_lead2mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead2mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead1mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_40Inner_50Outer_lead2mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res








foldername=AngReso_IT20_OT20_Ogapfirst_25Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_Ogapfirst_25Inner_50Outer_lead2mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res
foldername=AngReso_IT20_OT20_Ogapfirst_25Inner_50Outer_lead1mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_Ogapfirst_25Inner_50Outer_lead2mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead2mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res


foldername=AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead1mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res

foldername=AngReso_IT20_OT20_Ogapfirst_40Inner_50Outer_lead2mm_Polystyrene5mm_20mmSteelVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername

ANALYSIS=$FILES/Analysis

mkdir $ANALYSIS

mkdir $ANALYSIS/ROOT
mkdir $ANALYSIS/C
mkdir $ANALYSIS/PDF

counter=0
for f in $FILES/*.root
do
    #echo "$f"
    FilePath=$f
    filename="${FilePath##*/}"

    foldername=${filename%_*}

    # mkdir $AnaPath

    ./Analysis 0.0 1000 $FilePath $ANALYSIS

done

./AngularResolution $FILES/Analysis/ROOT LogE_Res
./PlotQuantiles $FILES/Analysis/ROOT LogE_Res
