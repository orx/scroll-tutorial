/**
 * @file Object.h
 * @date 4-May-2024
 */

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "BindingOfObjects.h"

/** Object Class
 */
class Object : public ScrollObject
{
public:


protected:

                void            OnCreate();
                void            OnDelete();
                void            Update(const orxCLOCK_INFO &_rstInfo);


private:
};

#endif // __OBJECT_H__
