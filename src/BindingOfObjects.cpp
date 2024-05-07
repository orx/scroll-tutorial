/**
 * @file BindingOfObjects.cpp
 * @date 4-May-2024
 */

#define __SCROLL_IMPL__
#include "BindingOfObjects.h"
#undef __SCROLL_IMPL__

#include "Object.h"
#include "EnemyBug.h"
#include "Hero.h"

#define orxBUNDLE_IMPL
#include "orxBundle.h"
#undef orxBUNDLE_IMPL

#ifdef __orxMSVC__

/* Requesting high performance dedicated GPU on hybrid laptops */
__declspec(dllexport) unsigned long NvOptimusEnablement = 1;
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;

#endif // __orxMSVC__

/** Update function, it has been registered to be called every tick of the core clock
 */
void BindingOfObjects::Update(const orxCLOCK_INFO &_rstInfo)
{
  // Should quit?
  if (orxInput_IsActive("Quit"))
  {
    // Send close event
    orxEvent_SendShort(orxEVENT_TYPE_SYSTEM, orxSYSTEM_EVENT_CLOSE);
  }
}

/** Init function, it is called when all orx's modules have been initialized
 */
orxSTATUS BindingOfObjects::Init()
{
  // Create the scene
  CreateObject("Scene");

  // Is processing a new bundle?
  if (orxBundle_IsProcessing())
  {
    // Done!
    return orxSTATUS_SUCCESS;
  }

  // Done!
  return orxSTATUS_SUCCESS;
}

/** Run function, it should not contain any game logic
 */
orxSTATUS BindingOfObjects::Run()
{
  // Return orxSTATUS_FAILURE to instruct orx to quit
  return orxSTATUS_SUCCESS;
}

/** Exit function, it is called before exiting from orx
 */
void BindingOfObjects::Exit()
{
  // Exit from bundle support
  orxBundle_Exit();

  // Let orx clean all our mess automatically. :)
}

/** BindObjects function, ScrollObject-derived classes are bound to config sections here
 */
void BindingOfObjects::BindObjects()
{
  // Bind the Object class to the Object config section
  ScrollBindObject<Object>("Object");
  // Bind the EnemyBug class to the O-EnemyBug config section
  ScrollBindObject<EnemyBug>("O-EnemyBug");
  // Bind the Hero class to the O-Hero config section
  ScrollBindObject<Hero>("O-Hero");
}

/** Bootstrap function, it is called before config is initialized, allowing for early resource storage definitions
 */
orxSTATUS BindingOfObjects::Bootstrap() const
{
  // Initialize bundle resource type
  orxBundle_Init();

  // Add config storage to find the initial config file
  orxResource_AddStorage(orxCONFIG_KZ_RESOURCE_GROUP, orxBUNDLE_KZ_RESOURCE_STORAGE, orxFALSE);
  orxResource_AddStorage(orxCONFIG_KZ_RESOURCE_GROUP, orxBUNDLE_KZ_RESOURCE_STORAGE "BindingOfObjects.obr", orxFALSE);
  orxResource_AddStorage(orxCONFIG_KZ_RESOURCE_GROUP, "../data/config", orxFALSE);

  // Return orxSTATUS_FAILURE to prevent orx from loading the default config file
  return orxSTATUS_SUCCESS;
}

/** Main function
 */
int main(int argc, char **argv)
{
  // Execute our game
  BindingOfObjects::GetInstance().Execute(argc, argv);

  // Done!
  return EXIT_SUCCESS;
}
