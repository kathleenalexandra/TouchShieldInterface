
var serial;
var portName = '/dev/cu.usbmodem1411'; 
var mpos = 0;
var inByte;


var r, g, b;

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
}

function draw() {
  background(127);
  
  fill(0, 0, 0);
  ellipse(105, 100, 50, 50);
  rect(80, 200, 50, 50);
  triangle(80, 375, 108, 320, 136, 375);

fill('red');
rect(580, 70, 50, 50);
fill('yellow');
rect(580, 170, 50, 50);
fill('blue');
rect(580, 270, 50, 50);
fill('green');
rect(580, 370, 50, 50);

}


function mousePressed() {

  
  
  var d = dist(mouseX, mouseY, 100, 100);


  if (d < 27 && d < 70) {
   alert('circle')
 
   console.log(d + "draw circle"); 
   serial.write("1");
   console.log("wrote one");
   

  }
  else if ( d < 202 && d < 210) {
    alert('square'); 
    console.log(d);
    serial.write("2");
    console.log(d + "draw square"); 

  }

 else if ( d > 250 && d < 300 ) { 
    alert('triangle'); 
    console.log(d);
    serial.write("3");
    console.log(d + "draw triangle");


  }

   else if ( d > 500 && d < 510 ) { 
    alert('red'); 
    console.log(d);
    serial.write("4");
    console.log(d + "color red");

  }

   else if ( d > 510 && d < 525 ) { 
    alert('yellow'); 
    console.log(d);
    serial.write("5");
    console.log(d + "color yellow");

  }

   else if ( d > 530 && d < 550 ) { 
    alert('blue'); 
    console.log(d);
    serial.write("6");
    console.log(d + "color blue");

  }

   else if ( d > 580 && d < 590 ) { 
    alert('green'); 
    console.log(d);
    serial.write("7");
    console.log(d + "color green");

  }


  else {
    console.log(d); 
  }
  
 
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



