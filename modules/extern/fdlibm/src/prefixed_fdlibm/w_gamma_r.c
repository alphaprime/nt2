
/* @(#)w_gamma_r.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

/* 
 * wrapper double gamma_r(double x, int *signgamp)
 */

#include "fdlibm.h"


#ifdef __STDC__
	double fd_gamma_r(double x, int *signgamp) /* wrapper lgamma_r */
#else
	double fd_gamma_r(x,signgamp)              /* wrapper lgamma_r */
        double x; int *signgamp;
#endif
{
#ifdef _IEEE_LIBM
	return fd___ieee754_gamma_r(x,signgamp);
#else
        double y;
        y = fd___ieee754_gamma_r(x,signgamp);
        if(_LIB_VERSION == _IEEE_) return y;
        if(!fd_finite(y)&&fd_finite(x)) {
            if(fd_floor(x)==x&&x<=0.0)
                return fd___kernel_standard(x,x,41); /* gamma pole */
            else
                return fd___kernel_standard(x,x,40); /* gamma overflow */
        } else
            return y;
#endif
}             