int x;
int y=300;
int i=0;
int x1=550;
int vel;
void setup(){
  size(1000,600);
  background(255);
  
}

void draw(){
  background(255);
  figura(); 
  esfera();
  fill(200,0,0);
  rect(50,500,50,50);
  if(i==1){
    if(y>200){
      y=y-2;
    }
    else{
      i=0;
      y=300;
  }
  }
  fill(255,0,0);
  ellipse(x1+x,430,20,20);
  
  if(x1>0){
    
    x1=x1-vel;
  }
  else
  x1=900-vel;
}

void figura(){
  beginShape();
  fill(0);
  vertex(10+x,60+y);
  vertex(15+x,60+y);
  vertex(15+x,65+y);
  vertex(20+x,65+y);
  vertex(20+x,70+y);
  vertex(20+x,70+y);
  vertex(30+x,70+y);
  vertex(30+x,65+y);
  vertex(35+x,65+y);
  vertex(35+x,60+y);
  vertex(45+x,60+y);
  vertex(45+x,55+y);
  vertex(55+x,55+y);
  vertex(55+x,50+y);
  vertex(60+x,50+y);
  vertex(60+x,10+y);
  vertex(65+x,10+y);
  vertex(65+x,5+y);
  vertex(100+x,5+y);
  vertex(100+x,10+y);
  vertex(110+x,10+y);
  vertex(110+x,30+y);
  vertex(80+x,30+y);
  vertex(80+x,45+y);
  vertex(95+x,45+y);
  vertex(95+x,50+y);
  vertex(75+x,50+y);
  vertex(75+x,60+y);
  vertex(85+x,60+y);
  vertex(85+x,70+y);
  vertex(80+x,70+y);
  vertex(80+x,65+y);
  vertex(75+x,65+y);
  vertex(75+x,80+y);
  vertex(70+x,80+y);
  vertex(70+x,90+y);
  vertex(65+x,90+y);
  vertex(65+x,95+y);
  vertex(60+x,95+y);
  vertex(60+x,120+y);
  vertex(65+x,120+y);
  vertex(65+x,125+y);
  vertex(55+x,125+y);
  vertex(55+x,110+y);
  vertex(50+x,110+y);
  vertex(50+x,105+y);
  vertex(45+x,105+y);
  vertex(45+x,110+y);
  vertex(40+x,110+y);
  vertex(40+x,115+y);
  vertex(35+x,115+y);
  vertex(35+x,120+y);
  vertex(40+x,120+y);
  vertex(40+x,125+y);
  vertex(30+x,125+y);
  vertex(30+x,95+y);
  vertex(20+x,95+y);
  vertex(20+x,90+y);
  vertex(15+x,90+y);
  vertex(15+x,85+y);
  vertex(10+x,85+y);
  vertex(10+x,80+y);
  vertex(5+x,80+y);
  vertex(5+x,50+y);
  vertex(10+x,50+y);
  vertex(10+x,60+y);
  endShape();
  fill(255);
  rect(70+x,15+y,10,10);
}

void mouseClicked(){
  
  if(mouseButton==LEFT&&mouseX>50&&mouseX<100&&mouseY>500&&mouseY<550){
   i=1-i;
   vel=4;
  }
}

void esfera(){
  
  
}
