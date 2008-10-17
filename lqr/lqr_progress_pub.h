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


#ifndef __LQR_PROGRESS_PUB_H__
#define __LQR_PROGRESS_PUB_H__

#define LQR_PROGRESS_MAX_MESSAGE_LENGTH (1024)

struct _LqrProgress;

typedef struct _LqrProgress LqrProgress;

typedef LqrRetVal (*LqrProgressFuncInit)(const gchar*);
typedef LqrRetVal (*LqrProgressFuncUpdate)(gdouble);
typedef LqrRetVal (*LqrProgressFuncEnd)(const gchar*);

/*** LQR_PROGRESS CLASS DEFINITION ***/

struct _LqrProgress
{
  gfloat update_step;
  LqrProgressFuncInit init;
  LqrProgressFuncUpdate update;
  LqrProgressFuncEnd end;
  gchar init_width_message[LQR_PROGRESS_MAX_MESSAGE_LENGTH];
  gchar end_width_message[LQR_PROGRESS_MAX_MESSAGE_LENGTH];
  gchar init_height_message[LQR_PROGRESS_MAX_MESSAGE_LENGTH];
  gchar end_height_message[LQR_PROGRESS_MAX_MESSAGE_LENGTH];
};

/* LQR_PROGRESS CLASS PUBLIC FUNCTIONS */

LqrProgress * lqr_progress_new(void);

LqrRetVal lqr_progress_set_update_step(LqrProgress *p, gfloat update_step);

LqrRetVal lqr_progress_set_init(LqrProgress * p, LqrProgressFuncInit init_func);
LqrRetVal lqr_progress_set_update(LqrProgress * p, LqrProgressFuncUpdate update_func);
LqrRetVal lqr_progress_set_end(LqrProgress * p, LqrProgressFuncEnd end_func);

LqrRetVal lqr_progress_set_init_width_message(LqrProgress *p, const gchar * message);
LqrRetVal lqr_progress_set_init_height_message(LqrProgress *p, const gchar * message);
LqrRetVal lqr_progress_set_end_width_message(LqrProgress *p, const gchar * message);
LqrRetVal lqr_progress_set_end_height_message(LqrProgress *p, const gchar * message);

#endif /* __LQR_PROGRESS_PUB_H__ */
