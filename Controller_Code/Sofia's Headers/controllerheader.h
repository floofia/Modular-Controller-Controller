//enum connection_type
//{
//// fill out once I figure out the ble library
//unused,     //pin is unused
//lx,         // left joystick x
//ly,         //left joystick y
//lz,         //left joystick button press
//rx,         //right joystick x
//ry,         //right joystick y
//rz,         //right joystick button press
//a,          //a button
//b,          //b button
//x,          //x button
//y,          //y button
//up,         //dpad up
//down,       //dpad down
//left,       //dpad left
//right,      //dpad right
//select,     //select
//start,      //start
//home,       //home
//l1,         //left trigger 1
//r1,         //right trigger 1
//l2,         //left trigger 2
//r2,         //right trigger 2
//screenshot, //screenshot
//lspeaker,   //left speaker output
//rspeaker,   //right speaker output
//lhaptic,    //left vibration feedback
//rhaptic,    //right vibration feedback
//batt_lvl,   //battery percentage
//volup,      //volume up
//voldown,    //volume down
//button1,    //customizable button 1
//button2,    //customizable button 2
//button3,    //customizable button 3
//button4,    //customizable button 4
//button5,    //customizable button 5
//button6,    //customizable button 6
//button7,    //customizable button 7
//button8,    //customizable button 8
//button9,    //customizable button 9
//button10,   //customizable button 10
//button11,   //customizable button 11
//button12,   //customizable button 12
//button13,   //customizable button 13
//button14,   //customizable button 14
//button15,   //customizable button 15
//button16,   //customizable button 16
//}

//struct seesawpin
//{
//	int usable; //if the pin is usable as an input/output
//	bool io; //true if pin is input, false if used as output
//	bool pwm; //pin can/will use pulse width modulation, 
//		//pins 0, 1, 2, 3, 6, 7, 18, 19, 20
//	bool adc; //pin can/will use analog to digital input, 
//		//pins 0, 1, 9, 12, 13
//	enum connection_type connection;
//};

//struct module
//{
//	char address; //the seesaw's adress
//	struct seesawpin pin[20]
//  // the seesaw has 20 pins but 4 is numbered as pin 20
//	//defaulting all pins to input
//	{  //usable i/o   pwm    adc   connection type
//		{ true,  true,  true,  true , unused},//0  - adc pwm
//		{ true,  true,  true,  true , unused},//1  - adc pwm
//		{ true,  true,  false, true , unused},//2  - adc
//		{ true,  true,  false, true , unused},//3  - adc
//		{ false, true,  false, true , unused},//20 - adc
//		//I'm not sure why 4 is 20 on the board 
//		//but I'm not messing with it 
//		{ true,  true,  false, true , unused},//5  - adc
//		{ true,  true,  false, true , unused},//6  - adc
//		{ true,  true,  false, true , unused},//7  - adc
//		{ true,  true,  false, false, unused},//8
//		{ true,  true,  true,  false, unused},//9  - pwm
//		{ false, true,  false, false, unused},//10
//		{ false, true,  false, false, unused},//11
//		{ true,  true,  true,  false, unused},//12 - pwm
//		{ true,  true,  true,  false, unused},//13 - pwm
//		{ true,  true,  false, false, unused},//14 
//		{ false, true,  false, false, unused},//15 - interrupt pin
//		{ false, true,  false, fasle, unused},//16 - addr increment by 1
//		{ false, true,  false, false, unused},//17 - addr increment by 2
//		{ true,  true,  false, true , unused},//18 - adc
//		{ true,  true,  false, true , unused} //19 - adc
////	{ false, true,  false, true , unused} //20 - adc
//	};
//};
//void define_pin( struct module mod, int pinnumber, bool io, enum connection_type connection)

//void define_pin( struct module mod, int pinnumber, bool io, enum connection_type connection)
//{	
//	//since pin 20 is put in the array as value 4 since it's basically pin 4
//	if ( pinnumber == 4 || pinnumber == 20)
//	{
//		mod.pin[4].io = io;
//		mod.pin[4].connection = connection;
//	}
//	//if the pin can be used as a gpio pin
//	else if (mod.pin[pinnumber].usable == true)
//	{
//		mod.pin[pinnumber].io = io;
//		mod.pin[pinnumber].connection = connection;
//	}
//};

