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
static const char *ng0 = "D:/Libraries/EE/FPGA/Basys 2/Pong2/paddle.vhd";
extern char *IEEE_P_2592010699;
extern char *WORK_P_2892063302;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *work_p_2892063302_sub_1835150778_3757376413(char *, char *);


static void work_a_1243395395_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(60, ng0);

LAB3:    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 5320);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 5208);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1243395395_3212880686_p_1(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    int t14;
    int t15;
    int t16;
    int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned char t23;
    unsigned char t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    int t28;
    int t29;
    int t30;
    unsigned int t31;
    unsigned int t32;
    int t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    int t38;
    int t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    static char *nl0[] = {&&LAB9, &&LAB10, &&LAB11, &&LAB11};

LAB0:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5224);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(72, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(101, ng0);
    t1 = (t0 + 2928U);
    t3 = *((char **)t1);
    t9 = *((int *)t3);
    t1 = (t0 + 3048U);
    t4 = *((char **)t1);
    t14 = *((int *)t4);
    t2 = (t9 >= t14);
    if (t2 != 0)
        goto LAB12;

LAB14:
LAB13:    xsi_set_current_line(140, ng0);
    t1 = (t0 + 2928U);
    t3 = *((char **)t1);
    t9 = *((int *)t3);
    t14 = (t9 + 1);
    t1 = (t0 + 2928U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    *((int *)t1) = t14;

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(74, ng0);
    t3 = (char *)((nl0) + (unsigned char)1);
    goto **((char **)t3);

LAB8:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 5384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_delta(t1, 4U, 1, 0LL);
    xsi_set_current_line(97, ng0);
    t1 = (t0 + 5384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_delta(t1, 5U, 1, 0LL);
    goto LAB6;

LAB9:    xsi_set_current_line(77, ng0);
    t7 = (t0 + 3288U);
    t8 = *((char **)t7);
    t9 = *((int *)t8);
    t7 = (t0 + 5384);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((int *)t13) = t9;
    xsi_driver_first_trans_delta(t7, 0U, 1, 0LL);
    xsi_set_current_line(78, ng0);
    t1 = ((WORK_P_2892063302) + 1288U);
    t3 = *((char **)t1);
    t9 = *((int *)t3);
    t14 = (t9 / 2);
    t15 = (t14 - 1);
    t16 = (60 / 2);
    t17 = (t15 - t16);
    t1 = (t0 + 5384);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    *((int *)t10) = t17;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 5384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 10;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);
    xsi_set_current_line(81, ng0);
    t1 = (t0 + 5384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 60;
    xsi_driver_first_trans_delta(t1, 3U, 1, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(85, ng0);
    t1 = ((WORK_P_2892063302) + 1168U);
    t3 = *((char **)t1);
    t9 = *((int *)t3);
    t14 = (t9 - 10);
    t1 = (t0 + 3288U);
    t4 = *((char **)t1);
    t15 = *((int *)t4);
    t16 = (t14 - t15);
    t1 = (t0 + 5384);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    *((int *)t11) = t16;
    xsi_driver_first_trans_delta(t1, 0U, 1, 0LL);
    xsi_set_current_line(86, ng0);
    t1 = ((WORK_P_2892063302) + 1288U);
    t3 = *((char **)t1);
    t9 = *((int *)t3);
    t14 = (t9 / 2);
    t15 = (t14 - 1);
    t16 = (60 / 2);
    t17 = (t15 - t16);
    t1 = (t0 + 5384);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    *((int *)t10) = t17;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);
    xsi_set_current_line(88, ng0);
    t1 = (t0 + 5384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 10;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);
    xsi_set_current_line(89, ng0);
    t1 = (t0 + 5384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 60;
    xsi_driver_first_trans_delta(t1, 3U, 1, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(92, ng0);
    goto LAB8;

LAB12:    xsi_set_current_line(102, ng0);
    t1 = (t0 + 1832U);
    t7 = *((char **)t1);
    t18 = (0 + 1U);
    t1 = (t7 + t18);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB15;

LAB17:
LAB16:    xsi_set_current_line(106, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t18 = (0 + 0U);
    t1 = (t3 + t18);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB18;

LAB20:
LAB19:    xsi_set_current_line(111, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t18 = (0 + 0U);
    t1 = (t3 + t18);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB24;

LAB25:    t2 = (unsigned char)0;

LAB26:    if (t2 != 0)
        goto LAB21;

LAB23:
LAB22:    xsi_set_current_line(117, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = work_p_2892063302_sub_1835150778_3757376413(WORK_P_2892063302, t3);
    t4 = (t0 + 3168U);
    t7 = *((char **)t4);
    t4 = (t7 + 0);
    memcpy(t4, t1, 16U);
    xsi_set_current_line(121, ng0);
    t1 = (t0 + 3168U);
    t3 = *((char **)t1);
    t18 = (0 + 8U);
    t1 = (t3 + t18);
    t9 = *((int *)t1);
    t4 = (t0 + 2152U);
    t7 = *((char **)t4);
    t19 = (0 + 16U);
    t20 = (t19 + 4U);
    t4 = (t7 + t20);
    t14 = *((int *)t4);
    t15 = (t9 + t14);
    t5 = (t15 >= 0);
    if (t5 == 1)
        goto LAB30;

LAB31:    t2 = (unsigned char)0;

LAB32:    if (t2 != 0)
        goto LAB27;

LAB29:    xsi_set_current_line(126, ng0);
    t1 = (t0 + 3168U);
    t3 = *((char **)t1);
    t18 = (0 + 8U);
    t1 = (t3 + t18);
    t9 = *((int *)t1);
    t4 = (t0 + 2152U);
    t7 = *((char **)t4);
    t19 = (0 + 16U);
    t20 = (t19 + 4U);
    t4 = (t7 + t20);
    t14 = *((int *)t4);
    t15 = (t9 + t14);
    t2 = (t15 < 0);
    if (t2 != 0)
        goto LAB33;

LAB35:    t1 = (t0 + 3168U);
    t3 = *((char **)t1);
    t18 = (0 + 12U);
    t1 = (t3 + t18);
    t9 = *((int *)t1);
    t4 = (t0 + 2152U);
    t7 = *((char **)t4);
    t19 = (0 + 16U);
    t20 = (t19 + 4U);
    t4 = (t7 + t20);
    t14 = *((int *)t4);
    t15 = (t9 + t14);
    t8 = ((WORK_P_2892063302) + 1288U);
    t10 = *((char **)t8);
    t16 = *((int *)t10);
    t17 = (t16 - 1);
    t2 = (t15 > t17);
    if (t2 != 0)
        goto LAB36;

LAB37:
LAB34:    xsi_set_current_line(133, ng0);
    t1 = (t0 + 5384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_delta(t1, 5U, 1, 0LL);

LAB28:    xsi_set_current_line(137, ng0);
    t1 = (t0 + 2928U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    *((int *)t1) = 0;
    goto LAB13;

LAB15:    xsi_set_current_line(103, ng0);
    t8 = (t0 + 2152U);
    t10 = *((char **)t8);
    t19 = (0 + 16U);
    t20 = (t19 + 4U);
    t8 = (t10 + t20);
    t15 = *((int *)t8);
    t16 = (t15 + 1);
    t11 = (t0 + 5384);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t21 = (t13 + 56U);
    t22 = *((char **)t21);
    *((int *)t22) = t16;
    xsi_driver_first_trans_delta(t11, 5U, 1, 0LL);
    goto LAB16;

LAB18:    xsi_set_current_line(107, ng0);
    t4 = (t0 + 2152U);
    t7 = *((char **)t4);
    t19 = (0 + 16U);
    t20 = (t19 + 4U);
    t4 = (t7 + t20);
    t9 = *((int *)t4);
    t14 = (t9 - 1);
    t8 = (t0 + 5384);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((int *)t13) = t14;
    xsi_driver_first_trans_delta(t8, 5U, 1, 0LL);
    goto LAB19;

LAB21:    xsi_set_current_line(112, ng0);
    t8 = (t0 + 5384);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((int *)t13) = 0;
    xsi_driver_first_trans_delta(t8, 5U, 1, 0LL);
    goto LAB22;

LAB24:    t4 = (t0 + 1832U);
    t7 = *((char **)t4);
    t19 = (0 + 1U);
    t4 = (t7 + t19);
    t23 = *((unsigned char *)t4);
    t24 = (t23 == (unsigned char)2);
    t2 = t24;
    goto LAB26;

LAB27:    xsi_set_current_line(122, ng0);
    t13 = (t0 + 2152U);
    t22 = *((char **)t13);
    t31 = (0 + 0U);
    t32 = (t31 + 4U);
    t13 = (t22 + t32);
    t33 = *((int *)t13);
    t34 = (t0 + 2152U);
    t35 = *((char **)t34);
    t36 = (0 + 16U);
    t37 = (t36 + 4U);
    t34 = (t35 + t37);
    t38 = *((int *)t34);
    t39 = (t33 + t38);
    t40 = (t0 + 5384);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    *((int *)t44) = t39;
    xsi_driver_first_trans_delta(t40, 1U, 1, 0LL);
    goto LAB28;

LAB30:    t8 = (t0 + 3168U);
    t10 = *((char **)t8);
    t25 = (0 + 12U);
    t8 = (t10 + t25);
    t16 = *((int *)t8);
    t11 = (t0 + 2152U);
    t12 = *((char **)t11);
    t26 = (0 + 16U);
    t27 = (t26 + 4U);
    t11 = (t12 + t27);
    t17 = *((int *)t11);
    t28 = (t16 + t17);
    t13 = ((WORK_P_2892063302) + 1288U);
    t21 = *((char **)t13);
    t29 = *((int *)t21);
    t30 = (t29 - 1);
    t6 = (t28 <= t30);
    t2 = t6;
    goto LAB32;

LAB33:    xsi_set_current_line(127, ng0);
    t8 = (t0 + 5384);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((int *)t13) = 0;
    xsi_driver_first_trans_delta(t8, 1U, 1, 0LL);
    goto LAB34;

LAB36:    xsi_set_current_line(129, ng0);
    t8 = ((WORK_P_2892063302) + 1288U);
    t11 = *((char **)t8);
    t28 = *((int *)t11);
    t29 = (t28 - 60);
    t8 = (t0 + 5384);
    t12 = (t8 + 56U);
    t13 = *((char **)t12);
    t21 = (t13 + 56U);
    t22 = *((char **)t21);
    *((int *)t22) = t29;
    xsi_driver_first_trans_delta(t8, 1U, 1, 0LL);
    goto LAB34;

}

static void work_a_1243395395_3212880686_p_2(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    int t13;
    unsigned char t14;
    int t15;
    unsigned int t16;
    int t17;
    unsigned char t18;
    char *t19;
    int t20;
    char *t21;
    unsigned int t22;
    int t23;
    unsigned char t24;
    char *t25;
    char *t26;
    int t27;
    char *t28;
    unsigned int t29;
    int t30;
    unsigned char t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(150, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5240);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(151, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(155, ng0);
    t1 = (t0 + 8472);
    t4 = (t0 + 5448);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_delta(t4, 1U, 8U, 0LL);
    xsi_set_current_line(157, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = work_p_2892063302_sub_1835150778_3757376413(WORK_P_2892063302, t3);
    t4 = (t0 + 3408U);
    t7 = *((char **)t4);
    t4 = (t7 + 0);
    memcpy(t4, t1, 16U);
    xsi_set_current_line(160, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t1 = (t0 + 3408U);
    t4 = *((char **)t1);
    t12 = (0 + 0U);
    t1 = (t4 + t12);
    t13 = *((int *)t1);
    t14 = (t11 >= t13);
    if (t14 == 1)
        goto LAB17;

LAB18:    t6 = (unsigned char)0;

LAB19:    if (t6 == 1)
        goto LAB14;

LAB15:    t5 = (unsigned char)0;

LAB16:    if (t5 == 1)
        goto LAB11;

LAB12:    t2 = (unsigned char)0;

LAB13:    if (t2 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(163, ng0);
    t1 = (t0 + 5448);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_delta(t1, 0U, 1, 0LL);

LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(152, ng0);
    t3 = (t0 + 5448);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_delta(t3, 0U, 1, 0LL);
    xsi_set_current_line(153, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t3 = t1;
    memset(t3, (unsigned char)2, 8U);
    t4 = (t0 + 5448);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_delta(t4, 1U, 8U, 0LL);
    goto LAB6;

LAB8:    xsi_set_current_line(161, ng0);
    t32 = (t0 + 5448);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    *((unsigned char *)t36) = (unsigned char)1;
    xsi_driver_first_trans_delta(t32, 0U, 1, 0LL);
    goto LAB9;

LAB11:    t25 = (t0 + 1512U);
    t26 = *((char **)t25);
    t27 = *((int *)t26);
    t25 = (t0 + 3408U);
    t28 = *((char **)t25);
    t29 = (0 + 12U);
    t25 = (t28 + t29);
    t30 = *((int *)t25);
    t31 = (t27 <= t30);
    t2 = t31;
    goto LAB13;

LAB14:    t10 = (t0 + 1512U);
    t19 = *((char **)t10);
    t20 = *((int *)t19);
    t10 = (t0 + 3408U);
    t21 = *((char **)t10);
    t22 = (0 + 8U);
    t10 = (t21 + t22);
    t23 = *((int *)t10);
    t24 = (t20 >= t23);
    t5 = t24;
    goto LAB16;

LAB17:    t7 = (t0 + 1352U);
    t8 = *((char **)t7);
    t15 = *((int *)t8);
    t7 = (t0 + 3408U);
    t9 = *((char **)t7);
    t16 = (0 + 4U);
    t7 = (t9 + t16);
    t17 = *((int *)t7);
    t18 = (t15 <= t17);
    t6 = t18;
    goto LAB19;

}


extern void work_a_1243395395_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1243395395_3212880686_p_0,(void *)work_a_1243395395_3212880686_p_1,(void *)work_a_1243395395_3212880686_p_2};
	xsi_register_didat("work_a_1243395395_3212880686", "isim/tb_pong1_isim_beh.exe.sim/work/a_1243395395_3212880686.didat");
	xsi_register_executes(pe);
}
