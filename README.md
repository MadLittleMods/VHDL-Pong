VHDL-Pong
=========

Straightforward Pong Game written in VHDL.

Runs on the [Basys 2 board from Digilent](http://www.digilentinc.com/Products/Detail.cfm?Prod=BASYS2)

Read more about it in this [blog post](http://ericeastwood.com/blog/9/pong-on-a-fpga).

Watch [a video of this project](https://www.youtube.com/watch?v=H2etR0ogEfI) in action on youtube.

[As seen on Hackday.com](http://hackaday.com/2013/12/26/fubarino-contest-fpga-pong/)

![Pong game screenshot](http://i.imgur.com/6vYlZQA.png)

## Features:

 - Multiplayer: Battle against your friend
 - Play against the AI. Or AI vs AI battles
 - Score Keeping
 - Hidden Mode / Easter Egg
 

## Controls:

Action | Control
------ | -----------
Player Left/1 Paddle movement | btn2 and btn3
Player Right/2 Paddle movement | btn0 and btn1
Reset | switch0
Player Left/1 AI Enable | switch7
Player Right/2 AI Enable | switch6


## Technology:

Here just a list of things implemented in this design

 - Collision Detection and Resolution
 - VGA Output, game video
 - Text display on VGA which includes a ram arbiter (uses my other project [FP-V-GA Text](https://github.com/MadLittleMods/FP-V-GA-Text))
 - Basic AI for the paddles
 - Button and Switch Input
 - Seven Segment driver (BCD converter)
 


