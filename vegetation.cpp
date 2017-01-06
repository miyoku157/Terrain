#include "vegetation.h"

vegetation::vegetation()
{

}
vegetation::vegetation(int type, int x, int y, double maxDirt){
    if(type==1){
        this->age=1;
        this->rayon=2;
        this->slopeMax=110;
        this->dirtMin=maxDirt*0.7;
        this->heightMax=180;
        this->ageMax=75;
    }else{
        this->age=1;
        this->rayon=1;
        this->slopeMax=90;
        this->dirtMin=maxDirt*0.35;
        this->heightMax=150;
        this->ageMax=55;
    }
    this->type=type;
    this->x=x;
    this->y=y;
}

bool vegetation::IsAlived(double slope, double dirt, double height){
    if(this->dirtMin<dirt&&slope<slopeMax&&height<heightMax){
        return true;
    }
    return false;
}

