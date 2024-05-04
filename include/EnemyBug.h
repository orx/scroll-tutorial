#pragma once

#include "Object.h"

enum Direction
{
  NORTH,
  SOUTH,
  EAST,
  WEST,
  LAST = WEST,
};

class EnemyBug : public Object
{
public:
protected:
  void OnCreate();
  void OnDelete();
  void Update(const orxCLOCK_INFO &_rstInfo);

private:
  // Direction of movement
  Direction m_direction;
  // Speed of movement
  orxFLOAT m_movementSpeed;
  // Time since change of direction
  orxFLOAT m_timeSinceDirectionChange;
  // Time interval between direction changes
  orxFLOAT m_directionChangeInterval;
};
