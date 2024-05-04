/**
 * @file Object.cpp
 * @date 4-May-2024
 */

#include "Object.h"

void Object::OnCreate()
{
  orxConfig_SetBool("IsObject", orxTRUE);
}

void Object::OnDelete()
{
}

void Object::Update(const orxCLOCK_INFO &_rstInfo)
{
}
