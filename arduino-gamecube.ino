#include "Nintendo.h"

#define stick_left uint8_t(35);
#define stick_right uint8_t(221);
#define stick_down uint8_t(35);
#define stick_up uint8_t(221);
#define stick_center uint8_t(128);

// wire colors for the generic gamecube controller I chopped apart:
// white = 5v (rumble supply)
// black = 3.4v (signal voltage)
// red = data
// yellow = ground
// brown = ground

// line to send data on
CGamecubeConsole gc(15); 
// controller (doesn't need to be connected)
CGamecubeController cont(14);

// buttons
int a = 6;
int b = 7;
int select = 11;
int start = 10;
int z = 12;
int l = 8;
int r = 9;
int up = 2;
int down = 3;
int left = 4;
int right = 5;

// default data
Gamecube_Data_t d = defaultGamecubeData;

void setup() {
  pinMode(a, INPUT_PULLUP);
  pinMode(b, INPUT_PULLUP);
  pinMode(select, INPUT_PULLUP);
  pinMode(start, INPUT_PULLUP);
  pinMode(z, INPUT_PULLUP);
  pinMode(l, INPUT_PULLUP);
  pinMode(r, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  // gamecube needs this I guess
  cont.read();
}

int du, dd, dl, dr;

void loop() {
  d.report.a = !digitalRead(a);
  d.report.b = !digitalRead(b);
  d.report.x = !digitalRead(select);
  d.report.start = !digitalRead(start);
  d.report.z = !digitalRead(z);
  d.report.l = !digitalRead(l);
  d.report.r = !digitalRead(r);

  du = !digitalRead(up);
  dd = !digitalRead(down);
  dl = !digitalRead(left);
  dr = !digitalRead(right);

  d.report.xAxis = stick_center;
  if (dl) {
    d.report.xAxis = stick_left;
  } else if (dr) {
    d.report.xAxis = stick_right;
  }
  d.report.yAxis = stick_center;
  if (du) {
    d.report.yAxis = stick_up;
  } else if (dd) {
    d.report.yAxis = stick_down;
  }
  
  gc.write(d);
}
