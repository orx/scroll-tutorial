/**
 * @file BindingOfObjects.h
 * @date 4-May-2024
 */

#ifndef __BindingOfObjects_H__
#define __BindingOfObjects_H__

#define __NO_SCROLLED__
#include "Scroll.h"

/** Game Class
 */
class BindingOfObjects : public Scroll<BindingOfObjects>
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

#endif // __BindingOfObjects_H__
