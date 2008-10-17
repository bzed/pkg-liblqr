/* LiquidRescaling Library
 * Copyright (C) 2007-2008 Carlo Baldassi (the "Author") <carlobaldassi@gmail.com>.
 * All Rights Reserved.
 *
 * This library implements the algorithm described in the paper
 * "Seam Carving for Content-Aware Image Resizing"
 * by Shai Avidan and Ariel Shamir
 * which can be found at http://www.faculty.idc.ac.il/arik/imret.pdf
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3 dated June, 2007-2008.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/> 
 */

#include <glib.h>

#include <lqr.h>

#ifdef __LQR_DEBUG__
#include <assert.h>
#endif /* __LQR_DEBUG__ */


/**** CARVER LIST FUNCTIONS ****/

LqrCarverList * 
lqr_carver_list_append (LqrCarverList * list, LqrCarver * r)
{
  LqrCarverList * prev = NULL;
  LqrCarverList * now = list;
  while (now != NULL)
    {
      prev = now;
      now = now->next;
    }
  TRY_N_N (now = g_try_new(LqrCarverList, 1));
  now->next = NULL;
  now->current = r;
  if (prev)
    {
      prev->next = now;
    }
  if (list == NULL)
    {
      return now;
    }
  else
    {
      return list;
    }
}

void
lqr_carver_list_destroy(LqrCarverList * list)
{
  LqrCarverList * now = list;
  if (now != NULL)
    {
      lqr_carver_list_destroy(now->next);
      lqr_carver_destroy(now->current);
    }
}

LQR_PUBLIC
LqrCarverList *
lqr_carver_list_start (LqrCarver *r)
{
  return r->attached_list;
}

LQR_PUBLIC
LqrCarverList *
lqr_carver_list_next (LqrCarverList * list)
{
  TRY_N_N (list);
  return list->next;
}

LQR_PUBLIC
LqrCarver *
lqr_carver_list_current (LqrCarverList * list)
{
  TRY_N_N (list);
  return list->current;
}

LQR_PUBLIC
LqrRetVal
lqr_carver_list_foreach (LqrCarverList * list, LqrCarverFunc func, LqrDataTok data)
{
  LqrCarverList * now = list;
  if (now != NULL)
    {
      CATCH (func(now->current, data));
      return lqr_carver_list_foreach (now->next, func, data);
    }
  return LQR_OK;
}

