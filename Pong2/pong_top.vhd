----------------------------------------------------------------------------------
-- Original Author: Eric Eastwood (http://ericeastwood.com/)
-- Original Source: https://github.com/MadLittleMods/VHDL-Pong
-- 
-- Create Date:    13:29:20 12/12/2013 
-- Module Name:    pong_top - Behavioral 
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
use work.fontPak.all;

entity pong_top is
	port(
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
end pong_top;

architecture Behavioral of pong_top is

	signal reset: std_logic := '0';

	signal ledReg: std_logic_vector(7 downto 0) := (others => '0');
	signal debugReg: std_logic_vector(7 downto 0) := (others => '0');

	-- Start out at the end of the display range, 
	-- so we give a sync pulse to kick things off
	signal hCount: integer range 0 to 1023 := 640;
	signal vCount: integer range 0 to 1023 := 480;
	
	signal nextHCount: integer range 0 to 1023 := 641;
	signal nextVCount: integer range 0 to 1023 := 480;

	constant NUM_DRAW_ELEMENTS: integer range 0 to 3 := 3;
	signal drawElementArray: type_drawElementArray(0 to NUM_DRAW_ELEMENTS-1) := (others => init_type_drawElement);
	
	constant NUM_BALL_COLLISION_ELEMENTS: integer range 0 to 2 := 2;
	-- The objects we want the ball to collide with
	signal ball_collisionObjects: type_collisionRectArray(0 to NUM_BALL_COLLISION_ELEMENTS-1) := (others => init_type_collisionRect);
	
	-- The ball collision rectangle
	signal ball_colRect: type_collisionRect := init_type_collisionRect;
	
	signal player1_btnControls: type_controls := (up => '0', down => '0');
	signal player2_btnControls: type_controls := (up => '0', down => '0');
	
	
	constant NUM_TEXT_ELEMENTS: integer range 0 to 1 := 1;
	signal inArbiterPortArray: type_inArbiterPortArray(0 to NUM_TEXT_ELEMENTS-1) := (others => init_type_inArbiterPort);
	signal outArbiterPortArray: type_outArbiterPortArray(0 to NUM_TEXT_ELEMENTS-1) := (others => init_type_outArbiterPort);
	signal drawTextElementArray: type_drawElementArray(0 to NUM_TEXT_ELEMENTS-1) := (others => init_type_drawElement);

	signal pongScore: type_score := init_type_score;
--	signal pongScoreLeft: string(1 to 6) := (others => NUL);
--	signal pongScoreRight: string(1 to 6) := (others => NUL);
	
	
	
	--signal debugBallStrings: type_ballDebugStrings := init_type_ballDebugStrings;
	
	signal had_url_pos: point_2d := (-100, -100);
	
begin

	reset <= sw(0);
	
	-- Or the bits together so that we can actually see the data
	ledReg <= "01010101";
	Led <= ledReg;

	
	paddleLeft: entity work.paddle
	generic map(
		sidePos => left,
		rgbColor => "111" & "000" & "11"
	)
	port map(
		reset => reset,
		clk => clk,
		hCount => nextHCount,
		vCount => nextVCount,
		colObject => ball_collisionObjects(0),
		controls => player1_btnControls,
		drawElement => drawElementArray(0)
	);
	
	paddleRight: entity work.paddle
	generic map(
		sidePos => right,
		rgbColor => "000" & "111" & "11"
	)
	port map(
		reset => reset,
		clk => clk,
		hCount => nextHCount,
		vCount => nextVCount,
		colObject => ball_collisionObjects(1),
		controls => player2_btnControls,
		drawElement => drawElementArray(1)
	);
	
	ball: entity work.ball
	generic map(
		numCollisionObjects => NUM_BALL_COLLISION_ELEMENTS,
		ballRadius => 8,
		rgbColor => "111" & "111" & "11"
	)
	port map(
		reset => reset,
		clk => clk,
		hCount => nextHCount,
		vCount => nextVCount,
		colObject => ball_colRect,
		colObjectArray => ball_collisionObjects,
		drawElement => drawElementArray(2),
		score => pongScore
		--debugStrings => debugBallStrings
	);


	-- AI for the paddles, if you have no one to play with... :(
	aiPaddles: process(clk)
		variable ai_p1_controls: type_controls := (up => '0', down => '0');
		variable ai_p2_controls: type_controls := (up => '0', down => '0');
	begin
		if rising_edge(clk) then
			if reset = '1' then
				ai_p1_controls := (up => '0', down => '0');
				ai_p2_controls := (up => '0', down => '0');
				
				player1_btnControls <= (up => '0', down => '0');
				player2_btnControls <= (up => '0', down => '0');
			else
			
				-- sw7 for left player
				if sw(7) = '1' then
					-- Is the ball above the padde?
					if ball_colRect.pos.y > ball_collisionObjects(0).pos.y then
						-- We should move up then
						ai_p1_controls.up := '1';
						ai_p1_controls.down := '0';
						
					-- Is the ball below the paddle?
					elsif ball_colRect.pos.y < ball_collisionObjects(0).pos.y then
						-- We should move down then
						ai_p1_controls.down := '1';
						ai_p1_controls.up := '0';
						
					else
						-- Otherwise we are exactly where we should be
						ai_p1_controls.up := '0';
						ai_p1_controls.down := '0';
					end if;
				else
					ai_p1_controls.up := '0';
					ai_p1_controls.down := '0';
				end if;
				
				-- sw6 for right player
				if sw(6) = '1' then
					-- Is the ball above the padde?
					if ball_colRect.pos.y > ball_collisionObjects(1).pos.y then
						-- We should move up then
						ai_p2_controls.up := '1';
						ai_p2_controls.down := '0';
						
					-- Is the ball below the paddle?
					elsif ball_colRect.pos.y < ball_collisionObjects(1).pos.y then
						-- We should move down then
						ai_p2_controls.down := '1';
						ai_p2_controls.up := '0';
						
					else
						-- Otherwise we are exactly where we should be
						ai_p2_controls.up := '0';
						ai_p2_controls.down := '0';
					end if;
				else
					ai_p2_controls.up := '0';
					ai_p2_controls.down := '0';
				end if;
				
				-- `OR` the controls together with the ai ones
				-- We only add ai control if the switch is active
				player1_btnControls <= (up => btn(3) or ai_p1_controls.up, down => btn(2) or ai_p1_controls.down);
				player2_btnControls <= (up => btn(1) or ai_p2_controls.up, down => btn(0) or ai_p2_controls.down);
			end if;
		end if;
	end process;





	-- Move the url into position if in hackaday mode (1337)
	hadURLPos: process(clk)
	begin
		if rising_edge(clk) then
			if reset = '1' then
				had_url_pos <= (-100, -100);
			else
				
				-- If the score is 1337, time to move the hackaday url into view
				-- had_mode
				if pongScore.left = 13 and pongScore.right = 37 then
					had_url_pos <= (20, 360);
					
				-- else, hide it away
				else
					had_url_pos <= (-100, -100);
				end if;
			end if;
		end if;
	end process;


--	scoreToString: process(clk)
--		variable testInt: integer := -123;
--	begin
--		if rising_edge(clk) then
--			if reset = '1' then
--				pongScoreLeft <= (others => NUL);
--				pongScoreRight <= (others => NUL);
--			else
--				pongScoreLeft <= integer2string_pad(pongScore.left, 6);
--				pongScoreRight <= integer2string_pad(pongScore.right, 6);
--				report "|" & integer2string_pad(pongScore.left, 6) & "|";
--				report "|" & integer2string_pad(-123456, 6) & "|";
--				
--				-- If the score is 1337, time to move the hackaday url into view
--				-- had_mode
--				if pongScore.left = 13 and pongScore.right = 37 then
--					had_url_pos <= (SCREEN_RESX/2, 360);
--					
--				-- else, hide it away
--				else
--					had_url_pos <= (-100, -100);
--				end if;
--			end if;
--		end if;
--	end process;


	


	scoreToSevenSeg: process(clk)
		variable bcdLeft: std_logic_vector(7 downto 0) := (others => '0');
		variable bcdRight: std_logic_vector(7 downto 0) := (others => '0');
		
		variable currAn: integer range 0 to 3 := 0; -- The current anode we are lighting up
		variable currBCD: std_logic_vector(3 downto 0)  := (others => '0'); -- The current bcd we are going to use for that anode
	
		variable update_clk_count: integer := 0;
		variable update_clk_prescaler: integer := 100000; -- 50 Mhz / clk_prescaler = desired speed
	begin
		if rising_edge(clk) then
			if reset = '1' then
				bcdLeft := (others => '0');
				bcdRight := (others => '0');
				
				currAn := 0;
				currBCD := (others => '0');
			else
				
				if update_clk_count >= update_clk_prescaler then
					
					-- Update the bcd
					bcdLeft := int_bcd2(pongScore.left);
					bcdRight := int_bcd2(pongScore.right);
					
					-- Set anode correctly
					case currAn is
						when 0 => 
							an <= "1110"; -- AN 0
							currBCD := bcdRight(3 downto 0); -- one digit of right score
						when 1 => 
							an <= "1101"; -- AN 1
							currBCD := bcdRight(7 downto 4); -- ten digit of right score
						when 2 => 
							an <= "1011"; -- AN 2
							currBCD := bcdLeft(3 downto 0); -- one digit of left score
						when 3 => 
							an <= "0111"; -- AN 3
							
							currBCD := bcdLeft(7 downto 4); -- ten digit of left score
						
						when others => an <= "1111"; -- nothing
					end case;
					
					-- Set segments correctly
					case currBCD is
						when "0000" => seg <= "1000000"; -- 0
						when "0001" => seg <= "1111001"; -- 1
						when "0010" => seg <= "0100100"; -- 2
						when "0011" => seg <= "0110000"; -- 3
						when "0100" => seg <= "0011001"; -- 4
						when "0101" => seg <= "0010010"; -- 5
						when "0110" => seg <= "0000011"; -- 6
						when "0111" => seg <= "1111000"; -- 7
						when "1000" => seg <= "0000000"; -- 8
						when "1001" => seg <= "0010000"; -- 9
						
						when others => seg <= "1111111"; -- nothing
					end case;
					
					-- Move to the next anode
					currAn := currAn + 1;
					
					update_clk_count := 0;
				end if;
				
				update_clk_count := update_clk_count + 1;
				
			end if;
		end if;
		
		
	end process;


	
	fontLibraryArbiter: entity work.blockRamArbiter
	generic map(
		numPorts => NUM_TEXT_ELEMENTS
	)
	port map(
		clk => clk,
		reset => reset,
		inPortArray => inArbiterPortArray,
		outPortArray => outArbiterPortArray
	);


--	collisions_textDrawElement: entity work.text_line
--	generic map (
--		textPassageLength => 14
--	)
--	port map(
--		clk => clk,
--		reset => reset,
--		textPassage => debugBallStrings.collisions,
--		position => (50, 50),
--		colorMap => (13 downto 0 => "111" & "111" & "11"),
--		inArbiterPort => inArbiterPortArray(0),
--		outArbiterPort => outArbiterPortArray(0),
--		hCount => nextHCount,
--		vCount => nextVCount,
--		drawElement => drawTextElementArray(0)
--	);
--	
--	velocity_textDrawElement: entity work.text_line
--	generic map (
--		textPassageLength => 18
--	)
--	port map(
--		clk => clk,
--		reset => reset,
--		textPassage => debugBallStrings.velocity,
--		position => (50, 70),
--		colorMap => (17 downto 0 => "111" & "111" & "11"),
--		inArbiterPort => inArbiterPortArray(1),
--		outArbiterPort => outArbiterPortArray(1),
--		hCount => nextHCount,
--		vCount => nextVCount,
--		drawElement => drawTextElementArray(1)
--	);





--	scoreLeft_textDrawElement: entity work.text_line
--	generic map (
--		textPassageLength => pongScoreLeft'length
--	)
--	port map(
--		clk => clk,
--		reset => reset,
--		textPassage => pongScoreLeft,
--		position => (SCREEN_RESX/4, 50),
--		colorMap => (pongScoreLeft'length-1 downto 0 => "111" & "111" & "11"),
--		inArbiterPort => inArbiterPortArray(0),
--		outArbiterPort => outArbiterPortArray(0),
--		hCount => nextHCount,
--		vCount => nextVCount,
--		drawElement => drawTextElementArray(0)
--	);
--	
--	scoreRight_textDrawElement: entity work.text_line
--	generic map (
--		textPassageLength => pongScoreRight'length
--	)
--	port map(
--		clk => clk,
--		reset => reset,
--		textPassage => pongScoreRight,
--		position => ((SCREEN_RESX/4)*3, 50),
--		colorMap => (pongScoreRight'length-1 downto 0 => "111" & "111" & "11"),
--		inArbiterPort => inArbiterPortArray(1),
--		outArbiterPort => outArbiterPortArray(1),
--		hCount => nextHCount,
--		vCount => nextVCount,
--		drawElement => drawTextElementArray(1)
--	);
	
	hadURL_textDrawElement: entity work.text_line
	generic map (
		textPassageLength => 26
	)
	port map(
		clk => clk,
		reset => reset,
		textPassage => "Visit http://hackaday.com/",
		position => had_url_pos,
		colorMap => (25 downto 0 => "111" & "111" & "11"),
		inArbiterPort => inArbiterPortArray(0),
		outArbiterPort => outArbiterPortArray(0),
		hCount => nextHCount,
		vCount => nextVCount,
		drawElement => drawTextElementArray(0)
	);




	vgasignal: process(clk)
		variable divide_by_2 : std_logic := '0';
		variable rgbDrawColor : std_logic_vector(7 downto 0) := (others => '0');
	begin
		
		if rising_edge(clk) then
			if reset = '1' then
				hsync <= '1';
				vsync <= '1';
				
				-- Start out at the end of the display range, 
				-- so we give a sync pulse to kick things off
				hCount <= 640;
				vCount <= 480;
				nextHCount <= 641;
				nextVCount <= 480;
				
				rgbDrawColor := (others => '0');
				
				divide_by_2 := '0';
			else
				
				-- Running at 25 Mhz (50 Mhz / 2)
				if divide_by_2 = '1' then
					
					if(hCount = 799) then
						hCount <= 0;
						
						if(vCount = 524) then
							vCount <= 0;
						else
							vCount <= vCount + 1;
						end if;
					else
						hCount <= hCount + 1;
					end if;
					
					
					-- Make sure we got the rollover covered
					if (nextHCount = 799) then	
						nextHCount <= 0;
						
						-- Make sure we got the rollover covered
						if (nextVCount = 524) then	
							nextVCount <= 0;
						else
							nextVCount <= vCount + 1;
						end if;
					else
						nextHCount <= hCount + 1;
					end if;
					
					
					
					if (vCount >= 490 and vCount < 492) then
						vsync <= '0';
					else
						vsync <= '1';
					end if;
					
					if (hCount >= 656 and hCount < 752) then
						hsync <= '0';
					else
						hsync <= '1';
					end if;
					
					
					-- If in display range
					if (hCount < 640 and vCount < 480) then
						
						
						
						-- Draw stack:
						-- Default is black
						rgbDrawColor := "000" & "000" & "00";
						
						
						
						-- Draw bounding left line - 2px
						if hCount >= 0 and hCount < 2 then
							rgbDrawColor := "111" & "111" & "00";
						-- Draw bounding right line - 2px
						elsif hCount <= 639 and hCount > 637 then
							rgbDrawColor := "111" & "111" & "00";
						end if;
						
						
						-- Draw bounding top line - 2px
						if vCount >= 0 and vCount < 2 then
							rgbDrawColor := "111" & "111" & "00";
						-- Draw bounding bottom line - 2px
						elsif vCount <= 479 and vCount > 477 then
							rgbDrawColor := "111" & "111" & "00";
						end if;



						-- Draw the center line
						if hCount > (SCREEN_RESX/2)-3 and hCount < (SCREEN_RESX/2)+3 then
							rgbDrawColor := "011" & "011" & "01";
						end if;



						-- Draw Stack
						-----------------
						for i in drawElementArray'range loop
							if drawElementArray(i).pixelOn then
								rgbDrawColor := drawElementArray(i).rgb;
							end if;
						end loop;
						
						
						
						-- Text Draw Stack
						-----------------
						for i in drawTextElementArray'range loop
							if drawTextElementArray(i).pixelOn then
								rgbDrawColor := drawTextElementArray(i).rgb;
							end if;
						end loop;
						
						
						
						-- Show your colors
						Red <= rgbDrawColor(7 downto 5);
						Green <= rgbDrawColor(4 downto 2);
						Blue <= rgbDrawColor(1 downto 0);
						
						
					else
						Red <= "000";
						Green <= "000";
						Blue <= "00";
					end if;
			
				end if;
				divide_by_2 := not divide_by_2;
			end if;
		end if;
	end process;


end Behavioral;

