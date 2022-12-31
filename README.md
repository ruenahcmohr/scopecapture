# Serial data capture for Tek scope

This is the capture program I use with my Tek scope.
Its used in a shell script that, after capturing the data,
converts it into a PNG file and opens it up in Gimp for me.

For the capture board itself, see https://github.com/ruenahcmohr/scopecapture

I have included the bash script I use with this.

To use this, I just run it like

  dograb temp
  
This will capture the file to temp.eps, convert it to temp.png and then open it with gimp.


