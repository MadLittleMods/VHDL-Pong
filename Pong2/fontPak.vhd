----------------------------------------------------------------------------------
-- Original Author: Eric Eastwood (http://ericeastwood.com/)
-- Original Source: https://github.com/MadLittleMods/FP-V-GA-Text
-- 
-- Create Date:    15:24:50 11/19/2013 
-- Module Name:    fontPak - Behavioral 
--
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

use ieee.math_real.all;

package fontPak is
	
	
	
	constant ADDR_WIDTH : integer := 11;
	constant DATA_WIDTH : integer := 8;
	
	constant FONT_WIDTH : integer := 8;
	constant FONT_HEIGHT : integer := 16;

------------------------------------------

	type type_textColorMap is array(natural range <>) of std_logic_vector(7 downto 0); 
	
------------------------------------------

	type type_inArbiterPort is
	record
		dataRequest: boolean;
		addr: std_logic_vector(ADDR_WIDTH-1 downto 0);
		writeRequest: boolean;
		writeData: std_logic_vector(DATA_WIDTH-1 downto 0);
	end record;
	constant init_type_inArbiterPort: type_inArbiterPort := (dataRequest => false, addr => (others => '0'), writeRequest => false, writeData  => (others => '0'));
	type type_inArbiterPortArray is array(natural range <>) of type_inArbiterPort;
	
	
	type type_outArbiterPort is
	record
		dataWaiting: boolean;
		data: std_logic_vector(DATA_WIDTH-1 downto 0);
		dataWritten: boolean;
	end record;
	constant init_type_outArbiterPort: type_outArbiterPort := (dataWaiting => false, data => (others => '0'), dataWritten => false);
	type type_outArbiterPortArray is array(natural range <>) of type_outArbiterPort;


----------------------

	function log2_float(val : positive) return natural;
	
	-- Converts a boolean(true or false) into a string(0 or 1)
	-- Always returns a string size 1
	function bool2string_int(test : boolean) return string;
	
	-- Converts a integer to string and 
	-- Always returns a string sized as the specified depth
	function integer2string_pad(val: integer; stringSize: integer) return string;

end fontPak;

package body fontPak is
	function log2_float(val : positive) return natural is
	begin
		return integer(ceil(log2(real(val))));
	end function;
	
	function bool2string_int(test : boolean) return string is
	begin
		if test then
			return "1";
		else
			return "0";
		end if;
	end function;
	
	function integer2string_pad(val: integer; stringSize: integer) return string is
		variable imageString: string(1 to integer'image(val)'length);
		variable returnString: string(1 to stringSize);
	begin
		imageString := integer'image(val);
	
		-- Are we smaller than the desired size?
		if integer'image(val)'length < stringSize then
			-- Pad the string if we are
			returnString := integer'image(val) & (1 to stringSize-integer'image(val)'length => ' ');
			
		-- Are we to big for the desired size
		elsif integer'image(val)'length > stringSize then
			-- Only use the top most string bits and append a "." to the end signifing that there is more
			returnString := imageString(1 to stringSize-1) & ".";
		
		-- Otherwise we are just the right size
		else
			returnString := integer'image(val);
		end if;
		
		
		return returnString;
	end function;
	
end fontPak;
