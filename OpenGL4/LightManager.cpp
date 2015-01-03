#include "LightManager.h"
#include "World.h"
#include "EasyBMP\EasyBMP.h"
#include "Vector2D.h"
#include "Utils.h"
#include "DDAHelper.h"

LightManager::LightManager(void)
{
	this->finalShadowMap = nullptr;
	this->baseShadowMap = nullptr;
}


LightManager::~LightManager(void)
{
	this->clearPointers();
}

void LightManager::clearPointers() {

	if(this->finalShadowMap) {
		delete this->finalShadowMap;
		this->finalShadowMap = nullptr;
	}
	if(this->baseShadowMap) {
		delete this->baseShadowMap;
		this->baseShadowMap = nullptr;
	}


	for(int i=0;i<this->CircleLightsBags.size();i++) {
		this->clearLightBagPointer(this->CircleLightsBags[i]);
		this->clearLightBagRaycastingPointer(this->CircleLightsBags[i]);
		this->CircleLightsBags[i]->interpFromRaycastingPts.clear();
		this->CircleLightsBags[i]->lightMiniRadiusPts.clear();
		this->CircleLightsBags[i]->cCircleLight = nullptr;
		delete this->CircleLightsBags[i];
	}
	this->CircleLightsBags.clear();

	for(int i=0;i<this->LightNeonsBags.size();i++) {
		this->clearLightBagPointer(this->LightNeonsBags[i]);
		this->clearLightBagRaycastingPointer(this->LightNeonsBags[i]);
		this->LightNeonsBags[i]->interFromRaycastingPts.clear();
		delete this->LightNeonsBags[i];
	}
	this->LightNeonsBags.clear();
}

void LightManager::clearLightBagPointer(LightBag* lLightBag) {
	if(lLightBag->shadowMap) {
		delete lLightBag->shadowMap;
		lLightBag->shadowMap = nullptr;
	}
}
void LightManager::clearLightBagRaycastingPointer(LightBagRaycasting* lLightBagRaycasting) {
	if(lLightBagRaycasting->shadowMapRaycasting) {
		delete lLightBagRaycasting->shadowMapRaycasting;
		lLightBagRaycasting->shadowMapRaycasting = nullptr;
	}
}

void LightManager::copyMapWorld(LightBag* lb) {

	ShadowMap* shadowMap = new ShadowMap(this->baseShadowMap->getWidth(),this->baseShadowMap->getHeight());

	for(int x=0;x<this->baseShadowMap->getWidth();x++) {
		for(int y=0;y<this->baseShadowMap->getHeight();y++) {

			shadowMap->setScale(x, y, this->baseShadowMap->getScale(x, y));

		}
	}
	lb->shadowMap = shadowMap;
}

//void LightManager::copyMapWorldToEachLight() {
//	for(int i=0;i<this->Lights.size();i++) {
//
//		ShadowMap* shadowMap = new ShadowMap(this->baseShadowMap->getWidth(),this->baseShadowMap->getHeight());
//		for(int x=0;x<this->baseShadowMap->getWidth();x++) {
//			for(int y=0;y<this->baseShadowMap->getHeight();y++) {
//
//				shadowMap->setScale(x, y, this->baseShadowMap->getScale(x, y));
//
//			}
//		}
//		//this->convertToBMP(shadowMap, std::string("lighting/Copy")+i+std::string(".bmp"));
//		this->shadowMaps.push_back(shadowMap);
//
//	}
//}

void LightManager::mapWorld() {
	if(this->baseShadowMap) {
		return;
	}

	std::vector<Chunk*>* ActiveChunks = this->container->getWorld()->getActiveChunks();

	ShadowMap* CurShadowMap = new ShadowMap(this->container->getWorld()->getActiveChunksRectangle()->getWidth(),this->container->getWorld()->getActiveChunksRectangle()->getHeight());
	this->baseShadowMap = CurShadowMap;



	for(int ci=0; ci<ActiveChunks->size(); ci++) {
		Block*** CurBlocks = (*ActiveChunks)[ci]->getBlocks();
		for(int x = 0; x<16;x++) {

			for(int y = 0; y<16; y++) {

				//auto CurBlock =(*(*CurBlocks)[x])[y];
				Block* CurBlock = CurBlocks[x][y];
				if(CurBlock->getIsTransparent()) {

					CurShadowMap->setScale(CurBlock->getX()-this->container->getWorld()->getActiveChunksRectangle()->getX1(), CurBlock->getY()-this->container->getWorld()->getActiveChunksRectangle()->getY1(), 255);


				} else {

					CurShadowMap->setScale(CurBlock->getX()-this->container->getWorld()->getActiveChunksRectangle()->getX1(), CurBlock->getY()-this->container->getWorld()->getActiveChunksRectangle()->getY1(), 0);
				}

			}

		}

	}
	
}

void LightManager::lightRadius(CircleLightBag* cCircelLightBag) {

	int topLeftX = cCircelLightBag->cCircleLight->getRelX()/32.0f - cCircelLightBag->cCircleLight->getRadius()/32.0f;
	int topLeftY = cCircelLightBag->cCircleLight->getRelY()/32.0f - cCircelLightBag->cCircleLight->getRadius()/32.0f;
	int squareWidth = (cCircelLightBag->cCircleLight->getRadius()/32.0f)*2;


	for(int x=topLeftX;x<=topLeftX+squareWidth;x++) {
		for(int y=topLeftY;y<=topLeftY+squareWidth;y++) {

			// Les coordonnées de la lumière sont absolue
			// La shadow map est relative

			// Le getColor renvois une valeur par rapport aux coordonnées relatives
			// On va donc reconvertir x et y en absolu
			float indice = cCircelLightBag->cCircleLight->getColor((x + this->container->getWorld()->getActiveChunksRectangle()->getX1())*32, (y + this->container->getWorld()->getActiveChunksRectangle()->getY1())*32);


			cCircelLightBag->shadowMap->setScale(x, y, round(cCircelLightBag->shadowMap->getScale(x, y)*indice));
		}
	}

}

void LightManager::lightMiniRadius(CircleLightBag* cCircleLightBag) {

	
	if(cCircleLightBag->cCircleLight->getHasMiniRadius()) {

			
		int topLeftX = cCircleLightBag->cCircleLight->getRelX()/32.0f - cCircleLightBag->cCircleLight->getMiniRadius()/32.0f;
		int topLeftY = cCircleLightBag->cCircleLight->getRelY()/32.0f - cCircleLightBag->cCircleLight->getMiniRadius()/32.0f;
		int squareWidth = (cCircleLightBag->cCircleLight->getMiniRadius()/32.0f)*2;

		for(int x=topLeftX;x<=topLeftX+squareWidth;x++) {
			for(int y=topLeftY;y<=topLeftY+squareWidth;y++) {
					

				unsigned char curScale = cCircleLightBag->shadowMapRaycasting->getScale(x, y);
				if(curScale == 0) {
					float indice = cCircleLightBag->cCircleLight->getColorMiniRadius((x+this->container->getWorld()->getActiveChunksRectangle()->getX1())*32, (y+this->container->getWorld()->getActiveChunksRectangle()->getY1())*32);
					mapPoint mPt;
					mPt.x = x;
					mPt.y = y;
					mPt.scale = round(255*indice);
					cCircleLightBag->lightMiniRadiusPts.push_back(mPt);
				}


			}
		}

	}

}


void LightManager::doOneRaycastingCircleLight(CircleLightBag* cCircleLightBag, coords DestCoords) {
	
	int lx = cCircleLightBag->cCircleLight->getRelX()/32.0f;
	int ly = cCircleLightBag->cCircleLight->getRelY()/32.0f;

	if(DestCoords.x == lx && DestCoords.y == ly) {
		return;
	}

	DDAHelper* dDDAHelper = new DDAHelper(lx, ly, DestCoords.x, DestCoords.y);

	bool hit = false;
	bool flag = false;
	int count = 0;
	int ind = 0;
	while(!flag){

		coords point = dDDAHelper->getNextCoords();

		if(hit) {
			ind++;
			if(ind > count) {
				flag = true;
			}
		}

		if(!flag) {
			
			
			if(!hit) {
				//this->shadowMapsRaycasting[lightI]->setScale(point.x, point.y, 255);
				cCircleLightBag->shadowMapRaycasting->setScale(point.x, point.y, 255);
			}
		}	

		//int last = this->shadowMaps[lightI]->getScale(point.x, point.y);
		int last = cCircleLightBag->shadowMap->getScale(point.x, point.y);
		if(last == -1) {
			break;
		}

		if(last == 0 && !hit) {
			hit = true;
			mapPoint mPt;
			
			mPt.x = point.x;
			mPt.y = point.y;
			mPt.scale = 255*0.5f*cCircleLightBag->cCircleLight->getColor((mPt.x+this->container->getWorld()->getActiveChunksRectangle()->getX1())*32.0f, (mPt.y+this->container->getWorld()->getActiveChunksRectangle()->getY1())*32.0f);
			//this->interpFromRaycastingPts[lightI].push_back(mPt);			
			cCircleLightBag->interpFromRaycastingPts.push_back(mPt);
				
		}


	}
	delete dDDAHelper;
	dDDAHelper= nullptr;

}

void LightManager::doRaycastingNeonLight(LightNeonBag* lLightNeonBag) {
	
	int direction = lLightNeonBag->lLightNeon->getDirection();
	int lightX = lLightNeonBag->lLightNeon->getX()/32.0f;
	int lightWidth = lLightNeonBag->lLightNeon->getWidth()/32.0f;
	int boxX = this->container->getWorld()->getActiveChunksRectangle()->getX1();
	int boxY = this->container->getWorld()->getActiveChunksRectangle()->getY1();
	int boxWidth = this->container->getWorld()->getActiveChunksRectangle()->getWidth();

	if(direction == 0 || direction == 2) {

		int startX = 0;
		int endX = 0;
		if(lightX > boxX) {
			startX = lightX - boxX;

		}
		if(lightX + lightWidth > boxX + boxWidth) {
			endX = this->baseShadowMap->getWidth();
		} else {
			endX = lightX + lightWidth - boxX;
		}

		for(int x=startX;x<=endX;x++) {
			coords StartCoords;
			StartCoords.x = x;
			StartCoords.y = boxY;
			coords DestCoords;
			DestCoords.x = x;

			if(direction == 0) {
				DestCoords.y = 0;
			} else if(direction == 2) {
				DestCoords.y = this->baseShadowMap->getHeight();
			}
			
			this->doOneRaycastingNeonLight(lLightNeonBag, StartCoords, DestCoords);
		}

	} else if (direction == 1) {






	} else {

	}

}

void LightManager::doOneRaycastingNeonLight(LightNeonBag* lLightNeonBag, coords StartCoords, coords DestCoords) {

	//DDAHelper* dDDAHelper = new DDAHelper(, ly, DestCoords.x, DestCoords.y);
	coords CurCoords;
	CurCoords.x = StartCoords.x;
	CurCoords.y = StartCoords.y;
	if(CurCoords.y < 0) {
		CurCoords.y = 0;
	}
	if(CurCoords.y > this->baseShadowMap->getHeight()) {
		CurCoords.y = this->baseShadowMap->getHeight();
	}

	if(CurCoords.x < 0) {
		CurCoords.x = 0;
	}
	bool hit = false;
	bool first = true;

	bool toBottom = false;
	bool toRight = false;
	bool toTop = false;
	bool toLeft = false;
	if(StartCoords.x == DestCoords.x && StartCoords.y == DestCoords.y) {
		return;
	}
	if(StartCoords.x == DestCoords.x) {

		if(StartCoords.y < DestCoords.y) {
			toBottom = true;
		} else {
			toTop = true;
		}

	} else if(StartCoords.y == DestCoords.y) {

		if(StartCoords.x < DestCoords.x ) {
			toRight = true;
		} else {
			toLeft = true;
		}

	}

	while(!hit) {
		if(!first) {

			if(toTop) {
				CurCoords.y -= 1;
			} else if(toRight) {
				CurCoords.x += 1;
			} else if(toLeft) {
				CurCoords.x -= 1;
			} else if(toBottom) {
				CurCoords.y += 1;
			}

			
		}
		if(first) {
			first = false;
		}


		if(lLightNeonBag->shadowMap->getScale(CurCoords.x, CurCoords.y) == 255) {
			float indice = lLightNeonBag->lLightNeon->getColor(CurCoords.x, CurCoords.y);
			lLightNeonBag->shadowMapRaycasting->setScale(CurCoords.x, CurCoords.y, (255*indice));
		} else {

			mapPoint mMapPoint;
			mMapPoint.x = CurCoords.x;
			mMapPoint.y = CurCoords.y;
			mMapPoint.scale = (255*lLightNeonBag->lLightNeon->getColor(CurCoords.x, CurCoords.y));
			lLightNeonBag->interFromRaycastingPts.push_back(mMapPoint);
			hit = true;
		}
		

	}
}


void LightManager::mixRaycastingNeonLight(LightNeonBag* lLightNeonBag) {


	for(float x=0;x<this->baseShadowMap->getWidth();x++){

		for(float y=0; y<this->baseShadowMap->getHeight(); y++) {

			unsigned char scale = lLightNeonBag->shadowMapRaycasting->getScale(x, y);
			unsigned char baseScale = lLightNeonBag->shadowMap->getScale(x, y);
			lLightNeonBag->shadowMap->setScale(x, y, scale);
		}

	}
	for(int i=0;i<lLightNeonBag->interFromRaycastingPts.size();i++) {

		mapPoint mMapPoint = lLightNeonBag->interFromRaycastingPts[i];
		lLightNeonBag->shadowMap->setScale(mMapPoint.x, mMapPoint.y, mMapPoint.scale);
	}
}

void LightManager::assignShadowMapRaycasting(LightBagRaycasting* lbr) {
	int mapWidth = this->baseShadowMap->getWidth();
	int mapHeight = this->baseShadowMap->getHeight();
	ShadowMap* shadowMapRaycasting = new ShadowMap(mapWidth , mapHeight);
	lbr->shadowMapRaycasting = shadowMapRaycasting;

	for(int x=0;x<mapWidth;x++) {
		for(int y = 0; y < mapHeight; y++) {
			shadowMapRaycasting->setScale(x, y, 0);
		}
	}
}

void LightManager::doRaycastingCircleLight(CircleLightBag* clb) {
	int rad = 2;
	int mapWidth = clb->shadowMapRaycasting->getWidth();
	int mapHeight = clb->shadowMapRaycasting->getHeight();

	for(float y=0-rad;y<mapHeight+rad;y+=1) {
		int rx = mapWidth-1+rad;
		int lx = 0-rad;
		coords crds1;
		crds1.x = lx;
		crds1.y = y;

		coords crds2;
		crds2.x = rx;
		crds2.y = y;
		this->doOneRaycastingCircleLight(clb, crds1);
		this->doOneRaycastingCircleLight(clb, crds2);

	}

	for(float x=-rad;x<mapWidth+rad;x+=1) {
		int ty = 0-rad;
		int by = mapHeight-1+rad;
		coords crds1;
		crds1.x = x;
		crds1.y = ty;

		coords crds2;
		crds2.x = x;
		crds2.y = by;

		this->doOneRaycastingCircleLight(clb, crds1);
		this->doOneRaycastingCircleLight(clb, crds2);
	}
	this->convertToBMP(clb->shadowMapRaycasting, std::string("lighting/raycasting.bmp"));

}

//void LightManager::drawShadows() {
//	for(int mapI = 0; mapI < this->Lights.size(); mapI++) {
//
//		// Map noire pour chaque light
//		int mapWidth = this->shadowMaps[mapI]->getWidth();
//		int mapHeight = this->shadowMaps[mapI]->getHeight();
//		ShadowMap* shadowMapRaycasting = new ShadowMap(mapWidth , mapHeight);
//
//		this->shadowMapsRaycasting.push_back(shadowMapRaycasting);
//		for(int x=0;x<mapWidth;x++) {
//			for(int y = 0; y < mapHeight; y++) {
//				shadowMapRaycasting->setScale(x, y, 0);
//			}
//		}
//
//		std::vector<mapPoint> mapPointsVector;
//		this->interpFromRaycastingPts.push_back(mapPointsVector);
//
//		if(this->Lights[mapI]->getType() == std::string("circle")) {
//			this->drawShadowRectangle(mapI);
//
//		} else if(this->Lights[mapI]->getType() == std::string("neon")) {
//			this->drawShadowNeon(mapI);
//		}
//
//		
//	}
//		
//
//}

void LightManager::mixRaycastingRadius(CircleLightBag* cCircleLightBag) {
	int lx = cCircleLightBag->cCircleLight->getX()/32.0f;
	int ly = cCircleLightBag->cCircleLight->getY()/32.0f;
	int rad = cCircleLightBag->cCircleLight->getRadius()/32.0f;

	int mapWidth = cCircleLightBag->shadowMap->getWidth();
	int mapHeight = cCircleLightBag->shadowMap->getHeight();

	for(float x=0;x<mapWidth;x++){

		for(float y=0; y<mapHeight; y++) {
				
			// Si le raycast blanchie un bloc opaque
			// Alors on le remplace pa
			unsigned char scale = 0;
			scale = cCircleLightBag->shadowMapRaycasting->getScale(x, y);
			unsigned char newScale = round(scale*(cCircleLightBag->shadowMap->getScale(x,y)/255.0f));
			cCircleLightBag->shadowMap->setScale(x, y, newScale);

		}

	}
	
	//if(this->interpFromRaycastingPts.size() > li) {

	for(int i=0;i<cCircleLightBag->interpFromRaycastingPts.size();i++) {
			mapPoint mPt = cCircleLightBag->interpFromRaycastingPts[i];
			cCircleLightBag->shadowMap->setScale(mPt.x, mPt.y, mPt.scale);
		}
	//}
	//if(this->lightMiniRadiusPts.size() > li) {
	for(int i=0; i < cCircleLightBag->lightMiniRadiusPts.size(); i++) {
			mapPoint mPt = cCircleLightBag->lightMiniRadiusPts[i];
			cCircleLightBag->shadowMap->setScale(mPt.x, mPt.y, mPt.scale);
		}
	//}




}

void LightManager::enableFinalShadowMap() {
	this->finalShadowMap = new ShadowMap(this->baseShadowMap->getWidth(),this->baseShadowMap->getHeight());

	for(int x =0; x<this->baseShadowMap->getWidth(); x++) {

		for(int y = 0; y < this->baseShadowMap->getHeight(); y++) {

			int indice = 0;
			for(int i=0; i < this->CircleLightsBags.size(); i++) {
				indice += this->CircleLightsBags[i]->shadowMap->getScale(x, y);
			}
			for(int i=0; i < this->LightNeonsBags.size(); i++) {
				indice += this->LightNeonsBags[i]->shadowMap->getScale(x, y);
			}
			if(indice > 255) {
				indice = 255;
			}
			this->finalShadowMap->setScale(x, y, indice);
		}
	}
	this->convertToBMP(this->finalShadowMap, std::string("lighting/final.bmp"));
}




void LightManager::checkLighting() {

	//OutputDebugString((this->container->getWorld()->getActiveChunksRectangle()->getX1() + std::string(";") + this->container->getWorld()->getActiveChunksRectangle()->getY1() + std::string("\n")).c_str());
	this->clearPointers();

	for(int i=0;i<this->CircleLights.size();i++) {
		this->CircleLights[i]->setRelX(this->CircleLights[i]->getX()-this->container->getWorld()->getActiveChunksRectangle()->getX1()*32);
		this->CircleLights[i]->setRelY(this->CircleLights[i]->getY()-this->container->getWorld()->getActiveChunksRectangle()->getY1()*32);
	}

	this->mapWorld();
	for(int i=0;i<this->CircleLights.size();i++) {

		CircleLightBag* cCircleLightBag = new CircleLightBag();
		this->CircleLightsBags.push_back(cCircleLightBag);
		cCircleLightBag->cCircleLight = this->CircleLights[i];
		this->copyMapWorld(cCircleLightBag);
		this->assignShadowMapRaycasting(cCircleLightBag);
		this->doRaycastingCircleLight(cCircleLightBag);
		this->lightRadius(cCircleLightBag);
		this->lightMiniRadius(cCircleLightBag);
		this->mixRaycastingRadius(cCircleLightBag);
		
	}
	

	for(int i=0;i<this->LightNeons.size(); i++) {
		int lightX = this->LightNeons[i]->getX()/32.0f;
		int lightWidth = this->LightNeons[i]->getWidth()/32.0f;
		int lightY = this->LightNeons[i]->getY()/32.0f;
		int direction = this->LightNeons[i]->getDirection();
		int boxX = this->container->getWorld()->getActiveChunksRectangle()->getX1();
		int boxY = this->container->getWorld()->getActiveChunksRectangle()->getY1();
		int boxWidth = this->container->getWorld()->getActiveChunksRectangle()->getWidth();

		if(this->LightNeons[i]->getDirection() == 0 || this->LightNeons[i]->getDirection() == 2) {
			if(lightX + lightWidth < boxX) {
				continue;
			}
			if(lightX >  boxX + boxWidth) {
				continue;
			}
			if(direction == 2) {
				if(boxY != 0 && lightY < boxY) {
					continue;
				}
			}
		}
		if(this->LightNeons[i]->getDirection() == 1 || this->LightNeons[i]->getDirection() == 3) {
			//if(lightY + lightWidth < 
		}
		//OutputDebugString("HERE\n");

		LightNeonBag* lLightNeonBag = new LightNeonBag();
		lLightNeonBag->lLightNeon = this->LightNeons[i];
		this->LightNeonsBags.push_back(lLightNeonBag);
		this->copyMapWorld(lLightNeonBag);
		this->assignShadowMapRaycasting(lLightNeonBag);
		this->doRaycastingNeonLight(lLightNeonBag);
		this->mixRaycastingNeonLight(lLightNeonBag);
	}

	this->enableFinalShadowMap();

}

ShadowMap* LightManager::getFinalShadowMap() {

	return this->finalShadowMap;

}

void LightManager::convertToBMP(ShadowMap* s, std::string filename) {
	return;	
	BMP* curBMP = new BMP();

		curBMP->SetSize(s->getWidth(),s->getHeight());

		curBMP->SetBitDepth(32);

		unsigned char*** ary = s->getScale();
			
		for(int x=0; x < s->getWidth(); x++) {

			for(int y = 0; y < s->getHeight(); y++) {
	
				(*curBMP)(x, y)->Red = (*ary)[x][y];
				(*curBMP)(x, y)->Alpha = 255;
				(*curBMP)(x, y)->Green = (*ary)[x][y];
				(*curBMP)(x, y)->Blue = (*ary)[x][y];

			}
		}

		curBMP->WriteToFile(filename.c_str());
	delete curBMP;
}

void LightManager::addCircleLight(CircleLight* l){
	l->setContainer(this->container);
	this->CircleLights.push_back(l);
}
void LightManager::addLightNeon(LightNeon* l){
	l->setContainer(this->container);
	this->LightNeons.push_back(l);
}