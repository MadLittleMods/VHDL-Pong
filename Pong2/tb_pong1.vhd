--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:07:52 12/12/2013
-- Design Name:   
-- Module Name:   D:/Libraries/EE/FPGA/Basys 2/Pong2/tb_pong1.vhd
-- Project Name:  Pong2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: pong_top
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
USE ieee.numeric_std.ALL;


use ieee.std_logic_textio.all;
use std.textio.all;


ENTITY tb_pong1 IS
END tb_pong1;
 
ARCHITECTURE behavior OF tb_pong1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT pong_top
    PORT(
        clk: in std_logic;
		sw: in std_logic_vector(7 downto 0); -- sw0 is reset
		btn: in std_logic_vector(3 downto 0);
		Led: out std_logic_vector(7 downto 0);
		
		hsync: out std_logic;
		vsync: out std_logic;
		Red: out std_logic_vector(2 downto 0);
		Green: out std_logic_vector(2 downto 0);
		Blue: out std_logic_vector(2 downto 1);
		
		seg: out std_logic_vector(6 downto 0);
		an: out std_logic_vector(3 downto 0)
	);
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal sw : std_logic_vector(7 downto 0) := (others => '0');
   signal btn : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Led : std_logic_vector(7 downto 0);
   signal hsync : std_logic;
   signal vsync : std_logic;
   signal Red : std_logic_vector(2 downto 0);
   signal Green : std_logic_vector(2 downto 0);
   signal Blue : std_logic_vector(2 downto 1);
   signal seg : std_logic_vector(6 downto 0);
   signal an : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: pong_top PORT MAP (
          clk => clk,
          sw => sw,
          btn => btn,
          Led => Led,
          hsync => hsync,
          vsync => vsync,
          Red => Red,
          Green => Green,
          Blue => Blue,
		  seg => seg,
		  an => an
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

	-- Stimulus process
	stim_proc: process
	begin		
		-- hold reset state for 100 ns.
		wait for 100 ns;	

		wait for clk_period*10;

		-- insert stimulus here 
		sw(0) <= '1';
		wait for 100 ns;
		sw(0) <= '0';

		wait;
	end process;



	process (clk)
		file file_pointer: text is out "write.txt";
		variable line_el: line;
	begin

		if rising_edge(clk) then

			-- Write the time
			write(line_el, now); -- write the line.
			write(line_el, ":"); -- write the line.

			-- Write the hsync
			write(line_el, " ");
			write(line_el, hsync); -- write the line.

			-- Write the vsync
			write(line_el, " ");
			write(line_el, vsync); -- write the line.

			-- Write the red
			write(line_el, " ");
			write(line_el, Red); -- write the line.

			-- Write the green
			write(line_el, " ");
			write(line_el, Green); -- write the line.

			-- Write the blue
			write(line_el, " ");
			write(line_el, Blue); -- write the line.

			writeline(file_pointer, line_el); -- write the contents into the file.

		end if;
	end process;

END;
