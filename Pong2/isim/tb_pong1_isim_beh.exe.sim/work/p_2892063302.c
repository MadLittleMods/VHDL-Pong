/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif



char *work_p_2892063302_sub_1835150778_3757376413(char *t1, char *t2)
{
    char t3[128];
    char t4[16];
    char t8[16];
    char *t0;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    unsigned char t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    int t16;
    char *t17;
    char *t18;
    unsigned int t19;
    int t20;
    int t21;
    int t22;
    unsigned int t23;

LAB0:    t5 = (t3 + 4U);
    t6 = (t1 + 3760);
    t7 = (t5 + 88U);
    *((char **)t7) = t6;
    t9 = (t5 + 56U);
    *((char **)t9) = t8;
    xsi_type_set_default_value(t6, t8, 0);
    t10 = (t5 + 80U);
    *((unsigned int *)t10) = 16U;
    t11 = (t4 + 4U);
    t12 = (t2 != 0);
    if (t12 == 1)
        goto LAB3;

LAB2:    t13 = (0 + 0U);
    t14 = (t13 + 0U);
    t15 = (t2 + t14);
    t16 = *((int *)t15);
    t17 = (t5 + 56U);
    t18 = *((char **)t17);
    t19 = (0 + 0U);
    t17 = (t18 + t19);
    *((int *)t17) = t16;
    t13 = (0 + 0U);
    t14 = (t13 + 0U);
    t6 = (t2 + t14);
    t16 = *((int *)t6);
    t19 = (0 + 8U);
    t7 = (t2 + t19);
    t20 = *((int *)t7);
    t21 = (t16 + t20);
    t22 = (t21 - 1);
    t9 = (t5 + 56U);
    t10 = *((char **)t9);
    t23 = (0 + 4U);
    t9 = (t10 + t23);
    *((int *)t9) = t22;
    t13 = (0 + 0U);
    t14 = (t13 + 4U);
    t6 = (t2 + t14);
    t16 = *((int *)t6);
    t7 = (t5 + 56U);
    t9 = *((char **)t7);
    t19 = (0 + 8U);
    t7 = (t9 + t19);
    *((int *)t7) = t16;
    t13 = (0 + 0U);
    t14 = (t13 + 4U);
    t6 = (t2 + t14);
    t16 = *((int *)t6);
    t19 = (0 + 12U);
    t7 = (t2 + t19);
    t20 = *((int *)t7);
    t21 = (t16 + t20);
    t22 = (t21 - 1);
    t9 = (t5 + 56U);
    t10 = *((char **)t9);
    t23 = (0 + 12U);
    t9 = (t10 + t23);
    *((int *)t9) = t22;
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t0 = xsi_get_transient_memory(16U);
    memcpy(t0, t7, 16U);

LAB1:    return t0;
LAB3:    *((char **)t11) = t2;
    goto LAB2;

LAB4:;
}

unsigned char work_p_2892063302_sub_1445971953_3757376413(char *t1, char *t2, char *t3)
{
    char t4[248];
    char t5[24];
    char t9[16];
    char t15[16];
    unsigned char t0;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    unsigned char t19;
    char *t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    unsigned int t25;
    int t26;
    unsigned int t27;
    int t28;
    unsigned char t29;
    unsigned int t30;
    int t31;
    unsigned int t32;
    int t33;
    unsigned char t34;
    unsigned char t35;
    unsigned int t36;
    int t37;
    char *t38;
    unsigned int t39;
    int t40;
    unsigned char t41;
    char *t42;
    char *t43;
    unsigned int t44;
    int t45;
    char *t46;
    char *t47;
    unsigned int t48;
    int t49;
    unsigned char t50;

LAB0:    t6 = (t4 + 4U);
    t7 = (t1 + 3760);
    t8 = (t6 + 88U);
    *((char **)t8) = t7;
    t10 = (t6 + 56U);
    *((char **)t10) = t9;
    xsi_type_set_default_value(t7, t9, 0);
    t11 = (t6 + 80U);
    *((unsigned int *)t11) = 16U;
    t12 = (t4 + 124U);
    t13 = (t1 + 3760);
    t14 = (t12 + 88U);
    *((char **)t14) = t13;
    t16 = (t12 + 56U);
    *((char **)t16) = t15;
    xsi_type_set_default_value(t13, t15, 0);
    t17 = (t12 + 80U);
    *((unsigned int *)t17) = 16U;
    t18 = (t5 + 4U);
    t19 = (t2 != 0);
    if (t19 == 1)
        goto LAB3;

LAB2:    t20 = (t5 + 12U);
    t21 = (t3 != 0);
    if (t21 == 1)
        goto LAB5;

LAB4:    t22 = work_p_2892063302_sub_1835150778_3757376413(t1, t2);
    t23 = (t6 + 56U);
    t24 = *((char **)t23);
    t23 = (t24 + 0);
    memcpy(t23, t22, 16U);
    t7 = work_p_2892063302_sub_1835150778_3757376413(t1, t3);
    t8 = (t12 + 56U);
    t10 = *((char **)t8);
    t8 = (t10 + 0);
    memcpy(t8, t7, 16U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t25 = (0 + 4U);
    t7 = (t8 + t25);
    t26 = *((int *)t7);
    t10 = (t12 + 56U);
    t11 = *((char **)t10);
    t27 = (0 + 0U);
    t10 = (t11 + t27);
    t28 = *((int *)t10);
    t29 = (t26 >= t28);
    if (t29 == 1)
        goto LAB9;

LAB10:    t21 = (unsigned char)0;

LAB11:    if (t21 == 1)
        goto LAB6;

LAB7:    t22 = (t6 + 56U);
    t23 = *((char **)t22);
    t36 = (0 + 0U);
    t22 = (t23 + t36);
    t37 = *((int *)t22);
    t24 = (t12 + 56U);
    t38 = *((char **)t24);
    t39 = (0 + 0U);
    t24 = (t38 + t39);
    t40 = *((int *)t24);
    t41 = (t37 >= t40);
    if (t41 == 1)
        goto LAB12;

LAB13:    t35 = (unsigned char)0;

LAB14:    t19 = t35;

LAB8:    t0 = t19;

LAB1:    return t0;
LAB3:    *((char **)t18) = t2;
    goto LAB2;

LAB5:    *((char **)t20) = t3;
    goto LAB4;

LAB6:    t19 = (unsigned char)1;
    goto LAB8;

LAB9:    t13 = (t6 + 56U);
    t14 = *((char **)t13);
    t30 = (0 + 4U);
    t13 = (t14 + t30);
    t31 = *((int *)t13);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    t32 = (0 + 4U);
    t16 = (t17 + t32);
    t33 = *((int *)t16);
    t34 = (t31 <= t33);
    t21 = t34;
    goto LAB11;

LAB12:    t42 = (t6 + 56U);
    t43 = *((char **)t42);
    t44 = (0 + 0U);
    t42 = (t43 + t44);
    t45 = *((int *)t42);
    t46 = (t12 + 56U);
    t47 = *((char **)t46);
    t48 = (0 + 4U);
    t46 = (t47 + t48);
    t49 = *((int *)t46);
    t50 = (t45 <= t49);
    t35 = t50;
    goto LAB14;

LAB15:;
}

unsigned char work_p_2892063302_sub_1445973042_3757376413(char *t1, char *t2, char *t3)
{
    char t4[248];
    char t5[24];
    char t9[16];
    char t15[16];
    unsigned char t0;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    unsigned char t19;
    char *t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    unsigned int t25;
    int t26;
    unsigned int t27;
    int t28;
    unsigned char t29;
    unsigned int t30;
    int t31;
    unsigned int t32;
    int t33;
    unsigned char t34;
    unsigned char t35;
    unsigned int t36;
    int t37;
    char *t38;
    unsigned int t39;
    int t40;
    unsigned char t41;
    char *t42;
    char *t43;
    unsigned int t44;
    int t45;
    char *t46;
    char *t47;
    unsigned int t48;
    int t49;
    unsigned char t50;

LAB0:    t6 = (t4 + 4U);
    t7 = (t1 + 3760);
    t8 = (t6 + 88U);
    *((char **)t8) = t7;
    t10 = (t6 + 56U);
    *((char **)t10) = t9;
    xsi_type_set_default_value(t7, t9, 0);
    t11 = (t6 + 80U);
    *((unsigned int *)t11) = 16U;
    t12 = (t4 + 124U);
    t13 = (t1 + 3760);
    t14 = (t12 + 88U);
    *((char **)t14) = t13;
    t16 = (t12 + 56U);
    *((char **)t16) = t15;
    xsi_type_set_default_value(t13, t15, 0);
    t17 = (t12 + 80U);
    *((unsigned int *)t17) = 16U;
    t18 = (t5 + 4U);
    t19 = (t2 != 0);
    if (t19 == 1)
        goto LAB3;

LAB2:    t20 = (t5 + 12U);
    t21 = (t3 != 0);
    if (t21 == 1)
        goto LAB5;

LAB4:    t22 = work_p_2892063302_sub_1835150778_3757376413(t1, t2);
    t23 = (t6 + 56U);
    t24 = *((char **)t23);
    t23 = (t24 + 0);
    memcpy(t23, t22, 16U);
    t7 = work_p_2892063302_sub_1835150778_3757376413(t1, t3);
    t8 = (t12 + 56U);
    t10 = *((char **)t8);
    t8 = (t10 + 0);
    memcpy(t8, t7, 16U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t25 = (0 + 8U);
    t7 = (t8 + t25);
    t26 = *((int *)t7);
    t10 = (t12 + 56U);
    t11 = *((char **)t10);
    t27 = (0 + 8U);
    t10 = (t11 + t27);
    t28 = *((int *)t10);
    t29 = (t26 >= t28);
    if (t29 == 1)
        goto LAB9;

LAB10:    t21 = (unsigned char)0;

LAB11:    if (t21 == 1)
        goto LAB6;

LAB7:    t22 = (t6 + 56U);
    t23 = *((char **)t22);
    t36 = (0 + 12U);
    t22 = (t23 + t36);
    t37 = *((int *)t22);
    t24 = (t12 + 56U);
    t38 = *((char **)t24);
    t39 = (0 + 8U);
    t24 = (t38 + t39);
    t40 = *((int *)t24);
    t41 = (t37 >= t40);
    if (t41 == 1)
        goto LAB12;

LAB13:    t35 = (unsigned char)0;

LAB14:    t19 = t35;

LAB8:    t0 = t19;

LAB1:    return t0;
LAB3:    *((char **)t18) = t2;
    goto LAB2;

LAB5:    *((char **)t20) = t3;
    goto LAB4;

LAB6:    t19 = (unsigned char)1;
    goto LAB8;

LAB9:    t13 = (t6 + 56U);
    t14 = *((char **)t13);
    t30 = (0 + 8U);
    t13 = (t14 + t30);
    t31 = *((int *)t13);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    t32 = (0 + 12U);
    t16 = (t17 + t32);
    t33 = *((int *)t16);
    t34 = (t31 <= t33);
    t21 = t34;
    goto LAB11;

LAB12:    t42 = (t6 + 56U);
    t43 = *((char **)t42);
    t44 = (0 + 12U);
    t42 = (t43 + t44);
    t45 = *((int *)t42);
    t46 = (t12 + 56U);
    t47 = *((char **)t46);
    t48 = (0 + 12U);
    t46 = (t47 + t48);
    t49 = *((int *)t46);
    t50 = (t45 <= t49);
    t35 = t50;
    goto LAB14;

LAB15:;
}


extern void work_p_2892063302_init()
{
	static char *se[] = {(void *)work_p_2892063302_sub_1835150778_3757376413,(void *)work_p_2892063302_sub_1445971953_3757376413,(void *)work_p_2892063302_sub_1445973042_3757376413};
	xsi_register_didat("work_p_2892063302", "isim/tb_pong1_isim_beh.exe.sim/work/p_2892063302.didat");
	xsi_register_subprogram_executes(se);
}
