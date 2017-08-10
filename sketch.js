
var serial;
var portName = '/dev/cu.usbmodem1411'; 
var mpos = 0;
var inByte;
var input;
var button;
var greeting;
var color; 
var shape;


function setup() {
  createCanvas(720, 720); 
  serial = new p5.SerialPort(); 
  serial.on('list', printList);
  serial.on('connected', serverConnected); 
  serial.on('open', portOpen); 
  serial.on('data', serialEvent); 
  serial.on('error', serialError); 
  serial.on('close', portClose); 
  serial.open(portName); 
  shape = createElement('h2', 'shape');
  shape.position(70, 5);
  color = createElement('h2', 'color');
  color.position(570, 5);
  textAlign(CENTER);
  textSize(50);


input = createInput();
  input.position(60, 465);
  button = createButton('submit');
  button.position(input.x + input.width, 465);
  button.mousePressed(greet);
  greeting = createElement('h2', 'say something');
  greeting.position(60, 405);
  textAlign(CENTER);
  textSize(50);
}


function draw() {
  background('lightgrey');

  
fill('white');
ellipse(105, 100, 50, 50);
rect(80, 200, 50, 50);
triangle(80, 375, 108, 320, 136, 375);
fill('red');
textSize(30);
text("RED", 600, 100);
fill('yellow');
textSize(30);
text("YELLOW", 600, 200);
fill('blue');
textSize(30);
text("BLUE", 600, 300);
fill('green');
textSize(30);
text("GREEN", 600, 400);

}


function mousePressed() {
  var d = dist(mouseX, mouseY, 100, 100);

  if (d < 27 && d < 70) {
   console.log(d + "draw circle"); 
   serial.write("1");
   shape.html("circle");
   console.log("wrote one");
  }

  else if ( d < 202 && d < 210) {
    console.log(d);
    serial.write("2");
    shape.html("square");
    console.log(d + "draw square"); 
  }


 else if ( d > 250 && d < 300 ) {  
    console.log(d);
    serial.write("3");
    shape.html("triangle");
    console.log(d + "draw triangle");
  }

   else if ( d > 490 && d < 505 ) { 
    console.log(d);
    serial.write("4");
    color.html("red");
    console.log(d + "color red");

  }

   else if ( d > 508 && d < 520 ) { 
    console.log(d);
    serial.write("5");
    color.html("yellow");
    console.log(d + "color yellow");

  }

   else if ( d > 525 && d < 540 ) { 
    console.log(d);
    serial.write("6");
    color.html("blue");
    console.log(d + "color blue");

  }

   else if ( d > 571 && d < 580 ) { 
    console.log(d);
    serial.write("7");
    color.html("green");
    console.log(d + "color green");

  }

  else {
    console.log(d); 
  }
  
 
}

function greet() {
  var name = input.value();
  greeting.html(name);
  var mystring = String(name);
  alert(mystring); 
  serial.write(mystring);
  serial.write("\n");
  input.value('');

}

function serialError(err) {
    console.log('Something went wrong with the serial port. ' + err);
}

function portClose() {
    console.log('The serial port closed.');
}

function printList(portList) {
    for (var i = 0; i < portList.length; i++) {
        console.log(i + " " + portList[i]);
    }
}

function serialEvent() {
    inByte = Number(serial.read()); } 

function serverConnected() {
    console.log('connected to server.');
}

function portOpen() {
    console.log('the serial port opened.');
}



