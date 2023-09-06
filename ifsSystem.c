#include "FPToolkit.c"

// appropriate for a 600x600 window
double x[1] = {0.0};
double y[1] = {0.0};
int n = 1;

void translate(double dx, double dy){
  int i = 0 ;
  while (i < n) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}

void scale(double w, double h){
  int i = 0;
  while(i < n){
    x[i] = x[i]*w;
    y[i] = y[i]*h;
    i += 1;
  }
}

void rotate(double degree){
  int i = 0;
  double radians = (M_PI/180)*degree;
  double temp;
  while(i < n){
    temp = x[i]*cos(radians) - y[i]*sin(radians);
    y[i] = x[i]*sin(radians) + y[i]*cos(radians);
    x[i] = temp;
    i += 1;
  }
}

void scenery(double r){
  double c = drand48();
  
  if(r < 0.25){
    G_rgb(1.0, 1.0, 1.0); //white
    translate(-0.7, 0.0);
    scale(0.25, 0.25);
    rotate(325);
    translate(0.2, 1.67);
  }else if(r < 0.5){
    G_rgb(0.0, 0.0, 1.0); //blue
    translate(-0.5, -0.5);
    scale(0.5, 0.5);
    translate(0.75, 0.97);
  }else if(r < 0.75){
    G_rgb(0.0, 1.0, 0.0); //green
    translate(-0.75, -0.75);
    scale(0.5, 0.87);
    rotate(75);
    translate(0.65*sin(M_PI/4), 0.47*cos(M_PI/4));
  }else{
    G_rgb(1.0, 1.0, 0.8); //cream
    translate(-0.5, -0.5);
    scale(0.7, 0.7);
    translate(0.7, 0.5);
  }
  if(y[0] > 0.47 && y[0] < 0.67 && c > 0.6){
    G_rgb(1.0, 1.0, 0.0);
  }
  if(x[0] > 0.7 && c > 0.9){
    G_rgb(x[0], 0.0, y[0]);
  }
  if(x[0] > 0.8 && c > 0.8){
    G_rgb(x[0], 0.0, y[0]);
  }
  if(x[0] > 0.9 && y[0] > 0.25 && c > 0.67){
    G_rgb(x[0], 0.0, y[0]);
  }
}

int main() {
  int width = 700;
  int height = 700;
  G_init_graphics(width, height);
  G_rgb(0,0,0);
  G_clear();

  srand48(200);
  double r = drand48(); // 0 <= r < 1  
  double n = 1000000;

  for(int i = 0; i < n; i++){
    r = drand48();

    scenery(r);

    G_point(x[0]*width, y[0]*height/2);
  }
  G_wait_key();
  G_save_to_bmp_file("ifs.bmp");
}