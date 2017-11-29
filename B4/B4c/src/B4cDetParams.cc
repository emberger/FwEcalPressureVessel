#include "B4cDetParams.hh"



DetParams::~DetParams(){
}

void DetParams::InitDet(){

								nofInnerTilesX=calorSizeXY/InnertileLenX;
								nofInnerTilesY=calorSizeXY/InnertileLenY;

								nofOuterTilesX=calorSizeXY/OutertileLenX;
								nofOuterTilesY=calorSizeXY/OutertileLenY;

								InnerlayerThickness=InnerabsoThickness+InnergapThickness;
								OuterlayerThickness=OuterabsoThickness+OutergapThickness;


								InnercalorThickness=fNofInnerLayers*InnerlayerThickness;
								OutercalorThickness=fNofOuterLayers*OuterlayerThickness;

								InnertilesPerLayer=nofInnerTilesY*nofInnerTilesX;
								OutertilesPerLayer=nofOuterTilesX*nofOuterTilesY;

								DetectorThickness=InnercalorThickness+OutercalorThickness+PvesselThickness;

								WorldSizeXY=4.0 * calorSizeXY;
								WorldSizeZ=4.0 * calorSizeXY;
}

//Outer Calorimeter Part



void DetParams::SetfNofLayers(G4double nla){
								fNofOutertileLayers=nla;
}

G4double DetParams::GetfNofLayers(){
								return fNofOutertileLayers;
}

void DetParams::SettileLenX(G4double tx){
								OutertiletileLenX=tx;
}

G4double DetParams::GettileLenX(){
								return OutertiletileLenX;
}

void DetParams::SettileLenY(G4double ty){
								OutertiletileLenY=ty;
}

G4double DetParams::GettileLenY(){
								return OutertiletileLenY;
}

void DetParams::SetabsoThickness(G4double abso){
								OutertileabsoThickness=abso;
}

G4double DetParams::GetabsoThickness(){
								return OutertileabsoThickness;
}

void DetParams::SetgapThickness(G4double gap){
								OutertilegapThickness=gap;
}

G4double DetParams::GetgapThickness(){
								return OutertilegapThickness;
}

G4double DetParams::GetnofOuterTilesX(){
								return nofOuterTilesX;
}
G4double DetParams::GetnofOuterTilesY(){
								return nofOuterTilesY;
}

G4double DetParams::GetOuterlayerThickness(){
								return OuterlayerThickness;
}
G4double DetParams::GetOutercalorThickness(){
								return OutercalorThickness;
}

G4double DetParams::GetOutertilesPerLayer(){
								return OutertilesPerLayer;
}

void DetParams::SetOuterAbsFirst(G4bool Ocfg){
								Outerabsofirst=Ocfg;
}
G4bool DetParams::GetOuterAbsFirst(){
								return Outerabsofirst;
}

//Inner Calorimeter Part

void DetParams::SetfNofInnerLayers(G4double nla){
								fNofInnerLayers=nla;
}

G4double DetParams::GetfNofInnerLayers(){
								return fNofInnerLayers;
}

void DetParams::SetInnertileLenX(G4double tx){
								InnertileLenX=tx;
}

G4double DetParams::GetInnertileLenX(){
								return InnertileLenX;
}

void DetParams::SetInnertileLenY(G4double ty){
								InnertileLenY=ty;
}

G4double DetParams::GetInnertileLenY(){
								return InnertileLenY;
}

void DetParams::SetInnerabsoThickness(G4double abso){
								InnerabsoThickness=abso;
}

G4double DetParams::GetInnerabsoThickness(){
								return InnerabsoThickness;
}

void DetParams::SetInnergapThickness(G4double gap){
								InnergapThickness=gap;
}

G4double DetParams::GetInnergapThickness(){
								return InnergapThickness;
}

G4double DetParams::GetnofInnerTilesX(){
								return nofInnerTilesX;
}
G4double DetParams::GetnofInnerTilesY(){
								return nofInnerTilesY;
}


G4double DetParams::GetInnerlayerThickness(){
								return InnerlayerThickness;
}
G4double DetParams::GetInnercalorThickness(){
								return InnercalorThickness;
}


G4double DetParams::GetInnertilesPerLayer(){
								return InnertilesPerLayer;
}

void DetParams::SetInnerAbsFirst(G4bool Icfg){
								Innerabsofirst=Icfg;
}
G4bool DetParams::GetInnerAbsFirst(){
								return Innerabsofirst;
}

//General Parameters

void DetParams::SetcalorSizeXY(G4double cs){
								calorSizeXY=cs;
}

G4double DetParams::GetcalorSizeXY(){
								return calorSizeXY;
}

void DetParams::SetWorldMult(G4double wm){
								WorldMult=wm;
}

void DetParams::SetPvesselThickness(G4double pvt){
								PvesselThickness=pvt;
}
G4double DetParams::GetPvesselThickness(){
								return PvesselThickness;
}

G4double DetParams::GetWorldSizeXY(){
								return WorldSizeXY;
}
G4double DetParams::GetWorldSizeZ(){
								return WorldSizeZ;
}

G4double DetParams::GetDetectorThickness(){
	return DetectorThickness;
}
