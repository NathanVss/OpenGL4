#include "GameRenderer.h"

std::vector<Renderer*> GameRenderer::Renderers;

GameRenderer::GameRenderer(void){
}


GameRenderer::~GameRenderer(void){
}

void GameRenderer::addRenderer(Renderer* rRenderer) {
	GameRenderer::Renderers.push_back(rRenderer);
}

void GameRenderer::render() {

	Mouse::render();
	for(int i=0;i<GameRenderer::Renderers.size();i++) {
		GameRenderer::Renderers[i]->render();
	}
}

void GameRenderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
	glClearColor(119/255.0f,181/255.0f,254/255.0f,1);
}