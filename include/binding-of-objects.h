/**
 * @file binding-of-objects.h
 * @date 4-May-2024
 */

#ifndef __binding_of_objects_H__
#define __binding_of_objects_H__

#define __NO_SCROLLED__
#include "Scroll.h"

/** Game Class
 */
class binding_of_objects : public Scroll<binding_of_objects>
{
public:


private:

                orxSTATUS       Bootstrap() const;

                void            Update(const orxCLOCK_INFO &_rstInfo);

                orxSTATUS       Init();
                orxSTATUS       Run();
                void            Exit();
                void            BindObjects();


private:
};

#endif // __binding_of_objects_H__
