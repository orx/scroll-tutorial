#include "Hero.h"

void Hero::OnCreate()
{
  // Get movement speed from config value
  m_movementSpeed = orxConfig_GetFloat("MovementSpeed");
}

void Hero::OnDelete()
{
  // Do nothing when deleted
}

void Hero::Update(const orxCLOCK_INFO &_rstInfo)
{
  // Use movement input to initialize a vector to scale movement speed
  orxVECTOR speed = {
      // Vector's x component is right - left input strength. It will
      // be 0.0 if the inputs are either inactive or both equally active.
      orxInput_GetValue("MoveRight") - orxInput_GetValue("MoveLeft"),
      // Vector's y component is down - up input strength. It will
      // be 0.0 if the inputs are either inactive or both equally active.
      orxInput_GetValue("MoveDown") - orxInput_GetValue("MoveUp"),
      0.0};

  // Normalize the input vector if it has a length > 1
  if (orxVector_GetSquareSize(&speed) > 1.0)
  {
    orxVector_Normalize(&speed, &speed);
  }

  // Scale the raw input vector by the our movement speed
  orxVector_Mulf(&speed, &speed, m_movementSpeed);

  // Update our speed
  SetSpeed(speed, false);
}

void Hero::OnCollide(ScrollObject *_poCollider, orxBODY_PART *_pstPart, orxBODY_PART *_pstColliderPart, const orxVECTOR &_rvPosition, const orxVECTOR &_rvNormal)
{
  // Add flash effect
  AddFX("FX-Flash");
}
