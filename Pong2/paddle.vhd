----------------------------------------------------------------------------------
-- Original Author: Eric Eastwood (http://ericeastwood.com/)
-- Original Source: https://github.com/MadLittleMods/VHDL-Pong
-- 
-- Create Date:    13:50:33 12/12/2013 
-- Module Name:    paddle - Behavioral 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;


library work;
use work.commonPak.all;


entity paddle is
	generic(
		sidePos : type_side := left;
		paddleLength : integer := 60;
		paddleWidth : integer := 10;
		rgbColor : std_logic_vector(7 downto 0) := "111" & "111" & "11"
	);
	port(
		reset: in std_logic;
		clk: in std_logic;
		hCount: in integer range 0 to 1023;
		vCount: in integer range 0 to 1023;
		colObject: out type_collisionRect := init_type_collisionRect;
		
		controls: in type_controls;
		drawElement: out type_drawElement := init_type_drawElement
	);
end paddle;

architecture Behavioral of paddle is
	signal paddleObj: type_collisionRect := init_type_collisionRect;
begin

	colObject <= paddleObj;

	anim: process(clk)
		variable update_clk_count: integer := 0;
		variable update_clk_prescaler: integer := 833333; -- 50 Mhz / clk_prescaler = desired speed
		
		variable paddleBounds: type_bounds;
		
		variable spaceFromWall: integer := 20;
		
	begin
		if rising_edge(clk) then
			if reset = '1' then

				case sidePos is
					-- Make the paddle vertical
					when left => 
						paddleObj.pos.x <= spaceFromWall;
						paddleObj.pos.y <= (SCREEN_RESY/2)-1 - (paddleLength/2);
						
						paddleObj.width <= paddleWidth;
						paddleObj.height <= paddleLength;
						
					-- Make the paddle vertical
					when right => 
						paddleObj.pos.x <= SCREEN_RESX - paddleWidth - spaceFromWall;
						paddleObj.pos.y <= (SCREEN_RESY/2)-1 - (paddleLength/2);
						
						paddleObj.width <= paddleWidth;
						paddleObj.height <= paddleLength;
						
					when others =>
						null;
						
				end case;
				
				paddleObj.velocity.x <= 0;
				paddleObj.velocity.y <= 0;
				
				
			else
				if update_clk_count >= update_clk_prescaler then
					if controls.down = '1' then
						paddleObj.velocity.y <= paddleObj.velocity.y + 1;
					end if;

					if controls.up = '1' then
						paddleObj.velocity.y <= paddleObj.velocity.y - 1;
					end if;

					-- Bleed off the velocity
					if controls.up = '0' and controls.down = '0' then
						paddleObj.velocity.y <= 0;
					end if;
					
					
					-- Create the nice bound object
					paddleBounds := createBounds(paddleObj);
					
					-- If top edge of paddle not at the top then we can move up
					-- If bottom edge of paddle not at the bottom then we can move down
					if paddleBounds.top + paddleObj.velocity.y >= 0 and paddleBounds.bottom + paddleObj.velocity.y <= SCREEN_RESY-1 then
						paddleObj.pos.y <= paddleObj.pos.y + paddleObj.velocity.y;				
					else
						
						-- Get them at the limit they wanted
						if paddleBounds.top + paddleObj.velocity.y < 0 then
							paddleObj.pos.y <= 0;
						elsif paddleBounds.bottom + paddleObj.velocity.y > SCREEN_RESY-1 then
							paddleObj.pos.y <= SCREEN_RESY - paddleLength;
						end if;
						
						-- If you hit a wall bleed off...
						paddleObj.velocity.y <= 0;
					end if;
					
					
					update_clk_count := 0;
				end if;

				update_clk_count := update_clk_count + 1;
			end if;
		end if;
	
	end process;


	drawing: process(clk)
		variable objectBounds: type_bounds;
	begin
		if rising_edge(clk) then
			if reset = '1' then
				drawElement.pixelOn <= false;
				drawElement.rgb <= (others => '0');
			else
				drawElement.rgb <= rgbColor;

				objectBounds := createBounds(paddleObj);

				-- If within pixel bounds of bar
				if hCount >= objectBounds.left and hCount <= objectBounds.right and vCount >= objectBounds.top and vCount <= objectBounds.bottom then
					drawElement.pixelOn <= true;
				else
					drawElement.pixelOn <= false;
				end if;
				
			end if;
		end if;
	end process;


end Behavioral;

