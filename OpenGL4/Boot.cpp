#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "Boot.h"
#include "Keyboard.h"
#include "Camera.h"
#include "Block.h"
#include "BlockAir.h"
#include "BlockDirt.h"
#include "BlockStone.h"
#include "World.h"
#include "Player.h"
#include "Spritesheet.h"
#include <iostream>
#include "RapidInventory.h"
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <string>
#include <sstream>
#include "TextureLoader.h"
#include "FontRenderer.h"
#include "Chunk.h"
#include "PerlinNoise.h"
#include <time.h>
#include "NRectangle.h"
#include "Mouse.h"
#include <cmath>
#include "Utils.h"
#include "PlayerInventory.h"
#include "GameRenderer.h"
#include "GameUpdater.h"
#include "GameConsole.h"
#include "CommandsManager.h"
#include "DebugOverlay.h"
#include "Container.h"

#include "CircleLight.h"
#include "Vector2D.h"
#include "LightNeon.h"

#include <Psapi.h>
#include <utility>
#include <thread>

int Boot::width = 1280;
int Boot::height = 720;
int Boot::cameraX = 0;
int Boot::cameraY = 0;
int Boot::blocksIndex = 0;
int Boot::mouseX = 0;
int Boot::mouseY = 0;



Boot::Boot() {

	this->initOpenGL();
	this->mainLoop();
}

void Boot::mainLoop() {
	SDL_Event event;
	Uint32 lastTime = SDL_GetTicks();
	Uint32 currentTime, elapsedTime;
	Uint32 startTime;
	Uint32 timeForFps;
	Uint32 frozenTimeForFps = 0;
	Uint32 frames = 0;
	Uint32 lastFrames = 0;


	std::shared_ptr<Vector2D> vector2D(new Vector2D());
	vector2D->setBase(4,4);
	vector2D->setEnd(7,1);
	std::pair<float, float> coords = vector2D->getCoordFromRadius(2);
	OutputDebugString((std::string("COUPLE : ") + coords.first + std::string(";") + coords.second + std::string(". \n\n")).c_str());

	std::shared_ptr<Container> cContainer(new Container());

	TextureLoader *pTextureLoader = new TextureLoader();
	pTextureLoader->SetAlphaMatch(TRUE, 0x33,0xCC,0xCC);

	
	std::shared_ptr<LightManager> lLightManager(new LightManager());
	lLightManager->setContainer(cContainer);
	cContainer->setLightManager(lLightManager);


	CircleLight* cCircleLight = new CircleLight();
	cCircleLight->setX(0);
	cCircleLight->setY(0);
	//lLightManager->addCircleLight(cCircleLight);
	
	LightNeon* lLightNeon = new LightNeon();
	lLightNeon->setX(32*5);
	lLightNeon->setY(-300);
	lLightManager->addLightNeon(lLightNeon);
	

	std::shared_ptr<World> wWorld(new World());
	wWorld->setContainer(cContainer);
	cContainer->setWorld(wWorld);
	wWorld->init();
	wWorld->generateWorld();
	wWorld->update();
	lLightManager->checkLighting();

	Keyboard Keyboard;
	Camera cCamera;
	Player Natyu;
	Natyu.setName("Natyu");
	PlayerInventory* pPlayerInventory = new PlayerInventory(&Keyboard);
	RapidInventory* rRapidInventory = new RapidInventory();
	

	std::shared_ptr<DebugOverlay> dDebugOverlay(new DebugOverlay());

	std::shared_ptr<CommandsManager> cCommandsManager(new CommandsManager());
	cCommandsManager->setCurPlayer(std::shared_ptr<Player>(&Natyu));

	std::shared_ptr<GameConsole> gGameConsole(new GameConsole());
	gGameConsole->setCommandsManager(cCommandsManager);
	gGameConsole->setKeyboard(&Keyboard);

	cCommandsManager->setGameConsole(gGameConsole);

	Natyu.setWorld(wWorld.get());
	Natyu.teleport(200,0);
	Natyu.setKeyboard(&Keyboard);

	rRapidInventory->setKeyboard(&Keyboard);

	wWorld->addPlayerToRendering(&Natyu);



	

	GameRenderer::addRenderer(wWorld.get());
	GameRenderer::addRenderer(&Natyu);
	GameRenderer::addRenderer(&cCamera);
	GameRenderer::addRenderer(gGameConsole.get());
	GameRenderer::addRenderer(dDebugOverlay.get());
	//GameRenderer::addRenderer(cCircleLight.get());


	GameUpdater::addUpdatable(wWorld.get());
	GameUpdater::addUpdatable(&Keyboard);
	GameUpdater::addUpdatable(&Natyu);
	GameUpdater::addUpdatable(gGameConsole.get());
	GameUpdater::addUpdatable(dDebugOverlay.get());
	GameUpdater::addUpdatable(cCircleLight);



	/* Sprite sheets */
	Spritesheet* FontSpritesheet = new Spritesheet("textures\\font.bmp", 16, pTextureLoader);
	Spritesheet* MiscSpritesheet = new Spritesheet("textures\\misc.bmp", 16, pTextureLoader);
	Spritesheet* InventorySpritesheet = new Spritesheet("textures\\inventory.bmp", 16, pTextureLoader);
	FontRenderer::fFontSpritesheet = new Spritesheet("textures\\font.bmp", 16, pTextureLoader);
	/* Font Renderer */
	FontRenderer* pFontRenderer = new FontRenderer();
	pFontRenderer->setFontSpriteSheet(FontSpritesheet);

	gGameConsole->setFontRenderer(std::shared_ptr<FontRenderer>(pFontRenderer));
	dDebugOverlay->setFontRenderer(std::shared_ptr<FontRenderer>(pFontRenderer));

	Mouse::setFontRenderer(pFontRenderer);
	cCamera.setFontRenderer(pFontRenderer);
	rRapidInventory->setMiscSpritesheet(MiscSpritesheet);
	pPlayerInventory->setInventorySpritesheet(InventorySpritesheet),

	Natyu.setRapidInventory(rRapidInventory);
	Natyu.setPlayerInventory(pPlayerInventory);

	int framesPerSecond = 60;

	PROCESS_MEMORY_COUNTERS pmc;


	bool a = true;
    for (;;)
    {
		startTime = SDL_GetTicks();

		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				exit(0);
			}
			Keyboard.checkInputs(event);
		}

		GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		double currentMemoryUsage;
		SIZE_T virtualMemUsedByMe = pmc.WorkingSetSize;
		currentMemoryUsage = (float)virtualMemUsedByMe/1024/1024;
		


		currentTime = SDL_GetTicks();
		timeForFps = SDL_GetTicks();
		elapsedTime = currentTime - lastTime;
		lastTime = currentTime;


		/* UPDATE */
		GameUpdater::update();
		cCamera.focus(Natyu.getX(), Natyu.getY());
		cCircleLight->setX(Natyu.getX());
		cCircleLight->setY(Natyu.getY());
		Boot::cameraX = cCamera.getCurX();
		Boot::cameraY = cCamera.getCurY();
		Mouse::checkInputs(&event);

		GameRenderer::clear();

		for(int i = 0;i<0;i++) {
			std::vector<Chunk*>* Chunks = wWorld->getActiveChunks();
			for(int j=0; j<Chunks->size(); j++) {
			
				auto Block = (*Chunks)[j]->getBlocks();
			}
		}
		//std::thread thread1 = std::thread(lLightManager->checkLighting());
		lLightManager->checkLighting();
		GameRenderer::render();

		dDebugOverlay->addString(std::string("Blocks compaired to the player : ") + Boot::blocksIndex);	
		dDebugOverlay->addString(std::string("Memory Usage : ") + currentMemoryUsage + std::string("Mo"));
		dDebugOverlay->addString(std::string("FPS : ") + (int)lastFrames);
		dDebugOverlay->addString(std::string("Camera [") + cCamera.getCurX() + std::string(";") + cCamera.getCurY() + std::string("]"));
		dDebugOverlay->addString(std::string("Mouse Coord [") + Mouse::wX + std::string(";") + Mouse::wY + std::string("]"));

		
		if(Natyu.getIsGodMode()) {
			dDebugOverlay->addString(std::string("GOD MODE"));
		}
		
		if(Keyboard.getKeyG()) {
			//wWorld->generate
			//TESTCHUNK->show();
			lLightManager->checkLighting();
		}
		//debug(y);
		frames++;
		glFlush();
		glFinish();
		SDL_GL_SwapBuffers();

		if(timeForFps > frozenTimeForFps + 1000) {
			
			lastFrames = frames;
			frames = 0;

			frozenTimeForFps = SDL_GetTicks();
		}
		elapsedTime = SDL_GetTicks() - startTime;
		if(elapsedTime < (1000.0f/framesPerSecond) ) {
			SDL_Delay((1000.0f/framesPerSecond)-elapsedTime);
		}
    }

	
}

void Boot::initOpenGL() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("SDL GL Application", NULL);
	SDL_SetVideoMode(Boot::width, Boot::height, 32, SDL_OPENGL);

	glEnable(GL_BLEND);
	glEnable(GL_COLOR_MATERIAL);
	glBlendFunc (GL_ONE, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();
	gluOrtho2D(0, Boot::width, Boot::height, 0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
