int counter = 0;

void setup()
{
  size(640, 480);
}


void draw() 
{
  counter = counter + 1;

  if (counter > 255)
  {
    counter = 0;
  }

  background(counter);

  if (mousePressed)
  {
    fill(0, 255, 0);
    ellipse(mouseX, mouseY, 100, 100);
  } 
  else 
  {
    fill(255, 255, 0);
    ellipse(mouseX, mouseY, 30, 30);
  }
}