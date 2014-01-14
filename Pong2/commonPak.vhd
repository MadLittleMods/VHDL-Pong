----------------------------------------------------------------------------------
-- Original Author: Eric Eastwood (http://ericeastwood.com/)
-- Original Source: https://github.com/MadLittleMods/VHDL-Pong
-- 
-- Create Date:    13:29:20 12/12/2013 
-- Module Name:    commonPak - Behavioral 
--
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.ALL;

package commonPak is

	constant SCREEN_RESX: integer := 640;
	constant SCREEN_RESY: integer := 480;


	-- We use this to place paddles
	type type_side is (left, right, top, bottom);

	-- This is just a useful type when doing collision
	type type_bounds is
	record
		left : integer range -8192 to 8191;
		right : integer range -8192 to 8191;
		top : integer range -8192 to 8191;
		bottom : integer range -8192 to 8191;
	end record;
	
	-- Just something useful
	type point_2d is
	record
		x : integer range -4096 to 4095;
		y : integer range -4096 to 4095;
	end record;
	constant init_point_2d: point_2d := (x => 0, y => 0);

	-- The main obj to figure out everything
	type type_collisionRect is
	record
		pos : point_2d; -- top left
		width : integer range 0 to 4095;
		height : integer range 0 to 4095;
		velocity : point_2d;
	end record;
	constant init_type_collisionRect: type_collisionRect := (pos => init_point_2d, width => 0, height => 0, velocity => init_point_2d);
	type type_collisionRectArray is array(natural range <>) of type_collisionRect; 


	-- What we use to pass around to draw
	type type_drawElement is
	record
		pixelOn: boolean;
		rgb: std_logic_vector(7 downto 0);
	end record;
	constant init_type_drawElement: type_drawElement := (pixelOn => false, rgb => (others => '0'));
	type type_drawElementArray is array(natural range <>) of type_drawElement; 


	type type_controls is
	record
		up : std_logic;
		down : std_logic;
	end record;


	type type_score is
	record
		left : integer range 0 to 255;
		right : integer range 0 to 255;
	end record;
	constant init_type_score: type_score := (left => 0, right => 0);
	
	
	type type_ballDebugStrings is
	record
		collisions : string(1 to 14); -- c| x: 0 - y: 0
		velocity : string(1 to 18); -- v| x: 100 - y: -99
	end record;
	constant init_type_ballDebugStrings: type_ballDebugStrings := (collisions => (others => NUL), velocity => (others => NUL));

	
	function createBounds(colObject : type_collisionRect) return type_bounds;
	function CheckCollisionX (rect1, rect2 : type_collisionRect) return boolean;
	function CheckCollisionY (rect1, rect2 : type_collisionRect) return boolean;
	
	function int_bcd2(val: integer) return std_logic_vector;
	
end commonPak;

package body commonPak is

	function createBounds(colObject : type_collisionRect) return type_bounds is
		variable bounds: type_bounds;
	begin
		bounds.left := colObject.pos.x;
		bounds.right := colObject.pos.x + colObject.width-1;
		bounds.top := colObject.pos.y;
		bounds.bottom := colObject.pos.y + colObject.height-1;
	
		return bounds;
	end createBounds;


	-- right edge of ball in between objects left and right edge
	-- OR
	-- left edge of ball in between objects left and right edge
	function CheckCollisionX (rect1, rect2 : type_collisionRect) return boolean is
		variable rect1_bounds: type_bounds;
		variable rect2_bounds: type_bounds;
	begin
		rect1_bounds := createBounds(rect1);
		rect2_bounds := createBounds(rect2);
	
		return (rect1_bounds.right >= rect2_bounds.left and rect1_bounds.right <= rect2_bounds.right)
			or (rect1_bounds.left >= rect2_bounds.left and rect1_bounds.left <= rect2_bounds.right);
	end CheckCollisionX;
	
	-- top edge of ball in between objects top and bottom edge
	-- OR
	-- bottom edge of ball in between objects top and bottom edge
	function CheckCollisionY (rect1, rect2 : type_collisionRect) return boolean is
		variable rect1_bounds: type_bounds;
		variable rect2_bounds: type_bounds;
	begin
		rect1_bounds := createBounds(rect1);
		rect2_bounds := createBounds(rect2);
		
		return (rect1_bounds.top >= rect2_bounds.top and rect1_bounds.top <= rect2_bounds.bottom)
			or (rect1_bounds.bottom >= rect2_bounds.top and rect1_bounds.bottom <= rect2_bounds.bottom);
	end CheckCollisionY;
 
 
	function int_bcd2(val: integer) return std_logic_vector is
		variable bcd : std_logic_vector(7 downto 0) := (others => '0');
		variable bint : std_logic_vector(7 downto 0) := std_logic_vector(to_unsigned(val, 8));
	begin
		for i in 0 to 7 loop 
			bcd(7 downto 1) := bcd(6 downto 0);  -- shifting left 1
			bcd(0) := bint(7);
			
			bint(7 downto 0) := bint(6 downto 0) & '0'; -- shifting left 1


			if(i < 7 and bcd(3 downto 0) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(3 downto 0) := std_logic_vector(unsigned(bcd(3 downto 0)) + 3);
			end if;

			if(i < 7 and bcd(7 downto 4) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(7 downto 4) := std_logic_vector(unsigned(bcd(7 downto 4)) + 3);
			end if;

		end loop;
		
		return bcd;
		
	end int_bcd2;
 
end commonPak;
