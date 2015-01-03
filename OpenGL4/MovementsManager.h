#ifndef DEF_MOVEMENTSMANAGER
#define DEF_MOVEMENTSMANAGER

#include <vector>
#include <utility>

class MovementsManager
{
public:
	MovementsManager(void);
	~MovementsManager(void);
	static std::vector<std::pair<int, int>> getTrajCoords(int startX, int startY, int endX, int endY);
	static std::vector<std::pair<int, int>> getTrajCoordsSimple(int startX, int startY, int endX, int endY);


};

#endif

