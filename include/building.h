#ifndef BUILDING_H
#define BUILDING_H

#include <SDL2/SDL_rect.h>

#include "event.h"
#include "mapunit.h"

typedef enum BuildingType {
  BUILDING_TYPE_TOWER
} BuildingType;

class Game;
class Agent;
struct Objective;

class Building {
  friend class Game;
  friend class Agent;
  friend struct Objective;
protected:
  Game *game;
  BuildingType type;
  SDL_Rect region;
  SpawnerID sid;
  bool ready;
  int hp;
  int max_hp;
  int updateCounter;
  int updateTime;
public:
  MapUnit::iterator getIterator();
  bool canUpdate();
  Building(Game*, BuildingType, SpawnerID, int, int, int, int, int, int);
};

class Tower: public Building {
  friend class Game;
private:
  TowerID tid;
public:
  Tower(Game*, SpawnerID, TowerID, int, int);
  void update(TowerEvent*);
};

#endif
