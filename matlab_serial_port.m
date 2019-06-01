clear a;
a = arduino('COM3');
a.pinMode(8, 'OUTPUT');
a.pinMode(12, 'INPUT');
tic
while (toc<10)
    
    b=a.digitalRead(12);
    if ( b==true)
        a.digitalWrite(8,1);
    else
        a.digitalWrite(8,0);
    end
end