fs=11025;
dur=0.9;
t=0:1/fs:dur;
f=2000;
xx=sin(2*pi*f*t);
sound(xx, fs); 