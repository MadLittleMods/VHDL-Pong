
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name Pong2 -dir "D:/Libraries/EE/FPGA/Basys 2/Pong2/planAhead_run_2" -part xc3s250ecp132-4
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/Libraries/EE/FPGA/Basys 2/Pong2/pong_top.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/Libraries/EE/FPGA/Basys 2/Pong2} }
set_property target_constrs_file "constraints.ucf" [current_fileset -constrset]
add_files [list {constraints.ucf}] -fileset [get_property constrset [current_run]]
link_design
