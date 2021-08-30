#define lm_input_1 2	//Terminals 1 and 2 of LHS motor
#define lm_input_2 3
#define rm_input_3 4	//Terminals 1 and 2 of RHS motor
#define rm_input_4 5
#define ir_l 13			//LHS IR Sensor
#define ir_c 12			//Centre IR Sensor
#define ir_r 11 		//RHS IR Sensor
int movement;

void setup() {
  Serial.begin(9600);
  pinMode(ir_l, INPUT);
  pinMode(ir_c, INPUT);
  pinMode(ir_r, INPUT);
  pinMode(lm_input_1, OUTPUT);
  pinMode(lm_input_2, OUTPUT);
  pinMode(rm_input_3, OUTPUT);
  pinMode(rm_input_4, OUTPUT);
}

int go_forward() {
  Serial.println("Going forward");
  digitalWrite(lm_input_1, HIGH);
  digitalWrite(lm_input_2, LOW);
  digitalWrite(rm_input_3, HIGH);
  digitalWrite(rm_input_4, LOW);
  return 0;
}

int stop_bot() {
  Serial.println("Stopping the bot");
  digitalWrite(lm_input_1, LOW);
  digitalWrite(lm_input_2, LOW);
  digitalWrite(rm_input_3, LOW);
  digitalWrite(rm_input_4, LOW);
  return 0;
}

int go_left() {
  Serial.println("Going left");
  digitalWrite(lm_input_1, LOW);
  digitalWrite(lm_input_2, LOW);
  digitalWrite(rm_input_3, HIGH);
  digitalWrite(rm_input_4, LOW);
  return 0;
}

int go_right() {
  Serial.println("Going right");
  digitalWrite(lm_input_1, HIGH);
  digitalWrite(lm_input_2, LOW);
  digitalWrite(rm_input_3, LOW);
  digitalWrite(rm_input_4, LOW);
  return 0;
}

void loop() {
  //Taking inputs from three IR Sensors-
  int il = digitalRead(ir_l);
  int ic = digitalRead(ir_c);
  int ir = digitalRead(ir_r);
  digitalWrite(6, HIGH);
  
  if ((il == 0) && (ic == 1) && (ir == 0)) {	//only the centre IR Sensor is on the line.
  	//keep going forward
    movement = go_forward();
  }
  
  else if ((il == 0) && (ic == 0) && (ir == 1)) {	//only right IR Sensor is on the line
    //move to right
    movement = go_right();
  }
  
  else if ((il == 1) && (ic == 0) && (ir == 0)) {	//only left IR Sensor is on the line
    //move to left
    movement = go_left();
  }
  
  else if ((il == 0) && (ic == 1) && (ir == 1)) {	//right and centre IR Sensor is on the line
    //move to right
    movement = go_right();
  }
  
  else if ((il == 1) && (ic == 1) && (ir == 0)) {	//left and centre IR Sensor is on the line
    //move to left
    movement = go_left();
  }
  
  
  else if ((il == 1) && (ic == 1) && (ir == 1)) {	//all three IR Sensors are on the line
    //move to right
    movement = go_right();
  }
  
  else if ((il == 0) && (ic == 0) && (ir == 0)) {	//no IR Sensor is on the line
    //stop the bot
    movement = stop_bot();
  }
}	//End of loop

//TinkerCAD Link: https://www.tinkercad.com/things/jJH6uYaclC2-line-tracing-bot/editel?sharecode=u1qoBl8UaIvgGl1ACXnaGrs4BJsldAh96s9lDa2PZ9w