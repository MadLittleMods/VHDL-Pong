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
extern char *IEEE_P_3972351953;
static const char *ng1 = "Function bool2string_int ended without a return statement";
extern char *STD_STANDARD;

double ieee_p_3972351953_sub_1147618771_2984157535(char *, double );
double ieee_p_3972351953_sub_528838134_2984157535(char *, double );


int work_p_3830156895_sub_3737532971_2311137310(char *t1, int t2)
{
    char t4[8];
    int t0;
    char *t5;
    double t6;
    double t7;
    int t8;
    unsigned char t9;
    unsigned char t10;
    double t11;
    double t12;

LAB0:    t5 = (t4 + 4U);
    *((int *)t5) = t2;
    t6 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, ((double)(t2)));
    t7 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t6);
    t9 = (t7 >= 0);
    if (t9 == 1)
        goto LAB2;

LAB3:    t12 = (t7 - 0.50000000000000000);
    t8 = ((int)(t12));

LAB4:    t0 = t8;

LAB1:    return t0;
LAB2:    t10 = (t7 >= 2147483647);
    if (t10 == 1)
        goto LAB5;

LAB6:    t11 = (t7 + 0.50000000000000000);
    t8 = ((int)(t11));
    goto LAB4;

LAB5:    t8 = 2147483647;
    goto LAB4;

LAB7:;
}

char *work_p_3830156895_sub_1561883244_2311137310(char *t1, char *t2, unsigned char t3)
{
    char t5[8];
    char *t0;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;

LAB0:    t6 = (t5 + 4U);
    *((unsigned char *)t6) = t3;
    if (t3 != 0)
        goto LAB2;

LAB4:    t7 = (t1 + 5865);
    t0 = xsi_get_transient_memory(1U);
    memcpy(t0, t7, 1U);
    t9 = (t2 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 1;
    t10 = (t9 + 4U);
    *((int *)t10) = 1;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t11 = (1 - 1);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;

LAB1:    return t0;
LAB2:    t7 = (t1 + 5864);
    t0 = xsi_get_transient_memory(1U);
    memcpy(t0, t7, 1U);
    t9 = (t2 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 1;
    t10 = (t9 + 4U);
    *((int *)t10) = 1;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t11 = (1 - 1);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    goto LAB1;

LAB3:    xsi_error(ng1);
    t0 = 0;
    goto LAB1;

LAB5:    goto LAB3;

LAB6:    goto LAB3;

}

char *work_p_3830156895_sub_2780417342_2311137310(char *t1, char *t2, int t3, int t4)
{
    char t5[296];
    char t6[16];
    char t7[16];
    char t15[16];
    char t40[16];
    char t63[16];
    char t72[16];
    char t79[16];
    char t80[16];
    char *t0;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    int t13;
    unsigned int t14;
    char *t16;
    unsigned int t17;
    char *t18;
    char *t19;
    int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    int t38;
    unsigned int t39;
    char *t41;
    char *t42;
    int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    int t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    unsigned int t70;
    unsigned char t71;
    unsigned char t73;
    unsigned char t74;
    int t75;
    int t76;
    int t77;
    int t78;
    int t81;
    int t82;
    unsigned int t83;
    int t84;
    int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;

LAB0:    t8 = ((STD_STANDARD) + 384);
    t9 = xsi_int_to_mem(t3);
    t10 = xsi_string_variable_get_image(t7, t8, t9);
    t11 = (t7 + 12U);
    t12 = *((unsigned int *)t11);
    t13 = (t12 - 1);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t14 = (t14 * 1U);
    t16 = (t7 + 12U);
    t17 = *((unsigned int *)t16);
    t18 = (t15 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 1;
    t19 = (t18 + 4U);
    *((unsigned int *)t19) = t17;
    t19 = (t18 + 8U);
    *((int *)t19) = 1;
    t20 = (t17 - 1);
    t21 = (t20 * 1);
    t21 = (t21 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t21;
    t19 = (t5 + 4U);
    t22 = ((STD_STANDARD) + 1008);
    t23 = (t19 + 88U);
    *((char **)t23) = t22;
    t24 = xsi_get_memory(t14);
    t25 = (t19 + 56U);
    *((char **)t25) = t24;
    xsi_type_set_default_value(t22, t24, t15);
    t26 = (t19 + 64U);
    *((char **)t26) = t15;
    t27 = (t19 + 80U);
    *((unsigned int *)t27) = t14;
    t28 = (t19 + 136U);
    *((char **)t28) = t24;
    t29 = (t19 + 124U);
    *((int *)t29) = 0;
    t30 = (t19 + 128U);
    t31 = (t15 + 12U);
    t21 = *((unsigned int *)t31);
    t32 = (t21 - 1);
    *((int *)t30) = t32;
    t33 = (t19 + 120U);
    t35 = (t14 > 2147483644);
    if (t35 == 1)
        goto LAB2;

LAB3:    t36 = (t14 + 3);
    t37 = (t36 / 16);
    t34 = t37;

LAB4:    *((unsigned int *)t33) = t34;
    t38 = (t4 - 1);
    t39 = (t38 * 1);
    t39 = (t39 + 1);
    t39 = (t39 * 1U);
    t41 = (t40 + 0U);
    t42 = (t41 + 0U);
    *((int *)t42) = 1;
    t42 = (t41 + 4U);
    *((int *)t42) = t4;
    t42 = (t41 + 8U);
    *((int *)t42) = 1;
    t43 = (t4 - 1);
    t44 = (t43 * 1);
    t44 = (t44 + 1);
    t42 = (t41 + 12U);
    *((unsigned int *)t42) = t44;
    t42 = (t5 + 148U);
    t45 = ((STD_STANDARD) + 1008);
    t46 = (t42 + 88U);
    *((char **)t46) = t45;
    t47 = xsi_get_memory(t39);
    t48 = (t42 + 56U);
    *((char **)t48) = t47;
    xsi_type_set_default_value(t45, t47, t40);
    t49 = (t42 + 64U);
    *((char **)t49) = t40;
    t50 = (t42 + 80U);
    *((unsigned int *)t50) = t39;
    t51 = (t42 + 136U);
    *((char **)t51) = t47;
    t52 = (t42 + 124U);
    *((int *)t52) = 0;
    t53 = (t42 + 128U);
    t54 = (t40 + 12U);
    t44 = *((unsigned int *)t54);
    t55 = (t44 - 1);
    *((int *)t53) = t55;
    t56 = (t42 + 120U);
    t58 = (t39 > 2147483644);
    if (t58 == 1)
        goto LAB5;

LAB6:    t59 = (t39 + 3);
    t60 = (t59 / 16);
    t57 = t60;

LAB7:    *((unsigned int *)t56) = t57;
    t61 = (t6 + 4U);
    *((int *)t61) = t3;
    t62 = (t6 + 8U);
    *((int *)t62) = t4;
    t64 = ((STD_STANDARD) + 384);
    t65 = xsi_int_to_mem(t3);
    t66 = xsi_string_variable_get_image(t63, t64, t65);
    t67 = (t19 + 56U);
    t68 = *((char **)t67);
    t67 = (t68 + 0);
    t69 = (t63 + 12U);
    t70 = *((unsigned int *)t69);
    memcpy(t67, t66, t70);
    t8 = ((STD_STANDARD) + 384);
    t9 = xsi_int_to_mem(t3);
    t10 = xsi_string_variable_get_image(t7, t8, t9);
    t11 = (t7 + 12U);
    t12 = *((unsigned int *)t11);
    t71 = (t12 < t4);
    if (t71 != 0)
        goto LAB8;

LAB10:    t8 = ((STD_STANDARD) + 384);
    t9 = xsi_int_to_mem(t3);
    t10 = xsi_string_variable_get_image(t7, t8, t9);
    t11 = (t7 + 12U);
    t12 = *((unsigned int *)t11);
    t71 = (t12 > t4);
    if (t71 != 0)
        goto LAB20;

LAB21:    t8 = ((STD_STANDARD) + 384);
    t9 = xsi_int_to_mem(t3);
    t10 = xsi_string_variable_get_image(t7, t8, t9);
    t11 = (t42 + 56U);
    t16 = *((char **)t11);
    t11 = (t16 + 0);
    t18 = (t7 + 12U);
    t12 = *((unsigned int *)t18);
    memcpy(t11, t10, t12);

LAB9:    t8 = (t42 + 56U);
    t9 = *((char **)t8);
    t8 = (t40 + 12U);
    t12 = *((unsigned int *)t8);
    t12 = (t12 * 1U);
    t0 = xsi_get_transient_memory(t12);
    memcpy(t0, t9, t12);
    t10 = (t40 + 0U);
    t13 = *((int *)t10);
    t11 = (t40 + 4U);
    t20 = *((int *)t11);
    t16 = (t40 + 8U);
    t32 = *((int *)t16);
    t18 = (t2 + 0U);
    t22 = (t18 + 0U);
    *((int *)t22) = t13;
    t22 = (t18 + 4U);
    *((int *)t22) = t20;
    t22 = (t18 + 8U);
    *((int *)t22) = t32;
    t38 = (t20 - t13);
    t14 = (t38 * t32);
    t14 = (t14 + 1);
    t22 = (t18 + 12U);
    *((unsigned int *)t22) = t14;

LAB1:    t8 = (t42 + 80);
    t13 = *((int *)t8);
    t9 = (t42 + 136U);
    t10 = *((char **)t9);
    xsi_put_memory(t13, t10);
    t11 = (t19 + 80);
    t20 = *((int *)t11);
    t16 = (t19 + 136U);
    t18 = *((char **)t16);
    xsi_put_memory(t20, t18);
    return t0;
LAB2:    t34 = 2147483647;
    goto LAB4;

LAB5:    t57 = 2147483647;
    goto LAB7;

LAB8:    t16 = ((STD_STANDARD) + 384);
    t18 = xsi_int_to_mem(t3);
    t22 = xsi_string_variable_get_image(t63, t16, t18);
    t23 = ((STD_STANDARD) + 384);
    t24 = xsi_int_to_mem(t3);
    t25 = xsi_string_variable_get_image(t72, t23, t24);
    t26 = (t72 + 12U);
    t14 = *((unsigned int *)t26);
    t13 = (t4 - t14);
    t20 = (t13 - 1);
    t17 = (t20 * 1);
    t17 = (t17 + 1);
    t21 = (1 * t17);
    t34 = (0U + t21);
    t27 = xsi_get_transient_memory(t34);
    memset(t27, 0, t34);
    t28 = t27;
    t29 = (t72 + 12U);
    t35 = *((unsigned int *)t29);
    t43 = (t4 - t35);
    t73 = (1 == 1);
    if (t73 == 1)
        goto LAB11;

LAB12:    t32 = t43;
    t38 = 1;

LAB13:    t74 = (1 == 1);
    if (t74 == 1)
        goto LAB14;

LAB15:    t55 = t38;

LAB16:    t30 = (t72 + 12U);
    t36 = *((unsigned int *)t30);
    t75 = (t4 - t36);
    if (1 == 1)
        goto LAB17;

LAB18:    t37 = t75;

LAB19:    t76 = (t37 - t55);
    t39 = (t76 * 1);
    t44 = (1U * t39);
    t31 = (t28 + t44);
    t33 = (t72 + 12U);
    t57 = *((unsigned int *)t33);
    t77 = (t4 - t57);
    t78 = (t77 - 1);
    t58 = (t78 * 1);
    t58 = (t58 + 1);
    t59 = (1U * t58);
    memset(t31, (unsigned char)32, t59);
    t45 = ((STD_STANDARD) + 1008);
    t46 = (t72 + 12U);
    t60 = *((unsigned int *)t46);
    t81 = (t4 - t60);
    t47 = (t80 + 0U);
    t48 = (t47 + 0U);
    *((int *)t48) = 1;
    t48 = (t47 + 4U);
    *((int *)t48) = t81;
    t48 = (t47 + 8U);
    *((int *)t48) = 1;
    t82 = (t81 - 1);
    t70 = (t82 * 1);
    t70 = (t70 + 1);
    t48 = (t47 + 12U);
    *((unsigned int *)t48) = t70;
    t41 = xsi_base_array_concat(t41, t79, t45, (char)97, t22, t63, (char)97, t27, t80, (char)101);
    t48 = (t42 + 56U);
    t49 = *((char **)t48);
    t48 = (t49 + 0);
    t50 = (t63 + 12U);
    t70 = *((unsigned int *)t50);
    t51 = (t72 + 12U);
    t83 = *((unsigned int *)t51);
    t84 = (t4 - t83);
    t85 = (t84 - 1);
    t86 = (t85 * 1);
    t86 = (t86 + 1);
    t87 = (1 * t86);
    t88 = (0U + t87);
    t89 = (t70 + t88);
    memcpy(t48, t41, t89);
    goto LAB9;

LAB11:    t32 = 1;
    t38 = t43;
    goto LAB13;

LAB14:    t55 = t32;
    goto LAB16;

LAB17:    t37 = 1;
    goto LAB19;

LAB20:    t16 = (t19 + 56U);
    t18 = *((char **)t16);
    t16 = (t15 + 0U);
    t13 = *((int *)t16);
    t14 = (1 - t13);
    t20 = (t4 - 1);
    t22 = (t15 + 4U);
    t32 = *((int *)t22);
    t23 = (t15 + 8U);
    t38 = *((int *)t23);
    xsi_vhdl_check_range_of_slice(t13, t32, t38, 1, t20, 1);
    t17 = (t14 * 1U);
    t21 = (0 + t17);
    t24 = (t18 + t21);
    t25 = (t1 + 5866);
    t28 = ((STD_STANDARD) + 1008);
    t43 = (t4 - 1);
    t29 = (t72 + 0U);
    t30 = (t29 + 0U);
    *((int *)t30) = 1;
    t30 = (t29 + 4U);
    *((int *)t30) = t43;
    t30 = (t29 + 8U);
    *((int *)t30) = 1;
    t55 = (t43 - 1);
    t34 = (t55 * 1);
    t34 = (t34 + 1);
    t30 = (t29 + 12U);
    *((unsigned int *)t30) = t34;
    t30 = (t79 + 0U);
    t31 = (t30 + 0U);
    *((int *)t31) = 1;
    t31 = (t30 + 4U);
    *((int *)t31) = 1;
    t31 = (t30 + 8U);
    *((int *)t31) = 1;
    t75 = (1 - 1);
    t34 = (t75 * 1);
    t34 = (t34 + 1);
    t31 = (t30 + 12U);
    *((unsigned int *)t31) = t34;
    t27 = xsi_base_array_concat(t27, t63, t28, (char)97, t24, t72, (char)97, t25, t79, (char)101);
    t31 = (t42 + 56U);
    t33 = *((char **)t31);
    t31 = (t33 + 0);
    t76 = (t4 - 1);
    t77 = (t76 - 1);
    t34 = (t77 * 1);
    t34 = (t34 + 1);
    t35 = (1U * t34);
    t36 = (t35 + 1U);
    memcpy(t31, t27, t36);
    goto LAB9;

LAB22:;
}


extern void work_p_3830156895_init()
{
	static char *se[] = {(void *)work_p_3830156895_sub_3737532971_2311137310,(void *)work_p_3830156895_sub_1561883244_2311137310,(void *)work_p_3830156895_sub_2780417342_2311137310};
	xsi_register_didat("work_p_3830156895", "isim/tb_pong1_isim_beh.exe.sim/work/p_3830156895.didat");
	xsi_register_subprogram_executes(se);
}
