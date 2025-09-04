t=0:0.001:1;
f=10;
figure(1);
for i = 1:6    
    y = sin(2*pi*f*i*t);
    subplot(3,2,i);
    plot(t,y)
    title_str =  ['Signal of ',num2str(i*10),'Hz frequency'];
    title(title_str);
    xlabel('Time');
    ylabel('Amplitude');
    grid on;
    hold on
end
figure(2);
w=-(length(y)-1)/2:(length(y) -1)/2;

for j = 1:6    
    y = sin(2*pi*f*j*t);
    x_f = fft(y, length(w));
    x_fshift = fftshift(x_f);
    subplot(3,2,j);
    plot(w,abs(x_fshift))    
    title_str =  ['Frequency Response of signal of ',' ',num2str(j*10),'Hz'];
    title(title_str);
    xlabel('Frequency');
    ylabel('Amplitude');
    grid on;
    hold on
end
