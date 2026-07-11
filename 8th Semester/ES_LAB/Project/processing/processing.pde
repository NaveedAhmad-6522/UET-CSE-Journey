import processing.serial.*;

Serial myPort;

String angle = "";
String distance = "";
String data = "";
String noObject;

float pixsDistance;

int iAngle = 0;
int iDistance = 0;

int index1 = 0;

void setup()
{
  size(1200,700);
  smooth();

  println("Available Serial Ports:");
  println(Serial.list());

  String portName = "";

  for (String port : Serial.list())
  {
    if (port.contains("usbserial") || port.contains("usbmodem"))
    {
      portName = port;
      break;
    }
  }

  if (portName.equals(""))
  {
    println("Arduino not found!");
    exit();
    return;
  }

  println("Connecting to: " + portName);

  myPort = new Serial(this, portName, 9600);

  // Wait for Arduino Uno to restart after opening the port
  delay(2500);

  // Remove any incomplete data
  myPort.clear();

  myPort.bufferUntil('.');
}

void draw()
{
  fill(98,245,31);

  noStroke();
  fill(0,4);
  rect(0,0,width,height);

  fill(98,245,31);

  drawRadar();
  drawLine();
  drawObject();
  drawText();
}

void serialEvent(Serial myPort)
{
  data = myPort.readStringUntil('.');

  if(data == null)
    return;

  data = trim(data);

  data = data.substring(0,data.length()-1);

  index1 = data.indexOf(",");

  angle = data.substring(0,index1);

  distance = data.substring(index1+1);

  iAngle = int(angle);

  iDistance = int(distance);
}

void drawRadar()
{
  pushMatrix();

  translate(width/2,height-height*0.074);

  noFill();

  strokeWeight(2);

  stroke(98,245,31);

  arc(0,0,width-75,width-75,PI,TWO_PI);
  arc(0,0,width-325,width-325,PI,TWO_PI);
  arc(0,0,width-575,width-575,PI,TWO_PI);
  arc(0,0,width-825,width-825,PI,TWO_PI);

  line(-width/2,0,width/2,0);

  for(int i=30;i<=150;i+=30)
  {
    line(
      0,
      0,
      (-width/2)*cos(radians(i)),
      (-width/2)*sin(radians(i))
    );
  }

  popMatrix();
}

void drawObject()
{
  pushMatrix();

  translate(width/2,height-height*0.074);

  strokeWeight(9);

  stroke(255,0,0);

  pixsDistance=iDistance*((height-height*0.1666)*0.025);

  if(iDistance<40)
  {
    line(
      pixsDistance*cos(radians(iAngle)),
      -pixsDistance*sin(radians(iAngle)),
      (width-width*0.505)*cos(radians(iAngle)),
      -(width-width*0.505)*sin(radians(iAngle))
    );
  }

  popMatrix();
}

void drawLine()
{
  pushMatrix();

  translate(width/2,height-height*0.074);

  strokeWeight(9);

  stroke(30,250,60);

  line(
    0,
    0,
    (height-height*0.12)*cos(radians(iAngle)),
    -(height-height*0.12)*sin(radians(iAngle))
  );

  popMatrix();
}

void drawText()
{
  fill(0);

  rect(0,height-50,width,50);

  fill(98,245,31);

  textSize(25);

  text("Arduino Ultrasonic Radar",20,height-15);

  text("Angle : "+iAngle+"°",450,height-15);

  if(iDistance<40)
    text("Distance : "+iDistance+" cm",700,height-15);
  else
    text("Out of Range",700,height-15);
}
