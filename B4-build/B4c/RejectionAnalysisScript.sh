
foldername=AngReso_IT20_OT20_25Inner_50Outer_lead1mm_Polystyrene5mm_14mmTitanVessel  #folder containing .root files

FILES=/home/iwsatlas1/emberger/Geant4/Data/ForwardEcalWithPressureVessel/AngularResolution/$foldername
ANALYSIS=$FILES/RejectionMethodAnalysis

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

./AngularResolution $FILES/RejectionMethodAnalysis/ROOT Res
./PlotQuantiles $FILES/RejectionMethodAnalysis/ROOT
