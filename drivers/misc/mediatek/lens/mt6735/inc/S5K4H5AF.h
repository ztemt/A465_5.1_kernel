#ifndef _S5K4H5AF_H
#define _S5K4H5AF_H

#include <linux/ioctl.h>
/* #include "kd_imgsensor.h" */

#define S5K4H5AF_MAGIC 'A'
/* IOCTRL(inode * ,file * ,cmd ,arg ) */


/* Structures */
typedef struct {
/* current position */
	u32 u4CurrentPosition;
/* macro position */
	u32 u4MacroPosition;
/* Infiniti position */
	u32 u4InfPosition;
/* Motor Status */
	bool bIsMotorMoving;
/* Motor Open? */
	bool bIsMotorOpen;
/* Support SR? */
	bool bIsSupportSR;
} stS5K4H5AF_MotorInfo;

/* Control commnad */
/* S means "set through a ptr" */
/* T means "tell by a arg value" */
/* G means "get by a ptr" */
/* Q means "get by return a value" */
/* X means "switch G and S atomically" */
/* H means "switch T and Q atomically" */
#define S5K4H5AFIOC_G_MOTORINFO _IOR(S5K4H5AF_MAGIC, 0, stS5K4H5AF_MotorInfo)

#define S5K4H5AFIOC_T_MOVETO _IOW(S5K4H5AF_MAGIC, 1, u32)

#define S5K4H5AFIOC_T_SETINFPOS _IOW(S5K4H5AF_MAGIC, 2, u32)

#define S5K4H5AFIOC_T_SETMACROPOS _IOW(S5K4H5AF_MAGIC, 3, u32)

#else
#endif
