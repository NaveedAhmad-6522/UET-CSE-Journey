time=0:0.01:10;
fun_f=100;
sig=((4/pi)*sin(2*pi*fun_f*time))/time;
for k=1:2:100;
    harmonicfreq=k*fun_f;
    x=((4/(k*pi)*sin(2*pi*harmonicfreq*time));
    sig=sig+x;
end
plot(time,sig,'k','linewidth',1.5);
xlable('time , t');
ylebal('ampltuid');
grid;
