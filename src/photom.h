/*
*				photom.h
*
* Include file for photom.c.
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*
*	This file part of:	SExtractor
*
*	Copyright:		(C) 1993-2012 Emmanuel Bertin -- IAP/CNRS/UPMC
*
*	License:		GNU General Public License
*
*	SExtractor is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*	SExtractor is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*	You should have received a copy of the GNU General Public License
*	along with SExtractor. If not, see <http://www.gnu.org/licenses/>.
*
*	Last modified:		21/03/2012
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*----------------------------- AUTO flags ----------------------------------*/

#define	AUTOFLAG_CROWDED	0x0001	/* Singularity in WINdowed light dist.*/
#define	AUTOFLAG_APERT_PB	0x0002	/* Meas. area incomplete or truncated */
#define	AUTOFLAG_DETECT_PB	0x0004	/* Detection area too truncated */

/*----------------------------- Internal constants --------------------------*/

#define	APER_OVERSAMP	5	/* oversampling in each dimension (MAG_APER) */
#define	KRON_NSIG	3*MARGIN_SCALE	/* MAG_AUTO analysis range (number */
					/* of sigma) */
#define	PETRO_NSIG	3*MARGIN_SCALE	/* MAG_PETRO analysis range (number */
					/* of sigma) */
#define	CROWD_THRESHOLD	0.1	/* The OBJ_CROWDED flag is set if photometric*/
				/* contamination may exceed this fraction of */
				/* flux */

/* NOTES:
One must have:	APER_OVERSAMP >= 1
		KRON_NSIG > 0.0
		PETRO_NSIG > 0.0
		CROWD_THRESHOLD >= 0
*/

/*------------------------------- functions ---------------------------------*/
extern void	photom_aper(fieldstruct *field, fieldstruct *wfield,
			obj2struct *obj2, int aper),
		photom_auto(fieldstruct **fields, fieldstruct **wfields,
			int nfield, obj2struct *obj2),
		photom_isocor(fieldstruct *field, obj2struct *obj2),
		photom_mags(fieldstruct *field, obj2struct *obj2),
		photom_petro(fieldstruct *field, fieldstruct *dfield,
			fieldstruct *wfield, fieldstruct *dwfield,
			obj2struct *obj2),
		photom_printinstruinfo(void);

