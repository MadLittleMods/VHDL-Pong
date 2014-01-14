----------------------------------------------------------------------------------
-- Original Author: Eric Eastwood (http://ericeastwood.com/)
-- Original Source: https://github.com/MadLittleMods/VHDL-Pong
-- 
-- Create Date:    14:37:47 12/12/2013 
-- Module Name:    ball - Behavioral 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

library work;
use work.commonPak.all;
use work.fontPak.all;

entity ball is
	generic(
		numCollisionObjects: integer := 2;
		ballRadius : integer := 10;
		rgbColor : std_logic_vector(7 downto 0) := "111" & "111" & "11"
	);
	port(
		reset: in std_logic;
		clk: in std_logic;
		hCount: in integer range 0 to 1023;
		vCount: in integer range 0 to 1023;
		colObject: out type_collisionRect := init_type_collisionRect;
		colObjectArray: in type_collisionRectArray(0 to numCollisionObjects-1);
		
		drawElement: out type_drawElement := init_type_drawElement;
		
		score: out type_score := init_type_score
		
		--debugStrings: out type_ballDebugStrings := init_type_ballDebugStrings
	);
end ball;

architecture Behavioral of ball is
	signal ballObj: type_collisionRect := init_type_collisionRect;
	
	-- Hackaday mode
	signal had_mode: boolean := true;
begin
	
	colObject <= ballObj;
	
	
	anim: process(clk)
		variable update_clk_count: integer := 0;
		variable update_clk_prescaler: integer := 833333; -- 50 Mhz / clk_prescaler = desired speed
		
		variable temp_ballObj: type_collisionRect := ballObj;
		variable temp_ballObj_bounds: type_bounds;
		
		variable currColObjectBounds: type_bounds;
		
		variable xColliding: boolean := false;
		variable yColliding: boolean := false;
		
		variable scoreReg: type_score := init_type_score;
		
		variable temp_had_mode: boolean := true;
		
		--variable debugHasCollided: boolean := false;
	begin
		if rising_edge(clk) then
			if reset = '1' then
				ballObj.pos.x <= SCREEN_RESX/2 - ballRadius;
				ballObj.pos.y <= SCREEN_RESY/2 - ballRadius;
				ballObj.width <= ballRadius * 2;
				ballObj.height <= ballRadius * 2;
				ballObj.velocity.x <= -3;
				ballObj.velocity.y <= 2;
				
				scoreReg := init_type_score;
				had_mode <= false;
				
				--debugStrings  <= init_type_ballDebugStrings;
				
				temp_ballObj := ballObj;
				temp_ballObj_bounds := createBounds(ballObj);
				
				xColliding := false;
				yColliding := false;
				
				--debugHasCollided := false;
				
			else
				if update_clk_count >= update_clk_prescaler then
					
					-- Only activate the Hackaday mode when
					-- Player left has a score of 13 and the right has a score of 37
					-- 1337
					if scoreReg.left = 13 and scoreReg.right = 37 then
						temp_had_mode := true;
					else
						temp_had_mode := false;
					end if;
					
					-- For testing purposes, just make it always had mode
					--temp_had_mode := true;
					
					
					
					-- We create a temp variable copy so that we can do some
					-- stuff that needs to updated right away
					temp_ballObj := ballObj;
					
					-- Hackaday mode
					if temp_had_mode then
						temp_ballObj.width := 13;
						temp_ballObj.height := 13;
					else
						temp_ballObj.width := ballRadius * 2;
						temp_ballObj.height := ballRadius * 2;
					end if;
					
					-- Move the temp to the real
					had_mode <= temp_had_mode;
					
					
					
					-- Update this before we need to use it
					temp_ballObj_bounds := createBounds(ballObj);
					
					
					-- SCORE! The Right player scored on the left side
					if temp_ballObj_bounds.left < 0 then
						temp_ballObj.pos.x := SCREEN_RESX/2 - ballRadius;
						temp_ballObj.pos.y := SCREEN_RESY/2 - ballRadius;
						
						scoreReg.right := scoreReg.right + 1;
					
					-- SCORE! The Left player scored on  the right
					elsif temp_ballObj_bounds.right > SCREEN_RESX-1 then
						temp_ballObj.pos.x := SCREEN_RESX/2 - ballRadius;
						temp_ballObj.pos.y := SCREEN_RESY/2 - ballRadius;
						
						scoreReg.left := scoreReg.left + 1;
					end if;
					
					
					score <= scoreReg;
					
					
					
					-- Update this before we need to use it
					temp_ballObj_bounds := createBounds(ballObj);
					
					-- We hit the top or bottom wall
					if temp_ballObj_bounds.top < 0 or temp_ballObj_bounds.bottom > SCREEN_RESY-1 then
						-- Reflect off the edge
						temp_ballObj.velocity.y := temp_ballObj.velocity.y * (-1);
					end if;
					
					
					
				
					-- Update X
					temp_ballObj.pos.x := temp_ballObj.pos.x + temp_ballObj.velocity.x;
					
					for i in colObjectArray'range loop
						-- Use this for collision resolution
						currColObjectBounds := createBounds(colObjectArray(i));
						
						-- Check Collisions
						xColliding := false;
						yColliding := false;
						xColliding := xColliding or CheckCollisionX(temp_ballObj, colObjectArray(i));
						yColliding := yColliding or CheckCollisionY(temp_ballObj, colObjectArray(i));
						
						--debugHasCollided := debugHasCollided or (xColliding and yColliding);
						
						-- Resolve X collisions
						if xColliding and yColliding then
							
							if temp_ballObj.velocity.x > 0 then
								temp_ballObj.pos.x := currColObjectBounds.left-temp_ballObj.width-1;
							else
								temp_ballObj.pos.x := currColObjectBounds.right+1;
							end if;
							
							-- Reflect off the object
							temp_ballObj.velocity.x := temp_ballObj.velocity.x * (-1);
							
							
						end if;
					end loop;
				
				
				
					-- Update Y
					temp_ballObj.pos.y := temp_ballObj.pos.y + temp_ballObj.velocity.y;
					
					for i in colObjectArray'range loop
						-- Use this for collision resolution
						currColObjectBounds := createBounds(colObjectArray(i));
					
						-- Check Collisions
						xColliding := false;
						yColliding := false;
						xColliding := xColliding or CheckCollisionX(temp_ballObj, colObjectArray(i));
						yColliding := yColliding or CheckCollisionY(temp_ballObj, colObjectArray(i));

						--debugHasCollided := debugHasCollided or (xColliding and yColliding);

						-- Resolve Y collisions
						if xColliding and yColliding then
							
							if temp_ballObj.velocity.y > 0 then
								temp_ballObj.pos.y := currColObjectBounds.top-temp_ballObj.height-1;
							else
								temp_ballObj.pos.y := currColObjectBounds.bottom+1;
							end if;
							
							
							-- Reflect off the object
							-- and Add glancing blow velocity from the paddle
							temp_ballObj.velocity.y := (temp_ballObj.velocity.y * (-1)) + colObjectArray(i).velocity.y;
						end if;
					end loop;
				
					
					-- Update the debug strings
					--debugStrings.collisions <= "c| x: " & bool2string_int(debugHasCollided) & " - y: " & bool2string_int(debugHasCollided); -- boolean'image(xColliding)
					--debugStrings.velocity <= "v| x: " & integer2string_pad(temp_ballObj.velocity.x, 3) & " - y: " & integer2string_pad(temp_ballObj.velocity.y, 3);
					--report "|" & integer2string_pad(temp_ballObj.velocity.x, 3) & "|";
					
					-- Now apply it to the actual object
					ballObj <= temp_ballObj;
					
					
					
					
					update_clk_count := 0;
				end if;
				
				update_clk_count := update_clk_count + 1;
			end if;
		end if;
	
	end process;


	drawing: process(clk)
		variable objectBounds: type_bounds;
		
		type had_store_type is array (0 to 12) of std_logic_vector(12 downto 0);
		variable had_logo: had_store_type := (
			"0110000000110",
			"1010000000101",
			"1111000001111",
			"0011011101100",
			"0000111110000",
			"0001001001000",
			"0001011101000",
			"0001110111000",
			"0000111110000",
			"0010101010100",
			"1111000001111",
			"1010000000101",
			"0110000000110"
		);
	begin
		if rising_edge(clk) then
			if reset = '1' then
				drawElement.pixelOn <= false;
				drawElement.rgb <= (others => '0');
			else
				drawElement.rgb <= rgbColor;

				objectBounds := createBounds(ballObj);

				-- If within pixel bounds of bar
				if hCount >= objectBounds.left and hCount <= objectBounds.right and vCount >= objectBounds.top and vCount <= objectBounds.bottom then
					if had_mode then
						if had_logo(vCount - objectBounds.top)(had_logo(0)'length-1 - (hCount - objectBounds.left)) = '1' then
							drawElement.pixelOn <= true;
						else
							drawElement.pixelOn <= false;
						end if;
					else
						-- else we draw a solid ball
						drawElement.pixelOn <= true;
					end if;
					
				else
					drawElement.pixelOn <= false;
				end if;
				
				
				
				
			end if;
		end if;
	end process;


end Behavioral;

