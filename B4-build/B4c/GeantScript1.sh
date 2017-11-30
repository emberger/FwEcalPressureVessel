#!/bin/bash

echo working!


AngCOUNTER=0


Sen=50          #starting energy
EnIterations=10
increment=100
eventsPerEnergy=5000

Xangle=0.4     #starting angles
Yangle=0.4
Zangle=1.0
XAngIncrement=0.
 YAngIncrement=0.
AngIiterations=1





foldername=rmsx_over_E_lead1mmScint5mm_absorberfirst_20x20mmGran  #folder containing .root files



 mkdir $foldername

 sed -i "19 s%^/run/beamOn.*%/run/beamOn $eventsPerEnergy%" GeantSim.mac

     while [ $AngCOUNTER -lt $AngIiterations ]; do

         sed -i "16 s%^/gun/direction.*%/gun/direction $Xangle $Yangle $Zangle%" GeantSim.mac

         EnCOUNTER=0
         en=$Sen
         buf=start
         sed -i "18 s%^/gun/energy.*%/gun/energy $buf MeV%" GeantSim.mac

         while [  $EnCOUNTER -lt $EnIterations ]; do

             s=$foldername

             sed -i "18 s%$buf%$en%" GeantSim.mac
             buf=$en

             ./exampleB4c -m GeantSim.mac

             s+=/gamma
             s+=$en
             s+=MeV
             s+=_$Xangle
             s+=:$Yangle
             s+=_.root

             #echo $s

             mv Tree.root ./$s

             let en=en+$increment
             let EnCOUNTER=EnCOUNTER+1
         done


         Xangle=$(echo "($Xangle+$XAngIncrement)" | bc)
         Yangle=$(echo "($Yangle+$YAngIncrement)" | bc)

         let AngCOUNTER=AngCOUNTER+1
 done

AngCOUNTER=0
Sen=1500
EnIterations=1
increment=500
eventsPerEnergy=5000

sed -i "19 s%^/run/beamOn.*%/run/beamOn $eventsPerEnergy%" GeantSim.mac

    while [ $AngCOUNTER -lt $AngIiterations ]; do

        sed -i "16 s%^/gun/direction.*%/gun/direction $Xangle $Yangle $Zangle%" GeantSim.mac

        EnCOUNTER=0
        en=$Sen
        buf=start
        sed -i "18 s%^/gun/energy.*%/gun/energy $buf MeV%" GeantSim.mac

        while [  $EnCOUNTER -lt $EnIterations ]; do

            s=$foldername

            sed -i "18 s%$buf%$en%" GeantSim.mac
            buf=$en

            ./exampleB4c -m GeantSim.mac

            s+=/gamma
            s+=$en
            s+=MeV
            s+=_$Xangle
            s+=:$Yangle
            s+=_.root

            #echo $s

            mv Tree.root ./$s

            let en=en+$increment
            let EnCOUNTER=EnCOUNTER+1
        done


        Xangle=$(echo "($Xangle+$XAngIncrement)" | bc)
        Yangle=$(echo "($Yangle+$YAngIncrement)" | bc)

        let AngCOUNTER=AngCOUNTER+1
done
