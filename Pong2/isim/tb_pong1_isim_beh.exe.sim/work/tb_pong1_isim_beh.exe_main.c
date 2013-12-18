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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *IEEE_P_3972351953;
char *WORK_P_2892063302;
char *WORK_P_3830156895;
char *IEEE_P_1242562249;
char *IEEE_P_3564397177;
char *STD_TEXTIO;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    std_textio_init();
    ieee_p_3564397177_init();
    work_p_2892063302_init();
    ieee_p_3972351953_init();
    work_p_3830156895_init();
    work_a_0624366421_3212880686_init();
    work_a_1243395395_3212880686_init();
    work_a_3709530218_3212880686_init();
    work_a_3840338369_3212880686_init();
    work_a_0679969511_3212880686_init();
    work_a_0644304968_3212880686_init();
    work_a_3731669840_3212880686_init();
    work_a_3855696906_3212880686_init();
    work_a_0335020208_3212880686_init();
    work_a_0962481081_3212880686_init();
    work_a_3115483099_2372691052_init();


    xsi_register_tops("work_a_3115483099_2372691052");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_3972351953 = xsi_get_engine_memory("ieee_p_3972351953");
    WORK_P_2892063302 = xsi_get_engine_memory("work_p_2892063302");
    WORK_P_3830156895 = xsi_get_engine_memory("work_p_3830156895");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    IEEE_P_3564397177 = xsi_get_engine_memory("ieee_p_3564397177");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");

    return xsi_run_simulation(argc, argv);

}
